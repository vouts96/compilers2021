%option noyywrap
%x COMMENT

%{
#include <cstdio>
#include <cstdlib>
#include "lexer.hpp"
#include "parser.hpp"

#define T_eof 0


int lineno = 1;


%}

W [ \t\r]
D [0-9]

%%

"and"     { return T_and;     }
"array"   { return T_array;   }
"begin"   { return T_begin;   }
"bool"    { return T_bool;    }
"char"    { return T_char;    }
"delete"  { return T_delete;  }
"dim"     { return T_dim;     }
"do"      { return T_do;      }
"done"    { return T_done;    }
"downto"  { return T_downto;  }
"else"    { return T_else;    }
"end"     { return T_end;     }
"false"   { return T_false;   }
"float"   { return T_float;   }
"for"     { return T_for;     }
"if"      { return T_if;      }
"in"      { return T_in;      }
"int"     { return T_int;     }
"let"     { return T_let;     }
"match"   { return T_match;   }
"mutable" { return T_mutable; }
"new"     { return T_new;     }
"of"      { return T_of;      }
"rec"     { return T_rec;     }
"ref"     { return T_ref;     }
"then"    { return T_then;    }
"to"      { return T_to;      }
"type"    { return T_type;    }
"unit"    { return T_unit;    }
"while"   { return T_while;   }
"with"    { return T_with;    }


"not" { printf("not '%s' at line %d\n", yytext, lineno); return T_not; }
[!]{1}  { printf("logic_not '%c' at line %d\n", yytext[0], lineno); return yytext[0]; }

[+]{1}  { printf("plus '%c' at line %d\n", yytext[0], lineno); return yytext[0]; }
[;]{1}  { printf("semicolon '%c' at line %d\n", yytext[0], lineno); return yytext[0]; }
[/]{1}  { printf("slash '%c' at line %d\n", yytext[0], lineno); return yytext[0]; }
[*]{1}  { printf("star '%c' at line %d\n", yytext[0], lineno); return yytext[0]; }
[<]{1}  { printf("less '%c' at line %d\n", yytext[0], lineno); return yytext[0]; }
[>]{1}  { printf("greater '%c' at line %d\n", yytext[0], lineno); return yytext[0]; }
[&]{2}  { printf("logic_and '%s' at line %d\n", yytext, lineno); return T_logic_and; }
[|]{2}  { printf("logic_or '%s' at line %d\n", yytext, lineno); return T_logic_or;  }
[*]{2}  { printf("double_star '%s' at line %d\n", yytext, lineno); return T_double_star;  }
[:]{1}[=]{1}  { printf("assign '%s' at line %d\n", yytext, lineno); return T_assign; }
[!]{1}[=]{1}  { printf("not_equal '%s' at line %d\n", yytext, lineno); return T_neq; }
[=]{1}[=]{1}  { printf("is_equal '%s' at line %d\n", yytext, lineno); return T_iseq; }
[>]{1}[=]{1}  { printf("greater_equal '%s' at line %d\n", yytext, lineno); return T_greq; }
[<]{1}[=]{1}  { printf("less_equal '%s' at line %d\n", yytext, lineno); return T_leq; }
[<]{1}[>]{1}  { printf("less_greater '%s' at line %d\n", yytext, lineno); return T_legr; }
[-]{1}[.]{1}  { printf("minus_dot '%s' at line %d\n", yytext, lineno); return T_minus_dot; }
[*]{1}[.]{1}  { printf("star_dot '%s' at line %d\n", yytext, lineno); return T_star_dot; }
[/]{1}[.]{1}  { printf("slash_dot '%s' at line %d\n", yytext, lineno); return T_slash_dot; }
[-]{1}[>]{1}  { printf("arrow '%s' at line %d\n", yytext, lineno); return T_arrow; }
"mod" { printf("modulo '%s' at line %d\n", yytext, lineno); return T_mod; }

[=]{1}  { printf("equalop '%c' at line %d\n", yytext[0], lineno); return yytext[0]; }
[-]{1}  { printf("minus '%c' at line %d\n", yytext[0], lineno); return yytext[0]; }
[+]{1}[.]{1}  { printf("plus_dot '%s' at line %d\n", yytext, lineno); return T_plus_dot; }

[a-z]([a-z]|[A-Z]|[0-9]|_)* { printf("identifier '%s' at line %d\n", yytext, lineno); return T_id; }
[A-Z]([a-z]|[A-Z]|[0-9]|_)* { return T_Id; }


\"[^\n"]*\" { return T_string_literal; }
\'([a-z]|[A-Z]){1}\'  { printf("char %s at line %d\n", yytext, lineno); return T_char_const; }

{D}+ { yylval = atoi(yytext); printf("int '%d' at line %d\n", yylval, lineno); return T_int_const; }
{D}+[.]{D}+ { float yyfloat = atof(yytext); printf("float '%f' at line %d\n", yyfloat, lineno); return T_float_const; }


[\(\)\\\/\:\[\]\,\.\|]   { return yytext[0]; }


"(*"              { BEGIN(COMMENT); }
<COMMENT><<EOF>>  { fprintf(stderr, "ERROR: Unfinished comment\n" ); exit(1); }
<COMMENT>"*)"     { BEGIN(INITIAL); }
<COMMENT>\n       {  lineno++;      }
<COMMENT>"*"      {  /* nothing*/   }
<COMMENT>[^*\n]+  {  /*nothing*/    }


"--".*   { /* one line comment */ }

{W}+    { /* nothing */ }

\n    { lineno++; }

.       { fprintf(stderr, "Illegal character '%c' with code %d and line %d\n", yytext[0],  yytext[0], lineno);
          exit(1);
        }

<<EOF>>				{ return T_eof; }

%%
void yyerror(const char *msg) {
  int token;
  token = yylex();
  fprintf(stderr, "%s near lexeme:\"%s\" with token_code:\"%d\" in line %d\n", msg, yytext, token, lineno);
  exit(1);
}
