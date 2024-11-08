#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();

    int sum_gas_minus_cost = 0;
    int surplus = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        int gas_minus_cost = gas[i] - cost[i];

        sum_gas_minus_cost += gas_minus_cost;
        surplus += gas_minus_cost;

        if (surplus < 0) {
            surplus = 0;
            start = i + 1;
        }
    }

    return sum_gas_minus_cost >= 0 ? start : -1;
}

void test() {
    vector<int> gas = {5, 8, 2, 8};
    vector<int> cost = {6, 5, 6, 6};

    cout << canCompleteCircuit(gas, cost) << endl;
}