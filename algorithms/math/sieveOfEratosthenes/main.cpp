#include <cstdio> 
#include <iostream> 
#include <bitset> 
#include <vector> 

using namespace std; 

typedef long long          ll; 
typedef vector<int>        vi; 

ll _sieve_size; 
bitset<10000010> bs; 
vi primes; 

// Sieve of Eratosthenes.
void sieve(ll upperbound) { 
  _sieve_size = upperbound + 1; 
  bs.set(); 
  bs[0] = bs[1] = 0; 

  for(ll i=2; i<=_sieve_size; i++) { 
    if(bs[i]) { // This is a prime! :D
      for(ll j = i*i; j <= _sieve_size; j += i) 
	bs[j] = 0; // Mark the composite numbers 

      primes.push_back((int)i); // Save the prime number in a vector. 
    } 
  } 
} 

// Test if a number is prime.
bool isPrime(ll n) { 
  if(n <= _sieve_size) 
    return bs[n]; 

  // Checks if the number is prime, when this exceeds the _sieve_size value.
  for(int i=0; i<(int)primes.size(); i++) { 
    if(n % primes[i] == 0) 
      return false; 
  } 

  return true; 
} 

int main() { 

  sieve(10000000); 
    
  cout << isPrime(2147483647) << endl; // 10-digits prime 
  cout << isPrime(136117223861LL) << endl; // not a prime, 104729*1299709 
}
