#include "lexer.h"
#include "parser.h"
#include <string.h>

// Define keywords for your language
static const char* keywords[] = {
    "Showme",
    "Remember",
    "give",
    "steal",
    "LikeMe",
    "notLikeMe",
    "moreThanMe",
    "lessThanMe",
    "IsitTrue",
    "hide",
    "startgossiping",
    "endgossiping",
    "ofCourse",
    "never",
    "getIn",
    "getOut",
    NULL // End of keywords
};

// Helper function to check if a word is a keyword
static TokenType checkKeyword(const char* word) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(keywords[i], word) == 0) {
            return i + 2; // Offset by 2 for custom keywords
        }
    }
    return TOKEN_IDENTIFIER; // Not a keyword, treat as identifier
}

// Helper function to check if a character is whitespace
static int isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

Token getNextToken(Lexer* lexer) {
    Token token;
    token.lexeme = NULL;

    // Skip whitespace
    while (isWhitespace(lexer->input[lexer->position])) {
        lexer->position++;
    }

    // Check for the end of input
    if (lexer->input[lexer->position] == '\0') {
        token.type = TOKEN_EOF;
        return token;
    }

        // Check for the plus sign
    if (lexer->input[lexer->position] == '+') {
        lexer->position++;
        token.lexeme = "+";
        token.type = TOKEN_PLUS;
        return token;
    }

    // Add the following code for multiplication (*) operator
    if (lexer->input[lexer->position] == '*') {
        lexer->position++;
        token.lexeme = "*";
        token.type = TOKEN_MULTIPLY; // Update the token type
        return token;
    }

    // Add the following code for division (/) operator
    if (lexer->input[lexer->position] == '/') {
        lexer->position++;
        token.lexeme = "/";
        token.type = TOKEN_DIVIDE; // Update the token type
        return token;
    }

    // Check for keywords or identifiers
    int start = lexer->position;
    while (lexer->input[lexer->position] != '\0' && !isWhitespace(lexer->input[lexer->position])) {
        lexer->position++;
    }

    // Determine token type
    if (start != lexer->position) {
        // We have a non-empty lexeme
        int length = lexer->position - start;
        char* lexeme = malloc(length + 1);
        strncpy(lexeme, &lexer->input[start], length);
        lexeme[length] = '\0';

        token.lexeme = lexeme;
        token.type = checkKeyword(lexeme); // Check if it's a keyword
    } else {
        token.type = TOKEN_UNKNOWN; // Unknown token
    }

    return token;
}
