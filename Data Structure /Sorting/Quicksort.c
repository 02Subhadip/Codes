#include<stdio.h>

int partition(int a[],int low,int high){
  int pivat=a[low],temp,i=low+1,j=high;
  do{
    while(a[i]<=pivat){
    i++;}
    while(a[j]>=pivat){
      j--;
    }
    if(i<j){
      temp=a[i];
      a[i]=a[j];
      a[j]=temp; }

  } while(i<j);

  temp=a[low];
  a[low]=a[j];
  a[j]=temp;

return j;
}
void quicksort(int arr[],int low,int high){
  if(low<high){
    int partitionIndex=partition(arr,low,high);
    quicksort(arr,low,partitionIndex-1);
    quicksort(arr,partitionIndex+1,high);
  }
}

int main()
{
  int arr[]={25,13,16,11,17,12};
  int size=6;
  int low=0;
  quicksort(arr,low,size-1);
  for(int i=0;i<size;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
