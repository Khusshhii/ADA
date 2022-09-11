#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int low,int high)
{
    _sleep(10);
    int i,j,k=a[low],t;
    i=low+1;
    j=high;
    while(low<high)
    {
        while(a[i]<=k && i<high)i++;
        while(a[j]>k)j--;
        if(i<j)
        {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        }
        else
        {
        t=a[j];
        a[j]=a[low];
        a[low]=t;
        return j;
        }
    }
}
void quicksort(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}

int main()
{
    int a[20000],i,j;
    printf("Enter array length : ");
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
         a[i]=rand()%100;
         printf("%d ",a[i]);
    }

    clock_t start=clock();
    quicksort(a,0,j-1);
    clock_t end=clock();
    printf("\nAfter sorting\n");
    for(i=0;i<j;i++)
    {
        printf("%d ",a[i]);
    }
    clock_t diff= (end-start)/CLK_TCK;
    printf("\nDiff is : ");
    printf("%d",diff);
    return 0;
}