#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  DIR* dir = opendir("tmp");
  if (dir == NULL) {
    return -1;
  }

  struct dirent* dp = malloc(sizeof(struct dirent));
  struct stat* info = malloc(sizeof(struct stat));
  while ((dp = readdir(dir)) != NULL) {
    if (dp->d_type == DT_REG) {
      char filename[256];
      snprintf(filename, sizeof(filename), "%s%s", "tmp/", dp->d_name);
      stat(filename, info);
      if (info->st_nlink > 1) {
        long unsigned int ino = info->st_ino;
        long unsigned int nlinks = info->st_nlink;
        long unsigned int cur_link = 1;
        DIR* in_dir = opendir("tmp");
        struct dirent* in_dp = malloc(sizeof(struct dirent));
        printf("%s - ", dp->d_name);
        while ((in_dp = readdir(in_dir)) != NULL) {
          if (in_dp->d_type == DT_REG) {
            snprintf(filename, sizeof(filename), "%s%s", "tmp/", in_dp->d_name);
            stat(filename, info);
            if (ino == info->st_ino) {
              if (cur_link == nlinks) {
                printf("%s\n", in_dp->d_name);
                break;
              } else {
                printf("%s, ", in_dp->d_name);
              }
              ++cur_link;
            }
          }
        }
        closedir(in_dir);
      }
    }
  }
  closedir(dir);

  return 0;
}
