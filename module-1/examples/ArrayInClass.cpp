#include <iostream>
#include <string>
using namespace std;

class student{
private:
	string name;
	int *exam_scores;
	int num_exams;
	
public:
	student(){};
	void inputStudent();
	void displayStudent() const;
	double classAverage()const;
	char letterGrade() const;
};


void student::inputStudent(){
	cout<<"Enter the name of the student>>>"<<endl;
	cin>>name;
	cout<<"Enter the number of exams student had taken>>>"<<endl;
	cin>>num_exams;
	exam_scores = new int[num_exams];
	for (int i=0; i<num_exams; i++){
		cout<<"Enter exam ["<<i+1<<"]'s score >>>";
		cin>>exam_scores[i];
	}
}
void student::displayStudent() const{
	cout<<"Name of the student>>>"<<name<<endl;
	cout<<"Number of exams student had taken>>>"<<num_exams<<endl;
	cout<<"Exams scores are as follows>>>"<<endl;
	for (int i=0; i<num_exams; i++){
		cout<<"Exam ["<<i+1<<"]'s score >>>";
		cout<<exam_scores[i]<<endl;
	}
	cout<<"The class average >>>"<<classAverage()<<endl;
	cout<<"The letter grade >>>"<<letterGrade()<<endl;
}

double student::classAverage()const{
	int sum=0;
	for (int i=0; i<num_exams; i++)
		sum +=exam_scores[i];

	double average = double(sum)/num_exams;
	return average;
}

char student::letterGrade() const{
	char grade;
	double classavg= classAverage();
	if (classavg >=90 && classavg <=100)
		grade = 'A';
	else if (classavg >=80 && classavg <90)
		grade = 'B';
	else if (classavg >=70 && classavg <80)
		grade = 'C';
	else if (classavg >=60 && classavg <70)
		grade = 'D';
	else if (classavg >=0 && classavg <60)
		grade = 'F';
	return grade;
}

int main(){
	student st1;
	st1.inputStudent();
	st1.displayStudent();
	return 0;
}
