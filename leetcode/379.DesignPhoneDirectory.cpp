// Time: O(1)
// Space: O(n). 10 digits: 10 * 10^10 bytes = 100 GB
class PhoneDirectory {
    // Hash set to store all available slots.
    unordered_set<int> slotsAvailable;

public:
    PhoneDirectory(int maxNumbers) {
        // Initially, all slots are available.
        for (int i = 0; i < maxNumbers; ++i) {
            slotsAvailable.insert(i);
        }
    }
    
    int get() {
        // If the hash set is empty it means no slot is available.
        if (slotsAvailable.size() == 0) {
            return -1;
        }

        // Otherwise, pop the first element from the hash set and return the slot. 
        int slot = *(slotsAvailable.begin());
        slotsAvailable.erase(slot);
        return slot;
    }
    
    bool check(int number) {
        // Check if the slot at index 'number' is available or not.
        return slotsAvailable.contains(number);
    }
    
    void release(int number) {
        // Mark the slot 'number' as available.
        slotsAvailable.insert(number);
    }
};


/**
379. Design Phone Directory
Medium

Design a phone directory that initially has maxNumbers empty slots that can store numbers. 
The directory should store numbers, check if a certain slot is empty or not, and empty a given slot.

Implement the PhoneDirectory class:

    PhoneDirectory(int maxNumbers) Initializes the phone directory with the number of available slots maxNumbers.
    int get() Provides a number that is not assigned to anyone. Returns -1 if no number is available.
    bool check(int number) Returns true if the slot number is available and false otherwise.
    void release(int number) Recycles or releases the slot number.
 */
