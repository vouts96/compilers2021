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

//___identifiers and constants______
%token T_id
%token T_Id
%token T_int_const
%token T_float_const
%token T_char_const
%token T_string_literal

//___input-output functions_________
%token T_print_int "print_int"
%token T_print_bool "print_bool"
%token T_print_char "print_char"
%token T_print_float "print_float"
%token T_print_string "print_string"

%token T_read_int "read_int"
%token T_read_bool "read_bool"
%token T_read_char "read_char"
%token T_read_float "read_float"
%token T_read_string "read_string"

//___math functions_________________
%token T_abs "abs"
%token T_fabs "fabs"
%token T_sqrt "sqrt"
%token T_sin "sin"
%token T_cos "cos"
%token T_tan "tan"
%token T_atan "atan"
%token T_exp "exp"
%token T_ln "ln"
%token T_pi "pi"

//___functions incr-decr____________
%token T_incr "incr"
%token T_decr "decr"

// ___conversion functions__________
%token T_float_of_int "float_to_int"
%token T_int_of_float "int_to_float"
%token T_round "round"
%token T_int_of_char "int_of_char"
%token T_char_of_int "char_of_int"

//___string functions_______________
%token T_strlen "strlen"
%token T_strcmp "strcmp"
%token T_strcpy "strcpy"
%token T_strcat "strcat"

//___operators______________________
%token T_arrow  "->"
%token T_plus_dot "+."
%token T_logic_and "&&"
%token T_logic_or "||"
%token T_double_star "**"
%token T_def_op ":="
%token T_not_equal "!="
%token T_double_equals "=="
%token T_gr_eq ">="
%token T_less_eq "<="
%token T_less_gr "<>"
%token T_minus_dot "-."
%token T_star_dot "*."
%token T_div_dot "/."
%token T_mod "mod"
%token T_not "not"

%left ';'
%nonassoc ":="
%left "||"
%left "&&"
%nonassoc '=' '<' '>' "<>" ">=" "<=" "==" "!="
%left '+' '-'
%left '*' '/' "*." "/." "mod"
%right "**"
%nonassoc "+." "-." "not" "delete"
%left '!'
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
  "let" def andDef
  | "let" "rec" def andDef
  | "type" tdef andTdef
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
  identifier '=' constr bar_constrs
;


def:
  identifier params '=' expr
  | identifier params ':' type '=' expr
  | "mutable" identifier
  | "mutable" identifier '[' expr commaExprs ']'
  | "mutable" identifier ':' type
  | "mutable" identifier '[' expr commaExprs ']' ':' type
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
  identifier
  | '(' identifier ':' type ')'
;

params:
  /* nothing */
  | params par
;


type:
  "unit"
  | "int"
  | "char"
  | "bool"
  | "float"
  | '(' type ')'
  | type "->" type
  | type "ref"
  | "array" "of" type
  | identifier
;


types:
  /* nothing */
  | types type
;


expr:
  T_pi
  | expr '=' expr
  | expr '+' expr
  | expr '-' expr
  | expr "+." expr
  | expr ';' expr
  | expr '*' expr
  | expr "&&" expr
  | expr "||" expr
  | expr "**" expr
  | expr ":=" expr
  | expr "!=" expr
  | expr "==" expr
  | expr ">=" expr
  | expr "<=" expr
  | expr "<>" expr
  | expr '<' expr
  | expr '>' expr
  | expr "-." expr
  | expr "*." expr
  | expr "/." expr
  | expr "mod" expr
  | T_id exprs
  | T_Id exprs
  | "print_string" exprs
  | "print_int" exprs
  | "print_bool" exprs
  | "print_char" exprs
  | "print_float" exprs
  | "read_string" exprs
  | "read_int" exprs
  | "read_bool" exprs
  | "read_char" exprs
  | "read_float" exprs
  | "int_of_char" exprs
  | "int_of_float" exprs
  | "float_of_int" exprs
  | "char_of_int" exprs
  | "round" exprs
  | "abs" exprs
  | "fabs" exprs
  | "sqrt" exprs
  | "sin" exprs
  | "cos" exprs
  | "tan" exprs
  | "atan" exprs
  | "exp" exprs
  | "ln" exprs
  | "incr" exprs
  | "decr" exprs
  | "strlen" exprs
  | "strcmp" exprs
  | "strcpy" exprs
  | "strcat" exprs
  | '=' expr
  | '-' expr
  | "+." expr
  | '!' expr
  | "not" expr
  | T_int_const
  | T_float_const
  | T_char_const
  | T_string_literal
  | "true"
  | "false"
  | '(' ')'
  | '(' expr ')'
  | "new" type
  | "let" def andDef "in" expr
  | "let" "rec" def andDef "in" expr
  | "begin" expr "end"
  | "if" expr "then" expr
  | "if" expr "then" expr "else" expr
  | "while" expr "do" expr "done"
  | "for" identifier '=' expr "to" expr "do" expr "done"
  | "for" identifier '=' expr "downto" expr "do" expr "done"
  | "match" expr "with" clauses "end"
;

exprs:
  /* nothing */
  | exprs expr
;

commaExprs:
  /* nothing */
  | commaExprs ',' expr
;


clause:
  pattern "->" expr
;

clauses:
  /* nothing */
  | clauses '|' clause
;


pattern:
  '+' T_int
  | '-' T_int
  | "+." T_float
  | "-." T_float
  | T_char
  | "true"
  | "false"
  | identifier
  | '(' pattern ')'
  | T_Id patterns
;

patterns:
  /* nothing */
  | patterns pattern
;

identifier:
  T_id
  | T_Id
  | "print_string"
  | "print_int"
  | "print_bool"
  | "print_char"
  | "print_float"
  | "read_string"
  | "read_int"
  | "read_bool"
  | "read_char"
  | "read_float"
  | "int_of_char"
  | "int_of_float"
  | "float_of_int"
  | "char_of_int"
  | "round"
  | "abs"
  | "fabs"
  | "sqrt"
  | "sin"
  | "cos"
  | "tan"
  | "atan"
  | "exp"
  | "ln"
  | "incr"
  | "decr"
  | "strlen"
  | "strcmp"
  | "strcpy"
  | "strcat"
;

%%
int main() {
  int result = yyparse();
  if (result == 0) printf("Success.\n");
  return result;
}
