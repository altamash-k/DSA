#include<bits/stdc++.h>
using namespace std;
#define d 256
void search(char pat[], char txt[], int q)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for(i = 0; i < m-1; i++)
        h = (h * d) % q;

    for(i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q; // hash value of pattern
        t = (d * t + txt[i]) % q; // hash value of text
    }

    for(i = 0; i < n-m; i++)
    {
        if(p == t)
        {
            for(j = 0; j < m; j++)
            {
                if(txt[i+j] != pat[j])
                    break;
            }

            if(j == m)
                cout << "Pattern found at: " << i << endl;
                
        }
        if(i < n-m)
        {
            t = (d * (t-txt[i] * h) + txt[i+m]) % q;

            if(t < 0)
                t = t + q;
        }
    }
}

int main() 
{ 
    char txt[] = "GEEKS FOR GEEKS"; 
    char pat[] = "GEEK";
        
      //we mod to avoid overflowing of value but we should take as big q as possible to avoid the collison
    int q =INT_MAX; 
      
      // Function Call
      search(pat, txt, q); 
    return 0; 
} 