class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        if(dead.count("0000")){
            return -1;
        }
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({"0000",0});
        visited.insert("0000");
        while(!q.empty()){
            auto t = q.front();
            auto curr = t.first;
            auto steps = t.second;
            q.pop();
            if(curr == target){
                return steps;
            }
            for(int i=0;i<4;i++){
                string next = curr;
                if(curr[i]=='9'){
                    next[i] = '0';
                }
                else{
                    next[i] = curr[i]+1;
                }
                if(!dead.count(next) && !visited.count(next)){
                    visited.insert(next);
                    q.push({next,steps+1});
                }
                next = curr;
                if(curr[i]=='0'){
                    next[i]='9';
                }
                else{
                    next[i]=curr[i]-1;
                }
                if(!dead.count(next) && !visited.count(next)){
                    visited.insert(next);
                    q.push({next,steps+1});
                }
            }
        }
        return -1;
    }
};