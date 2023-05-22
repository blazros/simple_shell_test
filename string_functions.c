#include "shell.h"

/**
 * _putchar - writes the character to stdout
 * @c: input
 * Return: character
 */

int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _strlen - gets length of string
 * @s: char
 * Return: always int
 */

int _strlen(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        continue;
    }

    return (i);
}

/**
 * _itoa - converts int to char
 * @n: input
 * Return: always char
 */

char *_itoa(unsigned int n)
{
    int len = 0;
    int i = 0;
    char *s;

    len = intlen(n);
    s = malloc(len + 1);
    if (!s)
        return (NULL);

    *s = '\0';
    while (n / 10)
    {
        s[i] = (n % 10) + '0';
        n /= 10;
        i++;
    }
    rev_arr(s, len);
    s[i + 1] = '\0';
    return (s);
}

/**
 * rev_arr - Reverses arrays
 * @arr: input array
 * @len: length of array
 * Return: always void
 */

void rev_arr(char *arr, int len)
{
    int i;
    char tmp;

    for (i = 0; i < (len / 2); i++)
    {
        tmp = arr[i];
        arr[i] = arr[(len - 1) - i];
        arr[(len - 1) - i] = tmp;
    }
}

/**
 * intlen - gets length of integar
 * @n: input int
 * Return: always int
 */

int intlen(int num)
{
    int len = 0;
    while (num != 0)
    {
        len++;
        num /= 10;
    }
    return (len);
}

/**
 * _strncpy - copies n items from string
 * @dest: input 1
 * @src: input 2
 * @n: intput
 * Return: always char
 */

char *_strncpy(char *dest, char *src, int n)
{
    int i;

    i = 0;
    while (i < n && *(src + i))
    {
        *(dest + i) = *(src + i);
        i++;
    }
    while (i < n)
    {
        *(dest + i) = '\0';
        i++;
    }
    return (dest);
}

/**
 * _atoi - convert to int
 * @s: input
 * Return: always int
 */

int _atoi(char *s)
{
    int i, j, n, x;
    i = n = 0;
    x = 1;

    while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
    {
        if (s[i] == '-')
            x *= -1;
        i++;
    }
    j = i;
    while ((s[j] >= '0') && (s[j] <= '9'))
    {
        n = (n * 10) + x * ((s[j]) - '0');
        j++;
    }
    return (n);
}

/**
 * _puts - prints a string
 * @str: input
 * return: always void
 */

void _puts(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i]);
    }
    _putchar('\n');
    return;
}

/**
 * _strcmp - compares 2 strings
 * @s1: ip 1
 * @s2: ip 2
 * Return: cmp value 0 if same, otherwise returns difference
 */

int _strcmp(char *s1, char *s2)
{
    int cmp = 0, i, len1, len2;
    len1 = _strlen(s1);
    len2 = _strlen(s2);

    if (s1 == NULL || s2 == NULL)
        return (1);
    if (len1 != len2)
        return (1);
    for (i = 0; s1[i]; i++)
    {
        if (s1[i] != s2[i])
        {
            cmp = s1[i] - s2[i];
            break;
        }
        else
            continue;
    }
    return (cmp);
}

/**
 * _isalpha - checks if c is alphabetical char
 *@c: input
 * Return: 1 if true, o if false
 */

int _isalpha(int c)
{
    if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

/**
 * _strcpy - copies a string
 * @dest: destination
 * @src: source
 * Return: copy of string
 */

char *_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * _strcat - adds two strings
 * @dest: string input 1
 * @src: string input 2
 * Return: two strings
 */

char *_strcat(char *dest, char *src)
{
    char *s = dest;

    while (*dest != '\0')
    {
        dest++;
    }

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return (s);
}

/**
 * _strsr - sreaches for a character in string
 * @s: string 1
 * @c: string 2
 * Return: ptr
 */

char *_strsr(char *s, char c)
{

    do
    {

        if (*s == c)
        {
            break;
        }
    } while (*s++);

    return (s);
}

/**
 * _strncmp - compares n characters in 2 strings
 * @s1: string input
 * @s2: string input
 * @n: characters to compare
 *
 * Return: 1 if different
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if (s1 == NULL)
        return (-1);
    for (i = 0; i < n && s2[i]; i++)
    {
        if (s1[i] != s2[i])
        {
            return (1);
        }
    }
    return (0);
}

/**
 * _strdup - duplicates a string
 * @str:String
 * Return: Duplicate String Failed Null
 */

char *_strdup(char *str)
{
    size_t len, i;
    char *str2;

    len = _strlen(str);
    str2 = malloc(sizeof(char) * (len + 1));
    if (!str2)
    {
        return (NULL);
    }

    for (i = 0; i <= len; i++)
    {
        str2[i] = str[i];
    }

    return (str2);
}