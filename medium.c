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
#include "libhardcode/libhardcode.h"
#include "push_swap.h"



// int  push_2_to_b(Stack * game_stack){
// 	int err = 0; 
// 	int i = 0;
// 	while (i < 2){		
// 		err = pb(game_stack);
// 		if(err)
// 			return 1;
// 		i++;
// 	}	
// 	return 0;
// }





// void simple_while_more_than_0(Stack * game_stack);
// void simple_push_stupidly_back_a(Stack * game_stack);
// void simple_push_all_chunks_to_b(Stack * game_stack);
void start_medium(t_stack * game_stack)
{

	if(process_sort_3(game_stack))
		return;
	

	// if (game_stack->B)
	// 	printf("\n test %d\n", game_stack->B->value);
	
	int original_size = get_stack_length(game_stack->A);
	int upper = original_size - 1;
	int lower;
	int number_of_buckets = get_less_than_sqrt(upper) / 2;
	// TODO: use this one instead
	// int chunk_size = (original_size + number_of_buckets) / number_of_buckets;
	int chunk_size = (original_size + number_of_buckets - 1) / number_of_buckets;
	
	while(upper > 0){
		lower = upper - chunk_size;
		push_current_upper_chunk_to_b(game_stack, lower, upper);
		push_back_to_descending(game_stack, lower, upper);
		upper = lower;
		
#ifdef DEBUG
		display_state_output(game_stack);
#endif
		

	}
				return;
}


void push_current_upper_chunk_to_b(t_stack * game_stack, int lower, int upper)
{
	int size = get_stack_length(game_stack->A);
	int rank_value_at_top;
	printf("\n upper %d\n", upper);
	printf("\n lower %d\n", lower);
	while(size > 0){
		rank_value_at_top = get_rank_from_position(game_stack->A, 0);
		if (rank_value_at_top >= lower && rank_value_at_top <= upper){
			printf("\n gets pushed\n");
			pb(game_stack);


		}
		else
			ra(game_stack);
		size--;
	}
	
}


void push_back_to_descending(t_stack * game_stack, int lower, int upper){
	int current_rank_value = upper;
	// int current_position;


	printf("\n current lower %d\n", lower);


	while(current_rank_value > lower){
		if (get_index_from_rank(game_stack->B, current_rank_value) < 0)
			return;
		printf("\n curent rank value %d\n", current_rank_value);
		if (get_index_from_rank(game_stack->B, current_rank_value) < get_stack_length(game_stack->B) / 2){			
			while(get_index_from_rank(game_stack->B, current_rank_value) != 0)
				rb(game_stack);

		}
		else
			while(get_index_from_rank(game_stack->B, current_rank_value) != 0)
				rrb(game_stack);
		current_rank_value--;
		pa(game_stack);
	}
}
