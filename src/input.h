#ifndef STDDEF_H
    #include <stddef.h>
#endif

#ifndef STRING_H
    #include <string.h>
#endif

#ifndef STDIO_H
    #include <stdio.h>
#endif

#ifndef STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef CTYPE_H
    #include <ctype.h>
#endif

#ifndef STDLIB_H
    #include <stdlib.h>
#endif

#ifndef ERRNO_H
    #include <errno.h>
#endif

#ifndef INPUT_H
    #define INPUT_H    

    /* Reads string from stdin and writes it to the buffer */
    void stdin_get_command(char *buffer, size_t buffer_length);

    /* Expand command budder. 
     * Currently it doubles the buffer size
     *
     * Return 0 if success expanding
     * Return ENOMEM if reallocation failed*/
    int expand_command_buffer(char *buffer, size_t buffer_length);
#endif