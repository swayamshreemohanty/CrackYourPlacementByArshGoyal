// 287. Find the Duplicate Number

#include "iostream"
using namespace std;

class Sorting
{

private:

    void swapInArray(int nums[],int startIndex,int endIndex){
        int temp=nums[startIndex];
        nums[startIndex]=nums[endIndex];
        nums[endIndex]=temp;
        return;
    }

public:


    void bubbleSort(int nums[],int arraySize){
        for (int i = 0; i < arraySize; i++)
        {
            for (int j = arraySize-1; j > i; j--)
            {
                if (nums[j]<nums[j-1])
                {
                    swapInArray(nums,j,j-1);
                }
                
            }
            
        }
        
    };

    void insertionSort(int nums[],int arraySize){
        for (int i = 1; i < arraySize; i++)
        {
            if (nums[i]<nums[i-1])
            {
                int temp=nums[i];
                int j = i-1;
                for (j; j >=0 && nums[j]>temp; j--)
                {
                    nums[j+1]=nums[j];
                }
                nums[j+1]=temp;
            }
        }
        
    };

    void selectionSort(int nums[],int arraySize){
    for (int i = 0; i < arraySize; i++)
    {
        int minIndex=i;
        for (int j = i+1; j< arraySize;j++)
        {
            if (nums[j]<nums[minIndex])
            {
                minIndex=j;
            }
        }
        if (minIndex!=i)
        {
            swapInArray(nums,i,minIndex);
        }
        
    }
        
    };
};



class Solution {
public:
    int findDuplicate(int nums[],int arraySize) {
        Sorting().insertionSort(nums,arraySize);
        for (int i = 0; i < arraySize; i++) {
            if (nums[i] == nums[i-1])
            {
                // cout<<nums[i]<<" ";
                return nums[i]; //return the 1st repeat number.
            }
        }
        return -1;
    }
};

int main(){
    int nums[]={3,1,3,4,2};
    int arraySize= sizeof(nums)/sizeof(nums[0]);
    cout<<Solution().findDuplicate(nums,arraySize);;
    return 0;
}