#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <random>
#include <iostream>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void ZeroMatrix(vector<vector<int>>& matrix)
{
    int sz = matrix.back().size();
    for (int i = 0; i < sz; ++i)
    {
        if (matrix.back()[i] > 0)
        {
            matrix.back()[i] = 0;
        }
    }

}

void RandomMatrix(vector<vector<int>>& matrix)
{

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            matrix[i][j] = (rand() % 2000 + (-1000));
            if (matrix[i][j] > 0) matrix[i][j] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix;

    cout << "Choose your input method:\n";
    cout << "Manual or automatic?\n";

    string result;
    cin >> result;

    if (result == "manual") {
        // Input matrix
        cout << "You have chosen manual matrix generation\n";
        cin.ignore();
        string line;
        while ((getline(cin, line)) && !line.empty())
        {

            istringstream rawValues(line);
            vector<int> vals;
            copy(istream_iterator<int>(rawValues), {}, back_inserter(vals));
            matrix.push_back(vals);
            int sz = matrix.back().size();
            ZeroMatrix(matrix);
        }

    }
    else if (result == "automatic") {
        cout << "You have chosen automatic matrix generation\n";
        "Enter size -> m n:\n";
        int rows = 0, cols = 0;
        cin >> rows >> cols;
        matrix.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            matrix[i].resize(cols);
        }
        RandomMatrix(matrix);
    }
    else cout << "You entered an invalid method";

    printMatrix(matrix);

    return 0;
}
