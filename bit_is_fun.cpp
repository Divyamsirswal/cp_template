#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){

    ll x;
    cin>>x;

    auto print_binary = [&](ll x){
        return bitset<4>(x).to_string();
    };

    auto check_kth_bit = [&](ll x,ll k){
        return (x >> k) & 1LL;
    };

    auto set_kth_bit = [&](ll x,ll k){
        return (1LL << k) | x;
    };

    auto unset_kth_bit = [&](ll x,ll k){
        return ~(1LL << k) & x;
    };

    auto is_even = [&](ll x){
        return (x & 1LL) == 0;
    };

    auto is_odd = [&](ll x){
        return (x & 1LL) == 1;
    };

    auto toggle_kth_bit = [&](ll x,ll k){
        return (1LL << k) ^ x;
    };

    auto count_set_bits = [&](ll x){
        return __builtin_popcountll(x);
    };

    auto check_power_of_two = [&](ll x){
        return count_set_bits(x) == 1;
    };

    auto kth_remainder = [&](ll x,ll k){
        return x & ((1LL << k) - 1);   
    };

    auto swap_nums = [&](ll a,ll b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    };
}
