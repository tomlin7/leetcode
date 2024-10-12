struct Node {
    int data;
    struct Node *next;
};

int identical(struct Node *a, struct Node *b){
    while(a && b) {
        if(a->data != b->data)
            return 0;
        a = a->next;
        b = b->next;
    }

    return !(a||b); // !a && !b is equal to !(a||b)
}

void push(int val, struct Node **a){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = *a;
    *a = temp;
}

void add(int *a, int *b){
    *a += *b;
}

void main() {
    struct Node *a = NULL;
    struct Node *current = a;
    for(int i=0;i<5;i++){
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = i;
        current->next = temp;
        current = temp;
    }

    // pushing
    for(int i=0;i<5;i++){
        push(i, &a);
    }

    // a pointer variable also have an address

}