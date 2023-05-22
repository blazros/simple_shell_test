#include "shell.h"

/**
 * print_uns_num - prints unsigined number
 * @n: unsingined int
 * Return: always void
 */

void print_num(unsigned int n)
{
    unsigned int x = n;

    if ((x / 10) > 0)
        print_num(x / 10);

    _putchar(x % 10 + '0');
}

/**
 * print_int
 * @n: integar
 * Return: always void
 */

void print_int(int n)
{
    unsigned int x = n;

    if (n < 0)
    {
        _putchar('-');
        x = -x;
    }
    if ((x / 10) > 0)
        print_num(x / 10);

    _putchar(x % 10 + '0');
}