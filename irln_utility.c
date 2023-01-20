#include"def.h"

void ir_ln_init(ir_listnode* p, codenode* ir)
{
    p = (ir_listnode*)malloc(sizeof(ir_listnode));
    p->next = NULL;
    p->ir = ir;
}

void ir_ln_push(ir_listnode** p, codenode* ir)
{
    if(!(*p))
    {
        *p = (ir_listnode*)malloc(sizeof(ir_listnode));
        (*p)->ir = ir;
        (*p)->next = NULL;
    }else
    {
        ir_listnode* temp = (ir_listnode*)malloc(sizeof(ir_listnode));
        temp->ir = ir;
        temp->next = *p;
        *p = temp;
    }
}

codenode* ir_ln_pop(ir_listnode** p)
{
    codenode* rtn = (*p)->ir;
    (*p) = (*p)->next;
    return rtn;
}
codenode* ir_ln_top(ir_listnode *p)
{
    codenode* rtn = p->ir;
    return rtn;
}