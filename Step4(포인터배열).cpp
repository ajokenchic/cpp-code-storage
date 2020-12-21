// #include "student1.h"
// #include <iostream>
// #include<time.h>
// #include<vector>
// using namespace std;

// int findMin(Student* s[], int subj)
// {
// 	int ret=0;
// 	for (int i = 1; i < 10; i++)
// 		if (s[ret]->getGrades(subj) > s[i]->getGrades(subj))	ret = i;
// 	return ret;
// }
// int findMax(Student* s[], int subj)
// {
// 	int ret = 0;
// 	for (int i = 1; i < 10; i++)
// 		if (s[ret]->getGrades(subj) < s[i]->getGrades(subj))	ret = i;
// 	return ret;
// }
// int main()
// {
// 	srand((unsigned int)time(NULL));
// 	Student* s[10] = { 0, };
// 	string  name[10] = { "�","�","�û�","�","�","�","�","�ֳ�","�","�" };
// 	for (int i = 0; i < 10; i++)
// 	{
// 		s[i] = new Student;
// 		s[i]->setName(name[i]);
// 		s[i]->initStudent();
// 	}
// 	//int sub = GEO;//�ȸ� �ϴ� � �.
// 	for (int i = 0; i < 5; i++)
// 	{
// 		int t = findMin(s, i);
// 		printf("[%s] � �л� \n", subjTitles[i].c_str());
// 		s[t]->show();
// 		cout << "�: [ " << s[t]->getAvg() << " ] �\n" << endl;
// 		t = findMax(s, i);
// 		printf("[%s] �ְ� �л� \n", subjTitles[i].c_str());
// 		s[t]->show();
// 		cout << "�: [ " << s[t]->getAvg() << " ] �\n" << endl;
// 	}
// 	for (auto t:s)	delete t;
// }