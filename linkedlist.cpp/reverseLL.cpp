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
    else{
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

void reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr=head->next;
while(currptr!=NULL){
//nextptr=currptr->next;
currptr->next=prevptr;

prevptr=currptr;
currptr=nextptr;
if(currptr==NULL){
    continue;
}
nextptr=nextptr->next;
}
head=prevptr;
}

void reverserecursive(node* &head,node* prevptr,node* currptr,node* nextptr){
 currptr->next=prevptr;
 if(nextptr==NULL){
     head=currptr;
return;
 }
 reverserecursive(head,currptr,nextptr,nextptr->next);

}

int main()
{
    node *head = NULL;
    insertattail(head, 10);
    insertattail(head,20);
    insertattail(head,30);
    insertattail(head,40);
    insertattail(head,50);
    insertattail(head,100);
    insertattail(head,0);
    display(head);

reverserecursive(head,NULL,head,head->next);
display(head);
    return 0;
}