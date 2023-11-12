#ifndef HEADERS_H
#define HEADERS_H


typedef struct Node{
    struct Node *next;
    float value;
    int index;
    struct Node *ancs;
} Node;

Node* createList(void);
Node * append(Node *npt, float value);
void print_list(Node *npt);
void alignIndices(Node *npt, int pred_index);
Node *Elremove(Node *npt, float value);
Node *pop(Node *npt, int index, float *);

#endif

