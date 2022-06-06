#include <bits/stdc++.h>
using namespace std;

int main()
{
   stack<char> s;
	char x;
	string expr;
   cout << "Enter the String: ";
   cin >> expr;
   for(int i = 0; i < expr.length(); i++) {
      char ch = expr[i];
      if(ch == ')') {
         if(s.top() == '(') {
            cout << "Duplicate Brackets Found" << endl;
            return 0;
         } else {
            while(s.top() != '(') {
               s.pop();
            }
            s.pop();
         }
      } else {
         s.push(ch);
      }
   }

   cout << "No Duplicates Brackets";
	return 0;
}
