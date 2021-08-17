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

int main() {
  printf("Numero total de arquivos em: %lu\n", multiprocs("/"));
  return 0;
}

uli readdir_count(char* path) {
  DIR* dir = opendir(path);
  uli files = 0;
  struct dirent* file;
  if(!dir) return 0;
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
  int procs = get_nprocs_conf(), active = 0;
  pid_t* pids;
  pids = (pid_t*) malloc(sizeof(pid_t) * procs);
  if(!pids) return -1;
  DIR* dir = opendir(path);
  if(!dir) return -1;
  uli rootFiles = 0;
  struct dirent* file;
  pids[active++] = getpid();
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
      readdir_count(newDir);
    }
    if(active >= 4) {
      
    }
  }
  closedir(dir);
}