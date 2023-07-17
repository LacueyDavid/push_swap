#ifndef TESTS_INPUT_H
# define TESTS_INPUT_H

#include <stdio.h>

#include "../push_swap.h"
#include "../array.h"
#include "../libft.h"
#include "../delete.h"
#include "../error.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

void	error_management_tests();
void array_sorted_and_not_sorted_tests();

#endif
