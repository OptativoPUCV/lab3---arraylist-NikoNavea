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
  if (list == NULL) exit(EXIT_FAILURE);
  list->capacity = 2;
  list->size = 0;
  list->data = malloc(sizeof(void*));
  return list;
}

void append(ArrayList * l, void * data){
  for (int k = 0 ; k < l->capacity ; k++){
    if (l->size == l->capacity){
      l->data = realloc(l->data, l->capacity*2*sizeof(void**));
      l->capacity = l->capacity*2;
    }
    l->data[l->size] = data;
    l->size++;
  }
}

void push(ArrayList * l, void * data, int i){
  if(i > l->size) return;
  
  if(l->size == l->capacity){
    l->data = realloc(l->data, l->capacity*2*sizeof(void**));
    l->capacity = l->capacity*2;
  }
  
  for (int k = l->size-1 ; k >= i ; k++){
    l->data[k+1] = l->data[k];
  }
  
  l->data[i] = data;
  l->size++;
}

void* pop(ArrayList * l, int i){
  if(i < 0){
    i += l->size;
  }
  void* dato = l->data[i];
  for(int k = i+1 ; k < l->size ; k++){
    
    l->data[k] = l->data[k-1];
  }
  l->size--;
  return dato;
}

void* get(ArrayList * l, int i){
  if(i >= l->size) return NULL;
  if(i < 0){
    i += l->size;
  }
  void* dato = l->data[i];
  return dato;
}

int get_size(ArrayList * l){
  if(l == NULL) exit(EXIT_FAILURE);
  int cont = 0;
  for(int k = 0 ; k < l->size ; k++){
    if(l->data[k] != NULL){
      cont++;
    }
  }
  l->size = cont;
  return l->size;
}

//remove elements
void clean(ArrayList * l){
  for (int i = 0; i < l->size; i++) {
    free(l->data[i]);
  }
  
  l->capacity = 2;
  l->size = 0;
  l->data = realloc(l->data, l->capacity*sizeof(void**));
  
  if(l->data != NULL){
    l->data[0] = NULL;
    l->data[1] = NULL;
  }
  
}
