#include <iostream>
#include <vector>
using namespace std;

int min_coins(vector<int> D, int A)
{
    // Construct a 1D DP:
    vector<int> DP(A+1,-1);
    // Base cases:
    DP[0]=0;
    for(int coin: D)
        if(coin <= A)
            DP[coin] = 1;
    for(int i=1; i<A+1; i++)
    {
        if(DP[i] != -1) continue;
        int min = INT_MAX;
        for(int coin: D)
        {
            if(i>coin)
            {
                if(DP[i-coin]!=-1 && min>DP[i-coin])
                    min=DP[i-coin];
            }
        }
        if(min == INT_MAX) continue;
        DP[i] = min+1;
    }
    return DP[A];
}

int main()
{
    vector<int> denominations = {186,419,83,408};
    int amount = 6249;
    cout << "Minimum number of coins required: " << min_coins(denominations, amount) << endl;
    return 0;
}