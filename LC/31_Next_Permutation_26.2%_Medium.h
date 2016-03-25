/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        //http://www.nayuki.io/page/next-lexicographical-permutation-algorithm
        //Find largest index i such that array[i − 1] < array[i].
        //Find largest index j such that j ≥ i and array[j] > array[i − 1].
        //Swap array[j] and array[i − 1].
        //Reverse the suffix starting at array[i].(In fact, we can avoid sorting and simply reverse the suffix, because the replaced element respects the weakly decreasing order. )
        if(num.size()<=1) return;
        int left =-1;
        int right=-1;
        int i=1;
        while(i<num.size()){
            if(num[i]>num[i-1])
                right = i-1;
            i++;
        }
        if(right==-1){
            reverse(num.begin(), num.end());
        }
        else{
            for(int i=right+1; i<num.size(); i++)
                if(num[i]>num[right])
                    left = i;
            swap(num[left], num[right]);
            reverse(num.begin()+right+1, num.end());
        }
    }
};