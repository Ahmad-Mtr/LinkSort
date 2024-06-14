#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void insertLast(int value, Node** head, Node** tail) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*tail != NULL) {
        (*tail)->next = newNode;
    }
    newNode->prev = *tail;
    *tail = newNode;
    if (*head == NULL) {
        *head = newNode;
    }
}

void insertFirst(int value, Node** head, Node** tail) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
    if (*tail == NULL) {
        *tail = newNode;
    }
}

void insertBetween(int value, Node* temp, Node** tail) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    if (newNode->next == NULL) {
        *tail = newNode;
    }
}

void resetArray(int A[], int n, Node* temp) {
    for (int i = 0; i < n; ++i) {
        A[i] = temp->data;
        temp = temp->next;
    }
}

void linkSort(int A[], int n) {
    Node* head = NULL;
    Node* tail = NULL;
    
    insertFirst(A[0], &head, &tail);
    for (int i = 1; i < n; ++i) {
        if (A[i] <= head->data) {
            insertFirst(A[i], &head, &tail);
        } else if (A[i] >= tail->data) {
            insertLast(A[i], &head, &tail);
        } else {
            insertBetween(A[i], head, &tail);
        }
    }
    resetArray(A, n, head);

    // Free the allocated memory
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int X[] = {5, 3, 2, 10, 9, 0, -10, 8, 8, 1, 10, 30, 44, 31, 22};
    int n = sizeof(X) / sizeof(X[0]);
    linkSort(X, n);
    
    for(int a: X){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
