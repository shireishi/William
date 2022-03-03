#include <stdio.h>
#include <string.h>

const char* hash(const char* text) { // This function should generate a hash based on the information provided
    // declare all variables
    int text_length = strlen(text);
    // -std=c99
    
    char* char_list = (char*)malloc(text_length*sizeof(char*));
    char* hash_list = (char*)malloc(text_length*sizeof(char*)*2);
    int hash_list_length = (sizeof(hash_list) / sizeof(char*));
    const char* hashed_string[hash_list_length];

    // convert the string to a list
    for (int i = 0; i < text_length; i++) {
        char_list[i] = text[i];
    }

    //convert all values in the string to ordinal values
    for (int i = 0; i < text_length; i++) {
        if (typeof(char_list[i]) == typeof(42)) {
            hash_list[i] = char_list[i];
        } else {
            sprintf(hash_list[i], "%d", char_list[i]);
        }
    }

    // perform hashing algorithm on the ordinal values of the string
    for (int i = 0; i < hash_list_length; i++) {
        hash_list[i] = atoi(hash_list[i])%text_length*(i+1);
    }

    // convert all numerical values to their hexadecimal counterparts
    for (int i = 0; i < (sizeof(hash_list) / sizeof(char*)); i++) {
        sprintf(hash_list[i], "%x", atoi(hash_list[i]));
    }

    // convert the list of strings to a string
    for (int i = 0; i < hash_list_length; i++) {
       hashed_string[i] = hash_list[i];
    } 

    return hashed_string;
}