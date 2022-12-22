#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

int main(){

    struct node *header = NULL;
    header = (struct node *)malloc(sizeof(node));
    header->data = 52;
    header->next = NULL;

    cout << header << endl;
    cout << header->data << endl;
    cout << header->next << endl;

    system("PAUSE");
    return 0;
}