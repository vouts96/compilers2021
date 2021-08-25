%{
#include <cstdio>
#include "lexer.hpp"
%}

%token T_and "and"
%token T_array "array"
%token T_begin "begin"
%token T_bool "bool"
%token T_char "char"
%token T_delete "delete"
%token T_dim "dim"
%token T_do "do"
%token T_done "done"
%token T_downto "downto"
%token T_else "else"
%token T_end "end"
%token T_false "false"
%token T_float "float"
%token T_for "for"
%token T_if "if"
%token T_in "in"
%token T_int "int"
%token T_let "let"
%token T_match "match"
%token T_mutable "mutable"
%token T_new "new"
%token T_of "of"
%token T_rec "rec"
%token T_ref "ref"
%token T_then "then"
%token T_to "to"
%token T_true "true"
%token T_type "type"
%token T_unit "unit"
%token T_while "while"
%token T_with "with"

//___operators______________________
%token T_plus_dot "+."
%token T_logic_and "&&"
%token T_logic_or "||"
%token T_double_star "**"
%token T_assign ":="
%token T_neq "!="
%token T_iseq "=="
%token T_greq ">="
%token T_leq "<="
%token T_legr "<>"
%token T_minus_dot "-."
%token T_star_dot "*."
%token T_slash_dot "/."
%token T_arrow "->"
%token T_mod "mod"
%token T_not "not"


//___identifiers and constants______
%token T_id
%token T_Id
%token T_int_const
%token T_float_const
%token T_char_const
%token T_string_literal



%precedence "let" "in"
%left ';'
%precedence "if" "then" "else"
%nonassoc ":="
%left "||"
%left "&&"
%nonassoc '=' '<' '>' "<>" ">=" "<=" "==" "!="
%left '+' '-' "+." "-."
%left '*' '/' "*." "/." "mod"
%right "**"
%precedence "not" "delete"
%precedence '!'
%nonassoc '[' ']'
%nonassoc "new"

%%


program:
  defList
;

defList:
  /* nothing */
  | defList defs
;

defs:
  letdef
  | "type" tdef andTdef
;

letdef:
  "let" def andDef
  | "let" "rec" def andDef
;

andDef:
  /* nothing */
  | andDef "and" def
;


andTdef:
  /* nothing */
  | andTdef "and" tdef
;

tdef:
  T_id '=' constr bar_constrs
;


def:
  T_id params '=' expr
  | T_id params ':' type '=' expr
  | "mutable" T_id
  | "mutable" T_id '[' expr commaExprs ']'
  | "mutable" T_id ':' type
  | "mutable" T_id '[' expr commaExprs ']' ':' type
;


constr:
  T_Id
  | T_Id "of" types
;

bar_constrs:
  /* nothing */
  | bar_constrs '|' constr
;


par:
  T_id
  | '(' T_id ':' type_list ')'
;

params:
  /* nothing */
  | params par
;


type_list:
  type
  | '(' type ')'
  | type "->" type
  | type "ref"
  | "array" "of" type
;

types:
  /* nothing */
  | types type
;

type:
  "unit"
  | "int"
  | "char"
  | "bool"
  | "float"
  | T_id
;


exprs:
  /* nothing */
  | exprs expr
;

commaExprs:
  /* nothing */
  | commaExprs ',' expr
;


expr:
  T_int_const
  | T_float_const
  | T_char_const
  | T_string_literal
  | "true"
  | "false"
  | '(' ')'
  //___unop expressions________
  | '(' expr ')'
  | '+' expr
  | '-' expr
  | "+." expr
  | "-." expr
  | '!' expr
  | "not" expr
  //___binop expressions_______
  | expr '+' expr
  | expr '-' expr
  | expr '*' expr
  | expr '/' expr
  | expr "+." expr
  | expr "-." expr
  | expr "*." expr
  | expr "/." expr
  | expr "mod" expr
  | expr "**" expr
  | expr '=' expr
  | expr "<>" expr
  | expr '<' expr
  | expr '>' expr
  | expr "<=" expr
  | expr ">=" expr
  | expr "==" expr
  | expr "!=" expr
  | expr "&&" expr
  | expr "||" expr
  | expr ';' expr
  | expr ":=" expr
  //____________________________
  | T_id exprs
  | T_Id exprs
  | "dim" T_id
  | "dim" T_int_const T_id
  | T_id '[' expr commaExprs ']'
  | letdef "in" expr
  | "begin" expr "end"
  | "if" expr "then" expr
  | "if" expr "then" expr "else" expr
  | "while" expr "do" expr "done"
  | "for" T_id '=' expr "to" expr "do" expr "done"
  | "for" T_id '=' expr "downto" expr "do" expr "done"
  | "match" expr "with" clause "end"
;




clause:
  pattern_list "->" expr
;


pattern_list:
  pattern
  | '(' pattern ')'
  | patterns
  | T_Id patterns
;

patterns:
  /* nothing */
  | patterns pattern
;

pattern:
  '+' T_int
  | '-' T_int
  | "+." T_float
  | "-." T_float
  | T_char
  | "true"
  | "false"
  | T_id
  | T_Id
;


%%
int main() {
  int result = yyparse();
  if (result == 0) printf("Success.\n");
  return result;
}
