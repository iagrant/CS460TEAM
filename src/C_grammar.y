%{
	#include <stdio.h>
	#include <string.h>
    #include <cstring>
	#include <stdlib.h>
	#include <iostream>

	extern int lineNum;
	extern int tabNum;
	extern int colNum;
	extern bool printToken;
	extern bool printProductions;
	extern bool printSymbol;
	extern bool printFile;
    extern bool printGraphviz;
	extern std::string buffer;
	extern std::string srcFile;
	extern std::string outSrcFile;
    extern SymbolTable globalSymbolTable;
    extern ASTnode *globalASTnode = new ASTnode("translation_unit");;
    std::ofstream fileP;
    void  yyerror(char *msg)
	{
    	std::ifstream srcFileP(srcFile);
	    for (int i = 0; i < lineNum; i++)
	    { std::getline(srcFileP,buffer);
	    }
	    std::cout << "Syntax Error on line " << lineNum << ": " << buffer << std::endl;
	    srcFileP.close();
	    exit(1);
	}
%}
%union {
    ASTnode *node;
    int ival;
    char cval;
    char sval[32];
    double dval;
}

%token <sval> IDENTIFIER
%token <ival> INTEGER_CONSTANT
%token <dval> FLOATING_CONSTANT
%token <cval> CHARACTER_CONSTANT
%token ENUMERATION_CONSTANT
%token <sval> STRING_LITERAL
%token SIZEOF
%token INC_OP DEC_OP
%token LEFT_OP RIGHT_OP
%token LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
%token LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token TYPEDEF_NAME
%token SEMI COLON CURLYOPEN CURLYCLOSE BRACKETOPEN BRACKETCLOSE COMMA PERIOD EQUALS
%token OPEN CLOSE STAR QUESTION BAR CARROT AMP LESS_OP GREAT_OP PLUS MINUS FORSLASH
%token PERCENT BANG TILDA PTR_OP
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELIPSIS RANGE

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token ERROR DEBUG

%type <node> string identifier direct_declarator primary_expression postfix_expression unary_expression constant
%type <node> assignment_expression initializer translation_unit external_declaration function_definition declarator
%type <node> compound_statement init_declarator_list init_declarator declaration declaration_list declaration_specifiers
%type <node> logical_or_expression logical_and_expression inclusive_or_expression exclusive_or_expression shift_expression
%type <node> additive_expression multiplicative_expression cast_expression conditional_expression and_expression
%type <node> equality_expression relational_expression statement statement_list iteration_statement
%type <node> expression expression_statement selection_statement jump_statement labeled_statement
%type <sval> assignment_operator type_specifier

%start translation_unit
%%

translation_unit
	: external_declaration
		{
            globalASTnode->addNode($1);
            if (printProductions) {
                std::cout << "translational_unit -> external_declaration" << std::endl;
            }
            if (printFile) {
                fileP << "translational_unit -> external_declaration" << std::endl;
            }
        }
	| translation_unit external_declaration
		{
            globalASTnode->addNode($1);
            globalASTnode->addNode($2);
            if (printProductions) {
                std::cout << "translational_unit -> translational_unit external_declaration" << std::endl;
            }
            if (printFile) {
                fileP << "translational_unit -> translational_unit external_declaration" << std::endl;
            }
        }
	;

external_declaration
	: function_definition
		{
            $$ = $1;
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "external_declaration -> function definition" << std::endl;
            }
            if (printFile) {
                fileP << "external_declaration -> function definition" << std::endl;
            }
        }
	| declaration
		{
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "external_declaration -> declaration" << std::endl;
            }
            if (printFile) {
                fileP << "external_declaration -> declaration" << std::endl;
            }
        }
	;

function_definition
	: declarator compound_statement
		{
            ASTnode *tmpNode = new ASTnode("FUNCTION");
            tmpNode->addNode($1);
            tmpNode->addNode($2);
            $$ = tmpNode;
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "function_definition -> declarator compound_statment" << std::endl;
            }
            if (printFile) {
                fileP << "function_definition -> declarator compound_statment" << std::endl;
            }
        }
	| declarator declaration_list compound_statement
		{
            ASTnode *tmpNode = new ASTnode("FUNCTION");
            tmpNode->addNode($1);
            tmpNode->addNode($2);
            tmpNode->addNode($3);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "function_defintion -> declarator declaration_list compound_statment" << std::endl;
            }
            if (printFile) {
                fileP << "function_defintion -> declarator declaration_list compound_statment" << std::endl;
            }
        }
	| declaration_specifiers declarator compound_statement
		{
            ASTnode *tmpNode = new ASTnode("FUNCTION");
            tmpNode->addNode($1);
            tmpNode->addNode($2);
            tmpNode->addNode($3);
            $$ = tmpNode;

            if (printProductions) {
                std::cout << "function_definition -> declaration_specifiers declarator compound_statement" << std::endl;
            }
            if (printFile) {
                fileP << "function_definition -> declaration_specifiers declarator compound_statement" << std::endl;
            }
        }
	| declaration_specifiers declarator declaration_list compound_statement
		{
            ASTnode *tmpNode = new ASTnode("FUNCTION");
            tmpNode->addNode($1);
            tmpNode->addNode($2);
            tmpNode->addNode($3);
            tmpNode->addNode($4);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "function_definition -> declaration_specifiers declarator declaration_list compound_statment" << std::endl;
            }
            if (printFile) {
                fileP << "function_definition -> declaration_specifiers declarator declaration_list compound_statment" << std::endl;
            }
        }
	;

declaration
	: declaration_specifiers SEMI
		{
            globalSymbolTable.mode = lookup;
            if (printProductions) {
                std::cout << "declaration -> declaration_specifiers SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "declaration -> declaration_specifiers SEMI" << std::endl;
            }
        }
	| declaration_specifiers init_declarator_list SEMI
		{
            ASTnode *tmpNode = new ASTnode("DECLARATION");
            tmpNode->addNode($1);
            tmpNode->addNode($2);
            $$ = tmpNode;
            globalSymbolTable.mode = lookup;
            if (printProductions) {
                std::cout << "declaration -> declaration_specifiers init_declarator_list SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "declaration -> declaration_specifiers init_declarator_list SEMI" << std::endl;
            }
        }
	;

declaration_list
	: declaration
		{
            $$ = $1;
            globalSymbolTable.mode = lookup;
            if (printProductions) {
                std::cout << "declaration_list -> declaration" << std::endl;
            }
            if (printFile) {
                fileP << "declaration_list -> declaration" << std::endl;
            }
        }
	| declaration_list declaration
		{
            ASTnode *tmpNode = new ASTnode("DECL_LIST");
            tmpNode->addNode($1);
            tmpNode->addNode($2);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "declaration_list -> declaration_list declaration" << std::endl;
            }
            if (printFile) {
                fileP << "declaration_list -> declaration_list declaration" << std::endl;
            }
        }
	;

declaration_specifiers
	: storage_class_specifier
		{
            if (printProductions) {
                std::cout << "declaration_specifiers -> storage_class_specifier" << std::endl;
            }
            if (printFile) {
                fileP << "declaration_specifiers -> storage_class_specifier" << std::endl;
            }
        }
	| storage_class_specifier declaration_specifiers
		{
            if (printProductions) {
                std::cout << "declaration_specifiers -> storage_class_specifier declaration_specifiers" << std::endl;
            }
            if (printFile) {
                fileP << "declaration_specifiers -> storage_class_specifier declaration_specifiers" << std::endl;
            }
        }
	| type_specifier
        {
        ASTnode *tmpNode = new ASTnode($1);
        $$ = tmpNode;
        if (printProductions){
                std::cout << "declaration_specifiers -> type_specifier" << std::endl;}
        if (printFile){
                fileP << "declaration_specifiers -> type_specifier" << std::endl;}
        }
	| type_specifier declaration_specifiers
		{
            if (printProductions) {
                std::cout << "declaration_specifiers -> type_specifier declaration_specifiers" << std::endl;
            }
            if (printFile) {
                fileP << "declaration_specifiers -> type_specifier declaration_specifiers" << std::endl;
            }
        }
	| type_qualifier
		{
            if (printProductions) {
                std::cout << "declaration_specifiers ->  type_qualifier" << std::endl;
            }
            if (printFile) {
                fileP << "declaration_specifiers ->  type_qualifier" << std::endl;
            }
        }
	| type_qualifier declaration_specifiers
		{
            if (printProductions) {
                std::cout << "declaration_specifiers -> type_qualifier declaration_specifiers" << std::endl;
            }
            if (printFile) {
                fileP << "declaration_specifiers -> type_qualifier declaration_specifiers" << std::endl;
            }
        }
	;

