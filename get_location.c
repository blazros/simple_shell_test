#include "shell.h"

/**
 * path_cmd - search in $PATH for exe cmd
 * @cmd - command
 * Return: 0 on success, 1 on failure
 */

int path_cmd(char **cmd)
{
    char *path, *path_tok, *cmd_path;
    struct stat buf;

    path = _getenv("PATH");
    path_tok = _strtok(path, ":");
    while (path_tok != NULL)
    {
        cmd_path = full_path(*cmd, cmd_path);
        if (stat(cmd_path, &buf) == 0)
        {
            *cmd = _strdup(cmd_path);
            free(cmd_path);
            free(path);
            return (0);
        }
        free(cmd_path);
        path_tok = _strtok(NULL, ":");
    }
    free(path);
    return (1);
}

/**
 * full_path - generates full path
 * @token: command
 * @dir_path: command directory
 * Return: full path
 */

char *full_path(char *token, char *dir_path)
{
    char *cmd;
    size_t len;

    len = _strlen(dir_path) + _strlen(token) + 2;
    cmd = malloc(sizeof(char) * len);
    if (cmd == NULL)
    {
        return (NULL);
    }

    memset(cmd, 0, len);

    cmd = _strcat(cmd, dir_path);
    cmd = _strcat(cmd, "/");
    cmd = _strcat(cmd, token);

    return (cmd);
}

/**
 * _getenv - get the env variable
 * @name: enviroment variable
 * Return: value of env
 */

char *_getenv(char *name)
{
    size_t nl, vl;
    char *value;
    int i, x, j;

    nl = _strlen(name);
    for (i = 0; environ[i]; i++)
    {
        if (_strncmp(name, environ[i], nl) == 0)
        {
            vl = _strlen(environ[i]) - nl;
            value = malloc(sizeof(char) * vl);
            if (!value)
            {
                free(value);
                perror("unable to alloc");
                return (NULL);
            }

            j = 0;
            for (x = nl + 1; environ[i][x]; x++, j++)
            {
                value[j] = environ[i][x];
            }
            value[j] = '\0';

            return (value);
        }
    }

    return (NULL);
}