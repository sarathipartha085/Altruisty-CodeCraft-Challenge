/*

Question 2

Bees and flowers are placed on a line segment represented by a string. The character `*` represents a bee, and `|` represents a flower. The string consists of only these two characters. You are given two arrays, `startIndex` and `endIndex`, which represent ranges on the line segment. For each range, calculate the number of bees between two flowers, including the flowers at the endpoints.
Note: `startIndex` and `endIndex` are 1-indexed.

Example:

plaintext
s = "|*|**|"
startIndex = [1, 2]
endIndex = [5, 6]


For the first pair of indices (1,5), the substring is "`|*|**`", which contains 1 bee between two flowers.  
For the second pair of indices (2,6), the substring is "`*|**|`", which also contains 1 bee between two flowers.  
The answer for both pairs is `[1, 1]`.

Constraints:
\(1 \leq n \leq 10^5\)
\(1 \leq \text{Start Index}[i] \leq \text{End Index}[i]\)
 Each character in \( s \) is either "`*`" or "`|`".

Input Format for Custom Testing:

The first line contains the string \( s \).  
The next line contains an integer \( n \), the number of elements in `startIndex`.  
Each of the next \( n \) lines contains an integer for `startIndex[i]`.  
The next line contains an integer \( n \), the number of elements in `endIndex`.  
Each of the next \( n \) lines contains an integer for `endIndex[i]`.  

Sample Input for Custom Testing:

plaintext
|*|*|
1
1
1
5


Sample Output:

plaintext
1


Explanation:
The substring from index \(1\) to index \(5\) is "`|*|*|`". There is exactly 1 bee between two flowers in this substring.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BeeFlowerCounter {
private:
    string s;
    vector<int> prefix_bees;

public:
    BeeFlowerCounter(const string& str) {
        s = str;
        int n = s.size();
        prefix_bees.resize(n + 1, 0);
        preprocessPrefixBees();
    }

    void preprocessPrefixBees() {
        for (int i = 1; i <= s.size(); ++i) {
            prefix_bees[i] = prefix_bees[i - 1] + (s[i - 1] == '*' ? 1 : 0);
        }
    }

    int countBeesInRange(int start, int end) {
        int left_flower = -1;
        for (int i = start; i <= end; ++i) {
            if (s[i] == '|') {
                left_flower = i;
                break;
            }
        }

        int right_flower = -1;
        for (int i = end; i >= start; --i) {
            if (s[i] == '|') {
                right_flower = i;
                break;
            }
        }

        if (left_flower != -1 && right_flower != -1 && left_flower < right_flower) {
            return prefix_bees[right_flower + 1] - prefix_bees[left_flower];
        }
        return 0;  // No valid range between flowers
    }

    vector<int> getBeesBetweenFlowers(const vector<int>& startIndex, const vector<int>& endIndex) {
        vector<int> result;
        int q = startIndex.size();
        for (int i = 0; i < q; ++i) {
            int start = startIndex[i] - 1;
            int end = endIndex[i] - 1;
            result.push_back(countBeesInRange(start, end));
        }
        return result;
    }
};

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<int> startIndex(n);
    for (int i = 0; i < n; ++i) {
        cin >> startIndex[i];
    }

    vector<int> endIndex(n);
    for (int i = 0; i < n; ++i) {
        cin >> endIndex[i];
    }

    BeeFlowerCounter counter(s);
    vector<int> result = counter.getBeesBetweenFlowers(startIndex, endIndex);

    for (int res : result) {
        cout << res << endl;
    }

    return 0;
}

