#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* createNode(int );
int isEmpty(struct node *);

int main(){

    struct node *header = NULL;
    
    (isEmpty(header)) ? cout << "Linked list is empty!" << endl : cout << "Linked list is not empty!" << endl;

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