#include <iostream>
#include <vector>

class SortingAlgorithms
{
public:
    std::vector<int> BubbleSort(std::vector<int> &arr)
    {
        int length = arr.size();

        for (int i = 0; i < length; ++i)
        {
            bool swapped = false;
            for (int j = 0; j < length - i - 1; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
            {
                break;
            }
        }

        return arr;
    }

    std::vector<int> InsertionSort(std::vector<int> &arr)
    {
        int length = arr.size();

        for (int i = 1; i < length; ++i)
        {
            int current = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > current)
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = current;
        }

        return arr;
    }

    std::vector<int> SelectionSort(std::vector<int> &arr)
    {
        int length = arr.size();

        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = i + 1; j < length; ++j)
            {
                if (arr[i] > arr[j])
                {
                    std::swap(arr[i], arr[j]);
                }
            }
        }

        return arr;
    }

    std::vector<int> QuickSort(std::vector<int> &arr)
    {
        int length = arr.size();

        if (length <= 1)
        {
            return arr;
        }

        int pivot = arr[length / 2];
        std::vector<int> left, middle, right;

        for (int x : arr)
        {
            if (x < pivot)
            {
                left.push_back(x);
            }
            else if (x == pivot)
            {
                middle.push_back(x);
            }
            else
            {
                right.push_back(x);
            }
        }

        arr.clear();
        arr.insert(arr.end(), QuickSort(left).begin(), QuickSort(left).end());
        arr.insert(arr.end(), middle.begin(), middle.end());
        arr.insert(arr.end(), QuickSort(right).begin(), QuickSort(right).end());

        return arr;
    }

    std::vector<int> MergeSort(std::vector<int> &arr)
    {
        int length = arr.size();

        if (length <= 1)
        {
            return arr;
        }

        int mid = length / 2;
        std::vector<int> left_half(arr.begin(), arr.begin() + mid);
        std::vector<int> right_half(arr.begin() + mid, arr.end());

        MergeSort(left_half);
        MergeSort(right_half);

        int i = 0, j = 0, k = 0;

        while (i < left_half.size() && j < right_half.size())
        {
            if (left_half[i] < right_half[j])
            {
                arr[k++] = left_half[i++];
            }
            else
            {
                arr[k++] = right_half[j++];
            }
        }

        while (i < left_half.size())
        {
            arr[k++] = left_half[i++];
        }

        while (j < right_half.size())
        {
            arr[k++] = right_half[j++];
        }

        return arr;
    }
};

int main()
{
    SortingAlgorithms sort;

    std::vector<int> arr = {8, 5, 5, 2, 8, 4};

    std::cout << "Original Array : ";
    for (int x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted Array (Bubble Sort): ";
    for (int x : sort.BubbleSort(arr))
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
