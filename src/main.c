#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <ctype.h>

#include "config.h"
#define ENTER 10


void banner(void) { 
    printf("Welcome to CrazyShell!\n\r"); 
}

/* Returns true if command is built-in to Shell */
bool is_internal_cmd(char *cmd) {
    char *echo = "echo"; // one of built

    return strcmp(echo, cmd);
}

void stdin_get_command(char* buf, size_t buf_len) {
    int ch; // Buffer for single byte from stdin
    char *carret = buf; // Pointer for carriage.
    size_t taken_buffer_space = 0; // Contains the number of bytes written to the command input buffer
    memset(buf, 0, buf_len); // Cleaning the command input buffer
    
    /* Read command input command and write to buf */
    while(true) {
        ch = getchar();
        if (isalnum(ch) || isblank(ch) || isgraph(ch)) { // If ch is number or letter or space or horizontal tab or any printable character
            if (taken_buffer_space == buf_len) { // Checking if buffer have not free space
                buf_len *= 2; // ATTENTION!!! should be a limit
                buf = realloc(buf, buf_len);
            }
            *carret = ch;
            carret += 1;
            taken_buffer_space += 1;
        } else if iscntrl(ch) { // if ch is control symbol
            break;
        }
        
    }
}

int main(void) {
    config cfg = default_config();
    if (cfg.banner) banner();

    char* buf = NULL; // Pointer to the command input buffer
    size_t buf_len = 256; // Command input buffer length
    buf = (char*)calloc(buf_len, sizeof(char));
    
    while(true) {
        stdin_get_command(buf,buf_len);

        printf("buf: %s\n\r", buf);
    }

    free(buf);
    return 0;
}

