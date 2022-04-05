

#include "../include/tree.h"
#include "../include/database.h"

Node* do_data_loading(const char *const data_file)
{
    //assert (data_file);

    Node* root = tree_construct();

    if (data_file)
    {
        FILE* in_file = fopen(data_file, "r");

        load_node(root, in_file);

        fclose(in_file);
    }
    else
        load_node(root, stdin);

    return root;
}

void load_node(Node* node, FILE* in_file)
{
    if (!node)
        return;

    //printf("h\n");

    static char bracket_case = {};

    bracket_case = getc(in_file);

    if (bracket_case == '(')
    {
        load_node(son_init(&node->left_son), in_file);

        getc(in_file);
    }
    else
        ungetc(bracket_case, in_file);

    argument_reader(in_file, node);//scanf_string(in_file, &node->cell);

    bracket_case =  getc(in_file);

    if (bracket_case == '(')
    {
        load_node(son_init(&node->right_son), in_file);

        getc(in_file);
    }
    else
        ungetc(bracket_case, in_file);

    return;
}

Node* son_init(Node** one_node_son)
{
    Node* son = (Node*) calloc(1, sizeof(Node));

    *one_node_son = son;

    son->left_son  = nullptr;
    son->right_son = nullptr;
    son->cell      = nullptr;

    return son;
}

void argument_reader(FILE* in_file, Node* node)
{
    node->cell = scanf_string(in_file);

    argument_indent(node->cell, node);
}

void argument_indent(const char *const arg_string, Node* node)
{
    assert (node && arg_string);


    #define newoper(name, val, ...)     \
        if (!strcmp(#val, arg_string))  \
        {                               \
            printf(#val" ");            \
                                        \
            node->type = OPERATOR;      \
            node->data.stat = name;     \

        }                               \
        else

    #define newfun(name, ...)           \
        if (!strcmp(#name, arg_string)) \
        {                               \
            printf(#name" ");           \
                                        \
            node->type = FUNCTION;      \
            node->data.stat = name;     \
            node->data.string = #name;  \
                                         \
            printf("%d", node->data.stat);  \
            printf("|%d|", name);              \
                                        \
        }                               \
        else

    #include "../function"

    #undef newfun
    #undef newoper

    if (arg_string[0] >= 'a' && arg_string[0] <= 'z'
        ||
        arg_string[0] >= 'A' && arg_string[0] <= 'Z'
       )
    {
        node->type = VARIABLE;
        node->data.string = arg_string;

        printf("%s ", arg_string);
    }
    else if (arg_string[0] >= '0' && arg_string[0] <= '9')
    {
        num_indent(node, arg_string);
    }

}

char* scanf_string(FILE* in_file)
{
    char input_c   = '\0';

    size_t real_size = 0;

    size_t capacity = WORLD_LENGTH;//useless variable

    char* string = (char*) calloc(capacity, sizeof (char));

    while ((input_c = getc(in_file)) == ' ');

    do
    {
        string[real_size++] = input_c;
        //printf("debufg");
    }
    while ((input_c = getc(in_file)) != ' ' && input_c != '\n' && input_c != ')' && input_c != '(');

    if (input_c == ' ')
    {
        while ((input_c = getc(in_file)) == ' ');
    }

    ungetc(input_c, in_file);

    return string;
}

void num_indent(Node* node, const char *const arg_string)
{
    size_t key = 0;

    while (arg_string[key] != '.'
           &&
           arg_string[key] != '\0'
          )
        ++key;

    if (arg_string[key] == '.')
    {
        node->type = DOT;
        node->data.d_num = atof(arg_string);

        printf("%f ", node->data.d_num);
    }
    else
    {
        node->type = INT;
        node->data.i_num = atoi(arg_string);

        printf("%d ", node->data.i_num);// node->data.i_num);
    }
}

Node* diff_node(Node* node)
{
    if (!node)
        return node;

    switch (node->type)
    {
        case INT:
        {
            Node* the_new_node = new_node(INT);

            the_new_node->data.i_num = 0;

            the_new_node->cell[0] = '0';

            return the_new_node;
        }
        case DOT:
        {
            Node* the_new_node = new_node(INT);

            the_new_node->data.d_num = 0;

            the_new_node->cell[0] = '0';

            return the_new_node;
        }
        case VARIABLE:
        {
            Node* the_new_node = new_node(INT);

            the_new_node->data.i_num = 1;

            the_new_node->cell[0] = '1';

            return the_new_node;
        }
        case FUNCTION:
        {
            printf("sindiff");

            printf("%d", node->data.stat);

            switch (node->data.stat)
            {
                case ln:
                {
                    //return new_node()
                }

                case sin:
                {
                    printf("sindiff");

                    Node* the_new_node = new_node(INT);

                    the_new_node->data.i_num = -1;

                    free(the_new_node->cell);

                    the_new_node->cell = "-1";

                    return new_node(OPERATOR, MUL, diff_node(node->right_son),
                    new_node(OPERATOR, MUL, new_node(FUNCTION, sin, tree_cpy(node->right_son)), the_new_node));
                }

                case cos:
                {
                    //return
                }

            }

            break;
        }
        case OPERATOR:
        {
            switch (node->data.stat)
            {
                case MINUS:
                {
                    return new_node(OPERATOR, MINUS, diff_node(node->right_son), diff_node(node->left_son));
                }

                case PLUS:
                {
                    return new_node(OPERATOR, PLUS, diff_node(node->right_son), diff_node(node->left_son));
                }

                case MUL:
                {
                    return new_node(OPERATOR, PLUS, mul_node(diff_node(node->right_son), tree_cpy(node->left_son)), mul_node( tree_cpy(node->right_son), diff_node(node->left_son)));
                }

                /*case DEGREE:
                {
                    return new_node(OPERATOR, MUL, diff_node(node->right_son), diff_node(node->left_son));
                } */

                case DIV:
                {
                    Node* the_new_node = new_node(INT);

                    the_new_node->data.i_num = 2;

                    the_new_node->cell[0] = '2';

                    return new_node
                    (OPERATOR, DIV,
                     new_node(OPERATOR, DEGREE, the_new_node, tree_cpy(node->right_son)),
                     new_node(OPERATOR, MINUS, mul_node(diff_node(node->right_son), tree_cpy(node->left_son)), mul_node( tree_cpy(node->right_son), diff_node(node->left_son)))
                    );
                }

            }

        }
    }

    return node;
}

Node* new_node(Type a_type, OperAndFunc a_stat, Node* right_node, Node* left_node)
{
    Node* result_node = tree_construct();

    result_node->cell = (char*) calloc(2, sizeof(char));

    result_node->cell[0] = (char) a_stat;

    result_node->type = a_type;

    result_node->data.stat = a_stat;

    result_node->left_son = left_node;

    result_node->right_son = right_node;

    return result_node;
}
Node* tree_cpy(Node* main_node)
{
    if (!main_node)
        return main_node;

    Node* copy_node = (Node*) calloc(1, sizeof(Node));

    assert(copy_node);

    *copy_node = *main_node;

    copy_node->left_son = tree_cpy(main_node->left_son);

    copy_node->right_son = tree_cpy(main_node->right_son);

    return copy_node;
}

Node* mul_node(Node* right_node, Node* left_node)
{
    Node* main_node = (Node*) calloc(1, sizeof(Node));

    assert (main_node);

    main_node->type = OPERATOR;

    main_node->data.stat = MUL;

    main_node->cell = (char*) calloc(2, sizeof(char));

    main_node->cell[0] = (char) MUL;

    main_node->left_son = left_node;

    main_node->right_son = right_node;

    return main_node;
}
