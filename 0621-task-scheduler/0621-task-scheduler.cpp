class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //map + pq

        unordered_map<char,int> mp; //alphabets , freq
        for(char &ch : tasks){
            mp[ch]++;
        }

        priority_queue<int> pq;
        for(auto &it : mp){
            pq.push(it.second); //storing freq in pq
        }

        int time =0;
        while(!pq.empty()){
            vector<int> temp; //used to take n+1 task together

            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
//pushing top freq of pq in temp by decrementing by one as we used that n+1 task
                    temp.push_back(pq.top()-1); 
                    pq.pop();
                }
            }

            for(int freq : temp){
                if(freq>0) pq.push(freq);
            }

            //time calculating 
            if(pq.empty())
                time += temp.size();
            else
                time += n+1;
        }
        return time;
    }
};