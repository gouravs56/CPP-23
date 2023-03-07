#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNodeAtHead(Node*& head, int value) {
    Node* newNode = new Node{value, head}; /* creating newNode whichs data= given value and link/next = current head which is going to be the second node after that */
    head = newNode; /* now head pointing the newnode, so now current head is newNode  */
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    // Create a linked list based on user input
    int n, value;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        cout << "Enter the value of node " << i + 1 << ": ";
        cin >> value;
        insertNodeAtHead(head, value);
    }

    // Print the linked list
    cout << "The linked list is: ";
    printLinkedList(head);
    cout << endl;

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
