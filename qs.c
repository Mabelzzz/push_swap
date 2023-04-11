#include "push_swap.h"

int quicksort(t_list **lst, t_stc *stack, int size)
{
	static int	id;

	id = qs_pb(lst, stack, size);
	while (id--)
	{
		// stack->tmp_sz = cnt_tmp_size
		printf("id-->%d\n", id);
	}
	while (stack->a)
	{
		printf("a = %d ---- id = %d\n", stack->a->val, stack->a->id);
		stack->a = stack->a->next;
	}
	while (stack->b)
	{
		printf("b = %d ---- id = %d| ck_id = %d\n", stack->b->val, stack->b->id, stack->b->chunk_id);
		stack->b = stack->b->next;
	}
	exit(0);
	return (0);
}


int qs_pb(t_list **lst, t_stc *stack, int size)
{
	static int	id;
	static int	id1;
	int sz;

	sz = size;
    // int ra_cnt = 0;
    // int pb_cnt = 0;
	// id = 1;
	stack->size_a = stack_size(stack->a, stack);
	stack->size_b = stack_size(stack->b, stack);
	find_min_max_idex(stack->a, stack, size);

	stack->chunk_size = ((size / 2) + (size % 2));
	stack->med = stack->min + stack->chunk_size - (stack->chunk_size % 2);
	stack->lower = stack->min;
	stack->upper = stack->min + stack->chunk_size - 1;
	stack->pb_cnt = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	id1++;
	if (check_sort(stack->a) == 0 && stack->size_b == 0)
		return (0);
	// printf("min = %d| max = %d| low = %d | up = %d|\n", stack->min, stack->max, stack->lower, stack->upper);
	// printf("Before------> id = %d | size = %d| ck_id = %d|\n", id, size, stack->chunk_size);
	// printf("ck_id = %d | size = %d | pb = %d|\n", stack->chunk_size, size, stack->pb_cnt);
    if (size <= 3)
    {
		if (size == stack->size_a)
			sort_by_len(stack, lst, size);
		else if (size == 2 && stack->a->id > stack->a->next->id)
			sa(stack);
		else if (size == 3)
			sort_three_min(stack);

		// if (size == stack_size(stack->a, stack))
		// printf("min = %d | max = %d | size = %d | id = %d\n", stack->min, stack->max, size, id);
		id++;
        return (id);
		// quicksort_back(&stack->b, stack);
    }
	// if (stack->size_a <= 3)
	// 	return (0);
	while(stack->pb_cnt != stack->chunk_size && size--)
    {
		if (stack->a->id <= stack->upper)
        {
			printf("a = %d | <= | up = %d |\n", stack->a->id , stack->upper);
			stack->a->chunk_id = id1;
            pb(stack);
			// stack->a = stack->a->next;
            stack->pb_cnt++;
        }
		// else if (stack->a->next->id < stack->a->id && stack->size_b >= 2 && stack->b->next->val > stack->b->val)
		// 	ss(stack);
		else
        {
			ra(stack);
			stack->ra_cnt++;
        }
    }
	while (stack->ra_cnt-- && sz != stack->chunk_size)
		rra(stack);
	// id++;
	qs_pb(lst, stack, sz/2);
	// qs_pa(lst, stack, sz/2 + sz%2);
	printf("finish---+___ sz = %d | size_a = %d | chunk_size = %d|\n", sz, stack->size_a, stack->chunk_size);
	printf("finish---+___ sz/2 + sz2 = %d|\n", sz/2 + sz%2); 
	qs_pa(lst, stack, sz/2 + sz%2);
	return (0);
}

