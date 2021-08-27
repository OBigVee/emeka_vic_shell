#include <stdio.h>
#include "sshell.h"

/**
* shell_prompt1 - return $ string as a single line prompt
* Return: 0
*/

void shell_prompt1(void)
{
	fprintf(stderr, "$$");
}


/**
* shell_prompt1 - return > string as a multi line prompt
* Return: 0
*/
void shell_prompt2(void)
{
	fprintf(stderr, "> ");
}
