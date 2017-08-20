class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int left, top, right, bot, sum, row, col, neighbors;
        vector<vector<int>> res = M;
        int rows = M.size();
        int cols = M[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                row = i;
                col = j;
                sum = M[row][col];
                neighbors = 1;
                
                left = col - 1;
                right = col + 1;
                top = row - 1;
                bot = row + 1;
                
                if (left >= 0) {sum += M[row][left]; ++neighbors;}
                if (right < cols) {sum += M[row][right];++neighbors;}
                if (top >= 0) {sum += M[top][col];++neighbors;}
                if (bot < rows) {sum += M[bot][col];++neighbors;}
                if (top >= 0 && right < cols) {sum += M[top][right];++neighbors;}
                if (bot < rows && right < cols) {sum += M[bot][right];++neighbors;}
                if (left >= 0 && bot < rows) {sum += M[bot][left];++neighbors;}
                if (left >= 0 && top >= 0) {sum += M[top][left];++neighbors;}
                //cout << "sum=" << sum << " ";
                sum = sum / neighbors;
                //cout << row << " " << col << " " << " " << neighbors << " " << sum << endl;
                res[row][col] = sum;
                
            }
        }
        return res;
        
    }
};