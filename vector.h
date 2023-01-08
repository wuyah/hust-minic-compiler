#pragma once

#include<stdlib.h>

typedef struct vector
{
    int *data;
    int size;
    int capacity;
}vector;

void vector_init(vector* v, int capacity);
void vector_destory(vector* v);
void vector_push_back(vector* v, int value);
void vector_pop_back(vector* v);
