//TC-->O(Words.size() * maxWidth)  // SC-->O(Words.size() * maxWidth)
class Solution {
public:
    string leftJustify(vector<string>&A, int diff, int i, int j){
        int spacesOnRight=diff-(j-i-1);
        string res=A[i];
        for(int k=i+1;k<j;k++){
            res.append(" "+A[k]);
        }
        while(spacesOnRight!=0){
            res+=" ";
            spacesOnRight--;
        }
        return res;
    }
  
    string middleJustify(vector<string>&A, int diff, int i, int j){
        int spacesNeeded=j-i-1;
        int spaces=diff / spacesNeeded;
        int extraSpaces=diff % spacesNeeded;
        string res=A[i];
        for(int k=i+1;k<j;k++){
            int spacesToApply=spaces+((extraSpaces--)>0? 1:0);
            while(spacesToApply!=0){
                res+=" ";
                spacesToApply--;
            }
            res+=A[k];
        }
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int i=0,n=words.size();
        while(i<n){
            int j=i+1;
            int linelen=words[i].size();
            while(j<n && (linelen+words[j].size()+(j-i-1)<maxWidth)){
                linelen+=words[j].size();
                ++j;
            }
            int diff=maxWidth-linelen;  //amount of space we need to assign
            int numberOfWords=j-i;
            if(numberOfWords==1 || j>=n) ans.push_back(leftJustify(words, diff, i, j));
            else  ans.push_back(middleJustify(words, diff, i, j));
            i=j;
        }
        return ans;
    }
};
