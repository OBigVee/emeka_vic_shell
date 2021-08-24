#include "shell.h"



void main(void)
{
	char *line, token;
	char **args;
	int status;

	do
	{
		printf("shell>$");

		line = read_line();
		args = split_line(line);
		status = execve(args[0], args, NULL);
		if (status == -1)
		{
			perror("Error");
		}

	} while(status);
}

/**
 * read_line - read line from input
 * Return: line read
 */

char *read_line(void)
{
        char *line = "";
        size_t *n;

        n = malloc(3);
        getline(&line, n, stdin);

        return(line);
}

/**
 * split_line - tokenize line into words
 * Return: words
 */

char **split_line(char *line)
{
	int index = 0;
	char **words;

	char *word = strtok(line, " ");

	while (word != NULL)
	{
		words[index] = strdup(word);
		word = strtok(NULL, " ");
		index++;
	}
	return (words);
}
