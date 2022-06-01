class Solution {
public:
    bool isSameAfterReversals(int num) {
       if(num==0 or num%10!=0)
           return true;
        return false;
    }
};