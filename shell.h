#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
void handle_builtin(char **command, char **argv, int *status, int idex);
void exit_shell(char **command, char **argv, int *status, int idex);
void print_env(char **command, int *status);
int is_builtin(char *command);
extern char **environ;
char *_strcat(char *dest, char *src);
char *read_line(void);
int _str_length(const char *s);
int _str_compare(char *s1, char *s2);
char *_string_copy(char *destination, char *source);
char *_string_duplicate(char *str);
char *_str_concatenate(char *dest, char *src);
char **tokenizer(char *line);
void free2D(char **arr);
char *_getenv(char *variable);
char *_getpath(char *command);
int _execute(char **command, char **argv, int idx);
void printerror(char *name, char *cmd, int idx);
void reverse_string(char *str, int len);
char *_itoa(int n);
int _atoi(char *str);
int is_positive_number(char *str);

#endif
