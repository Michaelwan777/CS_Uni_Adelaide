#include <iostream>

using namespace std;
int Fibonacci(int n);

int Fibonacci(int n)
{
    if (n ==1 || n== 2)
    {
        return 1;
    }
    return (Fibonacci(n - 2) + Fibonacci(n - 1));
}
int main()
{
    int N;
    cout << "Enter N = ";
    cin >> N;
    
    cout << Fibonacci(N) << endl;
    
    return 0;
}