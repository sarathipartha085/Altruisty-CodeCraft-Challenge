/*
Question 1

Meera is a real estate investor. She is known for her excellent sense of timing when it comes to buying and selling properties. Meera always buys property at a low price and sells it at a high price to ensure the maximum profit. However, Meera never buys a property if the price is constantly going down.

As an analyst, your job is to calculate the maximum profit Meera could have made based on the property prices each day. If prices only decrease over time, Meera does not make any purchases.

Example 1:

Price = `[3, 8, 4, 12]`

Meera buys on the first day at price 3 and sells it on the fourth day at price 12, resulting in a profit of 9.

Example 2:

Price = `[15, 14, 12]`

The price always went down, so Meera never bought any property.

Input Format:

First line with an integer `n`, denoting the number of days with property prices.

Next `n` lines, each with an integer, representing the property price on that day.

Output Format:

Maximum profit made by Meera in a single line.
Constraints:

Number of days `<= 10^8`

Sample Input for Custom Testing

Sample Input: 6, [5, 10, 3, 9, 1, 8]
Sample Output: 7

Explanation:
The maximum profit possible is when Meera buys the property at 3 and sells it at 10, resulting in a profit of 7.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if ( prices.size() == 0 ) return 0;

        int result = 0; // maximim profit
        int check = INT_MAX; // minimum prize
        int profit; // track prize for each iteration

        for ( int price : prices ) {

            if ( price < check ) check = price;

            profit = price - check;
            
            if ( profit > result ) result = profit;
        
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;  // Number of days

    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    Solution solution;
    int result = solution.maxProfit(prices);
    
    cout << result << endl;

    return 0;
}
