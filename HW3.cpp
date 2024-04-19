#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class Cache {
private:
    int numEntries; // Total number of cache entries
    int associativity; // Associativity of the cache
    vector<vector<bool>> validBits; // Valid bits for cache entries
    vector<vector<int>> tags; // Tags for cache entries

public:
    // Constructor
    Cache(int numEntries, int associativity) : numEntries(numEntries), associativity(associativity) {
        // Initialize valid bits and tags for each set
        validBits.resize(numEntries / associativity, vector<bool>(associativity, false));
        tags.resize(numEntries / associativity, vector<int>(associativity, -1));
    }

    // Process memory reference
    bool processMemoryReference(int address) {
        int setIndex = address % (numEntries / associativity);
        int tag = address / (numEntries / associativity);

        // Check if the tag matches any entry in the cache set
        for (int i = 0; i < associativity; ++i) {
            if (validBits[setIndex][i] && tags[setIndex][i] == tag) {
                return true; // Hit
            }
        }

        // Update cache set with new tag
        validBits[setIndex].push_back(true);
        tags[setIndex].push_back(tag);

        // Remove the oldest entry if set is full
        if (validBits[setIndex].size() > associativity) {
            validBits[setIndex].erase(validBits[setIndex].begin());
            tags[setIndex].erase(tags[setIndex].begin());
        }

        return false; // Miss
    }
};

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " num_entries associativity memory_reference_file\n";
        return -1;
    }

    int numEntries = atoi(argv[1]);
    int associativity = atoi(argv[2]);
    string memoryReferenceFile = argv[3];


    // Create cache object
    Cache cache(numEntries, associativity);

    // Open memory reference file
    ifstream input(memoryReferenceFile);
    if (!input.is_open()) {
        cerr << "Error: Unable to open memory reference file." << endl;
        return 1;
    }

    // Process memory references
    int address;
    while (input >> address) {
        bool hit = cache.processMemoryReference(address);
        cout << address << " : " << (hit ? "HIT" : "MISS") << endl;
    }

    // Close files
    input.close();

    return 0;
}
