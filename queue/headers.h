typedef struct Node{
    struct Node *right;
    struct Node *left;
    float value;
} Node;

Node *left_push(Node * npt, float value);
Node *right_push(Node *npt, float value);
Node *left_pop(Node *npt, float *pop_result);
Node *right_pop(Node *npt,float *pop_result);
void printf_queue(Node *npt);