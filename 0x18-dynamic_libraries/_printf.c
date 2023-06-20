#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...) {
    /* initialize argument list */
    va_list args;
    va_start(args, format);

    /* loop through format string and print each argument */
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            /* handle format specifier */
            switch (format[++i]) {
                case 'd': {  /* integer argument */
                    int val = va_arg(args, int);
                    printf("%d", val);
                    break;
                }
                case 's': {  /* string argument */
                    char *val = va_arg(args, char *);
                    printf("%s", val);
                    break;
                }
                /* add more cases for other specifiers as needed */

                default: {
                    putchar(format[i]);
                    break;
                }
            }
        } else {
            putchar(format[i]);
        }
    }

    /* cleanup argument list */
    va_end(args);
}
