class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        // Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        // Sort frequencies in ascending order
        sort(freq.begin(), freq.end());
        
        int max_freq = freq[25] - 1;  // Max freq minus 1 (last bucket is always full)
        int idle_slots = max_freq * n;
        
        // Fill idle slots with remaining tasks
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            idle_slots -= min(freq[i], max_freq);
        }
        
        // If idle slots remain, add to task count, else just return tasks.size()
        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
    }
};