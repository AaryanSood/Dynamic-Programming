#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
//Recusrive Solution
bool isSubset(ll arr[], ll sum, ll i){

    if(sum == 0)
        return true;
    if(i == 0)
        return false;

    if(arr[i-1]>sum)
        return isSubset(arr, sum, i-1);
    else{
        return isSubset(arr, sum-arr[i-1], i-1)||isSubset(arr, sum, i-1);
    }
}

 */

int main(){

    ll n;
    cin>>n;

    ll arr[n];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    ll sum1;
    cin>>sum1;

    ll dp[n+1][sum1+1];
    for(ll i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(ll j=1; j<=sum1; j++){
        dp[0][j] = 0;
    }

    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=sum1; j++){
            if(arr[i-1]>sum1)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
        }
    }

    cout<<dp[n][sum1]<<" ";

    return 0;
}
