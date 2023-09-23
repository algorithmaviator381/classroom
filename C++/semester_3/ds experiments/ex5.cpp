#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Display(int list[], int length){
    for(int i=0; i<length; i++){
        cout<<list[i]<<" ";
    }
    cout<<endl<<endl;
}

void DisplayIndices(vector<int> indices){
    if (indices.empty()) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at indices: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    }
}

class searching{
public:
    int BinarySearchNonRec(int arr[], int length, int target){
        int left = 0;
        int right = length-1;

        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid] == target){
                return mid;
            }else if(arr[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }

    int BinarySearchRecc(int arr[], int left, int right, int target){
        if(right>=left){
            int mid = (left+right)/2;
            if(arr[mid] == target) return mid;
            else if(arr[mid]>target) return BinarySearchRecc(arr, left, mid-1, target);
            else return BinarySearchRecc(arr, mid+1, right, target);
        }
    }

    vector<int> BinarySearchAll(int arr[], int length, int target) {
        vector<int> indices;
        int left = 0;
        int right = length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                indices.push_back(mid);
                left = mid + 1;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return indices;
    }

    int LinearSearchNonRecc(int arr[], int length, int target){
        for(int index=0; index<length; index++){
            if(arr[index] == target){
                return index;
            }
        }
    }

    int LinearSearchRecc(int arr[], int length, int target) {
    if (length < 0) return -1;  // Element not found
    if (arr[length] == target) return length;  // Element found
    int result = LinearSearchRecc(arr, length - 1, target);  // Recursive case
    if (result == -1 && length == 0) return -1;  // Element not found
    return result;
}

};

int main(){
    int mylist[] = {3,6,7,2,4,5,6,7,9};
    int length = sizeof(mylist)/sizeof(mylist[0]);
    int target = 2;

    sort(mylist, mylist+length);
    Display(mylist, length);
    
    searching search;
    vector<int> indices = search.BinarySearchAll(mylist, length, target);

    // cout<<search.BinarySearchNonRec(mylist, length, target);
    // cout<<search.BinarySearchRecc(mylist, 0, length-1, target);
    // DisplayIndices(indices);
    // cout<<search.LinearSearchNonRecc(mylist, length-1, target);
    // cout<<search.LinearSearchRecc(mylist, length-1, target);
}