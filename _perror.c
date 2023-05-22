#include "shell.h"
/**
 *  _prerror - prints custom error
 * @argv: command ran
 * @c: error counter
 * @cmd: command
 * Return: void
 */
void _perror(char **argv, int c, char **cmd)
{
    char *am = _itoa(c);

    PROMPT(argv[0]);
    PROMPT(": ");
    PROMPT(am);
    PROMPT(": ");
    PROMPT(cmd[0]);
    PROMPT(": bad number: ");
    PROMPT(cmd[1]);
    PROMPT("\n");
    free(am);
}