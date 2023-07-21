#include "main.h"


/**
 * read_line - examines an input string
 *
 * @i_eof: the returned result of the getline function
 *
 * Return:  string inputted
 */

char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
