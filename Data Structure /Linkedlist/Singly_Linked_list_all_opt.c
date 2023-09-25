#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;//Here we use Node because of typedef

void Traversal(struct Node *ptr)// Function body for Linked list traversal
{
    while(ptr)//Here we can use while(ptr!=NULL)
       {
        printf("Element of Linkedlist: %d\n",ptr->data);
       //printf("Element of Linkedlist: %d\n",(*ptr).data); > We can also use this for print.
       ptr=ptr->next;   } 
}

struct Node *InsertAtFirst(struct Node *head){// Function body for Insert at first node.
  int element;
  printf("Enter the element whihc you wanna to insert: ");
  scanf("%d",&element);

  struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));// Dynamicaly creat memory for new node in Heap. 
  ptr->data=element;
  ptr->next=head;
  return ptr;//Here we return ptr because now our head replece by ptr.
}//End of the InsertAtFirst function. 

struct Node *InsertAtIndex(struct Node *head){// Function body for Insert at given index node.
  int element,index;
  printf("Enter the element which you wanna to insert: \n");
  scanf("%d",&element);
  printf("Enter the Index of the element: ");
  scanf("%d",&index);

   struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
   struct Node *p=head;
   int i=0;
   while(i=index-1)
    { 
      p=p->next;
    
    }

  ptr->data=element;
  ptr->next=p->next;
  p->next=ptr;
  
  return head;   
}//End of the InsertAtIndex function. 

struct Node *InsertAtEnd(struct Node *head){//Function body to insert at last node.
  int element;
  printf("Enter the element which you wanna to insert \n");
  scanf("%d",&element);

  struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
  struct Node *p=head;
  while(p->next!=NULL)
   {
     p=p->next;
   }
  ptr->data=element;
  p->next=ptr;
  ptr->next=NULL;
  
return head;
}//End of the InsertAtEnd function.

struct Node *InsBeNode(struct Node *head){//Function body for insert a val before a node.
    int val,node;
    printf("Enter the val to be insert before a node: ");
    scanf("%d",&val);
    printf("Enter the node which before you wanna to insert: ");
    scanf("%d",&node);
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node *p=head;
    struct Node *tmp=head;
    while(p->next->data!=node)
    {
        p=p->next;
    }
    while(tmp->data!=node)
    {
        tmp=tmp->next;
    }
   ptr->data=val;
   p->next=ptr;
   ptr->next=tmp;

return head;    
}//End of InsBeforeNode.

struct Node *InsAfNode(struct Node *head){// Function body for insert a val after a node 
    int val,node;
    printf("Enter the val to be insert : ");
    scanf("%d",&val);
    printf("Enter the node to insert after it's next node: ");
    scanf("%d",&node);
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node *tmp=head;
    while(tmp->data!=node)
    {
        tmp=tmp->next;
    }
   ptr->data=val;
   ptr->next=tmp->next;
   tmp->next=ptr;

 return head;
}// End of InsAfNode 


struct Node *InsertAfterIndex(struct Node *head){// Function body for Insert after Index.
 int element,node;
 printf("Enter the element to be insert: ");
 scanf("%d",&element);
 printf("Enter the node position to be insert in after: ");
 scanf("%d",&node);
 
 struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
 struct Node *temp=head;

 int i=1;
  while(i!=node)
  {
    temp=temp->next;
    i++;
  }
 ptr->data=element;
 ptr->next=temp->next;
 temp->next=ptr;
 
 return head;
   
}//End of the InsertAfterNode function.

