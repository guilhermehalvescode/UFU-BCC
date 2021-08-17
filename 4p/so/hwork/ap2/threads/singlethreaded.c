#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define MAX 1000

typedef unsigned long int uli;

uli readdir_count(char* path);

int main() {
  printf("Numero total de arquivos em: %lu\n", readdir_count("/"));
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