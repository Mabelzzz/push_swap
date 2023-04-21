#include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_stc	stack;
// 	int		i;
// 	int		j;
// 	int		nbr;
// 	t_list	*tmp;
// 	t_list	*start;

// 	stack.cnt = 1;
// 	i = 1;
// 	if (argc < 2)
// 		exit(0);
// 	stack.a = malloc(sizeof(t_stc));
// 	stack.a->next = NULL;
// 	while (i < argc)
// 	{
// 		stack.tmp = ft_split(argv[i], ' ');
// 		j = 0;
// 		while (stack.tmp[j])
// 		{
// 			// printf(" %d |%s| -> ", stack.cnt, stack.tmp[j]);
// 			// printf("%d convert to int -->  ", check_nbr(stack.tmp[j]));
// 			// check_duplicate(stack.tmp[j]);
// 			if (check_nbr(stack.tmp[j]) == 1)
// 			{
// 				stack.a->val = ft_atoi(stack.tmp[j]);
// 				printf("%d val --> %d \n", stack.cnt, stack.a->val);
// 				if (stack.cnt == 1)
// 					start = stack.a;
// 			}
// 			else
// 				printf("Error\n");
// 			tmp = malloc(sizeof(t_stc));
// 			tmp->next = NULL;
// 			stack.a->next = tmp;
// 			stack.a = stack.a->next;
// 			free(stack.tmp[j]);
// 			j++;
// 			stack.cnt++;
// 		}
// 		i++;
// 		free(stack.tmp);
// 	}
// 	stack.a = start;
// 	// printf(" cur = % \n", stack.a);
// 	printf("%p\n", stack.a);
// 	swap(&stack.a);
	// while (stack.a)
	// {
	// 	printf("stack.a->val -> %d\n", stack.a->val);
	// 	stack.a = stack.a->next;
	// }
// }

void	init(t_stc *stack)
{
	stack->cnt = 0;
	stack->chunk_size = 0;
	stack->chunk = 0;
	stack->lower = 0;
	stack->upper = 0;
	stack->min = 1;
	stack->max = 0;
	// stack->push_b = 0;
	// stack->push_a = 0;
	stack->med = 0;
	// stack->round = 0;
	stack->pb_cnt = 0;
	stack->pa_cnt = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	// stack->rra_cnt = 0;
	// stack->rrb_cnt = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
}

int	main(int argc, char **argv)
{
	t_stc	stack;

	init(&stack);
	if (argc == 1)
		return (0);
	get_val(&stack, argc, argv);
	get_list(&stack);
	if (check_duplicate(&stack.a) == 1 || stack.cnt == 0)
		error_free(&stack);
	set_index(stack.a);
	if (check_sort(stack.a) == 0)
	{
		free_stack_tmp(&stack);
		free_lst(stack.a);
		return (0);
	}
	sort_by_len_a(&stack, &stack.a, stack.cnt);
	// while (stack.a)
	// {
	// 	printf("|a = %d ---- id = %d\n", stack.a->val, stack.a->id);
	// 	stack.a = stack.a->next;
	// }
	// while (stack.b)
	// {
	// 	printf("|b = %d ---- id = %d\n", stack.b->val, stack.b->id);
	// 	stack.b = stack.b->next;
	// }
	free_stack_tmp(&stack);
	free_lst(stack.a);
	free_lst(stack.b);
}

void	sort_by_len_a(t_stc *stack, t_list **lst, int len)
{
	if (len <= 1)
		return ;
	else if (len == 2)
		sort_2a(stack);
	else if (len == 3)
		sort_3a(stack);
	else if (len <= 15)
		sort_ten(stack, stack->min);
	else if (len == 500)
		quicksort_a(lst, stack, len);
	else
		sort_100(stack, len);
}
// void	sort_by_len_b(t_stc *stack, int len)
// {
// 	// printf("len = %d | min = %d\n", len, stack->min);
// 	if (len == 1)
// 		return ;
// 	else
// 	{

// 	}
// }
// void	sort_bylen_max(t_stc *stack, t_list **lst, char st, int len)
// {
// 	if (len == 2)
// 		sort_2b(lst, st);
// 	else if (len == 3)
// 		sort_3b_top(stack, lst, st);
// }
// void	sort_ab(t_stc *stack, int c)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	*l_a;
// 	t_list	*l_b;

