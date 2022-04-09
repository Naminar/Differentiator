
#include <stdlib.h>
#include "../include/hash_table.h"

void do_hash_table(const char* inp_file)
{
    assert (inp_file);

    Tree* tree_union = (Tree*) calloc(TABLE_SIZE, sizeof(Tree));

    //list_init(&tree_union[0], 2);

    all_list_init(tree_union);

    processing_data(inp_file, tree_union);

    //add_new_word("aav", tree_union);

    //list_insert(&tree_union[0], 0, "aav");

    //printf("%zu\n", DragonHash("aav"));

    ////printf("%zu\n", (tree_union[0].lst[0].next)->frequency);

    //list_insert(&tree_union[0], 1, "a");

    ////printf("%s\n", (tree_union[0].lst[0].next)->word);

    //list_destructor(&tree_union[0]);

    get_info(tree_union);

    all_list_destr(tree_union);

    free(tree_union);

}

void get_info(Tree* tree_union)
{
    assert (tree_union);

    FILE* out_file = fopen("info.txt", "w");

    for (size_t tree_ind = 0; tree_ind < TABLE_SIZE; tree_ind++)
    {
        if (!tree_union[tree_ind].size)
            continue;

        fprintf(out_file, "table ¹%zu\n{\n", tree_ind);

        List* next_cell = tree_union[tree_ind].lst;

        for (size_t list_ind = 0; list_ind < tree_union[tree_ind].size; list_ind++)
        {
            next_cell = next_cell->next;

            fprintf(out_file, "  %s - %zu\n", next_cell->word, next_cell->frequency);
        }

        fprintf(out_file, "}\n\n", tree_ind);
    }

    fclose(out_file);
}

void processing_data(const char* inp_file, Tree* tree_union)
{
    assert (tree_union && inp_file);
    assert (inp_file)              ;

    FILE* read_file = fopen(inp_file, "r");

    assert (read_file);

    char read_line[NAME_LENGTH] = {};

    while (fscanf(read_file, "%"M_SCN_LENGTH"s", read_line) != EOF)
    {
        add_new_word(read_line, tree_union);
    }

    fclose(read_file);
}

void add_new_word(const char* word, Tree* tree_union)
{
    assert (word && tree_union);

    size_t hash = DragonHash(word);

    List* next_cell = tree_union[hash].lst;

    for (size_t key_index = 0; key_index < tree_union[hash].size; key_index++)
    {
        next_cell = next_cell->next;

        if (!strcmp(word, next_cell->word))
        {
            ++next_cell->frequency;

            return;
        }
    }

    list_insert(&tree_union[hash], 0, word);
}

void all_list_init(Tree* tree_union)
{
    assert (tree_union);

    for (size_t ind = 0; ind < TABLE_SIZE;ind++)
        list_init(&tree_union[ind], MAX_LIST_SIZE);//list_init();
}

void all_list_destr(Tree* tree_union)
{
    assert (tree_union);

    for (size_t ind = 0; ind < TABLE_SIZE;ind++)
        list_destructor(&tree_union[ind]);//list_init();
}

size_t DragonHash(const char* word)
{
    assert (word);

    size_t hash = 0;

    size_t records_key = 0;

    size_t data_key = NULL_HASH;

    const unsigned char* word_records = (const unsigned char*) word;

    size_t length = strlen(word);

    switch (length)
    {
        case 1:
        {
            return (NULL_HASH - length + word[0]) % TABLE_SIZE;;

            break;
        }

        case 2:
        {
            data_key += data_key/(word[0] * word[1]);

            data_key = data_key & (~word[1] ^ word[0]);

            records_key += word[0] * word[1];

            break;
        }
    }

    for(size_t ind = 3; ind < length; ind++)
    {
        records_key += 2 * word_records[ind - 1] + word_records[ind - 2] % 2 + word_records[ind - 3];
    }

    switch(records_key % 4)
    {
        case 0:
        {
            records_key = records_key << 4 + 1;

            break;
        }

        case 1:
        {
            records_key = records_key << 8 + 3;

            break;
        }

        case 2:
        {
            records_key = records_key << 12 + 5;

            break;
        }

        case 3:
        {
            records_key = records_key << 16 + 7;

            break;
        }

        default:
        {
            assert (0);

            break;
        }
    }

    for(size_t ind = 1; ind < length; ind++)
    {
        data_key = data_key << 3 + 1;

        data_key = data_key ^ word[ind] + data_key % 3 + word[ind] + word[ind-1] | word[ind];
    }

    size_t secureID[3 + NAME_LENGTH] = {NULL_HASH, records_key, data_key + word[0] + word[1]};

    size_t ind = 0;

    for(ind = 3; ind < length / 2; ind++)
    {
        secureID[ind] = secureID[ind - 1] + secureID[ind - 1] % 5 + 2 * secureID[ind - 2] + secureID[ind - 3] % 13 ;
    }

    return secureID[ind - 1] % TABLE_SIZE;
}
