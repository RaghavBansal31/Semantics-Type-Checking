#ifndef __LEXER__H__

#define __LEXER__H__



#include <vector>

#include <string>



#include "inputbuf.h"






typedef enum { END_OF_FILE, INT, REAL, BOO, TR, FA, IF, WHILE, SWITCH, CASE, PUBLIC, PRIVATE, NUM, REALNUM, NOT, PLUS, MINUS, MULT, DIV, GTEQ, GREATER, LTEQ, NOTEQUAL, LESS, LPAREN, RPAREN, EQUAL, COLON, COMMA, SEMICOLON, LBRACE, RBRACE, ID, ERROR // TODO: Add labels for new token types here

} TokenType;



class Token {

  public:

    void Print();



    std::string lexeme;

    TokenType token_type;

    int line_no;

};



class LexicalAnalyzer {

  public:

    Token GetToken();

    TokenType UngetToken(Token);

    LexicalAnalyzer();



  private:

    std::vector<Token> tokens;

    int line_no;

    Token tmp;

    InputBuffer input;



    bool SkipSpace();

    bool SkipComments();

    bool IsKeyword(std::string);

    TokenType FindKeywordIndex(std::string);

    Token ScanIdOrKeyword();

    Token ScanNumber();

};

void update_Types(int LHS, int RHS);

void addList(std::string n, int lN, int t);

int Search_List(std::string n);







#endif
