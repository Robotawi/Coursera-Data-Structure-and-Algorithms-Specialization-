#include<iostream>
#include<bits/stdc++.h>

// LCM(a, b) = abs(a*b)/GCD(a, b)

int gcd(int a, int b){

    if (b == 0){
        return a;
    }
    
    return gcd(b, a%b); 
}

using namespace std; 

int main(int argc, char const *argv[])
{
    long a = 0;
    long b = 0;

    //cout << "Enter a : " ;
    cin >> a; 
    //cout << "Enter b : " ;
    cin >> b; 

	cout << abs(a*b)/gcd(a, b); 

    return 0;
}
