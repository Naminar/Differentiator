
#include "../include/latex.h"

void do_latex_document(Node* root)
{
    FILE* tex_file = fopen("gotovo.tex", "w");

    if (!tex_file)
        printf("open file error");

    assert(root);

    fprintf(tex_file, latex_header);

    forming_notes(tex_file, root);

    fprintf(tex_file, latex_end);
}


void forming_notes(FILE* tex_file, Node* node)
{
    if (!node)
        return;

    if (node->type == OPERATOR && node->data.stat == DIV)
    {
        fprintf(tex_file, "\\frac{");

        forming_notes(tex_file, node->left_son);

        fprintf(tex_file, "}{");

        forming_notes(tex_file, node->right_son);

        fprintf(tex_file, "}");
    }
    else
    {
        if (result_priority(node, node->left_son))
        {
            fprintf(tex_file, "\(");

            forming_notes(tex_file, node->left_son);

            fprintf(tex_file, "\)");
        }
        else
           forming_notes(tex_file, node->left_son);

        latex_node_fmt(tex_file, node);

        if (node->type == OPERATOR && node->data.stat == DEGREE)
            fprintf(tex_file,"{");

        if (result_priority(node, node->right_son))
        {
            fprintf(tex_file, "\(");

            forming_notes(tex_file, node->right_son);

            fprintf(tex_file, "\)");
        }
        else
           forming_notes(tex_file, node->right_son);

        if (node->type == OPERATOR && node->data.stat == DEGREE)
            fprintf(tex_file, "}");

        /*forming_notes(tex_file, node->left_son);

        latex_node_fmt(tex_file, node);

        forming_notes(tex_file, node->right_son);*/
    }
}

void latex_node_fmt(FILE* tex_file, Node* node)
{
    switch (node->type)
    {
        case INT:
        {
            fprintf(tex_file, "%d", node->data.i_num);

            break;
        }

        case DOT:
        {
            fprintf(tex_file, "%.2f", node->data.d_num);

            break;
        }

        case VARIABLE:
        {

            fprintf(tex_file, CELL_FMT, node->cell);

            break;
        }

        case OPERATOR:
        {
            if (node->data.stat == MUL)
                fprintf(tex_file, " \\cdot ", node->data.stat);
            else
                fprintf(tex_file, " %c ", node->data.stat);

            break;
        }

        case FUNCTION:
        {
            fprintf(tex_file, CELL_FMT, node->cell);

            break;
        }
    }
}


