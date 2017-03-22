#include <stdlib.h>
#include "union-find.h"

union_find_elem_t * make_set(void * element){
    union_find_elem_t * singleton = (union_find_elem_t *) malloc(sizeof(union_find_elem_t));
    singleton->value = element;
    singleton->parent = NULL;
    singleton->depth = 1;
    return singleton;
}

union_find_elem_t * find(union_find_elem_t * element){
    if(!element) return NULL;
    union_find_elem_t * original_element = element;
    while(element->parent != NULL)
        element=element->parent;
    if(element != original_element->parent && element!=original_element)
        original_element->parent = element; //path compression
    return element;
}

union_find_elem_t * merge(union_find_elem_t * a, union_find_elem_t * b){
    union_find_elem_t * root_a = find(a);
    union_find_elem_t * root_b = find(b);
    union_find_elem_t * newroot = root_a;
    if(root_a!=root_b){
        if(root_a->depth > root_b->depth){ //merge by rank
            root_b->parent = root_a;
            root_a->depth++;
        }else{
            root_a->parent = root_b;
            root_b->depth++;
            newroot = root_b;
        }
    }
    return newroot;
}
