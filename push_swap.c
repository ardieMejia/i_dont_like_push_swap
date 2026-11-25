
 
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


void count_assemble_operations_1(t_stack * game_stack, char ** bench_op_string){

		char * sa = ft_itoa(game_stack->op_count.sa);
		char * sb =	ft_itoa(game_stack->op_count.sb);
		char * ss = ft_itoa(game_stack->op_count.ss);
		char * pa = ft_itoa(game_stack->op_count.pa);
		char * pb = ft_itoa(game_stack->op_count.pb);

	
	
	*bench_op_string = ft_strjoin(*bench_op_string, " sa: ");
	*bench_op_string = ft_strjoin(*bench_op_string, sa);
	*bench_op_string = ft_strjoin(*bench_op_string, " sb: ");
	*bench_op_string = ft_strjoin(*bench_op_string, sb);
	*bench_op_string = ft_strjoin(*bench_op_string, " ss: ");
	*bench_op_string = ft_strjoin(*bench_op_string, ss);
	*bench_op_string = ft_strjoin(*bench_op_string, " pa: ");
	*bench_op_string = ft_strjoin(*bench_op_string, pa);
	*bench_op_string = ft_strjoin(*bench_op_string, " pb: ");
	*bench_op_string = ft_strjoin(*bench_op_string, pb);
	*bench_op_string = ft_strjoin(*bench_op_string, "\n");
	free(sa);
	free(sb);
	free(ss);
	free(pa);
	free(pb);

	
}

void count_assemble_operations_2(t_stack * game_stack, char ** bench_op_string){
		
		char * ra = ft_itoa(game_stack->op_count.ra);
		char * rb = ft_itoa(game_stack->op_count.rb);
		char * rr = ft_itoa(game_stack->op_count.rr);
		char * rra = ft_itoa(game_stack->op_count.rra);

			
		*bench_op_string = ft_strjoin(*bench_op_string, " ra: ");
		*bench_op_string = ft_strjoin(*bench_op_string, ra );
		*bench_op_string = ft_strjoin(*bench_op_string, " rb: ");
		*bench_op_string = ft_strjoin(*bench_op_string, rb );
		*bench_op_string = ft_strjoin(*bench_op_string, " rr: ");
		*bench_op_string = ft_strjoin(*bench_op_string, rr );
		*bench_op_string = ft_strjoin(*bench_op_string, " rra: ");
		*bench_op_string = ft_strjoin(*bench_op_string, rra );



		free(ra);
		free(rb);
		free(rr);
		free(rra);

}
void count_assemble_operations_3(t_stack * game_stack, char ** bench_op_string){
		
		char * rrb = ft_itoa(game_stack->op_count.rrb);
		char * rrr = ft_itoa(game_stack->op_count.rrr);
			
	*bench_op_string = ft_strjoin(*bench_op_string, " rrb: ");
	*bench_op_string = ft_strjoin(*bench_op_string, rrb );
	*bench_op_string = ft_strjoin(*bench_op_string, " rrr: ");
	*bench_op_string = ft_strjoin(*bench_op_string, rrr );
	*bench_op_string = ft_strjoin(*bench_op_string, "\n" );


			free(rrb);


			free(rrr);

}


char * bench_method_string_1(t_stack * game_stack){
		char * return_string;

		
	if (game_stack->adaptive_on)
	{
		return_string = ft_strdup("Adaptive / ");
		return return_string;
	}
	else if (game_stack->method == SIMPLE)
	{
		return_string = ft_strdup("Simple / ");
		return return_string;
	}
	else if (game_stack->method == MEDIUM)
	{
		return_string = ft_strdup("Medium / ");
		return return_string;
	}
	else if (game_stack->method == COMPLEX)
	{
		return_string = ft_strdup("Complex / ");
		return return_string;
	}
	return_string = ft_strdup("");
	return return_string;
}

char * bench_method_string_2(t_stack * game_stack){
		char * return_string;

		
		if (game_stack->method == SIMPLE)
		{
				return_string = ft_strdup("0(n2)");
				return return_string;
		}
		else if (game_stack->method == MEDIUM)
		{
				return_string = ft_strdup("0(n/n)");
				return return_string;
		}
		else if (game_stack->method == COMPLEX)
		{
				return ft_strdup("0(nlogn)");
				return return_string;
		}
		return_string = ft_strdup("");	
		return return_string;
}

void assemble_3_first_string(t_stack *game_stack, char ** bs){
		char * cd;
		char * s_bench1 = bench_method_string_1(game_stack);
		char * s_bench2 = bench_method_string_2(game_stack);
		char * ttl_ops = ft_itoa(game_stack->op_count.total);
		cd = ft_ftoa(game_stack->computed_disorder);
		*bs = ft_strjoin(ft_strjoin(*bs, "\n[bench] disorder: "), cd);
		*bs = ft_strjoin(*bs, "%\n[bench] strategy: ");
		*bs = ft_strjoin(ft_strjoin(*bs, s_bench1), s_bench2);
		*bs = ft_strjoin(ft_strjoin(*bs, "\n[bench] total_ops: "), ttl_ops);
		free(cd);
		free(ttl_ops);
		free(s_bench1);
		free(s_bench2);
		
}

void assemble_string(t_stack *game_stack, char ** bs){


		char * bench_op_string = ft_strdup("");
	


		assemble_3_first_string(game_stack, bs);

		count_assemble_operations_1(game_stack, &bench_op_string);
		*bs = ft_strjoin(ft_strjoin(*bs, "\n[bench] "), bench_op_string);
		free(bench_op_string);
		bench_op_string = ft_strdup("");

		count_assemble_operations_2(game_stack, &bench_op_string);
		count_assemble_operations_3(game_stack, &bench_op_string);
		*bs = ft_strjoin(ft_strjoin(*bs, "[bench] "), bench_op_string);


		free(bench_op_string);


	
}

