#include <iostream>

using namespace std;

void reverse(char* name, size_t len);

int main() {
    char* me = new char[3];
    me[0] = 'L';
    me[1] = 'e';
    me[2] = 'o';

    cout << "Hello, " << me << "!" << endl;

    return 0;
}

void reverse(char* name, size_t len)
{
    
}