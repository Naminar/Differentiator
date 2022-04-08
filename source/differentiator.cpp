
#include "../include/differentiator.h"

void differentiator(void)
{
    Node* root = do_data_loading();//"data.txt");

    //graph_tree_dump(root);

    printf("\n");

    //print_in(root);



    Node* diff_root = diff_node(root);//tree_cpy(root);




    tree_destruct(root);

    do_tree_simplify(&diff_root);

    pro_print(diff_root);

    graph_tree_dump(diff_root);

    //print_in(diff_root);

    tree_destruct(diff_root);



    //graph_tree_dump(root);

    /*Node* copy =  tree_cpy(root);

    graph_tree_dump(copy);

    tree_destruct(copy);*/

    //graph_tree_dump(root);

    //tree_destruct(root);
}




