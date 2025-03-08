//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
    bool isPosibaleSoluation(vector<int> &arr, int n, int k  , int mid){
        
        int pagesum =0;
        int c =1;
        for(int i = 0; i<n; i++){
            
            if(arr[i] > mid){
                return false;
            }
            
            if(pagesum +arr[i] >mid){
                c++;
                pagesum = arr[i];
                if(c>k){
                    return false;
                }
                
                
            }
            else{
                pagesum += arr[i];
            }
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        if (k > n) {
            return -1;
        }
        
        int start =0;
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans =-1;
        
        while(start <=end ){
            int mid = (start +end) >> 1;
            if (isPosibaleSoluation(arr , n , k  ,mid)){
                ans = mid;
                end = mid -1;
                
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends