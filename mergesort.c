#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int high)
{
        int b[high+1];
        int i=low;
        int j=mid+1;
        int k=low;

        while(i<=mid&&j<=high)
        {
            _sleep(1);
            if(a[i]<a[j])
            {
                b[k]=a[i];
                i++;
                k++;
            }
            else
            {
                b[k]=a[j];
                j++;
                k++;
            }
            

        }
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
        while(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }
        for(i=low;i<=high;i++)
        {
            a[i]=b[i];
        }
}


void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
       
    }

}

int main()
{
    int a[20000],i,j;
    printf("enter array lenght");
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
         a[i]=rand()%100;
         printf("%d ",a[i]);
    }

    clock_t start=clock();
    mergesort(a,0,j-1);
    clock_t end=clock();
    printf("After sorting");
    for(i=0;i<j;i++)
    {
        printf("%d ",a[i]);
    }
    int diff= (end-start)/CLK_TCK;
    printf("diff is");
    printf("%d",diff);
    return 0;



}
