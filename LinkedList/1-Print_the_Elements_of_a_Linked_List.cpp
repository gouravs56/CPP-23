#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next; /*it is self referencial structure eg, bcoz next is pointer to the address of the next "Node"*/
};

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " "; /* printing the data of current node */
        current = current->next;
    }
}

int main() {
    // Create a linked list based on user input
    int n, value;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    Node* head = nullptr; /* initializing head (address of the 1st node) with NULL */
    Node* current = nullptr;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of node " << i + 1 << ": ";
        cin >> value;

        if (head == nullptr) {  /* for 1st node */
            head = new Node{value, nullptr}; /* "new" dynamically allocate memory for the head of the linked list with a new node that contains the given value and a null pointer for the next member */
            current = head;
        } else {
            current->next = new Node{value, nullptr};
            current = current->next;
        }
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