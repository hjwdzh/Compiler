%{
    #include "types.h"
    #include "statement.h"
    #include "buffer.h"
    void* node;
%}
%union {
    char cValue; //2
    int iValue; //1
    float fValue; //3
    void* nPtr; //0
    double dValue; //4
};

%token <iValue> INTEGER_VAL
%token <cValue> CHAR_VAL
%token <fValue> FLOAT_VAL
%token <dValue> DOUBLE_VAL
%token <nPtr> IDENTIFIER
%token <nPtr> STRING_LITERAL

%token SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <iValue> unary_operator type_specifier assignment_operator type_qualifier storage_class_specifier struct_or_union

%type <nPtr> primary_expression postfix_expression argument_expression_list unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression expression constant_expression declaration declaration_specifiers init_declarator_list init_declarator struct_or_union_specifier struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list struct_declarator enum_specifier enumerator_list enumerator declarator direct_declarator pointer type_qualifier_list parameter_type_list parameter_list parameter_declaration identifier_list type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement compound_statement declaration_list statement_list expression_statement selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition

%start translation_unit
%%

primary_expression
: IDENTIFIER {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 0;
    ((struct PrimaryExpression*)node)->identifier = (char*)$1;
    $$ = node;
}
| INTEGER_VAL {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 1;
    ((struct PrimaryExpression*)node)->iValue = (int)$1;
    $$ = node;
}
| CHAR_VAL {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 2;
    ((struct PrimaryExpression*)node)->cValue = (char)$1;
    $$ = node;
}
| FLOAT_VAL {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 3;
    ((struct PrimaryExpression*)node)->fValue = (float)$1;
    $$ = node;
}
| DOUBLE_VAL {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 4;
    ((struct PrimaryExpression*)node)->dValue = (double)$1;
    $$ = node;
}
| STRING_LITERAL {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 5;
    ((struct PrimaryExpression*)node)->literal = (char*)$1;
    $$ = node;
}
| '(' expression ')' {
    node = malloc(sizeof(struct PrimaryExpression));
    ((struct PrimaryExpression*)node)->type = 6;
    ((struct PrimaryExpression*)node)->expression = (struct Expression*)$2;
    $$ = node;
}
;

postfix_expression
: primary_expression {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 0;
    ((struct PostfixExpression*)node)->primaryExpression = (struct PrimaryExpression*)$1;
    $$ = node;
}
| postfix_expression '[' expression ']' {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 1;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)$1;
    ((struct PostfixExpression*)node)->expression = (struct Expression*)$3;
    $$ = node;
}
| postfix_expression '(' ')' {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 2;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)$1;
    $$ = node;
}
| postfix_expression '(' argument_expression_list ')' {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 3;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)$1;
    ((struct PostfixExpression*)node)->argumentExpressionList = (struct ArgumentExpressionList*)$3;
    $$ = node;
}
| postfix_expression '.' IDENTIFIER {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 4;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)$1;
    ((struct PostfixExpression*)node)->identifier = (char*)$3;
    $$ = node;
}
| postfix_expression PTR_OP IDENTIFIER {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 5;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)$1;
    ((struct PostfixExpression*)node)->identifier = (char*)$3;
    $$ = node;
}
| postfix_expression INC_OP {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 6;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)$1;
    $$ = node;
}
| postfix_expression DEC_OP {
    node = malloc(sizeof(struct PostfixExpression));
    ((struct PostfixExpression*)node)->type = 7;
    ((struct PostfixExpression*)node)->postfixExpression = (struct PostfixExpression*)$1;
    $$ = node;
}
;

argument_expression_list
: assignment_expression {
    node = malloc(sizeof(struct ArgumentExpressionList));
    ((struct ArgumentExpressionList*)node)->type = 0;
    ((struct ArgumentExpressionList*)node)->assignmentExpression = (struct AssignmentExpression*)$1;
    $$ = node;
}
| argument_expression_list ',' assignment_expression {
    node = malloc(sizeof(struct ArgumentExpressionList));
    ((struct ArgumentExpressionList*)node)->type = 1;
    ((struct ArgumentExpressionList*)node)->argumentExpressionList = (struct ArgumentExpressionList*)$1;
    ((struct ArgumentExpressionList*)node)->assignmentExpression = (struct AssignmentExpression*)$3;
    $$ = node;
}
;

unary_expression
: postfix_expression {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 0;
    ((struct UnaryExpression*)node)->postfixExpression = (struct PostfixExpression*)$1;
    $$ = node;
}
| INC_OP unary_expression {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 1;
    ((struct UnaryExpression*)node)->unaryExpression = (struct UnaryExpression*)$2;
    $$ = node;
}
| DEC_OP unary_expression {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 2;
    ((struct UnaryExpression*)node)->unaryExpression = (struct UnaryExpression*)$2;
    $$ = node;
}
| unary_operator cast_expression {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 3;
    ((struct UnaryExpression*)node)->unaryOperator = (char)$1;
    ((struct UnaryExpression*)node)->castExpression = (struct CastExpression*)$2;
    $$ = node;
}
| SIZEOF unary_expression {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 4;
    ((struct UnaryExpression*)node)->unaryExpression = (struct UnaryExpression*)$2;
    $$ = node;
}
| SIZEOF '(' type_name ')' {
    node = malloc(sizeof(struct UnaryExpression));
    ((struct UnaryExpression*)node)->type = 5;
    ((struct UnaryExpression*)node)->typeName = (struct TypeName*)$3;
    $$ = node;
}
;

unary_operator
: '&' { $$ = 1; }
| '*' { $$ = 2; }
| '+' { $$ = 3; }
| '-' { $$ = 4; }
| '~' { $$ = 5; }
| '!' { $$ = 6; }
;

cast_expression
: unary_expression {
    node = malloc(sizeof(struct CastExpression));
    ((struct CastExpression*)node)->type = 0;
    ((struct CastExpression*)node)->unaryExpression = (struct UnaryExpression*)$1;
    $$ = node;
}
| '(' type_name ')' cast_expression {
    node = malloc(sizeof(struct CastExpression));
    ((struct CastExpression*)node)->type = 1;
    ((struct CastExpression*)node)->typeName = (struct TypeName*)$2;
    ((struct CastExpression*)node)->castExpression = (struct CastExpression*)$4;
    $$ = node;
}
;

