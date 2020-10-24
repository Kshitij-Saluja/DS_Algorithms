class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        if(nums .size()==0)
                return 1; 
        if(nums.size()==1)
    {
        if(nums[0] == 1)
            return 2;
        return 1;
    }        
        int off = 1;
        while(off<=nums.size()){
            if((nums[off-1]<nums.size() && nums[off-1]>0) && nums[off-1]!=off-1)
            {
                if(nums[off-1]!=nums[nums[off-1]])
                        swap(nums[off-1],nums[nums[off-1]]);
                else
                        off++;
            }
            else
                off++;
    }
        int i=1;
        while(nums.size()>i)
        {
            if(nums[i]!=i)
                return i;
            i++;
        }
        if(nums[0]==i)
            return ++i;
        return i;
    }
};
