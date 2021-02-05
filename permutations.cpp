/*
 * String Permutations
 * ---------------------------------------------------------------------------------------------
 * Create all permutations of an input string and remove duplicates, if present. That is to say,
 * shuffle all letters from the input in all possible orders. For instance,
 *
 * permutations("a");     // => vector<string> {"a"}
 * permutations("ab");    // => vector<string> {"ab", "ba"}
 * permutations("aabb");  // => vector<string> {"aabb", "abab", "abba", "baab", "baba", "bbaa"}
 * ---------------------------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> permutations(string str)
{
    vector<string> myvec;
    sort(str.begin(), str.end());

    do { 
        myvec.push_back(str);
    } while (next_permutation(str.begin(), str.end()));
    return myvec;
}

int main()
{
    vector<string> myvec = permutations("aabb");
    for (string str : myvec) cout << str << endl;
}
