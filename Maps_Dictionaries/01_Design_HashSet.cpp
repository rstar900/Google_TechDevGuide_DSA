// Link: https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1139/

#include <forward_list>
#include <algorithm>

class MyHashSet {
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        // Apply hashing function 
        int bucket = key % 1000;
        
        // Only if the key is unique
        if (!contains(key))
        {   
        // forward_list will automatically take care of collisions
        hash_table[bucket].push_front(key);
        }
        
    }
    
    void remove(int key) {
        // Apply hashing function 
        int bucket = key % 1000;
        
        // Find key in the particular bucket if it exists
        hash_table[bucket].remove(key);
        
    }
    
    bool contains(int key) {
        // Apply hashing function 
        int bucket = key % 1000;
        
        // Find key in the particular bucket
        auto it = std::find(hash_table[bucket].begin(), hash_table[bucket].end(), key);
        
        if (it != hash_table[1000].end())
        {
            return true; 
        }
        
        return false;
        
    }

private:
    // Keep array size as 1000 as you then have constant access time for 10^3 elements
    // and for the rest 10^3 only it will be linear
    std::forward_list<int> hash_table[1000]{};
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
