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

int findintersection(node *&head1, node *&head2, int l1, int l2)
{
    node *ptr1;
    node *ptr2;
    int l = 0;
    int count = 0;
    if (l1 > l2)
    {
         l = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
         l = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (count != l)
    {
        ptr1 = ptr1->next;
        count++;
    }
    while (ptr1->next != ptr2->next)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1->next->data;
}

void makeintersection(node *&head1, node *&head2, int pos)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    int count = 1;
    while (count != pos)
    {
        ptr1 = ptr1->next;
        count++;
    }
    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr1;
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

int main()
{
    node *head1 = NULL;
    insertattail(head1, 10);
    insertattail(head1, 20);
    insertattail(head1, 30);
    insertattail(head1, 40);
    insertattail(head1, 50);
    insertattail(head1, 60);
    display(head1);
    node *head2 = NULL;
    insertattail(head2, 1);
    insertattail(head2, 2);
    display(head2);
    makeintersection(head1, head2, 5);
    display(head1);
    display(head2);
    cout << findintersection(head1, head2, 6, 4);
    return 0;
}