storage_class_specifier
	: AUTO
		{
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){globalTempNode.setStorageSpec(autoS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> AUTO" << std::endl;
            }
            if (printFile) {
                fileP << "storage_class_specifier -> AUTO" << std::endl;
            }
        }
	| REGISTER
		{
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){globalTempNode.setStorageSpec(registerS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> REGISTER" << std::endl;
            }
            if (printFile) {
                fileP << "storage_class_specifier -> REGISTER" << std::endl;
            }
        }
	| STATIC
		{
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){globalTempNode.setStorageSpec(staticS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> STATIC" << std::endl;
            }
            if (printFile) {
                fileP << "storage_class_specifier -> STATIC" << std::endl;
            }
        }
	| EXTERN
		{
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){globalTempNode.setStorageSpec(externS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> EXTERN" << std::endl;
            }
            if (printFile) {
                fileP << "storage_class_specifier -> EXTERN" << std::endl;
            }
        }
	| TYPEDEF
		{
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){globalTempNode.setStorageSpec(typedefS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> TYPEDEF" << std::endl;
            }
            if (printFile) {
                fileP << "storage_class_specifier -> TYPEDEF" << std::endl;
            }
        }
	;

type_specifier
	: VOID
		{
            std::strcpy($$, yytext);
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){
                globalTempNode.setTypeSpec(voidS);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_specifier -> VOID" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> VOID" << std::endl;
            }
        }
	| CHAR
		{
            std::strcpy($$, yytext);
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){
                globalTempNode.setTypeSpec(charS);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_specifier -> CHAR" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> CHAR" << std::endl;
            }
        }
	| SHORT
		{
            std::strcpy($$, yytext);
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){
                globalTempNode.setTypeSpec(shortS);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_specifier -> SHORT" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> SHORT" << std::endl;
            }
        }
	| INT
		{
            std::strcpy($$, yytext);
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){
                globalTempNode.setTypeSpec(intS);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_specifier -> INT" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> INT" << std::endl;
            }
        }
	| LONG
		{
            std::strcpy($$, yytext);
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){
                globalTempNode.setTypeSpec(longS);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_specifier -> LONG" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> LONG" << std::endl;
            }
        }
	| FLOAT
		{
            std::strcpy($$, yytext);
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){
                globalTempNode.setTypeSpec(floatS);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_specifier -> FLOAT" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> FLOAT" << std::endl;
            }
        }
	| DOUBLE
		{
            std::strcpy($$, yytext);
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){
                globalTempNode.setTypeSpec(doubleS);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_specifier -> DOUBLE" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> DOUBLE" << std::endl;
            }
        }
	| SIGNED
		{
            std::strcpy($$, yytext);
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){
                globalTempNode.setSigned(signedE);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_specifier -> SIGNED" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> SIGNED" << std::endl;
            }
        }
	| UNSIGNED
		{
            std::strcpy($$, yytext);
            globalSymbolTable.mode = insert;
            if(globalSymbolTable.mode == insert){
                globalTempNode.setSigned(unsignedE);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_specifier -> UNSIGNED" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> UNSIGNED" << std::endl;
            }
        }
	| struct_or_union_specifier
		{
            if (printProductions) {
                std::cout << "type_specifier -> struct_or_union_specifier" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> struct_or_union_specifier" << std::endl;
            }
        }
	| enum_specifier
		{
            if (printProductions) {
                std::cout << "type_specifier -> enum_specifier" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier -> enum_specifier" << std::endl;
            }
        }
	| TYPEDEF_NAME
		{
            if (printProductions) {
                std::cout << "type_specifier ->TYPEDEF_NAME" << std::endl;
            }
            if (printFile) {
                fileP << "type_specifier ->TYPEDEF_NAME" << std::endl;
            }
        }
	;

type_qualifier
	: CONST
		{
            if(globalSymbolTable.mode == insert){
                globalTempNode.setTypeQual(constQ);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_qualifier -> CONST" << std::endl;
            }
            if (printFile) {
                fileP << "type_qualifier -> CONST" << std::endl;
            }
        }
	| VOLATILE
		{
            if(globalSymbolTable.mode == insert){
                globalTempNode.setTypeQual(volatileQ);
                globalTempNode.setLine(lineNum);
            }
            if (printProductions) {
                std::cout << "type_qualifier -> VOLATILE" << std::endl;
            }
            if (printFile) {
                fileP << "type_qualifier -> VOLATILE" << std::endl;
            }
        }
	;

struct_or_union_specifier
	: struct_or_union identifier CURLYOPEN struct_declaration_list CURLYCLOSE
		{
            if (printProductions) {
                std::cout << "struct_or_union_specifier -> struct_or_union identifier CURLYOPEN struct_declaration_list CURLYCLOSE " << std::endl;
            }
            if (printFile) {
                fileP << "struct_or_union_specifier -> struct_or_union identifier CURLYOPEN struct_declaration_list CURLYCLOSE " << std::endl;
            }
        }
	| struct_or_union CURLYOPEN struct_declaration_list CURLYCLOSE
		{
            if (printProductions) {
                std::cout << "struct_or_union_specifier -> struct_or_union CURLYOPEN struct_declaration_list CURLYCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "struct_or_union_specifier -> struct_or_union CURLYOPEN struct_declaration_list CURLYCLOSE" << std::endl;
            }
        }
	| struct_or_union identifier
		{
            if (printProductions) {
                std::cout << "struct_or_union_specifier -> struct_or_union identifier " << std::endl;
            }
            if (printFile) {
                fileP << "struct_or_union_specifier -> struct_or_union identifier " << std::endl;
            }
        }
	;

struct_or_union
	: STRUCT
		{
            if (printProductions) {
                std::cout << "struct_or_union -> STRUCT" << std::endl;
            }
            if (printFile) {
                fileP << "struct_or_union -> STRUCT" << std::endl;
            }
        }
	| UNION
		{
            if (printProductions) {
                std::cout << "struct_or_union -> UNION" << std::endl;
            }
            if (printFile) {
                fileP << "struct_or_union -> UNION" << std::endl;
            }
        }
	;

struct_declaration_list
	: struct_declaration
		{
            if (printProductions) {
                std::cout << "struct_declaration_list -> struct_declaration" << std::endl;
            }
            if (printFile) {
                fileP << "struct_declaration_list -> struct_declaration" << std::endl;
            }
        }
	| struct_declaration_list struct_declaration
		{
            if (printProductions) {
                std::cout << "struct_declaration_list -> struct_declaration_list struct_declaration" << std::endl;
            }
            if (printFile) {
                fileP << "struct_declaration_list -> struct_declaration_list struct_declaration" << std::endl;
            }
        }
	;

init_declarator_list
	: init_declarator
		{
            $$ = $1;
            if (printProductions) {
                std::cout << "init_declarator_list -> init_declarator" << std::endl;
            }
            if (printFile) {
                fileP << "init_declarator_list -> init_declarator" << std::endl;
            }
        }
	| init_declarator_list COMMA init_declarator
		{
            ASTnode* tmpNode = new ASTnode("INIT_DECL_LIST");
            tmpNode->addNode($1);
            tmpNode->addNode($3);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "init_declarator_list -> init_declarator_list" << std::endl;
            }
            if (printFile) {
                fileP << "init_declarator_list -> init_declarator_list" << std::endl;
            }
        }
	;

