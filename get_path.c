#include "main.h"
/**
 * get_path - gets path to a command
 * @cmd: the command to execute
 * Return: the path of the command
 */
char *get_path(char *cmd)
{
	char *path, *cppath, *cmdpath, *token;
	int cmdlen, pathlen;
	struct stat buf;

	path = getenv("PATH");
	cppath = strdup(path);
	if (path)
	{
		token = strtok(cppath, ":");
		while (token != NULL)
		{
			cmdlen = strlen(cmd);
			pathlen = strlen(token);
			cmdpath = malloc(cmdlen + pathlen + 2);
			strcpy(cmdpath, token);
			strcat(cmdpath, "/");
			strcat(cmdpath, cmd);
			strcat(cmdpath, "\0");
			if (stat(cmdpath, &buf) == 0)
			{
				free(cppath);
				return (cmdpath);
			}
			else
			{
				free(cmdpath);
				token = strtok(NULL, ":");
			}
		}
		free(cppath);
		if (stat(cmd, &buf) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
