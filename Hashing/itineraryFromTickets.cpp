#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Function to determine and print travel itinerary based on unordered ticket mappings
void printItinerary(const unordered_map<string, string>& tickets) {
    unordered_set<string> destinations;

    // Step 1: Identify all cities that are destinations (O(n))
    for (const auto& ticket : tickets) {
        destinations.insert(ticket.second); // Each insertion is O(1) average
    }

    // Step 2: Find the starting city (one that is not in the destinations) (O(n))
    string startCity = "";
    for (const auto& ticket : tickets) {
        if (!destinations.count(ticket.first)) { // Checking presence is O(1) average
            startCity = ticket.first;
            break;
        }
    }

    // Step 3: Traverse the itinerary using ticket mappings (O(n))
    cout << "Itinerary: " << startCity;
    while (tickets.count(startCity)) { // Checking existence is O(1) average
        startCity = tickets.at(startCity); // Accessing map value is O(1) average
        cout << " -> " << startCity;
    }
    cout << endl;
}

int main() {
    unordered_map<string, string> tickets = {
        {"Chennai", "Bengaluru"},
        {"Mumbai", "Delhi"},
        {"Goa", "Chennai"},
        {"Delhi", "Goa"}
    };

    printItinerary(tickets);
    return 0;
}