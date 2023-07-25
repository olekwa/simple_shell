#include "main.h"

/**
 * _memcpy - The transfer of data between void pointers.
 * @newptr: location of pointer
 * @ptr: origin of pointer.
 * @size: new pointer's size.
 * Return: no return.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - new memory allocations.
 * @ptr: previously allocated memory pointer.
 * @old_size: size of the pointer space allotted in bytes.
 * @new_size: updated memory block size, in bytes.
 *Return: pointer address.
 * if new_size == old_size gives an unchanged ptr back.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - provides a double pointer with a new memory block.
 * @ptr: pointer to a double-pointed memory allocation.
 * @old_size: size of the pointer space allotted in bytes.
 * @new_size: updated memory block size, in bytes..
 * Return: ptr.
 * if new_size == old_size gives an unchanged ptr back.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
