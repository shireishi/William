const char* colored(int r, int g, int b, const char* title, const char* text) {
    const char* color_string[1024];
    sprintf(color_string, "[\033[38;2;%d;%d;%dm%s\033[m] : %s", r, g, b, title, text);
    printf("%s\n", color_string);
    return color_string;
}

void notification(char* text) {
    printf(colored(0, 125, 0, "Notif", text)); // prints a notification
}

void error(char* text) {
    printf(colored(255, 0, 0, "Error", text)); // prints an error message
}

void broadcast(char* text) {
    printf(colored(125, 125, 0, "Broad", text)); // prints a general message to the terminal
}