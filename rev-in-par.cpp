/*
 * The following function reverses characters in (possibly nested) parentheses
 * in the input string. Input strings will always be well-formed with matching
 * opening-closing parentheses. Examples are provided in the main function.
 */

#include <iostream>
#include <string>
using namespace std;

string reverse_in_parentheses(string str)
{
    string ret = "";
    int idx = 0;
    
    while (idx < str.length()) {
        ret.push_back(str[idx]);
        
        if (str[idx++] == ')')
        {
            string tmp = "";
            ret.pop_back();
            
            while (ret.back() != '(')
            {
                tmp += ret[ret.length()-1];
                ret.pop_back();
            }
            ret.pop_back();
            ret.append(tmp);
        }
    }
    return ret;
}

int main()
{                                                                                       // Outputs
    cout << reverse_in_parentheses("(bar)")                                  << endl;   // "rab"
    cout << reverse_in_parentheses("foo(bar)baz")                            << endl;   // "foorabbaz"
    cout << reverse_in_parentheses("foo(bar)baz(blim")                       << endl;   // "foorabbazmilb"
    cout << reverse_in_parentheses("foo(bar(baz))blim")                      << endl;   // "foobazrabblim"
    cout << reverse_in_parentheses("")                                       << endl;   // ""
    cout << reverse_in_parentheses("foo((bar)ren(baz))blim(ab(cd(ef)gh)ij)") << endl;   // "foobaznerbarblimjicdfeghba"
}
