#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "system.c"

const char* commands[] = {"test"};
const bool debug = true;

/*
Figure out how to make lencomliststr work with the concatination 
with lencomlistint
*/

bool args_parser(int argc, const char** argv) {
    bool is_valid_command = false;
    char* lencomliststr;
    int lencomlistint = (sizeof(commands) / sizeof(const char*));

    sprintf(lencomliststr, "%d", lencomlistint);

    if (debug == true)
        notification(lencomliststr);

    for (int i = 0; i < lencomlistint; i++) {
        if (debug == true) {
            printf("Command: %s\n", commands[i]);
        }
        for (int j = 0; j < argc; j++) {
            if (debug == true) {
                printf("Argument: %s\n", argv[j]);
            }
            if (strcmp(commands[i], argv[j])) {
                is_valid_command = true;
            }
        }
    }
    return is_valid_command;
}

int main(int argc, const char** argv) {
    char* command_string;

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    bool command = args_parser(argc, argv);
    sprintf(command_string, "%d", command);

    if (debug)
        notification(command_string);
    
    if (command == true) {
        printf("valid command\n");
    } else if (command == false) {
        printf("invalid command\n");
    } else {
        printf("an error has occurred\n");
    }

    return 0;
}