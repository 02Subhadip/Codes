#include<stdio.h>
#include<stdlib.h>

int Max(int *arr,int n){//Function body for find maxmimum element
    int i=0;
    int Max=arr[i];
    for(i=i+1;i<n;i++){
        if(Max<arr[i])
         {Max=arr[i];}
    }
 return Max;
}//End of the Max function.

void countshort(int *arr,int n){//Function body for count short.
    int i;
    int max=Max(arr,n);
    int *count=(int*) malloc((max+1)*sizeof(int));
    for(i=0;i<=max;i++)
     {
         count[i]=0;
     }
    for(i=0;i<n;i++)
     {
         count[arr[i]]=count[arr[i]]+1;//For incriment the current value compare with array.
     }
int m=n=0;
    while(m<=max){
        if(count[m]>0){
            arr[n]=m;
            count[m]--;
            n++;
        }
       else
       {m++;}
    }
   
}//End of the count short function.

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    { printf("Enter the %d array element: \n",i+1);
      scanf("%d",&arr[i]);}

    countshort(arr,n);//Function call for countshort.
     for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
  
return 0;
}
