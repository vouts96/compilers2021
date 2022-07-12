
%{
#include <iostream>
#include <cstdio>
#include <string>
#include "ast.hpp"
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
%token<id> T_id
%token<constrId> T_Id
%token<int_const> T_int_const
%token<float_const> T_float_const
%token<char_const> T_char_const
%token<stringLiteral> T_string_literal


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
%precedence UPLUS UMINUS UPLUS_DOT UMINUS_DOT "not" "delete"
%nonassoc FUNCTION_CALL CONSTRUCTOR_CALL
%precedence '!'
%nonassoc '[' ']'
%nonassoc "new"




%union{
  Letdef *let;
  Expr *expr;
  ExprList *exprList;
  Def *def;
  DefList *defList;
  Par *par;
  //ParId *parId;
  ParList *parList;
  CommaExprList *commaExprList;
  Type *type;
  TypeList *typeList;
  Typedef *typeDef;
  AndDef *andDef;
  AndTypeDef *andTypeDef;
  char char_const;
  int int_const;
  float float_const;
  Id *id;
  ConstrId *constrId;
  BarConstrs *barConstrs;
  StringLiteral *stringLiteral;
  Pattern *pattern;
  Clause *clause;
  PatternList *patternList;
  ClauseList *clauseList;
}

//%expect 1

%type<defList> program defList
%type<def> defs letdef typedef
%type<andDef> andDef
%type<constrId> constr
%type<barConstrs> bar_constrs
%type<let> def
%type<typeDef> tdef
%type<andTypeDef> andTdef
%type<type> type
%type<typeList> types
%type<expr> expr
%type<exprList> exprs
%type<par> par
%type<parList> params
%type<commaExprList> commaExprs
%type<pattern> pattern
%type<patternList> patterns
%type<clause> clause
%type<clauseList> clauses
%%


program:
  defList {
    std::cout << "AST:\n" << *$1 << std::endl;
    $1->run(cout, "global");
  }
;

defList:
  /* nothing */ { $$ = new DefList(); }
  | defList defs  { $1->append($2); $$ = $1; }
;

defs:
  letdef
  | typedef
;

letdef:
  "let" def andDef  { $$ = $2; if(!$3->isEmpty()){$3->append($2); $$ = $3;}}
  | "let" "rec" def andDef  { $$ = $3; }
;

andDef:
  /* nothing */ { $$ = new AndDef(); }
  | andDef "and" def  { $1->append($3); $$ = $1; }
;

def:
T_id params '=' expr { $$ = new Letdef(false, $1, $2, $4);}
  | T_id params ':' type '=' expr { $$ = new Letdef(false, $1, $2, $4, $6); }
  | "mutable" T_id  { $$ = new Letdef(true, $2); }
  | "mutable" commaExprs ']'  { $$ = new Letdef(true, $2); }
  | "mutable" T_id ':' type { $$ = new Letdef(true, $2, $4); }
  | "mutable" commaExprs ']' ':' type { $$ = new Letdef(true, $2, $5); }
;

params:
  /* nothing */ { $$ = new ParList(); }
  | params par  { $1->append($2); $$ = $1; }
;

par:
  T_id  { $$ = new Par($1); }
  | '(' T_id ':' type ')' { $$ = new ParType($2, $4); }
;


typedef:
  "type" tdef andTdef { $$ = $2; if(!$3->isEmpty()){$3->append($2); $$ = $3;} }
;

andTdef:
  /* nothing */ { $$ = new AndTypeDef(); }
  | andTdef "and" tdef  { $1->append($3); $$ = $1; }
;

tdef:
  T_id '=' constr bar_constrs { $$ = new Typedef($1, $3, $4); }
  //| T_id '=' T_id { yyerror("Syntax error: Constructor expected but got identifier"); }
  //| T_id constr { yyerror("Syntax error: Operator '=' expected"); }
;

bar_constrs:
  /* nothing */ { $$ = new BarConstrs(); }
  | bar_constrs '|' constr  { $1->append($3); $$ = $1; }
;


constr:
  T_Id
  | T_Id "of" types { $$ = new ConstrOfTypes($1, $3); }
;

types:
  type { $$ = new TypeList(); $$->append($1); }
  | types type  { $1->append($2); $$ = $1; }
;


type:
  "unit"  { $$ = new Type("unit"); }
  | "int" { $$ = new Type("int"); }
  | "char"  { $$ = new Type("char"); }
  | "bool"  { $$ = new Type("bool"); }
  | "float" { $$ = new Type("float"); }
  | T_id  { $$ = new Type($1); }
  | '(' type ')'  { $$ = $2; }
  | type "->" type  { $$ = new TypeToType($1, $3); }
  | type "ref"  { $$ = new TypeRef($1); }
  | "array" "of" type { $$ = new ArrayOfType($3); }
;


exprs:
  /* nothing */  { $$ = new ExprList(); }
  | exprs expr   { $1->append($2); $$ = $1;}
;



commaExprs:
  T_id '[' expr           { $$ = new CommaExprList($1); $$->append($3); }
  | commaExprs ',' expr   { $1->append($3); $$ = $1; }
;


expr:
  T_int_const { $$ = new IntConst($1); }
  | T_float_const { $$ = new FloatConst($1); }
  | T_char_const  { $$ = new CharConst($1); }
  | T_string_literal  { $$ = new StringLiteral(*$1); }
  | "true"  { $$ = new BoolConst("true"); }
  | "false" { $$ = new BoolConst("false"); }
  | '(' ')'
  | '(' expr ')'  { $$ = $2; }
  //___unop expressions________
  | '+' expr %prec UPLUS  { $$ = new UnOp("+", $2); }
  | '-' expr %prec UMINUS { $$ = new UnOp("-", $2); }
  | "+." expr %prec UPLUS_DOT { $$ = new UnOp("+.", $2); }
  | "-." expr %prec UMINUS_DOT  { $$ = new UnOp("-.", $2); }
  | '!' expr  { $$ = new UnOp("!", $2); }
  | "not" expr  { $$ = new UnOp("not", $2); }
  //___binop expressions_______
  | expr '+' expr { $$ = new BinOp($1, "+", $3); }
  | expr '-' expr { $$ = new BinOp($1, "-", $3); }
  | expr '*' expr { $$ = new BinOp($1, "*", $3); }
  | expr '/' expr { $$ = new BinOp($1, "/", $3); }
  | expr "+." expr { $$ = new BinOp($1, "+.", $3); }
  | expr "-." expr  { $$ = new BinOp($1, "-.", $3); }
  | expr "*." expr  { $$ = new BinOp($1, "*.", $3); }
  | expr "/." expr  { $$ = new BinOp($1, "/.", $3); }
  | expr "mod" expr { $$ = new BinOp($1, "mod", $3); }
  | expr "**" expr  { $$ = new BinOp($1, "**", $3); }
  | expr '=' expr { $$ = new BinOp($1, "=", $3); }
  | expr "<>" expr  { $$ = new BinOp($1, "<>", $3); }
  | expr '<' expr  { $$ = new BinOp($1, "<", $3); }
  | expr '>' expr { $$ = new BinOp($1, ">", $3);}
  | expr "<=" expr  { $$ = new BinOp($1, "<=", $3); }
  | expr ">=" expr  { $$ = new BinOp($1, ">=", $3); }
  | expr "==" expr  { $$ = new BinOp($1, "==", $3); }
  | expr "!=" expr  { $$ = new BinOp($1, "!=", $3); }
  | expr "&&" expr  { $$ = new BinOp($1, "&&", $3); }
  | expr "||" expr  { $$ = new BinOp($1, "||", $3); }
  | expr ';' expr { $$ = new BinOp($1, ";", $3); /*std::cout << *$$ << endl;*/ }
  | expr ":=" expr  { $$ = new BinOp($1, ":=", $3); }
  //____________________________
  | T_id exprs %prec FUNCTION_CALL  { $$ = new Function_call($1, $2); }
  | T_Id exprs %prec CONSTRUCTOR_CALL { $$ = new Constr_call($1, $2); }
  | "dim" T_id  { $$ = new Dim($2, false); }
  | "dim" T_int_const T_id { $$ = new Dim($2, $3, true); }
  | "new" type  { $$ = new NewType($2); }
  | "delete" expr { $$ = new Delete($2); }
  | commaExprs ']'  { $$ = $1; }
  | letdef "in" expr  /*%prec LOCAL_DECL*/ { $$ = new LetIn($1, $3); }
  //| letdef  /*%prec LOCAL_DECL*/ { yyerror("Syntax error: 'in' expected"); }
  | "begin" expr "end"  { $$ = new Begin($2); }
  //| "begin" expr { yyerror("Syntax error: 'end' expected"); }
  | "if" expr "then" expr /*%prec IF_THEN*/   { $$ = new If($2, $4); /*std::cout << *$$;*/ }
  | "if" expr "then" expr "else" expr /*%prec IF_THEN_ELSE*/ { $$ = new If($2, $4, $6);  }
  | "while" expr "do" expr "done"   { $$ = new While($2, $4); }
  | "for" T_id '=' expr "to" expr "do" expr "done"  { $$ = new For($2, $4, $6, $8, true); }
  | "for" T_id '=' expr "downto" expr "do" expr "done" { $$ = new For($2, $4, $6, $8, false); }
  | "match" expr "with" clauses "end"  { $$ = new MatchExpr($2, $4); }
;



patterns:
  /* nothing */        { $$ = new PatternList(); }
  | patterns pattern   { $1->append($2); $$ = $1; }
;


pattern:
  '+' T_int_const         { $$ = new Pattern('+', $2); }
  | '-' T_int_const       { $$ = new Pattern('-', $2); }
  | "+." T_float_const    { $$ = new Pattern("+.", $2); }
  | "-." T_float_const    { $$ = new Pattern("-.", $2); }
  | T_char_const          { $$ = new Pattern($1); }
  | "true"                { $$ = new Pattern("true"); }
  | "false"               { $$ = new Pattern("false"); }
  | T_id                  { $$ = new Pattern($1); }
  | T_Id                  { $$ = new Pattern($1); }
  | '(' pattern ')'       { $$ = $2; }
  | T_Id patterns         { $$ = new PatternConstr($1, $2); }
;

clauses:
  clause                  { $$ = new ClauseList(); $$->append($1); }
  | clauses '|' clause        { $1->append($3); $$ = $1; }

clause:
  pattern "->" expr  { $$ = new Clause($1, $3); }
;


%%

int main() {
  int result = yyparse();
  if (result == 0) printf("Success.\n");
  //for (auto it = symbolTable.begin(); it != symbolTable.end(); ++it) cout << " " << (*it).getSymbolName() << (*it).getSymbolType() << (*it).getSymbolScope() << endl;
  return result;
}
