/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"
bool searchlist(int value, int values[], int n);
void sortlist(int values[],int n);
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(value<0)
    {
        return false;
    }
    else
    {
        return searchlist(value,values,n);   
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
   sortlist(values,n);
   return;
}

bool searchlist(int value, int values[], int n)
{  
  int first=0;
    int last=n-1;
    while(first<=last)
    {
        int m=(first+last)/2;
        if(values[m]==value)
        return true;
        else if(values[m]>value)
        last=m-1;
        else if(values[m]<value)
        first=m+1;
    }
    return false;
}
void sortlist(int values[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(values[i]>values[j])
            {
                int temp=values[i];
                values[i]=values[j];
                values[j]=temp;
            }
        }
    }
}

