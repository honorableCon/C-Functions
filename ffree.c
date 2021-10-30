#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


/*function allowing many free at once *
 *       - Dynamic allocation         */

void ffree(void* ptr, ...){
    va_list args;
    void* argc;

    va_start(args, ptr);
    free(ptr);
    while( (argc = va_arg(args, void*)) != NULL)
        free(argc);
}


/******* exemple  ********/

int main() {

    char *a = malloc(sizeof(char) * 10);
    char *b = malloc(sizeof(char) * 10);
    char *c = malloc(sizeof(char) * 10);
    
    ffree(a, b, c, NULL);
    return 0;
}
