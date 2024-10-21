/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:30:42 by brunogue          #+#    #+#             */
/*   Updated: 2024/10/08 13:58:45 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;	

	i = 0;
	if (max <= min)
	{
		return (NULL);
	}
	array = (int *)malloc((max - min) * sizeof(int));
	if (array == NULL)
	{
		return (NULL);
	}
	while (min < max)
	{
		array[i] = min;
		i++;
		min++;
	}
	return (array);
}
/*
#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int min = 0;
	int max = 20000;
	int *result;
	int i;
	result = ft_range(min, max);
	i = 0;
	while (i < (max - min))
	{
		printf("%d ", result[i]);
		i++;
	}
	printf("\n");
	free(result);

	return (0);
}*/