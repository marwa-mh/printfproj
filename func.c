#include "main.h"
#include <string.h>
int get_char_count(va_list args)
{
    //_putchar(;)
	return (1);
}

int get_string_count(va_list args)
{
	char *str = va_arg(args, char*);

	return (strlen(str));
}
char extract_conversion(const char *format,int index)
{
    
    return format[index];
}
