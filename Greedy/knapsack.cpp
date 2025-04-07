#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5;
    double W = 10;

    vector<double> weight = {3, 3, 2, 5, 1};
    vector<double> profit = {10, 15, 10, 12, 8};

    double weight_left = W;
    double total_profit = 0.0;

    vector<bool> taken(n, false);

    while (weight_left > 0) {
        int max_profit_index = -1;

        // Find the item with the best profit-to-weight ratio
        for (int i = 0; i < n; i++) {
            if (!taken[i]) {
                if (max_profit_index == -1 || 
                    (profit[i] / weight[i] > profit[max_profit_index] / weight[max_profit_index])) {
                    max_profit_index = i;
                }
            }
        }

        if (max_profit_index == -1) {
            break; // No more items to take
        }

        taken[max_profit_index] = true;

        if (weight_left < weight[max_profit_index]) {
            double fraction_taken = weight_left / weight[max_profit_index];
            double added_profit = profit[max_profit_index] * fraction_taken;
            cout << "Taking " << fraction_taken * 100 << "% of item " << max_profit_index + 1 
                 << " (Weight: " << weight_left << ", Profit: " << added_profit << ")\n";
            total_profit += added_profit;
            weight_left = 0;
        } else {
            cout << "Taking full item " << max_profit_index + 1 
                 << " (Weight: " << weight[max_profit_index] << ", Profit: " 
                 << profit[max_profit_index] << ")\n";
            weight_left -= weight[max_profit_index];
            total_profit += profit[max_profit_index];
        }
    }

    cout << "Total profit: " << total_profit << endl;
    return 0;
}
