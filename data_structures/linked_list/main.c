#include <stdio.h>
#include <stdlib.h>
#include "headers.h"


int main(int argc, char *argv[]){
    Node * my_list = createList();

    // float f = 0.5;
    float *pop_result = (float *)malloc(sizeof(float));

    for (float f = 1.1; f < 11; f++){
        my_list = append(my_list, f);
    }
    my_list = Elremove(my_list, (float) 1.1);
    my_list = pop(my_list, 6, pop_result);
    printf("%f\n", (double) *pop_result);
    print_list(my_list);
    return 0;
}


















