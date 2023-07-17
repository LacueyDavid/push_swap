#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int array_size = 500;
	int array[array_size];

	for (int i = 0; i < array_size; i++)
		array[i] = i + 1;

	for (int j = 0; j < 4; j++)
		for (int i = 0; i < array_size; i++)
		{
			int j = rand() % array_size;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}

	for (int i = 0; i < array_size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
