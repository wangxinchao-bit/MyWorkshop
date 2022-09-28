#include<iostream>
#include<stdlib.h>
#include<stack>
#include<math.h>
#include<cstdlib>
#include<vector>
#include<string>
#include <algorithm>

using  namespace std;

// 辗转相除法
int gcb(int a,int b){
    return b==0?a: gcb(b,a%b);
}

int xGCD (int a ,int b ,int & x,int &y){

    if(!b){
        x= 1,y=0;
        return a;
    }


    int x1,y1, gcb = xGCD(b,a%b,x1,y1);
    x = y1 ,y = x1 -(a/b)*y1;
     return gcb;
}

// 质数的计算
int countPrime(int n){

    if(n<=2) return 0;
    vector<bool> prime(n,true);

    int i =3,sqrtn = sqrt(n),count =n/2; //偶数一定不是质数
    while (i<=sqrtn)
    {
        for (int j =i*i;j<n;j+=2*i) //避免偶数和重复遍历
        {
            if(prime[j]){
                --count;
                prime[j] = false;
            }
        }
        do {
            i +=2;
        }while (i<=sqrtn && !prime[i]); //避免偶数和重复遍历
    }

    return count;
    
}

// 给定一个数字，求它在七进制下的表示
string coverttoBase7(int num){
    if(num ==0) return "0";
    bool is_negative = num <0;
    if(is_negative) num =- num;
    string ans;
    while (num ){
        int a = num /7,b = num %7;
        ans = to_string(b) +ans;
        num = a;

    }
    return is_negative? "-"+ans:ans;
}

// 输入一个非负整数，表示输入的阶乘结果有几个零

int trailingZeroes (int n){
    return n==0? 0:n/5+trailingZeroes(n/5);
}

// 字符串数字求和
/*
1、求取两个字符串的长度，然后将长的和短的进行固定
2、对两个字符串进行翻转操作，因为数学计算是从后面开始进行计算  
3、设置进位标志，从而对两个字符串的公共部分进行数值计算
4、对多余的数位和进位信息进行计算
*/


string addString(string num1,string num2){
    string output("");
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int len1 = num1.length();
    int len2 = num2.length();
    if(len1<=len2){
        swap(num1,num2);
        swap(len1,len2);
    }
    int addbit =0;
    for (int i =0; i<len2;++i){
        int cur_sum = (num1[i]-'0'+num2[i]-'0')+addbit;
        output += to_string(cur_sum%10);
        addbit = cur_sum<10?0:1;

    }

    for (int i = len2;i<len1;i++){
         int cur_sum = (num1[i]-'0')+addbit;
        output += to_string(cur_sum%10);
        addbit = cur_sum<10?0:1;
    }
    if(addbit) output+='1';
    reverse(output.begin(),output.end());
    return output;
}

/**
 * 给定一个数组，实现两个指令，一个进行shuffle操作，一个实现reset 操作，从而对数组进行洗牌和重新设置
 * 在这里我们采用经典的Fisher-Yales洗牌算法
 */

class Solution{
    vector <int> origin;
    public :
    Solution(vector<int> nums):origin(move(nums)){}
    vector<int> reset(){
        return origin;
    }

    vector<int> shuffle(){
        if(origin.empty()) return {};
        vector<int> shuffled(origin);

        int n = origin.size();
        //可以使用反向或者正向洗牌，效果相同
        // 反向洗牌
        for(int i = n-1;i>=0;--i){
            swap(shuffled[i],shuffled[rand()%(i+1)]);
        }

        return shuffled;
    }
};

/**
 * 设计一个算法，可以随机取到其中的一个数字
 * 不同于数组，在未遍历完链表之前，我们无法知道链表的总长度，这里我们就可以使用水库采样算法：
 * 遍历一次链表，在遍历到第m个节点的时候，有1/m的概率选择这个节点覆盖掉之前的节点选择。
 * 我们提供一个简单的对于水库算法随机性的证明。
 * 
*/
class Solution{
    ListNode *

};

int main(void ){

    int a =36,b = 24;
    cout << "a = "<<a<<" b ="<<b<<endl;
    cout <<gcb(a,b)<<endl;

    int x,y;

    xGCD(a,b,x,y);
    cout<<"x ="<<x << " y ="<<y<<endl;

    cout<< " less than "<<a<< " primes has "<<countPrime(a)<<endl;

    cout<<" 89 covert into Base7 is"<<coverttoBase7(7)<<endl;

    cout<<"  the number has   zeos in the tail  of  "<<trailingZeroes(50)<<endl;

    cout<<"string nums add and the result is  "<<addString("2324","454543");

    system ("pause");
    return 0;
}