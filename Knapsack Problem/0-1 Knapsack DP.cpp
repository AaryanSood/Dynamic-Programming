/*
 * 0/1 KnapSack Problem
 * Given weights and values of n items, put these items in a
 * knapsack of capacity W to get the maximum total value in the
 * knapsack. In other words, given two integer arrays val[0..n-1]
 * and wt[0..n-1] which represent values and weights associated
 * with n items respectively. Also given an integer W which
 * represents knapsack capacity, find out the maximum value
 * subset of val[] such that sum of the weights of this subset
 * is smaller than or equal to W. You cannot break an item,
 * either pick the complete item or don’t pick it (0-1 property).
 * One can solve this through recursion as well as Dynamic Programming.
 */

//Dynamic Programming Solution
#include<bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i=a; i<b; i++)


void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int knapsack(int wt[], int val[], int n, int w);

int main(){
    //fast();
    //cout<<"Enter the number of elements : ";
    int t;
    cin>>t;
    while(t--){
        int n, w;
        cin>>n>>w;
        int wt[n], val[n];
        REP(i, 0, n)
            cin>>val[i];
        REP(i, 0, n)
            cin>>wt[i];
        cout<<knapsack(wt, val, n, w)<<"\n";
    }
}

int knapsack(int wt[], int val[], int n, int W) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max( 
                    val[i - 1] + K[i - 1][w - wt[i - 1]], 
                    K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
} 
