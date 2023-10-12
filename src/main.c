#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "config.h"
#include "input.h"
#include "command.h"

#define ENTER 10

void banner(void) { 
    printf("Welcome to the CrazyShell!\n\r"); 
}

int main(void) {
    config cfg = default_config();
    if (cfg.banner) banner();

    char* buf = NULL; // Pointer to the command input buffer
    size_t buf_len = 256; // Command input buffer length
    buf = (char*)calloc(buf_len, sizeof(char));
    
    while(true) {
        stdin_get_command(buf,buf_len);

        char *cmd = NULL;
        char *argv[32] = {NULL};
        
        split_command(buf, &cmd, argv);

        int return_val = 0; // Contains return value of child process
        pid_t pid;
        switch (pid = vfork()) { // create a child process and block parent
            case -1: // Error
                perror("Failed to create child process: vfork error\n"); 
                break;
            case 0: // Child process
                execvp(cmd, argv);
                exit(return_val);
                break;
            default: // Parent process
                wait(&return_val);
        }
    }

    free(buf);
    return 0;
}

