class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int i=0;i< asteroids.size();i++){
            bool destroyed = false;

            // check collision
            while(!s.empty() && s.top()>0 &&  asteroids[i]<0) {
                if(abs(s.top()) < abs(asteroids[i])) {
                    s.pop();  
                    continue; //go to i++
                    }
                else if(abs(s.top()) == abs(asteroids[i])) {
                    s.pop();
                }
                destroyed=true;
                break;
            }
            if(!destroyed)
                s.push(asteroids[i]);
        }

        vector<int> ans(s.size());
        for(int i = s.size()-1; i >= 0; i--){
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};