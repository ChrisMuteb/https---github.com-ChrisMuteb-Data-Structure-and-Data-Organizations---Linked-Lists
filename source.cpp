#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* createNode(int );
int isEmpty(struct node *);
struct node *insertFront(struct node *, int );
struct node *insertBack(struct node *, int );
void insertAfter(struct node* , int );

int main(){

    struct node *header = NULL;
    
    header = createNode(5);
    header->next = createNode(6);
    // header = insertBack(header, 7);
    insertAfter(header, 7);

    system("PAUSE");
    return 0;
}

struct node* createNode(int item){
    //1. create a temp node
    struct node *temp;
    //2. allocate memory for node
    temp = (struct node *)malloc(sizeof(node));
    //3. assign item to node
    temp->data = item;
    //4. assign null to next node.
    temp->next = NULL;
    //5. return newly created node.
    return temp;
}

int isEmpty(struct node *header){
    return (header == NULL) ? 1 : 0;
}

struct node *insertFront(struct node *header, int data){
    //1. create node
    struct node *temp = createNode(data);
    //2. connect the new node to the front of the list
    temp->next = header;
    //3. change the header value so that it points to the beginning of the LL.
    header = temp;
    //4. return new header
    return header;
}

struct node *insertBack(struct node *header, int data){
    //1. create node
    struct node *temp = createNode(data);
    struct node *headertemp;
    //2. check if the list is empty
    if(header == NULL){
        header = temp;
        return header;
    }
    //2. find the end of list
    headertemp = header;
    while(headertemp->next != NULL)
        headertemp = headertemp->next;
    headertemp->next = temp;
    //4. return header
    return header;
    
}

void insertAfter(struct node* afterNode, int data){
    //1. create node
    struct node* temp = createNode(data);
    //2. connect new node after the afternode
    temp->next = afterNode->next;
    //3. change the afternode pointer value 
    afterNode->next = temp;
}