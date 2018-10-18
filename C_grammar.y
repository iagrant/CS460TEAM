%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <iostream>

	extern int lineNum;
	extern int tabNum;
	extern int colNum;
	extern bool printToken;
	extern bool printProductions;
	extern bool printSymbol;
	extern bool printFile;
	extern std::string buffer;
	extern std::string srcFile;
	extern std::string outSrcFile;
    extern SymbolTable globalSymbolTable;
    extern Node globalTempNode;
	void  yyerror(char *msg)
	{
    	std::ifstream srcFileP(srcFile);
	    for (int i = 0; i < lineNum; i++)
	    {
	        std::getline(srcFileP,buffer);
	    }
	    std::cout << "Syntax Error on line " << lineNum << ": " << buffer << std::endl;
	    srcFileP.close();
	    exit(1);
	}
%}
%union {
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

%type <sval> string identifier
%type <ival> declaration declaration_specifiers type_specifier

%start translation_unit
%%

translation_unit
	: external_declaration
		{
            if (printProductions) {
                std::cout << "translational_unit -> external_declaration" << std::endl;
            }
        }
	| translation_unit external_declaration
		{
            if (printProductions) {
                std::cout << "translational_unit -> translational_unit external_declaration" << std::endl;
            }
        }
	;

external_declaration
	: function_definition
		{
            if (printProductions) {
                std::cout << "external_declaration -> function definition" << std::endl;
            }
        }
	| declaration
		{
            if (printProductions) {
                std::cout << "external_declaration -> declaration" << std::endl;
            }
        }
	;

function_definition
	: declarator compound_statement
		{
            if (printProductions) {
                std::cout << "function_definition -> declarator compound_statment" << std::endl;
            }
        }
	| declarator declaration_list compound_statement
		{
            if (printProductions) {
                std::cout << "function_defintion -> declarator declaration_list compound_statment" << std::endl;
            }
        }
	| declaration_specifiers declarator compound_statement
		{
            if (printProductions) {
                std::cout << "function_definition -> declaration_specifiers declarator compound_statement" << std::endl;
            }
        }
	| declaration_specifiers declarator declaration_list compound_statement
		{
            if (printProductions) {
                std::cout << "function_definition -> declaration_specifiers declarator declaration_list compound_statment" << std::endl;
            }
        }
	;

declaration
	: declaration_specifiers SEMI
		{
            if (printProductions) {
                std::cout << "declaration -> declaration_specifiers SEMI" << std::endl;
            }
        }
	| declaration_specifiers init_declarator_list SEMI
		{
            std::cout << $1 << "FUCK " << std::endl;
            if (printProductions) {
                std::cout << "declaration -> declaration_specifiers init_declarator_list SEMI" << std::endl;
            }
        }
	;

declaration_list
	: declaration
		{
            if (printProductions) {
                std::cout << "declaration_list -> declaration" << std::endl;
            }
        }
	| declaration_list declaration
		{
            if (printProductions) {
                std::cout << "declaration_list -> declaration list declaration" << std::endl;
            }
        }
	;

declaration_specifiers
	: storage_class_specifier
		{
            if (printProductions) {
                std::cout << "declaration_specifiers -> storage_class_specifier" << std::endl;
            }
        }
	| storage_class_specifier declaration_specifiers
		{
            if (printProductions) {
                std::cout << "declaration_specifiers -> storage_class_specifier declaration_specifiers" << std::endl;
            }
        }
	| type_specifier
        {
        if (printProductions){
                std::cout << "declaration_specifiers -> type_specifier" << std::endl;}
        }
	| type_specifier declaration_specifiers
		{
            if (printProductions) {
                std::cout << "declaration_specifiers -> type_specifier declaration_specifiers" << std::endl;
            }
        }
	| type_qualifier
		{
            if (printProductions) {
                std::cout << "declaration_specifiers ->  type_qualifier" << std::endl;
            }
        }
	| type_qualifier declaration_specifiers
		{
            if (printProductions) {
                std::cout << "declaration_specifiers -> type_qualifier declaration_specifiers" << std::endl;
            }
        }
	;

storage_class_specifier
	: AUTO
		{
            if(mode == insert){globalTempNode.setStorageSpec(autoS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> AUTO" << std::endl;
            }
        }
	| REGISTER
		{
            if(mode == insert){globalTempNode.setStorageSpec(registerS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> REGISTER" << std::endl;
            }
        }
	| STATIC
		{
            if(mode == insert){globalTempNode.setStorageSpec(staticS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> STATIC" << std::endl;
            }
        }
	| EXTERN
		{
            if(mode == insert){globalTempNode.setStorageSpec(externS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> EXTERN" << std::endl;
            }
        }
	| TYPEDEF
		{
            if(mode == insert){globalTempNode.setStorageSpec(typedefS);}
            if (printProductions) {
                std::cout << "storage_class_specifier -> TYPEDEF" << std::endl;
            }
        }
	;

type_specifier
	: VOID
		{
            if(mode == insert){globalTempNode.setTypeSpec(voidS);}
            if (printProductions) {
                std::cout << "type_specifier -> VOID" << std::endl;
            }
        }
	| CHAR
		{
            if(mode == insert){globalTempNode.setTypeSpec(charS);}
            if (printProductions) {
                std::cout << "type_specifier -> CHAR" << std::endl;
            }
        }
	| SHORT
		{
            if(mode == insert){globalTempNode.setTypeSpec(shortS);}
            if (printProductions) {
                std::cout << "type_specifier -> SHORT" << std::endl;
            }
        }
	| INT
		{
            if(mode == insert){globalTempNode.setTypeSpec(intS);}
            if (printProductions) {
                std::cout << "type_specifier -> INT" << std::endl;
            }
        }
	| LONG
		{
            if(mode == insert){globalTempNode.setTypeSpec(longS);}
            if (printProductions) {
                std::cout << "type_specifier -> LONG" << std::endl;
            }
        }
	| FLOAT
		{
            if(mode == insert){globalTempNode.setTypeSpec(floatS);}
            if (printProductions) {
                std::cout << "type_specifier -> FLOAT" << std::endl;
            }
        }
	| DOUBLE
		{
            if(mode == insert){globalTempNode.setTypeSpec(doubleS);}
            if (printProductions) {
                std::cout << "type_specifier -> DOUBLE" << std::endl;
            }
        }
	| SIGNED
		{
            if(mode == insert){globalTempNode.setSigned(signedE);}
            if (printProductions) {
                std::cout << "type_specifier -> SIGNED" << std::endl;
            }
        }
	| UNSIGNED
		{
            if(mode == insert){globalTempNode.setSigned(unsignedE);}
            if (printProductions) {
                std::cout << "type_specifier -> UNSIGNED" << std::endl;
            }
        }
	| struct_or_union_specifier
		{
            if (printProductions) {
                std::cout << "type_specifier -> struct_or_union_specifier" << std::endl;
            }
        }
	| enum_specifier
		{
            if (printProductions) {
                std::cout << "type_specifier -> enum_specifier" << std::endl;
            }
        }
	| TYPEDEF_NAME
		{
            if (printProductions) {
                std::cout << "type_specifier ->TYPEDEF_NAME" << std::endl;
            }
        }
	;

type_qualifier
	: CONST
		{
            if(mode == insert){globalTempNode.setTypeQual(constQ);}
            if (printProductions) {
                std::cout << "type_qualifier -> CONST" << std::endl;
            }
        }
	| VOLATILE
		{
            if(mode == insert){globalTempNode.setTypeQual(volatileQ);}
            if (printProductions) {
                std::cout << "type_qualifier -> VOLATILE" << std::endl;
            }
        }
	;

struct_or_union_specifier
	: struct_or_union identifier CURLYOPEN struct_declaration_list CURLYCLOSE
		{
            if (printProductions) {
                std::cout << "struct_or_union_specifier -> struct_or_union identifier CURLYOPEN struct_declaration_list CURLYCLOSE " << std::endl;
            }
        }
	| struct_or_union CURLYOPEN struct_declaration_list CURLYCLOSE
		{
            if (printProductions) {
                std::cout << "struct_or_union_specifier -> struct_or_union CURLYOPEN struct_declaration_list CURLYCLOSE" << std::endl;
            }
        }
	| struct_or_union identifier
		{
            if (printProductions) {
                std::cout << "struct_or_union_specifier -> struct_or_union identifier " << std::endl;
            }
        }
	;

struct_or_union
	: STRUCT
		{
            if (printProductions) {
                std::cout << "struct_or_union -> STRUCT" << std::endl;
            }
        }
	| UNION
		{
            if (printProductions) {
                std::cout << "struct_or_union -> UNION" << std::endl;
            }
        }
	;

struct_declaration_list
	: struct_declaration
		{
            if (printProductions) {
                std::cout << "struct_declaration_list -> struct_declaration" << std::endl;
            }
        }
	| struct_declaration_list struct_declaration
		{
            if (printProductions) {
                std::cout << "struct_declaration_list -> struct_declaration_list struct_declaration" << std::endl;
            }
        }
	;

init_declarator_list
	: init_declarator
		{
            if (printProductions) {
                std::cout << "init_declarator_list -> init_declarator" << std::endl;
            }
        }
	| init_declarator_list COMMA init_declarator
		{
            if (printProductions) {
                std::cout << "init_declarator_list -> init_declarator_list" << std::endl;
            }
        }
	;

init_declarator
	: declarator
		{
            if (printProductions) {
                std::cout << "init_declarator -> declarator" << std::endl;
            }
        }
	| declarator EQUALS initializer
		{
            if (printProductions) {
                std::cout << "init_declarator -> declarator EQUALS initializer" << std::endl;
            }
        }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMI
		{
            if (printProductions) {
                std::cout << "struct_declaration -> specifier_qualifier_list struct_declarator_list SEMI" << std::endl;
            }
        }
	;

specifier_qualifier_list
	: type_specifier
		{
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_specifier" << std::endl;
            }
        }
	| type_specifier specifier_qualifier_list
		{
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_specifier specifier_qualifier_list" << std::endl;
            }
        }
	| type_qualifier
		{
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_qualifier" << std::endl;
            }
        }
	| type_qualifier specifier_qualifier_list
		{
            if (printProductions) {
                std::cout << "specifier_qualifier_list -> type_qualifier specifier_qualifier_list" << std::endl;
            }
        }
	;

struct_declarator_list
	: struct_declarator
		{
            if (printProductions) {
                std::cout << "struct_declarator_list -> struct_declarator" << std::endl;
            }
        }
	| struct_declarator_list COMMA struct_declarator
		{
            if (printProductions) {
                std::cout << "struct_declarator_list -> struct_declarator_list COMMA struct_declarator" << std::endl;
            }
        }
	;

struct_declarator
	: declarator
		{
            if (printProductions) {
                std::cout << "struct_declarator -> declarator" << std::endl;
            }
        }
	| COLON constant_expression
		{
            if (printProductions) {
                std::cout << "struct_declarator -> COLON constant_expression" << std::endl;
            }
        }
	| declarator COLON constant_expression
		{
            if (printProductions) {
                std::cout << "struct_declarator -> declarator COLON constant_expression" << std::endl;
            }
        }
	;

enum_specifier
	: ENUM CURLYOPEN enumerator_list CURLYCLOSE
		{
            if (printProductions) {
                std::cout << "enum_specifier -> ENUM CURLYOPEN enumerator_list CURLYCLOSE" << std::endl;
            }
        }
	| ENUM identifier CURLYOPEN enumerator_list CURLYCLOSE
		{
            if (printProductions) {
                std::cout << "enum_specifier -> ENUM identifier CURLYOPEN enumerator_list CURLYCLOSE" << std::endl;
            }
        }
	| ENUM identifier
		{
            if (printProductions) {
                std::cout << "enum_specifier -> ENUM identifier" << std::endl;
            }
        }
	;

enumerator_list
	: enumerator
        {
            if (printProductions) {
                std::cout << "enumerator_list -> enumerator" << std::endl;
            }
        }
	| enumerator_list COMMA enumerator
        {
            if (printProductions) {
                std::cout << "enumerator_list -> enumerator_list COMMA enumerator" << std::endl;
            }
        }
	;

enumerator
	: identifier
        {
            if (printProductions) {
                std::cout << "enumerator -> identifier" << std::endl;
            }
        }
	| identifier EQUALS constant_expression
        {
            if (printProductions) {
                std::cout << "enumerator -> identifier EQUALS constant_expression" << std::endl;
            }
        }
	;

declarator
	: direct_declarator
        {
            if (printProductions) {
                std::cout << "declarator -> direct_declarator" << std::endl;
            }
        }
	| pointer direct_declarator
        {
            if (printProductions) {
                std::cout << "declarator -> pointer direct_declarator" << std::endl;
            }
        }
	;

direct_declarator
	: identifier
        {
            if (printProductions) {
                std::cout << "direct_declarator -> identifier" << std::endl;
            }
        }
	| OPEN declarator CLOSE
        {
            if (printProductions) {
                std::cout << "direct_declarator -> OPEN declarator CLOSE" << std::endl;
            }
        }
	| direct_declarator BRACKETOPEN BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
        }
	| direct_declarator BRACKETOPEN constant_expression BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
        }
	| direct_declarator OPEN CLOSE
        {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator OPEN CLOSE" << std::endl;
            }
        }
	| direct_declarator OPEN parameter_type_list CLOSE
        {
            if (printProductions) {
                std::cout << "direct_declarator -> direct_declarator OPEN parameter_type_list CLOSE" << std::endl;
            }
        }
	| direct_declarator OPEN identifier_list CLOSE
        {
            if (printProductions) {
                std::cout << "direct_declarator ->  direct_declarator OPEN identifier_list CLOSE" << std::endl;
            }
        }
	;

