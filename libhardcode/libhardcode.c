

#include <stdlib.h>
#include "../libstructutils/libfillstruct.h"
#include "../libstructutils/libfilterinput.h"
#include "../libstructutils/libdebug.h"
#include "../getters/libgetters.h"
#include "../libft/libft.h"
#include "../liboperations/liboperations.h"


static int first(t_stack * game_stack){
	return game_stack->a->rank;
}
static int second(t_stack * game_stack){
	return game_stack->a->next->rank;
}

static int third(t_stack * game_stack){
	return game_stack->a->next->next->rank;
}

int process_sort_3(t_stack * game_stack){
	if(get_stack_length(game_stack->a) != 3)
		return 0;
		
	if (first(game_stack) > second(game_stack)
		&& second(game_stack) < third(game_stack) && first(game_stack) < third(game_stack))
		sa(game_stack);
	else if (first(game_stack) > second(game_stack) && second(game_stack) > third(game_stack))
	{
		sa(game_stack);
		rra(game_stack);
	}
	else if (first(game_stack) > second(game_stack)
		&& second(game_stack) < third(game_stack) && first(game_stack) > third(game_stack))
		ra(game_stack);
	else if (first(game_stack) < second(game_stack) && second(game_stack) > third(game_stack) && first(game_stack) < third(game_stack))
	{
		sa(game_stack);
		ra(game_stack);
	}
	else if (first(game_stack) < second(game_stack) && second(game_stack) > third(game_stack) && first(game_stack) > third(game_stack))
		rra(game_stack);
	
	return 1;
}


