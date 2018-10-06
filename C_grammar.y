%{
  #include <stdio.h>
  #include <string.h>
  #include <bool.h>

  extern bool printProductions = true;
%}

%union {
  int ival;
  char cval;
  std::string sval;
  double dval;
}

%token <sval> IDENTIFIER
%token INTEGER_CONSTANT FLOATING_CONSTANT CHARACTER_CONSTANT ENUMERATION_CONSTANT
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
%token PERCENT BANG TILDA
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELIPSIS RANGE

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token ERROR DEBUG

%type <sval> string identifier

%start translation_unit
%%

translation_unit
	: external_declaration {if (printProductions) {std::cout << "translational_unit -> external_declaration" << std::endl;}}
	| translation_unit external_declaration {if (printProductions) {std::cout << "translational_unit -> translational_unit external_declaration" << std::endl;}}
	;

external_declaration
	: function_definition {if (printProductions) {std::cout << "external_declaration -> function definition" << std::endl;}}
	| declaration {if (printProductions) {std::cout << "external_declaration -> declaration" << std::endl;}}
	;

function_definition
	: declarator compound_statement {if (printProductions) {std::cout << "function_definition -> declarator compound_statment" << std::endl;}}
	| declarator declaration_list compound_statement {if (printProductions) {std::cout << "function_defintion -> declarator declaration_list compound_statment" << std::endl;}}
	| declaration_specifiers declarator compound_statement {if (printProductions) {std::cout << "function_definition -> declaration_specifiers declarator compound_statement" << std::endl;}}
	| declaration_specifiers declarator declaration_list compound_statement {if (printProductions) {std::cout << "function_definition -> declaration_specifiers declarator declaration_list compound_statment" << std::endl;}}
	;

declaration
	: declaration_specifiers SEMI {if (printProductions) {std::cout << "declaration -> declaration_specifiers SEMI" << std::endl;}}
	| declaration_specifiers init_declarator_list SEMI {if (printProductions) {std::cout << "declaration -> declaration_specifiers init_declarator_list SEMI" << std::endl;}}
	;

declaration_list
	: declaration {if (printProductions) {std::cout << "declaration_list -> declaration" << std::endl;}}
	| declaration_list declaration {if (printProductions) {std::cout << "declaration_list -> declaration list declaration" << std::endl;}}
	;

declaration_specifiers
	: storage_class_specifier {if (printProductions) {std::cout << "declaration_specifiers -> storage_class_specifier" << std::endl;}}
	| storage_class_specifier declaration_specifiers {if (printProductions) {std::cout << "declaration_specifiers -> storage_class_specifier declaration_specifiers" << std::endl;}}
	| type_specifier {if (printProductions) {std::cout << "declaration_specifiers -> type_specifier" << std::endl;}}
	| type_specifier declaration_specifiers {if (printProductions) {std::cout << "declaration_specifiers -> type_specifier declaration_specifiers" << std::endl;}}
	| type_qualifier  {if (printProductions) {std::cout << "declaration_specifiers ->  type_qualifier" << std::endl;}}
	| type_qualifier declaration_specifiers {if (printProductions) {std::cout << "declaration_specifiers -> type_qualifier declaration_specifiers" << std::endl;}}
	;

storage_class_specifier
	: AUTO {if (printProductions) {std::cout << "storage_class_specifier -> AUTO" << std::endl;}}
	| REGISTER {if (printProductions) {std::cout << "storage_class_specifier -> REGISTER" << std::endl;}}
	| STATIC {if (printProductions) {std::cout << "storage_class_specifier -> STATIC" << std::endl;}}
	| EXTERN {if (printProductions) {std::cout << "storage_class_specifier -> EXTERN" << std::endl;}}
	| TYPEDEF {if (printProductions) {std::cout << "storage_class_specifier -> TYPEDEF" << std::endl;}}
	;

type_specifier
	: VOID {if (printProductions) {std::cout << "type_specifier -> VOID" << std::endl;}}
	| CHAR {if (printProductions) {std::cout << "type_specifier -> CHAR" << std::endl;}}
	| SHORT {if (printProductions) {std::cout << "type_specifier -> SHORT" << std::endl;}}
	| INT {if (printProductions) {std::cout << "type_specifier -> INT" << std::endl;}}
	| LONG {if (printProductions) {std::cout << "type_specifier -> LONG" << std::endl;}}
	| FLOAT  {if (printProductions) {std::cout << "type_specifier -> FLOAT" << std::endl;}}
	| DOUBLE {if (printProductions) {std::cout << "type_specifier -> DOUBLE" << std::endl;}}
	| SIGNED {if (printProductions) {std::cout << "type_specifier -> SIGNED" << std::endl;}}
	| UNSIGNED {if (printProductions) {std::cout << "type_specifier -> UNSIGNED" << std::endl;}}
	| struct_or_union_specifier {if (printProductions) {std::cout << "type_specifier -> struct_or_union_specifier" << std::endl;}}
	| enum_specifier {if (printProductions) {std::cout << "type_specifier -> enum_specifier" << std::endl;}}
	| TYPEDEF_NAME {if (printProductions) {std::cout << "type_specifier ->TYPEDEF_NAME" << std::endl;}}
	;

