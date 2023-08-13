#include <string.h>

#include "tokenizer.h"

unsigned char is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

unsigned char is_hex(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

unsigned char is_alphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c == '$';
}

unsigned char is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Fetch next token
// Return pointer to first character after token
const char *tokenize(const char *input, const char *instructions[], token_t *token) {
    char c;
    unsigned char i = 0;
    const char *mnem;

    // Skip whitespaces
    while (*input == ' ') {
        input++;
    }
    if (!*input) {
        return 0;
    }

    c = *input;
    token->data[0] = c;
    token->data[1] = 0;
    if (c == ':') {
        token->kind = TOK_COLON;
        return ++input;
    }
    if (c == '\n') {
        token->kind = TOK_EOL;
        return ++input;
    }
    if (c == '#') {
        token->kind = TOK_HASH;
        return ++input;
    }
    if (c == ',') {
        token->kind = TOK_COMMA;
        return ++input;
    }
    if (is_alphanumeric(c)) {
        c = *input;
        while (1) {
            token->data[i++] = c;
            c = *++input;
            if (!is_alphanumeric(c)) {
                break;
            }
        }
        token->data[i] = 0;
        if (token->data[0] == '$' || is_digit(token->data[0])) {
            token->kind = TOK_NUMBER;
        } else {
            token->kind = TOK_LABEL;
            i = 0;
            while (*instructions) {
                mnem = *instructions;
                if (!strcasecmp(mnem, token->data)) {
                    token->kind = TOK_MNEMONIC;
                    token->index = i;
                    break;
                }
                instructions++;
                i++;
            }
        }
        return input;
    }
    token->kind = TOK_UNKNOWN;
    return input + 1;
}

const char *token_kind_name(token_kind_t kind) {
    switch (kind) {
        case TOK_MNEMONIC:
            return "MNEMONIC";
        case TOK_REGISTER:
            return "REGISTER";
        case TOK_LABEL:
            return "LABEL";
        case TOK_COLON:
            return "COLON";
        case TOK_HASH:
            return "HASH";
        case TOK_COMMA:
            return "COMMA";
        case TOK_SCALAR:
            return "SCALAR";
        case TOK_EOL:
            return "EOL";
        case TOK_UNKNOWN:
            return "UNKNOWN";
        case TOK_NUMBER:
            return "NUMBER";
        case TOK_LPAREN:
            return "LPAREN";
        case TOK_RPAREN:
            return "RPAREN";
    }
    return "???";
}
