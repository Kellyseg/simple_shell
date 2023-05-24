#include "main.h"
/**
 * _realloc - re allocates memory
 * @ptr: pointer
 * @old_size: old size
 * @new_size: new_size
 * Return: void pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result = NULL;

	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (new_size)
	{
		if (new_size == old_size)
		{
			return (ptr);
		}

		result = malloc(new_size);
		if (result)
		{
			if (old_size > new_size)
			memcpy(result, ptr, new_size);
			else if (new_size > old_size)
			memcpy(result, ptr, old_size);
			free(ptr);
		}
	}
	else
	{
		if (ptr)
		{
			free(ptr);
		}
	}
	return (result);
}
