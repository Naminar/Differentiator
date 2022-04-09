
#ifndef HASHT_

#define HASHT_

#include "../ListPtr/list_ptr.h"

const size_t NULL_HASH      = 0xdd233d4;
const size_t TABLE_SIZE     = 1000;
const size_t MAX_LIST_SIZE  = 1000;

void   do_hash_table    (const char*        );
void   processing_data  (const char*, Tree* );
void   add_new_word     (const char*, Tree* );
void   all_list_init    (Tree*              );
void   all_list_destr   (Tree*              );
void   get_info         (Tree*              );
size_t DragonHash       (const char*        );

#endif
