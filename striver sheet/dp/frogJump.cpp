#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Most optimal solution
ll calculate_mimimum_reqired_energy(ll steps, vector<ll> heights){
    ll prev = 0;
    ll prev2 = 0;

    for(ll i=1; i<steps; i++){
        ll energy1 = prev + abs(heights[i] - heights[i-1]);
        ll energy2 = INT_MAX;
        if(i > 1) energy2 = prev2 + abs(heights[i] - heights[i-2]);
        ll curr = min(energy1, energy2);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main(){
    ll steps;
    cin >> steps;
    vector<ll> height(steps);

    for(ll i = 0; i<steps; i++){
        cin>> height[i];
    }

    ll ans = calculate_mimimum_reqired_energy(steps, height);

    cout<< ans << endl;
}