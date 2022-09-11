#include<bits/stdc++.h>
using namespace std;

#define MAX 50
int p[MAX] , w[MAX] , n ;
int knapsack(int , int);
int max(int , int);

int main()
{
    int i,m,x;
    cout<<"Enter number of items :";
    cin>>n;
    cout<<"Enter weights :";
    for(i=1;i<=n;i++)
    cin>>w[i];
    cout<<"Enter the profits :";
    for(i=1;i<=n;i++)
    cin>>p[i];
    cout<<"Enter knapsack capacity :";
    cin>>m;
    x=knapsack(1,m);
    cout<<"Optimal Solution = "<<x;
    return 0;
}

int knapsack(int i , int m)
{
    if(i==n)
    return (w[n]>m)?0:p[n];
    if(m<w[i])
    return knapsack(i+1,m);
    return max(knapsack(i+1,m) , knapsack(i+1,m-w[i])+p[i]);
}

int max(int a,int b)
{
if(a>b)
return a;
else
return b;
}
