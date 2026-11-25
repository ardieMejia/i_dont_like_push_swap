
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../libstructutils/libfillstruct.h"
#include "../libstructutils/libfilterinput.h"
#include "../libstructutils/libfree.h"
#include "../getters/libgetters.h"


int ra(t_stack * game_stack){
	if (!game_stack->a)
		return 1;
	if (get_stack_length(game_stack->a) == 1)
		return 0;
	
	t_blob * old_head = game_stack->a;
	t_blob * new_head = game_stack->a->next;
	t_blob * last_blob = get_last_blob(game_stack->a);
	last_blob->next = old_head;
	old_head->next = NULL;
	game_stack->a = new_head;

	
	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "ra\n");
	game_stack->op_count.ra += 1;
	game_stack->op_count.total += 1;

	
	// game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "ra\n");
	old_head = NULL;
	new_head = NULL;
	last_blob = NULL;
	return 0;
}

int rrb(t_stack * game_stack){
	if (!game_stack->b){
		return 1;
	}

	t_blob * temp_last_blob = get_last_blob(game_stack->b);
	t_blob * temp_next_to_last_blob = get_next_to_last_blob(game_stack->b);
	temp_last_blob->next = game_stack->b;
	game_stack->b = temp_last_blob;
	temp_next_to_last_blob->next = NULL;

	// char *temp_list_of_operations = ft_strjoin(game_stack->list_of_operations, "rrb\n");
	// free(game_stack->list_of_operations);
	// game_stack->list_of_operations = temp_list_of_operations;

	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "rrb\n");
	game_stack->op_count.rrb += 1;
	game_stack->op_count.total += 1;
	
	temp_last_blob = NULL;
	temp_next_to_last_blob = NULL;
	return 0;
}


int rra(t_stack * game_stack){
	if (!game_stack->a){
		return 1;
	}

	t_blob * temp_last_blob = get_last_blob(game_stack->a);
	t_blob * temp_next_to_last_blob = get_next_to_last_blob(game_stack->a);
	temp_last_blob->next = game_stack->a;
	game_stack->a = temp_last_blob;
	temp_next_to_last_blob->next = NULL;

	char *temp_list_of_operations = ft_strjoin(game_stack->list_of_operations, "rra\n");
	game_stack->op_count.rra += 1;
		game_stack->op_count.total += 1;
	free(game_stack->list_of_operations);
	game_stack->list_of_operations = temp_list_of_operations;
	
	temp_last_blob = NULL;
	temp_next_to_last_blob = NULL;
	return 0;
}


int pb(t_stack * game_stack)
{
	if (!game_stack->a){
		return 1;
	}

	t_blob * temp_blob = game_stack->a;
	game_stack->a = game_stack->a->next;
	temp_blob->next = game_stack->b;
	game_stack->b = temp_blob;

	temp_blob = NULL;
	
	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "pb\n");
	game_stack->op_count.pb += 1;
		game_stack->op_count.total += 1;
	return 0;
}


int pa(t_stack * game_stack)
{
	if (!game_stack->b){
		return 1;
	}

	t_blob * temp_blob = game_stack->b;
	game_stack->b = game_stack->b->next;
	temp_blob->next = game_stack->a;
	game_stack->a = temp_blob;

	temp_blob = NULL;
	
	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "pa\n");
	game_stack->op_count.pa += 1;
		game_stack->op_count.total += 1;
	return 0;

}

int rb(t_stack * game_stack){
	if (!game_stack->b)
		return 1;
	if (get_stack_length(game_stack->b) == 1)
		return 0;
	
	t_blob * old_head = game_stack->b;
	t_blob * new_head = game_stack->b->next;
	t_blob * last_blob = get_last_blob(game_stack->b);
	last_blob->next = old_head;
	old_head->next = NULL;
	game_stack->b = new_head;


	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "rb\n");
	game_stack->op_count.rb += 1;
		game_stack->op_count.total += 1;

	// game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "rb\n");
	old_head = NULL;
	new_head = NULL;
	last_blob = NULL;
	return 0;

}


int sa(t_stack * game_stack){
	if (get_stack_length(game_stack->a) < 2)
		return 1;
	t_blob * new_head = game_stack->a->next;
	
	game_stack->a->next = new_head->next;
	new_head->next = game_stack->a;
	game_stack->a = new_head;

	game_stack->list_of_operations = ft_strjoin(game_stack->list_of_operations, "sa\n");
	game_stack->op_count.sa += 1;
		game_stack->op_count.total += 1;
	
	new_head = NULL;
	return 0;
}
