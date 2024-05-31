# C++ Linked List Operations

This repository contains an implementation of various operations on a singly linked list in C++. The operations include counting nodes, displaying the list, adding nodes at different positions, and deleting nodes from the list.

## Table of Contents
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features
- Count the number of nodes in the linked list.
- Display the nodes of the linked list.
- Add nodes to the start, end, and specific positions in the linked list.
- Delete nodes from the start, end, and specific positions in the linked list.
- Delete the entire linked list.

## Getting Started

### Prerequisites
- C++ compiler (g++, clang, etc.)
- CLion IDE (optional, but recommended)

### Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/Adamo08/cpp-linked-list-operations.git
    cd cpp-linked-list-operations
    ```

2. Open the project in CLion:
    - Launch CLion.
    - Open the project directory (`cpp-linked-list-operations`).

3. Build and run the project using CLion's build tools.

## Usage
The main functions implemented in this project are:

- **countNodes(Node* head)**: Counts and prints the number of nodes in the linked list.
- **showList(Node* head)**: Displays the linked list.
- **addToList(Node* head, int data)**: Adds a node to the end of the linked list.
- **addToStart(Node* head, int data)**: Adds a node to the start of the linked list.
- **insertAtPos(Node* head, int data, int pos)**: Inserts a node at a specific position in the linked list.
- **removeHead(Node* head)**: Removes the head node of the linked list.
- **removeEnd(Node* head)**: Removes the last node of the linked list.
- **removeFromPos(Node* head, int pos)**: Removes a node from a specific position in the linked list.
- **deleteList(Node* head)**: Deletes the entire linked list.

### Example
Here's an example of how to use the functions:

```cpp
int main() {
    struct Node *Head = NULL;
    Head = (struct Node *) malloc(sizeof(Node));
    Head->Data = 45;
    Head->Link = NULL;

    addToList(Head, 15);
    addToList(Head, 55);
    addToList(Head, 5);

    countNodes(Head);
    showList(Head);

    Head = addToStart(Head, 44);
    Head = addToStart(Head, 56);

    countNodes(Head);
    showList(Head);

    insertAtPos(Head, 0, 3);
    countNodes(Head);
    showList(Head);

    Head = removeHead(Head);
    countNodes(Head);
    showList(Head);

    removeEnd(Head);
    countNodes(Head);
    showList(Head);

    removeFromPos(&Head, 3);
    countNodes(Head);
    showList(Head);

    Head = deleteList(Head);
    showList(Head);

    return 0;
}
