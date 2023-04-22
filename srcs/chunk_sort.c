/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:32:19 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/22 23:44:42 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunk_sort(t_stc *stack, int size);
void	send_to_b(t_stc *stack);
void	send_to_a(t_stc *stack, int id);
int		find_id(t_list *lst, int id);
int		find_less_upper(t_list *lst, int upper);

void	chunk_sort(t_stc *stack, int size)
{ 
	int	ck;
	int	i;
	int	n;

	i = 0;
	n = 0;
	ck = (size / 100) + 3;
	stack->upper = 1;
	stack->chunk_size = (size / ck) + (size % ck);
	while (i++ < ck)
	{
		if (i > 1)
			stack->chunk_size = (size / ck);
		stack->lower = stack->upper;
		stack->upper = stack->lower + stack->chunk_size;
		if (i == ck)
			stack->upper -= 3;
		stack->med = stack->lower + (stack->chunk_size / 2);
		send_to_b(stack);
	}
	i = stack_size(stack->a);
	sort_by_len_a(stack, &stack->a, i);
	n = size - i + 1;
	while (--n > 0)
		send_to_a(stack, n);
}

void	send_to_b(t_stc *stack)
{
	int	finder;

	while (stack->pb_cnt < stack->upper - 1)
	{
		finder = find_less_upper(stack->a, stack->upper);
		if (stack_size(stack->a) <= 3)
			return ;
		if (stack->a->id < stack->upper)
		{
			pb(stack);
			stack->pb_cnt++;
			if (stack_size(stack->b) >= 2)
			{
				if (stack->a->id >= stack->upper && stack->b->id < stack->med)
					rr(stack);
				else if ((ft_lstlast(stack->a)->id < stack->upper || finder == -1) && ft_lstlast(stack->b)->id  >= stack->med)
					rrr(stack);
				else if (stack->b->id < stack->med)
					rb(stack);
			}
		}
		else if (ft_lstlast(stack->a)->id < stack->upper || finder == -1)
			rra(stack);
		else
			ra(stack);
	}
}

void	send_to_a(t_stc *stack, int id)
{
	int	finder;

	finder = find_id(stack->b, id);
	while (stack_size(stack->b) != 0)
	{
		if (stack->b->id == stack->a->id - 1)
		{
			pa(stack);
			stack->pa_cnt++;
			return ;
		}
		else if (finder != -1)
			rb(stack);
		else
			rrb(stack);
	}
	return ;
}

int	find_id(t_list *lst, int id)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->id == id)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i < (stack_size(lst) / 2))
		return (i);
	return (-1);
}

int	find_less_upper(t_list *lst, int upper)
{
	t_list	*tmp;
	int		i;
	int		max;
	int		min;

	i = 0;
	min = stack_size(lst);
	max = 0;
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->id < upper)
		{
			if (i <= min)
				min = i;
			else if (i > max)
				max = i;
		}
		tmp = tmp->next;
		i++;
	}
	i = stack_size(lst);
	if (min <= i - max)
		return (min);
	return (-1);
}