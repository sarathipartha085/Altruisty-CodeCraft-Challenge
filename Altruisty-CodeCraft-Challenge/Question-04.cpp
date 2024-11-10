/*

Question 4 

At a festival, a street vendor is selling candy in different flavours. He has N different  flavours of candy (C[]). The task is to find the first  flavours of candy that appears an odd number of times in the batch of candies.

Note: If there are multiple  flavours that appear an odd number of times, the first  flavours in the array with an odd count should be displayed. If all  flavours appear an even number of times, output the message "All are even".

 Example 1:
Input:
8  -> Value of N [chocolate, mint, caramel, caramel, mint, vanilla, vanilla, chocolate]  -> C[] Elements C[0] to C[N-1]

Output:
chocolate  -> "chocolate" flavor appears an odd number of times.

Explanation:
From the input array above:
chocolate: 1 candy
mint: 2 candies
caramel: 2 candies
vanilla: 2 candies

Since "chocolate" is the only  flavours that appears an odd number of times, it is the output.

Example 2:
Input:
9  -> Value of N [strawberry, mango, mango, mango, orange, orange, apple, apple, berry]  -> C[] Elements C[0] to C[N-1]

Output:
mango  -> "mango"  flavours appears an odd number of times.

Explanation:
From the input array above:
strawberry: 1 candy
mango: 3 candies
orange: 2 candies
apple: 2 candies
berry: 1 candy

Both "mango" and "strawberry" appear an odd number of times, but "mango" occurs first, so it is the output.

Input Format for Testing
The candidate has to write the code to accept: 2 inputs

First input: Accept an integer value N (a positive integer).
Second input: Accept N number of flavor names (C[]), where each value is separated by a new line.

Output Format for Testing
The output should be a single string that represents the first  flavours that appears an odd number of times, or "All are even" if no  flavours have an odd count.

Constraints:
\(3 \leq N \leq 50\)
\(C[i] \) = {a-z} or {A-Z}

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string firstOddOccurrenceFlavour(int N, const vector<string>& C) {
        unordered_map<string, int> flavourCount;
        
        for (const string& flavour : C) {
            flavourCount[flavour]++;
        }
        
        for (const string& flavour : C) {
            if (flavourCount[flavour] % 2 != 0) {
                return flavour;
            }
        }
        
        return "All are even";
    }
};

int main() {
    int N;
    cin >> N; 
    vector<string> C(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    Solution solution;
    string result = solution.firstOddOccurrenceFlavour(N, C);
    cout << result << endl;

    return 0;
}