int qs_pa(t_list **lst, t_stc *stack, int size)
{
	static int	id;
	int sz;

	sz = size;
	id++;
	stack->size_a = stack_size(stack->a, stack);
	stack->size_b = stack_size(stack->b, stack);
	find_min_max_idex(stack->b, stack, size);

	stack->pa_cnt = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	stack->chunk_size = (size / 2) + (size % 2);
	stack->med = stack->min + stack->chunk_size - (stack->chunk_size % 2);
	stack->lower = stack->min;
	stack->upper = stack->max - stack->chunk_size + 1;
	id++;	
	if (check_sort(stack->a) == 0 && stack->size_b == 0)
		return (0);
    if (size <= 3)
    {
		if (size == 2 && stack->b->id < stack->b->next->id)
			sb(stack);
		else if (size == 3 && stack->size_b == 3)
			sort_3b_bottom(stack);
		else if (size == 3)
			sort_three_max(stack);
		while (size-- && stack->size_b > 3)
		{
			printf("b = %d | sz = %d | up = %d |\n", stack->b->id, size, stack->upper);
			pa(stack);
		}
        return (id);
    }
	if (stack->size_a <= 3)
		return (0);
	while(stack->pa_cnt != stack->chunk_size && size--)
    {
		if (stack->b->id >= stack->upper)
        {
			printf("b = %d | >= | up = %d | size = %d\n", stack->b->id , stack->upper, size);
            pa(stack);
            stack->pa_cnt++;
        }
		else if (stack->rb_cnt++)
        {
			rb(stack);
        }
    }
	while (stack->rb_cnt-- > 0 && sz != stack->chunk_size)
	{
			rrb(stack);
	}
	qs_pb(lst, stack, sz/2 + sz%2);
	printf("finish_a1---+___ sz = %d | size_a = %d | chunk_size = %d|\n", sz, stack->size_a, stack->chunk_size);
	printf("finish_a1---+___ sz/2 + sz2 = %d| >= up = %d\n", sz/2 + sz%2, stack->upper); 
	qs_pa(lst, stack, sz/2);
		printf("finish_a2---+___ sz = %d | size_a = %d | chunk_size = %d|\n", sz, stack->size_a, stack->chunk_size);
	printf("finish_a2---+___ sz/2 + sz2 = %d|\n", sz/2 + sz%2);
	(void) lst; 
	return (0);
}
int qs_pb2(t_list **lst, t_stc *stack, int size)
{
	static int	id;
	static int	id1;
	int sz;

	sz = size;
    // int ra_cnt = 0;
    // int pb_cnt = 0;
	// id = 1;
	stack->size_a = stack_size(stack->a, stack);
	stack->size_b = stack_size(stack->b, stack);
	find_min_max_idex(stack->a, stack, size);

	stack->chunk_size = ((size / 2) + (size % 2));
	stack->med = stack->min + stack->chunk_size - (stack->chunk_size % 2);
	stack->lower = stack->min;
	stack->upper = stack->min + stack->chunk_size - 1;
	stack->pb_cnt = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	id1++;
	if (check_sort(stack->a) == 0 && stack->size_b == 0)
		return (0);
	if (size <= 3)
    {
		if (size == 2 && stack->a->id > stack->a->next->id)
			sa(stack);
		else if (size == 3)
			sort_three_min(stack);
        return (id);
    }
	while(stack->pb_cnt != stack->chunk_size && size-- > 0)
    {
		if (stack->a->id <= stack->upper)
        {
            pb(stack);
            stack->pb_cnt++;
        }
		// else if (stack->a->next->id < stack->a->id && stack->size_b >= 2 && stack->b->next->val > stack->b->val)
		// 	ss(stack);
		else
        {
			ra(stack);
			stack->ra_cnt++;
        }
    }
	while (stack->ra_cnt-- > 0 && sz != stack->chunk_size)
		rra(stack);
	// if(stack->chunk_size <= 3)
	// 	sort_three_min(stack);
	printf("finish_b1---+___ sz = %d | size_a = %d | chunk_size = %d|\n", sz, stack->size_a, stack->chunk_size);
	printf("finish_b1---+___ sz/2 + sz2 = %d|\n", sz/2 + sz%2); 
	qs_pb2(lst, stack,  sz/2 );
	printf("finish_b-m---+___ sz = %d | size_a = %d | chunk_size = %d|\n", sz, stack->size_a, stack->chunk_size);
	printf("finish_b-m---+___ sz/2 + sz2 = %d|\n", sz/2 + sz%2); 
	qs_pa(lst, stack, sz/2 + sz%2);
	printf("finish_b2---+___ sz = %d | size_a = %d | chunk_size = %d|\n", sz, stack->size_a, stack->chunk_size);
	printf("finish_b2---+___ sz/2 + sz2 = %d|\n", sz/2 + sz%2); 
	return (0);
}