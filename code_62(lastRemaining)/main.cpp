class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        // 最后一轮剩下2个人，所以从2开始反推
        for (int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
    }
    //递归写法
    int lastRemaining(int n, int m){
        if(n==1)
            return 0;
        else
        {
            int x=lastRemaining(n-1,m);
            return (x+m)%n;
        }
        
    }
};