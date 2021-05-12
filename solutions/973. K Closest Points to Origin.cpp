// Using Heap 

class Solution {
public:
    
    int getDistance(int x , int y){
        
        return x * x + y * y ; 
    }
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        
        
        priority_queue<pair<int , pair<int , int>>> pointsSortedByDistance  ; 
        
        int length = points.size();
        
      
        
        for(int i=0; i<length; i++){
            
            int distance = getDistance(points[i][0] , points[i][1]);
            
            int x = points[i][0];
            int y = points[i][1];
            
            if(i<k){
                 pointsSortedByDistance.push({distance , {x , y}});
            }
            else{
                  pointsSortedByDistance.push({distance , {x , y}});
                pointsSortedByDistance.pop();
                

            }
           
        }
        
        int count = 0;
        vector<vector<int>>ans;
        
        while(count < k){
            
            auto point = pointsSortedByDistance.top();
            pointsSortedByDistance.pop();
            ans.push_back({point.second.first , point.second.second});
            ++count ; 
            
        }
    return ans;
    }
};
