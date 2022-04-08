
#ifndef STACK_

#define STACK_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ELEMENT_FMT "%p"
                                  //OPEN BY HAND!!
typedef  char* DATA;

//===============================================

const DATA CANARY = (DATA) 19;
const size_t CONTROL_DIMENS = 40; //It was = 200
const size_t NULL_HASH = 0xdd233d4;
const size_t WITH_CANARY_CONTROL_DIMENS = CONTROL_DIMENS + 2;

//===============================================

DATA *const ERR_PTR    = (DATA*) 1;
const int ERR_RESIZE   = 0;
//const int ERR_POP_SIZE = 0;

//===============================================

class cStack{

    private:

    DATA first_canary;

    DATA* data;

    size_t capacity;

    size_t hash;

    DATA second_canary;

    public:

    size_t size;

    //========functions======

    public:

    explicit cStack(int capacity, void* stack_place = NULL)  ;
            ~cStack()                                        ;

    int  stack_resize    ()                                  ;
    int  is_stack_spoiled()                                  ;
    int  stack_push      (DATA  element)                     ;
    int  stack_pop       (DATA* element)                     ;

    private:

    void stack_dump      (int, int, const char*, const char*);
    void DragonHash      ()                                  ;
};

#endif
