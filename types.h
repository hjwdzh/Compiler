#ifndef _TYPES_JINGWEI_H_
#define _TYPES_JINGWEI_H_

struct PrimaryExpression;
struct PostfixExpression;
struct ArgumentExpressionList;
struct UnaryExpression;
struct CastExpression;
struct MultiplicativeExpression;
struct AdditiveExpression;
struct ShiftExpression;
struct RelationalExpression;
struct EqualityExpression;
struct AndExpression;
struct ExclusiveOrExpression;
struct InclusiveOrExpression;
struct LogicalAndExpression;
struct LogicalOrExpression;
struct ConditionalExpression;
struct AssignmentExpression;
struct Expression;
struct ConstantExpression;
struct Declaration;
struct DeclarationSpecifiers;
struct InitDeclaratorList;
struct InitDeclarator;
struct structOrUnionSpecifier;
struct structOrUnion;
struct structDeclarationList;
struct structDeclaration;
struct SpecifierQualifierList;
struct DeclarationList;
struct Declarator;
struct EnumSpecifier;
struct EnumeratorList;
struct Enumerator;
struct Declarator;
struct DirectDeclarator;
struct Pointer;
struct TypeQualifierList;
struct ParameterTypeList;
struct ParameterList;
struct ParameterDeclaration;
struct IdentifierList;
struct TypeName;
struct AbstractDeclarator;
struct DirectAbstractDeclarator;
struct Initializer;
struct InitializerList;
struct Statement;
struct LabeledStatement;
struct CompoundStatement;
struct DeclarationList;
struct StatementList;
struct ExpressionStatement;
struct SelectionStatement;
struct IterationStatement;
struct JumpStatement;
struct TranslationUnit;
struct externalDeclaration;
struct function_definition;


struct PrimaryExpression
{
    int type;
//    union {
        char cValue;
        float fValue;
        int iValue;
        double dValue;
        char* identifier;
        char* literal;
        struct Expression* expression;
 //   };
};

struct PostfixExpression
{
    int type;
 //   union{
        struct PrimaryExpression* primaryExpression;
        struct PostfixExpression* postfixExpression;
   // };
   // union{
        struct Expression* expression;
        struct ArgumentExpressionList* argumentExpressionList;
        char* identifier;
    //};
};

struct ArgumentExpressionList
{
    int type;
    struct ArgumentExpressionList* argumentExpressionList;
    struct AssignmentExpression* assignmentExpression;
};

struct UnaryExpression
{
    int type;
    //union {
        struct PostfixExpression* postfixExpression;
        struct UnaryExpression* unaryExpression;
        struct TypeName* typeName;
        char unaryOperator;
    //};
    struct CastExpression* castExpression;
};

struct CastExpression
{
    int type;
    //union {
        struct UnaryExpression* unaryExpression;
        struct TypeName* typeName;
    //};
    struct CastExpression* castExpression;
};

struct MultiplicativeExpression
{
    int type;
    struct MultiplicativeExpression* multiplicativeExpression;
    struct CastExpression* castExpression;
};

struct AdditiveExpression
{
    int type;
    struct AdditiveExpression* additiveExpression;
    struct MultiplicativeExpression* multiplicativeExpression;
};

struct ShiftExpression
{
    int type;
    struct ShiftExpression* shiftExpression;
    struct AdditiveExpression* additiveExpression;
};

struct RelationalExpression
{
    int type;
    struct RelationalExpression* relationalExpression;
    struct ShiftExpression* shiftExpression;
};

struct EqualityExpression
{
    int type;
    struct EqualityExpression* equalityExpression;
    struct RelationalExpression* relationalExpression;
};

struct AndExpression
{
    int type;
    struct AndExpression* andExpression;
    struct EqualityExpression* equalityExpression;
};

struct ExclusiveOrExpression
{
    int type;
    struct ExclusiveOrExpression* exclusiveOrExpression;
    struct AndExpression* andExpression;
};

struct InclusiveOrExpression
{
    int type;
    struct InclusiveOrExpression* inclusiveOrExpression;
    struct ExclusiveOrExpression* exclusiveOrExpression;
};

struct LogicalAndExpression
{
    int type;
    struct InclusiveOrExpression* inclusiveOrExpression;
    struct LogicalAndExpression* logicalAndExpression;
    struct Expression* expression;
};

struct LogicalOrExpression
{
    int type;
    struct LogicalAndExpression* logicalAndExpression;
    struct LogicalOrExpression* logicalOrExpression;
};

struct ConditionalExpression
{
    int type;
    struct LogicalOrExpression* logicalOrExpression;
    struct ConditionalExpression* conditionalExpression;
    struct Expression* expression;
};

struct AssignmentExpression
{
    int type;
    //union{
        struct ConditionalExpression* conditionalExpression;
        struct UnaryExpression* unaryExpression;
    //};
    int assignmentOperator;
    struct AssignmentExpression* assignmentExpression;
};

struct Expression
{
    int type;
    struct AssignmentExpression* assignmentExpression;
    struct Expression* expression;
};

struct ConstantExpression
{
    int type;
    struct ConditionalExpression* conditionalExpression;
};

struct Declaration
{
    int type;
    struct DeclarationSpecifiers* declarationSpecifiers;
    struct InitDeclaratorList* initDeclaratorList;
};

struct DeclarationSpecifiers
{
    int type;
    //union {
        int storageClassSpecifier;
        int typeSpecifier;
        int typeQualifier;
    //};
    //union {
        struct DeclarationSpecifiers* declarationSpecifiers;
    //};
};