type_qualifier
	: CONST {if (printProductions) {std::cout << "type_qualifier -> CONST" << std::endl;}}
	| VOLATILE {if (printProductions) {std::cout << "type_qualifier -> VOLATILE" << std::endl;}}
	;

struct_or_union_specifier
	: struct_or_union identifier CURLYOPEN struct_declaration_list CURLYCLOSE {if (printProductions) {std::cout << "struct_or_union_specifier ->struct_or_union identifier CURLYOPEN struct_declaration_list CURLYCLOSE " << std::endl;}}
	| struct_or_union CURLYOPEN struct_declaration_list CURLYCLOSE {if (printProductions) {std::cout << "struct_or_union_specifier -> struct_or_union CURLYOPEN struct_declaration_list CURLYCLOSE" << std::endl;}}
	| struct_or_union identifier {if (printProductions) {std::cout << "struct_or_union_specifier -> struct_or_union identifier " << std::endl;}}
	;

struct_or_union
	: STRUCT {if (printProductions) {std::cout << "struct_or_union -> STRUCT" << std::endl;}}
	| UNION {if (printProductions) {std::cout << "struct_or_union -> UNION" << std::endl;}}
	;

struct_declaration_list
	: struct_declaration {if (printProductions) {std::cout << "struct_declaration_list -> " << std::endl;}}
	| struct_declaration_list struct_declaration {if (printProductions) {std::cout << "" << std::endl;}}
	;

init_declarator_list
	: init_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	| init_declarator_list COMMA init_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	;

init_declarator
	: declarator {if (printProductions) {std::cout << "" << std::endl;}}
	| declarator EQUALS initializer {if (printProductions) {std::cout << "" << std::endl;}}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMI {if (printProductions) {std::cout << "" << std::endl;}}
	;

specifier_qualifier_list
	: type_specifier {if (printProductions) {std::cout << "" << std::endl;}}
	| type_specifier specifier_qualifier_list {if (printProductions) {std::cout << "" << std::endl;}}
	| type_qualifier {if (printProductions) {std::cout << "" << std::endl;}}
	| type_qualifier specifier_qualifier_list {if (printProductions) {std::cout << "" << std::endl;}}
	;

struct_declarator_list
	: struct_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	| struct_declarator_list COMMA struct_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	;

struct_declarator
	: declarator {if (printProductions) {std::cout << "" << std::endl;}}
	| COLON constant_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| declarator COLON constant_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

enum_specifier
	: ENUM CURLYOPEN enumerator_list CURLYCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| ENUM identifier CURLYOPEN enumerator_list CURLYCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| ENUM identifier {if (printProductions) {std::cout << "" << std::endl;}}
	;

enumerator_list
	: enumerator {if (printProductions) {std::cout << "" << std::endl;}}
	| enumerator_list COMMA enumerator {if (printProductions) {std::cout << "" << std::endl;}}
	;

enumerator
	: identifier {if (printProductions) {std::cout << "" << std::endl;}}
	| identifier EQUALS constant_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

declarator
	: direct_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	| pointer direct_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	;

direct_declarator
	: identifier {if (printProductions) {std::cout << "" << std::endl;}}
	| OPEN declarator CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_declarator BRACKETOPEN BRACKETCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_declarator BRACKETOPEN constant_expression BRACKETCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_declarator OPEN CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_declarator OPEN parameter_type_list CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_declarator OPEN identifier_list CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	;

pointer
	: STAR {if (printProductions) {std::cout << "" << std::endl;}}
	| STAR type_qualifier_list {if (printProductions) {std::cout << "" << std::endl;}}
	| STAR pointer {if (printProductions) {std::cout << "" << std::endl;}}
	| STAR type_qualifier_list pointer {if (printProductions) {std::cout << "" << std::endl;}}
	;

