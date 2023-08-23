// class Solution {
// public:
//this one is wrog appraoch
//     string reorganizeString(string s) {
//         int i=0;
//         string str;
//         int n=s.size()-1;
//         while(s[i]!=s[i+1]){
//          str=next_permutation(s,s+n);
//         if(s.size()==i){
//             break;
//         }

//         }
//         if(str==s){
//             return "";
//         }
//         return str;
//     }
// };

/*
Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
*/


// class Solution {
// public:
//     string reorganizeString(string s) {
//         int n = s.size();
//         vector<int> count(26, 0);
//         for (char c : s) {
//             count[c - 'a']++;
//             if (count[c - 'a'] > (n + 1) / 2) {
//                 return "";
//             }
//         }
        
//         string result(n, ' ');
//         int evenIndex = 0, oddIndex = 1;
//         for (int i = 0; i < 26; i++) {
//             while (count[i] > 0 && count[i] <= n / 2 && oddIndex < n) {
//                 result[oddIndex] = 'a' + i;
//                 count[i]--;
//                 oddIndex += 2;
//             }
//             while (count[i] > 0) {
//                 result[evenIndex] = 'a' + i;
//                 count[i]--;
//                 evenIndex += 2;
//             }
//         }
//         return result;
//     }
// };
class Solution 
{
public:
    string reorganizeString(string s) 
    {
        map<char, int> mp;
        string res = "";
        priority_queue<pair<int, char>> pq;
        for(auto it : s)    mp[it]++;
        for(auto S : mp)    pq.push({S.second, S.first});
        while(pq.size() > 1)
        {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            res = res + top1.second;
            res = res + top2.second;

            top1.first = top1.first - 1;
            top2.first = top2.first - 1;

            if(top1.first > 0)  pq.push(top1);
            if(top2.first > 0)  pq.push(top2);
        }
        if(!pq.empty())
        {
            if(pq.top().first > 1)  res = "";
            else    res = res + pq.top().second;
        }
        return res;
    }
};