#include <stdio.h>
#include <stdlib.h>

#ifndef HEADERS
#include "headers.h"
#endif


int main(){
    Node *queue = NULL;
    float *result = (float *)malloc(sizeof(float));

    for (float data = 5.0; data<10; data++){
        queue = left_push(queue, data);
        queue = right_push(queue, data + 0.5);
    }

    while(queue){
        queue = left_pop(queue, result);
        printf("l%f ", *result);
        queue = right_pop(queue, result);
        printf("r%f ", *result);
    }

    return 0;
}

