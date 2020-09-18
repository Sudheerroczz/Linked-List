#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head; //global variable
void reverseitr()
{
    struct Node* curr=head;
    struct Node* prev=NULL;
    struct Node* next=NULL;
    
    while(curr!=NULL)
    {
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
    }
    head=prev;
    
}

void reverse(struct node* ptr){
   if(ptr->next == NULL){
      head = ptr;
      return;
    }
 
    /* Calling reverse method recursively */
 
    reverse(ptr->next);
 
    struct node* rev = ptr->next;
    rev->next = ptr;
    ptr->next = NULL;
}
 
void delatpos(int pos)
{   
    struct Node *ptr=head;
    if(head==NULL)
    {
        return;
    }
    if(pos==1)
    {
        head=head->next;
        free(ptr);
    }
    else
    {
        int count=1;
        while(count<pos-1)
        {
            ptr=ptr->next;
            count++;
        }
       struct Node* temp2=ptr->next;
       ptr->next=temp2->next;
       free(temp2);
        
    }
    
}
void insertatbeg(int data) //prepend
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=head;
    head=temp;
}
void create(int data)
{ 
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr=head;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        
    }
}
void insertatnthpos(int data,int pos)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    struct  Node*ptr=head;
    temp->data=data;
    temp->next=NULL;
    if(pos==1)
    {
        temp->next=head;
        head= temp;
    }
    else
    {
        int count=1;
        while(count<pos-1)
        {
            count++;
            ptr=ptr->next;
        }
        struct Node* temp2=ptr->next;
        ptr->next=temp;
        temp->next=temp2;
        }
}
void midofLL()
{
   if(head==NULL)
    {
    printf("f");
    }
    else
    {
        struct Node *ptr1=head ,*ptr2=head;
        while(ptr1!=NULL & ptr2->next!=NULL) //two pointer approch o(nlogn)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next->next;
            
        }
        printf("%d\n",ptr1->data);
    }  
}
void print()
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
    if(temp->next)
        printf("%d ->",temp->data);
    else
        printf("%d.\n",temp->data);

    temp=temp->next;

    }
}

int main()
{
    head=NULL;
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        create(x);
    }
    print();
    return 0;
}
