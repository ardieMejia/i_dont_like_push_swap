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

typedef struct  s_op_count{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;

} t_op_count;





typedef struct s_blob
{
    int value;
    int rank;
    struct s_blob * next;
    struct s_blob * prev;

}t_blob;


typedef struct s_stack
{
    struct s_blob *a;
    struct s_blob *b;
    char * list_of_operations;
    // char * bench_string;
    bool bench;    
    bool adaptive_on;
    t_method method;
    t_op_count op_count;
    float computed_disorder;
}t_stack;

t_stack * init_stack();
    

void fill_stack_values(t_stack* game_stack, int * list_of_numbers, int list_of_numbers_length );
// void fill_latest_cost(t_stack * game_stack);





#endif // LIBFILLSTRUCT_H
