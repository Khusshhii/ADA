#include<iostream>
#include<string.h>
#include<time.h>
using namespace std;
int st[27];
int horspool(char MS[],char SS[],int n,int m)
{
int i=m-1,k;
while(i<=n-1)
{
    _sleep(1);
   k=0;
   while(k<=m-1 && MS[i-k]==SS[m-1-k])
   k++;
   if(k==m)
   return 1;
   else
   {
      int z=MS[i]-'a';
      i=i+st[z];
   }
}
   return 0;
}
int main()
{
    clock_t s,e,d;
   char MS[1000],SS[100];
   int n,m,result;
   cout<<"Enter length of main string\n";
   cin>>n;
   for(int i=0;i<n;i++)
   {
       int r=(rand()%26)+97;
       MS[i]=r;
   }
   for(int i=0;i<n;i++)
    cout<<MS[i];
   cout<<endl;
   cout<<"Enter sub string";
   cin>>SS;
   m=strlen(SS);
   for(int i=0;i<27;i++)
    st[i]=m;
   int index;
for(int i=0;i<m-1;i++)
{
index=SS[i]-'a';
st[index]=m-1-i;
}
    s=clock();
   result=horspool(MS,SS,n,m);
   e=clock();
   if(result==1)
   cout<<"Pattern Matched\n";
   else
   cout<<"Patter Not Present";
    d=(e-s)/1000;
   cout<<"Time = "<<d ;
}

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int table[126],n,m;
void shiftTable(string p)
{
int i,j;
m=p.length();
for(i=0;i<126;i++)
table[i]=m;
for(j=0;j<=m-2;j++)
table[p[j]]=m-1-j;
}
int horspool(string s, string p)
{
int i,j,k;
int n = s.length();
int m = p.length();
shiftTable(p);
i = m-1;
while(i<=n-1)
{
    _sleep(1);
    k =0 ;
    while(k<=m && p[m-1-k]==s[i-k])
        k++;
    if(k==m)
        return i-m+1;
    else
        i=i+table[s[i]];
}
return -1;
}
string RandomString(int ch)
{
    char alpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z',' '};
    string result = "";
    for (int i = 0; i<ch; i++)
        result = result + alpha[rand() % 27];

    return result;
}
int main()
{
    clock_t s,e,l;
    int n;
    cout<<"Enter the length of the string: ";
    cin>>n;

    char ss[500];
    string str;
    str=RandomString(n);
    cout<<str<<endl;
    cin>>ss;
    s=clock();
    int ret=horspool(str,ss);
    e=clock();
    l=e-s;
    if(ret==-1)
        cout<<"Pattern not found"<<endl;
    else
        cout<<"Pattern found at position "<<ret<<endl;
    cout<<"\nTime: "<<(double)l/CLK_TCK<<"s";
    return 0;

}