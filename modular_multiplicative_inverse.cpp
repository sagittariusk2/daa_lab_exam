/**
 * @file modular_multiplicative_inverse.cpp
 * @author Ritesh Ranjan (https://sagittariusk2.github.io)
 * @brief Inverse Modular
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief Given two integers `a` and `m`, find modular multiplicative inverse of `a` under modulo `m`.
 * 
 * (1/a)%m = x
 * => ax = 1 (mod m)
 * 
 * `x` exists only when `a` and `m` are relatively prime
 * => gcd(a, m)=1
 * 
 * It can take values between 1 and m-1.
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007

/**
 * @brief Naive approach
 * 
 * try each value from 1 to m-1 to check (a*x)%m==1
 * Time complexity = O(m)
 * 
 * @param a 
 * @param m 
 * @return int 
 */
int mod_inverse_naive(int a, int m) {
    for(int i=1; i<m; i++) {
        if(((a%m) * (i%m)) %m == 1)
            return i;
    }
    return -1;
}
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return tuple<int, int, int> <x, y, gcd(a, b)>
 */
tuple<int, int, int> gcd_extended(int a, int b) {
    if(a==0) return make_tuple(0, 1, b);
    tuple<int, int, int> temp = gcd_extended(b%a, a);
    return make_tuple(get<1>(temp)-(b/a)*get<0>(temp), get<0>(temp), get<2>(temp));
}

/**
 * @brief Extended Euclidean Algorithms
 * 
 * ax + by = gcd(a, b)
 * 
 * let b = m
 * => ax + my = gcd(a, m)
 * => ax + my = 1     ; gcd(a, m)=1
 * take mod both side
 * => (ax + my) (mod m) = 1 (mod m)
 * => ax = 1 (mod m)
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int mod_inverse_ecludian(int a, int m) {
    tuple<int, int, int> x = gcd_extended(a, m);
    if(get<2>(x)!=1) {
        return -1;
    }
    return ((get<0>(x)%m)+m)%m;
}

int power(int x, int y, int m) {
    if(y==0) return 1;
    int a = power(x, y/2, m)%m;
    if(y%2==0) {
        return (a*a)%m;
    }
    return (((a*a)%m)*x)%m;
}

/**
 * @brief when `m` is a prime number
 * 
 * According to Fermat's little theorem 
 * => a^m = a (mod m)
 * => a^-1 = a^(m-2) (mod m)
 * 
 * modular inverse = x = (a^(m-2))%m
 * 
 * @param a 
 * @param m 
 * @return int 
 */
int mod_inverse_prime(int a, int m) {
    return power(a, m-2, m)%m;
}

/**
 * @brief Driver Code
 * 
 * @return signed 
 */
signed main() {
    int a, m;
    cin >> a >> m;
    cout << "Naive Approach : " << mod_inverse_naive(a, m) << "\n";
    cout << "Extended Eculidean Theorem : " << mod_inverse_ecludian(a, m) << "\n";
    cout << "If m is prime : " << mod_inverse_prime(a, m) << "\n";
}