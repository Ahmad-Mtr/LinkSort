#include <iostream>

using namespace std;
const int n = 15;
int X[n] = {5, 3, 2, 10, 9, 0, 8, 8, 8, 1, 10, 30, 44, 31, 22};
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = nullptr;
struct node *tail = nullptr;

void insertLast(int value) {
    struct node *newnode = new node;
    newnode->data = value;
    newnode->next = nullptr;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
//    struct node *temp = tail;
//    while (temp->next != NULL) {
//        temp = temp->next;
//    }
//    temp->next = newnode;
//    tail = newnode;
    cout<<"Head/Tail_ @Insert_last: "<<head->data<<" "<<tail->data<<endl;

}
void insertFirst(int value) {
    struct node *newnode = new node;
    newnode->data = value;
    newnode->prev = nullptr;
    if (head == nullptr) {
        head = newnode;
        tail = newnode;
    } else {
        if (head->next == nullptr) {
            // log here to check it
            //cout<<head->data<<endl;
            tail = head;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    cout<<"Head/Tail_ @Insert_first: "<<head->data<<" "<<tail->data<<endl;
}
void insert_inBetween(int value) {
    struct node *newnode = new node;
    newnode->data = value;
    struct node *temp = head;
    if (head == nullptr)
        insertFirst(value);
    else{
        while(!(temp->data <= value && value < temp->next->data)
        ){
            temp = temp->next;
        }
        if (temp->next->next == nullptr)
            tail = temp->next;
        temp->next->prev = newnode;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    cout<<"Head/Tail_ @Insert_inBetween: "<<head->data<<" "<<tail->data<<endl;

//    struct node *temp = head;
//    struct node *_4next;
//
//    while (temp != NULL) {
//        _4next = temp;
//        if ((temp->data <= value) && (_4next->next->data > value)) {
//            //put node
//            newnode->next = temp->next;
//            temp->next = newnode;
//            return;
//        }
//        temp = temp->next;
//    }
}
void resetArray(int A[n]) {
    struct node *tmp = head;
    for (int i = 0; i < n; ++i) {
        A[i] = tmp->data;
        tmp = tmp->next;
    }
}

void linkSort(int A[n]) {
    struct node *startingnode = new node;
    startingnode->data = A[0];
    startingnode->next = head;
    head = startingnode, tail = startingnode;
    for (int k = 1; k < n; ++k) {
        if (A[k] >= tail->data)
        insertLast(A[k]);
        else if (A[k] <= head->data)
        insertFirst(A[k]);
        else
            insert_inBetween(A[k]);
    }
    resetArray(A);
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

void PrintArray() {
    for (int i = 0; i < n; ++i)
        cout << "X[" << i << "]: " << X[i] << "\t\t";
}

int main() {
    //traverse();
    linkSort(X);
    //traverse();
    cout << endl;
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << X[i] << "-";
    }
    cout << endl;
    //PrintArray();
    return 0;
}