init_declarator
	: declarator
		{
            $$ = $1;
            if (printProductions) {
                std::cout << "init_declarator -> declarator" << std::endl;
            }
            if (printFile) {
                fileP << "init_declarator -> declarator" << std::endl;
            }
        }
	| declarator EQUALS initializer
		{
            ASTnode *tmpNode = new ASTnode("EQUALS");
            tmpNode->addNode($1);
            tmpNode->addNode($3);
            $$ = tmpNode;

            if (printProductions) {
                std::cout << "init_declarator -> declarator EQUALS initializer" << std::endl;
            }
            if (printFile) {
                fileP << "init_declarator -> declarator EQUALS initializer" << std::endl;
            }
        }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMI
		{
            if (printProductions) {
                std::cout << "struct_declaration -> specifier_qualifier_list struct_declarator_list SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "struct_declaration -> specifier_qualifier_list struct_declarator_list SEMI" << std::endl;
            }
        }
	;

specifier_qualifier_list
	: type_specifier
		{
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_specifier" << std::endl;
            }
            if (printFile) {
                fileP << "specifier_qualifier_list -> type_specifier" << std::endl;
            }
        }
	| type_specifier specifier_qualifier_list
		{
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_specifier specifier_qualifier_list" << std::endl;
            }
            if (printFile) {
                fileP << "specifier_qualifier_list -> type_specifier specifier_qualifier_list" << std::endl;
            }
        }
	| type_qualifier
		{
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_qualifier" << std::endl;
            }
            if (printFile) {
                fileP << "specifier_qualifier_list -> type_qualifier" << std::endl;
            }
        }
	| type_qualifier specifier_qualifier_list
		{
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_qualifier specifier_qualifier_list" << std::endl;
            }
            if (printFile) {
                fileP << "specifier_qualifier_list -> type_qualifier specifier_qualifier_list" << std::endl;
            }
        }
	;

struct_declarator_list
	: struct_declarator
		{
            if (printProductions) {
                std::cout << "struct_declarator_list -> struct_declarator" << std::endl;
            }
            if (printFile) {
                fileP << "struct_declarator_list -> struct_declarator" << std::endl;
            }
        }
	| struct_declarator_list COMMA struct_declarator
		{
            if (printProductions) {
                std::cout << "struct_declarator_list -> struct_declarator_list COMMA struct_declarator" << std::endl;
            }
            if (printFile) {
                fileP << "struct_declarator_list -> struct_declarator_list COMMA struct_declarator" << std::endl;
            }
        }
	;

struct_declarator
	: declarator
		{
            if (printProductions) {
                std::cout << "struct_declarator -> declarator" << std::endl;
            }
            if (printFile) {
                fileP << "struct_declarator -> declarator" << std::endl;
            }
        }
	| COLON constant_expression
		{
            if (printProductions) {
                std::cout << "struct_declarator -> COLON constant_expression" << std::endl;
            }
            if (printFile) {
                fileP << "struct_declarator -> COLON constant_expression" << std::endl;
            }
        }
	| declarator COLON constant_expression
		{
            if (printProductions) {
                std::cout << "struct_declarator -> declarator COLON constant_expression" << std::endl;
            }
            if (printFile) {
                fileP << "struct_declarator -> declarator COLON constant_expression" << std::endl;
            }
        }
	;

enum_specifier
	: ENUM CURLYOPEN enumerator_list CURLYCLOSE
		{
            if (printProductions) {
                std::cout << "enum_specifier -> ENUM CURLYOPEN enumerator_list CURLYCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "enum_specifier -> ENUM CURLYOPEN enumerator_list CURLYCLOSE" << std::endl;
            }
        }
	| ENUM identifier CURLYOPEN enumerator_list CURLYCLOSE
		{
            if (printProductions) {
                std::cout << "enum_specifier -> ENUM identifier CURLYOPEN enumerator_list CURLYCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "enum_specifier -> ENUM identifier CURLYOPEN enumerator_list CURLYCLOSE" << std::endl;
            }
        }
	| ENUM identifier
		{
            if (printProductions) {
                std::cout << "enum_specifier -> ENUM identifier" << std::endl;
            }
            if (printFile) {
                fileP << "enum_specifier -> ENUM identifier" << std::endl;
            }
        }
	;

enumerator_list
	: enumerator
        {
            if (printProductions) {
                std::cout << "enumerator_list -> enumerator" << std::endl;
            }
            if (printFile) {
                fileP << "enumerator_list -> enumerator" << std::endl;
            }
        }
	| enumerator_list COMMA enumerator
        {
            if (printProductions) {
                std::cout << "enumerator_list -> enumerator_list COMMA enumerator" << std::endl;
            }
            if (printFile) {
                fileP << "enumerator_list -> enumerator_list COMMA enumerator" << std::endl;
            }
        }
	;

enumerator
	: identifier
        {
            if (printProductions) {
                std::cout << "enumerator -> identifier" << std::endl;
            }
            if (printFile) {
                fileP << "enumerator -> identifier" << std::endl;
            }
        }
	| identifier EQUALS constant_expression
        {
            if (printProductions) {
                std::cout << "enumerator -> identifier EQUALS constant_expression" << std::endl;
            }
            if (printFile) {
                fileP << "enumerator -> identifier EQUALS constant_expression" << std::endl;
            }
        }
	;

declarator
	: direct_declarator
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "declarator -> direct_declarator" << std::endl;
            }
            if (printFile) {
                fileP << "declarator -> direct_declarator" << std::endl;
            }
        }
	| pointer direct_declarator
        {
            if (printProductions) {
                std::cout << "declarator -> pointer direct_declarator" << std::endl;
            }
            if (printFile) {
                fileP << "declarator -> pointer direct_declarator" << std::endl;
            }
        }
	;

direct_declarator
	: identifier
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "direct_declarator -> identifier" << std::endl;
            }
            if (printFile) {
                fileP << "direct_declarator -> identifier" << std::endl;
            }
        }
	| OPEN declarator CLOSE
        {
            if (printProductions) {
                std::cout << "direct_declarator -> OPEN declarator CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_declarator -> OPEN declarator CLOSE" << std::endl;
            }
        }
	| direct_declarator BRACKETOPEN BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_declarator -> direct_declarator BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
        }
	| direct_declarator BRACKETOPEN constant_expression BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_declarator -> direct_declarator BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
        }
	| direct_declarator OPEN CLOSE
        {
            globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator OPEN CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_declarator -> direct_declarator OPEN CLOSE" << std::endl;
            }
        }
	| direct_declarator OPEN parameter_type_list CLOSE
        {
            globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator OPEN parameter_type_list CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_declarator -> direct_declarator OPEN parameter_type_list CLOSE" << std::endl;
            }
        }
	| direct_declarator OPEN identifier_list CLOSE
        {
            std::cout << "The compiler does not support this feature" << std::endl;
            exit(1);
            if (printProductions) {
                std::cout << "direct_declarator ->  direct_declarator OPEN identifier_list CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_declarator ->  direct_declarator OPEN identifier_list CLOSE" << std::endl;
            }
        }
	;

pointer
	: STAR
        {
            if (printProductions) {
                std::cout << "pointer -> STAR" << std::endl;
            }
            if (printFile) {
                fileP << "pointer -> STAR" << std::endl;
            }
        }
	| STAR type_qualifier_list
        {
            if (printProductions) {
                std::cout << "pointer -> STAR type_qualifier_list" << std::endl;
            }
            if (printFile) {
                fileP << "pointer -> STAR type_qualifier_list" << std::endl;
            }
        }
	| STAR pointer
        {
            if (printProductions) {
                std::cout << "pointer -> STAR pointer" << std::endl;
            }
            if (printFile) {
                fileP << "pointer -> STAR pointer" << std::endl;
            }
        }
	| STAR type_qualifier_list pointer
        {
            if (printProductions) {
                std::cout << "pointer -> STAR type_qualifier_list pointer" << std::endl;
            }
            if (printFile) {
                fileP << "pointer -> STAR type_qualifier_list pointer" << std::endl;
            }
        }
	;

