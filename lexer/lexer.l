%option noyywrap
%x COMMENT

%{
#define T_eof 0
#define T_and 1001
#define T_array 1002
#define T_begin 1003
#define T_bool 1004
#define T_char 1005
#define T_delete 1006
#define T_dim 1007
#define T_do 1008
#define T_done 1009
#define T_downto 1010
#define T_else 1011
#define T_end 1012
#define T_false 1013
#define T_float 1014
#define T_for 1015
#define T_if 1016
#define T_in 1017
#define T_int 1018
#define T_let 1019
#define T_match 1020
#define T_mod 1021
#define T_mutable 1022
#define T_new 1023
#define T_not 1024
#define T_of 1025
#define T_rec 1026
#define T_ref 1027
#define T_then 1028
#define T_to 1029
#define T_true 1030
#define T_type 1031
#define T_unit 1032
#define T_while 1033
#define T_with 1034

//___identifiers and constants______
#define T_id 1035
#define T_Id 1068
#define T_const 1036
#define T_string 1037

//___input-output functions_________
#define T_print_int 1038
#define T_print_bool 1039
#define T_print_char 1040
#define T_print_float 1041
#define T_print_string 1042

#define T_read_int 1043
#define T_read_bool 1044
#define T_read_char 1045
#define T_read_float 1046
#define T_read_string 1047

//___math functions_________________
#define T_abs 1048
#define T_fabs 1049
#define T_sqrt 1050
#define T_sin 1051
#define T_cos 1052
#define T_tan 1053
#define T_atan 1054
#define T_exp 1055
#define T_ln 1056
#define T_pi 1057

//___functions incr-decr____________
#define T_incr 1058
#define T_decr 1059

// ___conversion functions__________
#define T_float_of_int 1060
#define T_int_of_float 1061
#define T_round 1062
#define T_int_of_char 1063
#define T_char_of_int 1064

//___string functions_______________
#define T_strlen 1065
#define T_strcmp 1066
#define T_strcpy 1067
#define T_strcat 1068


#define T_op 1069

int lineno = 1;


%}

l [a-z]
L [A-Z]
D [0-9]
W [ \t\r]

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
"mod"     { return T_mod;     }
"mutable" { return T_mutable; }
"new"     { return T_new;     }
"not"     { return T_not;     }
"of"      { return T_of;      }
"rec"     { return T_rec;     }
"ref"     { return T_ref;     }
"then"    { return T_then;    }
"to"      { return T_to;    }
"type"    { return T_type;    }
"unit"    { return T_unit;    }
"while"   { return T_while;   }
"with"    { return T_with;    }

"print_int"     { return T_print_int;    }
"print_bool"    { return T_print_bool;   }
"print_char"    { return T_print_char;   }
"print_float"   { return T_print_float;  }
"print_string"  { return T_print_string; }

"read_int"     { return T_read_int;    }
"read_bool"    { return T_read_bool;   }
"read_char"    { return T_read_char;   }
"read_float"   { return T_read_float;  }
"read_string"  { return T_read_string; }

"abs"   { return T_abs;  }
"fabs"  { return T_fabs; }
"sqrt"  { return T_sqrt; }
"sin"   { return T_sin;  }
"cos"   { return T_cos;  }
"tan"   { return T_tan;  }
"atan"  { return T_atan; }
"exp"   { return T_exp;  }
"ln"    { return T_ln;   }
"pi"    { return T_pi;   }

"incr"  { return T_incr; }
"decr"  { return T_decr; }

"float_of_int"  { return T_float_of_int; }
"int_of_float"  { return T_int_of_float; }
"round"         { return T_round;        }
"int_of_char"   { return T_int_of_char;  }
"char_of_int"   { return T_char_of_int;  }

"strlen"  { return T_strlen; }
"strcmp"  { return T_strcmp; }
"strcpy"  { return T_strcpy; }
"strcat"  { return T_strcat; }


[&]{2}  { return T_op;  }
[|]{2}  { return T_op;  }
[*]{2}  { return T_op;  }
[:]{1}[=]{1}  { return T_op; }
[!]{1}[=]{1}  { return T_op; }
[=]{1}[=]{1}  { return T_op; }
[>]{1}[=]{1}  { return T_op; }
[<]{1}[=]{1}  { return T_op; }
[<]{1}[>]{1}  { return T_op; }
[-]{1}[>]{1}  { return T_op; }
[-]{1}[.]{1}  { return T_op; }
[+]{1}[.]{1}  { return T_op; }
[*]{1}[.]{1}  { return T_op; }
[/]{1}[.]{1}  { return T_op; }


[a-z]([a-z]|[A-Z]|[0-9])* { return T_id; }
[A-Z]([a-z]|[A-Z]|[0-9])* { return T_Id; }

\"[^\n"]*\" { return T_string; }

[0-9]+ { return T_const; }

[\(\)\+\\\-\/\%\*\=\;\>\<\!\:\[\]\,\.]   { return yytext[0]; }

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


%%

#ifdef yyFlexLexer
int main () {
  yyFlexLexer lexer;
  int token;
  do {
    token = lexer.yylex();
    printf("token=%d, lexeme=\"%s\"\n", token, lexer.YYText());
  } while (token != T_eof);
}
#else
int main () {
  int token;
  do {
    token = yylex();
    printf("token=%d, lexeme=\"%s\"\n", token, yytext);
  } while (token != T_eof);
}
#endif
