#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

//1.- Create
List * createList() 
{
  List* lista = (List *) malloc (sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
  return lista;
}

//2.- First y Next
void * firstList(List * list)
{
  list->current = list->head;
  if(list->current) {
    return list->current->data;
  }
  return NULL;
}

void * nextList(List * list) 
{
  if(list->current && list->current->next) {
    list->current = list->current->next;
    return list->current->data;
  }
  return NULL;
}

//3.- Last y Prev
void * lastList(List * list) 
{
  if(list->tail) {
    list->current = list->tail;
    return list->current->data;
  }
  return NULL;
}

void * prevList(List * list) 
{
  if(list->current && list->current->prev) {
    list->current = list->current->prev;
    return list->current->data;
  }
  return NULL;
}

//4.- PushFront
void pushFront(List * list, void * data) 
{
  Node* aux = createNode(data);
  if(list->head) {
    list->head->prev = aux;
    aux->next = list->head;
  } else {
    list->tail = aux;
  }
  list->head = aux;
}

//5.- PushCurrent
void pushCurrent(List * list, void * data) 
{
  Node* aux = createNode(data);
  if(list->current) {
    aux->prev = list->current;
    aux->next = list->current->next;
    list->current->next = aux;
    list->current = aux;
  }
  if(list->current->prev == list->tail) {
    list->tail = list->current;
  }
}

//6.- PopCurrent
void * popCurrent(List * list) 
{
  void* popt = list->current->data;
  if(list->head == list->current) {
    list->current = list->current->next;
    list->current->prev = NULL;
    list->head = list->current;  
  } else if(list-> tail == list->current) {
    list->current = list->current->prev;
    list->current->next = NULL;
    list->tail = list->current;    
  } else /*if(list->current->prev && list->current->next)*/ {
    list->current = list->current->prev;
    list->current->next = list->current->next->next;
    list->current->next->prev = list->current;
  }
  return popt;
}
