#ifndef __SYMBOL_HPP__
#define __SYMBOL_HPP__


#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>

void yyerror(const char *msg);


enum Datatype {
  TYPE_unit,
  TYPE_int,
  TYPE_char,
  TYPE_bool,
  TYPE_float
};

/*
enum StandardType {
  "unit",
  "int",
  "char",
  "bool",
  "float"
};
*/


struct SymbolEntry{
  Datatype datatype;
  SymbolEntry(){}
  SymbolEntry(Datatype dt): datatype(dt) {}

  friend std::ostream& operator << (std::ostream &out, SymbolEntry se){
  //  out << datatype;
  }

  void printOn(std::ostream &out){
    out << datatype;
  }
};


class Scope{
public:
  Scope() {}
  SymbolEntry *lookup(std::string s){
    if(locals.find(s) == locals.end()){
        return nullptr;
    }
    return &locals[s];
  }
  void insert(std::string s, Datatype dt){
    if(locals.find(s) != locals.end()){
        const char *str =  s.c_str();
        yyerror(strcat("Duplicate variable with name: ", str));
    }

    locals[s] = SymbolEntry(dt);
  }

  void printOn(std::ostream &out){
    std::map<std::string, SymbolEntry>::iterator it;
    for(it = locals.begin(); it != locals.end(); ++it)
      out << it->first << " " << it->second << std::endl;
  }
private:
  std::map<std::string, SymbolEntry> locals;

};

class SymbolTable{
public:
  SymbolEntry *lookup(std::string s){
      for(auto i = scopes.rbegin(); i != scopes.rend(); ++i){
        SymbolEntry *e = i->lookup(s);
        if(e != nullptr) return e;
      }
      const char *str =  s.c_str();
      yyerror(strcat("Could not find variable with name: ", str));
      return nullptr;
  }

  void insert(std::string s, Datatype dt){
    scopes.back().insert(s, dt);
  }

  void openScope(){
    scopes.push_back(Scope());
  }

  void closeScope(){
    scopes.pop_back();
  }

  void printOn(std::ostream &out){
    for(auto i = scopes.rbegin(); i != scopes.rend(); ++i){
      i->printOn(out);
    }
  }

/*
  Datatype getEnumType(std::string type){
    switch(type){
      case "unit":
        return Datatype[0];
        break;
      case "int":
        return Datatype[1];
        break;
      case "char":
        return Datatype[2];
        break;
      case "bool":
        return Datatype[3];
        break;
      case "float":
        return Datatype[4];
        break;
    }
  }
*/


private:
  std::vector<Scope> scopes;
};

extern SymbolTable st;

#endif
