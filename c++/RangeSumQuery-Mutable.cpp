class NumArray {
public:
    vector<int> A;
    int sum =0 ;
    NumArray(vector<int>& nums) {
        A = nums;
        for(int i =0;i < nums.size();i++)
            sum += nums[i];
        }
    
    void update(int index, int val) {
        sum += (val - A[index]); //sum = sum - A[index] + val
        A[index] = val; 
       
    }
    
    int sumRange(int left, int right) {
        int res = sum;
        for(int i = 0;i < left; i++)
            res -= A[i];
        for(int i = right + 1; i < A.size();i ++  )
            res -= A[i];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
