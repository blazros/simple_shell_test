#include "shell.h"

/**
 * _getline - reads input from user
 * Return: user input
 */

char *_getline()
{
    int i, buffsize = B_SIZE, read_char;
    char c = 0;
    char *buff = malloc(buffsize);

    if (buff == NULL)
    {
        free(buff);
        return (NULL);
    }

    for (i = 0; c != EOF && c != '\n'; i++)
    {
        fflush(stdin);
        read_char = read(STDIN_FILENO, &c, 1);
        if (read_char == 0)
        {
            free(buff);
            exit(EXIT_SUCCESS);
        }

        buff[i] = c;

        if (buff[0] == '\n')
        {
            free(buff);
            return ("\0");
        }

        if (i >= buffsize)
        {
            buff = _realloc(buff, buffsize, buffsize + 1);
            if (buff == NULL)
            {
                return (NULL);
            }
        }
    }
    buff[i] = '\0';
    hash_handler(buff);
    return (buff);
}

/**
 * hash_handler - removes everthing after #
 * @buff: input
 * Return: always void
 */

void hash_handler(char *buff)
{
    int i;

    for (i = 0; buff[i] != '\0'; i++)
    {
        if (buff[i] == '#')
        {
            buff[i] = '\0';
            break;
        }
    }
}