#ifndef LIBFILLSTRUCT_H

#define LIBFILLSTRUCT_H

#include <stdbool.h>


typedef enum  s_method{
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE,
    BENCH
} t_method;





typedef struct s_blob
{
    int value;
    int norm;
    int cost;
    struct s_blob * next;
    struct s_blob * prev;
    bool bench;
}t_blob;


typedef struct s_stack
{
    struct s_blob *stackA;
    struct s_blob *stackB;
    char * list_of_operations;
}t_stack;

t_stack * init_stack();
    

void fill_stack_values(t_stack* game_stack, int * list_of_numbers, int list_of_numbers_length );
void fill_latest_cost(t_stack * game_stack);





#endif // LIBFILLSTRUCT_H
