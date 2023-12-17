#ifndef PARSER_H
#define PARSER_H

// Include necessary headers
#include "lexer.h"
#include <stdlib.h>

// Define AST node types
typedef enum {
    AST_BINARY_EXPRESSION,
    AST_LITERAL_EXPRESSION,
    AST_SHOWME_EXPRESSION,      // Define AST_SHOWME_EXPRESSION
    AST_REMEMBER_EXPRESSION,    // Define AST_REMEMBER_EXPRESSION
} AstNodeType;


// Define a struct for AST nodes
typedef struct AstNode {
    AstNodeType type;
    int intValue;
    struct AstNode* left;
    struct AstNode* right;
    TokenType operator;
} AstNode;


// Function prototypes for parser functions
AstNode* parseExpression(Lexer* lexer);
AstNode* parseMultiplicationExpression(Lexer* lexer);
AstNode* parseShowmeExpression(Lexer* lexer);
AstNode* parseRememberExpression(Lexer* lexer);
// Add more parser function prototypes as needed

#endif // PARSER_H
