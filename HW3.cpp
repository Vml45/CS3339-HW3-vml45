#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Class representing a simulated cache memory
class Cache {
private:
    int numEntries; // Stores the total number of cache entries
    int associativity; // Defines the number of lines per cache set
    vector<vector<bool>> validBits; // Matrix to store the validity of each cache entry within each set
    vector<vector<int>> tags; // Matrix to store the tags associated with each cache entry within each set

public:
    // Constructs a cache with a given number of entries and set associativity
    Cache(int numEntries, int associativity) : numEntries(numEntries), associativity(associativity) {
        // Calculate number of sets and initialize the valid bits and tags for each set
        int numSets = numEntries / associativity;
        validBits.resize(numSets, vector<bool>(associativity, false));
        tags.resize(numSets, vector<int>(associativity, -1));
    }

    // Processes a single memory address reference and determines if it's a cache hit or miss
    bool processMemoryReference(int address) {
        int setIndex = address % (numEntries / associativity); // Calculate the set index using modulo operation
        int tag = address / (numEntries / associativity); // Calculate the tag by dividing the address by the number of sets

        // Search for the tag in the cache set
        for (int i = 0; i < associativity; ++i) {
            if (validBits[setIndex][i] && tags[setIndex][i] == tag) {
                return true; // Cache hit
            }
        }

        // Cache miss: Update the cache set by adding the new tag
        validBits[setIndex].push_back(true);
        tags[setIndex].push_back(tag);

        // Ensure the cache set does not exceed its capacity by removing the oldest entry
        if (validBits[setIndex].size() > associativity) {
            validBits[setIndex].erase(validBits[setIndex].begin());
            tags[setIndex].erase(tags[setIndex].begin());
        }

        return false; // Return miss
    }
};

// Main function which setups the cache and processes memory references from a file
int main(int argc, char *argv[]) {
    // Verify command line arguments
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <num_entries> <associativity> <memory_reference_file>\n";
        return -1;
    }

    int numEntries = atoi(argv[1]);
    int associativity = atoi(argv[2]);
    string memoryReferenceFile = argv[3];

    // Instantiate the cache with specified size and associativity
    Cache cache(numEntries, associativity);

    // Open the file containing memory references
    ifstream input(memoryReferenceFile);
    if (!input.is_open()) {
        cerr << "Error: Unable to open memory reference file.\n";
        return 1;
    }

    // Read memory addresses from the file and process each one
    int address;
    while (input >> address) {
        bool hit = cache.processMemoryReference(address);
        cout << address << " : " << (hit ? "HIT" : "MISS") << endl;
    }

    // Close the input file
    input.close();

    return 0;
}
