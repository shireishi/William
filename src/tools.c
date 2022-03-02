const char* inttostring(int num) {
    const char* text[1024];
    sprintf(text, "%d", num);
    return text;
}

const char* listtostring(char* list[]) {
    // declare variables
    int list_length = (sizeof(list) / sizeof(char*));
    const char* text[list_length];
    const char* return_string[list_length+1];

    // move all letters in list to a string
    for (int i = 0; i < list_length; i++) {
        return_string[i] = text[i];
    }
    
    return return_string;
}