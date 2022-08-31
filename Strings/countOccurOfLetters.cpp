#include<bits/stdc++.h>
using namespace std;

string countOcc(string &str)
{
    string ans = "";
    int count = 1;
    for(int i = 0; i < str.length(); i++)
    {
        
        if(str[i] == str[i+1])
        {
            count++;
        }
        else
        {
            if(count == 1)
                ans += str[i];
            else
            {
                ans += str[i];
                ans += to_string(count);
            }

            count = 1;
        }
    }

    return ans;
}

int main()
{
    string str;
    cout << "Enter String: ";
    cin >> str;

    string ans = countOcc(str);
    cout << ans;
}