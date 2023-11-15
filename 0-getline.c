#include "shell.h"

/**
 * _getline- user-defined getline function reads input from a file
 * stream and stores in a dynamically allocated buffer (segment in
 * memory).
 *
 * @stor_str: pointer to pointer where array of char (string) will
 * be stored. Its a memory location.
 *
 * @stor_siz:pointer representing size of memory where characters
 * will be stored. Keeps track of allocated memory and can resize
 * depending on operations.
 *
 * @stream: pointer to input which is to be read (File Structure).
 *
 * Return:No of char read or NULL.
 *
 */
ssize_t _getline(char **stor_str, size_t *stor_siz, FILE *stream);

ssize_t _getline(char **stor_str, size_t *stor_siz, FILE *stream)
{
	char *buffer = *stor_str;
	size_t no_char = 0;
	int ch;

	if (*stor_str == NULL)
	{
		*stor_siz = 128;/*Initial buffer size*/
		*stor_str = (char *)malloc(*stor_siz);

		if (*stor_str == NULL)
			return (-1);/*Memory allocation failed*/
	}

	while (1)
	{
		ch = fgetc(stream);

		if (ch == EOF)
		{
			if (no_char == 0)
				return (-1);/*No data read, and we've reached the end of the file*/
			buffer[no_char] = '\0';
			return (no_char);/*Return the number of characters read*/
		}
		if (ch == '\n')
		{
			buffer[no_char] = '\0';
			return (no_char);/*Return the number of characters read*/
		}
		buffer[no_char] = (char)ch;
		no_char++;
		if (no_char >= *stor_siz)
		{
			/*Resize the buffer when it's full*/
			*stor_siz *= 2;
			*stor_str = (char *)realloc(*stor_str, *stor_siz);

			if (*stor_str == NULL)
				return (-1);/*Memory allocation failed*/
			buffer = *stor_str + no_char;/*Update the buffer pointer*/
		}
	}
}
