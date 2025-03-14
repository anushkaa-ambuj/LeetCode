class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int i=0, j=height.size()-1;

        while (i<j){
            max_area = max(max_area, min(height[i], height[j])*(j-i));

            if (height[i]<height[j]){
                i++;
            }
            else if (height[i]>height[j]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return max_area;
    }
};