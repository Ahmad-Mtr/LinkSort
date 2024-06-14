class Node {
  constructor(data) {
      this.data = data;
      this.next = null;
      this.prev = null;
  }
}

function insertLast(value, head, tail) {
  let newNode = new Node(value);
  if (tail !== null) {
      tail.next = newNode;
  }
  newNode.prev = tail;
  tail = newNode;
  if (head === null) {
      head = newNode;
  }
  return { head, tail };
}

function insertFirst(value, head, tail) {
  let newNode = new Node(value);
  newNode.prev = null;
  if (head !== null) {
      head.prev = newNode;
  }
  newNode.next = head;
  head = newNode;
  if (tail === null) {
      tail = newNode;
  }
  return { head, tail };
}

function insertBetween(value, temp, tail) {
  let newNode = new Node(value);
  while (temp.next !== null && temp.next.data < value) {
      temp = temp.next;
  }
  newNode.next = temp.next;
  newNode.prev = temp;
  if (temp.next !== null) {
      temp.next.prev = newNode;
  }
  temp.next = newNode;
  if (newNode.next === null) {
      tail = newNode;
  }
  return tail;
}

function resetArray(A, n, temp) {
  for (let i = 0; i < n; i++) {
      A[i] = temp.data;
      temp = temp.next;
  }
}

function linkSort(A, n) {
  let head = null;
  let tail = null;

  ({ head, tail } = insertFirst(A[0], head, tail));
  for (let i = 1; i < n; i++) {
      if (A[i] <= head.data) {
          ({ head, tail } = insertFirst(A[i], head, tail));
      } else if (A[i] >= tail.data) {
          ({ head, tail } = insertLast(A[i], head, tail));
      } else {
          tail = insertBetween(A[i], head, tail);
      }
  }
  resetArray(A, n, head);
}

// Test the linkSort function
const X = [5, 3, 2, 10, 9, 0, -10, 8, 8, 1, 10, 30, 44, 31, 22];
const n = X.length;
linkSort(X, n);

console.log(X.join(' '));
