#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libstructutils/libfillstruct.h"
#include "libstructutils/libfilterinput.h"
#include "libstructutils/libdebug.h"
#include "getters/libgetters.h"
#include "libft/libft.h"
#include "libstructutils/libfree.h"
#include "liboperations/liboperations.h"


int simple_pb_one_chunk(t_stack * game_stack, int chunk_start, int chunk_end)
{
	// int size = get_stack_length(game_stack->a);
	int moved = 0;
	// printf("\n szie %d\n", size);
	// printf("\n chunk_end %d\n", chunk_end);
	int rank_at_top;
	int total_to_push = chunk_end - chunk_start;

	while(moved < total_to_push)
	{
		rank_at_top = get_rank_from_position(game_stack->a, 0);
		// printf("\n rank_at_top %d\n", rank_at_top);
		if(rank_at_top > chunk_end){
			ra(game_stack);
		}else{
			pb(game_stack);
			if (rank_at_top < (chunk_start + chunk_end) / 2)
				rb(game_stack);
			moved++;
		}
		// size = get_stack_length(game_stack->a);
	}
	return 0;
}


void simple_while_more_than_0(t_stack * game_stack)
{
	int size = get_stack_length(game_stack->a);
	int chunk_count = 5;
	int chunk_size;
	chunk_size = 5;
	if (size > 20)
		chunk_size = 10;
	if (size > 50)
		chunk_size = 15;
	if(size > 75)
		chunk_count = 20;
	
	chunk_size = size / chunk_count;
	int chunk_start = 0;
	int chunk_end = chunk_size;
	while(chunk_start < size){
		simple_pb_one_chunk(game_stack, chunk_start, chunk_end);
		chunk_start = chunk_end;
		chunk_end = chunk_start + chunk_size;
	}
}



void simple_push_stupidly_back_a(t_stack * game_stack){
	int current_rank;
	int position;
	current_rank = get_stack_length(game_stack->b) - 1;
	// int i = 0;
	while(current_rank > -1){
		   position = get_index_from_rank(game_stack->b, current_rank);

        if (position == -1)
        {
            // printf("Error: rankalized index %d not found in stack B\n",
                // current_rank);
            return;
        }

        while (position != 0)
        {
            if (position < get_stack_length(game_stack->b) / 2)
                rb(game_stack);
            else
                rrb(game_stack);

            position = get_index_from_rank(
                game_stack->b, current_rank);

            if (position == -1)
            {
                return;
            }
        }

        pa(game_stack);
        current_rank--;


	

	}
}


void simple_push_all_chunks_to_b(t_stack * game_stack){
	simple_while_more_than_0(game_stack);
	simple_push_stupidly_back_a(game_stack);	
}

void start_simple(t_stack * game_stack){
	simple_push_all_chunks_to_b(game_stack);
}
