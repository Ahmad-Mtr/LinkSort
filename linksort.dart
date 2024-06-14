class Node {
  int data;
  Node? next;
  Node? prev;

  Node(this.data);
}

class LinkSort {
  Node? head;
  Node? tail;

  void insertLast(int value) {
    var newNode = Node(value);
    if (tail != null) {
      tail!.next = newNode;
      newNode.prev = tail;
    }
    tail = newNode;
    head ??= newNode;
  }

  void insertFirst(int value) {
    var newNode = Node(value);
    if (head != null) {
      head!.prev = newNode;
      newNode.next = head;
    }
    head = newNode;
    tail ??= newNode;
  }

  void insertBetween(int value) {
    var newNode = Node(value);
    var temp = head;
    while (temp!.next != null && temp.next!.data < value) {
      temp = temp.next;
    }
    newNode.next = temp.next;
    newNode.prev = temp;
    if (temp.next != null) {
      temp.next!.prev = newNode;
    }
    temp.next = newNode;
    if (newNode.next == null) {
      tail = newNode;
    }
  }

  void resetArray(List<int> A) {
    var temp = head;
    for (var i = 0; i < A.length; ++i) {
      A[i] = temp!.data;
      temp = temp.next;
    }
  }

  void linkSort(List<int> A) {
    head = tail = null;
    insertFirst(A[0]);
    for (var i = 1; i < A.length; ++i) {
      if (A[i] <= head!.data) {
        insertFirst(A[i]);
      } else if (A[i] >= tail!.data) {
        insertLast(A[i]);
      } else {
        insertBetween(A[i]);
      }
    }
    resetArray(A);
  }
}

void main() {
  List<int> X = [5, 3, 2, 10, 9, 0, -10, 8, 8, 1, 10, 30, 44, 31, 22];
  LinkSort sorter = LinkSort();
  sorter.linkSort(X);
  print(X);
}
