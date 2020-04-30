/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
	num=["","",["a","b","c"],["d","e","f"],["g","h","i"],["j","k","l"],["m","n","o"],["p","q","r","s"],["t","u","v"],["w","x","y","z"]];
	res=[]
	for(var i=0; i<digits.length;i++){
		if (i==0){
			res=num[digits[Number(i)]];
			continue;
		}
		var temp=res;
		res=[]
		for(j in temp){
			for(k in num[digits[Number(i)]])
				res.push(temp[j]+num[digits[Number(i)]][k]);
		}
	}
	return res;
};
letterCombinations("23")