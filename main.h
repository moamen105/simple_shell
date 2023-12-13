#ifndef MAIN_H
#define MAIN_H

#define ARG_MAX 4096
#define BUFFER_SIZE 1024
char *args[ARG_MAX];
extern char **environ;
char buffer[BUFFER_SIZE];
char *temp_command;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>
#include <sys/wait.h>


char *f_command(char *command);
int is_exec(char *path);
char **pars(char *buffer);
void prompt(void);
int exec_command(char *command, char **args);
void print_env(void);




#endif
