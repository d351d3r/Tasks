#include <iostream>
#include <stdlib.h>

int deduction(int* big, int* small, int* result, int max_size)
{
	for (int i = 0; i < (max_size - 1); i++) 
	{
		if (i < (max_size - 1)) 
		{
			big[i + 1]--;
			result[i] += 10 + big[i];
		}
		else 
			result[i] += big[i];

		result[i] -= small[i];

		if (result[i] / 10 > 0)
		{
			result[i + 1]++;
			result[i] %= 10;
		}
	}

	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int check = 3;
	int max_size;
	int size_mas1;
	int size_mas2;

	std::cout << "Длина первого массива чисел: " << std::endl;
	std::cin >> size_mas1;
	max_size = size_mas1;

	std::cout << "Введите первый массив чисел" << std::endl;
	int* mas1 = new int[size_mas1];
	for (int i = 0; i < size_mas1; i++) {
		std::cin >> mas1[i];
	}
	
	std::cout << "Длина второго массива чисел" << std::endl;
	std::cin >> size_mas2;

	std::cout << "Введите второй массив чисел" << std::endl;
	int* mas2 = new int[size_mas2];
	for (int i = 0; i < size_mas2; i++) {
		std::cin >> mas2[i];
	}

	if (size_mas1 > size_mas2)
	{
		max_size = size_mas1;
		check = 1; //  значит первое число длиннее второго
	}
	else
		if (size_mas2 > size_mas1)
		{
			max_size = size_mas2;
			check = 2; //  значит второе число длиннее первого
		}
		else // если числа одинаковой длинны, то необходимо сравнить их веса
			for (int i = 0; i < max_size; i++)
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
	int* mas3 = new int[max_size];
	if (check == 1) deduction(mas1, mas2, mas3, max_size); // Если первое число больше второго
	if (check == 2) deduction(mas2, mas1, mas3, max_size); // Если второе число больше первого
	
	int result = 0; for (int j = 0; j < max_size; j++) result = result * 10 + mas3[max_size];
	std::cout << "\n Результат: \n" << result;
	return 0;
}
