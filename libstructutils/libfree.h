#ifndef LIBFREE_H

#define LIBFREE_H


void free_split_string(char ** split_string);
void free_game(t_stack *game_stack);



void fill_stack_values(t_stack* game_stack, int * list_of_numbers, int list_of_numbers_length );
void fill_latest_cost(t_stack * game_stack);



int get_index_from_norm(t_blob* stack, int norm);

#endif // LIBFREE_H
