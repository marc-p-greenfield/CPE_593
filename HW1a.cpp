/*
Author : Marc Greenfield
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double Sieve(long long a, long long b){

    //Create array of type bool
    bool *prime;
    prime = new bool[b];

    //Set all values in array to true
    for (long i = 0; i < b; i++){
        prime[i] = true;
    }


    long count = 0;

    //Runs through main Sieve algorithm
    for (long x = 2*2; x <= (b); x += 2 ){
        prime[x] = false;
    }
    for (long x = 3; x <= sqrt(b); x = 2*x ){
        if (prime[x] == true){
            for (long y = pow(x,2); y <= b; y += x){
                prime[y] = false;
            }
        }

    }

    //Loop to print out and count how many primes are present
    for (long x = a; x <= b; x++){
        if(prime[x] == true){
            count++;
        }
    }
    return count;
}

int main(){
    int a, b;
    cout << "Please enter two numbers separated by one space" << endl;
    cin >> a >> b;
    cout << Sieve(1,20) << endl;
    cout << Sieve(a,b) << endl;
}
