#ifndef _SHELL_H_
#define _SHELL_H_

/*      env var       */
extern char **environ;

/*      Libraries used        */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
/*#include <limts.h>*/

/*       Function Prototypes       */
int _putchar(char c);
void print_num(unsigned int n);
void print_int(int n);
int intlen(int num);
int _strlen(char *s);
char *_itoa(unsigned int n);
void rev_arr(char *arr, int len);
int intlen(int num);
char *_strncpy(char *dest, char *src, int n);
void prompt(void);
void error_handler(char *input, int counter, char **argv);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void *_realloc(void *ptr, unsigned int prev, unsigned int new);
char *_mcpy(char *dest, char *src, unsigned int n);
void *array_fill(void *a, int el, unsigned int len);
void *_calloc(unsigned int size);
int builtin_cmd(char **cmd, int state);
void signal_to_handle(int sig);
int execmd(char **cmd, char *input, int c, char **argv);
int c_dir(char **cmd, int state);
int disp_history(char **c, int state);
int n_echo(char **cmd);
int echo_blt(char **cmd, int state);
int disp_help(char **cmd, int state);
int disp_env(char **cmd, int state);
int c_dir(char **cmd, int state);
void exit_blt(char **cmd, char *input, char **argv, int c);
void _perror(char **argv, int c, char **cmd);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(char *name);
int path_cmd(char **cmd);
void file_parser(char *line, int counter, FILE *fp, char **argv);
char **parse_cmd(char *input);
void file_exit(char **cmd, char *line, FILE *fd);
int check_builtin(char **cmd);
void hash_handler(char *buff);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
char *full_path(char *token, char *dir_path);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
void read_file(char *filename, char **argv);
char *_getline();
int history(char *input);
void free_env(char **env);
/*     Macros     */
#define PATH_MAX 4096
#define B_SIZE 1024
#define DELIM " \t\r\n\a"
#define PROMPT(c) (write(STDOUT_FILENO, c, _strlen(c)))
/* STDOUT_FILENO = 1*/

/*    struct    */
/**
 * struct built_in - contains built in to handle and execute functions
 * @command: pointer to char
 * @fun: executable functions
 */

typedef struct built_in
{
    char *command;
    int (*fun)(char **line, int am);
} blt_in;

#endif