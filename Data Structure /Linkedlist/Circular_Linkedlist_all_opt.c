#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;

void Display(struct Node *head){// Display function
    struct Node *ptr=head;
   
     do{
        printf("Element of Circular list: %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}// End of display function

struct Node *CountNode(struct Node *head){//Count function.
    int count=0;
   struct Node *ptr=head;
   do{
       count++;
       ptr=ptr->next;
   }while(ptr!=head);

 printf("The number of node in Cirucular linked list is: %d\n",count);
 return head;
}// End of count function.

struct Node *InsertAtFirst(struct Node *head){// Function Body for insert at begining of circular list.
    int ele;
    printf("Enter the element to be insert at end: ");
    scanf("%d",&ele);
   
    struct Node *p=head->next;
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    while(p->next!=head){
        p=p->next;
    }
   
    p->next=ptr;
    ptr->data=ele;
    ptr->next=head;
    head=ptr;
    
    return head;
}// End of InsertAtFirst function.

struct Node *InsertAtIndex(struct Node *head){// Function body for delete at Index in circular linked list.
    int ele,pos;
    printf("Enter the element to be insert: ");
    scanf("%d",&ele);
    printf("Enter the pos to be insert : ");
    scanf("%d",&pos);
    struct Node *p=head;
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    for(int i=1;i!=pos-1;i++)
    {
        p=p->next;
    }
    ptr->data=ele;
    ptr->next=p->next;
    p->next=ptr;
    
    return head;
}

struct Node *InsertAtEnd(struct Node *head){// Function body for insert at end of cirular list.
   struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
   struct Node *p=head->next;
   while(p->next!=head)
   {
       p=p->next;
   }
   ptr->data=59;
   p->next=ptr;
   ptr->next=head;

   return head;
}// End of InsertAtEnd function

struct Node *DelatBeg(struct Node *head){// Function body fr delete first node in circular linked list.

    struct Node *p=head,*fristnode=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=fristnode->next;
    free(fristnode);
    
    return p;
}// End of DelatBeg function.

struct Node *DelatEnd(struct Node *head){
 
 struct Node *ptr=head->next;
 while(ptr->next->next!=head){
     ptr=ptr->next;
 }
 struct Node *p=ptr->next;
 ptr->next=head;
 free(p);

return head;
}


int main()
{
    Node *head,*second,*third,*fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=55;
    head->next=second;

    second->data=56;
    second->next=third;

    third->data=57;
    third->next=fourth;

    fourth->data=60;
    fourth->next=head;

    int choice;
    while(1)
    {   printf("*****************************************\n");
        printf("Press 1. for Display\n\n");
        printf("** Insertion Operation On Circular Linked List**\n\n");
        printf("Press 2. for Insert a node to empty list/ Add at begining\n");
        printf("Press 3. for Insert a node at end\n");
        printf("Press 4. for Insert a node at position\n");
        printf("** Delete Operation On Doubly Linked List**\n\n");
        printf("Press 5. for Delete a node at first\n");
        printf("Press 6. for Delete a node at end\n");
        printf("Press 7. for count the element of list\n");
        printf("Press 8. for Quit\n");
        printf("*****************************************\n\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
               Display(head);
               break;
            case 2:
               head=InsertAtFirst(head);
               break;
            case 3:
               head=InsertAtEnd(head);
               break;
            case 4:
               head=InsertAtIndex(head);
               break;
            case 5:
               head=DelatBeg(head);
               break;
            case 6:
               head=DelatEnd(head);
               break;
            case 7:
               head=CountNode(head);
               break;
            case 8:
               exit(1);
            default:
              printf("Worng choice\n");
        }// End of switch
    }
return 0;
}
