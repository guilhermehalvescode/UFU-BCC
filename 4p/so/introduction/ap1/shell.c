#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
#include <sys/syscall.h>
#include <errno.h>

#define MAX_SIZE 4

//Input format
void formatCommand(char* str, unsigned short int max);
//Error format
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

void err(char* msg) {
  printf("Erro: \"%s\"\n", msg);
}

void cls() {
  //Writes "\e[1;1H\e[2J" to stdout, giving an effect of cleared screen
  char regex[13] = "\e[1;1H\e[2J";
  if(!syscall(SYS_write, STDIN_FILENO, regex, sizeof(char) * 13)) {
    err("syscall gerou erro!");
  }
}

void dir() {
  //Uses struct dirent data structure
  struct dirent *ddir;
  //Opens current dir "."
  DIR* direc = opendir(".");
  if(!direc)  {
    err("opendir gerou erro!");
    return;
  }
  //while direc is readable, get ddir d_name and show it's name
  while(1) {
    ddir = readdir(direc);
    if(!ddir) break;
    printf("%s\n", ddir->d_name);
  }
}

void date() {
  //Get current seconds in Epoch standard
  time_t now = time(NULL);
  struct tm timeFormat;
  char temp[11];
  //Get struct tm, which represents local time
  timeFormat = *localtime(&now);
  /* 
  Convert time, storing conversion in 'temp', 
  passing it's size, the format desired and
  tm structured representing local time
  */
  strftime(temp, sizeof(temp), "%d:%m:%Y", &timeFormat);
  printf("%s\n", temp);
}

void timeShell() {
  //Get current seconds in Epoch standard
  time_t now = time(NULL);
  struct tm timeFormat;
  char temp[9];
  //Get struct tm, which represents local time
  timeFormat = *localtime(&now);
  /* 
  Convert time, storing conversion in 'temp', 
  passing it's size, the format desired and
  tm structured representing local time
  */
  strftime(temp, sizeof(temp), "%H:%M:%S", &timeFormat);
  printf("%s\n", temp);
}