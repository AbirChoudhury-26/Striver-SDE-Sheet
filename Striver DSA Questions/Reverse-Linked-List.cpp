#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef struct linknode{
    int data;
    struct linknode *next;
}node;
node *head,*last,*temp,*prev,*curr,*next;

void create_node()
{
    temp=(node*)malloc(sizeof(node));
    cout<<"Enter the number :";
    cin>>temp->data;
    temp->next=NULL;

}
int display()
{
    temp=head;
     while(temp!=NULL)
     {
        cout<<temp->data<<" ";
         temp=temp->next;
     }
     cout<<endl;
}

int reverselinklist()
{
      curr=head;
      node *prev=NULL;
       while(curr)
       {
      node *next=curr->next;
      curr->next=prev;

      prev=curr;
      curr=next;
       }
      head=prev;
       display();
}
int main()
{
int n;
cin>>n;
for(int i=0;i<n;i++)
{
     create_node();
      if(head==NULL)
      {
        head=temp;
        last=temp;
      }
      else{
        last->next=temp;
        last=temp;
      }
}
 display();
 cout<<"Reverse Linked-List is:" <<endl;
  reverselinklist();

}