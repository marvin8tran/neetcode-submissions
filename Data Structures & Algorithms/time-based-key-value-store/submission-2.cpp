class TimeMap {
private:
    
    unordered_map<string, vector<pair<string, int>>> values;
    //key  -> values, timestamp

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        values[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!values.count(key)){return "";}

        int l = 0;
        int r = values[key].size() - 1;
        string res = "";
       
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(values[key][mid].second <= timestamp){
                res = values[key][mid].first;
                l = mid + 1;
            } else{
                r = mid - 1;
            }

        }

        return res;
    }
};
