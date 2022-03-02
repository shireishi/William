#include <stdio.h>
#include "security.c"

int main(void) {
    printf(hash("test 123"));
    return 0;
}