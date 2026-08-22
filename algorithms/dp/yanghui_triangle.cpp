#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> triangle;
    
    for (int i = 0; i < n; ++i) {
        vector<int> row(i + 1, 0);
        row[0] = 1;
        row[i] = 1;
        for (int j = 1; j < i; ++j) {                                             
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    
    for (const auto& row : triangle) {
        cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i < row.size() - 1) cout << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}