#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>


/**
 * struct variables - variables
 * @av: command line arguments
 * @buffer: buffer of command
 * @env: environment variables
 * @count: count of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 * @commands: double pointer to commands
 */

typedef struct variables
{
	char **av;
	char **argv;
	char *buffer;
	char **commands;
	char **env;
	size_t count;
	int status;
} vars_t;


/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;


/* Environment variable */
char **create_env(char **env);
void free_env(char **env);

/* Utility functions */
ssize_t _puts(char *str);
char *_strdup(char *strtodup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
unsigned int _strlen(char *str);

/* Tokenization */
char **tokenize(char *buf, char *delimiter);
char **_realloc(char **ptr, size_t *size);
char *_strtok(char *str, const char *delim);

/* Path Handler */
void check_for_path(vars_t *vars);
char *find_path(char **env);
int path_exec(char *command, vars_t *vars);
int execute_cwd_cmd(vars_t *vars);
int check_for_dir(char *str);

/* Environment handlers */
void (*check_for_builtins(vars_t *vars))(vars_t *vars);
void custom_exit(vars_t *vars);
void _env(vars_t *vars);
void _setenv(vars_t *vars);
void _unsetenv(vars_t *vars);

/* File Finder */
void add_key(vars_t *vars);
char **find_key(char **env, char *key);
char *add_value(char *key, char *value);
int _atoi(char *str);

/* Error Handling */
void print_error(vars_t *vars, char *msg);
void _puts2(char *str);
char *_uitoa(unsigned int count);


#endif
