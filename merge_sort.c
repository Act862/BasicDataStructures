#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *create(int data){
    node *new_node;

    new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

node *add(node *list, int new_data){
    node *new_node, *ptr;
    
    new_node = create(new_data);
    ptr = list;

    if(list == NULL){
        new_node->next = NULL;
        list = new_node;
        return list;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = NULL;
        return list;
    }
}

void print(node *list){
    node *ptr;
    ptr = list;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int length(node *list){
    node *ptr;
    ptr = list;
    int counter = 0;
    while(ptr != NULL){
        counter++;
        ptr = ptr->next;
    }
    return counter;
}

node *merge(node *first, node *second){
    
    node *new_list;
    node *temp;

    if(first == NULL)
        return second;
    if(second == NULL)
        return first;

    if(first->data <= second->data){
        temp = first;
        first = temp->next;
    }
    else{
        temp = second;
        second = temp->next;
    }
    new_list = temp;

    while(first != NULL && second != NULL){
        if(first->data <= second->data){
            temp->next = first;
            temp = first;
            first = temp->next;
        }
        else{
            temp->next = second;
            temp = second;
            second = temp->next;
        }
    }
    if(first == NULL) temp->next = second;
    if(second == NULL) temp->next = first;

    return new_list;
}

node *find_middle(node *list){
    node *middle;
    node *middle_next;

    middle = middle_next = list;
    if((list == NULL) || (list->next == NULL)){
        return list;
    }

    while(middle_next->next != NULL){
        if(middle_next->next->next == NULL){
            middle_next = middle_next->next;
            break;
        }
        middle = middle->next;
        middle_next = middle_next->next->next;
    }
    return middle;
}

node *merge_sort(node *list){
    if(list == NULL || list->next == NULL){
        return list;
    }
    node *middle = find_middle(list);
    node *middle_next = middle->next;
    middle->next = NULL;

    node *first = merge_sort(list);
    node *second = merge_sort(middle_next);

    node *res = merge(first,second);

    return res;
}


int main(){
    srand(time(NULL));
    int i;
    node *list = NULL;
    node *new_list = NULL;
    node *l2 = NULL;

    for(i = 0; i < 10; i++){
        l2 = add(l2, i*rand()%10);
    }
    print(l2);
    new_list = merge_sort(l2);
    print(l2);

    return 0;    
}