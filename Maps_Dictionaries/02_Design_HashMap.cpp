#include <utility> // for pair and it's functions
#include <forward_list>
#include <algorithm>

class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        // Apply hashing function 
        int bucket = key % 1000;
        
        // Only if the key is non existant, then make new pair.
        if (auto it = contains(key); it == hash_table[bucket].end())
        {   
            std::pair<int, int> key_val(key, value);
            
            // forward_list will automatically take care of collisions
            hash_table[bucket].push_front(key_val);
        }
        else
        {
            // Overwrite existing value
            it->second = value;
        }
    }
    
    int get(int key) {
        
        // Apply hashing function 
        int bucket = key % 1000;
        
        
        // Only if the key is non existant, return -1.
        if (auto it = contains(key); it == hash_table[bucket].end())
        {   
            return -1;
        }
        else
        {
            // Return existing value
            return it->second;
        }
    }
    
    void remove(int key) {
        // Apply hashing function 
        int bucket = key % 1000;
        
        // Remove element with the key in the particular bucket if it exists
        hash_table[bucket].remove_if([&](const auto& item)
                            {
                                return std::get<0>(item) == key;
                            });
        
        
    }
    
private:
    // Keep array size as 1000 as you then have constant access time for 10^3 elements
    // and for the rest 10^3 only it will be linear
    std::forward_list<std::pair<int,int>> hash_table[1000]{};
    
    // Private helper function to check if key already exists and return it's location
    std::forward_list<std::pair<int,int>>::iterator contains(int key) {
        // Apply hashing function 
        int bucket = key % 1000;
        
        // Find key in the particular bucket
        // https://stackoverflow.com/questions/63829918/using-stdfind-to-find-elements-in-vector-of-stdpair
        auto it = std::find_if(hash_table[bucket].begin(), 
                               hash_table[bucket].end(),
                              [&](const auto& item)
                               {
                                   return std::get<0>(item) == key;
                               });
        return it;
        
    }

    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
