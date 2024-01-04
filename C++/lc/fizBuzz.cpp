#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;

        for (int i = 1; i <= n; i++)
        {
            string output = "";
            if (i % 3 == 0)
            {
                output += "Fizz";
            }
            if (i % 5 == 0)
            {
                output += "Buzz";
            }

            result.push_back(output);
        }

        return result;
    }
};

int main()
{
    Solution obj;

    vector<string> res = obj.fizzBuzz(30);

    for (string i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
