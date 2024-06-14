# LinkSort Algorithm Documentation

## Index

- [LinkSort Algorithm Documentation](#linksort-algorithm-documentation)
  - [Index](#index)
  - [Overview](#overview)
  - [Inspiration](#inspiration)
  - [Algorithm Description](#algorithm-description)
  - [Use Case](#use-case)
  - [Complexity](#complexity)
  - [Implementation](#implementation)
  - [Usage](#usage)
  - [Conclusion](#conclusion)

---

## Overview

**LinkSort** is a sorting algorithm implemented using a doubly linked list with a head and tail. This algorithm is particularly effective for sorting arrays that are expanding, meaning that as the array is traversed, each newly accessed value is either the lowest or the highest compared to the previous values. The best-case time complexity is `Omega(n)`, while the worst-case time complexity is `O(n^2)`. The space complexity is `Theta(n)` .

---

## Inspiration

During my Algorithms class, I remembered how I was sorting a deck of Cards when I was a Kid, in which I'll put a choosen Card after/before the first Card if it had a higher/lower value or in between. That's how I was inpsired to start creating this Algorithm.

---

## Algorithm Description

The LinkSort algorithm works by inserting elements from an array into a doubly linked list in a sorted manner. The steps are as follows:

1. Initialize an empty doubly linked list with head and tail pointers.
2. Traverse the array and for each element:
   - Insert it at the head if it is the smallest value encountered so far.
   - Insert it at the tail if it is the largest value encountered so far.
   - Insert it between the appropriate nodes if it falls between existing values in the list.
3. Once all elements are inserted into the linked list, reconstruct the sorted array from the linked list.

## Use Case

The best use case for LinkSort is when dealing with an expanding array where each newly accessed value is either the smallest or the largest compared to previously accessed values. This characteristic ensures that the algorithm operates close to its best-case time complexity of \( \Omega(n) \).

## Complexity

- **Time Complexity**:
  - Best Case: Omega(n)
  - Worst Case: O(n^2)
    <img align="center" alt="time complexity" src="https://raw.githubusercontent.com/Ahmad-Mtr/linksort/master/assets/time.png">
- **Space Complexity**: Theta(n)
  <img align="center" alt="space complexity" src="https://raw.githubusercontent.com/Ahmad-Mtr/linksort/master/assets/space.png">

## Implementation

Below is the List of available implementations of the LinkSort algorithm:

| Language   | State of Implementation | Package or Code       | Installation script     |
| ---------- | ----------------------- | --------------------- | ----------------------- |
| C          | Implemented             | [Code](#)     |            |
| C++        | Implemented             | [Code](#)     |          |
| Dart       | Not Implemented             | [Pub Package Link](#) | `dart pub add linksort` |
| JavaScript | Not Implemented             | [npm Link](#)         | `npm install linksort`  |

## Usage

To use the LinkSort algorithm, follow these steps:

1. Define an array of integers.
2. Call the `linkSort` function with the array as the argument.
3. The array will be sorted in place.

Example (in C++):

```cpp
int main() {
    int array[] = {5, 3, 2, 10, 9, 0, -10, 8, 8, 1, 10, 30, 44, 31, 22};
    const int size = sizeof(array) / sizeof(array[0]);

    linkSort(array);

    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
```

## Conclusion

LinkSort is an efficient sorting algorithm for specific types of data sets, particularly those that expand in a manner where each new element is either the smallest or the largest seen so far. The use of a doubly linked list allows for flexible and efficient insertion of elements in their correct order, achieving optimal performance in favorable scenarios.
