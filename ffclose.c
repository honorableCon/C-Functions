#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*function allowing to close many files at once *
 *            - Dynamic allocation              */

void ffclose(void* fptr, ...){
    va_list args;
    void* argc;

    va_start(args, fptr);
    fclose(fptr);
    while( (argc = va_arg(args, void*)) != NULL)
        fclose(argc);
}

// Test

int main() {

    FILE* a = fopen("file1", "w");
    FILE* b = fopen("file2", "w");
    FILE* c = fopen("file3", "w");
    FILE* d = NULL;
    
    /* code.. */
    ffclose(a, d, b, c, NULL);
    
    return 0;
}