type_qualifier_list
	: type_qualifier
        {
            if (printProductions) {
                std::cout << "type_qualifier_list -> type_qualifier" << std::endl;
            }
            if (printFile) {
                fileP << "type_qualifier_list -> type_qualifier" << std::endl;
            }
        }
	| type_qualifier_list type_qualifier
        {
            if (printProductions) {
                std::cout << "type_qualifier_list -> type_qualifier_list type_qualifier" << std::endl;
            }
            if (printFile) {
                fileP << "type_qualifier_list -> type_qualifier_list type_qualifier" << std::endl;
            }
        }
	;

parameter_type_list
	: parameter_list
        {
            if (printProductions) {
                std::cout << "parameter_type_list -> parameter_list" << std::endl;
            }
            if (printFile) {
                fileP << "parameter_type_list -> parameter_list" << std::endl;
            }
        }
	| parameter_list COMMA ELIPSIS
        {
            if (printProductions) {
                std::cout << "parameter_type_list -> parameter_list COMMA ELIPSIS" << std::endl;
            }
            if (printFile) {
                fileP << "parameter_type_list -> parameter_list COMMA ELIPSIS" << std::endl;
            }
        }
	;

parameter_list
	: parameter_declaration
        {
            if (printProductions) {
                std::cout << "parameter_list -> parameter_declaration" << std::endl;
            }
            if (printFile) {
                fileP << "parameter_list -> parameter_declaration" << std::endl;
            }
        }
	| parameter_list COMMA parameter_declaration
        {
            if (printProductions) {
                std::cout << "parameter_list -> parameter_list COMMA parameter_declaration" << std::endl;
            }
            if (printFile) {
                fileP << "parameter_list -> parameter_list COMMA parameter_declaration" << std::endl;
            }
        }
	;

parameter_declaration
	: declaration_specifiers declarator
        {
            if (printProductions) {
                std::cout << "parameter_declaration -> declaration_specifiers declarator" << std::endl;
            }
            if (printFile) {
                fileP << "parameter_declaration -> declaration_specifiers declarator" << std::endl;
            }
        }
	| declaration_specifiers
        {
            if (printProductions) {
                std::cout << "parameter_declaration -> declaration_specifiers" << std::endl;
            }
            if (printFile) {
                fileP << "parameter_declaration -> declaration_specifiers" << std::endl;
            }
        }
	| declaration_specifiers abstract_declarator
        {
            if (printProductions) {
                std::cout << "parameter_declaration -> declaration_specifiers abstract_declarator" << std::endl;
            }
            if (printFile) {
                fileP << "parameter_declaration -> declaration_specifiers abstract_declarator" << std::endl;
            }
        }
	;

identifier_list
	: identifier
        {
            if (printProductions) {
                std::cout << "identifier_list -> identifier" << std::endl;
            }
            if (printFile) {
                fileP << "identifier_list -> identifier" << std::endl;
            }
        }
	| identifier_list COMMA identifier
        {
            if (printProductions) {
                std::cout << "identifier_list -> identifier_list COMMA identifier" << std::endl;
            }
            if (printFile) {
                fileP << "identifier_list -> identifier_list COMMA identifier" << std::endl;
            }
        }
	;

initializer
	: assignment_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "initializer -> assignment_expression" << std::endl;
            }
            if (printFile) {
                fileP << "initializer -> assignment_expression" << std::endl;
            }
        }
	| CURLYOPEN initializer_list CURLYCLOSE
        {
            if (printProductions) {
                std::cout << "initializer -> CURLYOPEN initializer_list CURLYCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "initializer -> CURLYOPEN initializer_list CURLYCLOSE" << std::endl;
            }
        }
	| CURLYOPEN initializer_list COMMA CURLYCLOSE
        {
            if (printProductions) {
                std::cout << "initializer -> CURLYOPEN initializer_list COMMA CURLYCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "initializer -> CURLYOPEN initializer_list COMMA CURLYCLOSE" << std::endl;
            }
        }
	;

initializer_list
	: initializer
        {
            if (printProductions) {
                std::cout << "initializer_list -> initializer" << std::endl;
            }
            if (printFile) {
                fileP << "initializer_list -> initializer" << std::endl;
            }
        }
	| initializer_list COMMA initializer
        {
            if (printProductions) {
                std::cout << "initializer_list -> initializer_list COMMA initializer" << std::endl;
            }
            if (printFile) {
                fileP << "initializer_list -> initializer_list COMMA initializer" << std::endl;
            }
        }
	;

type_name
	: specifier_qualifier_list
        {
            if (printProductions) {
                std::cout << "type_name -> specifier_qualifier_list" << std::endl;
            }
            if (printFile) {
                fileP << "type_name -> specifier_qualifier_list" << std::endl;
            }
        }
	| specifier_qualifier_list abstract_declarator
        {
            if (printProductions) {
                std::cout << "type_name -> specifier_qualifier_list abstract_declarator" << std::endl;
            }
            if (printFile) {
                fileP << "type_name -> specifier_qualifier_list abstract_declarator" << std::endl;
            }
        }
	;

abstract_declarator
	: pointer
        {
            if (printProductions) {
                std::cout << "abstract_declarator -> pointer" << std::endl;
            }
            if (printFile) {
                fileP << "abstract_declarator -> pointer" << std::endl;
            }
        }
	| direct_abstract_declarator
        {
            if (printProductions) {
                std::cout << "abstract_declarator -> direct_abstract_declarator" << std::endl;
            }
            if (printFile) {
                fileP << "abstract_declarator -> direct_abstract_declarator" << std::endl;
            }
        }
	| pointer direct_abstract_declarator
        {
            if (printProductions) {
                std::cout << "abstract_declarator -> pointer direct_abstract_declarator" << std::endl;
            }
            if (printFile) {
                fileP << "abstract_declarator -> pointer direct_abstract_declarator" << std::endl;
            }
        }
	;

direct_abstract_declarator
	: OPEN abstract_declarator CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> OPEN abstract_declarator CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_abstract_declarator -> OPEN abstract_declarator CLOSE" << std::endl;
            }
        }
	| BRACKETOPEN BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_abstract_declarator -> BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
        }
	| BRACKETOPEN constant_expression BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_abstract_declarator -> BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
        }
	| direct_abstract_declarator BRACKETOPEN BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_abstract_declarator -> direct_abstract_declarator BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
        }
	| direct_abstract_declarator BRACKETOPEN constant_expression BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_abstract_declarator -> direct_abstract_declarator BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
        }
	| OPEN CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> OPEN CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_abstract_declarator -> OPEN CLOSE" << std::endl;
            }
        }
	| OPEN parameter_type_list CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> OPEN parameter_type_list CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_abstract_declarator -> OPEN parameter_type_list CLOSE" << std::endl;
            }
        }
	| direct_abstract_declarator OPEN CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator OPEN CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_abstract_declarator -> direct_abstract_declarator OPEN CLOSE" << std::endl;
            }
        }
	| direct_abstract_declarator OPEN parameter_type_list CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator OPEN parameter_type_list CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "direct_abstract_declarator -> direct_abstract_declarator OPEN parameter_type_list CLOSE" << std::endl;
            }
        }
	;

