#include "shell.h"

/**
 * _realloc - reallocates memory using malloc and free
 * @ptr: input
 * @prev: old pointer size
 * @new: new pointer size
 * Return: realloc pointers
 */

void *_realloc(void *ptr, unsigned int prev, unsigned int new)
{
    void *result;

    if (new == prev)
        return (ptr);
    if (new == 0 && ptr)
    {
        free(ptr);
        return (NULL);
    }
    result = malloc(new);
    if (result == NULL)
        return (NULL);
    if (ptr == NULL)
    {
        array_fill(result, '\0', new);
        free(ptr);
    }
    else
    {
        _mcpy(result, ptr, prev);
        free(ptr);
    }
    return (result);
}

/**
 * _mcpy - copies memory from a block from another
 * @dest: ip1
 * @src: ip2
 * @n: size
 * Return: pointer
 */

char *_mcpy(char *dest, char *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    return (dest);
}

/**
 * array_fill - Fill An Array By Constant Byte
 * @a: ptr
 * @el: int
 * @len: int
 *Return: ptr
 */
void *array_fill(void *a, int el, unsigned int len)
{
    char *p = a;
    unsigned int i = 0;

    while (i < len)
    {
        *p = el;
        p++;
        i++;
    }
    return (a);
}

/**
 * _calloc -  Allocates Memory For An Array, Using Malloc.
 * @size: Size
 * Return: ptr
 */

void *_calloc(unsigned int size)
{
    char *a;
    unsigned int i;

    if (size == 0)
        return (NULL);
    a = malloc(size);
    if (a == NULL)
        return (NULL);
    for (i = 0; i < size; i++)
    {
        a[i] = '\0';
    }
    return (a);
}