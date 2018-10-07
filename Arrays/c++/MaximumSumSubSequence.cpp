/*Program that finds the sub sequence with the maximum sum
and print the maximum sum value. The minimum length of the
sub sequence should be 1.

Note: A sub sequence is a contiguous sub section of an array.
*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxSubArraySum(int arr[], int n){

    int current_sum = 0, max_sum = INT_MIN;

    for(int i = 0; i < n; i++){
        current_sum += arr[i];
        max_sum = max(max_sum, current_sum);

        current_sum = (current_sum < 0) ? 0 : current_sum;

    }

    return max_sum;
}

int main(){

    int n;
    cout << "Enter:-\n Array Size: ";
    cin >> n;

    int arr[n];
    cout <<" Array Elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nMaximum Sub Array Sum: " << maxSubArraySum(arr, n) << endl;

    return 0;
}
