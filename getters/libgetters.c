#include <stdlib.h>
#include <limits.h>
#include "../libstructutils/libfillstruct.h"
#include "../libstructutils/libfilterinput.h"
#include "libgetters.h"




int get_stack_length(t_blob * stack){
	int i = 0;
	while(stack){
		stack = stack->next;
		i++;
	}
	return i;
}

t_blob * get_closest_candidate_from_A(t_blob * stackA, int rank_from_b){
	t_blob * closest_candidate = stackA;
	while(stackA){
		if(stackA->rank < closest_candidate->rank && stackA->rank > rank_from_b)
			closest_candidate = stackA;
		stackA = stackA->next;
	}
	return closest_candidate;
}

int get_lowest_cost(t_stack * game_stack, t_blob* candidate_from_A, t_blob* candidate_from_B)
{
	// game_stack->stackA->value = 4;
	// amount_to_calculate = 4;
	// printf("\n amount to cauflate %d\n", amount_to_calculate);
	// return 99;
	fill_latest_cost(game_stack);
	int i = 0;
	int combined_cost = 0;
	int lowest_total_cost = INT_MAX;
	int offset_to_search = get_stack_length(game_stack->stackB)/2;
	t_blob * current_tracker = game_stack->stackB;
	int rank_lowest_cost_from_B = current_tracker->rank;
	while(i < offset_to_search && !current_tracker){
		candidate_from_A = get_closest_candidate_from_A(game_stack->stackA, current_tracker->rank);
		combined_cost = candidate_from_A->cost + current_tracker->cost;
		if (combined_cost < lowest_total_cost)
			candidate_from_B = current_tracker;
		current_tracker = current_tracker->next;
		i++;
	}


}


t_blob * get_last_blob(t_blob * stack){

	t_blob * temp_blob = stack;
	while(temp_blob->next){
		temp_blob=temp_blob->next;
	}
	return temp_blob;
}


t_blob * get_next_to_last_blob(t_blob * stack){
	t_blob * temp_blob = stack;
	while(temp_blob->next->next){
		temp_blob=temp_blob->next;
	}
	return temp_blob;	
}

int get_less_than_sqrt(int number){
	int answer = 1;	
	while(answer <= number){
		if (answer*answer > number )
			break;

			
		answer++;
	}
	return answer - 1;
}


int get_value_from_index(t_blob* blob, int position){
	int i = 0;
	int rank = 99;
	while (blob)
	{
		if(i == position)
			return blob->value;
		i++;
		blob=blob->next;		
	}
	return -99;
}

int get_rank_from_position(t_blob* blob, int position){
	int i = 0;
	int rank = 99;
	while (blob)
	{
		if(i == position)
			return blob->rank;
		i++;
		blob=blob->next;		
	}
	return -99;
}

int get_index_from_rank(t_blob* head, int rank)
{
	if (!head)
		abort();
	int i = 0;
	t_blob *current_pointer = head;



	while(current_pointer){
		if (current_pointer->rank == rank)
			return i;
		current_pointer = current_pointer->next;
		i++;
	}

	current_pointer = NULL;

	return -1;

}
