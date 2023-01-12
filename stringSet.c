#include "stringSet.h"
#include "stdio.h"

#define SS_DEBUG 1

void ss_init(stringSet* ss)
{
    ss->data = (char*)malloc(sizeof(char));
    ss->index = (int*)malloc(sizeof(int));
    ss->size=0;
    ss->data_length = 0;
    return;
}

// add string back the 
void ss_push_back(stringSet* ss, const char* inputString)
{
    int length = strlen(inputString);
    ss->data = (char*)realloc(ss->data, sizeof(char) * (ss->data_length+1+length));
    strcpy(ss->data+ (ss->data_length==0?0:ss->data_length+1), inputString);
    ss->data[length] = '\0';
    ss->index = (int*)realloc(ss->index, sizeof(int) * (ss->size+1));
    ss->index[ss->size] = ss->data_length+(ss->size==0?0:1);
    ss->data_length += length+1;
    ss->size++;
    return ;
}

char *ss_get_string(stringSet* ss, int index)
{
    return ss->data+ss->index[index];
}

void ss_show(stringSet ss)
{
    for(int i = 0;i<ss.size;i++)
        printf("%s |", ss_get_string(&ss, i));
    printf("\n");
}

#if(S_DEBUG)
    int main()
    {
        stringSet* ss = (stringSet*)malloc(sizeof(stringSet));
        ss_init(ss);
        ss_push_back(ss, "Helloworld!\n");
        ss_push_back(ss, "Helloworld2!\n");
        ss_push_back(ss, "Helloworld3!\n");

        printf("data in stringSet:%s", ss->data);
        printf("data in stringSet:%s", ss_get_string(ss, 1));
        printf("data in stringSet:%s", ss_get_string(ss, 2));
        printf("%d\n", ss->size);
        return 0;
    }
#endif