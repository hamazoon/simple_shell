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
extern char **environ;

char *read_line(void);
int _str_length(const char *s);
int _str_compare(char *s1, char *s2);
char *_string_copy(char *destination, char *source);
char *_string_duplicate(char *str);
char *_str_concatenate(char *dest, char *src);
char **tokenizer(char *line);
void free2D(char **arr);
int _execute(char **command, char **argv);
#endif
