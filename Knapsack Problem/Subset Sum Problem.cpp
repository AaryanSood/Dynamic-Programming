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
    ll sum;
    cin>>sum;
    /* Recursive Definition
    if(isSubset(arr, sum, n)){
        cout<<"A subset exists!";
    }
    else{
        cout<<"Subset doesn't exist!";
    }
    */

    // Dynamic Programming Solution - Overlapping Sub-problems encountered in Recursion

    bool arr1[n+1][sum+1];

    //Initialization of the array
    for(ll i=0; i<=n; i++){
        for(ll j=0; j<=sum; j++){
            if(i == 0 && j == 0)
                arr1[i][j] = true;
            else if(i == 0)
                arr1[i][j] = false;
            else if(j == 0)
                arr1[i][j] = true;
        }
    }

    //Filling the DP array
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=sum; j++){
            if(arr[i-1]>j)
                arr1[i][j] = arr1[i-1][j];
            else
                arr1[i][j] = arr1[i-1][j]||arr1[i-1][j-arr[i-1]];
        }
    }

    cout<<arr1[n][sum]<<" ";
    return 0;
}
