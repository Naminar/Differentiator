
#include <stdio.h>
#include <stdlib.h>
#include "include/hash_table.h"

int main(int n_args, char *p_args[])
{
    if (n_args == 2)
    {
        do_hash_table(p_args[1]);
    }
    else
    {
        const char read_file[] = "box/empty.txt";

        do_hash_table(read_file);
    }

    return 0;
}