pointer
	: STAR
        {
            if (printProductions) {
                std::cout << "pointer -> STAR" << std::endl;
            }
        }
	| STAR type_qualifier_list
        {
            if (printProductions) {
                std::cout << "pointer -> STAR type_qualifier_list" << std::endl;
            }
        }
	| STAR pointer
        {
            if (printProductions) {
                std::cout << "pointer -> STAR pointer" << std::endl;
            }
        }
	| STAR type_qualifier_list pointer
        {
            if (printProductions) {
                std::cout << "pointer -> STAR type_qualifier_list pointer" << std::endl;
            }
        }
	;

type_qualifier_list
	: type_qualifier
        {
            if (printProductions) {
                std::cout << "type_qualifier_list -> type_qualifier" << std::endl;
            }
        }
	| type_qualifier_list type_qualifier
        {
            if (printProductions) {
                std::cout << "type_qualifier_list -> type_qualifier_list type_qualifier" << std::endl;
            }
        }
	;

parameter_type_list
	: parameter_list
        {
            if (printProductions) {
                std::cout << "parameter_type_list -> parameter_list" << std::endl;
            }
        }
	| parameter_list COMMA ELIPSIS
        {
            if (printProductions) {
                std::cout << "parameter_type_list -> parameter_list COMMA ELIPSIS" << std::endl;
            }
        }
	;

