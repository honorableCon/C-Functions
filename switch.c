#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char* remove_space(char* string);
char* Switch(int choice, ...);

int main(){
    int c = 3;
    
    char* result = Switch(
        c,
        "Un",
        "Deux",
        "Trois",
        "Quatre",
        "default = zero"
    );
    printf("%s\n", result);
    return 0;
}


char* Switch(int choice, ...){
    va_list list;
    char* current;
    int i = 1;

    va_start(list, choice);
    while(strncmp(current=va_arg(list, char*), "default", 7) != 0)
        if (i++ == choice)
            return current;
    return remove_space(current+strlen("default"));
}

char* remove_space(char* string){
    while (*string == 0x20 || *string == '=') 
        string++;
    return string; 
}