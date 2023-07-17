#include "tests_input.h"
#include "tests_linked_list.h"

int main()
{
	// printf(BLUE "\n\tArray sorted and array not sorted:\n\n");
	// array_sorted_and_not_sorted_tests();
	// printf("\n");
	printf(BLUE "\n\tError management tests:\n\n");
	error_management_tests();
	printf(BLUE "\n\tLinked list tests:\n\n");
	linked_list_tests();
	rotate_linked_list_tests();
	printf("\n");
	return 0;
}
