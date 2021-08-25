%option noyywrap
%x COMMENT


%{
#include <string>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "ast.hpp"
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
"true"    { return T_true;    }
"unit"    { return T_unit;    }
"while"   { return T_while;   }
"with"    { return T_with;    }


"not" { return T_not; }
[!]{1}  { return yytext[0]; }

[+]{1}  { return yytext[0]; }
[;]{1}  { return yytext[0]; }
[/]{1}  { return yytext[0]; }
[*]{1}  { return yytext[0]; }
[<]{1}  { return yytext[0]; }
[>]{1}  { return yytext[0]; }
[&]{2}  { return T_logic_and; }
[|]{2}  { return T_logic_or;  }
[*]{2}  { return T_double_star;  }
[:]{1}[=]{1}  { return T_assign; }
[!]{1}[=]{1}  { return T_neq; }
[=]{1}[=]{1}  { return T_iseq; }
[>]{1}[=]{1}  { return T_greq; }
[<]{1}[=]{1}  { return T_leq; }
[<]{1}[>]{1}  { return T_legr; }
[-]{1}[.]{1}  { return T_minus_dot; }
[*]{1}[.]{1}  { return T_star_dot; }
[/]{1}[.]{1}  { return T_slash_dot; }
[-]{1}[>]{1}  { return T_arrow; }
"mod" { return T_mod; }

[=]{1}  { return yytext[0]; }
[-]{1}  { return yytext[0]; }
[+]{1}[.]{1}  { return T_plus_dot; }

[a-z]([a-z]|[A-Z]|[0-9]|_)* { yylval.id = new Id(yytext); return T_id; }
[A-Z]([a-z]|[A-Z]|[0-9]|_)* { yylval.constrId = new ConstrId(yytext); return T_Id; }


\"[^\n"]*\" { yylval.stringLiteral = new StringLiteral(yytext); return T_string_literal; }
\'([0-9]|[a-z]|[A-Z]|[!]|[@]|[#]|[$]|[%]|[^]|[&]|[*]|[(]|[)]){1}\'  { yylval.char_const = yytext[1]; return T_char_const; }



{D}+ { yylval.int_const = atoi(yytext); return T_int_const; }
{D}+[.]{D}+ { yylval.float_const = atof(yytext); return T_float_const; }


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
  //int token;
  //token = yylex();
  fprintf(stderr, "%s in line %d\n", msg, lineno);
  exit(1);
}
