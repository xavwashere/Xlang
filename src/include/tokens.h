#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN_STRUCT{
    enum {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_SEMICOLON,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_EOF,
        TOKEN_LBRACE,
        TOKEN_RBRACE,
        TOKEN_COMMA
    } type;

    char* value;

} token_T;

token_T* init_token(int type, char* value);
#endif