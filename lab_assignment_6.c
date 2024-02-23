#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	// Assuming the given list, numbers[], is already sorted, search the list for the desired value.

	// Record the value of the centermost element.
	int center = (low + high) / 2;

	// Base case 1: The centermost element of the list is indeed where the value is found.
	if (value == numbers[center]) {
		// The desired value has been found, so return that value.
		return center;
	}

	// Base case 2: All elements in the possible range were searched, none were the value we were looking for.
	if (high < low) {
		// The desired element is not in the list, so return -1 to indicate this result.
		return -1;
	}
	
	// Recursive Case 1: The list is sorted in increasing order and the desired value is less than the centermost element.
	// THus if the desired value can be found, it must be left of the center. So, search that half of the list.
	if (value < numbers[center]) {
		// Take the left half of the list and if the now rightmost element is still not the desired value,
		// remove that element, and repeat until either the value is found, or all possible values have been searched.
		return search(numbers, low, center - 1, value);
	}

	// Recursive Case 2: The list is sorted in increasing order and the desired value is greater than the centermost element.
	// Thus uf the desired value can be found, it must be right of the center. So, search that half of the list.
	if (value > numbers[center]) {
		// Take the right half of the list and if the now leftmost element is still not the desired value,
		// remove that element, and repeat until either the value is found, or all possible values have been searched.
		return search(numbers, center + 1, high, value);
	}

	// The desired value is not within the list, so return -1 to indicate this.
	return -1;

}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}