type_qualifier_list
	: type_qualifier {if (printProductions) {std::cout << "" << std::endl;}}
	| type_qualifier_list type_qualifier {if (printProductions) {std::cout << "" << std::endl;}}
	;

parameter_type_list
	: parameter_list {if (printProductions) {std::cout << "" << std::endl;}}
	| parameter_list COMMA ELIPSIS {if (printProductions) {std::cout << "" << std::endl;}}
	;

parameter_list
	: parameter_declaration {if (printProductions) {std::cout << "" << std::endl;}}
	| parameter_list COMMA parameter_declaration {if (printProductions) {std::cout << "" << std::endl;}}
	;

parameter_declaration
	: declaration_specifiers declarator {if (printProductions) {std::cout << "" << std::endl;}}
	| declaration_specifiers {if (printProductions) {std::cout << "" << std::endl;}}
	| declaration_specifiers abstract_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	;

identifier_list
	: identifier {if (printProductions) {std::cout << "" << std::endl;}}
	| identifier_list COMMA identifier {if (printProductions) {std::cout << "" << std::endl;}}
	;

initializer
	: assignment_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| CURLYOPEN initializer_list CURLYCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| CURLYOPEN initializer_list COMMA CURLYCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	;

initializer_list
	: initializer {if (printProductions) {std::cout << "" << std::endl;}}
	| initializer_list COMMA initializer {if (printProductions) {std::cout << "" << std::endl;}}
	;

type_name
	: specifier_qualifier_list {if (printProductions) {std::cout << "" << std::endl;}}
	| specifier_qualifier_list abstract_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	;

