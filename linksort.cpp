#include <iostream>
using namespace std;
const int n = 15;

// Example Array
int X[n] = {5, 3, 2, 10, 9, 0, -10, 8, 8, 1, 10, 30, 44, 31, 22};

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = nullptr;
struct node *tail = nullptr;

void _insertLast(int value) {
    struct node *newnode = new node;
    newnode->data = value;
    newnode->next = nullptr;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void _insertFirst(int value) {
    struct node *newnode = new node;
    newnode->data = value;
    newnode->prev = nullptr;
    if (head == nullptr) {
        head = newnode;
        tail = newnode;
    } else {
        if (head->next == nullptr) {
            tail = head;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void _insertBetween(int value) {
    struct node *newnode = new node;
    newnode->data = value;
    struct node *temp = head;
    if (head == nullptr)
        _insertFirst(value);
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
}

// Replace the Array with the sorted one.
void _resetArray(int A[n]) {
    struct node *tmp = head;
    for (int i = 0; i < n; ++i) {
        A[i] = tmp->data;
        tmp = tmp->next;
    }
}

// linkSort: An Array sorting Algorithim that is O(n^2) and Omega(n) time, and O(n) Space.
void linkSort(int A[n]) {
    struct node *startingnode = new node;
    startingnode->data = A[0];
    startingnode->next = head;
    head = startingnode, tail = startingnode;
    for (int k = 1; k < n; ++k) {
        if (A[k] >= tail->data)
        _insertLast(A[k]);
        else if (A[k] <= head->data)
        _insertFirst(A[k]);
        else
            _insertBetween(A[k]);
    }
    _resetArray(A);
}


int main() {
    linkSort(X);
    for(int a: X){
        cout<<a<<". ";
    }
    cout<<endl;
    return 0;
}
