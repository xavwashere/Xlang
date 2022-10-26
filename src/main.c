#include <stdio.h>
#include "include/lexer.h"

int main(int argc, char* argv[]){
    lexer_T* lexer = init_lexer(
       "def var = \"var\";"
       "print(var)"
    );

    token_T* token = (void*)0;

    while ((token = lexer_get_next_token(lexer)) -> type != (void*)0){
        printf("TOKEN(%d, %s)\n", token -> type, token -> value);
    }

    return 0;
}