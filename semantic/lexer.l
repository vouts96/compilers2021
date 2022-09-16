%option noyywrap
%x COMMENT
%option yylineno


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
bool letin = false;

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
\'[^\n]\'  { yylval.char_const = yytext[1]; return T_char_const; }



{D}+ { yylval.int_const = atoi(yytext); return T_int_const; }
\'\\[x]([0-9]|[a-z]|[A-Z]){2}\' {
   int temp = 0;
   if(yytext[3] >= '0' && yytext[3] <= '9'){
     temp += ((int)(yytext[3]) - 48) * 16;
   }
   else if(yytext[3] == 'a' || yytext[3] == 'A'){
     temp += 10*16;
   }
   else if(yytext[3] == 'b' || yytext[3] == 'B'){
     temp += 11*16;
   }
   else if(yytext[3] == 'c' || yytext[3] == 'C'){
     temp += 12*16;
   }
   else if(yytext[3] == 'd' || yytext[3] == 'D'){
     temp += 13*16;
   }
   else if(yytext[3] == 'e' || yytext[3] == 'E'){
     temp += 14*16;
   }
   else if(yytext[3] == 'f' || yytext[3] == 'F'){
     temp += 15*16;
   }

   if(yytext[4] >= '0' && yytext[4] <= '9'){
     temp += ((int)(yytext[4]) - 48);
   }
   else if(yytext[4] == 'a' || yytext[4] == 'A'){
     temp += 10;
   }
   else if(yytext[4] == 'b' || yytext[4] == 'B'){
     temp += 11;
   }
   else if(yytext[4] == 'c' || yytext[4] == 'C'){
     temp += 12;
   }
   else if(yytext[4] == 'd' || yytext[4] == 'D'){
     temp += 13;
   }
   else if(yytext[4] == 'e' || yytext[4] == 'E'){
     temp += 14;
   }
   else if(yytext[4] == 'f' || yytext[4] == 'F'){
     temp += 15;
   }
   //printf("%d", temp);
   yylval.int_const = temp;
   return T_int_const;

 }
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

\n    { lineno++;}

.       { fprintf(stderr, "Illegal character '%c' with code %d and line %d\n", yytext[0],  yytext[0], lineno);
          exit(1);
        }

<<EOF>>				{ return T_eof; }

%%
void yyerror(const char *msg) {
  //int token;
  //token = yylex();
  fprintf(stderr, "%s in line %d\n", msg, yylineno);
  exit(1);
}
