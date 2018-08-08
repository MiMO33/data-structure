#include "stack.h"
#include <stdio.h>

// convert to base 16
void convert(int n){
    stack *s = stack_init(sizeof(char));
    static char* digit = "0123456789ABCDEF";
    while(n > 0){
        stack_push(s, &digit[n % 16]);
        n /= 16;
    }
    while(!stack_empty(s)){
        printf("%c", *(char*)stack_pop(s));
    }
    printf("\n");
}