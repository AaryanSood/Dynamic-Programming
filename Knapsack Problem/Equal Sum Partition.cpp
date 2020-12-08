#include<bits/stdc++.h>
using namespace std;
#define ll long long

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

//Equal Sum Partition Problem

bool subset(ll arr[], ll sum, ll n){
    bool dp[n+1][sum+1];

    //Initialization Part
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i == 0 && j == 0)
                dp[i][j] = true;
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){

        }
    }

}

int main(){
    cout<<"Enter the number of elements of the array: ";
    ll n, sum_ = 0, sum;
    cin>>n;

    ll arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sum_ += arr[i];
    }
    if(sum_%2 == 0) {
        sum = sum_/2;
        if (subset(arr, sum, n))
            cout << "Subset exists!!";
        else
            cout << "Subset does not exists!!";
    }
    else{
        cout<<"Does not exist!!";
    }
}
