# union-find-c
C implementation of the union-find data structure (with sets as trees).
This implementation features path compression and union by rank, thus the amortized time per operation is O(alpha(n)).

## Functions
```C
union_find_elem_t * make_set(void * element);
union_find_elem_t * find(union_find_elem_t * element);
union_find_elem_t * merge(union_find_elem_t * a, union_find_elem_t * b);
```
