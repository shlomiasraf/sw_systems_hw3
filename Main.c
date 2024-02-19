#include <stdio.h>
#include "StrList.h"

int main() 
{
    StrList* Strlist= StrList_alloc();
    int inputNum;
    scanf( "%d", &inputNum);
    while (inputNum != 0)
    {
        if(inputNum == 1)
        {
            int sizeNum;
            scanf( "%d", &sizeNum);
            for(int i = 0; i < sizeNum; i++)
            {
                char *word;
                word = (char *)malloc(50 * sizeof(char));  
                scanf("%s", word);
                StrList_insertLast(Strlist ,word);
                free(word);
            }
        }
        if(inputNum == 2)
        {
            int index;
            scanf( "%d", &index);
            char *word;
            word = (char *)malloc(50 * sizeof(char));  
            scanf("%s", word);
            StrList_insertAt(Strlist ,word,index);
            free(word);

        }
        if(inputNum == 3)
        {
            StrList_print(Strlist);
        }
        if(inputNum == 4)
        {
            int size = StrList_size(Strlist);
            printf( "%d", size);
        }
        if(inputNum == 5)
        {
            int index;
            scanf( "%d", &index);
            StrList_printAt(Strlist,index);
        }
        if(inputNum == 6)
        {
            int len = StrList_printLen(Strlist);
            printf( "%d", len);
        }
        if(inputNum == 7)
        {
            char *word;
            word = (char *)malloc(50 * sizeof(char));  
            scanf("%s", word);
            int count = StrList_count(Strlist,word);
            printf( "%d", count);
            free(word);
        }
        if(inputNum == 8)
        {
            char *word;
            word = (char *)malloc(50 * sizeof(char));  
            scanf("%s", word);
            StrList_remove(Strlist, word);
            free(word);
        }
        if(inputNum == 9)
        {
            int index;
            scanf( "%d", &index);
            StrList_removeAt(Strlist, index);
        }
        if(inputNum == 10)
        {
            StrList_reverse(Strlist);
        }
        if(inputNum == 11)
        {
            while (StrList_size(Strlist) > 0)
            {
                StrList_removeAt(Strlist,(StrList_size(Strlist)-1));
            }
        }
        if(inputNum == 12)
        {
            StrList_sort(Strlist);
        }
        if(inputNum == 13)
        {
            int a = StrList_isSorted(Strlist);
            if(a == 1)
            {
                printf("%s\n", "true");
            }
            else
            {
                printf("%s\n", "false");
            }
        }
        scanf( "%d", &inputNum);
    }
    StrList_free(Strlist);
    return 0;
}
