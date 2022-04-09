
#ifndef DATABASE_

#define DATABASE_

#include "tree.h"
#include "config.h"
#include <string.h>

//===============================================

const size_t SYNTAX_ERROR       = 0;

//===============================================

void    load_node       (Node* node, FILE* in_file);
Node*   do_data_loading (const char *const data_file = nullptr);
void argument_reader(FILE* in_file, Node* node);
Node* son_init(Node** one_node_son);
char* scanf_string       (FILE* in_file);
void argument_indent(const char* arg_string, Node* node);
void num_indent(Node* node, const char *const arg_string);
Node* diff_node(Node* node);
Node* new_node(Type a_type, OperAndFunc a_stat =  NULL_OPER, Node* right_node = nullptr, Node* left_node = nullptr);
Node* MUL_node(Node* right_node, Node* left_node);
Node* tree_cpy(Node* main_node);
void do_tree_simplify(Node** node);
Node* simple_node(Node* tested_node);

#endif // DATABASE_
