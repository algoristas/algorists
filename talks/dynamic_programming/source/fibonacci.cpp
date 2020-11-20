/**
 * Compile with C++17:
 * 		g++ -Wno-multichar -std=c++17 fibonacci.cpp -o fibonacci
 *
 * Run:
 * 		./fibonacci {classic-iterative|classic-recursive|top-down|bottom-up}
 *
 * You can play with the input file fibonacci.in like:
 *		./fibonacci top-down < fibonacci.in > top-down.out
 */
#include <iostream>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <functional>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <cstdlib>

using sli = signed long long int;
using uli = unsigned long long int;
using hashmap = std::unordered_map<std::string, std::function<sli(int)>>;
const sli UNDEFINED = -1ll;
const int MAX = 92;
const auto out_of_range = std::out_of_range(
	"We cannot compute k-th Fibonacci number for k > 92."
);
const std::string possible_implementations
	("it could be: classic-iterative, classic-recursive, bottom-up or top-down.");

std::vector<sli> memo(MAX + 1, UNDEFINED);

sli classic_iterative(int N) {
	if (N < 0 || N > MAX) throw out_of_range;
	sli current = 0ll, next = 1ll;
	for (int k = 1; k <= N; k++) {
		sli aux = current + next;
		current = next;
		next = aux;
	}
	return current;
}

sli classic_recursive(int N) {
	if (N < 0 || N > MAX) throw out_of_range;
	if (N < 2) return N;
	return classic_recursive(N - 1) + classic_recursive(N - 2);
}

sli bottom_up(int N) {
	if (N < 0 || N > MAX) throw out_of_range;
	if (memo[N] == UNDEFINED) {
		for (int k = 2; k <= N; k++) {
			memo[k] =  memo[k - 1] + memo[k - 2];
		}
	}
	return memo[N];
}

sli top_down(int N) {
	if (N < 0 || N > MAX) throw out_of_range;
	if (memo[N] != UNDEFINED) return memo[N];
	memo[N] = top_down(N - 1) + top_down(N - 2);
	return memo[N];
}

const hashmap implementations{
	{"classic-iterative", &classic_iterative},
	{"classic-recursive", &classic_recursive},
	{"bottom-up", &bottom_up},
	{"top-down", &top_down},
};

int main(int argc, char const *argv[]) {

	if (argc != 2) {
		std::cerr << "Missing argument implementation name in the command line,\n"
				<< possible_implementations << std::endl;
		return EXIT_FAILURE;
	}

	std::string approach(argv[1]);
	if (!implementations.count(approach)) {
		std::cerr << "Invalid implementation name,\n" << possible_implementations << std::endl;
		return EXIT_FAILURE;
	}

	auto fibonacci = implementations.at(approach);
	auto start = std::chrono::steady_clock::now();
	int Q, N;
	std::cin >> Q;
	memo[0] = 0ll; memo[1] = 1ll;
	for (int q = 1; q <= Q; q++) {
		std::cin >> N;
		std::cout << fibonacci(N) << std::endl;
	}
	auto end  = std::chrono::steady_clock::now();
	std::clog << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs" << std::endl;
	return EXIT_SUCCESS;
}
