#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int result = 0;
        for(int i = 0; i < n; i++)
            result ^= arr[i];
        
        // take xor with 1,2,3...n
        for(int i = 1; i <= n; i++)
            result ^= i;
        
        // result = missing ^ repeating
        
        int rsb_mask = result & -result;
        int missing = 0, repeating = 0;
        // partition elements into 2 sets
        for(int i = 0; i < n; i++) {
            if(rsb_mask & arr[i])
                repeating ^= arr[i];
            else
                missing ^= arr[i];
        }
        for(int i = 1; i <= n; i++) {
            if(rsb_mask & i)
                repeating ^= i;
            else
                missing ^= i;
        }
        
        // find the exact values of missing and repeating
        for(int i = 0; i < n; i++) {
            if(arr[i] == missing) {
                swap(missing, repeating);
                break;
            }
        }
        int *ans = new int[2];
        ans[0] = repeating;
        ans[1] = missing;
        
        return ans;
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}