struct Node *InsertBeforeNode(struct Node *head){// Function body for Insert Before Index.
    int item, node;
    printf("Enter the item to be insert: ");
    scanf("%d",&item);
    printf("Enter the node position to be insert in before: ");
    scanf("%d",&node);
   
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));// DMA for new ptr data in Heap.
    struct Node *p=head;// A tempurary node for select previous postion of ptr.
    struct Node *temp=head;// A tempurary pointer for find the given node position.

     if(node<1)
     {   printf("\n"); 
         printf("Enter a valid node position!!..\n\n");
         return head;
     }
     else if(node==1)
      { printf("\n"); 
        printf("You choice 1st node you should chose 2nd option for insert at frist..!!\n\n");
        return head;
       }

    int i=1;//loop element.
    while(i!=node)//loop for temp ptr.
     {
         temp=temp->next;
         i++;
     }
    ptr->data=item;
    ptr->next=temp;
    while(p->next!=temp)
    {
        p=p->next;
    }
    p->next=ptr;
    
    return head;
  }//End of InsBeforeNode.

  struct Node *DeleteAtBeg(struct Node *head){// Function body for Delete element from begining.
    struct Node *ptr=head->next;
    free(head);
    return ptr;

    /* We can also use 
      struct Node *ptr=head;
      head=head->next;
      free(ptr);
      return head;
      */

  }// End of delelteAtBeg function.

 struct Node *DeleteAtIndex(struct Node *head){// Function body for Delete element at given Index.
   int index;
   printf("Enter the index which node you wanna to delete: ");
   scanf("%d",&index);

   struct Node *ptr=head;
   for(int i=1;i!=index-1;i++){// Here we can also use int i=1; while(i!=index-1).
     ptr=ptr->next;
   }

   struct Node *p=ptr->next;
   ptr->next=p->next;
   free(p);
   return head;
 }// End of DeleteAtIndex.

 struct Node *DeleteAtEnd(struct Node *head){// Function body for Delete element at last index.
    struct Node *ptr=head;
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
    struct Node *p=head;// Another ptr for reched privious node of ptr node.
    while(p->next!=ptr)
     {
       p=p->next;
     }
     p->next=NULL;// We link the p with null and delete the ptr node.
     free(ptr);
     return head;

    /*  We can also use like this 
      struct Node *ptr=head;
      struct Node *tmp;
      while(ptr->next!=NULL)
       { tmp=ptr;
         ptr=ptr->next;
         }
       tmp->next=NULL;
       free(ptr); */
  
   
   /* We can also use like this 
     struct Node *p=head,*q=head->next;
     while(q->next!=NULL)
     {
       p=p->next;
       q=q->next;
     }
     p->next=NULL;
     free(q);
     return head; */
  }// End of DeleAtEnd function.

struct Node *DelWithValue(struct Node *head){// Function body for Delete element with a value.
 int element;
 printf("Enter the data to be deleted: ");
 scanf("%d",&element);
 struct Node *ptr=head;
 struct Node *p=head;
  while(ptr->data!=element && ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  if(ptr->data!=element)
  {
    printf("Element not found in list!! \n");
    return head;
  }
  else
 
 while(p->next!=ptr)
 {
   p=p->next;
 }
 p->next=ptr->next;
 free(ptr);
 
 return head;
 /* We can also use this approach
   struct Node *DelatIndex(struct Node *head){
     int node;
     printf("Enter the node which you wanna to delete: ");
     scanf("%d",&node);
    struct Node *ptr=head;
    while(ptr->next->data!=node)
     {
         ptr=ptr->next;
     }

     if(ptr->next==NULL)
      {printf("Item not found in list\n");
       return head;}
     struct Node *p=ptr->next;
     ptr->next=p->next;
     free(p);
     return head;
}*/

}// End of DelWithValue.

struct Node *DelBeforeVal(struct Node *head){// Function body for dlete a node after a node.
  int val;
  printf("Enter the node to delete its before element: ");
  scanf("%d",&val);

  struct Node *ptr=head;
  while(ptr->next->next->data!=val){
    ptr=ptr->next;
  }
  struct Node *p=ptr->next;
  ptr->next=p->next;
  free(p);
  
