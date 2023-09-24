#include<stdio.h>
int LinearSearch(int arr[],int size,int item){
for(int i=0;i<size;i++)
    {  if(arr[i]==item)
       { return i+1; }
    } 
return -1;  }
int main()
{
  int arr[]={23,13,16,11,17,12},size=6; 
  int item=23;
  int result=LinearSearch(arr,size,item);
  if(result==-1)
     printf("Result not found in array\n");
  else
    printf("The item found in %d location in array.\n",result);
  return 0;
}
