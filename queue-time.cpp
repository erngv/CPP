/*
 * The Supermarket Queue
 * ----------------------------------------------------------------
 * There is a queue for the self-checkout tills at the supermarket.
 * Write a function to calculate the total time required for all
 * the customers to check out.
 * ----------------------------------------------------------------
 * Input
 * 
 * customers: an array of positive integers representing the queue.
 *            Each integer represents a customer, and its value is
 *            the amount of time they require to check out.
 * no_tills:  a positive integer, the number of checkout tills.
 * ----------------------------------------------------------------
 * Output
 * 
 * The function should return an integer, the total time required.
 * ----------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long queue_time(vector<int> customers, int no_tills)
{
    vector<int> vec(no_tills);
    for (int customer : customers)
        *min_element(vec.begin(), vec.end()) += customer;
    return *max_element(vec.begin(), vec.end());
}

int main()
{
    cout << queue_time(vector<int>{5, 3, 4}, 1) << endl;
    // should return 12
    // because when no_tills = 1, the total time is just the sum of the times

    cout << queue_time(std::vector<int>{10, 2, 3, 3}, 2) << endl;
    // should return 10
    // because no_tills = 2 and the 2nd, 3rd, and 4th people in the queue finish
    // before the 1st person has finished

    cout << queue_time(std::vector<int>{2, 3, 10}, 2) << endl;
    // should return 12
}