parameter_list
	: parameter_declaration
        {
            if (printProductions) {
                std::cout << "parameter_list -> parameter_declaration" << std::endl;
            }
        }
	| parameter_list COMMA parameter_declaration
        {
            if (printProductions) {
                std::cout << "parameter_list -> parameter_list COMMA parameter_declaration" << std::endl;
            }
        }
	;

parameter_declaration
	: declaration_specifiers declarator
        {
            if (printProductions) {
                std::cout << "parameter_declaration -> declaration_specifiers declarator" << std::endl;
            }
        }
	| declaration_specifiers
        {
            if (printProductions) {
                std::cout << "parameter_declaration -> declaration_specifiers" << std::endl;
            }
        }
	| declaration_specifiers abstract_declarator
        {
            if (printProductions) {
                std::cout << "parameter_declaration -> declaration_specifiers abstract_declarator" << std::endl;
            }
        }
	;

identifier_list
	: identifier
        {
            if (printProductions) {
                std::cout << "identifier_list -> identifier" << std::endl;
            }
        }
	| identifier_list COMMA identifier
        {
            if (printProductions) {
                std::cout << "identifier_list -> identifier_list COMMA identifier" << std::endl;
            }
        }
	;

initializer
	: assignment_expression
        {
            if (printProductions) {
                std::cout << "initializer -> assignment_expression" << std::endl;
            }
        }
	| CURLYOPEN initializer_list CURLYCLOSE
        {
            if (printProductions) {
                std::cout << "initializer -> CURLYOPEN initializer_list CURLYCLOSE" << std::endl;
            }
        }
	| CURLYOPEN initializer_list COMMA CURLYCLOSE
        {
            if (printProductions) {
                std::cout << "initializer -> CURLYOPEN initializer_list COMMA CURLYCLOSE" << std::endl;
            }
        }
	;

