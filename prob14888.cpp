#include <iostream>

using namespace std;

typedef struct Data {
	int priority;
	string value;

}Data;


Data data_[] = { 3,"Python", 5,"Ada", 9,"Basic", 8,"C++", 1,"Java",6,"C#", 2,"C", 7,"Pascal", 4,"Ruby" };




int main() {
	cout << data_[0].priority << " " << data_[0].value;


}