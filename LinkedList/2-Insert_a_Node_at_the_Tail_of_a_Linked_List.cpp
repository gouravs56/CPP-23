#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// By using &, we pass a reference to the original pointer, which allows us to modify it inside the function. use of "pass-by-reference" 
void insertAtEnd(Node*& head, int value) { 
    Node* newNode = new Node{value, nullptr}; // create new node with given value
    
    if (head == nullptr) {
        // list is empty, new node becomes head
        head = newNode;
    } else {
        // traverse to last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        // set next pointer of last node to new node
        current->next = newNode;
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // initialize an empty list
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
      // print the list
    printList(head);

    int value;
        // get value from user
        cout << "Enter a value to insert at the end of the Linkedlist: ";
        cin >> value;
        
        // insert the value at the end of the list
        insertAtEnd(head, value);
        
    
    // print the list after new node inserted
    printList(head);
    
    return 0;
}
