#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main()
{
    char filename[100];
    memset(filename,'\0',sizeof(filename));
    printf("Give the file name: ");
    gets(filename);
    printf("%s\n",filename);
    freopen(filename,"r",stdin);
    char str[10000];
    memset(str,'\0',sizeof(str));
    int w=0,l=0,c=0,i;
    while(gets(str))
    {
        printf("%s\n",str);
        l++;
        int len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]==' ')
            {
                c++;
                w++;
            }
            else
            {
                c++;
            }
        }
    }
    printf("%d %d %d\n",l,w,c);
    return 0;
}
