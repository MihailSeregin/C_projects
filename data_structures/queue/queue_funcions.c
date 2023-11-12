#include <stdio.h>
#include <stdlib.h>

#ifndef HEADERS
#include "headers.h"
#endif


/* всегда подаем на вход левую вершину*/

void printf_queue(Node *npt){
    if (!npt){
        printf("Queue is empty");
        return;
    }
    do{
        printf("%f ", npt->value);
    } 
    while ((npt = npt->right) != NULL);
    printf("\n");
}

Node *left_push(Node * npt, float value){
    Node *current = (Node *)malloc(sizeof(Node));
    current->right = npt;
    current->left = NULL;
    current->value = value;
    if (npt)
        npt->left = current;
    return current;
}

Node *right_push(Node *npt, float value){
    Node *tmp = npt;
    Node *current = (Node *)malloc(sizeof(Node));
    current->value = value;

    if (!npt){
        current->left = NULL;
        current->right = npt;
        return current;
    }


    while(tmp->right != NULL){
        tmp = tmp->right;
    }
    tmp->right = current;
    current->right = NULL;
    current->left = tmp;
    return npt;
}

Node *left_pop(Node *npt, float *pop_result){
    Node *tmp = (Node *)malloc(sizeof(Node));
    if (!npt){
        printf("%s", "Queue is empty");
        return npt;
        }
    *pop_result = npt->value;
    tmp = npt->right;
    if (!tmp){
        return tmp;
    }
    else{
        tmp->left = NULL;
        free(npt);
        return tmp;
    }
}

Node *right_pop(Node *npt,float *pop_result){
    Node *tool_node = (Node *)malloc(sizeof(Node));
    Node *tmp = npt;
    Node *prev = NULL;

    if (!npt){
        printf("Queue is empty");
        return npt;
        }

    while (tmp->right != NULL){
        prev = tmp;
        tmp = tmp->right;
    }
    *pop_result = tmp->value;
    
    if (!prev){ /* there is one element only*/
        tool_node = tmp->right;
        free(tmp);
        return tool_node;
    }
    else{
        prev->right = NULL;
        free(tmp);
        return npt;
    }

}

