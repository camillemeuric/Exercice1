#include <iostream>
#include <string>
using namespace std;

int main() {

  int i, n;
  string rawline; 

  cout << "Enter a positive integer: ";
  
  
  while (true){
    bool is_prime = true;
    cin >> n;
    
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