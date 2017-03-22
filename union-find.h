#ifndef UNION-FIND_H_INCLUDED
#define UNION-FIND_H_INCLUDED

typedef struct union_find_elem {
    struct union_find_elem * parent;
    void * value;
    int depth;
} union_find_elem_t;

union_find_elem_t * make_set(void * element);
union_find_elem_t * find(union_find_elem_t * element);
union_find_elem_t * merge(union_find_elem_t * a, union_find_elem_t * b);

#endif // UNION-FIND_H_INCLUDED
