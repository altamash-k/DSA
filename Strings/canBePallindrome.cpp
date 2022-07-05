#include<bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

bool canBePallindrome(string str)
{
    int count[NO_OF_CHARS] = {0};

    for(int i = 0; i < str.length(); i++)
        count[str[i]]++;
    
    int odd = 0;
    for(int i; i < NO_OF_CHARS; i++)
    {
        if(count[i] % 2 == 1)
            odd++;
        if(odd > 1)
            return false;
    }

    return true;
}

int main()
{
    string str;
    cout << "Enter string: ";
    cin >> str;

    if(canBePallindrome(str) == true)
        cout << "Can be Pallindrome";
    else
        cout << "Cannot Be a Pallindrome";

    return 0;
}