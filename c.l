D           [0-9]
L           [a-zA-Z_]
H           [a-fA-F0-9]
E           [Ee][+-]?{D}+
FS          (f|F|l|L)
IS          (u|U|l|L)*

%{
#include <stdio.h>
#include "c.tab.h"

void count();
%}

%%
"/*"            { comment(); }

"auto"          { count(); return(AUTO); }
"break"         { count(); return(BREAK); }
"case"          { count(); return(CASE); }
"char"          { count(); return(CHAR); }
"const"         { count(); return(CONST); }
"continue"      { count(); return(CONTINUE); }
"default"       { count(); return(DEFAULT); }
"do"            { count(); return(DO); }
"double"        { count(); return(DOUBLE); }
"else"          { count(); return(ELSE); }
"enum"          { count(); return(ENUM); }
"extern"        { count(); return(EXTERN); }
"float"         { count(); return(FLOAT); }
"for"           { count(); return(FOR); }
"goto"          { count(); return(GOTO); }
"if"            { count(); return(IF); }
"int"           { count(); return(INT); }
"long"          { count(); return(LONG); }
"register"      { count(); return(REGISTER); }
"return"        { count(); return(RETURN); }
"short"         { count(); return(SHORT); }
"signed"        { count(); return(SIGNED); }
"sizeof"        { count(); return(SIZEOF); }
"static"        { count(); return(STATIC); }
"struct"        { count(); return(STRUCT); }
"switch"        { count(); return(SWITCH); }
"typedef"       { count(); return(TYPEDEF); }
"union"         { count(); return(UNION); }
"unsigned"      { count(); return(UNSIGNED); }
"void"          { count(); return(VOID); }
"volatile"      { count(); return(VOLATILE); }
"while"         { count(); return(WHILE); }

{L}({L}|{D})*       { count();
                      int len = strlen(yytext);
                      char* ptr = (char*)malloc(len + 1);
                      strcpy(ptr, yytext);
                      yylval.nPtr = ptr;
                      return(check_type());
                    }

0[xX]{H}+{IS}?      { count();
                      yylval.iValue = atoi(yytext);
                      return(INTEGER_VAL);
                    }
0{D}+{IS}?      { count();
                  yylval.iValue = atoi(yytext);
                  return(INTEGER_VAL);
                }
{D}+{IS}?       { count();
                  yylval.iValue = atoi(yytext);
                  return(INTEGER_VAL);
                }
L?'(\\.|[^\\'])+'   { count(); 
                      int posval = 1;
                      if (yytext[0] == 'L')
                        ++posval;
                      if (yytext[posval] == '\\')
                        ++posval;
                      yylval.cValue = yytext[posval];
                      return(CHAR_VAL);
                    }

{D}+{E}{FS}?        { count();
                      char c = yytext[strlen(yytext) - 1];
                      if (c == 'f' || c == 'F')
                      {
                          sscanf(yytext, "%f", &yylval.fValue);
                          return (FLOAT_VAL);
                      }
                      else
                      {
                          sscanf(yytext, "%lf", &yylval.dValue);
                          return (DOUBLE_VAL);
                      }
                    }
{D}*"."{D}+({E})?{FS}?  { count();
                          char c = yytext[strlen(yytext) - 1];
                          if (c == 'f' || c == 'F')
                          {
                              sscanf(yytext, "%f", &yylval.fValue);
                              return (FLOAT_VAL);
                          }
                          else
                          {
                              sscanf(yytext, "%lf", &yylval.dValue);
                              return (DOUBLE_VAL);
                          }
                        }
{D}+"."{D}*({E})?{FS}?  { count();
                          char c = yytext[strlen(yytext) - 1];
                          if (c == 'f' || c == 'F')
                          {
                              sscanf(yytext, "%f", &yylval.fValue);
                              return (FLOAT_VAL);
                          }
                          else
                          {
                              sscanf(yytext, "%lf", &yylval.dValue);
                              return (DOUBLE_VAL);
                          }
                        }

