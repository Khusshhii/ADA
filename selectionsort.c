#include<stdio.h>
#include<time.h>
void selectionsort(int a[],int n)
{
    int i,j,min,t;
    for(i=0;i<n-1;i++)
    {
        _sleep(1);
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            min=j;
        }
        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
}
int main()
{
    int i,a[100000],n;
    clock_t start,end,diff,t;
    while(1)
    {
    printf("\nEnter number of elements\n");
    scanf("%d",&n);
    if(n==0) return 0;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
        printf("%d ",a[i]);
    }
    start=clock();
    selectionsort(a,n);
    end=clock();
    printf("\nAfter sorting\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    diff=(end-start)/CLK_TCK;
    printf("\nDifference is : %d",diff);
    }

}
