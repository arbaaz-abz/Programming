/*Recursive method to check whether a given binary tree is a BST
The idea is to start at root with infinite range(max range of int),
and then changing the upper and lower bound for left and right subtrees
respectively. For each recursive step, the value of current node must lie between
the lower and upper bounds if the given binary tree is a BST.

Preferred compiler - GCC 4.8.0 and above

Input - Numer of nodes, tree(in its array representation)
Output - "BST" or "Not a BST"
*/

#include<bits/stdc++.h>

using namespace std;

bool checkBST(int bin_tree[], int n, int index, int low, int high){

    if(index >= n)      //handle out of bounds condition
        return true;

    if(bin_tree[index] > low && bin_tree[index] < high){
        //current node value is within the range
        return true & checkBST(bin_tree, n, 2 * index + 1, low, bin_tree[index]) & checkBST(bin_tree, n, 2 * index + 2, bin_tree[index], high);
    }
    else{
        //current node value is not within the range
        return false;
    }
}

int main(){

    int n;
    cout << "Enter:-\n Number of Nodes: ";
    cin >> n;

    int tree[n];
    cout << " Array representation of the Tree: ";
    for(int i = 0; i < n; i++)
        cin >> tree[i];

    if(checkBST(tree, n, 0, INT_MIN, INT_MAX))
        cout << "BST" << endl;
    else
        cout << "Not a BST" << endl;

    return 0;
}
