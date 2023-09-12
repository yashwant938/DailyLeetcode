class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int>st;
        unordered_map<char,int>mp;


        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }

        int count = 0;
        for(auto it: mp){

            while(it.second && (st.find(it.second) != st.end())){
                it.second--;
                count++;
            }
            
            st.insert(it.second);
        }

        return count;

    }
};