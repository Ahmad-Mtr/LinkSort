#include <iostream>

using namespace std;
const int n = 15;
int X[n] = {5, 3, 2, 10, 9,0,8,8,8,1,10,30,44,31,22};

struct node {
    int data;
    struct node *next;
};
struct node *head = nullptr;
struct node *tail = nullptr;

void insertLast(int value){
    struct node *newnode = new node;
    newnode->data = value;
    newnode->next = nullptr;
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    tail = newnode;

}
void insertFirst(int value){
    struct node *newnode = new node;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void insert_inBetween(int value){
    struct node *newnode = new node;
    newnode->data = value;

    struct node *temp = head;
    struct node *_4next;

    while (temp != NULL) {
        _4next = temp;
        if ((temp->data <= value) && (_4next->next->data > value)){
            //put node
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        temp = temp->next;
    }
}
void linkSort(int A[n]){
    struct node *startingnode = new node;
    startingnode->data = A[0];
    startingnode->next = head;
    head = startingnode, tail = startingnode;
    for (int k = 1; k < n; ++k) {
        if (A[k] >=  tail->data)
            insertLast(A[k]);
        else if (A[k] <=  head->data)
            insertFirst(A[k]);
        else
            insert_inBetween(A[k]);
    }

}

void traverse() {

    struct node *temp = head;
    if (temp == NULL) {
        cout << "Empty list!" << endl;
        return;
    }
    while (temp != NULL) {

        cout << temp->data << "  ";
        temp = temp->next;
    }

}
void _PrintArray() {
    for (int i = 0; i < n; ++i)
        cout << "X[" << i << "]: " << X[i] << "\t\t";
}

int main() {
    //traverse();
    linkSort(X);
    traverse();
    cout<<endl;
    _PrintArray();
    return 0;
}
