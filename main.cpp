/* Калинина Анастасия М8О-208Б

Вариант №10
Создать класс Angle для работы с углами на плоскости, задаваемыми величиной в градусах и минутах.
Обязательно должны быть реализованы: перевод в радианы, приведение к диапазону 0 - 360, сложение и вычитание углов,
деление углов, получение значений тригонометрических функций, сравнение углов. Операции сложения, вычитания, деления, сравнения
(на равенство, больше и меньше) должны быть выполнены в виде перегрузки операторов. 
Необходимо реализовать пользовательский литерал для работы с константами типа Angle.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#define _USE_MATH_DEFINES
#define ERROR 404
using namespace std;

class Angle{
private:
	int degrees;
	int minutes;

public:
	Angle (): degrees(0), minutes(0) {}   // конструктор по умолчанию

	Angle (int degrees, int minutes){
		this->degrees = degrees;
		this->minutes = minutes;
	}

	void setAngle() {
        cout << "Введите значение угла в градусах и минутах через пробел: ";
        cin >> degrees;
        cin >> minutes;
		this->degrees = degrees;
        this->minutes = minutes;
    }

    int getDegrees(){		// получение значения градусов
    	return degrees;
    }

    int getMinutes(){		// получения значения минут
    	return minutes;
    }
	 
	double radians(){ 		// перевод в радианы
		if(minutes > 60){
			degrees += minutes / 60;
			minutes %= 60;
			double rad = (degrees + minutes / 60.) * M_PI / 180;
			return rad;
		}
		double rad = (degrees + minutes / 60.) * M_PI / 180;
		return rad;
	}

	void standart(){
		if(minutes > 60){
			degrees += minutes / 60;
			minutes %= 60;
		}
		if (minutes < 0){
			if(abs(minutes) < 60){
				--degrees;
				minutes += 60;
				return;
			}
			int k = minutes / (-60);
			minutes +=  60;
			degrees -= k;
		}
	}

	void classic(){		// приведение к диапазону 0 - 360 градусов
		if(minutes > 60){
			degrees += minutes / 60;
			minutes %= 60;
		}
		if(abs(degrees) > 360 && degrees< 0){
			int d = degrees % (-360);
			if(d == 0){
			cout << "Угол в диапазоне 0 - 360:  " << d << "градуса(ов)" << endl;
			}
			else {
				d += 360;
				cout << "Угол в диапазоне 0 - 360: " << d  << "градуса(ов)"<< endl;
			}
			return;
		}
		if(degrees > 360){
			cout << "Угол в диапазоне 0 - 360: " << degrees % 360  << "градуса(ов)"<< endl;
		}
		if (degrees < 0){
			cout << "Угол в диапазоне 0 - 360: " << degrees + 360  << "градуса(ов)"<< endl;
		}

		if(degrees >= 0 && degrees < 360){
			cout << "Угол находится в заданном диапазоне!" << endl;
		}
	}

	Angle& operator=(const Angle& second) {
        degrees = second.degrees;
        minutes = second.minutes;
        return *this;
    }

	Angle operator+(const Angle& second){
		return Angle(degrees + second.degrees, minutes + second.minutes);
	}

	Angle operator-(const Angle& second){
		return Angle(degrees - second.degrees, minutes - second.minutes);
	}

	double operator/(const Angle& second){
		double res = static_cast<double>(degrees * 60 + minutes) / (second.degrees * 60 + second.minutes);
		return res ;
	}

	bool operator==(const Angle& second){
		return (degrees == second.degrees && minutes == second.minutes);
	}

	bool operator>(const Angle& second){
		return ((degrees * 60 + minutes) > (second.degrees * 60 + second.minutes));
	}

	bool operator<(const Angle& second){
		return ((degrees * 60 + minutes) < (second.degrees * 60 + second.minutes));
	}


	void display(){
		cout << "Градусы: " << degrees << " минуты: " << minutes << endl;
	}
};
	int operator"" _deg(unsigned long long degrees){	// пользовательский литерал для работы с константами
		return degrees * 60;							// преобразование градусов в минуты
	}

	int operator"" _toSec(unsigned long long degrees){	// пользовательский литерал для работы с константами
		return degrees * 3600;							// преобразование градусов в секунды
	}

	void menu(){
		cout << "\nМеню:\n"
		<< "0 Выход\n"
		<< "1 Перевод введенного значения угла в радианы\n"
		<< "2 Приведение угла к диапазону 0 - 360 градусов\n"
		<< "3 Сложение двух углов\n"
		<< "4 Вычитание двух углов\n"
		<< "5 Деление одного угла на другой\n"
		<< "6 Получение значения тригонометрических функций\n"
		<< "7 Сравнение двух углов\n" << endl;
	}

	void trigonometry(Angle& a){
		cout<< "Значение какой тригонометрической функции Вы хотите получить?" << endl;
		cout << "1) Получить значение sin(x)\n"
		"2) Получить значение cos(x)\n"
		"3) Получить значение tg(x)\n"
		"4) Получить значение ctg(x)\n" << "Выберите номер: ";
		short ans;
		cin >> ans;
		switch(ans){
			case 1: 
				cout << "sin(x) = " << sin(a.radians()) << endl;
				break;
			case 2:
				cout << "cos(x) = " << cos(a.radians()) << endl;
				break;
			case 3:
				cout << "tan(x) = " << tan(a.radians()) << endl;
				break;
			case 5: 
				cout << "tan(x) = " << 1 / tan(a.radians()) << endl;
				break;
			default:
			 	cout << "Неверное действие" << endl;
		}
		return;
	}

int main(){
	setlocale(LC_ALL, "rus");
	cout << "Вывод с помощью пользовательского литерала 34_deg." << endl;
	cout << "34 градуса = " << 34_deg << " минут."<< endl;
	cout << "Вывод с помощью пользовательского литерала 34_toSec." << endl;
	cout << "34 градуса = " << 34_toSec << " секунд."<< endl;
	cout << "\n";
	Angle a;
	Angle b;
	a.setAngle();
	cout << "Выберите действие с введенным значением угла из меню." << endl;
	menu();
	short action;
	cout << "Сделайте выбор: ";
	cin >> action;
	bool state = true;
	while(state){
		switch(action){

			case 0:
				state = false;
				break;

			case 1:{
				a.standart();
				double rad = a.radians();
				cout << "В радианах: " << fixed << setprecision(2) << rad << endl;
				break;
			}

			case 2:
				a.classic();
				break;

			case 3:{
				b.setAngle();
				Angle res;
				res = a + b;
				res.standart();
				cout << "Сумма двух углов: ";
				res.display();
				break;
			}

			case 4:{
				b.setAngle();
				Angle res;
				res = a - b;
				res.standart();
				cout << "Разность двух углов: ";
				res.display();
				break;
			}
			
			case 5:{
				b.setAngle();
				if(b.getDegrees() == 0 && b.getMinutes() == 0){
				cout << "На 0 делить нельзя!" << endl;
				break;
				}
				else{
					double res;
					res = a / b;
					cout << "Частное двух углов показывает, во сколько раз 1 угол больше 2: в " << res << " раз(а)" << endl;;
					break;
				}
			}

			case 6:
				trigonometry(a);
				break;

			case 7:
				b.setAngle();
				if (a == b)
                cout << "Углы равны" << endl;
            	if (a > b)
                cout << " Первый угол больше второго" << endl;
            	if (a < b)
                cout <<  "Первый угол меньше второго"  << endl;
            	break;

			default:
				std:: cout << "Невозможное действие!" << std:: endl;
				menu();
				std:: cout<< "Сделайте выбор: ";
				std:: cin >> action;
				std:: cout << "\n";
				break;
		}
		if(state){
			cout << "Сделайте выбор: ";
			cin >> action;
		}
			
	}

	return 0;
}
