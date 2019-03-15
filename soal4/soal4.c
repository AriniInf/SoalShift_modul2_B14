
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir(".")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    char path[100]="makan_enak.txt";
    struct stat stats;
	FILE *file;
	char nomor[100];
int counter = 2,i;
    stat(path, &stats);
    printf("%ld\n", time(NULL));
    while(time(NULL)-30<stats.st_atime){
	for(i=1;i<=counter;i++){
	sprintf(nomor,"makan_sehat%d.txt",i);
	file = fopen(nomor, "r");
	if(file==NULL)break;
	}
	file = fopen(nomor,"w");
	fclose(file);
	counter++;
	sleep(5);
	}
  }
  exit(EXIT_SUCCESS);
}
