char* colored(int r, int g, int b, const char* text) {
    char* color_string;
    sprintf(color_string, "\033[38;2;%d;%d;%dm%s\033[m", r, g, b, text);
    return color_string;
}

void notification(char* text) {
    printf(colored(0, 125, 0, text));
}