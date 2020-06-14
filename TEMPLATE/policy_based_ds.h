#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet; // order_of_key find_by_order

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};
gp_hash_table<int, int, chash> table; // Hash table, good alternative of unordered_map

// Typedef by chilli for gp_hash_table
// typedef gp_hash_table<int, int, hash<int>, equal_to<int>, direct_mod_range_hashing<int>, linear_probe_fn<>,
//                      hash_standard_resize_policy<hash_prime_size_policy, hash_load_check_resize_trigger<true>, true>>
//    gp;