statement
	: labeled_statement
        {
            $$ =$1;
            if (printProductions) {
                std::cout << "statement -> labeled_statement" << std::endl;
            }
            if (printFile) {
                fileP << "statement -> labeled_statement" << std::endl;
            }
        }
	| compound_statement
        {
            $$ =$1;
            if (printProductions) {
                std::cout << "statement -> compound_statement" << std::endl;
            }
            if (printFile) {
                fileP << "statement -> compound_statement" << std::endl;
            }
        }
	| expression_statement
        {
            $$ =$1;
            if (printProductions) {
                std::cout << "statement -> expression_statement" << std::endl;
            }
            if (printFile) {
                fileP << "statement -> expression_statement" << std::endl;
            }
        }
	| selection_statement
        {
            $$ =$1;
            if (printProductions) {
                std::cout << "statement -> selection_statement" << std::endl;
            }
            if (printFile) {
                fileP << "statement -> selection_statement" << std::endl;
            }
        }
	| iteration_statement
        {
            $$ = $1;
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "statement -> iteration_statement" << std::endl;
            }
            if (printFile) {
                fileP << "statement -> iteration_statement" << std::endl;
            }
        }
	| jump_statement
        {
            $$ =$1;
            if (printProductions) {
                std::cout << "statement -> jump_statement" << std::endl;
            }
            if (printFile) {
                fileP << "statement -> jump_statement" << std::endl;
            }
        }
	;

labeled_statement
	: identifier COLON statement
        {
            std::cout << "This compiler does not support this feature" << std::endl;
            exit(1);
            if (printProductions) {
                std::cout << "labeled_statement -> identifier COLON statement" << std::endl;
            }
            if (printFile) {
                fileP << "labeled_statement -> identifier COLON statement" << std::endl;
            }
        }
	| CASE constant_expression COLON statement
        {
            if (printProductions) {
                std::cout << "labeled_statement -> CASE constant_expression COLON statement" << std::endl;
            }
            if (printFile) {
                fileP << "labeled_statement -> CASE constant_expression COLON statement" << std::endl;
            }
        }
	| DEFAULT COLON statement
        {
            if (printProductions) {
                std::cout << "labeled_statement -> DEFAULT COLON statement" << std::endl;
            }
            if (printFile) {
                fileP << "labeled_statement -> DEFAULT COLON statement" << std::endl;
            }
        }
	;

expression_statement
	: SEMI
        {
            if (printProductions) {
                std::cout << "expression_statement -> SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "expression_statement -> SEMI" << std::endl;
            }
        }
	| expression SEMI
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "expression_statement -> expression SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "expression_statement -> expression SEMI" << std::endl;
            }
        }
	;

compound_statement
	: CURLYOPEN CURLYCLOSE
        {
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN CURLYCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "compound_statement -> CURLYOPEN CURLYCLOSE" << std::endl;
            }
        }
	| CURLYOPEN statement_list CURLYCLOSE
        {
            $$ = $2;
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN statement_list CURLYCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "compound_statement -> CURLYOPEN statement_list CURLYCLOSE" << std::endl;
            }
        }
	| CURLYOPEN declaration_list CURLYCLOSE
        {
            $$ = $2;
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN declaration_list CURLYCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "compound_statement -> CURLYOPEN declaration_list CURLYCLOSE" << std::endl;
            }
        }
	| CURLYOPEN declaration_list statement_list CURLYCLOSE
        {
            ASTnode *tmpNode = new ASTnode("COMPOUND_STATEMENT");
            tmpNode->addNode($2);
            tmpNode->addNode($3);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN declaration_list statement_list CURLYCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "compound_statement -> CURLYOPEN declaration_list statement_list CURLYCLOSE" << std::endl;
            }
        }
	;

statement_list
	: statement
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "statement_list -> statement" << std::endl;
            }
            if (printFile) {
                fileP << "statement_list -> statement" << std::endl;
            }
        }
	| statement_list statement
        {
            if (printProductions) {
                std::cout << "statement_list -> statement_list statement" << std::endl;
            }
            if (printFile) {
                fileP << "statement_list -> statement_list statement" << std::endl;
            }
        }
	;

selection_statement
	: IF OPEN expression CLOSE statement
        {
            ifNode *parentNode = new ifNode("IF_STATEMENT");
            parentNode->addNode($3);
            parentNode->addNode($5);
            $$ = parentNode;

            if (printProductions) {
                std::cout << "selection_statement -> IF OPEN expression CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "selection_statement -> IF OPEN expression CLOSE statement" << std::endl;
            }
        }
	| IF OPEN expression CLOSE statement ELSE statement
        {
            ifNode *parentNode = new ifNode("IF_ELSE_STATEMENT");
            parentNode->addNode($3);
            parentNode->addNode($5);
            parentNode->addNode($7);
            $$ = parentNode;
            if (printProductions) {
                std::cout << "selection_statement -> IF OPEN expression CLOSE statement ELSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "selection_statement -> IF OPEN expression CLOSE statement ELSE statement" << std::endl;
            }
        }
	| SWITCH OPEN expression CLOSE statement
        {
            if (printProductions) {
                std::cout << "selection_statement -> SWITCH OPEN expression CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "selection_statement -> SWITCH OPEN expression CLOSE statement" << std::endl;
            }
        }
	;

iteration_statement
	: WHILE OPEN expression CLOSE statement
        {
            if ($5 != NULL) {
                ASTnode* tmpNode = new ASTnode("WHILE");
                tmpNode -> addNode($3);
                tmpNode -> addNode($5);
                $$ = tmpNode;
            }
            else {
                ASTnode* tmpNode = new ASTnode("WHILE");
                tmpNode -> addNode($3);
                $$ = tmpNode;
            }
            if (printProductions) {
                std::cout << "iteration_statement -> WHILE OPEN expression CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> WHILE OPEN expression CLOSE statement" << std::endl;
            }
        }
	| DO statement WHILE OPEN expression CLOSE SEMI
        {
            if (printProductions) {
                std::cout << "iteration_statement -> DO statement WHILE OPEN expression CLOSE SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> DO statement WHILE OPEN expression CLOSE SEMI" << std::endl;
            }
        }
	| FOR OPEN SEMI SEMI CLOSE statement
        {
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI SEMI CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> FOR OPEN SEMI SEMI CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN SEMI SEMI expression CLOSE statement
        {
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI SEMI expression CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> FOR OPEN SEMI SEMI expression CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN SEMI expression SEMI CLOSE statement
        {
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI expression SEMI CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> FOR OPEN SEMI expression SEMI CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN SEMI expression SEMI expression CLOSE statement
        {
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI expression SEMI expression CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> FOR OPEN SEMI expression SEMI expression CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN expression SEMI SEMI CLOSE statement
        {
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI SEMI CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> FOR OPEN expression SEMI SEMI CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN expression SEMI SEMI expression CLOSE statement
        {
            //globalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI SEMI expression CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> FOR OPEN expression SEMI SEMI expression CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN expression SEMI expression SEMI CLOSE statement
        {
            //obalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI expression SEMI CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> FOR OPEN expression SEMI expression SEMI CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN expression SEMI expression SEMI expression CLOSE statement
        {
            //obalSymbolTable.addNewScope();
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI expression SEMI expression CLOSE statement" << std::endl;
            }
            if (printFile) {
                fileP << "iteration_statement -> FOR OPEN expression SEMI expression SEMI expression CLOSE statement" << std::endl;
            }
        }
	;

//where u rem scope
jump_statement
	: GOTO identifier SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> GOTO identifier SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "jump_statement -> GOTO identifier SEMI" << std::endl;
            }
        }
	| CONTINUE SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> CONTINUE SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "jump_statement -> CONTINUE SEMI" << std::endl;
            }
        }
	| BREAK SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> BREAK SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "jump_statement -> BREAK SEMI" << std::endl;
            }
        }
	| RETURN SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> RETURN SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "jump_statement -> RETURN SEMI" << std::endl;
            }
        }
	| RETURN expression SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> RETURN expression SEMI" << std::endl;
            }
            if (printFile) {
                fileP << "jump_statement -> RETURN expression SEMI" << std::endl;
            }
        }
	;

expression
	: assignment_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "expression -> assignment_expression" << std::endl;
            }
            if (printFile) {
                fileP << "expression -> assignment_expression" << std::endl;
            }
        }
	| expression COMMA assignment_expression
        {
            if (printProductions) {
                std::cout << "expression -> expression COMMA assignment_expression" << std::endl;
            }
            if (printFile) {
                fileP << "expression -> expression COMMA assignment_expression" << std::endl;
            }
        }
	;

