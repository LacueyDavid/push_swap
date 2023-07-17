#include "tests_input.h"

////////////////////// ARRAY SORTED AND NOT SORTED TEST ////////////////////////

void	printf_arrays(t_arrays arrays)
{
	size_t i = 0;
	printf("\narray_not_sorted:\n\n");
	while (i < arrays.size)
	{
		printf("array_not_sorted[%ld] \t%d\n", i, arrays.not_sorted[i]);
		i++;
	}
	i = 0;
	printf("\narray_sorted:\n\n");
	while (i < arrays.size)
	{
		printf("array_sorted[%ld] \t%d\n", i, arrays.sorted[i]);
		i++;
	}
}

void	exec_test_array(char *str)
{
	t_arrays *arrays;

	char **test = ft_split(str, ' ');
	arrays = init_arrays(test);
	printf_arrays(*arrays);
	free_strs(test);
	clear_arrays(arrays);
}

void array_sorted_and_not_sorted_tests()
{
	exec_test_array("1 2 3 4 5");
	exec_test_array("3 2 1");
	exec_test_array("1 3 2 8 9 2147483647 -2147483648 -42");
	exec_test_array("1");
	exec_test_array("+1 +2 +4 -1 -2 -4");
	exec_test_array("1 +2 4 -5 +7 32");
	exec_test_array("4 2 90 42 -42");
	exec_test_array("+42 -42");
}
