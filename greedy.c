#include<stdio.h>
#include<cs50.h>

int main(void)
{    
    int totalchange=0,n;
    double i;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int pennies = 1;
    printf("O hai!");
    do
    {
        printf("How much change is owed?\n");
        i=GetDouble();
        n=(i*100);
    }while(n<1);
    
    //int ADollar=n/dollar;
    int AQuarter = n/quarter;
    int ADime = ((n% quarter) / dime);
    int ANickel = (((n%quarter) % dime) / nickel);
    int APennies = ((((n% quarter) % dime) % nickel) / pennies);
    totalchange+=AQuarter+ADime+ANickel+APennies;
    printf("%d\n",totalchange);
    
    
}