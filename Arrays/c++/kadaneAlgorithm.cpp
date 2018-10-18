/*
Another approach for finding sub sequence with the maximum sum

i.e finding a sub array which has the maximum sum 
Eg : -1 3 5 -2 1
Max sum : 8 [3 5]
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxSubArraySum(int arr[], int n){
    if(n==1)
        return arr[0];
    int current_sum , global_sum = arr[0];
    for(int i = 1; i < n; i++){
        current_sum = max(arr[i],current_sum+arr[i]);   
        if(current_sum > global_sum)
            global_sum = current_sum;
    }
    return global_sum;
}
int main(){
    int n;
    cout << "Enter Array Size: ";
    cin >> n;

    int arr[n];
    cout <<" Array Elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nMaximum Sub Array Sum: " << maxSubArraySum(arr, n) << endl;
    return 0;
}