#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
#include <sys/syscall.h>
#include <errno.h>

#define MAX_SIZE 4

void formatCommand(char* str, unsigned short int max);
void err(char * msg);
void cls();
void dir();
void date();
void timeShell();

int main() {
  char command[MAX_SIZE + 1];
  printf("Bem vindo ao Shell!!\n\n");
  while(1) {
    printf("> ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", command);
    formatCommand(command, MAX_SIZE + 1);

    if(!strcmp(command, "CLS")) {
      cls();
    } else if(!strcmp(command, "DIR")) {
      dir();
    } else if(!strcmp(command, "DATE")) {
      date();
    } else if(!strcmp(command, "TIME")) {
      timeShell();
    } else {
      err("Comando não encontrado!");
    }
  }
  return 0;
}


//Input format
void formatCommand(char* str, unsigned short int max) {
  int i, j;
  for(i = 0; i < max; i++) {
    str[i] = toupper(str[i]);
    //Removing ' ' through shifting O(n)
    if(str[i] == ' ') {
      for(j = i; j < max - 1; j++) 
        str[j] = str[j + 1];
      max--;
    }
  }
}

//Error format
void err(char* msg) {
  printf("Erro: \"%s\"\n", msg);
}

void cls() {
  char regex[13] = "\e[1;1H\e[2J";
  if(!syscall(SYS_write, STDIN_FILENO, regex, sizeof(char) * 13)) {
    err("syscall gerou erro!");
  }
}

void dir() {
  struct dirent *dfile;
  DIR* direc = opendir(".");
  if(!direc)  {
    err("opendir gerou erro!");
    return;
  }
  while(1) {
    dfile = readdir(direc);
    if(!dfile) break;
    printf("%s\n", dfile->d_name);
  }
}

void date() {
  time_t now = time(NULL);
  struct tm timeFormat;
  char temp[11];
  timeFormat = *localtime(&now);
  strftime(temp, sizeof(temp), "%d:%m:%Y", &timeFormat);
  printf("%s\n", temp);
}

void timeShell() {
  time_t now = time(NULL);
  struct tm timeFormat;
  char temp[9];
  timeFormat = *localtime(&now);
  strftime(temp, sizeof(temp), "%H:%M:%S", &timeFormat);
  printf("%s\n", temp);
}