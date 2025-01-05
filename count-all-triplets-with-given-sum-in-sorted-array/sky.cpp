//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int ans = 0;
    
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
    
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
    
                if (sum == target) {
                    // Count duplicates for left and right
                    if (arr[left] == arr[right]) {
                        int count = right - left + 1;
                        ans += (count * (count - 1)) / 2;  // nC2 combinations
                        break;
                    } else {
                        // Count the occurrences of arr[left]
                        int countLeft = 1;
                        while (left + 1 < right && arr[left] == arr[left + 1]) {
                            left++;
                            countLeft++;
                        }
    
                        // Count the occurrences of arr[right]
                        int countRight = 1;
                        while (right - 1 > left && arr[right] == arr[right - 1]) {
                            right--;
                            countRight++;
                        }
    
                        // Add the product of occurrences to the answer
                        ans += countLeft * countRight;
    
                        // Move the pointers
                        left++;
                        right--;
                    }
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends