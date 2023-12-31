#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include<string>
#include<map>
using namespace std;


// [프로그램 환경] Release, x64, 프로젝트 속성 C++ 언어: 미리 보기 - 최신 C++ 초안의 기능(/std:c++latest)

//---------
int main()
//---------
{
	// 파일 "시험1.dat"와 "시험2.dat"에 몇 개인지 모르는 int를 저장하였다. 
	// int 값은 operator<<를 사용하여 text 모드로 기록하였다.
	// (예)	int n = 123;
	//	    out << n << " ";

	ifstream in1{ "시험1.dat" };
	ifstream in2{ "시험2.dat" };

	vector<int> v1;			// "시험1.dat"를 여기에 저장한다
	vector<int> v2;			// "시험2.dat"를 여기에 저장한다


	// [문제 1] "시험1.dat"와 "시험2.dat"를 읽어 v1과 v2에 저장하고, v1과 v2의 size()를 화면에 출력하라.
	// 답지에는 v1에 저장하는 코드만 적고 화면에 출력된 size()값을 적으면 된다.		(15, 5)
	// (주의) v1과 v2는 이미 생성되어있다.
	
	int num{};
	while (in1>>num)
		v1.push_back(num);
	while (in2 >> num)
		v2.push_back(num);

	cout << "v1 size : " << v1.size() << endl;//10220610
	cout << "v2 size : " << v2.size() << endl;//10220615

	//40882440
	cout << "v1 byte : " << v1.size() * sizeof(int) << endl;
	//40882460
	cout << "v2 byte : " << v2.size() * sizeof(int) << endl;


	// [문제 2]	v1에 저장된 원소들을 홀수와 짝수로 분리한 후 각각 몇 개인지 출력하라.	
	// 출력한 홀수의 개수와 짝수의 개수도 답안지에 써라.							(15, 5)

	vector<int> fir, sec;

	partition_copy(v1.begin(), v1.end(), back_inserter(fir), back_inserter(sec), [](int& n) {return n % 2; });

	cout << "홀수 : " << fir.size() << endl;//5111014
	cout << "짝수 : " << sec.size() << endl;//5109596


	// [문제 3] v1과 v2의 공통 원소를 찾아 v3에 저장하라.		
	// v3에 저장된 원소개수를 출력하고 답지에도 적어라.								(25, 5)
	// (참고) 공통 원소는 set_intersection으로 찾을 수 있다.
	// 같은 값을 갖는 원소가 여러 개 있을 경우는 set_intersection의 처리방법을 따른다.

	vector<int> v3;		// v1과 v2의 공통 원소를 여기에 저장한다.

	ranges::sort(v1);
	ranges::sort(v2);

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),back_inserter(v3));

	cout << "v3 size : " << v3.size() << endl;

	// [문제 4] v3에 저장된 int를 화면에 출력하면 값이 나온다.
	// int 값은 [0,9] 숫자로 표현된다.
	// v3에 저장된 모든 int를 숫자로 나타낼때 각 숫자의 갯수를 화면에 출력하라.
	// '9'의 갯수는 답지에도 써라.													(35, 5)
	// (도움) to_string()으로 int를 string으로 변환할 수 있다.	
	// (예) 1231511   31233122 
	// 위 두 int에서 
	// [1] - 6
	// [2] - 4
	// [3] - 4
	// [4] - 0
	// [5] - 1
	// 이하 생략

	////[0] - 91447
	////[1] - 104838
	////[2] - 104970
	////[3] - 104585
	////[4] - 104362
	////[5] - 104030
	////[6] - 104415
	////[7] - 105005
	////[8] - 104767
	////[9] - 104520

	map<char, int> m;

	for (const auto t : v3)
	{
		auto i = to_string(t);
		
		for (const auto t2 : i)
			++m[t2];
	}

	for (const auto t : m)
		cout << "[" << t.first << "] - " << t.second << endl;
}