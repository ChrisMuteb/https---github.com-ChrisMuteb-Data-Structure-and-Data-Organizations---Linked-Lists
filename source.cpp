#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* createNode(int );

int main(){

    struct node *header = NULL;
    header = createNode(52);
    header->next = createNode(48); 

    cout << header << endl;
    cout << header->data << endl;
    cout << header->next << endl;
    cout << header->next->data << endl;
    cout << header->next->next << endl;

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