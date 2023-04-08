#pragma once
#include<string>
const int MAX_TOKEN_SIZE;
char TokenString[];
int TokenIndex;
//定义token类型：关键字，运算符，数值，identifier
enum class token_type{
    _null,
    _keyword,  
    _operator,
    _num,
    _id
};
//定义子类型及其转换函数


enum class keyword_type{
     _null,
     _if, 
     _else,
     _int, 
     _return, 
     _void, 
     _while
};
keyword_type string_to_keyword(std::string str);
std::string keyword_to_string(keyword_type key);


enum class operator_type{
    _null,
    _comment, // /*
    _add, // + 
    _sub, // -
    _mul, // * 
    _div, // /
    _les, // <
    _leq, // <= less equal
    _gre, // >
    _geq, // >= greater equal
    _equ, // == equal
    _neq, // != not equal
    _asi, // =
    _sem, // ; semicolon
    _com, // ,
    _slb, // ( small left bracket
    _srb, // ) smal right bracket
    _mlb, // [ medium left bracket
    _mrb, // ] medius rigth bracket
    _llb, // { large left bracket
    _lrb, // } large right bracket
};
operator_type string_to_operator(std::string str);
std::string operator_to_string(operator_type);

// 定义token基本类，并根据行为派生4中不同的token对象
class token_base{
    std::size_t _line = 0, _pos = 0;
public:
    token_base() = default;
    token_base(std::size_t l, std::size_t p): _line(l), _pos(p){}
    virtual  ~token_base() = default;
    // 返回token类型
    virtual token_type get_token_type() const{
        return token_type::_null;
    }
    virtual std::string to_string() const = 0;
    inline std::size_t get_line() const{
        return _line;
    }
    inline std::size_t get_pos() const{
        return _pos;
    }
};
// keyword类
class  token_keyword final : public token_base {
    keyword_type _type;
public:
    ~token_keyword() = default;
    token_keyword(keyword_type t, std::size_t l, std::size_t p): token_base(l,p), _type(t){} 

    std::string to_string() const override{
        return "Keyword:      \t" + keyword_to_string(_type);    
    }
    token_type get_token_type() const override{
        return token_type::_keyword;
    }
};
// 运算符token类
class  token_operator final : public token_base {
    operator_type _type;
public:
    ~token_operator() = default;
    token_operator(operator_type t, std::size_t l, std::size_t p): token_base(l,p), _type(t){} 

    std::string to_string() const override{
        return "Operator:   \t" + operator_to_string(_type);    
    }
    token_type get_token_type() const override{
        return token_type::_operator;
    }
//identifiertoken类
class  token_identifier final : public token_base {
    std::string _ID;
public:
    ~token_identifier() = default;
    token_identifier(std::string id, std::size_t l, std::size_t p): token_base(l,p), _ID(id){} 

    std::string to_string() const override{
        return "Identifier: \t" + _ID;   
    }
    token_type get_token_type() const override{
        return token_type::_id;
    }
};
};
// 数字token类
class  token_number final : public token_base {
    std::string _number;
public:
    ~token_number() = default;
    token_number(std::string number, std::size_t l, std::size_t p): token_base(l,p), _number(number){} 

    std::string to_string() const override{
        return "Number:     \t" + _number;    
    }
    token_type get_token_type() const override{
        return token_type::_num;
    }
};
