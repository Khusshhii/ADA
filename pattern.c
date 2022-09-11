#include<stdio.h>
#include<time.h>
#include<string.h>
int pattern(char s[],char c[],int l,int m)
{
    int i,j;
    for(i=0;i<=l-m;i++)
    {
        _sleep(1);
        j=0;
        while(j<m && c[j]==s[i+j])
            j++;
        if(j==m)
        return 1;
    }
}
int main()
{
    int                                                                                                                                                                                                                                                                                                                        b,check=0,l,r;
    clock_t start,end,diff;
    char s1[100000],s2[100];
    while(1)
    {
    printf("Enter length of Main string\n");
    scanf("%d",&l);
    if(l==0)
        return 0;
    for(int i=0;i<l;i++)
    {
        r=(rand()%26)+97;
        s1[i]=r;
    }
    printf("%s\n",s1);
    printf("Enter pattern to be found : ");
    scanf("%s",s2);
    b=strlen(s2);
    start=clock();
    check=pattern(s1,s2,l,b);
    end=clock();
    if(check==1)
        printf("Found\n");
    else
        printf("Not Found\n");
    diff=end-start;
    printf("Difference is %d\n",diff/CLK_TCK);
    }

}
