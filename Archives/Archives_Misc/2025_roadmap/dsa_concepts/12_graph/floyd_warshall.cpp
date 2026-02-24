class Solution {
    public:
      void shortestDistance(vector<vector<int>>& mat) {
          int n = mat.size();
          // counter negative values
          for(int i =0;i<n;i++){
              for(int j=0;j<n;j++){
                  if(mat[i][j]==-1){
                      mat[i][j]=10000;
                  }
              }
          }
          // Main Code
          for(int via=0;via<n;via++){
              for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                      mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);\
                  }
              }
          }
          
          for(int i =0;i<n;i++){
              for(int j=0;j<n;j++){
                  if(mat[i][j]==10000){
                      mat[i][j]=-1;
                  }
              }
          }

        // Check for Negative Cycles
        for (int i = 0; i < n; i++) {
            if (mat[i][i] < 0) {
                return true;  // Negative cycle detected
            }
        }
          
      }
  };