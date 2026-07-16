/*
Description:

You are given an integer array nums of length n.
Construct an array prefixGcd where for each index i:
Let mxi = max(nums[0], nums[1], ..., nums[i]).
prefixGcd[i] = gcd(nums[i], mxi).
After constructing prefixGcd:
Sort prefixGcd in non-decreasing order.
Form pairs by taking the smallest unpaired element and the largest unpaired element.
Repeat this process until no more pairs can be formed.
For each formed pair, compute the gcd of the two elements.
If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
Return an integer denoting the sum of the GCD values of all formed pairs.
The term gcd(a, b) denotes the greatest common divisor of a and b.
 
Example 1:
Input: nums = [2,6,4]
Output: 2
Explanation:
Construct prefixGcd:
i	nums[i]	mxi	prefixGcd[i]
0	2	2	2
1	6	6	6
2	4	6	2
prefixGcd = [2, 6, 2]. After sorting, it forms [2, 2, 6].
Pair the smallest and largest elements: gcd(2, 6) = 2. The remaining middle element 2 is ignored. Thus, the sum is 2.
  
Example 2:
Input: nums = [3,6,2,8]
Output: 5
Explanation:
Construct prefixGcd:
i	nums[i]	mxi	prefixGcd[i]
0	3	3	3
1	6	6	6
2	2	6	2
3	8	8	8
prefixGcd = [3, 6, 2, 8]. After sorting, it forms [2, 3, 6, 8].
Form pairs: gcd(2, 8) = 2 and gcd(3, 6) = 3. Thus, the sum is 2 + 3 = 5.
*/

//Solution:

int cmp(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
}

int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

long long gcdSum(int* nums, int numsSize) {
    
    int max[numsSize];
    max[0]=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]>max[i-1])
            max[i]=nums[i];
        else
            max[i]=max[i-1];
    }

    int pgcd[numsSize];
    for(int i=0;i<numsSize;i++)
        pgcd[i]=gcd(nums[i],max[i]);

    qsort(pgcd,numsSize,sizeof(int),cmp);

    int l=0,r=numsSize-1;
    long long sum=0;
    while(l<r)
    {
        sum+=gcd(pgcd[l],pgcd[r]);
        l++;
        r--;
    }
    return sum;
}
