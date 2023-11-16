#ifndef SHELL_H
#define SHELL_H

#define INPUT_SIZ 1024
#define CHUNK_SIZE 128

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

extern char **environ;

int _strlen(char *str);
int _strcmp(const char *str_1, const char *str_2);
void show_prompt(void);
char *_getinput(void);
void run_cmd(char *input);
void exit_cmd(void);
void print_env(void);

#endif