multiplicative_expression
: cast_expression {
    node = malloc(sizeof(struct MultiplicativeExpression));
    ((struct MultiplicativeExpression*)node)->type = 0;
    ((struct MultiplicativeExpression*)node)->castExpression = (struct CastExpression*)$1;
    $$ = node;
}
| multiplicative_expression '*' cast_expression {
    node = malloc(sizeof(struct MultiplicativeExpression));
    ((struct MultiplicativeExpression*)node)->type = 1;
    ((struct MultiplicativeExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)$1;
    ((struct MultiplicativeExpression*)node)->castExpression = (struct CastExpression*)$3;
    $$ = node;
}
| multiplicative_expression '/' cast_expression {
    node = malloc(sizeof(struct MultiplicativeExpression));
    ((struct MultiplicativeExpression*)node)->type = 2;
    ((struct MultiplicativeExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)$1;
    ((struct MultiplicativeExpression*)node)->castExpression = (struct CastExpression*)$3;
    $$ = node;
}
| multiplicative_expression '%' cast_expression {
    node = malloc(sizeof(struct MultiplicativeExpression));
    ((struct MultiplicativeExpression*)node)->type = 3;
    ((struct MultiplicativeExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)$1;
    ((struct MultiplicativeExpression*)node)->castExpression = (struct CastExpression*)$3;
    $$ = node;
}
;

additive_expression
: multiplicative_expression {
    node = malloc(sizeof(struct AdditiveExpression));
    ((struct AdditiveExpression*)node)->type = 0;
    ((struct AdditiveExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)$1;
    $$ = node;
}
| additive_expression '+' multiplicative_expression {
    node = malloc(sizeof(struct AdditiveExpression));
    ((struct AdditiveExpression*)node)->type = 1;
    ((struct AdditiveExpression*)node)->additiveExpression = (struct AdditiveExpression*)$1;
    ((struct AdditiveExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)$3;
    $$ = node;
}
| additive_expression '-' multiplicative_expression {
    node = malloc(sizeof(struct AdditiveExpression));
    ((struct AdditiveExpression*)node)->type = 2;
    ((struct AdditiveExpression*)node)->additiveExpression = (struct AdditiveExpression*)$1;
    ((struct AdditiveExpression*)node)->multiplicativeExpression = (struct MultiplicativeExpression*)$3;
    $$ = node;
}
;

shift_expression
: additive_expression {
    node = malloc(sizeof(struct ShiftExpression));
    ((struct ShiftExpression*)node)->type = 0;
    ((struct ShiftExpression*)node)->additiveExpression = (struct AdditiveExpression*)$1;
    $$ = node;
}
| shift_expression LEFT_OP additive_expression {
    node = malloc(sizeof(struct ShiftExpression));
    ((struct ShiftExpression*)node)->type = 1;
    ((struct ShiftExpression*)node)->shiftExpression = (struct ShiftExpression*)$1;
    ((struct ShiftExpression*)node)->additiveExpression = (struct AdditiveExpression*)$3;
    $$ = node;
}
| shift_expression RIGHT_OP additive_expression {
    node = malloc(sizeof(struct ShiftExpression));
    ((struct ShiftExpression*)node)->type = 2;
    ((struct ShiftExpression*)node)->shiftExpression = (struct ShiftExpression*)$1;
    ((struct ShiftExpression*)node)->additiveExpression = (struct AdditiveExpression*)$3;
    $$ = node;
}
;

relational_expression
: shift_expression {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 0;
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)$1;
    $$ = node;
}
| relational_expression '<' shift_expression {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 1;
    ((struct RelationalExpression*)node)->relationalExpression = (struct RelationalExpression*)$1;
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)$3;
    $$ = node;
}
| relational_expression '>' shift_expression {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 2;
    ((struct RelationalExpression*)node)->relationalExpression = (struct RelationalExpression*)$1;
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)$3;
    $$ = node;
}
| relational_expression LE_OP shift_expression {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 3;
    ((struct RelationalExpression*)node)->relationalExpression = (struct RelationalExpression*)$1;
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)$3;
    $$ = node;
}
| relational_expression GE_OP shift_expression {
    node = malloc(sizeof(struct RelationalExpression));
    ((struct RelationalExpression*)node)->type = 4;
    ((struct RelationalExpression*)node)->relationalExpression = (struct RelationalExpression*)$1;
    ((struct RelationalExpression*)node)->shiftExpression = (struct ShiftExpression*)$3;
    $$ = node;
}
;

equality_expression
: relational_expression{
    node = malloc(sizeof(struct EqualityExpression));
    ((struct EqualityExpression*)node)->type = 0;
    ((struct EqualityExpression*)node)->relationalExpression = (struct RelationalExpression*)$1;
    $$ = node;
}
| equality_expression EQ_OP relational_expression{
    node = malloc(sizeof(struct EqualityExpression));
    ((struct EqualityExpression*)node)->type = 1;
    ((struct EqualityExpression*)node)->equalityExpression = (struct EqualityExpression*)$1;
    ((struct EqualityExpression*)node)->relationalExpression = (struct RelationalExpression*)$3;
    $$ = node;
}
| equality_expression NE_OP relational_expression{
    node = malloc(sizeof(struct EqualityExpression));
    ((struct EqualityExpression*)node)->type = 2;
    ((struct EqualityExpression*)node)->equalityExpression = (struct EqualityExpression*)$1;
    ((struct EqualityExpression*)node)->relationalExpression = (struct RelationalExpression*)$3;
    $$ = node;
}
;

and_expression
: equality_expression{
    node = malloc(sizeof(struct AndExpression));
    ((struct AndExpression*)node)->type = 0;
    ((struct AndExpression*)node)->equalityExpression = (struct EqualityExpression*)$1;
    $$ = node;
}
| and_expression '&' equality_expression{
    node = malloc(sizeof(struct AndExpression));
    ((struct AndExpression*)node)->type = 1;
    ((struct AndExpression*)node)->andExpression = (struct AndExpression*)$1;
    ((struct AndExpression*)node)->equalityExpression = (struct EqualityExpression*)$3;
    $$ = node;
}
;

exclusive_or_expression
: and_expression{
    node = malloc(sizeof(struct ExclusiveOrExpression));
    ((struct ExclusiveOrExpression*)node)->type = 0;
    ((struct ExclusiveOrExpression*)node)->andExpression = (struct AndExpression*)$1;
    $$ = node;
}
| exclusive_or_expression '^' and_expression{
    node = malloc(sizeof(struct ExclusiveOrExpression));
    ((struct ExclusiveOrExpression*)node)->type = 1;
    ((struct ExclusiveOrExpression*)node)->exclusiveOrExpression = (struct ExclusiveOrExpression*)$1;
    ((struct ExclusiveOrExpression*)node)->andExpression = (struct AndExpression*)$3;
    $$ = node;
}
;

inclusive_or_expression
: exclusive_or_expression{
    node = malloc(sizeof(struct InclusiveOrExpression));
    ((struct InclusiveOrExpression*)node)->type = 0;
    ((struct InclusiveOrExpression*)node)->exclusiveOrExpression = (struct ExclusiveOrExpression*)$1;
    $$ = node;
}
| inclusive_or_expression '|' exclusive_or_expression{
    node = malloc(sizeof(struct InclusiveOrExpression));
    ((struct InclusiveOrExpression*)node)->type = 1;
    ((struct InclusiveOrExpression*)node)->inclusiveOrExpression = (struct InclusiveOrExpression*)$1;
    ((struct InclusiveOrExpression*)node)->exclusiveOrExpression = (struct ExclusiveOrExpression*)$3;
    $$ = node;
}
;

logical_and_expression
: inclusive_or_expression{
    node = malloc(sizeof(struct LogicalAndExpression));
    ((struct LogicalAndExpression*)node)->type = 0;
    ((struct LogicalAndExpression*)node)->inclusiveOrExpression = (struct InclusiveOrExpression*)$1;
    $$ = node;
}
| logical_and_expression AND_OP inclusive_or_expression{
    node = malloc(sizeof(struct LogicalAndExpression));
    ((struct LogicalAndExpression*)node)->type = 1;
    ((struct LogicalAndExpression*)node)->logicalAndExpression = (struct LogicalAndExpression*)$1;
    ((struct LogicalAndExpression*)node)->inclusiveOrExpression = (struct InclusiveOrExpression*)$3;
    $$ = node;
}
;

logical_or_expression
: logical_and_expression{
    node = malloc(sizeof(struct LogicalOrExpression));
    ((struct LogicalOrExpression*)node)->type = 0;
    ((struct LogicalOrExpression*)node)->logicalAndExpression = (struct LogicalAndExpression*)$1;
    $$ = node;
}
| logical_or_expression OR_OP logical_and_expression{
    node = malloc(sizeof(struct LogicalOrExpression));
    ((struct LogicalOrExpression*)node)->type = 1;
    ((struct LogicalOrExpression*)node)->logicalOrExpression = (struct LogicalOrExpression*)$1;
    ((struct LogicalOrExpression*)node)->logicalAndExpression = (struct LogicalAndExpression*)$3;
    $$ = node;
}
;

conditional_expression
: logical_or_expression{
    node = malloc(sizeof(struct ConditionalExpression));
    ((struct ConditionalExpression*)node)->type = 0;
    ((struct ConditionalExpression*)node)->logicalOrExpression = (struct LogicalOrExpression*)$1;
    $$ = node;
}
| logical_or_expression '?' expression ':' conditional_expression{
    node = malloc(sizeof(struct ConditionalExpression));
    ((struct ConditionalExpression*)node)->type = 1;
    ((struct ConditionalExpression*)node)->logicalOrExpression = (struct LogicalOrExpression*)$1;
    ((struct ConditionalExpression*)node)->expression = (struct Expression*)$3;
    ((struct ConditionalExpression*)node)->conditionalExpression = (struct ConditionalExpression*)$5;
    $$ = node;
}
;

assignment_expression
: conditional_expression{
    node = malloc(sizeof(struct AssignmentExpression));
    ((struct AssignmentExpression*)node)->type = 0;
    ((struct AssignmentExpression*)node)->conditionalExpression = (struct ConditionalExpression*)$1;
    $$ = node;
}
| unary_expression assignment_operator assignment_expression{
    node = malloc(sizeof(struct AssignmentExpression));
    ((struct AssignmentExpression*)node)->type = 1;
    ((struct AssignmentExpression*)node)->unaryExpression = (struct UnaryExpression*)$1;
    ((struct AssignmentExpression*)node)->assignmentOperator = (int)$2;
    ((struct AssignmentExpression*)node)->assignmentExpression = (struct AssignmentExpression*)$3;
    $$ = node;
}
;

assignment_operator
: '='{ $$ = 1; }
| MUL_ASSIGN{ $$ = 2; }
| DIV_ASSIGN{ $$ = 3; }
| MOD_ASSIGN{ $$ = 4; }
| ADD_ASSIGN{ $$ = 5; }
| SUB_ASSIGN{ $$ = 6; }
| LEFT_ASSIGN{ $$ = 7; }
| RIGHT_ASSIGN{ $$ = 8; }
| AND_ASSIGN{ $$ = 9; }
| XOR_ASSIGN{ $$ = 10; }
| OR_ASSIGN{ $$ = 11; }
;

expression
: assignment_expression{
    node = malloc(sizeof(struct Expression));
    ((struct Expression*)node)->type = 0;
    ((struct Expression*)node)->assignmentExpression = (struct AssignmentExpression*)$1;
    $$ = node;
}
| expression ',' assignment_expression{
    node = malloc(sizeof(struct Expression));
    ((struct Expression*)node)->type = 1;
    ((struct Expression*)node)->expression = (struct Expression*)$1;
    ((struct Expression*)node)->assignmentExpression = (struct AssignmentExpression*)$3;
    $$ = node;
}
;

constant_expression
: conditional_expression{
    node = malloc(sizeof(struct ConstantExpression));
    ((struct ConstantExpression*)node)->type = 0;
    ((struct ConstantExpression*)node)->conditionalExpression = (struct ConditionalExpression*)$1;
    $$ = node;
}
;

declaration
: declaration_specifiers ';'{
    node = malloc(sizeof(struct Declaration));
    ((struct Declaration*)node)->type = 0;
    ((struct Declaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$1;
    $$ = node;
}
| declaration_specifiers init_declarator_list ';'{
    node = malloc(sizeof(struct Declaration));
    ((struct Declaration*)node)->type = 1;
    ((struct Declaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$1;
    ((struct Declaration*)node)->initDeclaratorList = (struct InitDeclaratorList*)$2;
    $$ = node;
}
;

declaration_specifiers
: storage_class_specifier{
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 0;
    ((struct DeclarationSpecifiers*)node)->storageClassSpecifier = $1;
    $$ = node;
}
| storage_class_specifier declaration_specifiers{
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 1;
    ((struct DeclarationSpecifiers*)node)->storageClassSpecifier = $1;
    ((struct DeclarationSpecifiers*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$2;
    $$ = node;
}
| type_specifier{
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 2;
    ((struct DeclarationSpecifiers*)node)->typeSpecifier = (int)$1;
    $$ = node;
}
| type_specifier declaration_specifiers{
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 3;
    ((struct DeclarationSpecifiers*)node)->typeSpecifier = (int)$1;
    ((struct DeclarationSpecifiers*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$2;
    $$ = node;
}
| type_qualifier{
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 4;
    ((struct DeclarationSpecifiers*)node)->typeQualifier = (int)$1;
    $$ = node;
}
| type_qualifier declaration_specifiers{
    node = malloc(sizeof(struct DeclarationSpecifiers));
    ((struct DeclarationSpecifiers*)node)->type = 5;
    ((struct DeclarationSpecifiers*)node)->typeQualifier = (int)$1;
    ((struct DeclarationSpecifiers*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$2;
    $$ = node;
}
;

init_declarator_list
: init_declarator{
    node = malloc(sizeof(struct InitDeclaratorList));
    ((struct InitDeclaratorList*)node)->type = 0;
    ((struct InitDeclaratorList*)node)->initDeclarator = (struct InitDeclarator*)$1;
    $$ = node;
}
| init_declarator_list ',' init_declarator{
    node = malloc(sizeof(struct InitDeclaratorList));
    ((struct InitDeclaratorList*)node)->type = 1;
    ((struct InitDeclaratorList*)node)->initDeclaratorList = (struct InitDeclaratorList*)$1;
    ((struct InitDeclaratorList*)node)->initDeclarator = (struct InitDeclarator*)$3;
    $$ = node;
}
;

init_declarator
: declarator{
    node = malloc(sizeof(struct InitDeclarator));
    ((struct InitDeclarator*)node)->type = 0;
    ((struct InitDeclarator*)node)->declarator = (struct Declarator*)$1;
    $$ = node;
}
| declarator '=' initializer{
    node = malloc(sizeof(struct InitDeclarator));
    ((struct InitDeclarator*)node)->type = 1;
    ((struct InitDeclarator*)node)->declarator = (struct Declarator*)$1;
    ((struct InitDeclarator*)node)->initializer = (struct Initializer*)$3;
    $$ = node;
}
;

storage_class_specifier
: TYPEDEF{ $$ = 1; }
| EXTERN{ $$ = 2; }
| STATIC{ $$ = 3; }
| AUTO{ $$ = 4; }
| REGISTER{ $$ = 5; }
;

type_specifier
: VOID{ $$ = 1; }
| CHAR{ $$ = 2; }
| SHORT{ $$ = 3; }
| INT{ $$ = 4; }
| LONG{ $$ = 5; }
| FLOAT{ $$ = 6; }
| DOUBLE{ $$ = 7; }
| SIGNED{ $$ = 8; }
| UNSIGNED{ $$ = 9; }
| struct_or_union_specifier{ $$ = 10; }
| enum_specifier{ $$ = 11; }
| TYPE_NAME{ $$ = 12; }
;
//
struct_or_union_specifier
: struct_or_union IDENTIFIER '{' struct_declaration_list '}'{
    
}
| struct_or_union '{' struct_declaration_list '}'{
    
}
| struct_or_union IDENTIFIER{
    
}
;

struct_or_union
: STRUCT{ $$ = 1; }
| UNION{ $$ = 2; }
;

struct_declaration_list
: struct_declaration{
    node = malloc(sizeof(struct StructDeclarationList));
    ((struct StructDeclarationList*)node)->type = 0;
    ((struct StructDeclarationList*)node)->structDeclaration = (struct StructDeclaration*)$1;
    $$ = node;
}
| struct_declaration_list struct_declaration{
    node = malloc(sizeof(struct StructDeclarationList));
    ((struct StructDeclarationList*)node)->type = 1;
    ((struct StructDeclarationList*)node)->structDeclarationList = (struct StructDeclarationList*)$1;
    ((struct StructDeclarationList*)node)->structDeclaration = (struct StructDeclaration*)$2;
    $$ = node;
}
;

struct_declaration
: specifier_qualifier_list struct_declarator_list ';'{
    node = malloc(sizeof(struct StructDeclaration));
    ((struct StructDeclaration*)node)->type = 0;
    ((struct StructDeclaration*)node)->specifierQualifierList = (struct SpecifierQualifierList*)$1;
    ((struct StructDeclaration*)node)->structDeclaratorList = (struct StructDeclaratorList*)$2;
    $$ = node;
}
;

specifier_qualifier_list
: type_specifier specifier_qualifier_list{
    node = malloc(sizeof(struct SpecifierQualifierList));
    ((struct SpecifierQualifierList*)node)->type = 0;
    ((struct SpecifierQualifierList*)node)->typeSpecifier = (int)$1;
    ((struct SpecifierQualifierList*)node)->specifierQualifierList = (struct SpecifierQualifierList*)$2;
    $$ = node;
}
| type_specifier{
    node = malloc(sizeof(struct SpecifierQualifierList));
    ((struct SpecifierQualifierList*)node)->type = 1;
    ((struct SpecifierQualifierList*)node)->typeSpecifier = (int)$1;
    $$ = node;
}
| type_qualifier specifier_qualifier_list{
    node = malloc(sizeof(struct SpecifierQualifierList));
    ((struct SpecifierQualifierList*)node)->type = 2;
    ((struct SpecifierQualifierList*)node)->typeQualifier = (int)$1;
    ((struct SpecifierQualifierList*)node)->specifierQualifierList = (struct SpecifierQualifierList*)$2;
    $$ = node;
}
| type_qualifier{
    node = malloc(sizeof(struct SpecifierQualifierList));
    ((struct SpecifierQualifierList*)node)->type = 3;
    ((struct SpecifierQualifierList*)node)->typeQualifier = (int)$1;
    $$ = node;
}
;

struct_declarator_list
: struct_declarator{
    node = malloc(sizeof(struct StructDeclaratorList));
    ((struct StructDeclaratorList*)node)->type = 0;
    ((struct StructDeclaratorList*)node)->structDeclarator = (struct StructDeclarator*)$1;
    $$ = node;
}
| struct_declarator_list ',' struct_declarator{
    node = malloc(sizeof(struct StructDeclaratorList));
    ((struct StructDeclaratorList*)node)->type = 1;
    ((struct StructDeclaratorList*)node)->structDeclaratorList = (struct StructDeclaratorList*)$1;
    ((struct StructDeclaratorList*)node)->structDeclarator = (struct StructDeclarator*)$3;
    $$ = node;
}
;

struct_declarator
: declarator{
    node = malloc(sizeof(struct StructDeclarator));
    ((struct StructDeclarator*)node)->type = 0;
    ((struct StructDeclarator*)node)->declarator = (struct Declarator*)$1;
    $$ = node;
}
| ':' constant_expression{
    node = malloc(sizeof(struct StructDeclarator));
    ((struct StructDeclarator*)node)->type = 1;
    ((struct StructDeclarator*)node)->constantExpression = (struct ConstantExpression*)$2;
    $$ = node;
}
| declarator ':' constant_expression{
    node = malloc(sizeof(struct StructDeclarator));
    ((struct StructDeclarator*)node)->type = 2;
    ((struct StructDeclarator*)node)->declarator = (struct Declarator*)$1;
    ((struct StructDeclarator*)node)->constantExpression = (struct ConstantExpression*)$3;
    $$ = node;
}
;
//
enum_specifier
: ENUM '{' enumerator_list '}' { $$ = 0; }
| ENUM IDENTIFIER '{' enumerator_list '}' { $$ = 0; }
| ENUM IDENTIFIER { $$ = 0; }
;

enumerator_list
: enumerator{
    node = malloc(sizeof(struct EnumeratorList));
    ((struct EnumeratorList*)node)->type = 0;
    ((struct EnumeratorList*)node)->enumerator = (struct Enumerator*)$1;
    $$ = node;
}
| enumerator_list ',' enumerator{
    node = malloc(sizeof(struct EnumeratorList));
    ((struct EnumeratorList*)node)->type = 1;
    ((struct EnumeratorList*)node)->enumeratorList = (struct EnumeratorList*)$1;
    ((struct EnumeratorList*)node)->enumerator = (struct Enumerator*)$3;
    $$ = node;
}
;
//
enumerator
: IDENTIFIER
| IDENTIFIER '=' constant_expression
;

type_qualifier
: CONST{ $$ = 1; }
| VOLATILE{ $$ = 2; }
;

declarator
: pointer direct_declarator{
    node = malloc(sizeof(struct Declarator));
    ((struct Declarator*)node)->type = 0;
    ((struct Declarator*)node)->pointer = (struct Pointer*)$1;
    ((struct Declarator*)node)->directDeclarator = (struct DirectDeclarator*)$2;
    $$ = node;
}
| direct_declarator{
    node = malloc(sizeof(struct Declarator));
    ((struct Declarator*)node)->type = 1;
    ((struct Declarator*)node)->directDeclarator = (struct DirectDeclarator*)$1;
    $$ = node;
}
;

direct_declarator
: IDENTIFIER{
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 0;
    ((struct DirectDeclarator*)node)->identifier = (char*)$1;
    $$ = node;
}
| '(' declarator ')'{
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 1;
    ((struct DirectDeclarator*)node)->declarator = (struct Declarator*)$2;
    $$ = node;
}
| direct_declarator '[' constant_expression ']'{
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 2;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)$1;
    ((struct DirectDeclarator*)node)->constantExpression = (struct ConstantExpression*)$3;
    $$ = node;
}
| direct_declarator '[' ']'{
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 3;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)$1;
    $$ = node;
}
| direct_declarator '(' parameter_type_list ')'{
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 4;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)$1;
    ((struct DirectDeclarator*)node)->parameterTypeList = (struct ParameterTypeList*)$3;
    $$ = node;
}
| direct_declarator '(' identifier_list ')'{
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 5;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)$1;
    ((struct DirectDeclarator*)node)->identifierList = (struct IdentifierList*)$3;
    $$ = node;
}
| direct_declarator '(' ')'{
    node = malloc(sizeof(struct DirectDeclarator));
    ((struct DirectDeclarator*)node)->type = 6;
    ((struct DirectDeclarator*)node)->directDeclarator = (struct DirectDeclarator*)$1;
    $$ = node;
}
;

pointer
: '*'{
    node = malloc(sizeof(struct Pointer));
    ((struct Pointer*)node)->type = 0;
    $$ = node;
}
| '*' type_qualifier_list{
    node = malloc(sizeof(struct Pointer));
    ((struct Pointer*)node)->type = 1;
    ((struct Pointer*)node)->typeQualifierList = (struct TypeQualifierList*)$2;
    $$ = node;
}
| '*' pointer{
    node = malloc(sizeof(struct Pointer));
    ((struct Pointer*)node)->type = 2;
    ((struct Pointer*)node)->pointer = (struct Pointer*)$2;
    $$ = node;
}
| '*' type_qualifier_list pointer{
    node = malloc(sizeof(struct Pointer));
    ((struct Pointer*)node)->type = 3;
    ((struct Pointer*)node)->typeQualifierList = (struct TypeQualifierList*)$2;
    ((struct Pointer*)node)->pointer = (struct Pointer*)$3;
    $$ = node;
}
;

type_qualifier_list
: type_qualifier{
    node = malloc(sizeof(struct TypeQualifierList));
    ((struct TypeQualifierList*)node)->type = 0;
    ((struct TypeQualifierList*)node)->typeQualifier = (int)$1;
    $$ = node;
}
| type_qualifier_list type_qualifier{
    node = malloc(sizeof(struct TypeQualifierList));
    ((struct TypeQualifierList*)node)->type = 1;
    ((struct TypeQualifierList*)node)->typeQualifierList = (struct TypeQualifierList*)$1;
    ((struct TypeQualifierList*)node)->typeQualifier = (int)$2;
    $$ = node;
}
;

parameter_type_list
: parameter_list{
    node = malloc(sizeof(struct ParameterTypeList));
    ((struct ParameterTypeList*)node)->type = 0;
    ((struct ParameterTypeList*)node)->parameterList = (struct ParameterList*)$1;
    $$ = node;
}
| parameter_list ',' ELLIPSIS{
    node = malloc(sizeof(struct ParameterTypeList));
    ((struct ParameterTypeList*)node)->type = 1;
    ((struct ParameterTypeList*)node)->parameterList = (struct ParameterList*)$1;
    $$ = node;
}
;

parameter_list
: parameter_declaration{
    node = malloc(sizeof(struct ParameterList));
    ((struct ParameterList*)node)->type = 0;
    ((struct ParameterList*)node)->parameterDeclaration = (struct ParameterDeclaration*)$1;
    $$ = node;
}
| parameter_list ',' parameter_declaration{
    node = malloc(sizeof(struct ParameterList));
    ((struct ParameterList*)node)->type = 1;
    ((struct ParameterList*)node)->parameterList = (struct ParameterList*)$1;
    ((struct ParameterList*)node)->parameterDeclaration = (struct ParameterDeclaration*)$3;
    $$ = node;
}
;

parameter_declaration
: declaration_specifiers declarator{
    node = malloc(sizeof(struct ParameterDeclaration));
    ((struct ParameterDeclaration*)node)->type = 0;
    ((struct ParameterDeclaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$1;
    ((struct ParameterDeclaration*)node)->declarator = (struct Declarator*)$2;
    $$ = node;
}
| declaration_specifiers abstract_declarator{
    node = malloc(sizeof(struct ParameterDeclaration));
    ((struct ParameterDeclaration*)node)->type = 1;
    ((struct ParameterDeclaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$1;
    ((struct ParameterDeclaration*)node)->abstractDeclarator = (struct AbstractDeclarator*)$2;
    $$ = node;
}
| declaration_specifiers{
    node = malloc(sizeof(struct ParameterDeclaration));
    ((struct ParameterDeclaration*)node)->type = 2;
    ((struct ParameterDeclaration*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$1;
    $$ = node;
}
;

identifier_list
: IDENTIFIER{
    node = malloc(sizeof(struct IdentifierList));
    ((struct IdentifierList*)node)->type = 0;
    ((struct IdentifierList*)node)->identifier = (char*)$1;
    $$ = node;
}
| identifier_list ',' IDENTIFIER{
    node = malloc(sizeof(struct IdentifierList));
    ((struct IdentifierList*)node)->type = 1;
    ((struct IdentifierList*)node)->identifierList = (struct IdentifierList*)$1;
    ((struct IdentifierList*)node)->identifier = (char*)$3;
    $$ = node;
}
;

type_name
: specifier_qualifier_list{
    node = malloc(sizeof(struct TypeName));
    ((struct TypeName*)node)->type = 0;
    ((struct TypeName*)node)->specifierQualifierList = (struct SpecifierQualifierList*)$1;
    $$ = node;
}
| specifier_qualifier_list abstract_declarator{
    node = malloc(sizeof(struct TypeName));
    ((struct TypeName*)node)->type = 1;
    ((struct TypeName*)node)->specifierQualifierList = (struct SpecifierQualifierList*)$1;
    ((struct TypeName*)node)->abstractDeclarator = (struct AbstractDeclarator*)$2;
    $$ = node;
}
;

abstract_declarator
: pointer{
    node = malloc(sizeof(struct AbstractDeclarator));
    ((struct AbstractDeclarator*)node)->type = 0;
    ((struct AbstractDeclarator*)node)->pointer = (struct Pointer*)$1;
    $$ = node;
}
| direct_abstract_declarator{
    node = malloc(sizeof(struct AbstractDeclarator));
    ((struct AbstractDeclarator*)node)->type = 1;
    ((struct AbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)$1;
    $$ = node;
}
| pointer direct_abstract_declarator{
    node = malloc(sizeof(struct AbstractDeclarator));
    ((struct AbstractDeclarator*)node)->type = 2;
    ((struct AbstractDeclarator*)node)->pointer = (struct Pointer*)$1;
    ((struct AbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)$2;
    $$ = node;
}
;

direct_abstract_declarator
: '(' abstract_declarator ')'{
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 0;
    ((struct DirectAbstractDeclarator*)node)->abstractDeclarator = (struct AbstractDeclarator*)$2;
    $$ = node;
}
| '[' ']'{
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 1;
    $$ = node;
}
| '[' constant_expression ']'{
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 2;
    ((struct DirectAbstractDeclarator*)node)->constantExpression = (struct ConstantExpression*)$2;
    $$ = node;
}
| direct_abstract_declarator '[' ']'{
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 3;
    ((struct DirectAbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)$1;
    $$ = node;
}
| direct_abstract_declarator '[' constant_expression ']'{
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 4;
    ((struct DirectAbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)$1;
    ((struct DirectAbstractDeclarator*)node)->constantExpression = (struct ConstantExpression*)$3;
    $$ = node;
}
| '(' ')'{
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 5;
    $$ = node;
}
| '(' parameter_type_list ')'{
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 6;
    ((struct DirectAbstractDeclarator*)node)->parameterTypeList = (struct ParameterTypeList*)$2;
    $$ = node;
}
| direct_abstract_declarator '(' ')'{
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 7;
    ((struct DirectAbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)$1;
    $$ = node;
}
| direct_abstract_declarator '(' parameter_type_list ')'{
    node = malloc(sizeof(struct DirectAbstractDeclarator));
    ((struct DirectAbstractDeclarator*)node)->type = 8;
    ((struct DirectAbstractDeclarator*)node)->directAbstractDeclarator = (struct DirectAbstractDeclarator*)$1;
    ((struct DirectAbstractDeclarator*)node)->parameterTypeList = (struct ParameterTypeList*)$3;
    $$ = node;
}
;

initializer
: assignment_expression{
    node = malloc(sizeof(struct Initializer));
    ((struct Initializer*)node)->type = 0;
    ((struct Initializer*)node)->assignmentExpression = (struct AssignmentExpression*)$1;
    $$ = node;
}
| '{' initializer_list '}'{
    node = malloc(sizeof(struct Initializer));
    ((struct Initializer*)node)->type = 1;
    ((struct Initializer*)node)->initializerList = (struct InitializerList*)$2;
    $$ = node;
}
| '{' initializer_list ',' '}'{
    node = malloc(sizeof(struct Initializer));
    ((struct Initializer*)node)->type = 2;
    ((struct Initializer*)node)->initializerList = (struct InitializerList*)$2;
    $$ = node;
}
;

initializer_list
: initializer{
    node = malloc(sizeof(struct InitializerList));
    ((struct InitializerList*)node)->type = 0;
    ((struct InitializerList*)node)->initializer = (struct Initializer*)$1;
    $$ = node;
}
| initializer_list ',' initializer{
    node = malloc(sizeof(struct InitializerList));
    ((struct InitializerList*)node)->type = 1;
    ((struct InitializerList*)node)->initializerList = (struct InitializerList*)$1;
    ((struct InitializerList*)node)->initializer = (struct Initializer*)$3;
    $$ = node;
}
;

statement
: labeled_statement{
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 0;
    ((struct Statement*)node)->labeledStatement = (struct LabeledStatement*)$1;
    $$ = node;
}
| compound_statement{
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 1;
    ((struct Statement*)node)->compoundStatement = (struct CompoundStatement*)$1;
    $$ = node;
}
| expression_statement{
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 2;
    ((struct Statement*)node)->expressionStatement = (struct ExpressionStatement*)$1;
    $$ = node;
}
| selection_statement{
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 3;
    ((struct Statement*)node)->selectionStatement = (struct SelectionStatement*)$1;
    $$ = node;
}
| iteration_statement{
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 4;
    ((struct Statement*)node)->iterationStatement = (struct IterationStatement*)$1;
    $$ = node;
}
| jump_statement{
    node = malloc(sizeof(struct Statement));
    ((struct Statement*)node)->type = 5;
    ((struct Statement*)node)->jumpStatement = (struct JumpStatement*)$1;
    $$ = node;
}
;

labeled_statement
: IDENTIFIER ':' statement{
    node = malloc(sizeof(struct LabeledStatement));
    ((struct LabeledStatement*)node)->type = 0;
    ((struct LabeledStatement*)node)->identifier = (char*)$1;
    ((struct LabeledStatement*)node)->statement = (struct Statement*)$3;
    $$ = node;
}
| CASE constant_expression ':' statement{
    node = malloc(sizeof(struct LabeledStatement));
    ((struct LabeledStatement*)node)->type = 1;
    ((struct LabeledStatement*)node)->constantExpression = (struct ConstantExpression*)$2;
    ((struct LabeledStatement*)node)->statement = (struct Statement*)$4;
    $$ = node;
}
| DEFAULT ':' statement{
    node = malloc(sizeof(struct LabeledStatement));
    ((struct LabeledStatement*)node)->type = 2;
    ((struct LabeledStatement*)node)->constantExpression = (struct ConstantExpression*)$3;
    $$ = node;
}
;

compound_statement
: '{' '}'{
    node = malloc(sizeof(struct CompoundStatement));
    ((struct CompoundStatement*)node)->type = 0;
    $$ = node;
}
| '{' statement_list '}'{
    node = malloc(sizeof(struct CompoundStatement));
    ((struct CompoundStatement*)node)->type = 1;
    ((struct CompoundStatement*)node)->statementList = (struct StatementList*)$2;
    $$ = node;
}
| '{' declaration_list '}'{
    node = malloc(sizeof(struct CompoundStatement));
    ((struct CompoundStatement*)node)->type = 2;
    ((struct CompoundStatement*)node)->declarationList = (struct DeclarationList*)$2;
    $$ = node;
}
| '{' declaration_list statement_list '}'{
    node = malloc(sizeof(struct CompoundStatement));
    ((struct CompoundStatement*)node)->type = 3;
    ((struct CompoundStatement*)node)->declarationList = (struct DeclarationList*)$2;
    ((struct CompoundStatement*)node)->statementList = (struct StatementList*)$3;
    $$ = node;
}
;

declaration_list
: declaration{
    node = malloc(sizeof(struct DeclarationList));
    ((struct DeclarationList*)node)->type = 0;
    ((struct DeclarationList*)node)->declaration = (struct Declaration*)$1;
    $$ = node;
}
| declaration_list declaration{
    node = malloc(sizeof(struct DeclarationList));
    ((struct DeclarationList*)node)->type = 1;
    ((struct DeclarationList*)node)->declarationList = (struct DeclarationList*)$1;
    ((struct DeclarationList*)node)->declaration = (struct Declaration*)$2;
    $$ = node;
}
;

statement_list
: statement{
    node = malloc(sizeof(struct StatementList));
    ((struct StatementList*)node)->type = 0;
    ((struct StatementList*)node)->statement = (struct Statement*)$1;
    $$ = node;
}
| statement_list statement{
    node = malloc(sizeof(struct StatementList));
    ((struct StatementList*)node)->type = 1;
    ((struct StatementList*)node)->statementList = (struct StatementList*)$1;
    ((struct StatementList*)node)->statement = (struct Statement*)$2;
    $$ = node;
}
;

expression_statement
: ';'{
    node = malloc(sizeof(struct ExpressionStatement));
    ((struct ExpressionStatement*)node)->type = 0;
    $$ = node;
}
| expression ';'{
    node = malloc(sizeof(struct ExpressionStatement));
    ((struct ExpressionStatement*)node)->type = 1;
    ((struct ExpressionStatement*)node)->expression = (struct Expression*)$1;
    $$ = node;
}
;

selection_statement
: IF '(' expression ')' statement{
    node = malloc(sizeof(struct SelectionStatement));
    ((struct SelectionStatement*)node)->type = 0;
    ((struct SelectionStatement*)node)->expression = (struct Expression*)$3;
    ((struct SelectionStatement*)node)->s1 = (struct Statement*)$5;
    $$ = node;
}
| IF '(' expression ')' statement ELSE statement{
    node = malloc(sizeof(struct SelectionStatement));
    ((struct SelectionStatement*)node)->type = 1;
    ((struct SelectionStatement*)node)->expression = (struct Expression*)$3;
    ((struct SelectionStatement*)node)->s1 = (struct Statement*)$5;
    ((struct SelectionStatement*)node)->s2 = (struct Statement*)$7;
    $$ = node;
}
| SWITCH '(' expression ')' statement{
    node = malloc(sizeof(struct SelectionStatement));
    ((struct SelectionStatement*)node)->type = 2;
    ((struct SelectionStatement*)node)->expression = (struct Expression*)$3;
    ((struct SelectionStatement*)node)->s1 = (struct Statement*)$5;
    $$ = node;
}
;

iteration_statement
: WHILE '(' expression ')' statement{
    node = malloc(sizeof(struct IterationStatement));
    ((struct IterationStatement*)node)->type = 0;
    ((struct IterationStatement*)node)->expression = (struct Expression*)$3;
    ((struct IterationStatement*)node)->statement = (struct Statement*)$5;
    $$ = node;
}
| DO statement WHILE '(' expression ')' ';'{
    node = malloc(sizeof(struct IterationStatement));
    ((struct IterationStatement*)node)->type = 1;
    ((struct IterationStatement*)node)->statement = (struct Statement*)$2;
    ((struct IterationStatement*)node)->expression = (struct Expression*)$5;
    $$ = node;
}
| FOR '(' expression_statement expression_statement ')' statement{
    node = malloc(sizeof(struct IterationStatement));
    ((struct IterationStatement*)node)->type = 2;
    ((struct IterationStatement*)node)->s1 = (struct ExpressionStatement*)$3;
    ((struct IterationStatement*)node)->s2 = (struct ExpressionStatement*)$4;
    ((struct IterationStatement*)node)->statement = (struct Statement*)$6;
    $$ = node;
}
| FOR '(' expression_statement expression_statement expression ')' statement{
    node = malloc(sizeof(struct IterationStatement));
    ((struct IterationStatement*)node)->type = 3;
    ((struct IterationStatement*)node)->s1 = (struct ExpressionStatement*)$3;
    ((struct IterationStatement*)node)->s2 = (struct ExpressionStatement*)$4;
    ((struct IterationStatement*)node)->expression = (struct Expression*)$5;
    ((struct IterationStatement*)node)->statement = (struct Statement*)$7;
    $$ = node;
}
;

jump_statement
: GOTO IDENTIFIER ';'{
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 0;
    ((struct JumpStatement*)node)->identifier = (char*)$2;
    $$ = node;
}
| CONTINUE ';'{
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 1;
    $$ = node;
}
| BREAK ';'{
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 2;
    $$ = node;
}
| RETURN ';'{
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 3;
    $$ = node;
}
| RETURN expression ';'{
    node = malloc(sizeof(struct JumpStatement));
    ((struct JumpStatement*)node)->type = 4;
    ((struct JumpStatement*)node)->expression = (struct Expression*)$2;
    $$ = node;
}
;

translation_unit
: external_declaration{
    node = malloc(sizeof(struct TranslationUnit));
    ((struct TranslationUnit*)node)->type = 0;
    ((struct TranslationUnit*)node)->externalDeclaration = (struct ExternalDeclaration*)$1;
    $$ = node;
}
| translation_unit external_declaration{
    node = malloc(sizeof(struct TranslationUnit));
    ((struct TranslationUnit*)node)->type = 1;
    ((struct TranslationUnit*)node)->translationUnit = (struct TranslationUnit*)$1;
    ((struct TranslationUnit*)node)->externalDeclaration = (struct ExternalDeclaration*)$2;
    $$ = node;
}
;

external_declaration
: function_definition{
    node = malloc(sizeof(struct ExternalDeclaration));
    ((struct ExternalDeclaration*)node)->type = 0;
    ((struct ExternalDeclaration*)node)->functionDefinition = (struct FunctionDefinition*)$1;
    $$ = node;
}
| declaration{
    node = malloc(sizeof(struct ExternalDeclaration));
    ((struct ExternalDeclaration*)node)->type = 1;
    ((struct ExternalDeclaration*)node)->declaration = (struct Declaration*)$1;
    $$ = node;
}
;

function_definition
: declaration_specifiers declarator declaration_list compound_statement{
    node = malloc(sizeof(struct FunctionDefinition));
    ((struct FunctionDefinition*)node)->type = 0;
    ((struct FunctionDefinition*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$1;
    ((struct FunctionDefinition*)node)->declarator = (struct Declarator*)$2;
    ((struct FunctionDefinition*)node)->declarationList = (struct DeclarationList*)$3;
    ((struct FunctionDefinition*)node)->compoundStatement = (struct CompoundStatement*)$4;
    $$ = node;
}
| declaration_specifiers declarator compound_statement{
    node = malloc(sizeof(struct FunctionDefinition));
    ((struct FunctionDefinition*)node)->type = 1;
    ((struct FunctionDefinition*)node)->declarationSpecifiers = (struct DeclarationSpecifiers*)$1;
    ((struct FunctionDefinition*)node)->declarator = (struct Declarator*)$2;
    ((struct FunctionDefinition*)node)->compoundStatement = (struct CompoundStatement*)$3;
    $$ = node;
}
| declarator declaration_list compound_statement{
    node = malloc(sizeof(struct FunctionDefinition));
    ((struct FunctionDefinition*)node)->type = 2;
    ((struct FunctionDefinition*)node)->declarationList = (struct DeclarationList*)$1;
    ((struct FunctionDefinition*)node)->compoundStatement = (struct CompoundStatement*)$2;
    $$ = node;
}
| declarator compound_statement{
    node = malloc(sizeof(struct FunctionDefinition));
    ((struct FunctionDefinition*)node)->type = 3;
    ((struct FunctionDefinition*)node)->declarator = (struct Declarator*)$1;
    ((struct FunctionDefinition*)node)->compoundStatement = (struct CompoundStatement*)$2;
    $$ = node;
}
;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
    return 1;
}

int main(int argc, char* argv[])
{
    strcpy(name1, argv[1]);
    strcpy(name2, argv[3]);
    freopen(name1, "r" ,stdin);
    yyparse();
    translation_unit_begin(node);
    return 0;




}
