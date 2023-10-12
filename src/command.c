#include "command.h"

void split_command(char* buffer, char **cmd, char *argv[]) {
    int counter = 0;
    char *pch = NULL;
    pch = strtok(buffer, "    "); // spaces and tabs
    while (pch != NULL) {
        argv[counter] = pch;
        pch = strtok(NULL, "    ");
        counter++;
    }
    if (counter >= 1) {
        *cmd = argv[0];
    }
    argv[counter] = (char *) 0;
}