initializer_list
	: initializer
        {
            if (printProductions) {
                std::cout << "initializer_list -> initializer" << std::endl;
            }
        }
	| initializer_list COMMA initializer
        {
            if (printProductions) {
                std::cout << "initializer_list -> initializer_list COMMA initializer" << std::endl;
            }
        }
	;

type_name
	: specifier_qualifier_list
        {
            if (printProductions) {
                std::cout << "type_name -> specifier_qualifier_list" << std::endl;
            }
        }
	| specifier_qualifier_list abstract_declarator
        {
            if (printProductions) {
                std::cout << "type_name -> specifier_qualifier_list abstract_declarator" << std::endl;
            }
        }
	;

abstract_declarator
	: pointer
        {
            if (printProductions) {
                std::cout << "abstract_declarator -> pointer" << std::endl;
            }
        }
	| direct_abstract_declarator
        {
            if (printProductions) {
                std::cout << "abstract_declarator -> direct_abstract_declarator" << std::endl;
            }
        }
	| pointer direct_abstract_declarator
        {
            if (printProductions) {
                std::cout << "abstract_declarator -> pointer direct_abstract_declarator" << std::endl;
            }
        }
	;

direct_abstract_declarator
	: OPEN abstract_declarator CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> OPEN abstract_declarator CLOSE" << std::endl;
            }
        }
	| BRACKETOPEN BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
        }
	| BRACKETOPEN constant_expression BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
        }
	| direct_abstract_declarator BRACKETOPEN BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator BRACKETOPEN BRACKETCLOSE" << std::endl;
            }
        }
	| direct_abstract_declarator BRACKETOPEN constant_expression BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator BRACKETOPEN constant_expression BRACKETCLOSE" << std::endl;
            }
        }
	| OPEN CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> OPEN CLOSE" << std::endl;
            }
        }
	| OPEN parameter_type_list CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> OPEN parameter_type_list CLOSE" << std::endl;
            }
        }
	| direct_abstract_declarator OPEN CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator OPEN CLOSE" << std::endl;
            }
        }
	| direct_abstract_declarator OPEN parameter_type_list CLOSE
        {
            if (printProductions) {
                std::cout << "direct_abstract_declarator -> direct_abstract_declarator OPEN parameter_type_list CLOSE" << std::endl;
            }
        }
	;

