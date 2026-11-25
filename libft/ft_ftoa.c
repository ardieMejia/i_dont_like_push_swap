/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arwan <arwan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 10:18:59 by arwan             #+#    #+#             */
//   Updated: 2026/11/26 01:07:32 by arwan            ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>



char	*ft_ftoa(float n)
{
	char * return_string = ft_strdup("");
	char * s_integer_part;
	char * s_fractional_part;
	
	// printf("ORIGINAL FLOAT %f", n);

	n = n*100;
	int integer_part = (int)n;
	s_integer_part = ft_itoa(integer_part);
	return_string = ft_strjoin(return_string, s_integer_part);
	return_string = ft_strjoin(return_string, ".");

	int fractional_part = (int)(((float)n - (float)((int)n)) * 100);
	s_fractional_part = ft_itoa(fractional_part);
	return_string = ft_strjoin(return_string, s_fractional_part);
	// return_string = ft_strjoin(return_string, ".")q


	free(s_integer_part);
	free(s_fractional_part);
	return return_string;
	

}
