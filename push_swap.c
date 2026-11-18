
 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>



#include "libstructutils/libfillstruct.h"
#include "libstructutils/libfilterinput.h"
#include "libstructutils/libdebug.h"
#include "getters/libgetters.h"
#include "libft/libft.h"
#include "libstructutils/libfree.h"
#include "push_swap.h"







void base_swap(int * a, int * b){
	int temp = * a;
	* a = *b;
	*b = temp;
}






void display_stack_operations(char * list_of_operations){


	// char * test = strdup("hallsd\nlsd");
	// char * test = ft_strdup("hallsd\nlsd");

	

	// list_of_operations[2] = 's';

	// write(int __fd, const void *__buf, size_t __n);
	write(0,list_of_operations , ft_strlen(list_of_operations));
		
}














void fill_rank(t_stack * game_stack)
{

	int stack_a_length = get_stack_length(game_stack->stackA);
	int i ;
	int j ;
				  
	int * temp_array = malloc(sizeof(int) * stack_a_length );

	// if (temp_array[0])
	// 	printf("\n temp_arrat %d\n", temp_array[0]);

	i=0;
	t_blob * current = game_stack->stackA;
	while(current){
		temp_array[i] = current->value;
		current = current->next;
		i++;
	}
	i=0;
	j=0;
	while(i < stack_a_length ){
		j=i;
		while ( j < stack_a_length){
			if (temp_array[i] > temp_array[j])
				base_swap(&(temp_array[i]), &(temp_array[j]));
			j++;
		}
		i++;
	}
	// printf("\n temp_array %d\n", temp_array[0]);
	// printf("\n temp_array %d\n", temp_array[1]);

	i=0;
	j=0;
	current = game_stack->stackA;
	while(i < stack_a_length)
	{
		current = game_stack->stackA;
		while(current){
			if(temp_array[i] == current->value)
				current->rank = i ;
			current = current->next;
		}
		i++;
	}

	// printf("\n game_stack first rank (4 i think): %d\n", game_stack->stackA->rank_index);
	free(temp_array);
}











t_stack * create_game_stack(int * list_of_numbers, int length)

{
	t_stack *game_stack;
		
	game_stack = init_stack();
	game_stack->list_of_operations = NULL;
	fill_stack_values(game_stack, list_of_numbers, length);

	// fill_latest_cost(game_stack);
	fill_rank(game_stack);
	return game_stack;
	
}

void get_method_from_disorder(float computed_value, t_method * method){
	printf("computed disorder: %f", computed_value);
	if (computed_value < 0.2){
		*method = SIMPLE;
	}else if (computed_value < 0.5){
		*method = MEDIUM;
	}else
		*method = COMPLEX;
	
}

float compute_disorder(t_stack * game_stack){
	int mistakes = 0;
	int total_pairs = 0;
	int i = 0;
	int j = 0;
	int size = get_stack_length(game_stack->stackA);
	while(i < size - 1){
		j = i;
                while (j < size - 1) {
                  total_pairs++;
                  j++;
                  if (get_rank_from_position(game_stack->stackA, i) >
                      get_rank_from_position(game_stack->stackA, j))
                    mistakes++;
                }
                i++;
        }
	// *method =  SIMPLE;

	// int dividend = 3;
	// int divisor = 2;
	// float answer = (float)dividend / (float)divisor;


	return (float)mistakes/(float)total_pairs;


}



int main (int argc, char **argv){





	t_method method;

	method = ADAPTIVE;
	char * filtered_input = NULL;

	int * list_of_numbers;

	if(argc == 1){
		printf("\n no arguments\n");
		return 0;
	}

	list_of_numbers = NULL;

	int number_input_start = 1;

	if(!process_valid_input(argc, argv, &number_input_start, &method))
	{
		write(1,"Error\n",6);
		return 1;
	}


	if (argc - number_input_start == 0)
		return 0;

	list_of_numbers = (int * )malloc(sizeof(int) * (argc - number_input_start));


	if (!is_all_numbers(argv+number_input_start, &list_of_numbers, argc - number_input_start)){
		free(list_of_numbers);
		return 1;

	}
	t_stack * game_stack = create_game_stack(list_of_numbers, argc - number_input_start);


	float computed_disorder = compute_disorder(game_stack);
	


	if(method == SIMPLE){
		printf("\n simple\n");
		start_simple(game_stack);
	}else if(method == MEDIUM){
		start_medium(game_stack);
	}
	else if(method == COMPLEX){
		radix_sort(game_stack);
		printf("\n complex\n");
	}
	else if(method == ADAPTIVE)
	{
		get_method_from_disorder(computed_disorder, &method);
		printf("\n adaptive\n");
		free(filtered_input);
		free(list_of_numbers);
		list_of_numbers = NULL;
		free_game(game_stack);
		return 0;
	}
	else
		return 1;
	


	display_stack_operations(game_stack->list_of_operations);

	#ifdef DEBUG
	display_state_output(game_stack);
	#endif

	
	free(filtered_input);
	free(list_of_numbers);

	list_of_numbers = NULL;

	free_game(game_stack);


	return 0;




}


