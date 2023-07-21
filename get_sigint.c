#include "main.h"


/**
 * get_sigint - Ctrl + C call in quick response
 * @sig: operator for signals
 */

void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
