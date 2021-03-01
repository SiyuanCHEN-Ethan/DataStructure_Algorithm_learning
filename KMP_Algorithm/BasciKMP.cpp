//..和大话数据结构中不同的是 C++ 的string 首位不放置字符串长度。

#include<iostream>
#include<string>
using namespace std;

//计算T的Next数组
int* get_next(string T)
{
	int* next = new int[T.length()];
	next[0] = -1;

	int	i = 0;
	int j = -1;

	while (i < (int)T.length() - 1)
	{
		if (j == -1 || T[j] == T[i])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}


	}
	return next;
	
}

//KMP算法主体
int KMP(string T, string P) //T是模式串，P是主串
{
	int* nextT = get_next(T);
	int posP = 0;
	int posT = 0;
	while (posP < (int)P.length() && posT< (int)T.length())
	{
		if (posT == -1 || T[posT] == P[posP])
		{
			posP++;
			posT++;
		}
		else
		{
			posT = nextT[posT];
		}
		

	}
	if (posT == T.length())
		return posP - T.length();
	else
		return -1;
}

void test01()
{
	string T = "bbcd";
	string P = "abbcd";
	int temp = KMP(T, P);
	cout << temp << endl;
}

void test02()
{
	string T = "bbcd";
	string P = "aabbcd";
	int temp = KMP(T, P);
	cout << temp << endl;
}

//验证get_next 函数正确性
void testNext()
{
	string testS = "aabbcd";
	int* next = get_next(testS);
	cout << next[2] << " " << next[3] << endl;
}

int main()
{
	test02();
	return 0;
}