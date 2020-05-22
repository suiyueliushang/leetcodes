/**马拉车算法，
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
	if(s.length==0)return ''
	var index=[];//以每个中心的最长回文半径
	var rightmost=0,rightmost_index=0;
	s=s.split('').join("#")
	index[0]=0
	for (var i=1;i<s.length;i++){
		if (i<rightmost && index[2*rightmost_index-i]+i<rightmost)
			index[i]=index[2*rightmost_index-i];
		else if (i<rightmost && index[2*rightmost_index-i]+i>=rightmost){
			var j=rightmost-i;
			while(i-j>=0&&i+j<s.length&&s[i+j]==s[i-j])j++;
			rightmost=i+j-1;
			rightmost_index=i;
			index[i]=j-1;
			}
		else if (i>=rightmost){
			var j=1;
			while (i-j>=0&&i+j<s.length&&s[i+j]==s[i-j])j++;
			rightmost=i+j-1;
			rightmost_index=i;
			index[i]=j-1
			}
	}
	var max=0,max_index=0;
	for (var i=0;i<index.length;i++){
		if (index[i]>max||(index[i]==max&& i%2==1)){
		max=index[i];
		max_index=i;
		}
	}
	if (max==0)return s[0];
	var res=[]
	for(var i=max_index-max;i<=max_index+max;i++){
		if(s[i]!="#")res.push(s[i]);
	}
	return res.join('')
};
console.log(longestPalindrome("ba"))
