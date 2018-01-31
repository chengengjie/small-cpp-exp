#include <boost/icl/split_interval_map.hpp>
#include <iostream>

using namespace std;
using namespace boost::icl;

int main() {
    // std::set has op+ under icl
    set<int> mySet = {1, 2, 3};
    set<int> mySet2 = {3, 4, 5};
    auto mergedSet = mySet + mySet2;
    cout << mergedSet << endl;
    // {1 2 3 4 5 }

    // interval_map aggregate (arithmetic add)
    interval_map<int, int> intervals;
    intervals.add({interval<int>::closed(0, 5), 1});
    intervals.add({interval<int>::closed(2, 3), 2});
    intervals.add({interval<int>::right_open(4, 10), 3});
    intervals.add({interval<int>::closed(10, 20), 3});
    cout << intervals << endl;
    // {([0,2)->1)([2,3]->3)((3,5]->4)((5,20]->3)}

    // interval_map aggregate (set union)
    interval_map<int, set<string>> setOnIntervals;
    setOnIntervals.add({interval<int>::closed(1931, 1949), {"China"}});
    setOnIntervals.add({interval<int>::closed(1941, 1945), {"USA"}});
    setOnIntervals.add({interval<int>::closed(1895, 1945), {"Korea"}});
    setOnIntervals.add({interval<int>::closed(1945, 1953), {"Korea"}});
    cout << setOnIntervals << endl;
    // {([1895,1931)->{Korea })([1931,1941)->{China Korea })([1941,1945]->{China Korea USA })((1945,1949]->{China Korea })((1949,1953]->{Korea })}

    // query on intervals
    auto range = setOnIntervals.equal_range(interval<int>::closed(1942, 1950));
    for (auto it = range.first; it != range.second; ++it) {
        cout << "(" << it->first << "->" << it->second << ")";
    }
    cout << endl;
    // ([1941,1945]->{China Korea USA })((1945,1949]->{China Korea })((1949,1953]->{Korea })
    cout << boolalpha << (interval<int>::closed(1941, 1945) < interval<int>::closed(1942, 1950)) << endl;

    // boundary
    auto rightOpen = interval<int>::right_open(4, 10);
    cout << rightOpen << endl;
    cout << rightOpen.upper() << endl;
    cout << upper(rightOpen) << endl;
    cout << last(rightOpen) << endl;

    return 0;
}