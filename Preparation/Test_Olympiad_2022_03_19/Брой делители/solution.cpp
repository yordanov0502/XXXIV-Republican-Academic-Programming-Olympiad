// Towa reshenie e na dvukratniya zlaten medalist (i vednyz srebyren) ot mezdunarodnata uceniceska olimpiada (IOI) Alexander Krystev ot Varna (v momenta student v MIT - Massachusetts Institute of Technology)

#include <iostream>
#include <cstdint>
#include <utility>
#include <algorithm>
#include <vector>

const uint32_t MAX_N = 1e7 + 12;

std::vector<bool> notPrime;
std::vector<uint32_t> primes;

void sieve() {
	notPrime = std::vector<bool>(MAX_N, false);
	for (uint64_t i = 2;i < MAX_N;i++) {
		if (!notPrime[i]) {
			primes.push_back(i);
			for (uint64_t j = i * i;j < MAX_N;j += i) {
				notPrime[j] = true;
			}
		}
	}
}

uint32_t div_cnt(uint64_t a) {
	uint64_t ans = 1;
	for (uint32_t i : primes) {
		if (a % i == 0) {
			uint64_t cur = 0;
			while (a % i == 0) {
				a /= i;
				cur++;
			}
			ans *= (cur + 1); // +1 is added for i^0 = 1, which is also a divider
		}
	}
	if (a > 1) {
		ans *= (1 + 1); // The highest divider 'a' is always on first power (a^1). +1 is added again for a^0 = 1, which is also a divider
	}
	return ans;
}

std::vector<std::pair<uint64_t, uint64_t>> nums;

void input() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	uint32_t n;
	std::cin >> n;
	nums.resize(n);
	for (auto &i : nums) {
		std::cin >> i.second;
		i.first = div_cnt(i.second);
	}
}

int main() {
	sieve();
	input();
	std::sort(nums.begin(), nums.end());
	for (const auto &i : nums) {
		std::cout << i.second << "\n";
	}
}