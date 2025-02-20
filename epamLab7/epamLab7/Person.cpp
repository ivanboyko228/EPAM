#include "Person.h"
Person::Person() {
	this->day_of_birth = 1;
	this->gender = "N/A";
	this->month_of_birth = 1;
	this->name = "N/A";
	this->patronymic = "N/A";
	this->surname = "N/A";
	this->year_of_birth = 1970;
}
Person::Person(std::string name, std::string surname, std::string patronymic) {
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
	this->day_of_birth = 1;
	this->month_of_birth = 1;
	this->year_of_birth = 1970;
}
void Person::GetValidDate(STD string& obj) {
	int counter{ 0 };
	unsigned SWT{ 0 };
	STD string intermediate;
	while (counter<obj.size()) {
		if (obj.size() > 10) {
			return;
		}
		else {
			if (isalnum(obj[counter]) || obj[counter] != 46) {
				while (obj[counter] != '.' && counter < obj.size()) {
					intermediate.push_back(obj[counter]);
					counter++;
				}
				//day->month->year
				switch (SWT){
				case 0: {
					this->day_of_birth = (stoi(intermediate));
					SWT++;
					break;
				}
				case 1: {
					this->month_of_birth = stoi(intermediate);
					SWT++;
					break;
				}
				case 2: {
					this->year_of_birth = stoi(intermediate);
					break;
				}
				}
			}
			intermediate.clear();
		}
		counter++;
	}
}
void Person::GetValidString(std::string &obj) { // is_alpha check
	for (int i{ 0 }; i < obj.size(); i++) {
		if (isalpha(obj[i])) {}
		else {
			obj.erase(i, 1);
			i--;
		}
	}
}
void Person::Show()const  {
	STD cout << "\nThe name is " << this->name << " " << this->surname << " " << this->patronymic << STD endl;
	STD cout << "Gender is " << this->gender << ". Date of birth is " << this->day_of_birth << "." << this->month_of_birth << "." << this->year_of_birth << STD endl;
}
void OutOf(std::ifstream& out, std::vector<Person>& obj) { // what if obj is empty?
	unsigned counter{ 0 };
	STD string intermediate;
	while (!out.eof()) {
		if (counter == obj.size() ) {
			obj.resize(counter + 1);
		}
		_GET
			if (intermediate[0] == '�') { // position string
				_GET
					obj[counter].GetValidString(intermediate);
				obj[counter].SetN(intermediate);
				_GET
					obj[counter].GetValidString(intermediate);
				obj[counter].SetS(intermediate);
				_GET
					obj[counter].GetValidString(intermediate);
				obj[counter].SetP(intermediate);
				_GET
					obj[counter].GetValidString(intermediate);
				obj[counter].SetG(intermediate);
				_GET
					obj[counter].GetValidDate(intermediate);
			}
			else
		counter++;
		counter++;
	}
}
void Person::SetN(STD string&obj) {
	this->name = obj;
}
void Person::SetS(STD string&obj) {
	this->surname = obj;
}
void Person::SetP(STD string&obj) {
	this->patronymic = obj;
}
void Person::SetG(STD string&obj) {
	this->gender = obj;
}
void SortSurname(STD vector<Person>&obj) {
	sort(obj.begin(), obj.end(), [](Person a, Person b) {return a.surname < b.surname; });
}
void Menu(int& choice,STD vector<Person>&obj) {	
	switch (choice) {
	case 2: {
		for (int i{ 0 }; i < obj.size(); i++) {
			obj[i].Show();
		}
		break;
	}
	case 3: {
		SortSurname(obj);
		break;
	}
	case 4: {
		int month{ 0 };
		STD cout << "\nEnter your month: "; STD cin >> month;
		assert(month > 0 && month < 13);
		STD find_if(obj.begin(), obj.end(), [=]( Person a) {
			if (a.month_of_birth == month) {
				a.Show();
				return false;
			}
			else
				return false;
			});
		break;
	}
	case 5: { //copy that and use sort
		Person intermediate;
		for (int i{ 0 }; i < obj.size(); i++) {
			if (obj[i].year_of_birth < intermediate.year_of_birth && obj[i].GetGender() == "male") {
				intermediate = obj[i];
			}
		}
		intermediate.Show();
		break;
	}
	case 6: {
		char symbol{ 'k' };
		STD cout << "\nEnter your month: "; symbol = _getche();
		assert(isalpha(symbol));
		STD find_if(obj.begin(), obj.end(), [=](Person a) {
			if (a.surname[0] == symbol ) {
				a.Show();
				return false;
			}
			else
				return false;
			});
		break;
	}
	
	case 8: { // first task
		STD vector<int >nums = { 5,3,9,10,20,32,44,7,0 };
		STD cout << STD count_if(nums.begin(), nums.end(), Pred()) << STD endl;
		break;
	} 
	case 9: { // second task
		STD vector<double>cs = { 30,40,50,60,70,80,95 };
		STD for_each(cs.begin(), cs.end(), CtoK);
		STD for_each(cs.begin(), cs.end(), [](double a) {STD cout << a << " "; });
		STD vector<double>cs1 = { 30,40,50,60,70,80,95,54 };
		STD cout << STD endl;
		STD for_each(cs1.begin(), cs1.end(), [](double& a) {a = a * 1.8 - 32;  });
		STD for_each(cs1.begin(), cs1.end(), [](double a) {STD cout << a << " "; });
		break;
	}
	case 10: { // third task
		STD vector<int>my = { 1,2,4,5,6,7,8,22,5,6,35345,453,5,511,9,10 };
		STD cout << STD endl;
		STD cout << my.end() - my.begin();
		STD cout << STD endl;
		STD vector<int>::iterator iter = my.begin();
		for (; iter != my.end(); ++iter) {
			STD cout << *iter << " ";
		}
		STD cout << STD endl;
		iter = my.begin();
		for (int i{ 0 }; i < my.size(); i++) {
			STD cout << iter[i] << " ";
		}
		iter = my.begin();
		STD cout << STD endl;
		while (iter < my.end()) {
			STD cout << *iter << " ";
			iter += 2;
		}
		STD cout << STD endl;
		break;
	}
	case EXIT: {
		break;
	}
	default: {
		break;
	}
	}
}
STD string Person::GetGender() {
	return this->gender;
}
void CtoK(double& obj) {
	obj = obj * 1.8 - 32;
}
Person& Person::operator=(const Person&obj) {
	this->day_of_birth = obj.day_of_birth;
	this->month_of_birth = obj.month_of_birth;
	this->year_of_birth = obj.year_of_birth;
	this->name = obj.name;
	this->surname = obj.surname;
	this->patronymic = obj.patronymic;
	this->gender = obj.gender;
	return *this;
}