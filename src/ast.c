#include "include/ast.h"
#include <stdlib.h>

ast_T* init_ast(int type){
    ast_T* ast = calloc(1, sizeof(struct AST_STRUCT));
    ast -> type = type;

    ast -> ast_var_define_var_name = (void*)0;
    ast -> var_define_value = (void*)0;

    ast -> var_name = (void*)0;
    
    ast -> func_call_name = (void*)0;
    ast -> func_call_args = (void*)0;
    ast -> func_call_arg_size = (void*)0;

    ast -> string_value = (void*)0;
    
    return ast;
}