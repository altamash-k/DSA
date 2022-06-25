// Can the input be completed to the given word;
// input: btfl
// word: beautiful
// result: true

// input: tflb
// word: beautiful
// false (order is not same of words)

// input: bbtfl
// word: beautiful
// false (occurrence of b is more)

#include<bits/stdc++.h>
using namespace std;

bool canComplete(string input, string word)
{
    int v = -1;
    string newStr = "";
    for(int x = 0; x < input.length(); x++) //input: btfl (0 to 3)
    {
        for(int y = v+1; y < word.length(); y++) //word: beautiful (0 to 8)
        {
            if(input[x] == word[y]) // (b==b) (t==t) (f==f) (l==l)
            {
                v = y; //(v=0) (v=4) (v=6) (v=8)
                newStr = newStr + input[x]; // btfl
                break;
            }
        }
    }

    // cout << newStr << endl;

    for(int i = 0; i < input.length(); i++)
    {
        if(newStr[i] != input[i]) 
            return false;
    }
    return true; // true
}

int main()
{
    string input;
    cout << "Enter input: ";
    cin >> input;

    string word;
    cout << "Enter word: ";
    cin >> word;

    if(canComplete(input, word) == true)
        cout << "Input can be completed";
    else
        cout << "Input can not be completed";
}