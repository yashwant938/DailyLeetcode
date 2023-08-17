// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      //    int n=mat.size();
      //   int m=mat[0].size();
      //   if(mat[0][0]!=0) mat[0][0]=n+m;
        
      //  for(int j=1;j<m;j++){
			// 	 if(mat[0][j]!=0)	mat[0][j]=mat[0][j-1]+1;
			//  }
			//  for(int i=1;i<n;i++){
			// 	 if(mat[i][0]!=0)	mat[i][0]=mat[i-1][0]+1;
			//  }
			//  for(int i=1;i<n;i++)
			// 	 for(int j=1;j<m;j++)
			// 		 if(mat[i][j]!=0) mat[i][j]=min(mat[i-1][j],mat[i][j-1])+1;
				
      //   for(int i=n-2;i>=0;i--) if(mat[i][m-1]!=0)	mat[i][m-1]=min(mat[i][m-1],mat[i+1][m-1]+1);
			// 	for(int j=m-2;j>=0;j--){
			// 		if(mat[n-1][j]!=0)	mat[n-1][j]=min(mat[n-1][j],mat[n-1][j+1]+1);
			// 	}
      //   return mat;
      //getting some test cases false in this code
        
       class Solution {
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
                else{
                    ans[i][j]=INT_MAX;
                }
            }
        }
        int delrow[]={0,-1,0,1};
        int delcol[]={-1,0,1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=delrow[i]+r;
                int nc=delcol[i]+c;
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(ans[nr][nc]>ans[r][c]+1){
                        ans[nr][nc]=ans[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return ans;
    }
};
  