abstract_declarator
	: pointer {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_abstract_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	| pointer direct_abstract_declarator {if (printProductions) {std::cout << "" << std::endl;}}
	;

direct_abstract_declarator
	: OPEN abstract_declarator CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| BRACKETOPEN BRACKETCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| BRACKETOPEN constant_expression BRACKETCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_abstract_declarator BRACKETOPEN BRACKETCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_abstract_declarator BRACKETOPEN constant_expression BRACKETCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| OPEN CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| OPEN parameter_type_list CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_abstract_declarator OPEN CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| direct_abstract_declarator OPEN parameter_type_list CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	;

statement
	: labeled_statement {if (printProductions) {std::cout << "" << std::endl;}}
	| compound_statement {if (printProductions) {std::cout << "" << std::endl;}}
	| expression_statement {if (printProductions) {std::cout << "" << std::endl;}}
	| selection_statement {if (printProductions) {std::cout << "" << std::endl;}}
	| iteration_statement {if (printProductions) {std::cout << "" << std::endl;}}
	| jump_statement {if (printProductions) {std::cout << "" << std::endl;}}
	;

labeled_statement
	: identifier COLON statement {if (printProductions) {std::cout << "" << std::endl;}}
	| CASE constant_expression COLON statement {if (printProductions) {std::cout << "" << std::endl;}}
	| DEFAULT COLON statement {if (printProductions) {std::cout << "" << std::endl;}}
	;

expression_statement
	: SEMI {if (printProductions) {std::cout << "" << std::endl;}}
	| expression SEMI {if (printProductions) {std::cout << "" << std::endl;}}
	;

compound_statement
	: CURLYOPEN CURLYCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| CURLYOPEN statement_list CURLYCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| CURLYOPEN declaration_list CURLYCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| CURLYOPEN declaration_list statement_list CURLYCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	;

statement_list
	: statement {if (printProductions) {std::cout << "" << std::endl;}}
	| statement_list statement {if (printProductions) {std::cout << "" << std::endl;}}
	;

selection_statement
	: IF OPEN expression CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| IF OPEN expression CLOSE statement ELSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| SWITCH OPEN expression CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	;

iteration_statement
	: WHILE OPEN expression CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| DO statement WHILE OPEN expression CLOSE SEMI {if (printProductions) {std::cout << "" << std::endl;}}
	| FOR OPEN SEMI SEMI CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| FOR OPEN SEMI SEMI expression CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| FOR OPEN SEMI expression SEMI CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| FOR OPEN SEMI expression SEMI expression CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| FOR OPEN expression SEMI SEMI CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| FOR OPEN expression SEMI SEMI expression CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| FOR OPEN expression SEMI expression SEMI CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	| FOR OPEN expression SEMI expression SEMI expression CLOSE statement {if (printProductions) {std::cout << "" << std::endl;}}
	;

jump_statement
	: GOTO identifier SEMI {if (printProductions) {std::cout << "" << std::endl;}}
	| CONTINUE SEMI {if (printProductions) {std::cout << "" << std::endl;}}
	| BREAK SEMI {if (printProductions) {std::cout << "" << std::endl;}}
	| RETURN SEMI {if (printProductions) {std::cout << "" << std::endl;}}
	| RETURN expression SEMI {if (printProductions) {std::cout << "" << std::endl;}}
	;

expression
	: assignment_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| expression COMMA assignment_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

assignment_expression
	: conditional_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| unary_expression assignment_operator assignment_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

assignment_operator
	: EQUALS {if (printProductions) {std::cout << "" << std::endl;}}
	| MUL_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	| DIV_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	| MOD_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	| ADD_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	| SUB_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	| LEFT_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	| RIGHT_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	| AND_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	| XOR_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	| OR_ASSIGN {if (printProductions) {std::cout << "" << std::endl;}}
	;

conditional_expression
	: logical_or_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| logical_or_expression QUESTION expression COLON conditional_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

constant_expression
	: conditional_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

logical_or_expression
	: logical_and_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| logical_or_expression OR_OP logical_and_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

logical_and_expression
	: inclusive_or_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| logical_and_expression AND_OP inclusive_or_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

inclusive_or_expression
	: exclusive_or_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| inclusive_or_expression BAR exclusive_or_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

exclusive_or_expression
	: and_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| exclusive_or_expression CARROT and_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

and_expression
	: equality_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| and_expression AMP equality_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

equality_expression
	: relational_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| equality_expression EQ_OP relational_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| equality_expression NE_OP relational_expression
	;

relational_expression
	: shift_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| relational_expression LESS_OP shift_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| relational_expression GREAT_OP shift_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| relational_expression LE_OP shift_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| relational_expression GE_OP shift_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

shift_expression
	: additive_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| shift_expression LEFT_OP additive_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| shift_expression RIGHT_OP additive_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

additive_expression
	: multiplicative_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| additive_expression PLUS multiplicative_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| additive_expression MINUS multiplicative_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

multiplicative_expression
	: cast_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| multiplicative_expression STAR cast_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| multiplicative_expression FORSLASH cast_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| multiplicative_expression PERCENT cast_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

cast_expression
	: unary_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| OPEN type_name CLOSE cast_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

unary_expression
	: postfix_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| INC_OP unary_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| DEC_OP unary_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| unary_operator cast_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| SIZEOF unary_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| SIZEOF OPEN type_name CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	;

unary_operator
	: AMP {if (printProductions) {std::cout << "" << std::endl;}}
	| STAR {if (printProductions) {std::cout << "" << std::endl;}}
	| PLUS {if (printProductions) {std::cout << "" << std::endl;}}
	| MINUS {if (printProductions) {std::cout << "" << std::endl;}}
	| TILDA {if (printProductions) {std::cout << "" << std::endl;}}
	| BANG {if (printProductions) {std::cout << "" << std::endl;}}
	;

postfix_expression
	: primary_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| postfix_expression BRACKETOPEN expression BRACKETCLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| postfix_expression OPEN CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| postfix_expression OPEN argument_expression_list CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	| postfix_expression PERIOD identifier {if (printProductions) {std::cout << "" << std::endl;}}
	| postfix_expression STAR identifier {if (printProductions) {std::cout << "" << std::endl;}}
	| postfix_expression INC_OP {if (printProductions) {std::cout << "" << std::endl;}}
	| postfix_expression DEC_OP {if (printProductions) {std::cout << "" << std::endl;}}
	;

primary_expression
	: identifier {if (printProductions) {std::cout << "" << std::endl;}}
	| constant {if (printProductions) {std::cout << "" << std::endl;}}
	| string {if (printProductions) {std::cout << "" << std::endl;}}
	| OPEN expression CLOSE {if (printProductions) {std::cout << "" << std::endl;}}
	;

argument_expression_list
	: assignment_expression {if (printProductions) {std::cout << "" << std::endl;}}
	| argument_expression_list COMMA assignment_expression {if (printProductions) {std::cout << "" << std::endl;}}
	;

constant
	: INTEGER_CONSTANT {if (printProductions) {std::cout << "" << std::endl;}}
	| CHARACTER_CONSTANT {if (printProductions) {std::cout << "" << std::endl;}}
	| FLOATING_CONSTANT {if (printProductions) {std::cout << "" << std::endl;}}
	| ENUMERATION_CONSTANT {if (printProductions) {std::cout << "" << std::endl;}}
	;

string
	: STRING_LITERAL {if (printProductions) {std::cout << "" << std::endl;}}
	;

identifier
	: IDENTIFIER {if (printProductions) {std::cout << "" << std::endl;}}
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
