#include "shell.h"

/**
 * shell_prompt - prints shell prompt
 * Return: void
 */

void shell_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "vic_emeka>$ ", 12);
	}
}
