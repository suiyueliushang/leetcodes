#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	int superEggDrop(int K, int N) {
		if(K==1||N<=2)
			return N;
		int ** drop=new int*[K];
		for(int i=0;i<K;i++)
			drop[i]=new int[N];
		for(int i=0;i<N;i++)
			drop[0][i]=i+1;
		for(int j=1;j<K;j++){
			drop[j][0]=1;
			drop[j][1]=2;
		}
		for(int i=1;i<K;i++) 
		{
			for(int j=2;j<N;j++)
			{
				int minist = max(drop[i - 1][0], drop[i][j - 2]),mid,left = 0, right = j - 2;
				while (left < right) {
					mid = (left + right) / 2;
					if (drop[i - 1][mid] <= drop[i][j - 2 - mid] && drop[i - 1][mid + 1] >= drop[i][j - 3 - mid])
					{
						minist = min(max(drop[i - 1][mid], drop[i][j - 2 - mid]), max(drop[i - 1][mid + 1], drop[i][j - 3 - mid]));
						break;
					}
					else if (drop[i - 1][mid] <= drop[i][j - 2 - mid] && drop[i - 1][mid + 1] <= drop[i][j - 3 - mid])
					{
						left = mid + 1;
					}
					else if (drop[i - 1][mid] >= drop[i][j - 2 - mid] && drop[i - 1][mid + 1] >= drop[i][j - 3 - mid]) {
						right = mid - 1;
					}
				}
				drop[i][j]=minist+1;
			}
		}
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < N; j++)
				cout << drop[i][j]<<' ';
			cout << endl;
		}
		int res=drop[K-1][N-1];
		for(int i=0;i<K;i++)
			delete []drop[i];
		delete []drop;
		return res;
	}

	/**
	 * 逆推法和动态规划
	 */
	int superEggDrop1(int K, int N) {
		int res,*dp=new int[K+1];
		for(int i=0;i<K+1;i++,dp[i]=0);
		for(res=0;dp[K]<N;++res)
			for(int i=K;i>0;i--)
				dp[i]+=1+dp[i-1];
		return res;
	}
};

int main(int argc,char** argv	){
	cout << argv[0] << endl;
	printf(argv[1]);
}