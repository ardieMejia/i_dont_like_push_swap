#ifndef MEDIUM_H

#define MEDIUM_H




void start_medium(t_stack * game_stack);
void push_current_upper_chunk_to_b(t_stack * game_stack, int lower, int upper);
void push_back_to_descending(t_stack * game_stack, int lower, int upper);
    
#endif // MEDIUM_H

