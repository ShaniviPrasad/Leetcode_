class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m=n;
        vector<vector<int>>matrix(m,vector<int>(n));
       int minr=0, maxr=m-1, minc=0, maxc=n-1 , count=1;
       while(minr<=maxr && minc<=maxc){
        for(int j=minc; j<=maxc; j++){
            matrix[minr][j]=count++;
        }
        minr++;
        for(int i=minr; i<=maxr ; i++){
            matrix[i][maxc]=count++;
        }
        maxc--;
       for(int j=maxc; j>=minc; j--){
            matrix[maxr][j]=count++;
        }
        maxr--;
        for(int i=maxr; i>=minr; i--){
            matrix[i][minc]=count++;
        }
        minc++;
       }
       return matrix;
    }
};