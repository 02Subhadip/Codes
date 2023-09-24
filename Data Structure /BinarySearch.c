#include<stdio.h>
int BinarySearch(int arr[],int low,int size,int item){
 int l=low,h=size,mid;
 while(l!=h)
 { mid=(l+h)/2;
   if(item==arr[mid])
   { return mid+1; }
   if(item>arr[mid])
   { l=mid+1; }
   else
   {h=mid-1;}
 }
 return -1; }
int main()
{ int arr[]={23,13,16,11,17,12},size=6; 
  int item=12,low=0;
  int result=BinarySearch(arr,low,size,item);
  if(result==-1)
    printf("Result not found in array\n");
  else
printf("The item found in %d location in array\n",result);
  return 0; }
