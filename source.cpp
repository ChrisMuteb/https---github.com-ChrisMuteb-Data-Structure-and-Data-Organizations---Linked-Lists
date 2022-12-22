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
void display(struct node *);

int main(){
/*
Write a main function to perform each of the following;
1.Create a LL
2.Insert element 1 to the front of the LL.
3.Display the LL
4.Insert element 2 to the back of the LL.
5.Display the LL
6.Insert element 3 to the back of the LL.
7.Display the LL
8.Insert element 4 to the front of the LL.
9.Display the LL
10.Insert element 5 to after the 2nd element of the LL.
11.Display the LL.
*/
    struct node *header = NULL;
    header = insertFront(header, 1);
    display(header);
    header = insertBack(header, 2);
    display(header);
    header = insertBack(header, 3);
    display(header);
    header = insertFront(header, 4);
    display(header);
    insertAfter(header->next, 5);
    display(header);

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

void display(struct node *header){
    if(header == NULL)
        cout << "List is empty" << endl;
    struct node* temp = header;

    while(temp != NULL){
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << endl;
}