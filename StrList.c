#include "StrList.h"
#include <stdio.h>
#include <string.h>
// Node & List Data Structures
typedef struct _node
{
    char  *_data;
    struct _node * _next;
} Node;

typedef struct _StrList 
{
    Node* _head;
    size_t _size;
} StrList;

// Node implementation
//allocate memory for the node.

Node* Node_alloc(const char* data, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) 
    {
        if(data != NULL)
        {
            newNode->_data = strdup(data);
        }
        if (newNode->_data == NULL) 
        {
            free(newNode);
            return NULL;
        }
        newNode->_next = next;
    }
    return newNode;
}


void Node_free(Node* node) 
{
    if (node == NULL) 
    {
        return;
    }
	free(node);
}

// StrList implementation
//allocate memory for the list.

StrList* StrList_alloc() 
{
	StrList* p= (StrList*)malloc(sizeof(StrList));
    if(p==NULL)
    {
       return NULL;
    }
	p->_head= NULL;
	p->_size= 0;
	return p;
}
void StrList_free(StrList* StrList)
{
    if (StrList==NULL) return;
	Node* p1= StrList->_head;
	Node* p2;
	while(p1) 
    {
		p2= p1;
		p1= p1->_next;
		Node_free(p2);
	}
	free(StrList);
}
//gets the size of the list.
size_t StrList_size(const StrList* StrList)
{
    return StrList->_size;
}
//insert string to the last index.
void StrList_insertLast(StrList* StrList, const char* data)
{
    Node* newNode = Node_alloc(data, NULL);
    if (StrList->_head == NULL) 
    {
        StrList->_head = newNode;
    } 
    else 
    {
        Node* p = StrList->_head;
        while (p->_next != NULL) 
        {
            p = p->_next;
        }
        p->_next = newNode;
    }
    ++(StrList->_size);
}
//insert string in the index we got.
void StrList_insertAt(StrList* StrList, const char* data,int index)
{
    if (index < 0 || index > StrList->_size) 
    {
        return;
    }
    Node* newNode = Node_alloc(data, NULL);
    if (index == 0) 
    {
        newNode->_next = StrList->_head;
        StrList->_head = newNode;
    } 
    else 
    {
        Node* p = StrList->_head;
        for (int i = 0; i < index - 1; i++) 
        {
            p = p->_next;
        }
        newNode->_next = p->_next;
        p->_next = newNode;
    }
    ++(StrList->_size);
}
//return the data of the first index.
char* StrList_firstData(const StrList* StrList)
{
    	return StrList->_head-> _data;
}
//prints all the strlist.
void StrList_print(const StrList* StrList)
{
    Node* p = StrList->_head;

    while (p != NULL) 
    {
        if (p->_next == NULL)
        {
            printf("%s", p->_data);
        }
        else
        {
            printf("%s ", p->_data);
        }
        p = p->_next;
    }
    printf("\n");
}
//prints the data in the index we got on the list.
void StrList_printAt(const StrList* Strlist,int index)
{
    Node* p= Strlist->_head;
    if(index < Strlist-> _size)
    {
        for(int i = 0; i < index; i++)
        {
            p= p->_next;
        }
    }
    printf("%s", p->_data); 
}
//prints all the characters in the list
int StrList_printLen(const StrList* list) 
{
    int totalLength = 0;
    Node* p = list->_head;
    while (p != NULL) 
    {
        if (p->_data != NULL)
        {
            totalLength += strlen(p->_data);
        }
        p = p->_next;
    }

    return totalLength;
}
//return how many times the string in the Strlist.
int StrList_count(StrList* StrList, const char* data)
{
    int count = 0;
    Node* p = StrList->_head;

    while (p != NULL) {
        if (p->_data != NULL && data != NULL && strcmp(p->_data, data) == 0) 
        {
            count++;
        }
        p = p->_next;
    }
    return count;
}
//remove this string from StrList.
void StrList_remove(StrList* StrList, const char* data)
{
    Node* p = StrList->_head;
    Node* previous = NULL;
    while (p != NULL) 
    {
        if (strcmp(p->_data, data) == 0) 
        {
            Node* temp = p;
            if (previous != NULL)
            {
                previous->_next = p->_next;
            } 
            else 
            {
                StrList->_head = p->_next;
            }
            p = p->_next;
            free(temp);
            --(StrList->_size);
        } 
        else 
        {            
            previous = p;
            p = p->_next;
        }
    }
}
//remove the string of the index we got from StrList.
void StrList_removeAt(StrList* StrList, int index)
{
    if (index < 0 || index > StrList->_size) 
    {
        return;
    }
    Node* p = StrList->_head;
    Node* previous = NULL;
    if (index == 0) 
    {
        StrList->_head = p->_next;
    } 
    else 
    {
        for (int i = 0; i < index; i++) 
        {
            previous = p;
            p = p->_next;
        }
        previous->_next = p->_next;
    }
    free(p);
    --(StrList->_size);
}
//checks if the lists are equals.
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
        if(!StrList1 && !StrList2) 
	{
            return 1;
        }
         if ((StrList1 && !StrList2) || (!StrList1 && StrList2) || (StrList1->_size != StrList2->_size)) 
	{
            return 0;
        }
            Node *p1 = StrList1->_head;
            Node *p2 = StrList2->_head;
            while (p1 && p2) 
	    {
                if (strcmp(p1->_data, p2->_data) != 0)) 
		{
                    return 0;
                }
                p1 = p1->_next;
                p2 = p2->_next;
            }
            return 1;
        }

//clone the list to another list.
StrList* StrList_clone(const StrList* Strlist)
{
    if(!Strlist || !Strlist->_head)
    {
        return NULL;
    }
    StrList* copy = StrList_alloc();
    Node* old = Strlist->_head;
   while(old)
   {
        if(old->_data != NULL)
        {
            char* clone_data = strdup(old->_data);
            StrList_insertLast((struct _StrList *) copy, clone_data);
        }
        old = old->_next;
   }
   return (struct _StrList *) copy;
}
//reverse the strlist from end to start.
void StrList_reverse( StrList* StrList)
{
    Node* p = StrList->_head;
    Node* previous = NULL;
    Node* next = NULL;
    while (p != NULL) 
    {
        next = p->_next;
        p->_next = previous;
        previous = p;
        p = next;
    }
    StrList->_head = previous;
}
//swap between two nodes.
void swap(Node* a, Node* b) {
    char* temp = (char*)a->_data;
    a->_data = b->_data;
    b->_data = temp;
}
//Sort the given list in lexicographical order. 
void StrList_sort(StrList* StrList) 
{
    int swapped;
    Node* p;
    Node* last = NULL;

    if (StrList->_head == NULL) 
    {
        return;
    }
    for (int i = 0; i < StrList->_size - 1; ++i) 
    {
        swapped = 0;
        p = StrList->_head;
        while (p->_next != last) 
        {
            if (strcmp(p->_data, p->_next->_data) > 0) 
            {
                swap(p, p->_next);
                swapped = 1;
            }
            p = p->_next;
        }
        if (swapped == 0) 
        {
            break;
        }
        last = p;
    }
}
//checks if the given list in lexicographical order.
int StrList_isSorted(StrList* StrList)
{
    Node* p = StrList->_head;
    while (p != NULL && p->_next != NULL)
    {
        if (strcmp(p->_data, p->_next->_data) > 0) 
        {
            return 0;
        }
        p = p->_next;
    }
    return 1;        
}

