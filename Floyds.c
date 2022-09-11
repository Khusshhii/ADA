#include<stdio.h>
#include<omp.h>
#include<conio.h>
#include<time.h>
void floyd(int[100][100],int);
int min(int,int);
int main()
{
clock_t s,e;
int n,a[100][100],i,j;
printf("Enter the no.of nodes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
    if(i==j)
        a[i][j]=0;
    else
        a[i][j]=rand()%21;
}
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
        printf("%d ",a[i][j]);
    printf("\n");
}
s=clock();
floyd(a,n);
e=clock();
int d=(e-s)/CLK_TCK;
printf("\nTime = %d",d);
}
void floyd(int a[100][100],int n)
{
int d[100][100],i,j,k;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
d[i][j]=a[i][j];
}
for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
_sleep(1);
d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
}
}
printf("\nThe distance matrix is\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d\t",d[i][j]);
}
printf("\n");
}
}
int min (int a,int b)
{
if(a<b)
return a;
else
return b;
}


