#include <iostream>
#include <string>
using namespace std;

int main() {

  int i, n;
  string rawline; 

  cout << "Enter a positive integer: ";
  
  
  while (cin >> n){
    bool is_prime = true;

    if (n == 0 || n == 1){
      is_prime = false;
    }
    
    // loop to check if n is prime
    for (i = 2; i <= n/2; ++i) {
      if (n % i == 0) {
        is_prime = false;
        break;
      }
    }
    
    cout << n << " is a prime: ";
    if (is_prime)
      cout << "True\n";
    else
      cout << "False\n";
    
    if (cin.peek() == '\n') {
        break;
    }

  }
  return 0;
}