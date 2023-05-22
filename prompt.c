#include "shell.h"

/**
 * prompt - waits for user input
 */

void prompt(void)
{
    PROMPT("SHELLFISH> ");
}

/**
 * error_handler - dispalys error with extra information
 * @input: input from user
 * @counter: loop counter
 * @argv: input
 * Return: always void
 */

void error_handler(char *input, int counter, char **argv)
{
    char *error;

    PROMPT(argv[0]);
    PROMPT(": ");
    error = _itoa(counter);
    PROMPT(error);
    free(error);
    PROMPT(": ");
    PROMPT(input);
    PROMPT(": not found\n");
}