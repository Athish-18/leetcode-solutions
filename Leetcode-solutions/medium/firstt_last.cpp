class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> answer;

        if (nums.empty())
        {
            answer.push_back(-1);
            answer.push_back(-1);
            return answer;
        }

        
        int start=-1;
        int end=-1;

        int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin();

        if(lb==nums.size())
        {
            start=-1;
        }

        else if(nums[lb]!=target)
        {
            start=-1;
        }
        else
        {
            start=lb;
        }

        if(ub==0)
        {
            end=-1;
        }

        else if(nums[ub-1]==target)
        {
            end=ub-1;
        }
        else
        {
            end=-1;
        }

        answer.push_back(start);
        answer.push_back(end);

        return answer;
    }
};