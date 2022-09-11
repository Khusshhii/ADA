#include<stdio.h>
#include<omp.h>
#include<conio.h>
#include<time.h>
#define MAX 5000
int p[MAX],w[MAX],n;
int knapsack(int,int);
int max(int,int);
void main()
{
clock_t s,e;
int m,i,optsoln;
printf("Enter no. of objects: ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    w[i]=(rand()%101)+1;
    printf("%d ",w[i]);
}
for(i=1;i<=n;i++)
p[i]=rand()%1001;
printf("\nEnter the knapsack capacity:");
scanf("%d",&m);
s=clock();
optsoln=knapsack(1,m);
e=clock();
printf("\nThe optimal soluntion is: %d\n",optsoln);
int d=(e-s)/CLK_TCK;
printf("Time = %d\n",d);
}
int knapsack(int i,int m)
{
_sleep(1);
if(i==n)
return (w[n]>m) ? 0 : p[n];
if(w[i]>m)
return knapsack(i+1,m);
return max(knapsack(i+1,m),knapsack(i+1,m-w[i])+p[i]);
}
int max(int a,int b)
{
if(a>b)
return a;
else
return b;
}

