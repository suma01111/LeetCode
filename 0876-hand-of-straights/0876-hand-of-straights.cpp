class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //base case 
        if(hand.size() % groupSize != 0) return false;
        
        //using sorted map
        map<int,int> mp; //task(h), freq =>O(N log N)
        for(int h : hand){
            mp[h]++;
        }

        //forming sorted and consecutive grp
        for(auto [h,freq] : mp){
            if(freq==0) continue;
            while(freq--){ //explained at the end
                for(int curr = h; curr<h+groupSize ; curr++){
                    if(mp[curr]==0) return false;
                    mp[curr]--;
                }
            }
        }
        return true;
    }
};

/* while(freq--) ==  means if freq = 2;   means card 2 appears twice
 This loop tries to make 2 full groups starting from that card.
h is the current card

freq is how many times card h appears

\U0001f539 if (freq == 0) continue;
If all cards of value h are already used (count is 0), skip to the next h

\U0001f539 while (freq--)
We try to form freq groups starting from h

This is how many groups we can start with card h */