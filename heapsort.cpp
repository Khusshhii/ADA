#include<bits/stdc++.h>
using namespace std;

int a[100];
void heapify(int , int);

int main()
{
    int i,n;
    cout<<"Enter number of elements :";
    cin>>n;
    cout<<"Enter the elements to be sorted :";
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=n/2;i>=0;i--)
    heapify(i,n);
    for(i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(0,i);
    }
    cout<<"sorted array :";
     for(i=0;i<n;i++)
    cout<<a[i]<<"\t";   
    return 0;
}

void heapify(int i , int n)
{
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;
    if(left<n && a[largest]<a[left])
    largest=left;
    if(right<n && a[largest]<a[right])
    largest=right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(largest,n);
    }
}
