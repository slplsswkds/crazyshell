#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <ctype.h>

#include "config.h"
#include "input.h"
#define ENTER 10


void banner(void) { 
    printf("Welcome to CrazyShell!\n\r"); 
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
