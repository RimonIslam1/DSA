#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Structure to hold job details
struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparator to sort jobs in descending order of profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    vector<Job> job_details = {
        {'a', 2, 100},
        {'b', 2, 20},
        {'c', 1, 40},
        {'d', 3, 35},
        {'e', 1, 25}
    };

    int n = job_details.size();
    int maxD = 3;  // Maximum deadline

    // Sort jobs in descending order of profit
    sort(job_details.begin(), job_details.end(), compare);

    // Initialize job slots with 'empty'
    vector<string> slot(maxD, "empty");
    int total_profit = 0;

    // Assign jobs to slots
    for (int i = 0; i < n; ++i) {
        int k = job_details[i].deadline;
        while (k > 0) {
            if (slot[k - 1] == "empty") {
                slot[k - 1] = string(1, job_details[i].id);
                total_profit += job_details[i].profit;
                break;
            }
            --k;
        }
    }

    // Output the final job sequence and total profit
    cout << "Scheduled Jobs: ";
    for (const string& s : slot) {
        cout << s << " ";
    }
    cout << "\nTotal Profit: " << total_profit << endl;

    return 0;
}
