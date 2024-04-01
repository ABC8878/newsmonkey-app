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
    cout<<endl;
}

void append(node *&head, int n, int k)
{
    node *temp = head;
    int count = 1;
    while (count != n - k)
    {
        temp = temp->next;
        count++;
    }
    node *newhead = temp->next;
    temp->next = NULL;
    temp = newhead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head = newhead;
}

int main()
{
    node *head = NULL;
    insertattail(head, 10);
    insertattail(head, 20);
    insertattail(head, 30);
    insertattail(head, 40);
    insertattail(head, 50);
    insertattail(head, 60);
    insertattail(head, 70);
    insertattail(head, 80);
    insertattail(head, 90);
    display(head);
    append(head,9,8);
    display(head);

    return 0;
}