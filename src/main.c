// SYSTEM IMPORTS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// LOCAL IMPORTS
#include "system.c"

// GLOBAL DEFINITIONS
#define debug 0

// GLOBAL VARIABLES
const char* commands[] = {"test", "echo"};

// COMMAND STRUCT
typedef struct {
    const char* command_text;
    int verified;
} Command;

// COMMANDS
void test_command() {
    printf("Hello world\n");
}

void echo(const char* text) {
    printf(text);
}

// ARGUMENT PARSER
Command args_parser(int argc, const char** argv) {
    // variable declaration
    bool is_valid_command = false;
    char* lencomliststr = NULL;
    Command command_struct;
    int lencomlistint = (sizeof(commands) / sizeof(const char*));

    // format the length of the command list to a string instead of an integer
    sprintf(lencomliststr, "%d", lencomlistint);

    if (debug == 1) // if the global debug variable is true then print the length of the command list
        notification(lencomliststr);

    for (int i = 0; i < lencomlistint; i++) { // parse through the provided arguments and the command list to find any common strings
        if (debug == 1) {
            printf("Command: %s\n", commands[i]);
        }
        for (int j = 0; j < argc; j++) {
            if (debug == 1) {
                printf("Argument: %s\n", argv[j]);
            }
            if (strcmp(commands[i], argv[j])) {
                is_valid_command = true;
                command_struct.command_text = commands[i];
            }
        }
    }

    if (is_valid_command == true) // if one of the arguments provided is a command then return a true value
        command_struct.verified = 1;

    return command_struct;
}

// MAIN FUNCTION
int main(int argc, const char** argv) {
    // variable declaration
    Command command_struct = args_parser(argc, argv);
    args_length = (sizeof(argv)/sizeof(const char*));
    int command = command_struct.verified;
    const char* command_text = command_struct.command_text;

    if (debug == 1) { // if debug is active, then print all arguments
        for (int i = 0; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    switch (command) { // determine if the arguments provided are commands
        case true:
            notification("valid command\n");
            
            char* arguments[(sizeof(argv)/sizeof(const char*)-2)]; // set the size of the arguments list to the remaining arguments in the array of arguments provided to the command
            if (args_length > 2)
            for (int i = 2; i < argc-2; i++) {
                arguments[i-2] = argv[i];
            }
            
            break;
        case false:
            printf("Not a valid command\n");
            break;
        default:
            printf("A fatal error has occured in the command parser.\n");
            exit();
            break;
    }

    if (strcmp(command_text, commands[0]) == 0) { // determine the corresponding function for the command string
        test_command();
    } else if (strcmp(command_text, commands[1]) == 0) {
        echo(arguments);
    } else {
        exit();
    }

    return 0;
}