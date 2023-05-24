#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUFFER_SIZE 1024


void exec_handler(char **av, char **envp);
char *get_path(char *cmd);
ssize_t _getline(char **lineptr, size_t *len, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif
