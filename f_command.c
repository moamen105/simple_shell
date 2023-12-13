#include "main.h"

/**
 * f_command - Simple Shell
 * @command: The command to execute
 * Return: Path to the command or NULL
 */
char *f_command(char *command)
{
char *path = strdup(getenv("PATH"));
char *token = strtok(path, ":");

while (token)
{
char *path_command = malloc(PATH_MAX);
if (!path_command)
{
free(path);
return (NULL);
}

snprintf(path_command, PATH_MAX, "%s/%s", token, command);

if (is_exec(path_command))
{
free(path);
return (path_command);
}

free(path_command);
token = strtok(NULL, ":");
}

free(path);
return (NULL);
}
