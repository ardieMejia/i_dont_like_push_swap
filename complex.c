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

typedef struct s_node
{
	int	number;
	int	rank;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

static int	get_max_bit(int	size)
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

static void assign_indexes(t_node *stack_a)
{
	t_node	*current;
	t_node	*runner;
	int	id;
	
	current =  stack_a;
	while (current)
	{
		id = 0;
		runner = stack_a;
		while (runner)
		{
			if (current -> number > runner -> number)
				id++;
			runner = runner -> next;
		}
		current -> rank = id;
		current = current -> next;
	}
}

void radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	if (!stack_a || !*stack_a)
		return ;
	
	assign_indexes(*stack_a);
	max_bits = get_max_bit(ft_lstsize(*stack_a));
	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if(((*stack_a) -> rank >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a,stack_b);
		i++;
	}
}