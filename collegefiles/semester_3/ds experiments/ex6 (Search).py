import numpy as np

class SearchAlgorithms:
    def binary_search_2d(self, arr, target):
        """Search for the target element in a sorted 2D array using binary search."""
        rows, cols = arr.shape
        low, high = 0, rows * cols - 1
        while low <= high:
            mid = (low + high) // 2
            row, col = divmod(mid, cols)
            if arr[row, col] == target:
                return row, col
            elif arr[row, col] > target:
                high = mid - 1
            else:
                low = mid + 1
        return -1, -1

    def linear_search_2d(self, arr, target):
        """Search for the target element in a 2D array using linear search."""
        for i in range(arr.shape[0]):
            for j in range(arr.shape[1]):
                if arr[i, j] == target:
                    return i, j
        return -1, -1

def main():
    search = SearchAlgorithms()

    arr = np.array([[1, 2, 3],
                    [4, 5, 6],
                    [7, 8, 9]])

    target = 5
    
    print(arr)

    binary_result = search.binary_search_2d(arr, target)
    linear_result = search.linear_search_2d(arr, target)

    if binary_result != (-1, -1):
        print(f"(Binary Search) Element {target} found at position {binary_result}")
    else:
        print("(Binary Search) Element not found in the array ")

    if linear_result != (-1, -1):
        print(f"(Linear Search) Element {target} found at position {linear_result}")
    else:
        print("(Linear Search) Element not found in the array ")

if __name__ == "__main__":
    main()
