class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        priority_queue<pair<int,char>> pq; //max heap

        string ans ="";

        //counting freq and inserting in map
        for(char c:s){ 
            map[c]++;
        }

        //push in pq so that they can arrange by freq order
        for(auto it : map){
            pq.push({it.second, it.first});
        }

        //traverse in maxHeap and append char to string
        while(!pq.empty()){
            auto temp = pq.top();
            int freq = temp.first;
            int ch = temp.second;

            ans+=string(freq,ch); //(size,element)
            pq.pop();
        }
        return ans;
    }
};