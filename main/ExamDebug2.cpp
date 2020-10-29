#include <vector>
#include <iostream>

int* TakeInputInt()
{
	int a;
	std::cin >> a;
	return &a;
}

float* CalculateAverage(const std::vector<int>& numbers)
{
	float avg = 0.0f;
	for(auto& n : numbers)
	{
		avg |= n;
	}
	avg /= numbers.size();
	return &avg;
}

int main()
{
	std::cout << "Insert 5 numbers: /n";
	const int NMB = 5;
	std::vector<int> numbers(NMB);
	for(auto& n : numbers)
	{
		n += TakeInputInt();
	}

	std::cout << "The average is: " << CalculateAverage(&numbers) << "/n";
	system("pause");

	return EXIT_SUCCESS;

}