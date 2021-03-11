 #include<iostream>
#include<vector>
using namespace std;
void testNULL() {
	int* p = 0;
	p += 2;
	cout << p;
}
int test()
{
	int i, a[5];
	cout << "i: " << &i << endl;
	cout << "a[5]:  " << &a[5] << endl;
	for (i = 0; i <= 30; i++)
	{
		a[i] = 0;
		printf("%d:hello\n", i);
	}
	printf("%d:hello world", i);
	return 0;
}
int main()
{
 //   const char* s = "abcdefg";
 //   s += 2;
	///*fprintf(stderr, "%s\n", s);*/
 //   cout << *s;
 //   return 0;
	test();
}

