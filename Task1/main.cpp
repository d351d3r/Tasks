#include <iostream>
#include <algorithm>

int getResult(int* resultmas, int max_size)
{
	std::reverse(resultmas, resultmas + max_size);

	int result = 0;
	for (int i = 0; i < max_size; i++)
		result = result * 10 + resultmas[i];

	return result;
}

int deduction(int* big, int* small, int* resultmas, int max_size, int small_size)
{
	for (int i = 0; i < max_size; i++)
	{
		if (small[i] <= (big[i]))
		{
			resultmas[i] = big[i] - small[i];
		}
		else
		{
			int k = i + 1;
			while (big[k] = 0) ++k;

			big[k]--;
			int j = i + 1;

			while (j < k) {
				big[j] == 9;
				++j;
			}
			resultmas[i] = big[i] + small[i];
			i++;
		}
	}

	int result;
	result = getResult(resultmas, max_size);
	return result;
}
int main()
{
	int check = 3;

	std::cout << "Length of the first array of numbers: " << std::endl;
	int size_mas1;
	std::cin >> size_mas1;
	int max_size = size_mas1;

	std::cout << "Enter the first array of numbers: " << std::endl;
	int* mas1 = new int[size_mas1];
	for (int i = 0; i < size_mas1; i++) {
		std::cin >> mas1[i];
	}

	std::cout << "The length of the second array of numbers: " << std::endl;
	int size_mas2;
	std::cin >> size_mas2;

	std::cout << "Enter the second array of numbers: " << std::endl;
	int* mas2 = new int[size_mas2];
	for (int i = 0; i < size_mas2; i++) {
		std::cin >> mas2[i];
	}

	// Find out in which array the largest number
	if (size_mas1 > size_mas2)
	{
		max_size = size_mas1;
		check = 1; //  then the first number is longer than the second
	}
	else
		if (size_mas2 > size_mas1)
		{
			max_size = size_mas2;
			check = 2; //  then the second number is longer than the first
		}
		else // if the numbers are the same length, then you need to compare their weights
			for (int i = 0; i < max_size; ++i)
			{
				if (mas1[i] > mas2[i])
				{
					check = 1;
					break;
				}

				if (mas2[i] > mas1[i])
				{
					check = 2;
					break;
				}
			}
	// Inverse representation of arrays
	std::reverse(mas1, mas1 + max_size);
	std::reverse(mas2, mas2 + max_size);

	int* mas3 = new int[max_size];
	int result;

	// If the first number is greater than the second
	if (check == 1)
		result = deduction(mas1, mas2, mas3, max_size, size_mas2);

	// If the second number is greater than the first
	else if (check == 2)
		result = deduction(mas2, mas1, mas3, max_size, size_mas1);

	// If the numbers are equal
	else
	{
		std::cout << "Result: 0";
		return 0;
	}

	std::cout << "\n Result: \n" << result;

	delete[] mas1;
	delete[] mas2;
	delete[] mas3;

	return 0;
}
