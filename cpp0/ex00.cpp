#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string str1 = "something";
    char *str2 = NULL;
    // vr1 = 53;
    bool isValid = true;
    //char * str = "something";
    // cin >> vr1 >> vr2;
    //std::cout << how_much++ << "\n";
    //std::cout << ++how_much << "\n";
    // printf("%d", 'd');

    for (int i = 0; i < 5; i++)
    {
        cout << *str2 << endl;
        str2++;
    }

    return (0);
}