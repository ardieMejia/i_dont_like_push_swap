#ifndef LIBGETTER_H

#define LIBGETTER_H


t_blob * get_closest_candidate_from_A(t_blob * stack_A, int norm_from_b);
int get_lowest_cost(t_stack * game_stack, t_blob* candidate_from_A, t_blob* candidate_from_B);
int get_stack_length(t_blob * stack);
t_blob * get_last_blob(t_blob * stack);
t_blob * get_next_to_last_blob(t_blob * stack);

int get_index_from_norm(t_blob* stack, int norm);
int get_norm_from_position(t_blob* stack, int position);
int get_value_from_index(t_blob* blob, int position);

int get_less_than_sqrt(int number);
    
#endif // LIBGETTER_H
