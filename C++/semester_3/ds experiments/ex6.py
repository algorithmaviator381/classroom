class SearchAlgorithms:
    def binary_search(self, arr, target):
        """Search for the target element in a sorted 
            array using binary search."""
        low = 0
        high = len(arr) - 1
        while low <= high:
            mid = (low + high) // 2
            if arr[mid] == target: return mid
            elif arr[mid] > target: high = mid - 1
            else: low = mid + 1
        return -1

    def linear_search(self, arr, target):
        """Search for the target element in an array 
            using linear search."""
        for i, num in enumerate(arr):
            if num == target:
                return i
        return -1

def main():
    search = SearchAlgorithms()

    arr = [1, 3, 7, 12, 48, 59, 64]
    target = 12
    print(arr)

    binary_result = search.binary_search(arr, target)
    linear_result = search.linear_search(arr, target)

    if binary_result != -1:
        print(f"Element {target} found at index (Binary Search): {binary_result}")
    else:
        print("Element not found in the array (Binary Search)")

    if linear_result != -1:
        print(f"Element {target} found at index (Linear Search): {linear_result}")
    else:
        print("Element not found in the array (Linear Search)")

if __name__ == "__main__":
    main()
