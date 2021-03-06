/**
 * substitution_merlin.cpp
 * Check if current string can be generated by adding 'abc' repeatedly into a null string
 *
 * Description-
 * Let us fist see what happens when string=""
 * We add abc, string="abc"
 * Now we can add abc again, so string="aabcbc" "ababcc" abcabc"
 * This clearly shows that whenever we find a 'c', there must exist a 'b' for it, and for every 'b', we need an 'a'
 * This can be done using stack
 * And finally, we know that string is valid if and only if stack size after all operations is zero
 *
 * Time Complexity-O(n) Space Complexity-O(n)
 *
 * @author [merlin](https://github.com/m-e-r-l-i-n)
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

void solve()
{
    string a;
    cin>>a;
    stack<char> s;
    int i,n=a.length();

    for(i=0;i<n;i++)
    if(a[i]!='c') s.push(a[i]);
    else
    {
        if(!s.empty() && s.top()=='b')
        {
            s.pop();
            if(!s.empty() && s.top()=='a') s.pop();
            else
            {
                s.push('b');
                s.push('c');
            }
        }
        else s.push('c');
    }

    if(s.size()==0) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

/*
input-
3
aabcbc
abcabcababcc
abccba

output-
YES
YES
NO
*/
