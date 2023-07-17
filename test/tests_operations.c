#include "tests_linked_list.h"

# define TEST "0 1 2 3 4 5 6 7 8 9 10 11 12 13"

static void	print_stack(t_node *node, size_t size)
{
	t_node *tmp;
	size_t index;
	
	tmp = node;
	index = 0;
	while (index < size)
	{
		printf(GREEN "value: %d\tposition: %ld\n" RESET , tmp->value, tmp->position);
		tmp = tmp->next;
		index++;
	}
	// printf("\n");
	// printf(GREEN "head->prev value: %d\tposition: %ld\n" RESET, node->prev->value, node->prev->position);
	// printf(GREEN "head value: %d\tposition: %ld\n" RESET, node->value, node->position);
	// printf(GREEN "tail value: %d\tposition: %ld\n" RESET, node->prev->value, node->prev->position);
	// printf(GREEN "tail->next value: %d\tposition: %ld\n" RESET, node->prev->next->value, node->prev->next->position);
}

void	rotate_linked_list_tests(void)
{
	char		**test = ft_split(TEST, ' ');
	t_stacks	*stacks;

	stacks = init_stacks(test);
	if (stacks == NULL)
		return ;
	// print_stack(stacks->head_a, stacks->size_a);
	// print_stack(stacks->head_b, stacks->size_b);
	printf("\n\tROTATION TESTS:\n\n");
	// rotate_a(stacks);
	// rotate_a(stacks);
	// rotate_a(stacks);
	// rotate_a(stacks);
	// rotate_a(stacks);
	printf("\n");
	printf("\n\tPUSH TESTS:\n\n");
	push_b(stacks);
	push_b(stacks);
	push_b(stacks);
	push_b(stacks);
	push_b(stacks);
	push_b(stacks);
	push_a(stacks);
	push_a(stacks);
	push_a(stacks);
	push_a(stacks);
	push_a(stacks);
	push_a(stacks);
	push_b(stacks);
	push_a(stacks);
	printf("\n\tstack a\n\n");
	print_stack(stacks->head_a, stacks->size_a);
	printf("\n\tstack b\n\n");
	print_stack(stacks->head_b, stacks->size_b);
	clear_linked_list(stacks->head_a, stacks->size_a);
	clear_linked_list(stacks->head_b, stacks->size_b);
	free(stacks);
	free_strs(test);
	return ;
}
