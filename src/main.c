#include <stdio.h>
#include <stdbool.h>

const char* commands[] = {"test"};

bool args_parser(int argc, const char** argv) {
    bool is_valid_command;

    int lenocomlist = sizeof(commands) / sizeof(const char*);
    printf("%d\n", lenocomlist);

    for (int i = 0; i < lenocomlist; i++) {
        for (int j = 0; j < argc; j++) {
            if (commands[i] == argv[j]) {
                is_valid_command = true;
            }
        }
    }
    if (is_valid_command != true) {
        is_valid_command = false;
    }

    return is_valid_command;
}

int main(int argc, const char** argv) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    printf("\n");
    bool command = args_parser(argc, argv);
    if (command == true) {
        printf("valid command\n");
    } else if (command == false) {
        printf("invalid command\n");
    } else {
        printf("an error has occurred\n");
    }

    return 0;
}