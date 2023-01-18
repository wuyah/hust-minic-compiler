#include "def.h"

void arrayExp(ASTNode *T)
{
    int rtn, num, width;
    struct ASTNode *T0;
    struct opn opn1, opn2, result;
    int op;
    vector * v = (vector*)malloc(sizeof(vector)); vector_init(v, 1);
    T0 = T;
    T->width = 0;
    
    // use a temp var to save the offset
    int offset_place = fill_Temp(newTemp(), LEV, INT, 'T', T->offset+T->width);
    // never plus offset
    T->width += 4;
    int store = 4;
    // gen "offset := 0"
    opn1.kind=INT; opn1.type = 0; opn1.const_int=0;
    result.kind = ID; result.type = INT; result.offset = symbolTable.symbols[offset_place].offset;
    strcpy(result.id, symbolTable.symbols[offset_place].alias);
    T->code = genIR(ASSIGNOP, opn1, opn2, result);

    // in array call, exp1 means ID; exp2 means [0]
    // pushback all the Exp place
    while(T0->kind == ARRAY_CALL)
    {
        T0->Exp2->offset = T->offset+T->width;
        Exp(T0->Exp2);
        if(T0->Exp2->type != INT)
            semantic_error(T0->pos,"Fatal Error:", "Array's index_type isn't INT\n");
        vector_push_back(v, T0->Exp2->place);     
        T->width += T0->Exp2->width;
        printf("T.width:%d\n", T->width);
        T->code = merge(2, T->code, T0->Exp2->code);
        T0 = T0->Exp1;
    }
    if(T0->kind==ID)
    {
        // T0 offset is the T offset + the space T have used
        T0->offset = T->offset + T->width;
        T0->width = T->width;
        rtn = searchSymbolTable(T0->type_id);
        T0->type = symbolTable.symbols[rtn].type - ARRAY_DEC;
        T->type = T0->type;
        if (rtn == -1)
            semantic_error(T->pos, T->type_id, "变量未定义");
        else if (symbolTable.symbols[rtn].flag == 'F')
            semantic_error(T->pos, T->type_id, "是函数名，类型不匹配");
        else{
            int offset = symbolTable.symbols[rtn].offset;
            
            // store is the lengthof the basic type of the array
            int basic_type = symbolTable.symbols[rtn].type - ARRAY_DEC;
            int store = 4;

            for(int i=0; i < v->size; i++)
            {
                int var_pos = v->data[i];
                printf("var pos = %d\n", var_pos);
                // use a temp to save the immediate number
                // Why T.width: all the node use one stack mem, if use T0, then the first temp1 can't be stored
                int immediate_place = fill_Temp(newTemp(), LEV, INT, 'T', T->offset + T->width);
                printf("T.offset:%d, T,width%d\n", T->offset, T->width);
                T->width += 4;
                opn1.kind = ID; opn1.type = INT; opn1.offset = symbolTable.symbols[immediate_place].offset;   
                strcpy(opn1.id,symbolTable.symbols[immediate_place].alias);
                opn2.kind = INT; opn2.type = INT; opn2.const_int = store;    
                struct opn blank;  
                T->code = merge(2, T->code, genIR(ASSIGNOP, opn2,blank,opn1));

                // temp := ss.back * store
                // opn1 : store(immediate int) ; opn2 : ss.back; target : temp
                int mul_place = fill_Temp(newTemp(), LEV, INT, 'T', T->offset + T->width); 
                T->width += 4;
                // opn2
                opn2.kind = ID; opn2.type = INT;
                opn2.offset = symbolTable.symbols[var_pos].offset; 
                printf("varpos,offsey = %d\n", opn2.offset);
                strcpy(opn2.id, symbolTable.symbols[var_pos].alias);
                // res
                strcpy(result.id, symbolTable.symbols[mul_place].alias);
                result.kind = ID; result.type = INT; result.offset = symbolTable.symbols[mul_place].offset;
                T->code = merge(2, T->code, genIR(STAR, opn1, opn2, result));

                // offset = offset + temp result:offset | opn1:=res \uparrow result
                opn1 = result;                 
                result.kind = ID; result.type = INT; result.offset = symbolTable.symbols[offset_place].offset;
                strcpy(result.id, symbolTable.symbols[offset_place].alias);
                // merge IR
                T->code = merge(2, T->code, genIR(PLUS, opn1, result, result));

                // width add (No need, but temp to make symbol table more elegant)
                store *= symbolTable.symbols[rtn].arraylen->data[i];
            }
            printf("store = %d\n", offset);
            // T->width += T0->width;
            // use a temp to save the result of the array call; IR fmt: temp := array_id[offset]
            int return_position = fill_Temp(newTemp(), LEV, ARRAY_POINTER, 'T', T->offset+T->width);
            T->width += 4;
            // res:opn1(temp) | opn1:id(opn2) | opn2:offset(result opn)
            // temp
            opn1.kind = ARRAY_POINTER; opn1.type = T->type; opn1.offset = symbolTable.symbols[return_position].offset;
            strcpy(opn1.id, symbolTable.symbols[return_position].alias);
            // opn2
            opn2.kind = ID; opn2.type = T->type; opn2.offset = symbolTable.symbols[rtn].offset;
            strcpy(opn2.id, symbolTable.symbols[rtn].alias);
            result.kind = ID; result.type = INT; result.offset = symbolTable.symbols[offset_place].offset;
            strcpy(result.id, symbolTable.symbols[offset_place].alias);
            T->code = merge(2, T->code, genIR(ARRAY_POINTER, opn2, result, opn1));
            
            T->place = return_position;         // save position
            T->kind = ARRAY_CALL;
            /* TODO: a[b] := 0; c := a[b] we need to geenrate a pointer which -> the target mem
               and then if we assign, we directly assign to the target
               the resolution is when it comes like `temp9 -> v3[temp4]`
               we assign the temp9's value to v3.offset + temp4.typeint. and this need to 
               then when we use temp9 */
            
            // final IR h->op is ARRAY_POINTER result->kind==ARRAY_POINTER result
        }
    } else
        semantic_error(T0->pos,"Fatal Error!", "Array Left Must be ID\n");
    return;
}
/*  Array Call is a[0], so the T Node need to record  offset and all the node 
    so there must be one IR like this "tmp_offset := tmp_offset + a" to calculate the offset
    but then there must be one like this "arr[tmp_offset] := ..." or "opn := arr[tmp_offset]"
*/