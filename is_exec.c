#include "main.h"
/**
 * is_exec - Simple Shell
 * @path: The command to execute
 * Return: null
 */
int is_exec(char *path)
{
if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
{
return (1);
}
return (0);
}
