#include <iostream>

using namespace std;

struct node {
    // int data;
    float data;
    struct node* next;
};

struct node* createNode(float);
int isEmpty(struct node*);
struct node* insertFront(struct node*, float);
struct node* insertBack(struct node*, float);
void insertAfter(struct node*, float);
void display(struct node*);
int countLength(struct node*);
int sumElements(struct node*);

float averagelist(struct node*);
int countA(struct node*);

int main() {
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
    /* struct node *header = NULL;
    // header = insertFront(header, 1);
    // display(header);
    // header = insertBack(header, 2);
    // display(header);
    // header = insertBack(header, 3);
    // display(header);
    // header = insertFront(header, 4);
    // display(header);
    // insertAfter(header->next, 5);
    // display(header);
    // cout << "Length of the LL is " << countLength(header) << endl;
    // cout << "Sum of the elements of the LL is " << sumElements(header) << endl;*/

    struct node* header = NULL;
    header = insertBack(header, 1.5);
    header = insertBack(header, 2.5);
    header = insertBack(header, 3.5);
    header = insertBack(header, 4.5);

    cout << "The average of element of a linked list is: " << averagelist(header) << endl;

    system("PAUSE");
    return 0;
}

struct node* createNode(float item) {
    //1. create a temp node
    struct node* temp;
    //2. allocate memory for node
    temp = (struct node*)malloc(sizeof(node));
    //3. assign item to node
    temp->data = item;
    //4. assign null to next node.
    temp->next = NULL;
    //5. return newly created node.
    return temp;
}

int isEmpty(struct node* header) {
    return (header == NULL) ? 1 : 0;
}

struct node* insertFront(struct node* header, float data) {
    //1. create node
    struct node* temp = createNode(data);
    //2. connect the new node to the front of the list
    temp->next = header;
    //3. change the header value so that it points to the beginning of the LL.
    header = temp;
    //4. return new header
    return header;
}

struct node* insertBack(struct node* header, float data) {
    //1. create node
    struct node* temp = createNode(data);
    struct node* headertemp;
    //2. check if the list is empty
    if (header == NULL) {
        header = temp;
        return header;
    }
    //2. find the end of list
    headertemp = header;
    while (headertemp->next != NULL)
        headertemp = headertemp->next;
    headertemp->next = temp;
    //4. return header
    return header;

}

void insertAfter(struct node* afterNode, int data) {
    //1. create node
    struct node* temp = createNode(data);
    //2. connect new node after the afternode
    temp->next = afterNode->next;
    //3. change the afternode pointer value 
    afterNode->next = temp;
}

void display(struct node* header) {
    if (header == NULL)
        cout << "List is empty" << endl;
    struct node* temp = header;

    while (temp != NULL) {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << endl;
}

int countLength(struct node* header) {
    struct node* temp = header;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int sumElements(struct node* header) {
    struct node* temp = header;
    int sum = 0;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

float averagelist(struct node* header) {
    struct node* temp = header;
    float sum = 0.0;
    int number = 0;
    while (temp != NULL) {
        sum += temp->data;
        number++;
        temp = temp->next;
    }
    return sum / number;
}

int countA(struct node* header) {
    struct node* temp = header;
    int count = 0;

    while (temp != NULL) {
        if (temp->data == 'A')
            count++;
        temp = temp->next;
    }
    return count;
}