#include "shell.h"

/**
 * read_file - read files
 * @filename: filename
 * @argv: command ran
 * Return: 0
 */

void read_file(char *filename, char **argv)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int counter = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while ((getline(&line, &len, fp)) != -1)
    {
        counter++;
        file_parser(line, counter, fp, argv);
    }
    if (line)
        free(line);
    fclose(fp);
    exit(0);
}

/**
 * file_parser - check file commands
 * @line: file line
 * @counter: counter
 * @fp: file descriptor
 * @argv: command ran
 * Return: void
 */

void file_parser(char *line, int counter, FILE *fp, char **argv)
{
    char **cmd;
    int am = 0;

    cmd = parse_cmd(line);

    if (_strncmp(cmd[0], "exit", 4) == 0)
    {
        file_exit(cmd, line, fp);
    }
    else if (check_builtin(cmd) == 0)
    {
        am = builtin_cmd(cmd, am);
        free(cmd);
    }
    else
    {
        am = execmd(cmd, line, counter, argv);
        free(cmd);
    }
}

/**
 * file_exit - Exit Shell Case Of File
 * @line: file line
 * @counter: counter
 * @fp: file descriptor
 * @argv: command ran
 * Return: void
 */

void file_exit(char **cmd, char *line, FILE *fd)
{
    int status, i = 0;

    if (cmd[1] == NULL)
    {
        free(line);
        free(cmd);
        fclose(fd);
        exit(errno);
    }
    while (cmd[1][i])
    {
        if (_isalpha(cmd[1][i++]) < 0)
        {
            perror("bad number");
        }
    }
    status = _atoi(cmd[1]);
    free(line);
    free(cmd);
    fclose(fd);
    exit(status);
}