#include <stdio.h> 
#include <stdlib.h>
#include "Stack.h"

int main()
{   
    struct StackNode* testStack = init(10);
    
    push(&testStack, 10);
    
    push(&testStack, 20);
        
    printf("%d <- This should be 20\n", pop(&testStack));

    push(&testStack, 30);

    printf("%d <- This should be 30\n", pop(&testStack));

    return 0;
}