assignment_expression
	: conditional_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "assignment_expression -> conditional_expression" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_expression -> conditional_expression" << std::endl;
            }
        }
	| unary_expression assignment_operator assignment_expression
        {
            ASTnode *assignmentNode = new ASTnode($2);
            assignmentNode->addNode($1);
            assignmentNode->addNode($3);
            $$ = assignmentNode;
            if (printProductions) {
                std::cout << "assignment_expression -> unary_expression assignment_operator assignment_expression" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_expression -> unary_expression assignment_operator assignment_expression" << std::endl;
            }
        }
	;

assignment_operator
	: EQUALS
        {
            std::strcpy($$, "EQUALS");
            if (printProductions) {
                std::cout << "assignment_operator -> EQUALS" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> EQUALS" << std::endl;
            }
        }
	| MUL_ASSIGN
        {
            std::strcpy($$, "MUL_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> MUL_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> MUL_ASSIGN" << std::endl;
            }
        }
	| DIV_ASSIGN
        {
            std::strcpy($$, "DIV_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> DIV_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> DIV_ASSIGN" << std::endl;
            }
        }
	| MOD_ASSIGN
        {
            std::strcpy($$, "MOD_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> MOD_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> MOD_ASSIGN" << std::endl;
            }
        }
	| ADD_ASSIGN
        {
            std::strcpy($$, "ADD_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> ADD_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> ADD_ASSIGN" << std::endl;
            }
        }
	| SUB_ASSIGN
        {
            std::strcpy($$, "SUB_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> SUB_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> SUB_ASSIGN" << std::endl;
            }
        }
	| LEFT_ASSIGN
        {
            std::strcpy($$, "LEFT_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> LEFT_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> LEFT_ASSIGN" << std::endl;
            }
        }
	| RIGHT_ASSIGN
        {
            std::strcpy($$, "RIGHT_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> RIGHT_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> RIGHT_ASSIGN" << std::endl;
            }
        }
	| AND_ASSIGN
        {
            std::strcpy($$, "AND_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> AND_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> AND_ASSIGN" << std::endl;
            }
        }
	| XOR_ASSIGN
        {
            std::strcpy($$, "XOR_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> XOR_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> XOR_ASSIGN" << std::endl;
            }
        }
	| OR_ASSIGN
        {
            std::strcpy($$, "OR_ASSIGN");
            if (printProductions) {
                std::cout << "assignment_operator -> OR_ASSIGN" << std::endl;
            }
            if (printFile) {
                fileP << "assignment_operator -> OR_ASSIGN" << std::endl;
            }
        }
	;

conditional_expression
	: logical_or_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "conditional_expression -> logical_or_expression" << std::endl;
            }
            if (printFile) {
                fileP << "conditional_expression -> logical_or_expression" << std::endl;
            }
        }
	| logical_or_expression QUESTION expression COLON conditional_expression
        {
            if (printProductions) {
                std::cout << "conditional_expression -> logical_or_expression QUESTION expression COLON conditional_expression" << std::endl;
            }
            if (printFile) {
                fileP << "conditional_expression -> logical_or_expression QUESTION expression COLON conditional_expression" << std::endl;
            }
        }
	;

constant_expression
	: conditional_expression
        {
            if (printProductions) {
                std::cout << "constant_expression -> conditional_expression" << std::endl;
            }
            if (printFile) {
                fileP << "constant_expression -> conditional_expression" << std::endl;
            }
        }
	;

logical_or_expression
	: logical_and_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "logical_or_expression -> logical_and_expression" << std::endl;
            }
            if (printFile) {
                fileP << "logical_or_expression -> logical_and_expression" << std::endl;
            }
        }
	| logical_or_expression OR_OP logical_and_expression
        {
            if (printProductions) {
                std::cout << "logical_or_expression -> logical_or_expression OR_OP logical_and_expression" << std::endl;
            }
            if (printFile) {
                fileP << "logical_or_expression -> logical_or_expression OR_OP logical_and_expression" << std::endl;
            }
        }
	;

logical_and_expression
	: inclusive_or_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "logical_and_expression -> inclusive_or_expression" << std::endl;
            }
            if (printFile) {
                fileP << "logical_and_expression -> inclusive_or_expression" << std::endl;
            }
        }
	| logical_and_expression AND_OP inclusive_or_expression
        {
            if (printProductions) {
                std::cout << "logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression" << std::endl;
            }
            if (printFile) {
                fileP << "logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression" << std::endl;
            }
        }
	;

inclusive_or_expression
	: exclusive_or_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "inclusive_or_expression -> exclusive_or_expression" << std::endl;
            }
            if (printFile) {
                fileP << "inclusive_or_expression -> exclusive_or_expression" << std::endl;
            }
        }
	| inclusive_or_expression BAR exclusive_or_expression
        {
            if (printProductions) {
                std::cout << "inclusive_or_expression -> inclusive_or_expression BAR exclusive_or_expression" << std::endl;
            }
            if (printFile) {
                fileP << "inclusive_or_expression -> inclusive_or_expression BAR exclusive_or_expression" << std::endl;
            }
        }
	;

exclusive_or_expression
	: and_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "exclusive_or_expression -> and_expression" << std::endl;
            }
            if (printFile) {
                fileP << "exclusive_or_expression -> and_expression" << std::endl;
            }
        }
	| exclusive_or_expression CARROT and_expression
        {
            if (printProductions) {
                std::cout << "exclusive_or_expression -> exclusive_or_expression CARROT and_expression" << std::endl;
            }
            if (printFile) {
                fileP << "exclusive_or_expression -> exclusive_or_expression CARROT and_expression" << std::endl;
            }
        }
	;

and_expression
	: equality_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "and_expression -> equality_expression" << std::endl;
            }
            if (printFile) {
                fileP << "and_expression -> equality_expression" << std::endl;
            }
        }
	| and_expression AMP equality_expression
        {
            if (printProductions) {
                std::cout << "and_expression -> and_expression AMP equality_expression" << std::endl;
            }
            if (printFile) {
                fileP << "and_expression -> and_expression AMP equality_expression" << std::endl;
            }
        }
	;

equality_expression
	: relational_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "equality_expression -> relational_expression" << std::endl;
            }
            if (printFile) {
                fileP << "equality_expression -> relational_expression" << std::endl;
            }
        }
	| equality_expression EQ_OP relational_expression
        {
            if (printProductions) {
                std::cout << "equality_expression -> equality_expression EQ_OP relational_expression" << std::endl;
            }
            if (printFile) {
                fileP << "equality_expression -> equality_expression EQ_OP relational_expression" << std::endl;
            }
        }
	| equality_expression NE_OP relational_expression
		{
			if (printProductions) {
				std::cout << "equality_expression -> equality_expression NE_OP relational_expression" << std::endl;
			}
			if (printFile) {
				fileP << "equality_expression -> equality_expression NE_OP relational_expression" << std::endl;
			}
		}
	;

relational_expression
	: shift_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "relational_expression -> shift_expression" << std::endl;
            }
            if (printFile) {
                fileP << "relational_expression -> shift_expression" << std::endl;
            }
        }
	| relational_expression LESS_OP shift_expression
        {
            ASTnode* tmpNode = new ASTnode("LESS_OP");
            tmpNode -> addNode($1);
            tmpNode -> addNode($3);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression LESS_OP shift_expression" << std::endl;
            }
            if (printFile) {
                fileP << "relational_expression -> relational_expression LESS_OP shift_expression" << std::endl;
            }
        }
	| relational_expression GREAT_OP shift_expression
        {
            ASTnode* tmpNode = new ASTnode("GREAT_OP");
            tmpNode -> addNode($1);
            tmpNode -> addNode($3);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression GREAT_OP shift_expression" << std::endl;
            }
            if (printFile) {
                fileP << "relational_expression -> relational_expression GREAT_OP shift_expression" << std::endl;
            }
        }
	| relational_expression LE_OP shift_expression
        {
            ASTnode* tmpNode = new ASTnode("LE_OP");
            tmpNode -> addNode($1);
            tmpNode -> addNode($3);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression LE_OP shift_expression" << std::endl;
            }
            if (printFile) {
                fileP << "relational_expression -> relational_expression LE_OP shift_expression" << std::endl;
            }
        }
	| relational_expression GE_OP shift_expression
        {
            ASTnode* tmpNode = new ASTnode("GE_OP");
            tmpNode -> addNode($1);
            tmpNode -> addNode($3);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression GE_OP shift_expression" << std::endl;
            }
            if (printFile) {
                fileP << "relational_expression -> relational_expression GE_OP shift_expression" << std::endl;
            }
        }
	;

