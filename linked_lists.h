
typedef struct node{
    int data;
    struct node *next;
}node_t;

typedef struct llist_t{
    node_t *head;
    node_t *tail;
    int length;
}llist_t;

node_t *create_node(){
    node_t new_node;
    new_node = (node_t*)malloc(sizeof(node_t));

    return new_node;    //we return an empty but existent node
}

node_t *fill_node_data(node_t *node, int data){
    node->data = data;
    node->next = NULL;

    return node;
}

llist_t *create_list(){
    llist_t *alist;

    alist = (llist_t*)malloc(sizeof(llist_t));
    alist->head = NULL;
    alist->tail = NULL;
    alist->length = 0;
    
    return alist;
}

llist_t *append_node(llist_t *alist, node_t *node){
    
}