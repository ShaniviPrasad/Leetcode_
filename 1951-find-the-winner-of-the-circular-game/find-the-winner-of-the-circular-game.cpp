class Solution {
public:
    int josephusRec(vector<int> person, int k, int index){
    if (person.size() == 1) { ;
        return person[0];
    }
    index=((index+k-1)% person.size());
    person.erase(person.begin()+ index);
    return josephusRec(person, k, index);
   }
    int findTheWinner(int n, int k) {
        int index=0; 
        vector<int> person;
        for (int i=1; i<= n; i++) 
        person.push_back(i);
     return josephusRec(person,k,index);
    }
};