statement
	: labeled_statement
        {
            if (printProductions) {
                std::cout << "statement -> labeled_statement" << std::endl;
            }
        }
	| compound_statement
        {
            if (printProductions) {
                std::cout << "statement -> compound_statement" << std::endl;
            }
        }
	| expression_statement
        {
            if (printProductions) {
                std::cout << "statement -> expression_statement" << std::endl;
            }
        }
	| selection_statement
        {
            if (printProductions) {
                std::cout << "statement -> selection_statement" << std::endl;
            }
        }
	| iteration_statement
        {
            if (printProductions) {
                std::cout << "statement -> iteration_statement" << std::endl;
            }
        }
	| jump_statement
        {
            if (printProductions) {
                std::cout << "statement -> jump_statement" << std::endl;
            }
        }
	;

labeled_statement
	: identifier COLON statement
        {
            if (printProductions) {
                std::cout << "labeled_statement -> identifier COLON statement" << std::endl;
            }
        }
	| CASE constant_expression COLON statement
        {
            if (printProductions) {
                std::cout << "labeled_statement -> CASE constant_expression COLON statement" << std::endl;
            }
        }
	| DEFAULT COLON statement
        {
            if (printProductions) {
                std::cout << "labeled_statement -> DEFAULT COLON statement" << std::endl;
            }
        }
	;

expression_statement
	: SEMI
        {
            if (printProductions) {
                std::cout << "expression_statement -> SEMI" << std::endl;
            }
        }
	| expression SEMI
        {
            if (printProductions) {
                std::cout << "expression_statement -> expression SEMI" << std::endl;
            }
        }
	;

compound_statement
	: CURLYOPEN CURLYCLOSE
        {
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN CURLYCLOSE" << std::endl;
            }
        }
	| CURLYOPEN statement_list CURLYCLOSE
        {
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN statement_list CURLYCLOSE" << std::endl;
            }
        }
	| CURLYOPEN declaration_list CURLYCLOSE
        {
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN declaration_list CURLYCLOSE" << std::endl;
            }
        }
	| CURLYOPEN declaration_list statement_list CURLYCLOSE
        {
            if (printProductions) {
                std::cout << "compound_statement -> CURLYOPEN declaration_list statement_list CURLYCLOSE" << std::endl;
            }
        }
	;

statement_list
	: statement
        {
            if (printProductions) {
                std::cout << "statement_list -> statement" << std::endl;
            }
        }
	| statement_list statement
        {
            if (printProductions) {
                std::cout << "statement_list -> statement_list statement" << std::endl;
            }
        }
	;

selection_statement
	: IF OPEN expression CLOSE statement
        {
            if (printProductions) {
                std::cout << "selection_statement -> IF OPEN expression CLOSE statement" << std::endl;
            }
        }
	| IF OPEN expression CLOSE statement ELSE statement
        {
            if (printProductions) {
                std::cout << "selection_statement -> IF OPEN expression CLOSE statement ELSE statement" << std::endl;
            }
        }
	| SWITCH OPEN expression CLOSE statement
        {
            if (printProductions) {
                std::cout << "selection_statement -> SWITCH OPEN expression CLOSE statement" << std::endl;
            }
        }
	;

