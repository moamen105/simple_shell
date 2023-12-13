#include "main.h"

/**
 * exec_command - Execute a command
 * @command: The command to execute
 * @args: The arguments for the command
 * Return: 0 on success, -1 on failure
 */
int exec_command(char *command, char **args)
{
pid_t pid;
int status;

if (strcmp(command, "exit") == 0)
return (-1);

pid = fork();
if (pid == 0)
{
execve(command, args, environ);
perror(command);
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Error forking");
}
else
{
waitpid(pid, &status, 0);
}

return (0);
}
