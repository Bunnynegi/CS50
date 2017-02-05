#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    
    string s=GetString();
    int j=0;
    j=strlen(s);
    for(int i=0;i<j;i++)
    {
        if(i==0)
        {
        printf("%c",toupper(s[i]));
            
        }
        else if(s[i]==' ')
        {  
        printf("%c",toupper(s[i+1]));
        }
    }
    printf("\n");
}