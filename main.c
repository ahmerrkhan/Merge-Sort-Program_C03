#include <stdio.h>
#include <stdlib.h>

int main()
{
   int arr[100],n,i;

   printf("Enter Number of Terms :\n");
   scanf("%d",&n);

   printf("Enter %d Terms :\n",n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }

   //Logics
   MergeSort(arr,0,n-1);


   //After sorting
   printf("After Sorting new Array is :\n");
   for(i=0;i<n;i++)
   {
       printf("%d\t",arr[i]);
   }
}
void MergeSort(int arr[], int lb, int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        MergeSort(arr,lb,mid);
        MergeSort(arr,mid+1,ub);
        Merge(arr,lb,mid,ub);
    }
}
void Merge(int arr[],int lb, int mid, int ub)
{
    int brr[100],k,i,j;

    i=lb;
    j=mid+1;
    k=lb;

    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
         brr[k]=arr[i];
         i++;
        }
        else
        {
            brr[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            brr[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            brr[k]=arr[i];
            i++;
            k++;
        }
    }

    for(k=lb;k<=ub;k++)   //copying array elements
    {
        arr[k]=brr[k];
    }
}
