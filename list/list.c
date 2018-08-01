#include"list.h"

typedef struct list_node{
    void* data;
    list_node* pred;
    list_node* succ;
}list_node;

typedef struct list{
    size_t length;
    int element_size;
    list_node* header;
    list_node* trailer;
}list;

struct list* list_init(const int element_size){
    list* l = malloc(sizeof(list));
    l->element_size = element_size;
    l->length = 0;
    l->header = NULL;
    l->trailer = NULL;
    return l;
}

int list_length(const list* l){
    return l->length;
}

int list_empty(const list* l){
    return l->length == 0;
}