// 	a = stack->a;
// 	b = stack->b;
// 	l_a = ft_lstlast(stack->a);
// 	l_b = ft_lstlast(stack->b);
// 	if (a->id < stack->range * c)
// 	{
// 		pb(stack);
// 		stack->push++;
// 	}
// 	a = stack->a;
// 	b = stack->b;
// 	l_a = ft_lstlast(stack->a);
// 	l_b = ft_lstlast(stack->b);
// 	if (b)
// 	{
// 		if (a->next->id < stack->range * c && a->id <= stack->range * c / 2
// 			&& b->id > b->next->id && b->id <= stack->range * c / 2)
// 			ss(stack);
// 		else if (a->next->id < stack->range * c && a->id > stack->range * c / 2
// 			&& b->id > b->next->id && b->id > stack->range * c / 2)
// 			rr(stack);
// 		else if (l_a->id < stack->range * c && l_a->id <= stack->range * c / 2
// 			&& l_b->id < b->id && l_b->id <= stack->range * c / 2)
// 			rrr(stack);
// 	}
// 	a = stack->a;
// 	b = stack->b;
// 	l_a = ft_lstlast(stack->a);
// 	l_b = ft_lstlast(stack->b);
// 	if (a->next->id < stack->range * c && a->id <= stack->range * c / 2)
// 		swap(&stack->a, 'a');
// 	else if (a->next->id < stack->range * c && a->id > stack->range * c / 2)
// 		rotate(&stack->a, 'a');
// 	else if (l_a->id < stack->range * c && l_a->id <= stack->range * c / 2)
// 		reverse_rotate(&stack->a, 'a');
// 	else
// 		rotate(&stack->a, 'a');
// 	// else if (b->id > b->next->id && b->id < stack->range * c / 2 && stack->b)
// 	// 	swap(&stack->b, 'b');
// 	// else if (b->id > b->next->id && b->id > stack->range * c / 2 && stack->b)
// 	// 	rotate(&stack->b, 'b');
// 	// else if (l_b->id < b->id && l_b->id < stack->range * c / 2 && stack->b)
// 	// 	reverse_rotate(&stack->b, 'b');

// 	// if (check_sort(a) == 1 && check_sort(b) == 1)
// 	// 	sort_ab(stack);
// 	return ;
// }

// void	sort_a(t_stc *stack, t_list *a, t_list *l_a, int c)
// {
// 	// t_list	*a;
// 	// t_list	*l_a;

// 	a = stack->a;
// 	l_a = ft_lstlast(stack->a);
// 	if (a->next->id < stack->range * c && a->id <= stack->range * c / 2)
// 		swap(&stack->a, 'a');
// 	else if (a->next->id < stack->range * c && a->id > stack->range * c / 2)
// 		rotate(&stack->a, 'a');
// 	else if (l_a->id < stack->range * c && l_a->id <= stack->range * c / 2)
// 		reverse_rotate(&stack->a, 'a');
// 	else
// 		rotate(&stack->a, 'a');
// }

// void	sort_b(t_stc *stack, t_list *b, t_list *l_b, int c)
// {
// 	// t_list	*b;
// 	// t_list	*l_b;

// 	b = stack->b;
// 	l_b = ft_lstlast(stack->b);
// 	if (b->id < b->next->id && b->id >= stack->range * c / 2)
// 		swap(&stack->b, 'b');
// 	else if (b->id < b->next->id && b->id < stack->range * c / 2)
// 		rotate(&stack->b, 'b');
// 	else if (l_b->id > b->id && l_b->id > stack->range * c / 2)
// 		reverse_rotate(&stack->b, 'b');
// 	else
// 		rotate(&stack->b, 'b');
// }
int	check_sort(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->id > tmp->next->id)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort_min(t_list *tmp, int len)
{
	t_list *lst;

	lst = tmp;
	while (lst->next && len--)
	{
		if (lst->id > lst->next->id)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	check_sort_max(t_list *tmp, int len)
{
	t_list *lst;

	lst = tmp;
	// set_index(lst);
	while (lst->next && len--)
	{
		if (lst->id < lst->next->id)
			return (1);
		lst = lst->next;
	}
	return (0);
}