  /* We can also use this approach
  struct Node *ptr=head;
  struct Node *p=head;
  while(ptr->next->data!=val)
  {
    ptr=ptr->next;
  }
  while(p->data!=val)
  {
    p=p->next;
  }
  ptr->next=p->next;
  free(p); */

return head;
}

struct Node *DelAfterVal(struct Node *head){//Function body for Delete element after a chosern value.
  int value;
  printf("Enter the node to delete it's after node:  ");
  scanf("%d",&value);

  struct Node *ptr=head;
  while(ptr->data!=value)
  { 
    ptr=ptr->next;
  }
  if(ptr->next==NULL )
   {
     printf("\nThere is no node after choseen value !!\n");
     return head;
   }
  struct Node *p=ptr->next;
  ptr->next=p->next;
  free(p);
  
  return head;
}// End of DelAfterVal.

int main()
{    
     Node *head,*second,*third,*fourth;
    // Node *head; or if we use only struct without typedef then we can also use (struct Node *head).
    // Node *second;
    // Node *third;

    // Allocated memory for nodes in Linked List in Heap 
    head=(struct Node*) malloc(sizeof(struct Node));
    second=(struct Node*) malloc(sizeof(struct Node));
    third=(struct Node*) malloc(sizeof(struct Node));

    fourth=(struct Node*) malloc(sizeof(struct Node));
    //Linked frist node with second node
    head->data=23;
    //(*head).data=23; > we can also use this formate to link with node and incilized data.
    head->next=second;

    //Linked second node with third node
    second->data=13;
    (*second).next=third;
    // second->next=third;
    

    //Linked third node with fourth node
    third->data=16;
    third->next=fourth;
    
    // Tarminate the fourth node at the end of the list
    fourth->data=11;
    fourth->next=NULL;

 
  // head=InsertAtFirst(head);
  // head=InsertAtIndex(head);
  // head=InsertAtEnd(head);
  //  head=InsertAfterIndex(head,second);

  //Traversal(head); //Function call for Linked List traversal
    int choice;
    while(1)
    {   printf("*****************************************\n");
        printf("Press 1. for Display\n\n");
        printf("** Insertion Operation On Singly Linked List**\n\n");
        printf("Press 2. for Insert a node to empty list/ Add at begining\n");
        printf("Press 3. for Insert a node at end\n");
        printf("Press 4. for Insert a node after a node\n");
        printf("Press 5. for Insert a node before a node\n");
        printf("Press 6. for Insert a node after a node with node position\n");
        printf("Press 7. for Insert a node before a node with node positon\n");
        printf("Press 8. for Insert a node at position\n\n");
        printf("** Delete Operation On Singly Linked List**\n\n");
        printf("Press 9. for Delete a node at first\n");
        printf("Press 10. for Delete a node with index\n");
        printf("Press 11. for Delete a node at end\n");
        printf("Press 12. for Delete a node with a value\n");
        printf("Press 13. for Delete a node with before a node\n");
        printf("Press 14. for Delete a node with after a node\n");
        printf("Press 15. for Quit\n");
        printf("*****************************************\n\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
               Traversal(head);
               break;
            case 2:
               head=InsertAtFirst(head);
               break;
            case 3:
               head=InsertAtEnd(head);
               break;
            case 4:
               head=InsAfNode(head);
               break;
             case 5:
               head=InsBeNode(head);
               break;
            case 6:
               head=InsertAfterIndex(head);
               break;
            case 7:
               head=InsertBeforeNode(head);
               break;
            case 8:
              head=InsertAtIndex(head);
               break;
            case 9:
              head=DeleteAtBeg(head);
               break;
            case 10:
              head=DeleteAtIndex(head);
               break;
            case 11:
              head=DeleteAtEnd(head);
               break;
            case 12:
              head=DelWithValue(head);
               break;
            case 13:
              head=DelBeforeVal(head);
               break;
            case 14:
              head=DelAfterVal(head);
               break;
            case 15:
               exit(1);
            default:
              printf("Worng choice\n");
        }// End of switch
    }

return 0;
}

