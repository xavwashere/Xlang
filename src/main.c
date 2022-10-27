#include <stdio.h>
#include "include/lexer.h"
#include "include/parser.h"

int main(int argc, char* argv[]){
    lexer_T* lexer = init_lexer(
       "def var = \"var\";\n"
       "print(var);\n"
    );

    parser_T* parser = init_parser(lexer);
    ast_T* root = parser_parse(parser);

    printf("%d\n", root -> type);
    printf("%d\n", root -> compound_size);

    return 0;
}