typedef enum {
    TOK_MNEMONIC,
    TOK_REGISTER,
    TOK_LABEL,
    TOK_COLON,
    TOK_HASH,
    TOK_COMMA,
    TOK_SCALAR,
    TOK_EOL,
    TOK_UNKNOWN,
    TOK_NUMBER,
    TOK_LPAREN,
    TOK_RPAREN,
} token_kind_t;

typedef struct {
    token_kind_t kind;
    char data[32];
    unsigned char index;
} token_t;

const char *tokenize(const char *input, const char *instructions[], token_t *token);
const char *token_kind_name(token_kind_t kind);
