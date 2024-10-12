#include<stdio.h>
struct node {
    int data;
    struct node *next;
};

void createList(struct node *head, int n){
    struct node *newNode, *temp;
    int data, i;
    head = temp = (struct node *)malloc(sizeof(struct node));

    if(head == NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    
    printf("Enter the data of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    for(i=2;i<=n;i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode == NULL){
            printf("Memory not allocated\n");
            break;
        }
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
}

void insertOnTop(struct node *head, int data){
    struct node *n1 = (struct node*)malloc(sizeof(struct node));
    n1->data = data;
    n1->next = head;
    head = n1;
}

void insertAtEnd(struct node *head, int data) {
    struct node *n1 = (struct node*) malloc(sizeof(struct node));
    n1->data = data;
    n1->next = NULL;
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
}

int main(){
    int n, data;
    struct node *head = NULL; // root node
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createList(head, n);

}
