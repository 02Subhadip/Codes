#include<stdio.h>
void Marge(int arr[],int low,int mid,int size){
  int i,j,k,r[100];
  i=low,k=low,j=mid+1;
  while(i<=mid && j<=size){

    if(arr[i]<arr[j])
     {
       r[k]=arr[i];
       k++,i++;  }
    else
     {
       r[k]=arr[j];
       j++,k++; }
     }

  while(i<=mid)
    {
      r[k]=arr[i];
      i++,k++;
    }
    while(j<=size)
   {
      r[k]=arr[j];
      j++,k++;
    }
   for(int m=low; m<=size; m++)
    {
      arr[m]=r[m];
    }
}
void MargeSort(int a[],int low,int size){
  int mid;
  if(low<size){
    mid=(low+size)/2;
    MargeSort(a,low,mid);
    MargeSort(a,mid+1,size);
    Marge(a,low,mid,size);
  }
}
int main()
{
  int arr[]={23,13,16,82,17,12};
  int size=6,low=0;
  MargeSort(arr,low,size);
  for(int i=1;i<=size;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");

return 0;
}
