#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	string name;
	int exam_scores[4];
	Student(string nam) {
		name = nam;
	}
	void get_minimum_final_score();
	void print_name_and_score();
	//TODO
};



void Student::get_minimum_final_score() {
	int val = 0;
	for (int i = 0; i < 3; i++) {
		val += exam_scores[i];
	}
	exam_scores[3] = 240 - val;
	if (exam_scores[3] < 0) {
		exam_scores[3] = 0;
	}

}

void Student::print_name_and_score() {
	cout << name << ' ' << exam_scores[3];

}



int main() {

	string student_name;
	cin >> student_name;
	Student student(student_name);
	for (int i = 0; i < 3; i++) {
		cin >> student.exam_scores[i];
		
	}
	student.get_minimum_final_score();
	student.print_name_and_score();
	return 0;
}