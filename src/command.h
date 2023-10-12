#ifndef STRING_H
    #include <string.h>
#endif

#ifndef COMMAND_H
    #define COMMAND_H

    /* Writes the first word from the buffer to cmd. Writes args to argv 
    * Writes NULL to the cmd and argv if buffer is empty*/
    void split_command(char* buffer, char **cmd, char *argv[]);
#endif
