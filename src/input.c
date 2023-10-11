#include "input.h"
#include <asm-generic/errno-base.h>

void stdin_get_command(char *buf, size_t buf_len) {
    int ch; // Buffer for single byte from stdin
    char *carret = buf; // Pointer for carriage.
    size_t taken_buffer_space = 0; // Contains the number of bytes written to the command input buffer
    memset(buf, 0, buf_len); // Cleaning the command input buffer
    
    /* Read command input command and write to buf */
    while(true) {
        ch = getchar();
        if (isalnum(ch) || isblank(ch) || isgraph(ch)) { // If ch is number or letter or space or horizontal tab or any printable character
            if (taken_buffer_space == buf_len) { // Checking if buffer have not free space
                if (expand_command_buffer(buf, buf_len) == ENOMEM) 
                    break;
            }
            
            *carret = ch;
            carret += 1;
            taken_buffer_space += 1;
        } else if iscntrl(ch) { // if ch is control symbol
            break;
        }
    }
}

int expand_command_buffer(char *buffer, size_t buffer_length) {
    buffer_length *= 2;
    char *buffer_tmp = NULL;
    buffer_tmp = realloc(buffer, buffer_length);
    if (buffer_tmp == NULL) {
        perror("Input buffer has been filled in completely. Failed to reallocate memory\n\r");
        return ENOMEM;
    } else {
        buffer = buffer_tmp;
        return 0;
    }
}
