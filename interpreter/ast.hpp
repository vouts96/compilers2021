#ifndef __AST_HPP__
#define __AST_HPP__


#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stdlib.h>


using namespace std;

#define RED "\033[31m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BLUE "\u001b[34m"
#define GREEN "\u001b[32m"


extern int lineno;
extern void yyerror(const char *msg);


class AST {
public:
  virtual ~AST() {}
  virtual void printOn(std::ostream &out) const = 0;

  virtual void run(std::ostream &out, string scope) const = 0;


};

inline std::ostream& operator<< (std::ostream &out, const AST &t) {
  t.printOn(out);
  return out;
}


class Def: public AST{};



class Expr: public AST{
public:

  virtual void printOn(std::ostream &out) const = 0;

  virtual void run(std::ostream &out, string scope) const = 0;

  //virtual evalRet eval(string scope) const = 0;
};

class ExprList: public Expr{
public:
  ExprList(): expr_list() {}

  void append(Expr *e){ expr_list.push_back(e); }
  virtual void printOn(std::ostream &out) const override{
    if(!expr_list.empty()){
      out << "ExprList(";
      bool first = true;
      for (Expr *e : expr_list) {
        if (!first) out << ", ";
        first = false;
        out << *e;
      }
      out << ")" ;
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
    if(!expr_list.empty()){
      for (Expr *e : expr_list) {
          e->run(out, scope);
      }
    }
  }

  //virtual evalRet eval(string scope) const override{}

  bool isEmpty(){
    if(expr_list.empty()) return true;
    else return false;
  }

private:
  std::vector<Expr *> expr_list;
};






class Id: public Expr {
public:
  Id(string s): idName(s) {}
  virtual void printOn(std::ostream &out) const override {
    out << "id(" << idName << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    ////out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}

  /*
  virtual string run(string s) const override {
    return s;
  }
  */
  string getIdName(){
    return idName;
  }

private:
  string idName;
};


class Type: public AST{
public:
  Type(){}
  Type(string s): typeName(s) {}
  Type(Id *id): idTypeName(id) {}

  virtual void printOn(std::ostream &out) const override{
    if(idTypeName == NULL) out << "Type(" << typeName << ")";
    else out << "Type(" << *idTypeName << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  string getTypeName(){
    return typeName;
  }

private:
  string typeName;
  Id *idTypeName;
};

class TypeToType: public Type{
public:
  TypeToType(Type *t1, Type *t2): type1(t1), type2(t2) {}

  virtual void printOn(std::ostream &out) const override{
    out << "TypeToType(" << *type1 << " -> " << *type2 << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

private:
  Type *type1;
  Type *type2;
};

class TypeRef: public Type{
public:
  TypeRef(Type *t): myType(t) {}

  virtual void printOn(std::ostream &out) const override{
    out << "TypeRef(" << *myType << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

private:
  Type *myType;
};

class ArrayOfType: public Type{
public:
  ArrayOfType(Type *t): myType(t) {}

  virtual void printOn(std::ostream &out) const override{
    out << "ArrayOfType(" << *myType << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

private:
  Type *myType;
};

class TypeList: public Type{
public:
  TypeList(): type_list() {}

  void append(Type *t){ type_list.push_back(t); }

