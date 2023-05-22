#include "shell.h"

/**
 * main - simple shell (Shellfish)
 * @argc: argument counter
 * @argv: argument value
 * Return: always
 */

int main(__attribute__((unused)) int argc, char **argv)
{
    char *input;
    char **cmd;

    int index = 0;
    int status = 1;
    int am = 0;

    (void)argc;

    if (argv[1] != NULL)
        read_file(argv[1], argv);

    signal(SIGINT, signal_to_handle);
    while (status)
    {
        index++;
        if (isatty(STDIN_FILENO))
            prompt();
        input = _getline();
        if (input[0] == '\0')
        {
            continue;
        }
        history(input);
        cmd = parse_cmd(input);
        if (_strcmp(cmd[0], "exit") == 0)
        {
            exit_blt(cmd, input, argv, index);
        }
        else if (check_builtin(cmd) == 0)
        {
            am = builtin_cmd(cmd, am);
            free(cmd);
            free(input);
            continue;
        }
        else
        {
            am = execmd(cmd, input, index, argv);
        }
        free(cmd);
        free(input);
    }
    return (status);
}

/**
 * check_builtin - check builtin
 *
 * @cmd: command to check
 * Return: 0 on success, -1 on failure
 */

int check_builtin(char **cmd)
{
    blt_in fun[] = {
        {"cd", NULL},
        {"help", NULL},
        {"echo", NULL},
        {"history", NULL},
        {NULL, NULL}};
    int i = 0;

    if (*cmd == NULL)
    {
        return (-1);
    }

    while ((fun + i)->command)
    {
        if (_strcmp(cmd[0], (fun + i)->command) == 0)
            return (0);
        i++;
    }
    return (-1);
}

/**
 * create_env - create array of enviroment variable
 * @envi: array of enviroment variable
 * Return: void
 */

void create_env(char **envi)
{
    int i;

    for (i = 0; environ[i]; i++)
        envi[i] = _strdup(environ[i]);
    envi[i] = NULL;
}
