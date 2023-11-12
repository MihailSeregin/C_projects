#include <stdio.h>
#include <stdlib.h>
#include "headers.h"


Node * append(Node *npt, float value){
    Node *nptNext = (Node *)malloc(sizeof(Node));
    nptNext->next = npt;
    nptNext->value = value;
    nptNext->index = (npt == NULL) ? 0: (npt->index + 1);
    if (npt)
        npt->ancs = nptNext;
    return nptNext;
}

void alignIndices(Node *npt, int pred_index){
    while (npt){
        npt->index = pred_index;
        pred_index++;
        npt = npt->ancs;
    }
}

Node *Elremove(Node *npt, float value){
    Node *prev = NULL;
    Node *tmp = npt;
    Node *next = NULL;
    while (tmp && tmp->value!=value){
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp){ /* if tmp is  NULL, the element was not found alignment is not required*/
        return npt;
    }
    if (!prev){
        next = tmp->next;
        free(tmp);
        
        return next;
    } 
    else/* element in the first position*/
        prev->next = tmp->next;
        alignIndices(prev, tmp->index);
        free(tmp);
        return npt;
}

Node *pop(Node *npt, int index, float *result){
    Node *prev = NULL;
    Node *tmp = npt;
    Node *next = NULL;
    float return_value;
    while (tmp && tmp->index != index){
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp)
        return npt;
    if (!prev){
        next = tmp->next;
        *result = tmp->value;
        free(tmp);

        return next;
    }
    else{
        float save_prev = prev->value;;
        prev->value = tmp->value - 1; /*страхуемся, чтобы не равны были значения двух узлов*/
        *result = tmp->value;
        Elremove(prev, tmp->value);
        prev->value = save_prev;
        
        return npt;
    }
}