  virtual void printOn(std::ostream &out) const override{
    if(!type_list.empty()){
      out << "TypeList(";
      bool first = true;
      for (Type *t : type_list) {
        if (!first) out << ", ";
        first = false;
        out << *t;
      }
      out << ")" ;
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  bool isEmpty(){
    if(type_list.empty()) return true;
    else return false;
  }

private:
  std::vector<Type *> type_list;
};



class ConstrId: public Expr {
public:
  ConstrId(){}
  ConstrId(string s): idName(s) {}
  virtual void printOn(std::ostream &out) const override {
    out << "constrId(" << idName << ")";
  }


  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
  /*
  virtual string run(string s) const override {
    s = idName;
    return s;
  }
  */
private:
  string idName;
};


class BarConstrs: public ConstrId {
public:
  BarConstrs(): constr_list() {}

  void append(ConstrId *c){ constr_list.push_back(c); }

  virtual void printOn(std::ostream &out) const override{
    if(!constr_list.empty()){
      out << "BarConstrs(";
      bool first = true;
      for (ConstrId *c : constr_list) {
        if (!first) out << ", ";
        first = false;
        out << *c;
      }
      out << ")" ;
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  bool isEmpty(){
    if(constr_list.empty()) return true;
    else return false;
  }

private:
  std::vector<ConstrId *> constr_list;

};


class ConstrOfTypes: public ConstrId {
public:
  ConstrOfTypes(ConstrId *c, TypeList *tl): conName(c), type_list(tl) {}
  virtual void printOn(std::ostream &out) const override {
    out << "ConstrOfTypes(" << *conName << " of ";
    if(type_list != NULL) out << *type_list;
    out << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }
private:
  ConstrId *conName;
  TypeList *type_list;
};



class StringLiteral: public Expr {
public:
  StringLiteral(string s): idName(s) {}
  virtual void printOn(std::ostream &out) const override {
    out << "stringLiteral(" << idName << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  string idName;
};

class CharConst: public Expr {
public:
  CharConst(char c): const_char(c) {}
  virtual void printOn(std::ostream &out) const override {
    out << "char_const(" << const_char << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  char const_char;
};

class FloatConst: public Expr {
public:
  FloatConst(float f): const_float(f) {}
  virtual void printOn(std::ostream &out) const override {
    out << "float_const(" << const_float << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  float const_float;
};


class IntConst: public Expr {
public:
  IntConst(int i): const_int(i) {}
  virtual void printOn(std::ostream &out) const override {
    out << "int_const(" << const_int << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  int const_int;
};


class BoolConst: public Expr {
public:
  BoolConst(string s): const_bool(s) {}
  virtual void printOn(std::ostream &out) const override {
    out << "bool_const(" << const_bool << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  string const_bool;
};


class Pattern: public AST{
public:
  Pattern(){}
  Pattern(char c, int i): char_const(c), int_const(i) { constr_counter = 0; }
  Pattern(string s, float f): str(s), float_const(f) { constr_counter = 1; }
  Pattern(char c): char_const(c) { constr_counter = 2; }
  Pattern(string s): str(s) { constr_counter = 3; }
  Pattern(ConstrId *Id): constr_id(Id) { constr_counter = 4; }
  Pattern(Id *id): id(id) { constr_counter = 5; }


  virtual void printOn(std::ostream &out) const override{
    switch(constr_counter){
      case 0:
        out << "Pattern(" << char_const << ", " << int_const << ")";
      break;
      case 1:
        out << "Pattern(" << str << ", " << float_const << ")";
      break;
      case 2:
        out << "Pattern(" << char_const << ")";
      break;
      case 3:
        out << "Pattern(" << str << ")";
      break;
      case 4:
        out << "Pattern(" << *constr_id << ")";
      break;
      case 5:
        out << "Pattern(" << *id << ")";
      break;
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  char char_const;
  string str;
  int int_const;
  float float_const;
  Id *id;
  ConstrId *constr_id;
  int constr_counter;
};


class PatternList: public Pattern{
public:
  PatternList(): pattern_list() {}

  void append(Pattern *p){ pattern_list.push_back(p); }

  virtual void printOn(std::ostream &out) const override{
    if(!pattern_list.empty()){
      out << "PatternList(";
      bool first = true;
      for (Pattern *p : pattern_list) {
        if (!first) out << ", ";
        first = false;
        out << *p;
      }
      out << ")" ;
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
  }


private:
  std::vector<Pattern *> pattern_list;
};



class Clause: public AST{
public:
  Clause(){}
  Clause(Pattern *p, Expr *e): pattern(p), expr(e) {}

  virtual void printOn(std::ostream &out) const override{
    out << "Clause(" << *pattern << " -> " << *expr << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

private:
  Pattern *pattern;
  Expr *expr;
};


class ClauseList: public Clause{
public:
  ClauseList(): clause_list() {}

  void append(Clause *c){ clause_list.push_back(c); }

  virtual void printOn(std::ostream &out) const override{
    if(!clause_list.empty()){
      out << "ClauseList(";
      bool first = true;
      for (Clause *c : clause_list) {
        if (!first) out << ", ";
        first = false;
        out << *c;
      }
      out << ")" ;
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
  }


private:
  std::vector<Clause *> clause_list;
};



class For: public Expr{
public:
  For(Id *s, Expr *e1, Expr *e2, Expr *e3, bool up): idName(s), expr1(e1), expr2(e2), expr3(e3), to(up) {}

  virtual void printOn(std::ostream &out) const override{
    if(to) out << "For(" << *idName << " = " << *expr1 << " to " << *expr2 << " do " << *expr3 << ")";
    else out << "For(" << *idName << " = " << *expr1 << " downto " << *expr2 << " do " << *expr3 << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}

private:
  Id *idName;
  Expr *expr1, *expr2, *expr3;
  bool to;
};

class While: public Expr{
public:
  While(Expr *c, Expr *e): cond(c), expr(e) {}

  virtual void printOn(std::ostream &out) const override{
    out << "While(" << *cond << " do " << *expr << " done)" << endl;
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}

private:
  Expr *cond, *expr;

};

class If: public Expr{
public:
  If(Expr *e1, Expr *e2, Expr *e3 = nullptr): cond(e1), expr2(e2), expr3(e3) {}

  virtual void printOn(std::ostream &out) const override{
    if(expr3 == nullptr) out << "If(" << *cond << " then\n" << *expr2 << ")" << endl;
    else if(expr3 != nullptr) out << "If(" << *cond << " then\n" << *expr2 << " else " << *expr3 << ")" << endl;
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}

private:
  Expr *cond, *expr2, *expr3;
};


class BinOp: public Expr{
public:
  BinOp(Expr *l, string o, Expr *r): left(l), op(o), right(r) {}

  virtual void printOn(std::ostream &out) const override {
    out << CYAN << "BinOp(" << RESET << *left << " " << op << " " << *right << CYAN << ")" << RESET;
  }

  virtual void run(std::ostream &out, string scope) const override{
    cout << "I am the BinOp\n";
  }

  //virtual evalRet eval(string scope) const override{}

private:
  Expr *left;
  string op;
  Expr *right;

};

class UnOp: public Expr{
public:
  UnOp(string o, Expr *e): op(o), expr(e) {}

  virtual void printOn(std::ostream &out) const override {
    out << op << "(" << *expr << ")" << endl;
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}

private:
  string op;
  Expr *expr;
};

class Begin: public Expr{
public:
  Begin(Expr *e): expr(e) {}

  virtual void printOn(std::ostream &out) const override{
    out << "Begin(" << *expr << "End)" << endl;
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  Expr *expr;
};


class Dim: public Expr{
public:
  Dim(Id *id, bool b): idName(id), twoArgs(b) {}
  Dim(int n, Id *id, bool b): intConst(n), idName(id), twoArgs(b) {}

  virtual void printOn(std::ostream &out) const override{
    if(!twoArgs) out << "Dim(" << *idName << ")";
    else out << "Dim(" << intConst << ", " << *idName  << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  int intConst;
  Id* idName;
  bool twoArgs;
};


class Delete: public Expr{
public:
  Delete(Expr *e): expr(e) {}

  virtual void printOn(std::ostream &out) const override{
    out << "Delete(" << *expr << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  Expr *expr;
};

class CommaExprList: public Expr{
public:
  CommaExprList(){}
  CommaExprList(Id *id): expr_list(), idName(id) {}

  void append(Expr *e){ expr_list.push_back(e); }
  virtual void printOn(std::ostream &out) const override{
    if(!expr_list.empty()){
      out << "CommaExprList(" << *idName << ", ";
      bool first = true;
      for (Expr *e : expr_list) {
        if (!first) out << ", ";
        first = false;
        out << *e;
      }
      out << ")" ;
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}

  bool isEmpty(){
    if(expr_list.empty()) return true;
    else return false;
  }

private:
  std::vector<Expr *> expr_list;
  Id *idName;
};


class MatchExpr: public Expr{
public:
  MatchExpr(Expr *e, ClauseList *cl): expr(e), clause_list(cl) {}

  virtual void printOn(std::ostream &out) const override{
    out << "MatchExpr(" << *expr << " with " << *clause_list << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }
private:
  Expr *expr;
  ClauseList *clause_list;
};

class NewType: public Expr{
public:
  NewType(Type *t): myType(t) {}

  virtual void printOn(std::ostream &out) const override{
    out << "NewType(" << *myType << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}

private:
  Type *myType;
};



class Typedef: public Def{
public:
  Typedef(){}
  //Typedef(Id *id, ConstrId *conId): idName(id), constrIdName(conId) {}
  Typedef(Id *id, ConstrId *conId, BarConstrs *cl): idName(id), constrIdName(conId), constr_list(cl) {}

  virtual void printOn(std::ostream &out) const override{
    out << RED << "Typedef(" << RESET << *idName << ", " << *constrIdName;
    if(!constr_list->isEmpty()) out << *constr_list;
    out << RED << ")" << RESET;
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }
private:
  Id *idName;
  ConstrId *constrIdName;
  BarConstrs *constr_list;
};


class AndTypeDef: public Def{
public:
  AndTypeDef(): def_list() {}

  void append(Def *d){ def_list.push_back(d); }
  virtual void printOn(std::ostream &out) const override{
    if(!def_list.empty()){
      out << "AndTypeDef(";
      out << " " << *def_list.back();
      for (Def *d : def_list) {
        if (d != def_list.back()){
          out << " and ";
          out << *d;
        }
      }
      out << ")";
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  bool isEmpty(){
    if(def_list.empty()) return true;
    else return false;
  }
private:
  std::vector<Def *> def_list;

};

class Par: public Def{
public:
  Par(){}
  Par(Id *p): idName(p){}

  virtual void printOn(std::ostream &out) const override {
    out << "Par(" << *idName << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }


private:
Id *idName;
};


class ParType: public Par{
public:
  ParType(Id *id, Type *t): idName(id), myType(t) {}

  virtual void printOn(std::ostream &out) const override {
    out << "ParType(" << *idName << " : " << *myType << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{ }

private:
  Id *idName;
  Type *myType;
};

class ParList: public Par{
public:
  ParList(): par_list() {}

  void append(Par *p){ par_list.push_back(p); }
  virtual void printOn(std::ostream &out) const override{
    if(!par_list.empty()){
      out << BLUE << "ParList(" << RESET;
      bool first = true;
      for (Par *p : par_list) {
        if (!first) out << ", ";
        first = false;
        out << *p;
      }
      out << BLUE << ")" << RESET;
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
    if(!par_list.empty()){
      for (Par *p : par_list) {
        p->run(out, scope);
      }
    }
  }

  bool isEmpty(){
    if(par_list.empty()) return true;
    else return false;
  }

private:
  std::vector<Par *> par_list;
};

class DefList:public Def{
public:
  DefList(): def_list() {}

  void append(Def *d){ def_list.push_back(d); }
  virtual void printOn(std::ostream &out) const override{
    if(!def_list.empty()){
      out << "DefList(\n";
      bool first = true;
      for (Def *d : def_list) {
        if (!first) out << ",\n  ";
        else out << "  ";
        first = false;
        out << *d;
      }
      out << ")";
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
    if(!def_list.empty()){
      for (Def *d : def_list) {
        d->run(out, "global");
      }
    }
  }

private:
  std::vector<Def *> def_list;
};

class Letdef: public Def{
public:
  Letdef(bool mut, Id *id_name, ParList *pl, Type *t, Expr *e): Mutable(mut), idName(id_name), parList(pl), myType(t), expr(e) {}
  Letdef(bool mut, Id *id_name, ParList *pl, Expr *e): Mutable(mut), idName(id_name), parList(pl), expr(e) { }
  Letdef(bool mut, Id *id_name): Mutable(mut), idName(id_name) {}
  Letdef(bool mut, CommaExprList *cel): Mutable(mut), comma_expr_list(cel) {}
  Letdef(bool mut, Id *id_name, Type *t): Mutable(mut), idName(id_name), myType(t) {}
  Letdef(bool mut, CommaExprList *cel, Type *t): Mutable(mut), comma_expr_list(cel), myType(t) {}

  virtual void printOn(std::ostream &out) const override{
    out << RED << "Let(" << RESET;
    if(Mutable) out << "mutable ";
    if(idName != NULL) out << *idName;
    if(parList != NULL){
      out << ", " << *parList << " ";
    }
    if(myType != NULL) out << ": " << *myType << " ";
    out << "= ";
    if(expr != NULL){
      out << *expr;
    }
    if(comma_expr_list != NULL){
      out << *comma_expr_list;
    }

    out << RED << ")" << RESET;
  }

  virtual void run(std::ostream &out, string scope) const override{}

private:
  bool Mutable;
  Id *idName = NULL;
  ParList *parList = NULL;
  CommaExprList *comma_expr_list = NULL;
  Type *myType = NULL;
  Expr *expr = NULL;
  ExprList *expr_list = NULL;


};


class LetIn: public Def, public Expr {
public:
  LetIn(Def *l, Expr *e): let(l), expr(e) {}

  virtual void printOn(std::ostream &out) const override{
    out << "LetIn(" << *let << " in " << *expr << ")" << endl;
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  Def *let;
  Expr *expr;
};


class AndDef: public Def{
public:
  AndDef(): def_list() {}

  void append(Def *d){ def_list.push_back(d); }
  virtual void printOn(std::ostream &out) const override{
    if(!def_list.empty()){
      out << "AndDef(";
      out << " " << *def_list.back();
      for (Def *d : def_list) {
        if (d != def_list.back()){
          out << " and ";
          out << *d;
        }
      }
      out << ")";
    }
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  bool isEmpty(){
    if(def_list.empty()) return true;
    else return false;
  }
private:
  std::vector<Def *> def_list;
};

class Function_call: public Expr{
public:
  Function_call(Id *id, ExprList *el): idName(id), exprList(el) {}

  virtual void printOn(std::ostream &out) const override{
    if(!(exprList->isEmpty())) out << GREEN << "Function_call(" << RESET << *idName << ", " << *exprList << GREEN << ")" << RESET;
    else out << GREEN "Function_call(" << RESET << *idName << GREEN << ")" << RESET;
  }

  virtual void run(std::ostream &out, string scope) const override{
    idName->run(out, scope);
    exprList->run(out, scope);
  }

  //virtual evalRet eval(string scope) const override{}
private:
  Id *idName;
  ExprList *exprList;
};


class Constr_call: public Expr{
public:
  Constr_call(ConstrId *id, ExprList *el): idName(id), exprList(el) {}

  virtual void printOn(std::ostream &out) const override{
    if(!(exprList->isEmpty())) out << "Constr_call(" << *idName << ", " << *exprList << ")";
    else out << "Constr_call(" << *idName << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

  //virtual evalRet eval(string scope) const override{}
private:
  ConstrId *idName;
  ExprList *exprList;
};



class PatternConstr: public Pattern{
public:
  PatternConstr(ConstrId *c, PatternList *pl): constr_Id(c), pattern_list(pl) {}

  virtual void printOn(std::ostream &out) const override{
    out << "PatternConstr(" << *constr_Id << *pattern_list << ")";
  }

  virtual void run(std::ostream &out, string scope) const override{
    //out << "hello";
  }

private:
  ConstrId *constr_Id;
  PatternList *pattern_list;
};



#endif
