#include "shell.h"
/**
 * main - Infinite loop that runs shell
 * @ac: Arg count
 * @av: args passed to shell at beginning of prog
 * @env: Environment
 * Return: zero
 */
int main(int ac, char **av, char **env)
{
	char *line;
	char **args;
	int status;
	char *tmp = NULL;
	char *er;
	char *filename;
	int flow;

	er = "Error";
	do {
		shell_prompt();
		line = get_line();
		args = split_line(line);
		flow = be_sure(args[0], args);
		if (flow == 2)
		{
			filename = args[0];
			args[0] = find_path(args[0], tmp, er);
			if (args[0] == er)
			{
				args[0] = search_cwd(filename, er);
				if (args[0] == filename)
				{
					write(1, er, 5);
				}
			}
		}
		if (args[0] != er)
			status = execute_prog(args, line, env, flow);
		free(line);
		free(args);
	} while (status);
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	if (!env)
		(void)env;

	return (EXIT_SUCCESS);
}
