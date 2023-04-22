/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:14:12 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/22 22:15:11 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../gnl/get_next_line.h"

void	init_checker(t_stc *stack);
void	checker(t_stc *stack);
void	read_oprt(t_stc *stack);
int		find_oprt(char *line, size_t len);
void	run_oprt(t_stc *stack, char *oprt);
int		check_stack(t_stc *stack, char *str, size_t len);
void	oprt_ss(t_stc *stack);
void	oprt_rr(t_stc *stack);
void	oprt_rrr(t_stc *stack);

int	main(int argc, char **argv)
{
	t_stc	stack;

	init_checker(&stack);
	if (argc == 1)
		return (0);
	get_val(&stack, argc, argv);
	get_list(&stack);
	if (check_duplicate(&stack.a) == 1 || stack.cnt == 0)
		error_free(&stack);
	set_index(stack.a);
	checker(&stack);
	free_stack_tmp(&stack);
	free_lst(stack.a);
	free_lst(stack.b);
}

void	init_checker(t_stc *stack)
{
	stack->cnt = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
}

void	checker(t_stc *stack)
{
	read_oprt(stack);
	if (!check_sort(stack->a) && !stack_size(stack->b, stack))
		ft_putstr("OK");
	else
		ft_putstr("KO");
}

void	read_oprt(t_stc *stack)
{
	char	*line;
	size_t	len;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		len = ft_strlen(line);
		if(!find_oprt(line, len) || !check_stack(stack, line, len))
		{
			free(line);
			error_free(stack);
		}
		run_oprt(stack, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}
int	check_stack(t_stc *stack, char *str, size_t len)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(stack->a, stack);
	size_b = stack_size(stack->b, stack);
	if (len == 3 && (str[0] == 's' || str[0] == 'r'))
	{
		if (str[1] == 'a' && size_a >= 2)
			return (1);
		else if (str[1] == 'b' && size_b >= 2)
			return (1);
		else if ((str[1] == 's' || str[1] == 'r') && size_a >= 2 && size_b >= 2)
			return (1);
	}
	else if (len == 3 && str[0] == 'p')
	{
		if (str[1] == 'a' && size_b >= 1)
			return (1);
		else if (str[1] == 'b' &&  size_a >= 1)
			return (1);
	}
	else if (len == 4 && str[0] == 'r' && str[1] == 'r')
	{
		if (str[2] == 'a' && size_a >= 2)
			return (1);
		else if (str[2] == 'b' && size_b >= 2)
			return (1);
		else if (str[2] == 'r' && size_a >= 2 && size_b >= 2)
			return (1);
	}
	return (0);
}

int	find_oprt(char *line, size_t len)
{
	if (len == 3)
	{
		if (ft_strncmp(line, "sa\n", 3)
			|| ft_strncmp(line, "sb\n", 3)
			|| ft_strncmp(line, "ss\n", 3)
			|| ft_strncmp(line, "pa\n", 3)
			|| ft_strncmp(line, "pb\n", 3)
			|| ft_strncmp(line, "ra\n", 3)
			|| ft_strncmp(line, "rb\n", 3)
			|| ft_strncmp(line, "rr\n", 3))
			return (1);
	}
	else if (len == 4)
	{
		if (ft_strncmp(line, "rra\n", 4)
			|| ft_strncmp(line, "rrb\n", 4)
			|| ft_strncmp(line, "rrr\n", 4))
			return (1);
	}
	return (0);
}

void	run_oprt(t_stc *stack, char *oprt)
{
	if (ft_strncmp(oprt,"sa\n", 3))
		swap(&stack->a);
	else if (ft_strncmp(oprt,"sb\n", 3))
		swap(&stack->b);
	else if (ft_strncmp(oprt,"ss\n", 3) && stack->a)
		oprt_ss(stack);
	else if (ft_strncmp(oprt,"pa\n", 3))
		ft_lstadd_front(&stack->a, push(&stack->b));
	else if (ft_strncmp(oprt,"pb\n", 3) == 1)
		ft_lstadd_front(&stack->b, push(&stack->a));
	else if (ft_strncmp(oprt,"ra\n", 3))
		rotate(&stack->a);
	else if (ft_strncmp(oprt,"rb\n", 3) == 1)
		rotate(&stack->b);
	else if (ft_strncmp(oprt,"rr\n", 4) == 1)
		oprt_rr(stack);
	else if (ft_strncmp(oprt,"rra\n", 4))
		reverse_rotate(&stack->a);
	else if (ft_strncmp(oprt,"rrb\n", 4) == 1)
		reverse_rotate(&stack->b);
	else if (ft_strncmp(oprt,"rrr\n", 4) == 1)
		oprt_rrr(stack);
	
}

void	oprt_ss(t_stc *stack)
{
		swap(&stack->a);
		swap(&stack->b);
}

void	oprt_rr(t_stc *stack)
{
		rotate(&stack->a);
		rotate(&stack->b);
}

void	oprt_rrr(t_stc *stack)
{
		reverse_rotate(&stack->a);
		reverse_rotate(&stack->b);
}