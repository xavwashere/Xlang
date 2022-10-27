#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef ast_H
#define ast_H

typedef struct AST_STRUCT{
    enum {
        AST_FUNCTION_CALL,
        AST_var_DEFINE,
        AST_var,
        AST_STRING
    } type;

    char* ast_var_define_var_name;
    struct AST_STRUCT* var_define_value;

    char* var_name;
    
    char* func_call_name;
    struct AST_STRUCT** func_call_args;
    size_t func_call_arg_size;

    char* string_value;

} ast_T;

ast_T* init_ast(int type);
#endif