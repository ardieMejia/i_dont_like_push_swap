#include "../libft/libft.h"
#include "libfillstruct.h"
#include "libfilterinput.h"
#include "libfree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../getters/libgetters.h"

void free_split_string(char ** split_string){
	int i = 0;
	if(split_string){
		while(split_string[i]){
			free(split_string[i]);
			i++;
		}
	}

	free(split_string);
}

void free_game(t_stack *game_stack){
	t_blob * tracker = game_stack->A;
	t_blob * current = game_stack->A;
	
	while(tracker){
		tracker=current->next;
		free(current);
		current=tracker;
	}
	
	tracker = game_stack->B;
	current = game_stack->B;
	
	while(tracker){
		tracker=current->next;
		free(current);
		current=tracker;
	}

	free(game_stack->list_of_operations);

	free(game_stack);
	game_stack=NULL;
	
}
