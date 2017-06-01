#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private:
	void printMatrix(int **mat, int m, int n) {
		for (int r = 0; r < m; ++r) {
        	for (int c = 0; c < n; ++c) {
        		cout << mat[r][c] << " ";
        	}
        	cout << endl;
        }
	}
public:
    int uniquePaths(int m, int n) {
        int **paths = 0;
        paths = new int*[m];
        for (int r = 0; r < m; ++r) {
        	paths[r] = new int[n];
        }
        int l = 0, t = 0;// l -> left, t -> top
        int pl = 0, pt = 0; // pl -> # paths left, pt -> # paths top
        paths[0][0] = 1;
        for (int r = 0; r < m; ++r) {
        	for (int c = 0; c < n; ++c) {
        		l = c - 1;
        		t = r - 1;
        		pl = (l >= 0) ? paths[r][l] : 0;
        		pt = (t >= 0) ? paths[t][c] : 0;
        		paths[r][c] = pl + pt;
        	}
        }
        
        printMatrix (paths, m, n);

        int res = paths[m - 1][n - 1];
        for (int r = 0; r < m; ++r) {
        	delete paths[r];
        }
        delete paths;
        return res;
    }
};

void test0() {
	Solution sol;
	int res = sol.uniquePaths(1, 1);
	assert (res == 1);
}

void test1() {
	Solution sol;
	int res = sol.uniquePaths(2, 2);
	assert (res == 2);
}

void test2() {
	Solution sol;
	int res = sol.uniquePaths(3, 3);
	assert (res == 9);
}

/*void test0_recursive() {
	Solution sol;
	int res = sol.uniquePathsRecursive(3);
	assert (res == 3);
}*/

/*void test1_recursive() {
	Solution sol;
	int res = sol.uniquePathsRecursive(10);
	assert (res == 89);
}*/

int main() {
	test0();
	test1();
	test2();
	/*test0_recursive();
	test1_recursive();*/
	return 0;
}