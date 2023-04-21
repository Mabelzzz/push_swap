#include "../includes/push_swap.h"


void	sort_2a(t_stc *stack)
{
	if (stack->a->val > stack->a->next->val)
		sa(stack);
}

void	sort_2b(t_stc *stack)
{
	if (stack->b->val < stack->b->next->val)
		sb(stack);
}

void	sort_3a(t_stc *stack)
{
	set_val(stack, 'a');
	if (stack->x < stack->y && stack->x < stack->z && stack->y > stack->z)
		sa(stack);
	if (stack->x > stack->y && stack->x < stack->z && stack->y < stack->z)
		sa(stack);
	if (stack->x > stack->y && stack->x > stack->z && stack->y > stack->z)
		sa(stack);
	set_val(stack, 'a');
	if (stack->x < stack->y && stack->x > stack->z && stack->y > stack->z)
		rra(stack);
	set_val(stack, 'a');
	if (stack->x > stack->y && stack->x > stack->z && stack->y < stack->z)
		ra(stack);
}

void	sort_3a_top(t_stc *stack)
{
	set_val(stack, 'a');
	if (check_sort_min(stack->a, 3) == 0)
		return ;
	if (stack->x > stack->y && stack->x > stack->z) 
		sa(stack);
	set_val(stack, 'a');
	if (stack->y > stack->x && stack->y > stack->z) 
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	set_val(stack, 'a');
	if (stack->z > stack->y && stack->z > stack->x && stack->x > stack->y)
		sa(stack);
}

void	sort_3b_top(t_stc *stack)
{

	set_val(stack, 'b');
	if (stack->x < stack->y && stack->x < stack->z)
		sb(stack);
	set_val(stack, 'b');
	if (stack->y < stack->x && stack->y < stack->z)
	{
		rb(stack);
		sb(stack);
		rrb(stack);
		set_val(stack, 'b');
	}
	if (stack->z < stack->y && stack->z < stack->x && stack->y > stack->x)
		sb(stack);
}

void	sort_3b_bottom(t_stc *stack)
{

	set_val(stack, 'b');
	if (stack->x < stack->z && stack->z < stack->y)
		rb(stack);
	else if (stack->x < stack->y && stack->y < stack->z)
	{	
		rb(stack);
		sb(stack);
	}
	else if (stack->x > stack->y && stack->z > stack->x)
		rrb(stack);
	else if (stack->x > stack->z && stack->z > stack->y)
	{	
		rrb(stack);
		sb(stack);
	}
}

void set_val(t_stc *stack, char st)
{
	if (st == 'a')
	{
		stack->x = stack->a->val;
		stack->y = stack->a->next->val;
		stack->z = stack->a->next->next->val;
	}
	if (st == 'b')
	{
		stack->x = stack->b->val;
		stack->y = stack->b->next->val;
		stack->z = stack->b->next->next->val;
	}
}

void set_index(t_list *stack)
{
	t_list	*cur;
	t_list	*check;
	int		i;
	int		j;

	j = 0;
	cur = stack;
	while (cur)
	{
		i = 1;
		check = stack;
		while (check)
		{
			if (cur->val > check->val)
				i++;
			check = check->next;
		}
		cur->id = i;
		// cur->i = j;
		j++;
		cur = cur->next;
	}
}
