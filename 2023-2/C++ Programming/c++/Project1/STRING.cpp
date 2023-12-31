//---------------------------------------------------------------------------------
//STRING.cpp
// 
// 2023.11.09 파일분리함
//---------------------------------------------------------------------------------
#include<iostream>
#include "STRING.h"


bool STRING::관찰{ false };//관찰하려면 아무데서나 true로 바꿔주세요

STRING::STRING(const char* s)
	:num{ strlen(s) }
{
	p = new char[num];
	memcpy(p, s, num);

	if(관찰)
		std::cout << "생성자(const char*) - " << num << ", 메모리: " << (void*)p << std::endl;
}

STRING::~STRING() 
{
	
	if(관찰)
		std::cout << "소멸자 - " << num << " , 메모리: " << (void*)p << std::endl;
	delete[] p;
}

//2023. 11. 09 복사 생성자(스페셜 함수)
STRING::STRING(const STRING& other) :num{ other.num } {
	p = new char[num];
	//deep-copy
	memcpy(p, other.p, num);//DMA

	if(관찰)
		std::cout << "복사 생성자 - " << num << ", 메모리: " << (void*)p << std::endl;
}
//2023. 11. 09 복사 생성자를 만들었다면 이와 짝이 되는 copy assignment operator를 
//반드시 코딩해야 한다.
STRING& STRING::operator=(const STRING& other) 
{
	//가장 먼저 할 일은 자기 자신을 할당하지 않도록 해야 한다.
	if (this == &other)
		return *this;

	delete[] p;

	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);

	if(관찰)
		std::cout << "copy assignment 연산자 - " << num << ", 메모리: " << (void*)p << std::endl;

	return *this;
}

STRING::STRING(STRING&& other) 
	:num{other.num},p{other.p}
{//const를 붙일 수 없어요. 데이터를 뺏길텐데
	//other를 초기화한다.
	other.num = 0;
	other.p = nullptr;
}

//2023. 11. 15 연산자 오버로딩
STRING STRING::operator+(const char* str)const
{
	STRING temp;//default ctor는 스페셜 함수, 디폴트 생성자를 정의해서 빨간 줄을 사라지게 했다.

	temp.num = num + strlen(str);
	temp.p=new char[temp.num];

	memcpy(temp.p, p, num);
	memcpy(temp.p + num, str, strlen(str));

	return temp;//여기서 복사 생성자가 호출되어야 하지만 RVO가 작동된다.
	//RVO(Return Value Optimization) - 반환값 최적화
}
STRING STRING::operator+(const STRING& s)const
{
	STRING temp;//default ctor는 스페셜 함수, 디폴트 생성자를 정의해서 빨간 줄을 사라지게 했다.

	temp.num = num + s.num;
	temp.p = new char[temp.num];

	memcpy(temp.p, p, num);
	memcpy(temp.p + num, s.p, s.num);

	return temp;//여기서 복사 생성자가 호출되어야 하지만 RVO가 작동된다.
	//RVO(Return Value Optimization) - 반환값 최적화
}

//2023.11.16 free function
STRING operator+(const char* p, const STRING& s)
{
	STRING temp;
	temp.num = strlen(p) + s.num;
	temp.p=new char[temp.num];

	memcpy(temp.p, p, strlen(p));
	memcpy(temp.p + strlen(p), s.p, s.num);

	return temp;
}

//2023.11.16
char STRING::operator[](int idx)const
{
	return p[idx];
}

char& STRING::operator[](int idx)
{
	return p[idx];
}


size_t STRING::size() const 
{
	return num;
}

void STRING::show() const 
{
	for (int i{}; i < num; ++i)
		std::cout << p[i];
	std::cout << std::endl;
}

//2023.11.16
std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i{}; i < s.num; ++i)
		os << s.p[i];
	return os;
}


