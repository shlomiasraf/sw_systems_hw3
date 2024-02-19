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

Node* Node_alloc(const char* data, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) 
    {
        newNode->_data = strdup(data);

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
	free(node);
}
StrList* StrList_alloc() 
{
	StrList* p= (StrList*)malloc(sizeof(StrList));

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
size_t StrList_size(const StrList* StrList)
{
    return StrList->_size;
}
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
char* StrList_firstData(const StrList* StrList)
{
    	return StrList->_head-> _data;
}
void StrList_print(const StrList* StrList)
{
    Node* current = StrList->_head;

    while (current != NULL) {
        printf("%s ", current->_data);
        current = current->_next;
    }

    printf("\n");
}
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
    printf("%s\n", p->_data); 
}
int StrList_printLen(const StrList* list) 
{
    int totalLength = 0;
    Node* p = list->_head;
    while (p != NULL) 
    {
        totalLength += strlen(p->_data);
        p = p->_next;
    }

    return totalLength;
}

int StrList_count(StrList* StrList, const char* data)
{
    int count = 0;
    Node* p = StrList->_head;

    while (p != NULL) {
        if (strcmp(p->_data, data) == 0) 
        {
            count++;
        }
        p = p->_next;
    }
    return count;
}
void StrList_remove(StrList* StrList, const char* data)
{
    Node* current = StrList->_head;
    Node* previous = NULL;
    while (current != NULL) 
    {
        if (strcmp(current->_data, data) == 0) 
        {
            Node* temp = current;
            if (previous != NULL)
            {
                previous->_next = current->_next;
            } 
            else 
            {
                StrList->_head = current->_next;
            }
            current = current->_next;
            free(temp);
            --(StrList->_size);
        } 
        else 
        {            
            previous = current;
            current = current->_next;
        }
    }
}
void StrList_removeAt(StrList* StrList, int index)
{
    if (index < 0 || index > StrList->_size) 
    {
        return;
    }
    Node* current = StrList->_head;
    Node* previous = NULL;
    if (index == 0) 
    {
        StrList->_head = current->_next;
    } 
    else 
    {
        Node* p = StrList->_head;
        for (int i = 0; i < index; i++) 
        {
            previous = current;
            current = current->_next;
        }
        previous->_next = current->_next;
    }
    free(current);
    --(StrList->_size);
}
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    const int eq= 0;
	const int neq= 1;
	
	const Node* p1= StrList1->_head;
	const Node* p2= StrList2->_head;
	while(p1) {
		if (p2==NULL||p1->_data!=p2->_data) return neq;
		p1= p1->_next;
		p2= p2->_next;
	}
	if (p2!=NULL) return neq;
	return eq;
}
StrList* StrList_clone(const StrList* Strlist)
{
    StrList* ret= StrList_alloc();
	const Node* old= Strlist->_head;
	Node* * copy= &(ret->_head);
	ret->_size= Strlist->_size;
	while(old) {
		*copy= Node_alloc(old->_data,NULL);
		old= old->_next;
		copy= &((*copy)->_next);
	}
	return ret;
}
void StrList_reverse( StrList* StrList)
{
    Node* current = StrList->_head;
    Node* previous = NULL;
    Node* next = NULL;
    while (current != NULL) 
    {
        next = current->_next;
        current->_next = previous;
        previous = current;
        current = next;
    }
    StrList->_head = previous;
}
void swap(Node* a, Node* b) {
    char* temp = (char*)a->_data;
    a->_data = b->_data;
    b->_data = temp;
}
void StrList_sort(StrList* StrList) 
{
    int swapped;
    Node* current;
    Node* last = NULL;

    if (StrList->_head == NULL) 
    {
        return;
    }
    for (int i = 0; i < StrList->_size - 1; ++i) 
    {
        swapped = 0;
        current = StrList->_head;
        while (current->_next != last) 
        {
            if (strcmp(current->_data, current->_next->_data) > 0) 
            {
                swap(current, current->_next);
                swapped = 1;
            }
            current = current->_next;
        }
        if (swapped == 0) 
        {
            break;
        }
        last = current;
    }
}
int StrList_isSorted(StrList* StrList)
{
    Node* current = StrList->_head;
    while (current != NULL && current->_next != NULL)
    {
        if (strcmp(current->_data, current->_next->_data) > 0) 
        {
            return 0;
        }
        current = current->_next;
    }
    return 1;        
}

