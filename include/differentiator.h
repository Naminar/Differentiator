
#ifndef differentiator_

#define differentiator_

#include "dump.h"
#include "database.h"
#include "config.h"
#include "tree.h"
#include "latex.h"

void differentiator           (void);
void interectiv         (Node* root);
void fix_mistake        (Node* wrong_node);
void get_object_inform  (Node* node);
Node* diff_node(Node* node);
Node* tree_cpy(Node* main_node);
#endif // differentiator_