shift_expression
	: additive_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "shift_expression -> additive_expression" << std::endl;
            }
            if (printFile) {
                fileP << "shift_expression -> additive_expression" << std::endl;
            }
        }
	| shift_expression LEFT_OP additive_expression
        {
            if (printProductions) {
                std::cout << "shift_expression -> shift_expression LEFT_OP additive_expression" << std::endl;
            }
            if (printFile) {
                fileP << "shift_expression -> shift_expression LEFT_OP additive_expression" << std::endl;
            }
        }
	| shift_expression RIGHT_OP additive_expression
        {
            if (printProductions) {
                std::cout << "shift_expression -> shift_expression RIGHT_OP additive_expression" << std::endl;
            }
            if (printFile) {
                fileP << "shift_expression -> shift_expression RIGHT_OP additive_expression" << std::endl;
            }
        }
	;

additive_expression
	: multiplicative_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "additive_expression -> multiplicative_expression" << std::endl;
            }
            if (printFile) {
                fileP << "additive_expression -> multiplicative_expression" << std::endl;
            }
        }
	| additive_expression PLUS multiplicative_expression
        {
            ASTnode tmpNode("+");
            if (printProductions) {
                std::cout << "additive_expression -> additive_expression PLUS multiplicative_expression" << std::endl;
            }
            if (printFile) {
                fileP << "additive_expression -> additive_expression PLUS multiplicative_expression" << std::endl;
            }
        }
	| additive_expression MINUS multiplicative_expression
        {
            ASTnode tmpNode("-");
            if (printProductions) {
                std::cout << "additive_expression -> additive_expression MINUS multiplicative_expression" << std::endl;
            }
            if (printFile) {
                fileP << "additive_expression -> additive_expression MINUS multiplicative_expression" << std::endl;
            }
        }
	;

multiplicative_expression
	: cast_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "multiplicative_expression -> cast_expression" << std::endl;
            }
            if (printFile) {
                fileP << "multiplicative_expression -> cast_expression" << std::endl;
            }
        }
	| multiplicative_expression STAR cast_expression
        {
            if (printProductions) {
                std::cout << "multiplicative_expression -> multiplicative_expression STAR cast_expression" << std::endl;
            }
            if (printFile) {
                fileP << "multiplicative_expression -> multiplicative_expression STAR cast_expression" << std::endl;
            }
        }
	| multiplicative_expression FORSLASH cast_expression
        {
            if (printProductions) {
                std::cout << "multiplicative_expression -> multiplicative_expression FORSLASH cast_expression" << std::endl;
            }
            if (printFile) {
                fileP << "multiplicative_expression -> multiplicative_expression FORSLASH cast_expression" << std::endl;
            }
        }
	| multiplicative_expression PERCENT cast_expression
        {
            if (printProductions) {
                std::cout << "multiplicative_expression -> multiplicative_expression PERCENT cast_expression" << std::endl;
            }
            if (printFile) {
                fileP << "multiplicative_expression -> multiplicative_expression PERCENT cast_expression" << std::endl;
            }
        }
	;

cast_expression
	: unary_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "cast_expression -> unary_expression" << std::endl;
            }
            if (printFile) {
                fileP << "cast_expression -> unary_expression" << std::endl;
            }
        }
	| OPEN type_name CLOSE cast_expression
        {
            if (printProductions) {
                std::cout << "cast_expression -> OPEN type_name CLOSE cast_expression" << std::endl;
            }
            if (printFile) {
                fileP << "cast_expression -> OPEN type_name CLOSE cast_expression" << std::endl;
            }
        }
	;

unary_expression
	: postfix_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "unary_expression -> postfix_expression" << std::endl;
            }
            if (printFile) {
                fileP << "unary_expression -> postfix_expression" << std::endl;
            }
        }
	| INC_OP unary_expression
        {
            if (printProductions) {
                std::cout << "unary_expression -> INC_OP unary_expression" << std::endl;
            }
            if (printFile) {
                fileP << "unary_expression -> INC_OP unary_expression" << std::endl;
            }
        }
	| DEC_OP unary_expression
        {
            if (printProductions) {
                std::cout << "unary_expression -> DEC_OP unary_expression" << std::endl;
            }
            if (printFile) {
                fileP << "unary_expression -> DEC_OP unary_expression" << std::endl;
            }
        }
	| unary_operator cast_expression
        {
            if (printProductions) {
                std::cout << "unary_expression -> unary_operator cast_expression" << std::endl;
            }
            if (printFile) {
                fileP << "unary_expression -> unary_operator cast_expression" << std::endl;
            }
        }
	| SIZEOF unary_expression
        {
            if (printProductions) {
                std::cout << "unary_expression -> SIZEOF unary_expression" << std::endl;
            }
            if (printFile) {
                fileP << "unary_expression -> SIZEOF unary_expression" << std::endl;
            }
        }
	| SIZEOF OPEN type_name CLOSE
        {
            if (printProductions) {
                std::cout << "unary_expression -> SIZEOF OPEN type_name CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "unary_expression -> SIZEOF OPEN type_name CLOSE" << std::endl;
            }
        }
	;

unary_operator
	: AMP
        {
            if (printProductions) {
                std::cout << "unary_operator -> AMP" << std::endl;
            }
            if (printFile) {
                fileP << "unary_operator -> AMP" << std::endl;
            }
        }
	| STAR
        {
            if (printProductions) {
                std::cout << "unary_operator -> STAR" << std::endl;
            }
            if (printFile) {
                fileP << "unary_operator -> STAR" << std::endl;
            }
        }
	| PLUS
        {
            if (printProductions) {
                std::cout << "unary_operator -> PLUS" << std::endl;
            }
            if (printFile) {
                fileP << "unary_operator -> PLUS" << std::endl;
            }
        }
	| MINUS
        {
            if (printProductions) {
                std::cout << "unary_operator -> MINUS" << std::endl;
            }
            if (printFile) {
                fileP << "unary_operator -> MINUS" << std::endl;
            }
        }
	| TILDA
        {
            if (printProductions) {
                std::cout << "unary_operator -> TILDA" << std::endl;
            }
            if (printFile) {
                fileP << "unary_operator -> TILDA" << std::endl;
            }
        }
	| BANG
        {
            if (printProductions) {
                std::cout << "unary_operator -> BANG" << std::endl;
            }
            if (printFile) {
                fileP << "unary_operator -> BANG" << std::endl;
            }
        }
	;

