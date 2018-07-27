//Simple Threads
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
using namespace std;
void Hello(string name)
{
    string Greeting("Hello I am ");
    Greeting = Greeting + name + "\n";
    cout << Greeting << endl;
}


int main()
{
    //string n1("Brook"), n2("Belinda"), n3("Bella"), n4("Michael");
    string n1, n2, n3, n4;
    cout << "Enter names: ";
    cin >> n1 >> n2 >> n3 >> n4;
    
    thread t1(Hello, n1);
    thread t2(Hello, n2);
    thread t3(Hello, n3);
    thread t4(Hello, n4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    return 0;
}
