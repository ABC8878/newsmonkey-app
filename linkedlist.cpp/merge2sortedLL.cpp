#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertattail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *merge2LL(node *head1, node *head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *dummynode = new node(NULL);
    node *ptr3 = dummynode;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
    }
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummynode->next;
}
int main()
{
    node *head1 = NULL;
    insertattail(head1, 1);
    insertattail(head1, 3);
    insertattail(head1, 5);
    insertattail(head1, 7);
     insertattail(head1,50);
     insertattail(head1,60);
     insertattail(head1,70);
    display(head1);
    node *head2 = NULL;
    insertattail(head2, 2);
    insertattail(head2, 4);
    insertattail(head2, 6);
    insertattail(head2, 8);
    display(head2);
    node *newhead = merge2LL(head1, head2);
    display(newhead);

    return 0;
}