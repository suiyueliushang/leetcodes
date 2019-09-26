# 6. Z 字形变换
>将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
```
L   C   I   R
E T O E S I I G
E   D   H   N
```
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
### 示例 1:

>输入: s = "LEETCODEISHIRING", numRows = >3
>输出: "LCIRETOESIIGEDHN"
>示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:
```
L     D     R
E   O E   I I
E C   I H   N
T     S     G
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion

## 解题思路：
>本题我主要想找规律，计算出z中每个元素在原来元素中的位置然后遍历原来的字符串就可以得到最终结果,这样做就不会占用太多空间，不用再开几个列表来存储每行的元素
#### 事件复杂度：O(n)
#### 空间复杂度：O(1)