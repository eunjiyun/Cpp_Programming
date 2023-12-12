//---------------------------------------------------------------------------------
//STRING.h
// 
// 2023.11.09 ���Ϻи���
//---------------------------------------------------------------------------------

#pragma once

class STRING {
	size_t num{};//��� �޸� ��Ʈ�� 0����
	char* p{};//nullptr�� �Ǿ� �ִ�.

public:
	//2023. 11. 15 ���ڸ� �޴� �����ڸ� �ϳ��� �ڵ��ߴٸ� �ݵ�� ����Ʈ�����ڸ� �ڵ�
	STRING() = default;
	STRING(const char* s);
	~STRING();

	//2023. 11. 09 ���� ������(����� �Լ�)
	STRING(const STRING& other);

	//2023. 11. 09 ���� �����ڸ� ������ٸ� �̿� ¦�� �Ǵ� copy assignment operator�� 
	//�ݵ�� �ڵ��ؾ� �Ѵ�.
	STRING& operator=(const STRING& other);

	//2023.11.09 �̵��� �̵��Ҵ�
	STRING(STRING&&);//const�� ���� �� �����. �����͸� �����ٵ�

	//2023. 11. 15 ������ �����ε�
	STRING operator+(const char*)const;
	STRING operator+(const STRING&)const;

	//2023.11.16 free function
	friend STRING operator+(const char*, const STRING&);
	
	//2023.11.16
	char operator[](int idx)const;//�б� ���� [], ���Ʒ��� ���� �ٸ� �Լ� �����ε��� ������������.
	char& operator[](int idx);//���� ����

	size_t size() const;

	void show() const;

	//����� �Լ��� �ʿ��Ҷ� �����Ѵ�.
	static bool ����;


	//2023.11.16 ����� ����� �� Ŭ������ ������ ����̴�
	//�׷��� operator<< �Լ��� STRING�� ����� ��ġ �� �Լ��� ����Լ��ΰ� ó�� �����Ӱ�
	//�����ϵ��� �ڵ��ϴ� ���� �ո����̴�. -> �� �Լ��� friend�� �����Ѵ�
	friend std::ostream& operator<<(std::ostream&, const STRING&);
};
