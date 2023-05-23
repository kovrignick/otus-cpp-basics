#pragma once

#include <string>

#include "astnode.hpp"

class Add: public ASTNode {
    public:
        inline Add(ASTNode *lhs, ASTNode *rhs) 
            : ASTNode("+", lhs, rhs) {
            }
};

class Sub: public ASTNode {
    public:
        inline Sub(ASTNode *lhs, ASTNode *rhs) 
            : ASTNode("-", lhs, rhs) {
            }
};

class Mul: public ASTNode {
    public:
        inline Mul(ASTNode *lhs, ASTNode *rhs) 
            : ASTNode("*", lhs, rhs) {
            }
};

class Div: public ASTNode {
    public:
        inline Div(ASTNode *lhs, ASTNode *rhs) 
            : ASTNode("/", lhs, rhs) {
            }
};

class Variable : public ASTNode {
  public:
    Variable(std::string val)
        : ASTNode(val)
        , val_(val) {}

    std::string value() const { return val_; }

  private:
    std::string val_;
};