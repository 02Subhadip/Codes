#include<stdio.h>
void InsertionSort(int arr[],int low,int high){
  int k;
  for(int i=1;i<high;i++){
  k=arr[i];

  for(int j=i-1;j>=0 && k<arr[j];j--)
     {
       arr[j+1]=arr[j];
       arr[j]=k;
     }

  }
}
int main()
{
  int arr[]={33,13,16,25,76,23},size=6; 
  int low=0;
  InsertionSort(arr,low,size);
  for(int i=0;i<size;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}

