#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == nullptr) { //if any of one list is empty then other one is the output
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }
    if (head1->data < head2->data) {   //if head1 is smaller than head2 take the 2nd element of head1 and from that merge the entire 2 list recursively into the head1
        head1->next = mergeSortedLists(head1->next, head2);
        return head1;
    }
    else {
        head2->next = mergeSortedLists(head1, head2->next);
        return head2;
    }
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        Node* head1 = nullptr;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            Node* newNode = new Node{val, nullptr};
            if (head1 == nullptr) {
                head1 = newNode;
            }
            else {
                Node* curr = head1;
                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                curr->next = newNode;
            }
        }
        cin >> m;
        Node* head2 = nullptr;
        for (int i = 0; i < m; i++) {
            int val;
            cin >> val;
            Node* newNode = new Node{val, nullptr};
            if (head2 == nullptr) {
                head2 = newNode;
            }
            else {
                Node* curr = head2;
                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                curr->next = newNode;
            }
        }
        Node* result = mergeSortedLists(head1, head2);
        printList(result);
    }
    return 0;
}
