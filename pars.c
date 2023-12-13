#include "main.h"
/**
 * pars - Simple Shell
 * @buffer: The command to execute
 * Return: void
 */
char **pars(char *buffer)
{
int argc;
char *arg;
char **argv;
argc = 0;
argv = malloc(sizeof(char *) * BUFFER_SIZE);
arg = strtok(buffer, " ");

while (arg)
{
if (arg[0] == '/')
{
char *command_name = strrchr(arg, '/');
if (command_name)
{
argv[argc++] = strdup(command_name + 1);
}
else
{
argv[argc++] = strdup(arg);
}
}
else
{
argv[argc++] = strdup(arg);
}

arg = strtok(NULL, " ");
}

argv[argc] = NULL;

return (argv);
}
