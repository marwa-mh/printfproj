#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
int get_char_count(va_list args);
int get_string_count(va_list args);
char extract_conversion(const char *format,int index);
typedef struct format_type
{
	char type; // c ,s ,f
	int (*name)(va_list args);
} format_type_t