struct InitDeclaratorList
{
    int type;
    struct InitDeclaratorList* initDeclaratorList;
    struct InitDeclarator* initDeclarator;
};

struct InitDeclarator
{
    int type;
    struct Declarator* declarator;
    struct Initializer* initializer;
};

struct StructOrUnionSpecifier
{
    int type;
    struct StructOrUnionSpecifier* structOrUnionSpecifier;
    char* identifier;
    struct StructDeclarationList* structDeclarationList;
};

struct StructOrUnion
{
    int type;
};

struct StructDeclarationList
{
    int type;
    struct StructDeclarationList* structDeclarationList;
    struct StructDeclaration* structDeclaration;
};

struct StructDeclaration
{
    int type;
    struct SpecifierQualifierList* specifierQualifierList;
    struct StructDeclaratorList* structDeclaratorList;
};

struct SpecifierQualifierList
{
    int type;
    //union {
        int typeSpecifier;
        int typeQualifier;
    //};
    struct SpecifierQualifierList* specifierQualifierList;
};

struct StructDeclaratorList
{
    int type;
    struct StructDeclarator* structDeclarator;
    struct StructDeclaratorList* structDeclaratorList;
};

struct StructDeclarator
{
    int type;
    struct Declarator* declarator;
    struct ConstantExpression* constantExpression;
};

struct EnumSpecifier
{
    int type;
    char* identifier;
    struct EnumeratorList* enumeratorList;
};

struct EnumeratorList
{
    int type;
    struct Enumerator* enumerator;
    struct EnumeratorList* enumeratorList;
};

struct Enumerator
{
    int type;
    char* identifier;
    struct ConstantExpression* constantExpression;
};

struct Declarator
{
    int type;
    struct Pointer* pointer;
    struct DirectDeclarator* directDeclarator;
};

struct DirectDeclarator
{
    int type;
    char* identifier;
    //union {
        struct Declarator* declarator;
        struct ParameterTypeList* parameterTypeList;
        struct IdentifierList* identifierList;
        struct ConstantExpression* constantExpression;
    //};
    struct DirectDeclarator* directDeclarator;
};

struct Pointer
{
    int type;
    struct TypeQualifierList* typeQualifierList;
    struct Pointer* pointer;
};

struct TypeQualifierList
{
    int type;
    int typeQualifier;
    struct TypeQualifierList* typeQualifierList;
};

struct ParameterTypeList
{
    int type;
    struct ParameterList* parameterList;
};

struct ParameterList
{
    int type;
    struct ParameterDeclaration* parameterDeclaration;
    struct ParameterList* parameterList;
};

struct ParameterDeclaration
{
    int type;
    struct DeclarationSpecifiers* declarationSpecifiers;
   // union {
        struct Declarator* declarator;
        struct AbstractDeclarator* abstractDeclarator;
   // };
};

struct IdentifierList
{
    int type;
    char* identifier;
    struct IdentifierList* identifierList;
};

struct TypeName
{
    int type;
    struct SpecifierQualifierList* specifierQualifierList;
    struct AbstractDeclarator* abstractDeclarator;
};

struct AbstractDeclarator
{
    int type;
    struct Pointer* pointer;
    struct DirectAbstractDeclarator* directAbstractDeclarator;
};

struct DirectAbstractDeclarator
{
    int type;
    //union {
        struct AbstractDeclarator* abstractDeclarator;
        struct DirectAbstractDeclarator* directAbstractDeclarator;
    //};
    struct ConstantExpression* constantExpression;
    struct ParameterTypeList* parameterTypeList;
};

struct Initializer
{
    int type;
    //union {
        struct AssignmentExpression* assignmentExpression;
        struct InitializerList* initializerList;
    //};
};

struct InitializerList
{
    int type;
    struct Initializer* initializer;
    struct InitializerList* initializerList;
};

struct Statement
{
    int type;
    //union {
        struct LabeledStatement* labeledStatement;
        struct CompoundStatement* compoundStatement;
        struct ExpressionStatement* expressionStatement;
        struct SelectionStatement* selectionStatement;
        struct IterationStatement* iterationStatement;
        struct JumpStatement* jumpStatement;
    //};
};

struct LabeledStatement
{
    int type;
    //union {
        char* identifier;
        struct ConstantExpression* constantExpression;
    //};
    struct Statement* statement;
};

struct CompoundStatement
{
    int type;
    //union {
        struct StatementList* statementList;
        struct DeclarationList* declarationList;
    //};
};

struct DeclarationList
{
    int type;
    struct DeclarationList* declarationList;
    struct Declaration* declaration;
};

struct StatementList
{
    int type;
    struct StatementList* statementList;
    struct Statement* statement;
};

struct ExpressionStatement
{
    int type;
    struct Expression* expression;
};

struct SelectionStatement
{
    int type;
    struct Expression* expression;
    struct Statement *s1, *s2;
};

struct IterationStatement
{
    int type;
    struct ExpressionStatement *s1, *s2;
    struct Expression* expression;
    struct Statement* statement;
};

struct JumpStatement
{
    int type;
    //union {
        char* identifier;
        struct Expression* expression;
    //};
};

struct TranslationUnit
{
    int type;
    struct ExternalDeclaration* externalDeclaration;
    struct TranslationUnit* translationUnit;
};

struct ExternalDeclaration
{
    int type;
    struct FunctionDefinition* functionDefinition;
    struct Declaration* declaration;
};

struct FunctionDefinition
{
    int type;
    struct DeclarationSpecifiers* declarationSpecifiers;
    struct Declarator* declarator;
    struct DeclarationList* declarationList;
    struct CompoundStatement* compoundStatement;
};

#endif