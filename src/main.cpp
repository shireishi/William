#include <cstdio.h>
#include <iostream.h>
#include <string.h>
#include <stdbool.h>

#define debug 1

// COMMAND STRUCT
typedef struct {
    string command_text;
    int verified = 0;
} Command;

// COMMANDS
void test_command() {
    printf("Hello world\n");
}

// ARGUMENT PARSER
Command args_parser(int argc, const char* argv[]) {
    // variable declaration
    bool is_valid_command = false;
    Command command_struct;
    int lencomlistint = (sizeof(commands) / sizeof(const char*));
    const char* lencomliststr = (const char*)lencomlistint;

    // format the length of the command list int to a string
    if (debug == 1)
        notification(lencomliststr);

    for (int i = 0; i < lencomlistint; i++) {
        if (debug == 1)
            printf("Command: %s\n", commands[i]);
        for (int j = 0; j < argc; j++) {
            if (debug == 1)
                printf("Argument: %s\n", argv[j]);
            if (strcmp(commands[i], argv[j]) == 0) {
                is_valid_command = true;
                command_struct.command_text = commands[i];
            }
        }
    }
    if (is_valid_command == true)
        command_struct.verified = 1;

    return command_struct;
}

// MAIN FUNCTION
int main(int argc, const char* argv[]) {
    Command command_struct = args_parser(argc, argv);
    int command = command_struct.verified;
    const char* command_text = command_struct.command_text;

    if (debug == 1) {
        for (int i = 0; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    switch (command) {
        case true:
            notification("valid command\n");
            break;
        case false:
            notification("invalid command\n");
            break;
        default:
            notification("an error occurred\n");
            break;
    }

    if (strcmp(command_text, commands[0]) == 0) {
        test_command();
    }

    return 0;
}