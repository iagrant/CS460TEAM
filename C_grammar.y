%token IDENTIFIER 
%token INTEGER_CONSTANT FLOATING_CONSTANT CHARACTER_CONSTANT ENUMERATION_CONSTANT 
%token STRING_LITERAL 
%token SIZEOF
%token PTR_OP 
%token INC_OP DEC_OP 
%token LEFT_OP RIGHT_OP 
%token LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP 
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN 
%token LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN 
%token TYPEDEF_NAME
%token SEMI COLON CURLYOPEN CURLYCLOSE BRACKETOPEN BRACKETCLOSE COMMA PERIOD EQUALS 
%token OPEN CLOSE STAR QUESTION BAR CARROT AMP LESS_OP GREAT_OP PLUS MINUS FORSLASH
%token PERCENT BANG TILDA
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELIPSIS RANGE

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declarator compound_statement
	| declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declaration_specifiers declarator declaration_list compound_statement
	;

declaration
	: declaration_specifiers SEMI
	| declaration_specifiers init_declarator_list SEMI
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier 
	| type_qualifier declaration_specifiers
	;

storage_class_specifier
	: AUTO
	| REGISTER
	| STATIC
	| EXTERN
	| TYPEDEF
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT 
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME
	;

type_qualifier
	: CONST
	| VOLATILE
	;

struct_or_union_specifier
	: struct_or_union identifier CURLYOPEN struct_declaration_list CURLYCLOSE
	| struct_or_union CURLYOPEN struct_declaration_list CURLYCLOSE
	| struct_or_union identifier
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

init_declarator_list
	: init_declarator
	| init_declarator_list COMMA init_declarator
	;

init_declarator
	: declarator
	| declarator EQUALS initializer
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMI
	;

specifier_qualifier_list
	: type_specifier
	| type_specifier specifier_qualifier_list
	| type_qualifier
	| type_qualifier specifier_qualifier_list
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list COMMA struct_declarator
	;

struct_declarator
	: declarator
	| COLON constant_expression
	| declarator COLON constant_expression
	;

enum_specifier
	: ENUM CURLYOPEN enumerator_list CURLYCLOSE
	| ENUM identifier CURLYOPEN enumerator_list CURLYCLOSE
	| ENUM identifier
	;

enumerator_list
	: enumerator
	| enumerator_list COMMA enumerator
	;

enumerator
	: identifier
	| identifier EQUALS constant_expression
	;

declarator
	: direct_declarator
	| pointer direct_declarator
	;

direct_declarator
	: identifier
	| OPEN declarator CLOSE
	| direct_declarator BRACKETOPEN BRACKETCLOSE
	| direct_declarator BRACKETOPEN constant_expression BRACKETCLOSE
	| direct_declarator OPEN CLOSE
	| direct_declarator OPEN parameter_type_list CLOSE
	| direct_declarator OPEN identifier_list CLOSE
	;

pointer
	: STAR
	| STAR type_qualifier_list
	| STAR pointer
	| STAR type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;

parameter_type_list
	: parameter_list
	| parameter_list COMMA ELIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list COMMA parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers
	| declaration_specifiers abstract_declarator
	;

identifier_list
	: identifier
	| identifier_list COMMA identifier
	;

initializer
	: assignment_expression
	| CURLYOPEN initializer_list CURLYCLOSE
	| CURLYOPEN initializer_list COMMA CURLYCLOSE
	;

initializer_list
	: initializer
	| initializer_list COMMA initializer
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: OPEN abstract_declarator CLOSE
	| BRACKETOPEN BRACKETCLOSE
	| BRACKETOPEN constant_expression BRACKETCLOSE
	| direct_abstract_declarator BRACKETOPEN BRACKETCLOSE
	| direct_abstract_declarator BRACKETOPEN constant_expression BRACKETCLOSE
	| OPEN CLOSE
	| OPEN parameter_type_list CLOSE
	| direct_abstract_declarator OPEN CLOSE
	| direct_abstract_declarator OPEN parameter_type_list CLOSE
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: identifier COLON statement
	| CASE constant_expression COLON statement
	| DEFAULT COLON statement
	;

expression_statement
	: SEMI
	| expression SEMI
	;

compound_statement
	: CURLYOPEN CURLYCLOSE
	| CURLYOPEN statement_list CURLYCLOSE
	| CURLYOPEN declaration_list CURLYCLOSE
	| CURLYOPEN declaration_list statement_list CURLYCLOSE
	;

statement_list
	: statement
	| statement_list statement
	;

selection_statement
	: IF OPEN expression CLOSE statement
	| IF OPEN expression CLOSE statement ELSE statement
	| SWITCH OPEN expression CLOSE statement
	;

iteration_statement
	: WHILE OPEN expression CLOSE statement
	| DO statement WHILE OPEN expression CLOSE SEMI
	| FOR OPEN SEMI SEMI CLOSE statement
	| FOR OPEN SEMI SEMI expression CLOSE statement
	| FOR OPEN SEMI expression SEMI CLOSE statement
	| FOR OPEN SEMI expression SEMI expression CLOSE statement
	| FOR OPEN expression SEMI SEMI CLOSE statement
	| FOR OPEN expression SEMI SEMI expression CLOSE statement
	| FOR OPEN expression SEMI expression SEMI CLOSE statement
	| FOR OPEN expression SEMI expression SEMI expression CLOSE statement
	;

jump_statement
	: GOTO identifier SEMI
	| CONTINUE SEMI
	| BREAK SEMI
	| RETURN SEMI
	| RETURN expression SEMI
	;

expression
	: assignment_expression
	| expression COMMA assignment_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: EQUALS
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression QUESTION expression COLON conditional_expression
	;

constant_expression
	: conditional_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression BAR exclusive_or_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression CARROT and_expression
	;

and_expression
	: equality_expression
	| and_expression AMP equality_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

relational_expression
	: shift_expression
	| relational_expression LESS_OP shift_expression
	| relational_expression GREAT_OP shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression PLUS multiplicative_expression
	| additive_expression MINUS multiplicative_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression STAR cast_expression
	| multiplicative_expression FORSLASH cast_expression
	| multiplicative_expression PERCENT cast_expression
	;

cast_expression
	: unary_expression
	| OPEN type_name CLOSE cast_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF OPEN type_name CLOSE
	;

unary_operator
	: AMP
	| STAR
	| PLUS
	| MINUS
	| TILDA
	| BANG
	;

postfix_expression
	: primary_expression
	| postfix_expression BRACKETOPEN expression BRACKETCLOSE
	| postfix_expression OPEN CLOSE
	| postfix_expression OPEN argument_expression_list CLOSE
	| postfix_expression PERIOD identifier
	| postfix_expression PTR_OP identifier
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

primary_expression
	: identifier
	| constant
	| string
	| OPEN expression CLOSE
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
	;

constant
	: INTEGER_CONSTANT
	| CHARACTER_CONSTANT
	| FLOATING_CONSTANT
	| ENUMERATION_CONSTANT
	;

string
	: STRING_LITERAL
	;

identifier
	: IDENTIFIER
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
}

