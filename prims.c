#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define size 10
int st[size-1],stp=-1,min[2],n,top=-1;
void find_min(int arr[size][size])
{
    int i,j,m,k=0;
    min[0]=0;min[1]=1;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(k==0 && arr[i][j]!=0)
            {
                m=arr[i][j];
                k++;
                min[0]=i;min[1]=j;
                continue;
            }
            if(arr[i][j]<m && arr[i][j]!=0)
            {
            m=arr[i][j];
            min[0]=i;min[1]=j;
            }
        }
    st[++stp]=m;
    printf("%d->",st[stp]);
    //printf("%d %d\n",min[0],min[1]);
}
int find(int a,int b[])
{
    int i;
    for(i=0;i<top+1;i++)
        if(a==b[i])
        return 1;
    return 0;
}
void find_min_spec(int a[size][size],int b[15])
{
    int i,j,k=0,m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            _sleep(1);
            if(find(i,b))
            {
                if(find(j,b))
                    continue;
                if(k==0 && a[i][j]!=0)
                {
                    m=a[i][j];
                    k++;
                    min[0]=i;min[1]=j;
                    continue;
                }
                if(a[i][j]<m && a[i][j]!=0)
                {
                    m=a[i][j];
                    min[0]=i;
                    min[1]=j;
                }
            }
        }
    }
    st[++stp]=m;
    printf("%d->",st[stp]);
    //printf("%d %d\n",min[0],min[1]);
}
int main()
{
    clock_t s,e,d;
    int i,j,k[2000],x;
    int a[size][size];
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                a[i][j]=0;
            else
            {
                x=rand()%11;
                a[i][j]=a[j][i]=x;
            }
        }
    }
    j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    s=clock();
    find_min(a);
    k[++top]=min[0];k[++top]=min[1];
    for(i=0;i<n-2;i++)
    {
        find_min_spec(a,k);
        k[++top]=min[0];k[++top]=min[1];
    }
    e=clock();
    int sum=0;
    for(i=0;i<n-1;i++)
        sum+=st[i];
    /*for(i=0;i<10;i++)
    {
        printf("%d,",k[i]);
    }*/
    printf("NULL\nMST weight = %d \n",sum);
    d=e-s;
    printf("Diff is : %d\n",d/CLK_TCK);
}
