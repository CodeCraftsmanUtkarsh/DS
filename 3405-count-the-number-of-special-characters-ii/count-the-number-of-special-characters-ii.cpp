class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_map<char,int> mp;
        int count = 0;

        for(int i = 0; i < word.size(); i++) {

            if(word[i] >= 'A' && word[i] <= 'Z') {

                if(mp.find(word[i]) == mp.end()) {
                    mp[word[i]] = i;
                }
            }
            else {
                mp[word[i]] = i;
            }
        }

        for(auto it : mp) {

            if(it.first >= 'A' && it.first <= 'Z') {

                char lower = it.first - 'A' + 'a';

                if(mp.find(lower) != mp.end() &&
                   mp[lower] < mp[it.first]) {

                    count++;
                }
            }
        }

        return count;
    }
};