postfix_expression
	: primary_expression
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "postfix_expression -> primary_expression" << std::endl;
            }
            if (printFile) {
                fileP << "postfix_expression -> primary_expression" << std::endl;
            }
        }
	| postfix_expression BRACKETOPEN expression BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression BRACKETOPEN expression BRACKETCLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "postfix_expression -> postfix_expression BRACKETOPEN expression BRACKETCLOSE" << std::endl;
            }
        }
	| postfix_expression OPEN CLOSE
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression OPEN CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "postfix_expression -> postfix_expression OPEN CLOSE" << std::endl;
            }
        }
	| postfix_expression OPEN argument_expression_list CLOSE
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression OPEN argument_expression_list CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "postfix_expression -> postfix_expression OPEN argument_expression_list CLOSE" << std::endl;
            }
        }
	| postfix_expression PERIOD identifier
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression PERIOD identifier" << std::endl;
            }
            if (printFile) {
                fileP << "postfix_expression -> postfix_expression PERIOD identifier" << std::endl;
            }
        }
	| postfix_expression PTR_OP identifier
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression PTR_OP identifier" << std::endl;
            }
            if (printFile) {
                fileP << "postfix_expression -> postfix_expression PTR_OP identifier" << std::endl;
            }
        }
	| postfix_expression INC_OP
        {
            ASTnode *parentNode = new ASTnode("POSTFIX_EXPRESSION");
            ASTnode *incNode = new ASTnode("INC_OP");
            parentNode->addNode($1);
            parentNode->addNode(incNode);
            $$ = parentNode;

            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression INC_OP" << std::endl;
            }
            if (printFile) {
                fileP << "postfix_expression -> postfix_expression INC_OP" << std::endl;
            }
        }
	| postfix_expression DEC_OP
        {
            ASTnode *parentNode = new ASTnode("POSTFIX_EXPRESSION");
            ASTnode *incNode = new ASTnode("DEC_OP");
            parentNode->addNode($1);
            parentNode->addNode(incNode);
            $$ = parentNode;
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression DEC_OP" << std::endl;
            }
            if (printFile) {
                fileP << "postfix_expression -> postfix_expression DEC_OP" << std::endl;
            }
        }
	;

primary_expression
	: identifier
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "primary_expression -> identifier" << std::endl;
            }
            if (printFile) {
                fileP << "primary_expression -> identifier" << std::endl;
            }
        }
	| constant
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "primary_expression -> constant" << std::endl;
            }
            if (printFile) {
                fileP << "primary_expression -> constant" << std::endl;
            }
        }
	| string
        {
            $$ = $1;
            if (printProductions) {
                std::cout << "primary_expression -> string" << std::endl;
            }
            if (printFile) {
                fileP << "primary_expression -> string" << std::endl;
            }
        }
	| OPEN expression CLOSE
        {
            if (printProductions) {
                std::cout << "primary_expression -> OPEN expression CLOSE" << std::endl;
            }
            if (printFile) {
                fileP << "primary_expression -> OPEN expression CLOSE" << std::endl;
            }
        }
	;

argument_expression_list
	: assignment_expression
        {
            if (printProductions) {
                std::cout << "argument_expression_list -> assignment_expression" << std::endl;
            }
            if (printFile) {
                fileP << "argument_expression_list -> assignment_expression" << std::endl;
            }
        }
	| argument_expression_list COMMA assignment_expression
        {
            if (printProductions) {
                std::cout << "argument_expression_list -> argument_expression_list COMMA assignment_expression" << std::endl;
            }
            if (printFile) {
                fileP << "argument_expression_list -> argument_expression_list COMMA assignment_expression" << std::endl;
            }
        }
	;

constant
	: INTEGER_CONSTANT
        {
            constantNode *tmpNode = new constantNode("INTEGER_CONSTANT");
            tmpNode->intConst = std::stoi(yytext);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "constant -> INTEGER_CONSTANT" << std::endl;
            }
            if (printFile) {
                fileP << "constant -> INTEGER_CONSTANT" << std::endl;
            }
        }
	| CHARACTER_CONSTANT
        {
            constantNode *tmpNode = new constantNode("CHARACTER_CONSTANT");
            tmpNode->charConst = yytext[0];
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "constant -> CHARACTER_CONSTANT" << std::endl;
            }
            if (printFile) {
                fileP << "constant -> CHARACTER_CONSTANT" << std::endl;
            }
        }
	| FLOATING_CONSTANT
        {
            constantNode *tmpNode = new constantNode("FLOATING_CONSTANT");
            tmpNode->doubleConst = std::stof(yytext);
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "constant -> FLOATING_CONSTANT" << std::endl;
            }
            if (printFile) {
                fileP << "constant -> FLOATING_CONSTANT" << std::endl;
            }
        }
	| ENUMERATION_CONSTANT
        {
            if (printProductions) {
                std::cout << "constant -> ENUMERATION_CONSTANT" << std::endl;
            }
            if (printFile) {
                fileP << "constant -> ENUMERATION_CONSTANT" << std::endl;
            }
        }
	;

string
	: STRING_LITERAL
        {
            constantNode *tmpNode = new constantNode("STRING_LITERAL");
            tmpNode->stringConst = yytext+'\0';
            $$ = tmpNode;
            if (printProductions) {
                std::cout << "string -> STRING_LITERAL" << std::endl;
            }
            if (printFile) {
                fileP << "string -> STRING_LITERAL" << std::endl;
            }
        }
	;

identifier
	: IDENTIFIER
        {

            idNode * tmpNode = new idNode("IDENTIFIER");
            tmpNode->name = yytext;
            $$ = tmpNode;
            globalTempNode.setName(yytext+'\0');
            //std::cout << "ID" << std::endl;
            //globalTempNode.printNode();
            globalTempNode.setScope(globalSymbolTable.currentScopeNum);
            if(globalSymbolTable.mode==insert){
                globalSymbolTable.insertSymbol(globalTempNode);
            }
            if(globalSymbolTable.mode==lookup){
                globalSymbolTable.searchTree(globalTempNode);
                //globalSymbolTable.searchPrevScopes(globalTempNode);
            }
            //globalTempNode.resetNode();
            if (printProductions) {
                std::cout << "identifier -> IDENTIFIER" << std::endl;
            }
            if (printFile) {
                fileP << "identifier -> IDENTIFIER" << std::endl;
            }
        }
	;
%%
extern int column;

int main (int argc, char** argv)
{
    std::string tokenFlag = "-dl";
	std::string symbolFlag = "-ds";
	std::string productionFlag = "-dp";
    std::string graphFlag = "-dg";
	std::string fhFlag = "-fh";
    std::string inputFlag = "-i";
    std::string outputFlag = "-o";
	FILE* inputStream;
    extern std::string srcFile;
    extern std::string outSrcFile;
    extern std::string buffer;

    if(argc == 1)
    {
        std::cout << "Usage: ./fcc -i <inputfile.c>" << std::endl;
    }

  // Check command line args for debug symbols
  for (int i = 0; i < argc; i++) {
    if((tokenFlag.compare(argv[i])) == 0)
    {
      printToken = true;
    }
    if((symbolFlag.compare(argv[i])) == 0)
    {
      // Dump the symbol table
    }
    if((fhFlag.compare(argv[i])) == 0)
    {
      unleash();
    }
    if((graphFlag.compare(argv[i])) == 0)
    {
        printGraphviz = true;
    }
    if ((productionFlag.compare(argv[i])) == 0)
    {
      printLine();
      printProductions = true;
      printSource = true;
    }
    if ((inputFlag.compare(argv[i]))==0)
    {
      if (i+1 < argc)
      {
        srcFile = argv[++i];
        int n = srcFile.length();
        char inputFile[n+1];
        strcpy(inputFile,srcFile.c_str());
        inputStream = fopen(inputFile,"r");
      }
      else
      {
        std::cout << "ERROR: PLEASE SPECIFIY A SRC CODE FILE AFTER -i" << std::endl;
        return 0;
      }
    }
    if ((outputFlag.compare(argv[i]))==0)
    {
      if (i+1 < argc)
      {
        outSrcFile = argv[++i];
      }
      else
      {
        std::cout << "ERROR: PLEASE SPECIFIY A SRC CODE FILE AFTER -o" << std::endl;
        return 0;
      }
    }
  }



  yyin = inputStream;
  astFileP << "digraph AST {" << std::endl;
  fileP.open(outSrcFile);
  yyparse();
  printSubTree(globalASTnode);
  astFileP << "}" << std::endl;
  fclose(inputStream);
//  astFileP << "";
  astFileP.close();
  fileP.close();

  return 0;
}
