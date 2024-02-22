Write a recursive function to calculate the factorial of a non-negative integer.
  
#include <iostream>
using namespace std;

int fact(int n)
{
  if(n==1)
  return 1;
  return n*fact(n-1);
}

int main() 
{
    int n=5;
    cout << fact(n);
}

Write a recursive function to calculate the sum of n numbers.
  
#include <iostream>
using namespace std;

int sum(int n)
{
  if(n==0)
  return 0;
  return n+sum(n-1);
}

int main() 
{
    int n=5;
    cout << sum(n);
}

Implement a recursive function to compute the nth Fibonacci number.

#include <iostream>
using namespace std;

int fib(int n)
{
  if(n<=1)
  return n;

  return fib(n-1)+fib(n-2);
}

int main() 
{
    int n=10;
    cout << fib(n);
}

Write a recursive function to reverse a string.

#include <iostream>
#include <string>
using namespace std;

void rev(string &s,int i,int j)
{
  if(j <= i)
  return;
  swap(s[i],s[j]);
  rev(s,i+1,j-1);
}

int main() 
{
    string s ="polaroid";
    int i=0,j=s.length()-1;
    rev(s,i,j);
    cout << s;
}

Implement a recursive function to check if a string is a palindrome.
  
#include <iostream>
#include <string>
using namespace std;

void rev(string &s,int i,int j)
{
  if(j <= i)
  return;
  swap(s[i],s[j]);
  rev(s,i+1,j-1);
}

int main() 
{
    string s ="rotator";
    int i=0,j=s.length()-1;
    string dup = s;
    rev(s,i,j);
    if(s==dup)
    cout << "True";
    else
    cout << "False";
}
Write a recursive function to calculate the exponentiation of a number.
  
#include <iostream>
using namespace std;

int expo(int base, int exponent)
{
  if(exponent == 1)
  return base;
  return base*expo(base, exponent-1);
}

int main() 
{
    int base = 2;
    int exponent = 3; 
    cout << expo(base, exponent); 
    return 0;
}
