#include "push_swap.h"

// void	sort_two_min(t_list **lst, char st);
// void	sort_two_max(t_list **lst, char st);
// void	sort_three_min(t_stc *stack, t_list **lst, char st);
// void	sort_three_max(t_stc *stack, t_list **lst, char st);
// // void	sort_three_b(t_stc *stack);
// void	set_val(t_stc *stack, char st);
// void set_index(t_list *stack);

void	sort_two(t_stc *stack)
{
	if (stack->a->val > stack->a->next->val)
		sa(stack);
}

// void	sort_two_max(t_list **lst)
// {
// 	if ((*lst)->val < (*lst)->next->val)
// 		sa(lst);
// }
void	sort_three(t_stc *stack)
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
void	sort_two_max(t_stc *stack)
{
	if (stack->b->val < stack->b->next->val)
		sb(stack);
}
void	sort_three_max(t_stc *stack)
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
	return ;
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
	return ;
}
void	sort_three_min(t_stc *stack)
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
	if (stack->z > stack->y && stack->z > stack->x && stack->x > stack->y) // x > z > y -- 3 1 2
		sa(stack);
	return ;
}

// 	sort_three_min(t_stc *stack)
// 	// if (stack->x < stack->y && stack->x < stack->z && stack->y < stack->z) // z > y > x -- 1 2 3
// 	// 	sb(stack);
// 	// set_val(stack, 'b');
// 	// if (stack->x < stack->y && stack->x < stack->z && stack->y > stack->z) // y > z > x --  1 3 2
// 	// 	rb(stack);
// 	// if (stack->x > stack->y && stack->x < stack->z && stack->y < stack->z) // z > x > y -- 2 1 3
// 	// 	rrb(stack);
// 	// set_val(stack, 'a');
// }
// void	sort_three_max(t_stc *stack)
// {
// 	set_val(stack, 'b');
// 	if (stack->x > stack->y && stack->x > stack->z && stack->y < stack->z) // x > z > y -- 3 1 2
// 		sb(stack);
// 	if (stack->x < stack->y && stack->x > stack->z && stack->y > stack->z) // y > x > z -- 2 3 1
// 		sb(stack);
// 	if (stack->x < stack->y && stack->x < stack->z && stack->y < stack->z) // z > y > x -- 1 2 3
// 		sb(stack);
// 	set_val(stack, 'b');
// 	if (stack->x < stack->y && stack->x < stack->z && stack->y > stack->z) // y > z > x --  1 3 2
// 		rb(stack);
// 	if (stack->x > stack->y && stack->x < stack->z && stack->y < stack->z) // z > x > y -- 2 1 3
// 		rrb(stack);
// 	// set_val(stack, 'a');
// }
// void	sort_three_max(t_stc *stack, t_list **lst, char st)
// {
// 	set_val(stack, st);
// 	if (stack->x > stack->y && stack->x > stack->z && stack->y < stack->z)
// 		swap(lst, st);
// 	if (stack->x < stack->y && stack->x > stack->z && stack->y > stack->z)
// 		swap(lst, st);
// 	if (stack->x < stack->y && stack->x < stack->z && stack->y < stack->z)
// 		swap(lst, st);
// 	set_val(stack, st);
// 	if (stack->x > stack->y && stack->x < stack->z && stack->y < stack->z)
// 		reverse_rotate(lst, st);
// 	set_val(stack, st);
// 	if (stack->x < stack->y && stack->x < stack->z && stack->y > stack->z)
// 		rotate(lst, st);
// }
// void	sort_three(t_list **stack)
// {
// 	set_val(stack);
// 	if (stack->x < stack->y && stack->x < stack->z && stack->y > stack->z)
// 		sb(stack);
// 	if (stack->x > stack->y && stack->x < stack->z && stack->y < stack->z)
// 		sb(stack);
// 	if (stack->x > stack->y && stack->x > stack->z && stack->y > stack->z)
// 		sb(stack);
// 	set_val(stack);
// 	if (stack->x < stack->y && stack->x > stack->z && stack->y > stack->z)
// 		rrb(stack);
// 	set_val(stack);
// 	if (stack->x > stack->y && stack->x > stack->z && stack->y < stack->z)
// 		rb(stack);
// }

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
		cur->i = j;
		j++;
		cur = cur->next;
	}
}
