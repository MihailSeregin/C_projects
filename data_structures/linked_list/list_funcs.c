#include <stdio.h>
#include <stdlib.h>
#include "headers.h"


Node *createList(){
    return NULL;
}

void print_list(Node *npt){
    while (npt){
        printf("%f  [%d]\n ", npt->value, npt->index);
        npt = npt->next;
    }
}