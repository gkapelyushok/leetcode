class Solution {
public:
    string longestDupSubstring(string s) {
        string_view result;
        unordered_set<string_view> set;
        int left = 1;
        int right = s.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            bool found = false;
            for (int i = 0; i < s.size() - mid + 1; i++)
            {
                auto [it, inserted] = set.emplace(s.data() + i, mid);
                if (!inserted)
                {
                    found = true;
                    result = *it;
                    break;   
                }
            }
            
            if (found)
                left = mid + 1;
            else
                right = mid - 1;
            
            set.clear();      
        }
            
        return {result.begin(), result.end()};
    }
};