iteration_statement
	: WHILE OPEN expression CLOSE statement
        {
            if (printProductions) {
                std::cout << "iteration_statement -> WHILE OPEN expression CLOSE statement" << std::endl;
            }
        }
	| DO statement WHILE OPEN expression CLOSE SEMI
        {
            if (printProductions) {
                std::cout << "iteration_statement -> DO statement WHILE OPEN expression CLOSE SEMI" << std::endl;
            }
        }
	| FOR OPEN SEMI SEMI CLOSE statement
        {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI SEMI CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN SEMI SEMI expression CLOSE statement
        {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI SEMI expression CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN SEMI expression SEMI CLOSE statement
        {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI expression SEMI CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN SEMI expression SEMI expression CLOSE statement
        {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN SEMI expression SEMI expression CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN expression SEMI SEMI CLOSE statement
        {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI SEMI CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN expression SEMI SEMI expression CLOSE statement
        {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI SEMI expression CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN expression SEMI expression SEMI CLOSE statement
        {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI expression SEMI CLOSE statement" << std::endl;
            }
        }
	| FOR OPEN expression SEMI expression SEMI expression CLOSE statement
        {
            if (printProductions) {
                std::cout << "iteration_statement -> FOR OPEN expression SEMI expression SEMI expression CLOSE statement" << std::endl;
            }
        }
	;

jump_statement
	: GOTO identifier SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> GOTO identifier SEMI" << std::endl;
            }
        }
	| CONTINUE SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> CONTINUE SEMI" << std::endl;
            }
        }
	| BREAK SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> BREAK SEMI" << std::endl;
            }
        }
	| RETURN SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> RETURN SEMI" << std::endl;
            }
        }
	| RETURN expression SEMI
        {
            if (printProductions) {
                std::cout << "jump_statement -> RETURN expression SEMI" << std::endl;
            }
        }
	;

expression
	: assignment_expression
        {
            if (printProductions) {
                std::cout << "expression -> assignment_expression" << std::endl;
            }
        }
	| expression COMMA assignment_expression
        {
            if (printProductions) {
                std::cout << "expression -> expression COMMA assignment_expression" << std::endl;
            }
        }
	;

assignment_expression
	: conditional_expression
        {
            if (printProductions) {
                std::cout << "assignment_expression -> conditional_expression" << std::endl;
            }
        }
	| unary_expression assignment_operator assignment_expression
        {
            if (printProductions) {
                std::cout << "assignment_expression -> unary_expression assignment_operator assignment_expression" << std::endl;
            }
        }
	;

assignment_operator
	: EQUALS
        {
            if (printProductions) {
                std::cout << "assignment_operator -> EQUALS" << std::endl;
            }
        }
	| MUL_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> MUL_ASSIGN" << std::endl;
            }
        }
	| DIV_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> DIV_ASSIGN" << std::endl;
            }
        }
	| MOD_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> MOD_ASSIGN" << std::endl;
            }
        }
	| ADD_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> ADD_ASSIGN" << std::endl;
            }
        }
	| SUB_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> SUB_ASSIGN" << std::endl;
            }
        }
	| LEFT_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> LEFT_ASSIGN" << std::endl;
            }
        }
	| RIGHT_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> RIGHT_ASSIGN" << std::endl;
            }
        }
	| AND_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> AND_ASSIGN" << std::endl;
            }
        }
	| XOR_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> XOR_ASSIGN" << std::endl;
            }
        }
	| OR_ASSIGN
        {
            if (printProductions) {
                std::cout << "assignment_operator -> OR_ASSIGN" << std::endl;
            }
        }
	;

conditional_expression
	: logical_or_expression
        {
            if (printProductions) {
                std::cout << "conditional_expression -> logical_or_expression" << std::endl;
            }
        }
	| logical_or_expression QUESTION expression COLON conditional_expression
        {
            if (printProductions) {
                std::cout << "conditional_expression -> logical_or_expression QUESTION expression COLON conditional_expression" << std::endl;
            }
        }
	;

constant_expression
	: conditional_expression
        {
            if (printProductions) {
                std::cout << "constant_expression -> conditional_expression" << std::endl;
            }
        }
	;

logical_or_expression
	: logical_and_expression
        {
            if (printProductions) {
                std::cout << "logical_or_expression -> logical_and_expression" << std::endl;
            }
        }
	| logical_or_expression OR_OP logical_and_expression
        {
            if (printProductions) {
                std::cout << "logical_or_expression -> logical_or_expression OR_OP logical_and_expression" << std::endl;
            }
        }
	;

logical_and_expression
	: inclusive_or_expression
        {
            if (printProductions) {
                std::cout << "logical_and_expression -> inclusive_or_expression" << std::endl;
            }
        }
	| logical_and_expression AND_OP inclusive_or_expression
        {
            if (printProductions) {
                std::cout << "logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression" << std::endl;
            }
        }
	;

inclusive_or_expression
	: exclusive_or_expression
        {
            if (printProductions) {
                std::cout << "inclusive_or_expression -> exclusive_or_expression" << std::endl;
            }
        }
	| inclusive_or_expression BAR exclusive_or_expression
        {
            if (printProductions) {
                std::cout << "inclusive_or_expression -> inclusive_or_expression BAR exclusive_or_expression" << std::endl;
            }
        }
	;

