// Compare_two_linked_lists to check if both are equal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// function to free the memory allocated for a linked list
void freeLinkedList(Node* head) {
    if (head == nullptr) {
        return;
    }
    freeLinkedList(head->next);
    free(head);
}

// recursive function to compare two linked lists
bool compareLinkedLists(Node* head1, Node* head2) {
    // if both lists are empty, they are equal, 3 base conditions
    if (head1 == nullptr && head2 == nullptr) {
        return true;
    }
    // if one of the lists is empty, they are not equal
    if (head1 == nullptr || head2 == nullptr) {
        return false;
    }
    // if the current nodes have different data, the lists are not equal
    if (head1->data != head2->data) {
        return false;
    }
    // recurse on the next nodes of the lists
    return compareLinkedLists(head1->next, head2->next); /* checking if the next newNode address is same or not for comparison */
}

int main() {
    int tests;
    cin >> tests;
    while(tests--) {
        int n1;
        cin >> n1;
        Node* head1 = nullptr;
        // read in the elements of the first linked list
        for(int i=0;i<n1;i++) {
            int item;
            cin >> item;
            Node* newNode = new Node{item, head1};
            head1 = newNode;
        }
        int n2;
        cin >> n2;
        Node* head2 = nullptr;
        // read in the elements of the second linked list
        for(int i=0;i<n2;i++) {
            int item;
            cin >> item;
            Node* newNode = new Node{item, head2};
            head2 = newNode;
        }
        // compare the two linked lists and print out the result
        bool result = compareLinkedLists(head1, head2);
        if(result == true) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
        // free the memory allocated for the linked lists
        freeLinkedList(head1);
        freeLinkedList(head2);
    }
    return 0;
}
