class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int,vector<int>,greater<int>> min;
        for(int i = 0; i < N; i++){
            int sum = 0;
            for(int j = i; j < N; j++){
                sum += Arr[j];
                if(min.size() < K){
                    min.push(sum);
                }else{
                    if(sum > min.top()){
                        min.pop();
                        min.push(sum);
                    }
                }
            }
        }
       return min.top(); 
    }
};