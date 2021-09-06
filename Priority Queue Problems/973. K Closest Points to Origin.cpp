class comp{
  public:
     bool operator()(vector<int> a,vector<int> b){
         return (abs(a[0]*a[0]) + abs(a[1]*a[1])) < (abs(b[0]*b[0]) + abs(b[1]*b[1])); 
     }
};



class Solution {
public:
    
    int dist(int x,int y){
        return (abs(x*x) + abs(y*y));
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        int n = v.size();
        
        priority_queue<vector<int> , vector<vector<int > > ,comp > pq(v.begin(),v.begin()+k);
        
        for(int i=k;i<n;i++){
            vector<int> curr = pq.top();
            
            if(dist(v[i][0],v[i][1])   < dist(curr[0],curr[1])  ){
                pq.pop();
                pq.push(v[i]);
            }
        }
        
        
        vector<vector<int> > ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        
        
        return ans;
    }
};
