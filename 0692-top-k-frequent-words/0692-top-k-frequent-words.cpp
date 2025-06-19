class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string word: words){
            freq[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq; pq; //min heap (since, we can pop easily)
        for(auto& [word, count]: freq){
            pq.push({count, word});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};