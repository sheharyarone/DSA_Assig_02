**Data Structures & Algorithms**

**Assignment 2: Linked Lists, Stack, Dequeue and Recursion**

**Section:** BSCS-11-A&C **Session:** Fall-2022

**Task 1: Linked Lists**

Following the previous assignment of linked list operations, complete the following functions:

1. Suppose you are given a list of n\>=0 integers stored in a **singly linked list**. Implement a function which takes two values as input from the user and searches them in the list. If both the values are found, your task is to swap both the nodes in which these words are found. Note, that you are not supposed to swap values. You are supposed to change the next pointer fields of the concerned nodes. Your function should handle all possible cases:
  1. The two nodes are not adjacent and none of them is the first or the last node.
  2. The two nodes are not adjacent to each other and one of them is the first/last node.
  3. Both nodes are adjacent and none of them is the first or the last one.
  4. Both nodes are adjacent and one of them is the first node.
  5. Both are adjacent, one is first and the other is last. This is the case in which the length of a list is two.

voidswapNodes(intvalue1, intvalue2) {

}

//print the updated list.

**Task 2: Applications of Linear Data Structures – Stacks and Dequeue**

1. Implement all operations of the **dequeue** data structure. Decide which implementation of among array, singly linked list, circular linked list and doubly linked list is most suitable to implement **dequeue.** The implemented dequeue will be used in the next sub-task.
2. Suppose a user is given a random sequence of integer values. He wants to sort them in the ascending order. However, he only has two stacks S1 and S2 at his disposal to sort the sequence. Devise an algorithm that sorts a given sequence using S1 and S2. You must implement S1 and S2 using **dequeue**.

voidsort(int\*arr, intsize) {

    // write your code here

}

**Task 3: Recursion**

Consider you have an array of size NxN that contains randomly generated 1's and 0's – where 1 represents an open path and 0 represents a wall.

1. Generate an array of size NxN and populate it with randomly generated 0s and 1s.
2. Pick two random points (one as a starting point and one as an ending point) and make sure that they are not walls.
3. Implement a recursive function that finds a path from the starting point to the ending point. The function should return true if a path exists and false otherwise.
4. Implement a recursive function that finds the **shortest path** from the starting point to the ending point. The function should return true if a path exists and false otherwise.
5. Implement a recursive function that finds the longest path from the starting point to the ending point. The function should return true if a path exists and false otherwise.
6. Implement a recursive function that finds the number of paths from the starting point to the ending point. The function should return the number of paths.

boolfindPath(intx, inty, intendX, intendY, int\*\*arr, intsize)

{

    // write base case

    // write recursive case

    // return false if no path exists

}

**Deliverables:**

- Ensure that you use the provided function definitions in your source code. **DO NOT** rename the functions or their input parameters.
- Create a word document containing your outputs. Moreover, paste your source code in a folder and upload both as .zip file on LMS.