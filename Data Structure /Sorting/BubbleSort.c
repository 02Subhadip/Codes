#include<stdio.h>
void BubbleSort(int arr[],int low,int size){
 int temp,i=low,j,n=size;
 while(i!=n-1)
 {
   for(j=0;j<n-i-1;j++)
    { if(arr[j]>arr[j+1])
       {
         temp=arr[j];
         arr[j]=arr[j+1];
         arr[j+1]=temp;
       }
    }
    i++;
 }
     }
int main()
{
  int arr[]={23,13,16,11,82,12},size=6; 
  int low=0;
  BubbleSort(arr,low,size);
  for(int i=0;i<size;i++)
  {
    printf("%d ",arr[i]);
  }
  return 0;
}
