#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

int main()
{
    int attr_capacity;
    int rides_count;
    int groups_count;
    cin >> attr_capacity >> rides_count >> groups_count; cin.ignore();
    cerr << "capacity : " << attr_capacity << "\nrides: " << rides_count << "\n#groups" << groups_count << endl;

    vector<int> groups(groups_count);
    int curr_lead_group = 0;
    cerr << "groups: [";
    for (int i = 0; i < groups_count; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        cerr << "\t" << Pi << ", ";

        groups.push_back(Pi);
    }
    cerr << "]\n";

    long days_cash = 0;
    for (int i = 0; i < rides_count; ++i) {

        int places_left = attr_capacity;
        int queue_start_index = curr_lead_group;
        bool people_left = true;
        while (places_left >= groups.at(curr_lead_group) && people_left) {

            days_cash += groups.at(curr_lead_group);
            places_left -= groups.at(curr_lead_group);

            curr_lead_group = curr_lead_group < groups.size() - 1 ?
                              curr_lead_group + 1 : 0;
            people_left = curr_lead_group != queue_start_index;
        }
    }


    cout << days_cash << endl;
}