// #include<iostream>
// using namespace std;

// #define KOR 0
// #define ENG 1
// #define MATH 2
// #define SCI 3
// #define  GEO 4
// #define CNT 5

// string subjTitles[CNT] = { "�","�","�","�","�" };
// class Student
// {
// private:
// 	string name;
// 	int grades[CNT];
// public:
// 	Student(string _name="") { name = _name;	memset(grades, 0, sizeof(int) * 3); };
// 	~Student() { };
// 	void initStudent() {for (int i = 0; i < CNT; i++){	grades[i] = rand() % 101;}}
// 	void setName(string _name)	{name = _name;}
// 	string getName() { return name; }
// 	int getGrades(int i){	return grades[i];}
// 	float getAvg() 
// 	{
// 		int sum=0;
// 		for (int i = 0; i < CNT; i++)	sum += grades[i];
// 		return sum / CNT;
// 	}
// 	void show()
// 	{
// 		cout << "--------------------" << endl;
// 		cout << "�̸�: " << name << endl;
// 		for (int i = 0; i < CNT; i++)	cout << subjTitles[i]<<": " << grades[i] <<" �"<< endl;
// 		cout << "--------------------" << endl;
// 	}
// };

