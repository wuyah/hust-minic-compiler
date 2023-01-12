#pragma once

#include "string.h"
#include "stdlib.h"

/* no more used in symbol table\
    becase the stringSet is previously used to save the\
    id of the arraycall, but it is more elegant touse thr position\
    to save*/

typedef struct stringSet
{
    char *data;
    int size;
    int data_length;
    int *index;
}stringSet;

void ss_init(stringSet* ss);
void ss_push_back(stringSet* ss, const char* inputString);
char *ss_get_string(stringSet* ss, int index);
void ss_show(stringSet ss);