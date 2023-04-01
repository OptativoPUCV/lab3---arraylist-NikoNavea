#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *list = (ArrayList *) malloc (sizeof(ArrayList));
  if (ArrayList == NULL) return;
  list->capacity = 2;
  list->size = 0;
  list->data = malloc(sizeof(void*));
  return list;
}

void append(ArrayList * l, void * data){
  for (int k = 0 ; k < l->capacity ; k++){
    l->data[size] = data;
    l->size++;
    if (l->size == l->capacity){
      l->data = realloc(l->data, capacity*2);
    }
  }
}

void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
