#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function.
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list1 list1;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list1, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list1);
			precision = get_precision(format, &i, list1);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list1, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_char += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list1);

	return (printed_char);
}

/**
 * print_buffer - Print the contents of buffer if it exist
 * @buffer: Array of char
 * @buff_ind: Index to add next char at, represents length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}