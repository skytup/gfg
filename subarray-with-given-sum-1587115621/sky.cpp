// Written on 08/01/2025
// Akash Vishwakarma
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        
        int temp = 0, j=0;
        int min=0,max=0;
        for(int i=0; i<n; i++){
        temp+=arr[i];
            while(temp>target){
                temp = temp-arr[j];
                j++;    
            }
            if(temp == target){
                min =j+1,max = i+1;
                return {min,max};
                break;
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends