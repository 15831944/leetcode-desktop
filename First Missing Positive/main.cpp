#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {  
		//��ÿ��1��n�����ֱ�ŵ�a[0]��a[n-1]�У�������Χ������������������ҵ�һ�� a[i]��=i+1����i+1
        // Note: The Solution object is instantiated only once and is reused by each test case.  
        if(NULL==A || n<1)                                                                                                                                     
            return 1;  
        int pos=0;  
        while(pos<n)  
        {     
            if(A[pos]>0 && A[pos] != pos+1 && A[pos]-1<n && A[pos]!=A[A[pos]-1])  
            {                                                                                                                                                  
                swap(A[pos],A[A[pos]-1]);     
            }     
            else  
                ++pos;  
        }     
        for(int i=0;i<n;++i)  
        {     
            if(i+1 != A[i])  
                return i+1;                                                                                                                                    
        }     
        return n+1;  
    }  
     void swap(int &a,int &b)   
    {     
        int tmp = a;  
        a = b;  
        b= tmp;  
    }  
   
};

int main()
{

}