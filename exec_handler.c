#include "main.h"
/**
 * exec_handler - handles execution
 * @av: argument vector
 * Return: void;
 */
void exec_handler(char **av, char **envp)
{
	char *filepath = NULL, *entry = NULL;
	pid_t child_pid;
	struct stat buf;

	if (av)
	{
		entry = av[0];

		filepath = get_path(entry);
		if (stat(filepath, &buf) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				return;
			}
			if (child_pid == 0)
			{
				if (execve(filepath, av, envp) == -1)
				{
					perror("Error");
				}
			}
			else
			{
				wait(NULL);
			}
		}
		if (strcmp(entry, "exit") == 0)
			exit(0);
	}
}
