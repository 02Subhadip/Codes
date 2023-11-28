#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *priv;
    struct Node *next;
}Node;

void Traversal(struct Node *head){//Function body for display in Doubly linkedlist.
    struct Node *ptr=head;
    while(ptr!=NULL)
     {
         printf("Element of dubly linked list is: %d\n",ptr->data);
         ptr=ptr->next;
     }
}

struct Node *InsAtF(struct Node *head){//Function body for Insert a node at frist in Doubly linkedlist.
    int data;
    printf("Enter the data you wanna to insert: ");
    scanf("%d",&data);
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->priv=NULL;
    ptr->next=head;
    head->priv=ptr;
    return ptr;
}// End of the InsAtF function.

struct Node *InsAtE(struct Node *head){// Function body for insert a node ant last in Doubly linkedlist.
    int data;
    printf("Enter the data you wanna to insert: ");
    scanf("%d",&data);
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node *p=head;

    while(p->next!=NULL)
   { p=p->next; }

    ptr->data=data;
    ptr->next=NULL;
    ptr->priv=p;
    p->next=ptr;

return head;
}// End of the InsAte function.

struct Node *InsAtPos(struct Node *head){//Function body for insert a node at postion in Doubly linkedlist.
    
    int data,loc;
    printf("Enter the data you wanna to insert: \n");
    scanf("%d",&data);
    printf("Enter the location to be inserted: ");
    scanf("%d",&loc);
    int i=1;
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node *p=head;
    while(i!=loc-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    ptr->priv=p;
    p->next=ptr;

   return head;   
}// End of the InsAtPos function.

struct Node *InsBeforeNode(struct Node *head){//Function body for insert before a node in Doubly linkedlist.
    
    int data,node;
    printf("Enter the data you wanna to insert: \n");
    scanf("%d",&data);
    printf("Enter node to inserted it's before: ");
    scanf("%d",&node);
    int i=1;
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node *p=head;
    while(p->next->data!=node){
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    ptr->priv=p;
    p->next=ptr;

   return head;   
}// End of the InsBeforeNode function.

struct Node *InsAfterNode(struct Node *head){//Function body for insert after a node in Doubly linkedlist.
    
    int data,node;
    printf("Enter the data you wanna to insert: \n");
    scanf("%d",&data);
    printf("Enter the node inserted it's after: ");
    scanf("%d",&node);
    int i=1;
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node *p=head;
    while(p->data!=node){
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    ptr->priv=p;
    p->next=ptr;

   return head;   
}// End of the InsAfterNode function.

struct Node *DelAtF(struct Node *head){//Function body for delete node at frist.
    struct Node *p=head;
    head=head->next;
    head->priv=NULL;
    free(p);
    return head;
}//End of the DelAtF

struct Node *DelAtE(struct Node *head){//Function body for delete node at last.
    struct Node *p=head;
    while(p->next->next!=NULL){
        p=p->next;
    }
    struct Node *tmp=p->next;
    p->next=NULL;
    free(tmp);
    return head;
}//End of the DelAtE

struct Node *DelAtLoc(struct Node *head){//Function body for delete node at given location.
    int loc;
    printf("Enter the location to be deleted: ");
    scanf("%d",&loc);
    int i=1;
    struct Node *p=head;
    while(i!=loc-1){
        p=p->next;
        i++;
    }
    struct Node *tmp=p->next;
    p->next=tmp->next;
    free(tmp);
    return head;
}//End of the DelAtLoc

struct Node *DelNode(struct Node *head){//Function body for delete particular node.
    int node;
    printf("Enter the node to be deleted: ");
    scanf("%d",&node);
    struct Node *p=head;
    while(p->next->data!=node){
        p=p->next;
    }
    struct Node *tmp=p->next;
    p->next=tmp->next;
    free(tmp);
    return head;
}//End of the DelNode

int main()
{  
    Node *head,*second,*third,*fourth;
    head=(struct Node*) malloc(sizeof(struct Node));
    second=(struct Node*) malloc(sizeof(struct Node));
    third=(struct Node*) malloc(sizeof(struct Node));
    fourth=(struct Node*) malloc(sizeof(struct Node));

  head->data=23;
  head->priv=NULL;
  head->next=second;

  second->data=13;
  second->priv=head;
  second->next=third;
  
  third->data=16;
  third->priv=second;
  third->next=fourth;

  fourth->data=11;
  fourth->priv=third;
  fourth->next=NULL;
  
   int choice;
    while(1)
    {   printf("*****************************************\n");
        printf("Press 1. for Display\n\n");
        printf("** Insertion Operation On Doubly Linked List**\n\n");
        printf("Press 2. for Insert a node to empty list/ Add at begining\n");
        printf("Press 3. for Insert a node at end\n");
        printf("Press 4. for Insert a node after a node\n");
        printf("Press 5. for Insert a node before a node\n");
        printf("Press 6. for Insert a node at position\n\n");
        printf("** Delete Operation On Doubly Linked List**\n\n");
        printf("Press 7. for Delete a node at first\n");
        printf("Press 8. for Delete a node at end\n");
        printf("Press 9. for Delete a node with location\n");
        printf("Press 10. for Delete a node with a value\n");
        printf("Press 11. for Quit\n");
        printf("*****************************************\n\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
               Traversal(head);
               break;
            case 2:
               head=InsAtF(head);
               break;
            case 3:
               head=InsAtE(head);
               break;
            case 4:
               head=InsAfterNode(head);
               break;
             case 5:
               head=InsBeforeNode(head);
               break;
            case 6:
               head=InsAtPos(head);
               break;
            case 7:
               head=DelAtF(head);
               break;
            case 8:
              head=DelAtE(head);
               break;
            case 9:
              head=DelAtLoc(head);
               break;
            case 10:
              head=DelNode(head);
               break;
            case 11:
               exit(1);
            default:
              printf("Wrong choice\n");
        }// End of switch
    }
  return 0;
}

