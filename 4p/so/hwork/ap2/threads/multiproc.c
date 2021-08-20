#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX 1000

typedef unsigned long int uli;

uli readdir_count(char* path);
uli multiprocs(char* path);
int main() {
  printf("Numero total de arquivos em: %lu\n", multiprocs("/"));
  return 0;
}

uli readdir_count(char* path) {
  DIR* dir = opendir(path);
  if(!dir) return 0;
  uli files = 0;
  struct dirent* file;
  while(file = readdir(dir)) {
    if (
      !strcmp(file->d_name, ".") ||
      !strcmp(file->d_name, "..")
    ) continue;
    if(file->d_type == DT_DIR) {
      char newDir[MAX];
      strcpy(newDir, path);
      strcat(newDir, file->d_name);
      strcat(newDir, "/");
      files += readdir_count(newDir);
    } else {
      files++;
    }
  }
  closedir(dir);
  return files;
}

uli multiprocs(char* path) {
  DIR* dir = opendir(path);
  if(!dir) return -1;
  int nProc = get_nprocs_conf() - 1, i, j, files = 0, dirs = 0, res;
  if(nProc == 0) nProc = 1;
  struct dirent* file; 
  while(file = readdir(dir)) {
    if (
      !strcmp(file->d_name, ".") ||
      !strcmp(file->d_name, "..") ||
      file->d_type != DT_DIR
    ) continue;
    dirs++;
  } 
  rewinddir(dir);
  //could be done with malloc
  char names[dirs][50];
  i = 0;
  while(file = readdir(dir)) {
    if (
      !strcmp(file->d_name, ".") ||
      !strcmp(file->d_name, "..") ||
      file->d_type != DT_DIR
    ) continue;
    strcpy(names[i++], file->d_name);
  }
  for(i = 0; i < dirs; i += nProc + 1) {
    // start 'nProc' procs
    for(j = 0; j < nProc; j++) {
      if(!fork()) break;
    }
    //j = 0 (f child) // j = 1 (snd child) ... // j = nProc (master process)
    char arqName[12] = "f", num[2];
    num[0] = j + '0'; 
    num[1] = '\0'; 
    strcat(arqName, num);
    strcat(arqName, ".txt");
    FILE* arq = fopen(arqName, "w");
    if(arq && i + j < dirs) {
      char newDir[MAX];
      strcpy(newDir, path);
      strcat(newDir, names[i + j]);
      strcat(newDir, "/");
      int res = readdir_count(newDir);
      fprintf(arq, "%d", res);
    }
    fclose(arq);
    //if child, exit;
    if(j != nProc) exit(0);
    for(j = 0; j < nProc; j++) {
      wait(NULL);
    }
    for(j = 0; j <= nProc; j++) {
      char arqName[12] = "f", num[2];
      num[0] = j + '0'; 
      num[1] = '\0'; 
      strcat(arqName, num);
      strcat(arqName, ".txt");
      res = 0;
      FILE* arq = fopen(arqName, "r");
      if(arq) {
        fscanf(arq, "%d", &res);
        files += res;
      }
      fclose(arq);
      remove(arqName);
    }
  }
  return files;
}