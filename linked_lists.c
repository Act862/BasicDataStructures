#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int list_is_empty(node *list){
    if(list == NULL)
        return 1;
    else
        return 0;
}

node *node_create(int data){
    node *new_node;

    new_node = (int*)malloc(sizeof(int));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

node *list_append(node *list, int data){

    node *new_node;
    node *ptr;

    new_node = node_create(data);

    if(list == NULL){
        //the list is empty
        list = new_node;
    }
    else{
        ptr = list;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return list;
}

