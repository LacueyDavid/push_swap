#include "tests_linked_list.h"

# define TEST "0 1 2 3 4"

void	print_stack(t_node *node, size_t size)
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
	printf("\n");
	printf(GREEN "head->prev value: %d\tposition: %ld\n" RESET, node->prev->value, node->prev->position);
	printf(GREEN "head value: %d\tposition: %ld\n" RESET, node->value, node->position);
	printf(GREEN "tail value: %d\tposition: %ld\n" RESET, node->prev->value, node->prev->position);
	printf(GREEN "tail->next value: %d\tposition: %ld\n" RESET, node->prev->next->value, node->prev->next->position);
}

void	linked_list_tests(void)
{
	char		**test = ft_split(TEST, ' ');
	t_stacks	*stacks;

	stacks = init_stacks(test);
	if (stacks == NULL)
		return ;
	print_stack(stacks->head_a, stacks->size_a);
	// print_stack(stacks->head_b, stacks->size_b);
	clear_linked_list(stacks->head_a, stacks->size_a);
	free(stacks);
	free_strs(test);
	return ;
}
