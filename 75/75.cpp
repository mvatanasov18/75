#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string tracePath(unordered_map<string, string> map) {
    string res = "";

    // First, create an unordered_map to store the reverse mapping
    unordered_map<string, string> reverseMap;
    for (auto it = map.begin(); it != map.end(); it++) {
        reverseMap[it->second] = it->first;
    }

    // Find the starting point (i.e., the city that does not appear as a value in the map)
    string start = "";
    for (auto it = map.begin(); it != map.end(); it++) {
        if (reverseMap.find(it->first) == reverseMap.end()) {
            start = it->first;
            break;
        }
    }

    // Traverse the path by following the source-destination pairs
    string curr = start;
    while (map.find(curr) != map.end()) {
        res += curr + "->" + map[curr];

        // Add a comma if this is not the last pair
        if (map.find(map[curr]) != map.end()) {
            res += ", ";
        }

        curr = map[curr];
    }

    return res;
}

int main() {
    unordered_map<string, string> map = {
        {"NewYork", "Chicago"},
        {"Boston", "Texas"},
        {"Missouri", "NewYork"},
        {"Texas", "Missouri"}
    };

    string path = tracePath(map);

    cout << path << endl;
}