void create_display_bench_string(t_stack *game_stack){
	char * bench_string = ft_strdup("");
	
	assemble_string(game_stack, &bench_string);
	write(2,bench_string , ft_strlen(bench_string));
	free(bench_string);
	      
}

void display_stack_operations(char * list_of_operations){
	write(1,list_of_operations , ft_strlen(list_of_operations));
}


void fill_rank(t_stack * game_stack)
{

	int stack_a_length = get_stack_length(game_stack->a);
	int i ;
	int j ;
				  
	int * temp_array = malloc(sizeof(int) * stack_a_length );

	// if (temp_array[0])
	// 	printf("\n temp_arrat %d\n", temp_array[0]);

	i=0;
	t_blob * current = game_stack->a;
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
	current = game_stack->a;
	while(i < stack_a_length)
	{
		current = game_stack->a;
		while(current){
			if(temp_array[i] == current->value)
				current->rank = i ;
			current = current->next;
		}
		i++;
	}

	// printf("\n game_stack first rank (4 i think): %d\n", game_stack->a->rank_index);
	free(temp_array);
}











void fill_game_stack(t_stack * game_stack, int * list_of_numbers, int length)

{
	// t_stack *game_stack;
		
	// game_stack = init_stack();
	game_stack->list_of_operations = NULL;
	fill_stack_values(game_stack, list_of_numbers, length);

	// fill_latest_cost(game_stack);
	fill_rank(game_stack);
	// return game_stack;
	
}

void get_method_from_disorder(t_stack * game_stack){
	// printf("computed disorder: %f", game_stack->computed_disorder);
	if (game_stack->computed_disorder < 0.2){
		game_stack->method = SIMPLE;
	}else if (game_stack->computed_disorder < 0.5){
		game_stack->method = MEDIUM;
	}else
		game_stack->method = COMPLEX;
	
}


void adaptive_start(t_stack * game_stack){
	game_stack->adaptive_on = true;
	if(game_stack->method == SIMPLE){
		// printf("\n simple\n");
		start_simple(game_stack);
	}else if(game_stack->method == MEDIUM){
		// printf("\n medium\n");
		start_medium(game_stack);
	}
	else if(game_stack->method == COMPLEX){
		radix_sort(game_stack);
		// printf("\n complex\n");
	}
}


void compute_disorder(t_stack * game_stack){
	int mistakes = 0;
	int total_pairs = 0;
	int i = 0;
	int j = 0;
	int size = get_stack_length(game_stack->a);
	while(i < size - 1){
		j = i;
                while (j < size - 1) {
                  total_pairs++;
                  j++;
                  if (get_rank_from_position(game_stack->a, i) >
                      get_rank_from_position(game_stack->a, j))
                    mistakes++;
                }
                i++;
        }
	// *method =  SIMPLE;

	// int dividend = 3;
	// int divisor = 2;
	// float answer = (float)dividend / (float)divisor;


	game_stack->computed_disorder = (float)mistakes/(float)total_pairs;


}



int main (int argc, char **argv){




	t_stack *game_stack;
	// ft_bzero(&game_stack, sizeof(t_stack));
	game_stack = init_stack();

	// 	free_game(game_stack);
	// return 0;
	game_stack->bench = false;
	game_stack->adaptive_on = false;
	game_stack->method = ADAPTIVE;


	char * filtered_input = NULL;

	int * list_of_numbers;

	if(argc == 1){
		// printf("\n no arguments\n");
		return 0;
	}

	list_of_numbers = NULL;

	int number_input_start = 1;

	if(!process_valid_input(game_stack, argc, argv, &number_input_start))
	{
		write(1,"Error\n",6);
		free_game(game_stack);
		return 1;
	}


	if (argc - number_input_start == 0)
		return 0;

	list_of_numbers = (int * )malloc(sizeof(int) * (argc - number_input_start));


	if (!is_all_numbers(argv+number_input_start, &list_of_numbers, argc - number_input_start)){
				// free(filtered_input);
	// free(list_of_numbers);

		free_game(game_stack);
			write(1,"Error\n",6);
			

	// free_game(game_stack);
		free(list_of_numbers);
	// list_of_numbers = NULL;
		return 1;

	}
	fill_game_stack(game_stack, list_of_numbers, argc - number_input_start);


	compute_disorder(game_stack);
	


	if(game_stack->method == SIMPLE){
		// printf("\n simple\n");
		start_simple(game_stack);

	}else if(game_stack->method == MEDIUM){
		start_medium(game_stack);

	}
	else if(game_stack->method == COMPLEX){
		radix_sort(game_stack);
		// printf("\n complex\n");

	}
	else if(game_stack->method == ADAPTIVE)
	{
		get_method_from_disorder(game_stack);
		adaptive_start(game_stack);
		// printf("\n adaptive\n");
		// free(filtered_input);
		// free(list_of_numbers);
		// list_of_numbers = NULL;
		// free_game(game_stack);
		// return 0;
	}
	else
		return 1;
	


	display_stack_operations(game_stack->list_of_operations);
	if (game_stack->bench)
			create_display_bench_string(game_stack);

	#ifdef DEBUG
	display_state_output(game_stack);
	#endif

	
	free(filtered_input);
	free(list_of_numbers);

	list_of_numbers = NULL;

	free_game(game_stack);


	return 0;




}


