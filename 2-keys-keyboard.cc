#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
private:
	std::vector<int> primes = {2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41,
  43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97, 101,

 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,

 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,

 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569,

 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733,

 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823,
 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,

 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

 std::vector<int> primeFactors = {2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37 };
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        if (std::binary_search (primes.begin(), primes.end(), n)) return n;
        int steps = 0;
        for (int i = 0; i < primeFactors.size(); ++i) {
        	if (n % primeFactors[i] == 0) {
        		while (n > 0 && n % primeFactors[i] == 0) {
        			steps += primeFactors[i];
        			n /= primeFactors[i];
        		}
        		if (std::binary_search (primes.begin(), primes.end(), n)) {
        			steps += n;
        			n = 0;
        		}
        		if (n == 0) break;
        	}
        }
        return steps;
    }
};

void test0() {
	Solution sol;
	int res = sol.minSteps(3);
	assert (res == 3);
}

void test1() {
	Solution sol;
	int res = sol.minSteps(9);
	assert (res == 6);
}

void test2() {
	Solution sol;
	int res = sol.minSteps(1000);
	assert (res == 21);
}

void test3() {
	Solution sol;
	int res = sol.minSteps(9);
	assert (res == 6);
}

void test4() {
	Solution sol;
	int res = sol.minSteps(997);
	assert (res == 997);
}

void test5() {
	Solution sol;
	int res = sol.minSteps(123);
	cout << res << endl;
	assert (res == 44);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}