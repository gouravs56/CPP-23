// In this program I have given a example with the code for better understanding :-) .
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void insertNode(Node*& head, int data, int position) {  // Node*& head is reference to a pointer 
    Node* newNode = new Node();
    newNode->data = data;

    if (position == 1) { /* just like insert at head's code */
        newNode->next = head;
        head = newNode;
        return;
    }
    // for example a list is 4 5 6 7 8 and their address is 100,200,300,400,500 respectively
    Node* current = head; /* so now in the beginning current = 100 and pointing 4 same as head */
    for (int i = 1; i < position - 1 && current != nullptr; i++) { /* so now if we want to insert the newNode=9 at 4th position after 6.
    then the loop will iterate 1 to 2 [2 < 4-1] & there is no need to iterate to position as we can get the address of */
        current = current->next; /* this means storing Second item's[current->next] address into First item's address[current]  */
 // so after 1st iteration current = 200 since current->next was 200 when current was = head and now current will point to 5 [200 address] and now current->next will be 300
 // after 2nd iteration current = 300 and now current->next is 400 and will point to 6.
    }

    if (current == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }

    newNode->next = current->next; /* newNode->next = 400 [current->next] so now newNode has the link to connect 7 */
    current->next = newNode;       /* now current has the link to connect newNode so  current->next = x ( x = newNode's address)*/
    // so besically , current = (position - 1 )address
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next; 
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // create initial linked list
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 1; i <= n; i++) { 
        int data;
        cout << "Enter data for node " << i << ": ";
        cin >> data;
        insertNode(head, data, i); 
    }
    // print initial linked list
    cout << "Initial linked list: ";
    printList(head);


    // insert new node at specific position
    int newData, position;
    cout << "Enter position for new node: ";
    cin >> position;
    cout << "Enter data for new node: ";
    cin >> newData;
    
    insertNode(head, newData, position);

    // print updated linked list
    cout << "Updated linked list: ";
    printList(head);

    return 0;
}