exclusive_or_expression
	: and_expression
        {
            if (printProductions) {
                std::cout << "exclusive_or_expression -> and_expression" << std::endl;
            }
        }
	| exclusive_or_expression CARROT and_expression
        {
            if (printProductions) {
                std::cout << "exclusive_or_expression -> exclusive_or_expression CARROT and_expression" << std::endl;
            }
        }
	;

and_expression
	: equality_expression
        {
            if (printProductions) {
                std::cout << "and_expression -> equality_expression" << std::endl;
            }
        }
	| and_expression AMP equality_expression
        {
            if (printProductions) {
                std::cout << "and_expression -> and_expression AMP equality_expression" << std::endl;
            }
        }
	;

equality_expression
	: relational_expression
        {
            if (printProductions) {
                std::cout << "equality_expression -> relational_expression" << std::endl;
            }
        }
	| equality_expression EQ_OP relational_expression
        {
            if (printProductions) {
                std::cout << "equality_expression -> equality_expression EQ_OP relational_expression" << std::endl;
            }
        }
	| equality_expression NE_OP relational_expression
		{
			if (printProductions) {
				std::cout << "equality_expression -> equality_expression NE_OP relational_expression" << std::endl;
			}
		}
	;

relational_expression
	: shift_expression
        {
            if (printProductions) {
                std::cout << "relational_expression -> shift_expression" << std::endl;
            }
        }
	| relational_expression LESS_OP shift_expression
        {
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression LESS_OP shift_expression" << std::endl;
            }
        }
	| relational_expression GREAT_OP shift_expression
        {
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression GREAT_OP shift_expression" << std::endl;
            }
        }
	| relational_expression LE_OP shift_expression
        {
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression LE_OP shift_expression" << std::endl;
            }
        }
	| relational_expression GE_OP shift_expression
        {
            if (printProductions) {
                std::cout << "relational_expression -> relational_expression GE_OP shift_expression" << std::endl;
            }
        }
	;

shift_expression
	: additive_expression
        {
            if (printProductions) {
                std::cout << "shift_expression -> additive_expression" << std::endl;
            }
        }
	| shift_expression LEFT_OP additive_expression
        {
            if (printProductions) {
                std::cout << "shift_expression -> shift_expression LEFT_OP additive_expression" << std::endl;
            }
        }
	| shift_expression RIGHT_OP additive_expression
        {
            if (printProductions) {
                std::cout << "shift_expression -> shift_expression RIGHT_OP additive_expression" << std::endl;
            }
        }
	;

additive_expression
	: multiplicative_expression
        {
            if (printProductions) {
                std::cout << "additive_expression -> multiplicative_expression" << std::endl;
            }
        }
	| additive_expression PLUS multiplicative_expression
        {
            if (printProductions) {
                std::cout << "additive_expression -> additive_expression PLUS multiplicative_expression" << std::endl;
            }
        }
	| additive_expression MINUS multiplicative_expression
        {
            if (printProductions) {
                std::cout << "additive_expression -> additive_expression MINUS multiplicative_expression" << std::endl;
            }
        }
	;

multiplicative_expression
	: cast_expression
        {
            if (printProductions) {
                std::cout << "multiplicative_expression -> cast_expression" << std::endl;
            }
        }
	| multiplicative_expression STAR cast_expression
        {
            if (printProductions) {
                std::cout << "multiplicative_expression -> multiplicative_expression STAR cast_expression" << std::endl;
            }
        }
	| multiplicative_expression FORSLASH cast_expression
        {
            if (printProductions) {
                std::cout << "multiplicative_expression -> multiplicative_expression FORSLASH cast_expression" << std::endl;
            }
        }
	| multiplicative_expression PERCENT cast_expression
        {
            if (printProductions) {
                std::cout << "multiplicative_expression -> multiplicative_expression PERCENT cast_expression" << std::endl;
            }
        }
	;

cast_expression
	: unary_expression
        {
            if (printProductions) {
                std::cout << "cast_expression -> unary_expression" << std::endl;
            }
        }
	| OPEN type_name CLOSE cast_expression
        {
            if (printProductions) {
                std::cout << "cast_expression -> OPEN type_name CLOSE cast_expression" << std::endl;
            }
        }
	;

unary_expression
	: postfix_expression
        {
            if (printProductions) {
                std::cout << "unary_expression -> postfix_expression" << std::endl;
            }
        }
	| INC_OP unary_expression
        {
            if (printProductions) {
                std::cout << "unary_expression -> INC_OP unary_expression" << std::endl;
            }
        }
	| DEC_OP unary_expression
        {
            if (printProductions) {
                std::cout << "unary_expression -> DEC_OP unary_expression" << std::endl;
            }
        }
	| unary_operator cast_expression
        {
            if (printProductions) {
                std::cout << "unary_expression -> unary_operator cast_expression" << std::endl;
            }
        }
	| SIZEOF unary_expression
        {
            if (printProductions) {
                std::cout << "unary_expression -> SIZEOF unary_expression" << std::endl;
            }
        }
	| SIZEOF OPEN type_name CLOSE
        {
            if (printProductions) {
                std::cout << "unary_expression -> SIZEOF OPEN type_name CLOSE" << std::endl;
            }
        }
	;

