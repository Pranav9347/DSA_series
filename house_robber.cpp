#include <iostream>
#include <vector>
using namespace std;

int max_profit(vector<int>& nums)
{
    int n=nums.size();
    if(n==1) return nums[0]; 
    if(n==2) return max(nums[0],nums[1]);
    vector<int> DP(n);
    DP[0] = nums[0], DP[1] = nums[1], DP[2] = nums[0]+nums[2];
    for(int i=3; i<n; i++)
    {
        DP[i] = nums[i]+max(DP[i-2],DP[i-3]);
    }
    return max(DP[n-1],DP[n-2]);
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << max_profit(nums);
    return 0;
}