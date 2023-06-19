//TC-->O(wordList.size() * beginWord.size()* 26)  SC-->O(N)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>myset;
        bool ewpresent=false;
        for(auto it:wordList){
            myset.insert(it);
            if(it==endWord){
                ewpresent=true;
            }
        }
        if(ewpresent==false)return 0;
        queue<string>q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty()){
            depth+=1;
            int lsize=q.size();
            while(lsize--){
                auto curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();i++){
                    string temp=curr;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(temp.compare(curr)==0)continue;
                        if(temp.compare(endWord)==0){
                            return depth+1;
                        }
                        if(myset.find(temp)!=myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }  
        }
        return 0;
    }
};
