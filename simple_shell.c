#include "main.h"

char **fill_argv(char *line, int tok_count, char **av);
/**
 * main - simple shell
 * @ac: argument count
 * @av: argument vector/array
 * Return: 0 on success or 1 on failure
 */
int main(int ac, char **av, char **envp)
{
	char *cue = "#cisfun$ ", *line_getter = NULL;
	char *line_getter_cpy = NULL;
	size_t num = 0;
	ssize_t save_prompt;
	char *tok;
	int token_count = 0;
	char *delimiter = " \n";

	(void)ac;
	while (1)
	{
		printf("%s", cue);
		save_prompt = _getline(&line_getter, &num, stdin);
		if (save_prompt == -1)
		{
			printf("Exiting the shell ...........\n");
			return (-1);
		}

		line_getter_cpy = malloc(sizeof(char) * save_prompt);
		if (line_getter_cpy == NULL)
			return (-1);
		strcpy(line_getter_cpy, line_getter);

		tok = strtok(line_getter, delimiter);
		while (tok != NULL)
		{
			token_count++;
			tok = strtok(NULL, delimiter);
		}
		token_count++;
		av = fill_argv(line_getter_cpy, token_count, av);
		exec_handler(av, envp);
	}
	free(av);
	free(line_getter_cpy);
	free(line_getter);
	return (0);
}

char **fill_argv(char *line, int tok_count, char **av)
{
	int a;
	char *delimiter = " \n";
	char *tok;

	av = malloc(sizeof(char *) * tok_count);
	tok = strtok(line, delimiter);
	for (a = 0; tok != NULL; a++)
	{
		av[a] = malloc(sizeof(char) * strlen(tok));
		strcpy(av[a], tok);
		tok = strtok(NULL, delimiter);
	}
	av[a] = NULL;
	return (av);
}
