class Solution {
public:
    int minimumPushes(string word) {
        int result=0;
       for(int i=0; i<word.size(); i++)
       result+=(i/8+1);
       return result;
    }
};