#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <cassert>
#include <sstream>
using namespace std;

struct RideResult {
    RideResult(int new_lead_group, int cash_recieved)
        : new_lead_group(new_lead_group), cash_recieved(cash_recieved) {}

    int new_lead_group = 0;
    int cash_recieved = 0;
};

RideResult* emulateRide(int curr_lead_group, int attr_capacity, const vector<int>& groups) {

    int ride_cash = 0;
    int places_left = attr_capacity;
    int queue_start_index = curr_lead_group;
    bool people_left = true;
    while (places_left >= groups.at(curr_lead_group) && people_left) {

        ride_cash += groups.at(curr_lead_group);
        places_left -= groups.at(curr_lead_group);

        curr_lead_group = curr_lead_group < groups.size() - 1 ?
                          curr_lead_group + 1 : 0;
        people_left = curr_lead_group != queue_start_index;
    }
    return new RideResult (curr_lead_group, ride_cash);
}

int main()
{
    //region input

    int attr_capacity;
    int rides_count;
    int groups_count;
    cin >> attr_capacity >> rides_count >> groups_count; cin.ignore();

    vector<int> groups(groups_count);
    int curr_lead_group = 0;
    for (int i = 0; i < groups_count; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        groups.at(i) = Pi;
    }
    //endregion

    // each time a specific group leads the queue, the results of the ride will be the same
    vector<RideResult*> ride_results(groups_count, nullptr);
    long days_cash = 0;
    for (int i = 0; i < rides_count; ++i) {
        if(ride_results.at(curr_lead_group) == nullptr) {
            ride_results.at(curr_lead_group) = emulateRide(curr_lead_group, attr_capacity, groups);
        }
        days_cash += ride_results.at(curr_lead_group)->cash_recieved;
        curr_lead_group = ride_results.at(curr_lead_group)->new_lead_group;
//        assert(curr_lead_group >= 0 && curr_lead_group < groups.size());
    }

    cout << days_cash << endl;
}