//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long sum = 0;
        vector<int> ans;
        int flag = 0;
        int start = 0;
        if(s == 0){
            ans.push_back(-1);
            return ans;
        }
        for(int i = 0; i < n; i++){
            sum += arr[i];
            while(sum > s){
                sum = sum - arr[start];
                start++;
            }
            
            if(sum == s){
                ans.push_back(start+1);
                ans.push_back(i+1);
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            ans.push_back(-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends