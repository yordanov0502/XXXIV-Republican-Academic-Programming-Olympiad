#include <iostream>
#include <vector>
using namespace std;

int isPrime(long long number) {

	if (number == 0 || number == 1 || (number % 2 == 0 && number > 2)) 
	{
		return 0;
	}

	else 
	{
		for (long long i = 3; i <= (long long)sqrt(number) + 1; i++) 
		{
			if (number % i == 0) 
			{
				return 0;
			}
		}
		return 1;
	}
}

int main() { 
	
	vector <int> years;
	for (int i = 1900; i <2023; i++)
	{
		years.push_back(i);
	}

	int input=0;
	
	while (input != INT_MIN) //Programta obrabotva nqkolko testovi primera (***ne se znae kolko tochno***)
	{
		cin >> input;

		int currYear;
		int sum;

		for (int i = 0; i < 122; i++)
		{
			if (isPrime(years[i]))
			{
				currYear = years[i];
				sum = 0;
				while (currYear != 0)
				{
					sum += currYear % 10;
					currYear /= 10;
				}
				if (input == sum)
				{
					cout << years[years.size() - 1] - years[i] << endl;
				}


			}
		}
	}

	return 0; }