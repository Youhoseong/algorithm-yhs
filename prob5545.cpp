using namespace std;

#include <iostream>
#include <algorithm>
int N_toping;
int price_dow;
int price_toping;
int calory_dow;
int calory_toping[100];


int main() {
	cin >> N_toping;

	cin >> price_dow;
	cin >> price_toping;

	cin >> calory_dow;

	for (int i = 0; i < N_toping; i++)
		cin >> calory_toping[i];

	sort(calory_toping, calory_toping + N_toping);
	
	int price = price_dow;
	int calory = calory_dow;
	int index = N_toping - 1;

	while (1) {

		if (calory / price > (calory + calory_toping[index]) /( price + price_toping)) {
			break;
		}
		else {
			calory += calory_toping[index--];
			price += price_toping;
		}

	}

	cout << calory / price << endl;


	return 0;
}