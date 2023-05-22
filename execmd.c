#include "shell.h"

/**
 * builtin_cmd - executes builtin commands
 * @cmd: input command
 * @state: previous state of execution
 * Return: 0 on success, -1 on fail
 */

int builtin_cmd(char **cmd, int state)
{
    blt_in cmd_list[] = {
        {"cd", c_dir},
        {"env", disp_env},
        {"help", disp_help},
        {"echo", echo_blt},
        {"history", disp_history},
        {NULL, NULL}};

    int i = 0;

    while ((cmd_list + 1)->command)
    {
        if (_strcmp(cmd[0], (cmd_list + i)->command) == 0)
        {
            return ((cmd_list + i)->fun(cmd, state));
        }
        i++;
    }
    return (-1);
}

/**
 * execmd - ex shell commands
 * @cmd: input command
 * @input: user input
 * @c: exe time
 * @argv: command ran
 * Return: always
 */

int execmd(char **cmd, char *input, int c, char **argv)
{
    int status;
    pid_t pid;

    if (*cmd == NULL)
    {
        return (-1);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Error");
        return (-1);
    }

    if (pid == 0)
    {
        if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
        {
            path_cmd(cmd);
        }

        if (execve(*cmd, cmd, environ) == -1)
        {
            error_handler(cmd[0], c, argv);
            free(input);
            free(cmd);
            exit(EXIT_FAILURE);
        }
        return (EXIT_SUCCESS);
    }
    wait(&status);
    return (0);
}

/**
 * signal_to_handle - handles captured signal
 * @sig: input signal
 * Return: void
 */

void signal_to_handle(int sig)
{
    if (sig == SIGINT)
    {
        PROMPT("\n$ ");
    }
}