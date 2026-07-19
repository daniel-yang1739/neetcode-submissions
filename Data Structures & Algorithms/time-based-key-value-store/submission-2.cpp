class TimeMap {
private:
    unordered_map<string, vector<string>> key_values;
    unordered_map<string, vector<int>> key_timestamps;
public:
    void set(string key, string value, int timestamp) {
        key_values[key].push_back(value);
        key_timestamps[key].push_back(timestamp);
    }

    int upper_bound(vector<int> timestamps, int target) {
        int left = 0, right = timestamps.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (timestamps[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    string get(string key, int timestamp) {
        if (!key_timestamps.count(key)) return "";
        vector<int> timestamps = key_timestamps[key];
        if (timestamp < timestamps[0]) return "";
        int idx = upper_bound(timestamps, timestamp);
        return key_values[key][idx - 1];
    }
};
