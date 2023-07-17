#include "tests_input.h"

///////////////////////////////// SPECIAL TEST 2 /////////////////////////////////

void exec_special_str_test_2(char *test[4])
{
	if (is_input_incorrect(test))
		printf(GREEN "[OK] | special input 2 test: '1 2 \"\"'\n");
	else
		printf(RED "[KO] | special input 2 test: '1 2 \"\"' \n");
}

void	special_test_2()
{
	char *test[5];
	test[0] = "1";
	test[1] = "2";
	test[2] = "";
	test[3] = NULL;
	exec_special_str_test_2(test);
}

///////////////////////////////// SPECIAL TEST /////////////////////////////////

void exec_special_str_test(char *test[3])
{
	if (is_input_incorrect(test))
		printf(GREEN "[OK] | special input test: '\"\" 1'\n");
	else
		printf(RED "[KO] | special input test: '\"\" 1' \n");
}

void	special_test()
{
	char *test[3];
	test[0] = "";
	test[1] = "1";
	test[2] = NULL;
	exec_special_str_test(test);
}

//////////////////////////////// INCORRECT TEST ////////////////////////////////

void exec_incorrect_str_test(char *test[2])
{
	if (is_input_incorrect(test))
		printf(GREEN "[OK] | incorrect input test: '%s'\n", test[0]);
	else
		printf(RED "[KO] | incorrect input test: '%s'\n", test[0]);
}

void	incorrect_string_test(char *str)
{
	char *test[2];
	test[0] = str;
	test[1] = NULL;
	exec_incorrect_str_test(test);
}

///////////////////////////////// CORRECT TEST /////////////////////////////////

void exec_test(char *test[2])
{
	if (is_input_incorrect(test))
		printf(RED "[KO] | test: '%s'\n", test[0]);
	else
		printf(GREEN "[OK] | test: '%s'\n", test[0]);
}

void	correct_string_test(char *str)
{
	char *test[2];
	test[0] = str;
	test[1] = NULL;
	exec_test(test);
}

/////////////////////////// ERROR MANAGEMENTS TEST /////////////////////////////

void	error_management_tests()
{
	correct_string_test("1 2 3 4 5");
	correct_string_test("3 2 1            ");
	correct_string_test("     1    3  2        8 9 2147483647   -2147483648  -42" );
	correct_string_test("1");
	correct_string_test("+1 +2 +4 -1 -2 -4");
	correct_string_test("1 +2 4 -5 +7 32");
	correct_string_test("4 2 90 42 -42");
	correct_string_test("+42 -42");

	printf("\n");

	incorrect_string_test("++1");
	incorrect_string_test("1 ++1");
	incorrect_string_test("1 --1");
	incorrect_string_test("3 2 ++1");
	incorrect_string_test("3 2 --1");
	incorrect_string_test("3 2 +-1");
	incorrect_string_test("3 2 -+1");
	incorrect_string_test("+");
	incorrect_string_test("-");
	incorrect_string_test("--1");
	incorrect_string_test("+1 1");
	incorrect_string_test("2 +1 3 1");
	incorrect_string_test("");
	incorrect_string_test("3 ++2 1");
	incorrect_string_test("0 -0");
	incorrect_string_test("-0 +0");
	incorrect_string_test("0 +0");

	printf("\n");

	special_test();
	special_test_2();
}

