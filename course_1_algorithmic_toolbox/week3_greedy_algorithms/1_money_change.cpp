#include <iostream>

using namespace std; 

int main(int argc, char const *argv[])
{
    int m = 0;
    cin >> m;

    cout << m/10 + (m%10)/5 + (m%10)%5; 
    
    return 0;
}
