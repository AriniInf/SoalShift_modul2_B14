#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

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
    struct stat sb;
    char dir[255] = "/home/ariniinf/Praktikum/praktikum2/hatiku/elen.ku";
    stat(dir, &sb);

    struct passwd *pw = getpwuid(sb.st_uid);
    struct group  *gr = getgrgid(sb.st_gid);

    char ong[255] = "www-data";
    if(strcmp((pw->pw_name),ong)==0 && strcmp((gr->gr_name),ong)==0)
    {
    chmod(dir, 0777);
    remove(dir);
    }
sleep(3);
}
  exit(EXIT_SUCCESS);
}
