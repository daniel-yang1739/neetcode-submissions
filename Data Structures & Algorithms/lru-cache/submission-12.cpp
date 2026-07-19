class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> order;  // {key, value}

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        auto it = cache[key];
        order.push_front(*it);
        order.erase(it);
        cache[key] = order.begin();
        return order.front().second;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            auto it = cache[key];
            order.erase(it);
        } else {
            if (cache.size() == capacity) {
                // delete least recent unit
                auto [k, v] = order.back();
                order.pop_back();
                cache.erase(k);
            }
        }
        order.push_front({key, value});
        cache[key] = order.begin();
    }
};
