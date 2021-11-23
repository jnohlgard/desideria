/*
 * Copyright (c) 2020 Joakim Nohlgård
 */
#include <cerrno>
#include <span>

#include <sys/stat.h>
#include <unistd.h>

extern "C" {

/*
int close(int fildes);
void _exit(int status) [[noreturn]];
int execve(const char *path, char *const argv[], char *const envp[]);
pid_t getpid(void);
int isatty(int fildes);
int kill(pid_t pid, int sig);
int link(const char *path1, const char *path2);
off_t lseek(int fildes, off_t offset, int whence);
int open(const char *path, int oflag, mode_t mode);
ssize_t read(int fildes, void *buf, size_t nbyte);
int stat(const char *restrict path, struct stat *restrict buf);
int unlink(const char *path);
pid_t wait(int *stat_loc);
ssize_t write(int fildes, const void *buf, size_t nbyte);
*/
}

#include "deri/console.hpp"

int close(int) {
  errno = ENOSYS;
  return -1;
}

int execve(const char *, char *const[], char *const[]) {
  errno = ENOMEM;
  return -1;
}

pid_t getpid(void) { return 1; }

int isatty(int) { return 1; }

int kill(pid_t, int) {
  errno = EINVAL;
  return -1;
}

int link(const char *, const char *) {
  errno = EMLINK;
  return -1;
}

off_t lseek(int, off_t, int) { return 0; }

int open(const char *, int, mode_t) { return -1; }

_READ_WRITE_RETURN_TYPE read(int, void *, size_t) { return 0; }

int stat(const char *, struct stat *st) {
  st->st_mode = S_IFCHR;
  return 0;
}

int unlink(const char *) {
  errno = ENOENT;
  return -1;
}

pid_t wait(int *) {
  errno = ECHILD;
  return -1;
}

_READ_WRITE_RETURN_TYPE write(int, const void *ptr, size_t len) {
  std::span<const std::byte> buffer{static_cast<const std::byte *>(ptr), len};
  deri::console.write(buffer);
  return len;
}

[[noreturn]] void _exit(int code) {
  while (true) {
  }
}
