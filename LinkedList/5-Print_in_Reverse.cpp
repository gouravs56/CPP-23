#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};
// Iterative approach usingh 3 pointer
void reversePrint(Node *head)
{
    // for example a list is 6 7 8 and their address is 100,200,300 respectively
    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->link; /* for 1st iteraition next = 200[curr->link] as current = head = 6 and now next will point 7 */
        curr->link = prev; /* now making curr->link= NULL, so linking current node with previous node instead of next node  */
      
        prev = curr;       /* moving previous node to current node,so now prev=100 and it will point 6 */
        curr = next;       /* moving curr node to next node postion ,now curr = 200 and it will point 7*/
    // besically moving prev & curr 1 step in above 2 line
    }

    // prev is now the new head of the reversed list
    while (prev != NULL)
    {
        cout << prev->data << " ";
        prev = prev->link;
    }
    cout << endl;
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
    for (int i = 1; i <= n; i++)
    {
        int data;
        cout << "Enter data for node " << i << ": ";
        cin >> data;
        insertNode(head, data);
    }

    cout << "Original list: ";
    printLinkedList(head);

    cout << "Reversed list: ";
    reversePrint(head);

    return 0;
}
