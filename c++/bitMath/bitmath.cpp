#include<iostream>
#include<stdlib.h>
#include<stack>
#include<math.h>
#include<cstdlib>
#include<vector>
#include<string>
#include <algorithm>
#include <unordered_map>


// vector 的长度是size 
// string 等长度是通过 length 和size进行获取的

using  namespace std;
/*
    位异或           相同则1，不同则0
    按位与           全1则1，有0则0
    按位或           有1则1，无1则0 
    取反             1、0 互变
    算书左移和算术右移 左移*2  右移/2

    特性：

        x^0 = x  x&0 = 0   x|0 = x
        x^1 = ~x x&1 = x   x|1 = 1
        x^x = 0  x&x = x   x|x = x

    若n&1 =0,则二进制最右一位为 0
    若n&1 =1,则二进制最右一位为 1

        n-1: 无论是借位，还是减1，遇到1 就停止
             从低位到高位，一直到1,一位都发生了反转
        
        n   1101 100 100
        n-1 1101 100 011

        n&(n-1)     二进制数字 nn 最右边的 11 变成 00 ，其余不变
        n&(-n)      可以得到n的位级 表示中最低的那一位

        x &1 从而求取最后一位的数据信息
        x >>= 1 右移从而不断除以2操作 



        逐位遍历一个十进制数据的二进制位数采用
        
        // 在这里完整的求出了32数据的信息

        for(int i=0;i<32;i++){
            int tail = num &1;
            num >>=1;
        }

        // 这个中没有求取32位，只要遇到数字变成0 然后就停止
       while (n !=0)
       {
            int tail = n&1;
            cout<<"  "<<tail<<" ";
            n >>= 1;
            output +=to_string(tail);
       }

    // n &= n-1    


    //  一个数是2的次方 那么他的形式是10，100，1000，10000，100000，...形式
    //  那么 n-1的形式是 01,011,0111,0111 d的格式，那么 n& n-1 = 0，则

    // https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/solution/mian-shi-ti-15-er-jin-zhi-zhong-1de-ge-shu-wei-yun/

       初始化统计变量res
       循环消去最右边的1 当n =0时跳出来
            1、res += 1:统计变量+1
            2、n&= n-1: 消去数字右边的1
    
    如果 n&(n-1) = 0 那么这个数必定是2的次方形式
*/

// 给定两个十进制数字，求他们的二进制表示的汉明码
int hammingDistance(int num1,int num2){
    int diff = num1^num2,ans = 0;
    while (diff)
    {
        ans += diff&1;
        diff >>= 1;
    }
    return ans;
    
}
// 给定一个十进制正整数，输出他在二进制下的翻转结果

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;

    for (int i =0;i<32;i++)
    {
        int tail = n&1;
        n >>= 1;
        ans <<= 1;
        ans += tail;
    }
    return ans;
}

uint32_t bitMath(uint32_t n) {
    uint32_t ans = 0;
    string output("");
    while (n!=0)
    {
        int tail = n&1;
        cout<<"  "<<tail<<" ";

        n >>= 1;
        output +=to_string(tail);
    }
    cout<<endl;
    reverse(output.begin(), output.end());
    cout<< "the result is "<<output<<endl;

    return ans;
}

// 求取一个数组中只出现一次的数据信息
int singleNumber(vector<int>&nums){

    int ans =0;
    for(const int &num:nums){
        ans ^=num;
    }
    return ans;

}

// 二进制的特性
// 长度位n的数组，然后1 表示选取该数字，0表示不选取数据信息
// 从而可以获取一个2^n 个子集
// 给定一个整数，判断是不是4的次方
bool isPowerOfFour(int n) {
    return  n > 0 && !(n & (n - 1)) && (n & 1431655765);
}

// 给定一个字符串数组，求出任意两个没有重复数组的字符串上长度乘积的最大值
// 我们可以为每个字符串建立一个长度为26的二进制数字，表示是否存在重复数字，那么他们的二进制表示按位与 则不为0 
// 只要有相同的那么，两个数组然后按位与的结果就不会等于 0 

// 建立一个哈希表来存储字母串（在数组的位置）到二进制数字的映射关系，方便查找调用
int maxProduct(vector<string>& words){
    /*
        哈希表的使用方式
        #include<unordered_map>
    */
//     unordered_map<int,int> hash;
//     int ans =0 ;
//     for (const string & word:words){
//         int mask =0, size = word.size();
//         for(const char &c :word)
//         {
//             mask |= 1<< (c -'a');
//         }
//         hash[mask] = max(hash[mask],size);
//         for (const auto & [h_mask, h_len]: hash) {
//         if (!(mask & h_mask)) {
//         ans = max(ans, size * h_len);
// }
// }
//     }
    return 0;
}

int missingNumber(vector<int>&nums){
    // int sum =0 ,len = nums.size();
    // for(const int num:nums)
    // {
    //     sum += num;
    // }
    // return  (len+1)*(len)/2 -sum;


    // 索引和数组数值之间的关系
    int ans =0;
    int len = nums.size();
    for(int i =0;i<len;i++){
        ans ^= i;
        ans ^= nums[i];
    }
    ans ^=len;
    return ans;
}






// This is the main function.

int main(void){

    int x = 78,y = 56;
    cout<<"the num of  x = "<<x<<"and the number of y = "<<
    y <<" 's distance is : "<<hammingDistance(x,y)<<endl;

    cout<<" the reverse is "<<bitMath(43261596)<<endl;

    // vector<int>nums;

    // nums.push_back(3);
    // nums.push_back(0);
    // nums.push_back(1);



    // 数组和vector之间的转换问题
    int arr[10]= {9,6,4,2,3,5,7,0,1,8};
    vector < int > nums(arr, arr+10);

    cout<<"the array of num is "<<singleNumber(nums)<<endl;

    cout<<" the missing num is "<< missingNumber(nums)<<endl;


    system("pause");
    return 0;
}