#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"
#define SIZE 99999
int hash (const char* word);
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}node;
node* hashtable[SIZE];
int dictionarySize = 0;
bool load(const char* dictionary)
{
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;
    char word[LENGTH+1];
    while (fscanf(file, "%s\n", word)!= EOF)
    {   node* newWord = malloc(sizeof(node));
        strcpy(newWord->word, word);
        newWord->next = NULL;
        int i = hash(word);
        if (hashtable[i] == NULL)
        {
            hashtable[i] = newWord;
            
        }
        else
        {
            newWord->next = hashtable[i];
            hashtable[i] = newWord;
        }
        dictionarySize++;
    }
    fclose(file);
    return true;
}
bool check(const char* word)
{   char temp[LENGTH + 1];
    int len = strlen(word);
    for(int i = 0; i < len; i++)
        temp[i] = tolower(word[i]);
    temp[len] = '\0';
    int index = hash(temp);
    if (hashtable[index] == NULL)
    {
        return false;
    }
    node* cursor = hashtable[index];
    while (cursor != NULL)
    {
        if (strcmp(temp, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    
 
    return false;
}
unsigned int size(void)
{    if (dictionarySize > 0)
        return dictionarySize;
     else
        return 0;
}
bool unload(void)
{   int i = 0;
    while (i< SIZE)
    {
        if (hashtable[i] != NULL)
        {
            node* cursor = hashtable[i];
            while(cursor!=NULL)
            {
                node* temp = cursor;
                cursor=cursor->next;
                free(temp);
                
            }
            hashtable[i]=NULL;
        
        }
        i++;
    }
    return true;
}
int hash (const char* word)
{
   int n=word[0]-97;
   if(word[1]!='\0'&&word[1]!='\'')
   n=n*26+(word[1]-97);
   
    return n;
}