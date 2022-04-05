
#ifndef TREE_

#define TREE_

#include <stdlib.h>
#include <cstdio>
#include <assert.h>
#include "config.h"

#define CELL_FMT "%s"

typedef enum OperAndFunc{

    NULL_OPER = -111,

    #define newoper(name, val, codir,...)\
        name = codir,

    #define newfun(name, codir, ...)\
        name = codir,

    #include "../function"

    #undef newfun
    #undef newoper

    //PLUS   =  '+',
    //MINUS  =  '-',
    //MUL    =  '*',
    //DEGREE =  '^',
    //DIV    =  '/'

} OperAndFunc;

typedef enum Type{

    INT         = 'i',
    DOT         = 'd',
    VARIABLE    = 'v',
    FUNCTION    = 'f',
    OPERATOR    = 'o'

} Type;

typedef union Data{

    int i_num;

    double d_num;

    const char* string;

    OperAndFunc stat; //statement

} Data;

typedef struct Node{

    char* cell;

    Type type;
    Data data;

    Node* left_son;
    Node* right_son;

} Node;

//===============================================

Node* tree_construct    (void);
void tree_destruct      (Node* m_node);
Node* add_node          (int val, Node* m_node);
void print_in           (Node* tree);
void print_post         (Node* tree);

//===============================================

#endif // TREE_
