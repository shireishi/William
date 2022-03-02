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

typedef struct {
    char* command_text;
    int verified;
} Command;

// COMMANDS
void test_command() {
    printf("Hello world\n");
}

// ARGUMENT PARSER
Command* args_parser(int argc, const char** argv) {
    bool is_valid_command = false;
    char* lencomliststr;
    Command command_struct;
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
                command_struct.command_text = *commands[i];
            }
        }
    }

    if (is_valid_command == true)
        command_struct.verified = 1;

    return &command_struct;
}

// MAIN FUNCTION
int main(int argc, const char** argv) {
    char* command_string;
    Command command_struct = *args_parser(argc, argv);
    int command = command_struct.verified;
    char* command_text = command_struct.command_text;

    if (debug == true) { // if debug is active, then print all arguments
        for (int i = 0; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    switch (command) {
        case true:
            printf("valid command\n");
            break;
        case false:
            printf("invalid command\n");
            break;
        default:
            printf("an error has occurred\n");
            break;
    };

    if (strcmp(command_string, *commands[0]) == 0) {
        test_command();
    }

    return 0;
}