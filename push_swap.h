#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

void simple_while_more_than_0(t_stack * game_stack);
void simple_push_stupidly_back_a(t_stack * game_stack);
void simple_push_all_chunks_to_b(t_stack * game_stack);
void start_simple(t_stack * game_stack);

void start_medium(t_stack * game_stack);
void push_current_upper_chunk_to_b(t_stack * game_stack, int lower, int upper);
void push_back_to_descending(t_stack * game_stack, int lower, int upper);

void base_swap(int * a, int * b);
void display_stack_operations(char * list_of_operations);
void fill_norm(t_stack * game_stack);
t_stack * create_game_stack(int * list_of_numbers, int length);


    
#endif // PUSH_SWAP_H
