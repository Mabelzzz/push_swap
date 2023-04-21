/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:33:08 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/22 01:33:09 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_val(t_stc *stack, int argc, char **argv);
void	get_list(t_stc *stack);

void	get_val(t_stc *stack, int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argv[1][0] == 0)
		error();
	stack->tmp = malloc(sizeof(char **) * (argc));
	stack->tmp[argc - 1] = NULL;
	while (i < argc - 1)
	{
		stack->tmp[i] = ft_split(argv[i + 1], ' ');
		if (!stack->tmp[i])
			error_free(stack);
		j = 0;
		while (stack->tmp[i][j])
		{
			check_nbr(stack->tmp[i][j], stack);
			stack->cnt++;
			j++;
		}
		i++;
		if (stack->cnt == 0)
			error_free(stack);
	}
}

void	get_list(t_stc *stack)
{
	int		i;
	int		j;
	t_list	*start;
	t_list	*tmp;

	i = 0;
	stack->a = malloc(sizeof(t_stc));
	stack->a->next = NULL;
	while (stack->tmp[i])
	{
		j = 0;
		while (stack->tmp[i][j])
		{
			if (i == 0 && j == 0)
			{
				stack->a->val = ft_atoi(stack->tmp[i][j], stack, 0);
				start = stack->a;
			}
			else
			{
				tmp = malloc(sizeof(t_stc));
				tmp->val = ft_atoi(stack->tmp[i][j], stack, 1);
				tmp->next = NULL;
				stack->a->next = tmp;
				stack->a = stack->a->next;
			}
			j++;
		}
		i++;
	}
	stack->a = start;
 
}
