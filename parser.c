#include "parser.h"
#include "lexer.h"
#include <stdlib.h>

// Implementation of matchToken
static int matchToken(Lexer* lexer, TokenType tokenType) {
    // Check if the current token matches the specified tokenType
    return lexer->current.type == tokenType;
}

// Implementation of the parseExpression function
AstNode* parseExpression(Lexer* lexer) {
    // Dummy implementation for a binary expression
    AstNode* node = malloc(sizeof(AstNode));
    node->type = AST_BINARY_EXPRESSION;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Implement more parser functions as needed
static AstNode* parseAdditionExpression(Lexer* lexer) {
    AstNode* left = parseMultiplicationExpression(lexer);
    while (matchToken(lexer, TOKEN_PLUS) || matchToken(lexer, TOKEN_MINUS)) {
        TokenType operator = lexer->previous.type;
        AstNode* right = parseMultiplicationExpression(lexer);
    }
    return left;
}

AstNode* parseShowmeExpression(Lexer* lexer) {
    // Consume the "Showme" token
    lexer->current = getNextToken(lexer);

    // Parse the expression following "Showme"
    AstNode* expression = parseExpression(lexer);

    // Create an AST node for the Showme expression
    AstNode* showmeNode = malloc(sizeof(AstNode));
    showmeNode->type = AST_SHOWME_EXPRESSION;
    showmeNode->left = expression;
    showmeNode->right = NULL; // Showme expressions don't have a right node

    // Check for the end of expression
    if (!matchToken(lexer, TOKEN_EOF)) {
        fprintf(stderr, "Error: Unexpected token after Showme expression\n");
        free(showmeNode);
        return NULL;
    }

    

    // Return the Showme expression node
    return showmeNode;
}

static int evaluateExpression(AstNode* node) {
    if (node->type == AST_LITERAL_EXPRESSION) {
        return node->intValue;
    } else if (node->type == AST_BINARY_EXPRESSION) {
        int leftValue = evaluateExpression(node->left);
        int rightValue = evaluateExpression(node->right);

        // Perform the appropriate operation based on the operator
        switch (node->operator) {
            case TOKEN_PLUS:
                return leftValue + rightValue;
            case TOKEN_MINUS:
                return leftValue - rightValue;
            case TOKEN_MULTIPLY:
                return leftValue * rightValue;
            case TOKEN_DIVIDE:
                if (rightValue == 0) {
                    fprintf(stderr, "Error: Division by zero\n");
                    return 0;
                }
                return leftValue / rightValue;
            // Add more cases for other operators as needed
            default:
                fprintf(stderr, "Error: Unknown operator\n");
                return 0;
        }
    } else {
        fprintf(stderr, "Error: Unknown expression type\n");
        return 0;
    }
}

// Implementation for parsing Remember expression
AstNode* parseRememberExpression(Lexer* lexer) {
    // Consume the "Remember" token
    lexer->current = getNextToken(lexer);

    // Parse the expression following "Remember"
    AstNode* expression = parseExpression(lexer);

    // Create an AST node for the Remember expression
    AstNode* rememberNode = malloc(sizeof(AstNode));
    rememberNode->type = AST_REMEMBER_EXPRESSION;
    rememberNode->left = expression;
    rememberNode->right = NULL; // Remember expressions don't have a right node

    // Check for the end of expression
    if (!matchToken(lexer, TOKEN_EOF)) {
        fprintf(stderr, "Error: Unexpected token after Remember expression\n");
        free(rememberNode);
        return NULL;
    }

    // Return the Remember expression node
    return rememberNode;
}