unary_operator
	: AMP
        {
            if (printProductions) {
                std::cout << "unary_operator -> AMP" << std::endl;
            }
        }
	| STAR
        {
            if (printProductions) {
                std::cout << "unary_operator -> STAR" << std::endl;
            }
        }
	| PLUS
        {
            if (printProductions) {
                std::cout << "unary_operator -> PLUS" << std::endl;
            }
        }
	| MINUS
        {
            if (printProductions) {
                std::cout << "unary_operator -> MINUS" << std::endl;
            }
        }
	| TILDA
        {
            if (printProductions) {
                std::cout << "unary_operator -> TILDA" << std::endl;
            }
        }
	| BANG
        {
            if (printProductions) {
                std::cout << "unary_operator -> BANG" << std::endl;
            }
        }
	;

postfix_expression
	: primary_expression
        {
            if (printProductions) {
                std::cout << "postfix_expression -> primary_expression" << std::endl;
            }
        }
	| postfix_expression BRACKETOPEN expression BRACKETCLOSE
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression BRACKETOPEN expression BRACKETCLOSE" << std::endl;
            }
        }
	| postfix_expression OPEN CLOSE
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression OPEN CLOSE" << std::endl;
            }
        }
	| postfix_expression OPEN argument_expression_list CLOSE
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression OPEN argument_expression_list CLOSE" << std::endl;
            }
        }
	| postfix_expression PERIOD identifier
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression PERIOD identifier" << std::endl;
            }
        }
	| postfix_expression PTR_OP identifier
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression PTR_OP identifier" << std::endl;
            }
        }
	| postfix_expression INC_OP
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression INC_OP" << std::endl;
            }
        }
	| postfix_expression DEC_OP
        {
            if (printProductions) {
                std::cout << "postfix_expression -> postfix_expression DEC_OP" << std::endl;
            }
        }
	;

primary_expression
	: identifier
        {
            if (printProductions) {
                std::cout << "primary_expression -> identifier" << std::endl;
            }
        }
	| constant
        {
            if (printProductions) {
                std::cout << "primary_expression -> constant" << std::endl;
            }
        }
	| string
        {
            if (printProductions) {
                std::cout << "primary_expression -> string" << std::endl;
            }
        }
	| OPEN expression CLOSE
        {
            if (printProductions) {
                std::cout << "primary_expression -> OPEN expression CLOSE" << std::endl;
            }
        }
	;

argument_expression_list
	: assignment_expression
        {
            if (printProductions) {
                std::cout << "argument_expression_list -> assignment_expression" << std::endl;
            }
        }
	| argument_expression_list COMMA assignment_expression
        {
            if (printProductions) {
                std::cout << "argument_expression_list -> argument_expression_list COMMA assignment_expression" << std::endl;
            }
        }
	;

constant
	: INTEGER_CONSTANT
        {
            if (printProductions) {
                std::cout << "constant -> INTEGER_CONSTANT" << std::endl;
            }
        }
	| CHARACTER_CONSTANT
        {
            if (printProductions) {
                std::cout << "constant -> CHARACTER_CONSTANT" << std::endl;
            }
        }
	| FLOATING_CONSTANT
        {
            if (printProductions) {
                std::cout << "constant -> FLOATING_CONSTANT" << std::endl;
            }
        }
	| ENUMERATION_CONSTANT
        {
            if (printProductions) {
                std::cout << "constant -> ENUMERATION_CONSTANT" << std::endl;
            }
        }
	;

string
	: STRING_LITERAL
        {
            if (printProductions) {
                std::cout << "string -> STRING_LITERAL" << std::endl;
            }
        }
	;

identifier
	: IDENTIFIER
        {
            if (printProductions) {
                std::cout << "identifier -> IDENTIFIER" << std::endl;
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
	std::string fhFlag = "-fh";
    std::string inputFlag = "-i";
    std::string outputFlag = "-o";
	FILE* inputStream;
    extern std::string srcFile;
    extern std::string outSrcFile;
    extern std::string buffer;

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
    if ((productionFlag.compare(argv[i])) == 0)
    {
      printProductions = true;
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
  yyparse();
  fclose(inputStream);
  std::ofstream fileP(outSrcFile);
  fileP << "";
  fileP.close();
  globalSymbolTable.printST();

  return 0;
}
