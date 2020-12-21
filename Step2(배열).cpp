// #include "student1.h"
// #include <iostream>
// #include<time.h>

// using namespace std;

// int findMax(Student s[], int subj)
// {
// 	int ret=0;
// 		for (int i = 1; i < 10; i++)
// 			if (s[ret].getGrades(subj) <s[i].getGrades(subj)) ret = i;
// 	return ret;
// }
// int findMin(Student s[], int subj)
// {
// 	int ret=0;
// 	for (int i = 1; i < 10; i++)
// 		if (s[ret].getGrades(subj) > s[i].getGrades(subj)) ret = i;
// 	return ret;
// }
// int main()
// {
// 	srand((unsigned int)time(NULL));
// 	Student s[10];
// 	string  name[10] = { "�","�","�û�","�","�","�","�","�ֳ�","�","�" };
// 	for (int i = 0; i < 10; i++)
// 	{
// 		s[i].setName(name[i]);
// 		s[i].initStudent();
// 	}
// 	int t = findMin(s, SCI);
// 	printf("� � �л�: \n");
// 	s[t].show();
// 	cout << "�: " << s[t].getAvg() << " �\n" << endl;
// 	t = findMax(s, SCI);
// 	printf("� �ְ� �л�: \n");
// 	s[t].show();
// 	cout << "�: " << s[t].getAvg() << " �\n" << endl;
// }