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

