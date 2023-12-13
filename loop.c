#include "main.h"
/**
 * main - Main loop for the shell
 * Return: Always 0
 */
int main(void)
{
char buffer[BUFFER_SIZE];
char **argv;
char *command;

while (1)
{
if (isatty(STDIN_FILENO))
prompt();

if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
{
break;
}

buffer[strcspn(buffer, "\n")] = '\0';

if (strcmp(buffer, "exit") == 0)
{
break;
}
else if (strcmp(buffer, "env") == 0)
{
print_env();
continue;
}
argv = pars(buffer);
command = f_command(argv[0]);
if (!command)
{
fprintf(stderr, "%s: command not found\n", argv[0]);
free(argv);
continue;
}
exec_command(command, argv);
free(argv);
}
printf("\n");
return (0);
}
