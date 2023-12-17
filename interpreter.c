#include "parser.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the lexer

void initLexer(Lexer* lexer, const char* input) {
    lexer->input = input;
    lexer->position = 0;
    lexer->current.type = TOKEN_UNKNOWN;
    lexer->previous.type = TOKEN_UNKNOWN;
}




// Helper function to check if a character is whitespace
int isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Helper function to check if a character is a digit
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to create a new binary expression node
AstNode* createBinaryExpression(AstNode* left, AstNode* right) {
    AstNode* node = malloc(sizeof(AstNode));
    node->type = AST_BINARY_EXPRESSION;
    node->left = left;
    node->right = right;
    return node;
}

// Function to create a new literal expression node
AstNode* createLiteralExpression(int value) {
    AstNode* node = malloc(sizeof(AstNode));
    node->type = AST_LITERAL_EXPRESSION;
    node->intValue = value;
    
    return node;
}

// Function to parse a binary expression
AstNode* parseBinaryExpression(Lexer* lexer);

// Function to parse a primary expression
AstNode* parsePrimaryExpression(Lexer* lexer) {
    Token token = lexer->current;

    // Check if it's a literal (integer)
    if (token.type == TOKEN_INTEGER) {
        lexer->current = getNextToken(lexer); // Consume the token
        return createLiteralExpression(atoi(token.lexeme));
        free(token.lexeme);
    }

    // If it's not a literal, it's an error
    fprintf(stderr, "Error: Expected an integer\n");
    return NULL;
}

// Function to parse a binary expression
AstNode* parseBinaryExpression(Lexer* lexer) {
    AstNode* left = parsePrimaryExpression(lexer);
    Token token = lexer->current;

    while (token.type == TOKEN_PLUS) {
        lexer->current = getNextToken(lexer); // Consume the '+' token
        AstNode* right = parsePrimaryExpression(lexer);
        left = createBinaryExpression(left, right);
        token = lexer->current;
    }

    return left;
}


// Function to evaluate an expression
int evaluateExpression(AstNode* node) {
    if (node->type == AST_LITERAL_EXPRESSION) {
        return node->intValue;
    } else if (node->type == AST_BINARY_EXPRESSION) {
        int leftValue = evaluateExpression(node->left);
        int rightValue = evaluateExpression(node->right);
        return leftValue + rightValue;
    } else {
        fprintf(stderr, "Error: Unknown expression type\n");
        return 0;
    }
}

int main() {
    FILE *file = fopen("examples.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Read the file content
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *lingoCode = malloc(fsize + 1);
    fread(lingoCode, 1, fsize, file);
    fclose(file);
    lingoCode[fsize] = 0;

    // Interpret the Lingo code
    Lexer lexer;
    initLexer(&lexer, lingoCode);

    // Your existing parsing and interpretation logic goes here
    
    free(lingoCode);
    return 0;
}