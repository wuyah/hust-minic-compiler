#include "vector.h"

void vector_init(vector* v, int capacity)
{
    v->data = (int *)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_destory(vector* v)
{
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

void vector_push_back(vector* v, int value)
{
    if (v->size == v->capacity)
    {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_pop_back(vector* v)
{
    if (v->size > 0)
    {
        v->size--;
    }
}