#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to calculate the mean
float calculateMean(const vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return static_cast<float>(sum) / numbers.size();
}

// Function to calculate the sum
int calculateSum(const vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

// Function to calculate the median
float calculateMedian(const vector<int>& numbers) {
    vector<int> sortedNumbers = numbers;
    sort(sortedNumbers.begin(), sortedNumbers.end());
    int size = sortedNumbers.size();

    if (size % 2 == 0) {
        // If the size is even, return the average of the middle two elements
        int mid1 = sortedNumbers[size / 2 - 1];
        int mid2 = sortedNumbers[size / 2];
        return static_cast<float>(mid1 + mid2) / 2;
    } else {
        // If the size is odd, return the middle element
        return static_cast<float>(sortedNumbers[size / 2]);
    }
}

// Function to calculate the standard deviation
float calculateStandardDeviation(const vector<int>& numbers) {
    float mean = calculateMean(numbers);
    float sumOfSquaredDifferences = 0;

    for (int num : numbers) {
        float diff = num - mean;
        sumOfSquaredDifferences += (diff * diff);
    }

    float variance = sumOfSquaredDifferences / numbers.size();
    return sqrt(variance);
}

int main() {
    vector<int> numbers;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add number to the vector" << endl;
        cout << "2. Calculate mean" << endl;
        cout << "3. Calculate sum" << endl;
        cout << "4. Calculate median" << endl;
        cout << "5. Calculate standard deviation" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int num;
                cout << "Enter a number: ";
                cin >> num;
                numbers.push_back(num);
                break;

            case 2:
                cout << "Mean: " << calculateMean(numbers) << endl;
                break;

            case 3:
                cout << "Sum: " << calculateSum(numbers) << endl;
                break;

            case 4:
                cout << "Median: " << calculateMedian(numbers) << endl;
                break;

            case 5:
                cout << "Standard Deviation: " << calculateStandardDeviation(numbers) << endl;
                break;

            case 6:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }

    } while (choice != 6);

    return 0;
}
