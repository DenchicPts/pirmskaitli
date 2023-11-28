#include <iostream>
#include <vector>
using namespace std;

int pirmskaitli(long long N) {
	const long long size = N + 1;
	vector<char> isPrime(size, true);

	for (long long p = 2; p * p <= N; ++p) {
		if (isPrime[p]) {
			for (long long i = p * p; i <= N; i += p) {
				isPrime[i] = false;
			}
		}
	}

	int primeCount = 0;
	for (long long p = 2; p <= N; ++p) {
		if (isPrime[p]) {
			// Вместо вывода числа, увеличиваем счетчик простых чисел
			primeCount++;
		}
	}

	return primeCount;
}

bool isParasts(int num) {
	if (num < 2) {
		return false;
	}
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int maximalais(int n) {
	for (int i = n; i >= 2; --i) {
		if (isParasts(i)) {
			return i;
		}
	}
	return -1;
}



int main() {
	vector N{ 1000,1000000,1000000000 };
	for (const auto& i : N)
	{
	cout << pirmskaitli(i) << "  " << maximalais(i) << endl;
	}



	return 0;
}

