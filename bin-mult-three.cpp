/*
 * Binary Multiples of Three
 * ----------------------------------------------------------------------------------------------
 * Create a regular expression capable of evaluating binary strings (strings with only 1s and 0s)
 * and determining whether the given string represents a number divisible by 3.
 * ----------------------------------------------------------------------------------------------
 * Take into account that:
 * 
 * -- An empty string might be evaluated to true.
 * -- The input should consist only of binary digits, no spaces, alphanumeric characters, etc.
 * -- There might be leading 0s.
 * ----------------------------------------------------------------------------------------------
 * Examples:
 * 
 * multiple_of_3("000") should print true
 * multiple_of_3("001") should print false
 * multiple_of_3("011") should print true
 * ----------------------------------------------------------------------------------------------
 */

#include <iostream>
#include <regex>
using namespace std;

void multiple_of_3(string binary_str)
{
    regex multiple_of_3_regex("(1(01*0)*1|0)*");

    if (regex_match(binary_str, multiple_of_3_regex)) cout << boolalpha << true << endl;
    else cout << boolalpha << false << endl;
}

int main()
{
    multiple_of_3("");      // true
    multiple_of_3(" 0");    // false
    multiple_of_3("abc");   // false
    multiple_of_3("000");   // true
    multiple_of_3("110");   // true
    multiple_of_3("111");   // false
    multiple_of_3("011");   // true
    multiple_of_3("101111000110000101001110"); // 12345678 --> true
}