L?\"(\\.|[^\\"])*\" { count(); 
                      int len = strlen(yytext);
                      int s1 = 0, s2 = 0, s3 = 0;
                      if (yytext[s2] == 'L')
                      ++s2;
                      ++s2;
                      char* ptr = (char*)malloc(len + 1);
                      for (; s2 < len - 1; ++s2)
                      {
                          if (yytext[s2] == '\\')
                              s3 = 1 - s3;
                          else
                              if (s3 == 1 && yytext[s2] == 'n')
                              {
                                  ptr[s1++] = '\\';
                                  ptr[s1++] = '0';
                                  ptr[s1++] = 'A';
                              }
                              else
                                  ptr[s1++] = yytext[s2];
                      }
                      ptr[s1] = 0;
                      yylval.nPtr = ptr;
                      return(STRING_LITERAL);
                    }

"..."           { count(); return(ELLIPSIS); }
">>="           { count(); return(RIGHT_ASSIGN); }
"<<="           { count(); return(LEFT_ASSIGN); }
"+="            { count(); return(ADD_ASSIGN); }
"-="            { count(); return(SUB_ASSIGN); }
"*="            { count(); return(MUL_ASSIGN); }
"/="            { count(); return(DIV_ASSIGN); }
"%="            { count(); return(MOD_ASSIGN); }
"&="            { count(); return(AND_ASSIGN); }
"^="            { count(); return(XOR_ASSIGN); }
"|="            { count(); return(OR_ASSIGN); }
">>"            { count(); return(RIGHT_OP); }
"<<"            { count(); return(LEFT_OP); }
"++"            { count(); return(INC_OP); }
"--"            { count(); return(DEC_OP); }
"->"            { count(); return(PTR_OP); }
"&&"            { count(); return(AND_OP); }
"||"            { count(); return(OR_OP); }
"<="            { count(); return(LE_OP); }
">="            { count(); return(GE_OP); }
"=="            { count(); return(EQ_OP); }
"!="            { count(); return(NE_OP); }
";"         { count(); return(';'); }
("{"|"<%")      { count(); return('{'); }
("}"|"%>")      { count(); return('}'); }
","         { count(); return(','); }
":"         { count(); return(':'); }
"="         { count(); return('='); }
"("         { count(); return('('); }
")"         { count(); return(')'); }
("["|"<:")      { count(); return('['); }
("]"|":>")      { count(); return(']'); }
"."         { count(); return('.'); }
"&"         { count(); return('&'); }
"!"         { count(); return('!'); }
"~"         { count(); return('~'); }
"-"         { count(); return('-'); }
"+"         { count(); return('+'); }
"*"         { count(); return('*'); }
"/"         { count(); return('/'); }
"%"         { count(); return('%'); }
"<"         { count(); return('<'); }
">"         { count(); return('>'); }
"^"         { count(); return('^'); }
"|"         { count(); return('|'); }
"?"         { count(); return('?'); }

[ \t\v\n\f]     { count(); }
.           { /* ignore bad characters */ }

%%

int yywrap()
{
    return(1);
}


comment()
{
    char c, c1;

loop:
    while ((c = input()) != '*' && c != 0)
        putchar(c);

    if ((c1 = input()) != '/' && c != 0)
    {
        unput(c1);
        goto loop;
    }

    if (c != 0)
        putchar(c1);
    return 0;
}


int column = 0;

void count()
{
    int i;

    for (i = 0; yytext[i] != '\0'; i++)
        if (yytext[i] == '\n')
            column = 0;
        else if (yytext[i] == '\t')
            column += 8 - (column % 8);
        else
            column++;

    ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*   if (yytext == type_name)
*       return(TYPE_NAME);
*
*   return(IDENTIFIER);
*/

/*
*   it actually will only return IDENTIFIER
*/

    return(IDENTIFIER);
}