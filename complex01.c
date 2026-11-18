/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalim <jalim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:48:32 by jalim             #+#    #+#             */
/*   Updated: 2026/11/01 10:48:32 by jalim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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






int	get_max_bit(int	size)
{
	int	i;
	int	count;

	i  = 0;
	count = 0;
	while (((size - 1) >> i) != 0)
	{
		i++;
		count ++;
	}
	return (count);
}

static void assign_indexes(t_stack *game_stack)
{
	t_blob	* current;
	t_blob	* runner;
	int	id;
	
	current =  game_stack->stackA;
	while (current)
	{
		id = 0;
		runner = game_stack->stackA;
		while (runner)
		{
			if (current -> value > runner -> value)
				id++;
			runner = runner -> next;
		}
		current -> rank = id;
		current = current -> next;
	}
}

void radix_sort(t_stack *game_stack)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	if (!(game_stack -> stackA) || !((game_stack -> stackA) ))
		return ;
	
	assign_indexes(game_stack);
	max_bits = get_max_bit(get_stack_length(game_stack->stackA));
		// ft_lstsize(game_stack -> stackA));
	// size = ft_lstsize(game_stack->stackA);
	size = get_stack_length(game_stack->stackA);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if(((game_stack -> stackA)  -> rank >> i) & 1)
				ra(game_stack);
			else
				pb(game_stack);
			j++;
		}
		while ((game_stack -> stackB) )
			pa(game_stack);
		i++;
	}
}
