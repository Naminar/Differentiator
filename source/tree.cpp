
#include "../include/tree.h"

void print_in(Node* node)
{
    if (!node)
        return;

    printf("\(");

    print_in(node->left_son);

    printf(" " CELL_FMT " ", node->cell);

    print_in(node->right_son);

    printf("\)");
}

void print_post(Node* node)
{
    if (!node)
        return;

    print_post(node->left_son);

    print_post(node->right_son);

    printf(CELL_FMT "  ", node->cell);

}

Node* tree_construct(void)
{
    Node* root = (Node*) calloc(1, sizeof(Node));

    assert (root);

    root->left_son  =   nullptr;
    root->right_son =   nullptr;
    root->cell      =   nullptr;

    return root;
}

void tree_destruct(Node* node)
{
    if (node)
    {
        tree_destruct(node->left_son);

        tree_destruct(node->right_son);

        //printf(CELL_FMT, node->cell);

        free(node->cell);

        free(node);
    }
}
