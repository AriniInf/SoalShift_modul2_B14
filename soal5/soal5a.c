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

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
        time_t t;
        time(&t);
        struct tm *waktu;

        waktu = localtime(&t);
        char dir[100];
        char nama[100];
        sprintf(nama, "%d:%d:%d-%d:%d", waktu->tm_mday, waktu->tm_mon+1, waktu->tm_year+1900, waktu->tm_hour, waktu->tm_min);
        printf("%s", nama);
        sprintf(dir, "/home/ariniinf/Praktikum/praktikum2/hasil/%s", nama);
        mkdir(dir, 0777);
	int i;
        for(i=1; i<30; i++){
                FILE *file_lama, *file_baru;
                file_lama = fopen("/var/log/syslog", "r");
                char file[100];
                sprintf(file, "/home/ariniinf/Praktikum/praktikum2/hasil/%s/log%d.log", nama, i);
                file_baru = fopen(file, "w");
                char cr;
                while(fscanf(file_lama, "%c", &cr) != EOF)
                {fprintf(file_baru, "%c", cr);}
                fclose(file_lama);
                fclose(file_baru);
                sleep(60);
        }
 }
  exit(EXIT_SUCCESS);
}
