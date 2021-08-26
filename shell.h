#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define TOKENS_BUFFER_SIZE 64
#define LINE_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

extern char **environ;

/**
 * struct builtins - Has builtins and associated funcs
 * @arg: Builtins name
 * @builtin: Mathcing builtin func
 */

typedef struct builtins
{
	char *arg;
	void (*builtin)(char **args, char *line, char **env);
} builtins_t;

int main(int ac, char **av, char **env);

char *get_line(void);

char **split_line(char *line);

int execute_prog(char **args, char *line, char **env, int flow);

int check_for_builtins(char **args, char *line, char **env);

int launch_prog(char **args);

void exit_shell(char **args, char *line, char **env);

void env_shell(char **args, char *line, char **env);

char *find_path(char *args, char *tmp, char *er);

char *search_cwd(char *filename, char *er);

int be_sure(char *check, char **args);

void shell_prompt(void);

int builtins_checker(char **args);

char *save_path(char *tmp, char *path);

char *read_dir(char *er, struct dirent *s, char *fi, int l, char *p, char *t);

void shell(int ac, char **av, char **env);

char *_getenv(char *env);
#endif
