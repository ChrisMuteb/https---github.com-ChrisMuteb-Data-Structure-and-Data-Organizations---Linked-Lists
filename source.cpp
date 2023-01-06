#include <iostream>

using namespace std;

struct node {
    //int data;
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
float sumElements(struct node*);

float averagelist(struct node*);
int countA(struct node*);

void deleteAfter(struct node*);
struct node* deleteBack(struct node*);
struct node* deleteFront(struct node*);

struct node* moveforwardlist(struct node*, struct node*);
struct node* movebackwardlist(struct node*, struct node*);
struct node* loadlist(struct node*, float[], int);
struct node* moveforwardlist2(struct node* header, struct node* an);
struct node* moveforwardlist3(struct node* header, struct node* an);
struct node* movebackwardlist2(struct node* header, struct node* an);

int main() {

    struct node* header = NULL;
    float array[] = { 1.5, 2.5, 3.5, 4.5, 5.5, 6.5 };

    /* header = insertBack(header, 11.5);
     header = insertBack(header, 12.5);
     header = insertBack(header, 13.5);*/

    header = loadlist(header, array, sizeof(array) / sizeof(array[0]));
    display(header);

    /*header = moveforwardlist(header, header->next);
    display(header);*/

    /*header = moveforwardlist2(header, header->next->next);
    display(header);*/

    /*header = moveforwardlist3(header, header->next);
    display(header);*/

    /*header = movebackwardlist(header, header->next->next);
    display(header);*/

    header = movebackwardlist2(header, header->next->next);
    display(header);


    system("PAUSE");
    return 0;
}

struct node* createNode(float item) {
    //1. create a temp node
    struct node* temp = NULL;
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

void insertAfter(struct node* afterNode, float data) {
    //1. create node
    struct node* temp = createNode(data);
    //2. connect new node after the afternode
    temp->next = afterNode->next;
    //3. change the afternode pointer value 
    afterNode->next = temp;
}

struct node* deleteFront(struct node* header) {
    struct node* temp;
    if (header == NULL)
        return header;

    temp = header;
    header = header->next;
    free(temp);

    return header;
}

struct node* deleteBack(struct node* header) {
    struct node* temp, * headertemp;
    if (header == NULL)
        return header;
    headertemp = header;
    while (headertemp->next->next != NULL)
        headertemp = headertemp->next;
    temp = headertemp->next;
    headertemp->next = NULL;
    free(temp);
    return header;
}

void deleteAfter(struct node* afterNode) {
    struct node* temp;
    if (afterNode->next == NULL || afterNode == NULL)
        return;
    temp = afterNode->next;
    afterNode->next = temp->next;
    free(temp);
}

void display(struct node* header) {
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

float sumElements(struct node* header) {
    struct node* temp = header;
    float sum = 0;
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

struct node* loadlist(struct node* header, float arr[], int sz) {
    //struct node* temp = NULL;
    for (int i = 0; i < sz; i++) {
        
        //cout << arr[i] << endl;
        header = insertBack(header, arr[i]);
    }
    //header = temp;
    //display(temp);
    return header;
}

struct node* moveforwardlist(struct node* header, struct node* nodeToMove) {
    //1. Find the node before the afternode
    while (header->next != nodeToMove)
        header = header->next;

    //2. Hold the node after the afternode->next
    struct node* temp;
    temp = nodeToMove->next->next;

    //3. swap
    header->next = nodeToMove->next;
    nodeToMove->next = temp;
    header->next->next = nodeToMove;

    return header;
}

struct node* moveforwardlist2(struct node* header, struct node* an) {
    struct node* ht = header;
    //1. Find the node before the afternode
    while (ht->next != an)
        ht = ht->next;

    //2. Hold the node after the afternode->next
    struct node* temp;
    temp = an->next->next;

    //3. swap
    ht->next = an->next;
    an->next = temp;
    ht->next->next = an;

    return header;
}

struct node* moveforwardlist3(struct node* header, struct node* an) {
    struct node* ht = header;
    //1. Find the node before the afternode
    while (ht->next != an)
        ht = ht->next;

    //2. Hold the node after the afternode->next
    struct node* temp;
    temp = an->next;

    //3. swap
    ht->next = temp;
    an->next = temp->next;
    temp->next = an;

    return header;
}

struct node* movebackwardlist(struct node* header, struct node* nodeToMove) {

    //1. Find the node before the afternode
    while (header->next->next != nodeToMove)
        header = header->next;

    //2. Hold the node after the afternode->next
    struct node* temp1, *temp2;
    temp1 = header->next;
    temp2 = nodeToMove->next;

    //3. swap
    header->next = nodeToMove;
    temp1->next = temp2;
    header->next->next = temp1;
   
    return header;
}

struct node* movebackwardlist2(struct node* header, struct node* an) {

    //1. Find the node before the afternode
    while (header->next->next != an)
        header = header->next;

    //2. Hold the node after the afternode->next
    struct node* temp;
    temp = header->next;

    

    //3. swap
    header->next = an;
    temp->next = an->next;
    an->next = temp;

    return header;
}