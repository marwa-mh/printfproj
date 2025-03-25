//len = _printf("Let's try to printf a simple sentence.\n");
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
int _printf(const char *format, ...)
{
    va_list args;
    int args_count = 0;
    int char_count =0;
    int index=0;
    int variadic_arr_count = 0;
    unsigned int malloc_size = 0;
    char* str;
    char current_conversion;
    int str_index=0;
    format_type_t ft[] = {
	{'c', get_char_count},
	
	{'s', get_string_count}
	};
    while( format[index] != '\0')
    {

        if (format[index]=='%')
        {
            index++;
            current_conversion=format[index];// extract_conversion(format,index);
            
            if (current_conversion == 'c')
            {
               malloc_size = malloc_size + sizeof(char);
               
                
                
            }else if (current_conversion == 's')
            {
                // _printf("String:[%s]\n", "I am a string !");15
               malloc_size = malloc_size + sizeof(char*length);
                
            }
           variadic_arr_count++;
          
        }
        
       index++;
        
    }
  //  printf("argument count=%d\n",args_count);
    str =malloc(malloc_size);
    index = 0;
    str_index=0;
    
     while( format[index] != '\0')
    {
       
        if (format[index]=='%')
        {
            index++;
            current_conversion= extract_conversion(format,index);
          //  printf("current_conversion=%c\n",current_conversion);
            str[str_index]= current_conversion;
            
              str_index++;
        } 
        else
        {
            _putchar(format[index]);
        }
   
            index++;
        
    }
    
    va_start(args,str);
    int j =0;
    int i=0;
    int length; //csics
    while( str[i]!='\0')
    {
       // printf("str[i]=%c\n",str[i]);
       //format_type_t ft[] = {
//	{'c', get_char_count},
	
//	{'s', get_string_count}
	};
        while (j < 2)
        {
            if (ft[j].type == str[i])
            {
             length=   ft[j].name(args);//function pointer
             char_count = char_count + length;
                break;
            }
            j++;
        }
        i++;
    }
    
    return char_count;
}
