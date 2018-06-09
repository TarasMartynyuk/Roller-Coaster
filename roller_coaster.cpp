#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

int main()
{
    int kAttrCapacity;
    int kRides;
    int N;
    cin >> kAttrCapacity >> kRides >> N; cin.ignore();
//    cerr <<

    list<int> persons;

    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        cerr << Pi << " ";
        cerr << endl;

        persons.push_back(Pi);
    }

    long days_cash = 0;
    for (int i = 0; i < kRides; ++i) {

        auto it = persons.begin();
        int places_left = kAttrCapacity;
        while (*it <= places_left) {
            int group_count = *it;

            days_cash += group_count;
            places_left -= group_count;

            it = persons.erase(it);
            persons.push_back(group_count);
        }
    }


    cout << days_cash << endl;
}