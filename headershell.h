#ifndef HEADER_FILE_H
#define HEADER_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <limits.h>

extern char **environ;

/**
 * struct bltn - variables with info on builtins
 * @name: name
 * @func: pointer
 */

typedef struct bltn
{
	char *name;
	int (*func)(void);
} builtin;

int decoder(char **args);
void free_space(int x, ...);
void error_message(char **argv, char **args, int x);
void error_number(int x);
int exec(char **args);
int find(char **args);
int find_builtins(char **args);
int find_dirs(char **instruction, char **args);
void remove_equal_sign(char **string);
int countchars(char *string);
char **tokenize(char *string, int num);
char *search_path(char *string);
char *_strdup(char *s);
char _strcmp(char *string1, char *string2);
int _strlen(char *string);
int _atoi(char *string);
char *_strconcat(char *string1, char *string2);
void sig_transmission(int signal_no);
int exit_shell(char **args, char *string);
int print_environmt(void);
int main(__attribute__((unused)) int argc, char *argv[]);



#endif
