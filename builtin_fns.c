#include "shell.h"

/**
 * exit_blt - exit shell
 * @cmd: command
 * @input: user input
 * @argv: command ran
 * @count: execute count
 * Return: void
 */

void exit_blt(char **cmd, char *input, char **argv, int c)
{
    int status;
    int i = 0;
    if (cmd[1] == NULL)
    {
        free(input);
        free(cmd);
        exit(EXIT_SUCCESS);
    }
    while (cmd[1][i])
    {
        if (_isalpha(cmd[1][i++]) != 0)
        {
            _perror(argv, c, cmd);
            break;
        }
        else
        {
            status = _atoi(cmd[1]);
            free(input);
            free(cmd);
            exit(status);
        }
    }
}

/**
 * c_dir - change directory
 * @cmd: command
 * @state: input 2
 * Return: 0 on success, 1 on failure
 */

int c_dir(char **cmd, __attribute__((unused)) int state)
{
    int value = -1;
    char cwd[PATH_MAX];

    if (cmd[1] == NULL)
        value = chdir(getenv("HOME"));
    else if (_strcmp(cmd[1], "-") == 0)
    {
        value = chdir(getenv("OLDPWD"));
    }
    else
        value = chdir(cmd[1]);

    if (value == -1)
    {
        perror("hsh");
        return (-1);
    }
    else if (value != -1)
    {
        getcwd(cwd, sizeof(cwd));
        setenv("OLDPWD", getenv("PWD"), 1);
        setenv("PWD", cwd, 1);
    }
    return (0);
}

/**
 * disp_env - displays env variable
 * @cmd: command
 * @state: input 2
 * Return: 0
 */

int disp_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int state)
{
    size_t i;
    int len;

    for (i = 0; environ[i] != NULL; i++)
    {
        len = _strlen(environ[i]);
        write(1, environ[i], len);
        write(1, "\n", 1);
    }
    return (0);
}

/**
 * disp_help - displays help screen
 * @cmd: command
 * @state: input 2
 * Return: 0 on success, 1 on failure
 */

int disp_help(char **cmd, __attribute__((unused)) int state)
{
    int fd, fw, rd = 1;
    char c;

    fd = open(cmd[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error");
        return (0);
    }
    while (rd > 0)
    {
        rd = read(fd, &c, 1);
        fw = write(STDOUT_FILENO, &c, rd);
        if (fw < 0)
        {
            return (-1);
        }
    }
    _putchar('\n');
    return (0);
}

/**
 * echo_blt - echo cases
 * @cmd: command
 * @state: input 2
 * Return: 0 on success, 1 on failure
 */

int echo_blt(char **cmd, int state)
{
    char *path;
    unsigned int pid = getppid();

    if (_strcmp(cmd[1], "$?") == 0)
    {
        print_int(state);
        PROMPT("\n");
    }
    else if (_strncmp(cmd[1], "$$", 2) == 0)
    {
        print_num(pid);
        PROMPT("\n");
    }
    else if (_strncmp(cmd[1], "$PATH", 5) == 0)
    {
        path = _getenv("PATH");
        PROMPT(path);
        PROMPT("\n");
        free(path);
    }
    else
        return (n_echo(cmd));
    return (1);
}

/**
 * n_echo - executes normal echo
 * @cmd: command
 * Return: 0 on success, 1 on failure
 */

int n_echo(char **cmd)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execve("/bin/echo", cmd, environ) == -1)
        {
            return (-1);
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        return (-1);
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (1);
}

/**
 * disp_history - displays user input history
 * @c: command
 * @state: input 2
 * Return: 0 on success, 1 on failure
 */

int disp_history(__attribute__((unused)) char **c, __attribute__((unused)) int state)
{
    char *filename = ".simple_shell_history";
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int counter = 0;
    char *am;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return (-1);
    }
    while ((getline(&line, &len, fp)) != -1)
    {
        counter++;
        am = _itoa(counter);
        PROMPT(am);
        free(am);
        PROMPT(" ");
        PROMPT(line);
    }
    if (line)
        free(line);
    fclose(fp);
    return (0);
}