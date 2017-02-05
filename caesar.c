#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>


int main(int argc, string argv[])
{
    int result;
    int i;
    if(argc!=2)
    {
        printf("please enter two arguments\n");
        return 1;
    }
    string s=GetString();
    int key=atoi(argv[1]);
    if(key>=26)
    {
        key%=26;
    }
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        result=s[i]+key;
        if(isupper(s[i])&&(result>'Z'))
        {
            result-=26;
        }
        if(islower(s[i])&&(result>'z'))
        {
            result-=26;
        }
        if(isalpha(s[i]))
        {
            printf("%c",result);
        }
        else
        {
            printf("%c",s[i]);
        }
        
        
    }
    printf("\n");
    return 0;
}