#include <iostream>
#include<vector>

using namespace std;

void MergeSort(vector<int>& vector_input, int first, int middle, int last){
    
    vector<int> left_vector(middle - first + 1);
    vector<int> right_vector(last - middle);
    
    // Putting the elements into vector that will be compare to right
    for (int i = 0; i < left_vector.size(); ++i)
        left_vector[i] = vector_input[first + i];

    // Putting the elements into vector that will be compare to left
    for (int i = 0; i < right_vector.size(); ++i)
        right_vector[i] = vector_input[middle + 1 + i];
    
    // Indexes for divided elements of vector
    int left_index = 0, right_index = 0;
    int current_index = first;
    
    // Sorting the elements of the smaller vector
    while (left_index < left_vector.size() && right_index < right_vector.size()) {
        if (left_vector[left_index] <= right_vector[right_index]) {
            vector_input[current_index] = left_vector[left_index];
            left_index++;
        } else {
            vector_input[current_index] = right_vector[right_index];
            right_index++;
        }
        current_index++;
    }
    
    // Putting the left elements into vector that is remaining
    while (left_index < left_vector.size())
        vector_input[current_index++] = left_vector[left_index++];

    // Putting the right elements into vector that is remaining
    while (right_index < right_vector.size())
        vector_input[current_index++] = right_vector[right_index++];

}

// Function for finding limits and sort first and second half of the array
// After calling the merge sort function which compares the elements of array
// Individually
void MergeSortLimits(vector<int>& vector_input, int first_index, int last_index) {
    if (first_index < last_index) {
        // find the middle index point
        int middle_index = (first_index + 2) / 2;

        // Sorting beginning to middle
        MergeSortLimits(vector_input, first_index, middle_index);
        // Sorting from middle to last
        MergeSortLimits(vector_input, middle_index + 1, last_index);
        // Sorting the vector that sorted its two parts
        MergeSort(vector_input, first_index, middle_index, last_index);
    }
}

// Function for printing the vector
void PrintVector(vector<int>& vector_input){
    for (int i = 0; i < vector_input.size(); i++) {
        cout << vector_input[i];
        if (i < vector_input.size() - 1) cout << ", ";
    }
    cout << endl;
}


int main() {
    
    // Initializing variables
    int vector_begin = 0;
    int vector_last = 0;
    vector<int> vector_input;
    
    // Test Case 1
    
    vector_input = {100, 40, 60, 23, 25, 21, 15, 99, 5, 2};
    cout << "Vector before merge sorted: " << endl;
    PrintVector(vector_input);
    vector_last = static_cast<int>(vector_input.size() - 1);
    MergeSortLimits(vector_input,vector_begin,vector_last);
    cout << "Vector after merge sorted: " << endl;
    PrintVector(vector_input);
    cout << endl;
    
    // Test Case 2
    vector_input = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "Vector before merge sorted: " << endl;
    PrintVector(vector_input);
    vector_last = static_cast<int>(vector_input.size() - 1);
    MergeSortLimits(vector_input,vector_begin,vector_last);
    cout << "Vector after merge sorted: " << endl;
    PrintVector(vector_input);
    cout << endl;

    // Test Case 3
    vector_input = {15, 14, 13, 12, 11, 10, 4, 3, 2, 1};
    cout << "Vector before merge sorted: " << endl;
    PrintVector(vector_input);
    vector_last = static_cast<int>(vector_input.size() - 1);
    MergeSortLimits(vector_input,vector_begin,vector_last);
    cout << "Vector after merge sorted: " << endl;
    PrintVector(vector_input);
    cout << endl;

    // Test Case 4
    vector_input = {10, 8, 2, 6, 4, 3, 5, 7, 1, 9};
    cout << "Vector before merge sorted: " << endl;
    PrintVector(vector_input);
    vector_last = static_cast<int>(vector_input.size() - 1);
    MergeSortLimits(vector_input,vector_begin,vector_last);
    cout << "Vector after merge sorted: " << endl;
    PrintVector(vector_input);
    cout << endl;

    // Test Case 5
    vector_input = {10, 8, 2, 6, 4, 3, 5};
    cout << "Vector before merge sorted: " << endl;
    PrintVector(vector_input);
    vector_last = static_cast<int>(vector_input.size() - 1);
    MergeSortLimits(vector_input,vector_begin,vector_last);
    cout << "Vector after merge sorted: " << endl;
    PrintVector(vector_input);
    cout << endl;

    // Test Case 6
    vector_input = {3, 2,1};
    cout << "Vector before merge sorted: " << endl;
    PrintVector(vector_input);
    vector_last = static_cast<int>(vector_input.size() - 1);
    MergeSortLimits(vector_input,vector_begin,vector_last);
    cout << "Vector after merge sorted: " << endl;
    PrintVector(vector_input);
    
    return 1;
}
