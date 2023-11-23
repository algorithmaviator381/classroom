#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int matrix1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrix2[3][2] = {{7,8}, {9,10}, {11,12}};
    int result[2][2];

    cout << "matrix 1" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nmatrix 2" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatrix multiplication" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
            cout << sum << " ";
        }
        cout << endl;
    }


    return 0;
}
