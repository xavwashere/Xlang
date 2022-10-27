#include "include/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

parser_T* init_parser(lexer_T* lexer){
    parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser -> lexer = lexer;
    parser -> current_token = lexer_get_next_token(lexer);

    return parser;
}

void parser_eat(parser_T* parser, int token_type){
    if (parser -> current_token -> type == token_type){
        parser -> current_token = lexer_get_next_token(parser -> lexer);
    } else {
        printf("Unexpected token %s", parser -> current_token -> value);
        exit(1);
    }
}

ast_T* parser_parse(parser_T* parser){
    return parser_parse_statements(parser);
}

ast_T* parser_parse_statement(parser_T* parser){
    switch (parser -> current_token -> type){
        case TOKEN_ID: {
            return parser_parse_id(parser);
        }
    }
}

ast_T* parser_parse_statements(parser_T* parser){
    ast_T* compound = init_ast(AST_COMPOUND);
    compound -> compound_value = calloc(1, sizeof(struct AST_STRUCT*));
    ast_T* ast_statement = parser_parse_statement(parser);
    compound -> compound_value[0] = ast_statement;
    compound -> compound_size += 1;

    while (parser -> current_token -> type == TOKEN_SEMICOLON){
        parser_eat(parser, TOKEN_SEMICOLON);

        ast_T* ast_statement = parser_parse_statement(parser);
        compound -> compound_value = realloc(compound -> compound_value, compound -> compound_size = sizeof(struct AST_STRUCT*));
        compound -> compound_value[compound -> compound_size - 1] = ast_statement;
        compound -> compound_size += 1;
    }

    return compound;
}

ast_T* parser_parse_expr(parser_T* parser){
    switch (parser -> current_token -> type){
        case TOKEN_STRING: return parser_parse_string(parser);
    }
}

ast_T* parser_parse_term(parser_T* parser){

}

ast_T* parser_parse_factor(parser_T* parser){

}

ast_T* parser_parse_variable(parser_T* parser){
    char* token_value = parser -> current_token -> value;

    parser_eat(parser, TOKEN_ID);

    if (parser -> current_token -> type == TOKEN_LPAREN){
        return parser_parse_function_call(parser);
    }

    ast_T* ast_variable = init_ast(AST_VAR);

    return ast_variable;
}

ast_T* parser_parse_function_call(parser_T* parser){
    printf("func call");
}

ast_T* parser_parse_string(parser_T* parser){

}

ast_T* parser_parse_id(parser_T* parser){
    if (strcmp(parser -> current_token -> value, "var") == 0){
        return parser_parse_variable_define(parser);
    } else {
        return parser_parse_variable(parser);
    }
}

ast_T* parser_parse_variable_define(parser_T* parser){
    parser_eat(parser, TOKEN_ID);
    char* variable_name = parser -> current_token -> value;
    parser_eat(parser, TOKEN_ID);
    parser_eat(parser, TOKEN_EQUALS);
    ast_T* variable_value = parser_parse_expr(parser);

    ast_T* variable_def = init_ast(AST_VAR_DEFINE);
    variable_def -> ast_var_define_var_name = variable_name;
    variable_def -> var_define_value = variable_value;

    return variable_def;
}