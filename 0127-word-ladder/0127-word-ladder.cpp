// Approach:
// 1. Store all dictionary words in a hash set.
// 2. Start BFS from beginWord.
// 3. Generate all possible one-letter transformations.
// 4. If a transformed word exists in the dictionary,
//    push it into the queue and remove it from the set.
// 5. First time reaching endWord gives the shortest sequence.

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(),wordList.end());

        // base cae, End word doesn't exist
        if (!st.count(endWord)) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        // Mark beginWord as visited by removing from set
        st.erase(beginWord);

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word==endWord) return level;// Destination reached

            // Try changing every character
            for (int i=0;i<word.size();i++) {
                char original=word[i]; //IMP STEP , REMEBER

                for (char ch='a';ch<='z';ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push({word,level+1});
                        st.erase(word);             // Mark visited
                    }
                }
                word[i] = original;   // Restore original character
            }
        }

        return 0;
    }
};

// char original=word[i]; IMP STEP , REMEBER Because every character position must be changed starting from the original word, not from a word that was already modified. , word[i] = original;

// Change index 0:
// After finishing index 0, if you don't restore:
// word = "zit"
// Now when changing index 1, you'll generate:like Z_t so ultimate change 2 words but we can change only one word