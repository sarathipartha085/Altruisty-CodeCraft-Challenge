/*

Question 5

The Selection of candidates for ZSCS includes a strength test conducted on the field. A group of 4 trainees is participating in a lifting test for 3 rounds. After each round, you will record the strength level (in kilograms) lifted by each trainee. After all trainees complete all rounds, calculate the average strength level for each trainee across the 3 rounds, and identify the trainee (or trainees) with the highest average strength level as the strongest. If multiple trainees attain the same highest average level, they should all be selected.

Display the strongest trainee (or trainees) and the highest average strength level.

Note:

Only accept strength values between 1 and 200. If a strength value outside this range is entered, output "INVALID INPUT".
If the calculated highest average strength of all trainees is below 100, declare the trainees as unfit with the message "All trainees are unfit."
Round the average strength values to the nearest integer.

Example 1:

INPUT VALUES:

150
160
155
158
140
130
125
142
160
135
125
140


OUTPUT VALUES:

Trainee Number : 1
Trainee Number : 3

In this scenario, enter 12 integer values representing strength levels for each trainee, organized by:

Round 1
  Strength level of Trainee 1
  Strength level of Trainee 2
  Strength level of Trainee 3
  Strength level of Trainee 4
Round 2
  Strength level of Trainee 1
  Strength level of Trainee 2
  Strength level of Trainee 3
  Strength level of Trainee 4
Round 3
  Strength level of Trainee 1
  Strength level of Trainee 2
  Strength level of Trainee 3
  Strength level of Trainee 4

*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class TraineeStrengthTest {
public:
    bool isValidInput(const vector<vector<int>>& strength) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (strength[i][j] < 1 || strength[i][j] > 200) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<int> calculateAverages(const vector<vector<int>>& strength) {
        vector<int> averages(4);
        for (int i = 0; i < 4; ++i) {
            int sum = 0;
            for (int j = 0; j < 3; ++j) {
                sum += strength[i][j];
            }
            averages[i] = round(sum / 3.0);
        }
        return averages;
    }

    int findMaxAverage(const vector<int>& averages) {
        return *max_element(averages.begin(), averages.end());
    }

    bool allUnfit(const vector<int>& averages) {
        for (int avg : averages) {
            if (avg >= 100) {
                return false;
            }
        }
        return true;
    }

    void printStrongestTrainees(const vector<int>& averages, int maxAverage) {
        bool found = false;
        for (int i = 0; i < 4; ++i) {
            if (averages[i] == maxAverage) {
                cout << "Trainee Number : " << i + 1 << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "All trainees are unfit." << endl;
        }
    }

    void evaluateTrainees() {
        vector<vector<int>> strength(4, vector<int>(3));

        
        for (int round = 0; round < 3; ++round) {
            
            for (int trainee = 0; trainee < 4; ++trainee) {
                cin >> strength[trainee][round];
            }
        }

        if (!isValidInput(strength)) {
            cout << "INVALID INPUT" << endl;
            return;
        }

        vector<int> averages = calculateAverages(strength);
        int maxAverage = findMaxAverage(averages);

        if (allUnfit(averages)) {
            cout << "All trainees are unfit." << endl;
            return;
        }

        printStrongestTrainees(averages, maxAverage);
    }
};

int main() {
    TraineeStrengthTest test;
    test.evaluateTrainees();
    return 0;
}
