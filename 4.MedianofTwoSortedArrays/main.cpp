#include <iostream>
#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> mergedArr;

    int i = 0, j = 0;
    while(i < nums1.size() || j < nums2.size()){
        if(i == nums1.size()){
            mergedArr.push_back(nums2[j]);
            j++;
        }
        else if(j == nums2.size()){
            mergedArr.push_back(nums1[i]);
            i++;
        }
        else{
            if(nums1[i] < nums2[j]){
                mergedArr.push_back(nums1[i]);
                i++;
            }
            else{
                mergedArr.push_back(nums2[j]);
                j++;
            }
        }
    }

    int mid = mergedArr.size()/2;
    if(mergedArr.size()%2==0){
        return ((double)(mergedArr[mid])+(double)(mergedArr[mid-1]))/2;
    }

    return mergedArr[mid];
}

int main(){
    std::vector<int> f = {1, 2};
    std::vector<int> s = {3, 4};

    std::cout << findMedianSortedArrays(f, s) << '\n';

    return 0;
}