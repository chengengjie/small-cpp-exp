#include <iostream>
#include <random>
#include <chrono>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

constexpr int vecSize = 1e7;

int main()
{
    // init vals
    default_random_engine generator;
    uniform_int_distribution<int> distribution;
    auto randInt = bind(distribution, generator);
    vector<int> vals(vecSize);
    for (auto& val : vals) val = randInt();

    // get minimum element (sorted by speed)
    using namespace chrono;
    using clock = high_resolution_clock;
    {
        auto start = clock::now();
        int minV = numeric_limits<int>::max();
        for (auto val : vals) {
            if (val < minV) minV = val;
        }
        duration<double> dur = clock::now() - start;
        cout << minV << " " << dur.count() << endl;
    }
    {
        auto start = clock::now();
        int minV = *min_element(vals.begin(), vals.end());
        duration<double> dur = clock::now() - start;
        cout << minV << " " << dur.count() << endl;
    }
    {
        auto start = clock::now();
        int minV = numeric_limits<int>::max();
        for (auto val : vals) {
            minV = min(minV, val);
        }
        duration<double> dur = clock::now() - start;
        cout << minV << " " << dur.count() << endl;
    }
}