#include <iostream>

using namespace std;
const int n = 5;
int X[n] = {5, 3, 2, 10, 9};

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
    for (int i = 0; i < 4; ++i)
        cout << "X[" << i << "]: " << X[i] << endl;
}

int main() {
    //traverse();
    linkSort(X);
    traverse();
    cout<<endl;
    _PrintArray();
    return 0;
}
