#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private:
	void printMatrix(vector<vector<int> > mat, int m, int n) {
		for (int r = 0; r < m; ++r) {
        	for (int c = 0; c < n; ++c) {
        		cout << mat[r][c] << " ";
        	}
        	cout << endl;
        }
	}
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();

        
        if (obstacleGrid[0][0] == 1) 
        	return 0;

        vector<vector<int> > paths(m, vector<int> (n));
        
        paths[0][0] = 1;
        int l = 0, t = 0;
        for (int r = 0; r < m; ++r) {
        	for (int c = 0; c < n; ++c) {
        		if (r == 0 && c == 0) continue;
        		l = c - 1;
        		t = r - 1;

				paths[r][c] = 0;
        		if ( l >= 0 && obstacleGrid[r][l] != 1) {
        			paths[r][c] += paths[r][l];	
        		}

        		if (t >= 0 && obstacleGrid[t][c] != 1) {
        			paths[r][c] += paths[t][c];
        		}
        	}
        }
        
        //printMatrix (paths, m, n);

        return paths[m - 1][n - 1];
    }
};

void test0() {
	Solution sol;
	vector<vector<int> > vv (1, vector<int> (1, 0));
	
	int res = sol.uniquePathsWithObstacles(vv);
	assert (res == 1);
}

void test0_1() {
	Solution sol;
	vector<vector<int> > vv (1, vector<int> (1, 1));
	int res = sol.uniquePathsWithObstacles(vv);
	assert (res == 0);
}


void test1() {
	Solution sol;
	vector<vector<int> > vv (2, vector<int> (2, 0));
	int res = sol.uniquePathsWithObstacles(vv);
	assert (res == 2);
}

void test1_0() {
	Solution sol;
	vector<vector<int> > vv (2, vector<int> (2, 0));
	vv[0][1] = 1;
	int res = sol.uniquePathsWithObstacles(vv);
	assert (res == 1);
}

void test2() {
	Solution sol;
	vector<vector<int> > vv (3, vector<int> (3, 0));
	int res = sol.uniquePathsWithObstacles(vv);
	assert (res == 6);
}

void test2_0() {
	Solution sol;
	vector<vector<int> > vv (3, vector<int> (3, 0));
	vv[0][1] = 1;
	int res = sol.uniquePathsWithObstacles(vv);
	assert (res == 3);
}

void test2_1() {
	Solution sol;
	vector<vector<int> > vv (3, vector<int> (3, 0));
	vv[1][1] = 1;
	int res = sol.uniquePathsWithObstacles(vv);
	assert (res == 2);
}

void test3() {
	Solution sol;
	vector<vector<int> > vv (4, vector<int> (4, 0));
	int res = sol.uniquePathsWithObstacles(vv);
	assert (res == 20);
}

void test4() {
	Solution sol;
	vector<vector<int> > vv (4, vector<int> (5, 0));
	int res = sol.uniquePathsWithObstacles(vv);
	assert (res == 35);
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
	test1_0();
	test2();
	test2_0();
	test2_1();
	test3();
	test4();
	/*test0_recursive();
	test1_recursive();*/
	return 0;
}