
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
    this.prev = null;
  }
}

class LinkSort {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  insertLast(value) {
    const newNode = new Node(value);
    if (this.tail) {
      this.tail.next = newNode;
      newNode.prev = this.tail;
    }
    this.tail = newNode;
    if (!this.head) {
      this.head = newNode;
    }
  }

  insertFirst(value) {
    const newNode = new Node(value);
    if (this.head) {
      this.head.prev = newNode;
      newNode.next = this.head;
    }
    this.head = newNode;
    if (!this.tail) {
      this.tail = newNode;
    }
  }

  insertBetween(value) {
    const newNode = new Node(value);
    let temp = this.head;
    while (temp.next && temp.next.data < value) {
      temp = temp.next;
    }
    newNode.next = temp.next;
    newNode.prev = temp;
    if (temp.next) {
      temp.next.prev = newNode;
    }
    temp.next = newNode;
    if (!newNode.next) {
      this.tail = newNode;
    }
  }

  resetArray(A) {
    let temp = this.head;
    for (let i = 0; i < A.length; ++i) {
      A[i] = temp.data;
      temp = temp.next;
    }
  }

  linkSort(A) {
    this.head = this.tail = null;
    this.insertFirst(A[0]);
    for (let i = 1; i < A.length; ++i) {
      if (A[i] <= this.head.data) {
        this.insertFirst(A[i]);
      } else if (A[i] >= this.tail.data) {
        this.insertLast(A[i]);
      } else {
        this.insertBetween(A[i]);
      }
    }
    this.resetArray(A);
  }
}

// Example usage
const X = [5, 3, 2, 10, 9, 0, -10, 8, 8, 1, 10, 30, 44, 31, 22];
const sorter = new LinkSort();
sorter.linkSort(X);
console.log(X);
