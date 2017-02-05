#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(int argc, string argv[])
{
    unsigned char result;
    int i,j;
    if(argc!=2)
    {
        printf("enter two argument \n");
        return 1;
    }
    
    string s=argv[1];
    int k=strlen(s);
    for(i=0;i<k;i++)
    {
        if(isdigit(s[i]))
        {
            printf("you typed a no. in command line argument");
            return 1;
        }
    }
    int z[90];
    for(i=0;i<k;i++)
    {
        if(isalpha(s[i]))
        {   
            if(isupper(s[i]))
            {
                z[i]=s[i]-65;
            }
            if(islower(s[i]))
            {
                z[i]=s[i]-97;
            }
        }
    }
    string c=GetString();
    int l=strlen(c);
    for(i=0,j=0;i<l;i++)
    {
        if(j==k)
        {
            j=0;
        }
        if(isalpha(c[i]))
        {
            result=(c[i]+z[j++]);
            if(isupper(c[i]) && (result>'Z'))
            {
                result=result-26;
            }
            if(islower(c[i]) && (result>'z'))
            {
                result=result-26;
            }
            c[i]=result;    
            
        }
    }
        printf("%s\n",c);
        return 0;
}