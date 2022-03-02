#include <stdio.h>

int main(void) {
    char test_var[50];
    int x = 25; 
    int y = 32;
    sprintf(test_var, "Hello world: %d %d", x, y);
    printf("%s\n", test_var);
    return 0;
}