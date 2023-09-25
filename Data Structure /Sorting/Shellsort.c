#include<stdio.h>
void ShellSort(int arr[],int n){
int temp,gap,i,j;
for(gap=n/2;gap>=1;gap/=2)

 { for(j=gap;j<n;j++)
      {  for(i=j-gap;i>=0;i-=gap)
           { if(arr[gap+i]>arr[i])
               {
                   break;
               }
               else
               temp=arr[i];
               arr[i]=arr[i+gap];
               arr[i+gap]=temp;
           }
      }
 }
}
int main()
{ int arr[]={85,26,25,84,75,42};
  int size=6;
  ShellSort(arr,size);
  for(int i=0;i<size;i++)
   {
       printf("%d ",arr[i]);
   }
printf("\n");
return 0;

}
