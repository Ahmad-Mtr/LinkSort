
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertLast(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (tail != NULL) {
        tail->next = newNode;
    }
    newNode->prev = tail;
    tail = newNode;
    if (head == NULL) {
        head = newNode;
    }
}

void insertFirst(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->next = head;
    head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
}

void insertBetween(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    Node* temp = head;
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
        tail = newNode;
    }
}

void resetArray(int A[], int n) {
    Node* temp = head;
    for (int i = 0; i < n; ++i) {
        A[i] = temp->data;
        temp = temp->next;
    }
}

void linkSort(int A[], int n) {
    head = tail = NULL;
    insertFirst(A[0]);
    for (int i = 1; i < n; ++i) {
        if (A[i] <= head->data) {
            insertFirst(A[i]);
        } else if (A[i] >= tail->data) {
            insertLast(A[i]);
        } else {
            insertBetween(A[i]);
        }
    }
    resetArray(A, n);
}

int main() {
    int X[] = {5, 3, 2, 10, 9, 0, -10, 8, 8, 1, 10, 30, 44, 31, 22};
    int n = sizeof(X) / sizeof(X[0]);
    linkSort(X, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", X[i]);
    }
    printf("\n");
    return 0;
}
