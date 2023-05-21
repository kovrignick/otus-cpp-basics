#pragma once

#include <string>

#include "astnode.hpp"

class Add: public ASTNode {
    public:
        inline Add(ASTNode *lhs, ASTNode *rhs) 
            : ASTNode(val_, lhs, rhs) {}

    std::string value() const { return val_; }

  private:
    std::string val_ = "+";
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