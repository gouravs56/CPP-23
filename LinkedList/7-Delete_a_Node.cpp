#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node* deleteNode(Node* head, int position) {
    if (head == nullptr) {
        return nullptr;// The list is empty, so there's nothing to delete.
    }
    if (position == 0) {
        // The node to be deleted is the head node.
        Node* newHead = head->link;
        delete head;
        return newHead; 
    }
    Node* prev = head;
    Node* curr = head->link;
    int i = 0;
    while (curr != nullptr && i < position - 1) {
        prev = curr;
        curr = curr->link;
        i++;
    }
    if (curr == nullptr) {
    // The given position is greater than the length of the list,so there's nothing to delete.
        return head;
    }

    prev->link = curr->link; /* connecting prev node link with the next element of deleting element */
    delete curr; 
    return head;
}


// --------same as previous codes-------------
void insertNode(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->link;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter data for node " << i << ": ";
        cin >> data;
        insertNode(head, data);
    }

    cout << "Enter the position of the node to delete: ";
    int position;
    cin >> position;
    head = deleteNode(head, position);
    cout << "Updated list: ";
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->link;
    }
    cout << endl;

    return 0;
}
