/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:33:32 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/22 23:39:48 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quicksort_a(t_list **lst, t_stc *stack, int size);
void	quicksort_b(t_list **lst, t_stc *stack, int size);

void quicksort_a(t_list **lst, t_stc *stack, int size)
{
	static int	id;
	int sz;

	sz = size;
	stack->size_a = stack_size(stack->a);
	stack->size_b = stack_size(stack->b);
	find_min_max_idex(stack->a, stack, size);
	stack->chunk_size = ((size / 2) + (size % 2));
	stack->med = stack->min + stack->chunk_size - 1;
	stack->pb_cnt = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	if (check_sort(stack->a) == 0 && stack->size_b == 0)
		return ;
	if (size <= 3)
	{
		if (size == stack->size_a)
			sort_by_len_a(stack, lst, size);
		else if (size == 2 && stack->a->id > stack->a->next->id)
			sa(stack);
		else if (size == 3)
			sort_3a_top(stack);
		id++;
		return ;
	}
	while (stack->pb_cnt != stack->chunk_size)
	{
		if (stack->a->id <= stack->med)
		{
			pb(stack);
			stack->pb_cnt++;
		}
		else
		{
			ra(stack);
			stack->ra_cnt++;
		}
	}
	while (stack->ra_cnt-- && sz != stack->chunk_size && id)
		rra(stack);
	quicksort_a(lst, stack, sz - stack->chunk_size);
	quicksort_b(lst, stack, sz / 2 + sz % 2);
	return ;
}

void	quicksort_b(t_list **lst, t_stc *stack, int size)
{
	static int	id;
	int			sz;

	sz = size;
	id++;
	stack->size_a = stack_size(stack->a);
	stack->size_b = stack_size(stack->b);
	find_min_max_idex(stack->b, stack, size);
	stack->pa_cnt = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	stack->chunk_size = (size / 2);
	stack->med = stack->min + (size / 2) + (size % 2) - 1;
	if (size <= 3)
	{
		if (size == 2 && stack->b->id < stack->b->next->id)
			sb(stack);
		else if (size == 3 && stack->size_b == 3)
			sort_3b_bottom(stack);
		else if (size == 3)
			sort_3b_top(stack);
		while (size--)
			pa(stack);
		id++;
		return ;
	}
	if (stack_size(stack->b) <= 3)
		return ;
	while (stack->pa_cnt != stack->chunk_size)
	{
		if (stack->b->id > stack->med)
		{
			pa(stack);
			stack->pa_cnt++;
		}
		else
		{
			rb(stack);
			stack->rb_cnt++;
		}
	}
	while (stack->rb_cnt-- > 0 && sz != stack->chunk_size && id)
		rrb(stack);
	quicksort_a(lst, stack, stack->chunk_size);
	quicksort_b(lst, stack, sz / 2 + sz % 2);
	return ;
}