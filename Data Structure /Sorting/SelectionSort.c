#include<stdio.h>
void SelectionSort(int arr[],int low,int size){
 int temp,i=low,j,n=size,Mindex;
 while(i!=n)
 { Mindex=i;
   for(j=i+1;j<n;j++)
    {
      if(arr[Mindex]>arr[j])
       {
         Mindex=j; }
    temp=arr[i];
    arr[i]=arr[Mindex];
    arr[Mindex]=temp;
    }
   i++;
 }
    }

int main()
{ 
int arr[]={23,13,16,11,82,12},size=6; 
  int low=0;
  SelectionSort(arr,low,size);
  for(int i=0;i<size;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
