#include <iostream>
using namespace std;

class Motor {
	int putere; // putere ridicata -> viteza creste
	int greutate; // motor mai usor -> viteza creste
};
class Roata {
private:
	int aderenta; // aderenta crescuta -> viteza creste
	int dimensiune; // latimea creste -> suprafata de aderenta creste -> viteza creste
	float greutate; // greutatea scade -> viteza creste
};

class Vehicul {
private:
	string metodaViraj; // Volan / Ghidon
	int nrRoti; // 2 pentru Motocileta, 4 pentru Masina, Etc.
	int greutateCaroserie; // greutatea totala
	Motor motor;
	Roata roata;
	char* producator;

public :
	Vehicul(string metodaViraj, int nrRoti, int greutateCaroserie, Motor motor, Roata roata, char* producator) {
		this->metodaViraj = metodaViraj;
		this->nrRoti = nrRoti;
		this->greutateCaroserie = greutateCaroserie;
		this->motor = motor;
		this->producator = new char [strlen(producator) + 1];
		strcpy(this->producator, producator);
	}
};
class Motocicleta:public Vehicul {
public:
	Motocicleta(int greutateCaroserie, Motor motor, Roata roata, char* producator) : Vehicul("Ghidon", 2, greutateCaroserie, motor, roata, producator) {};
};
class Masina : public Vehicul {
	Masina(string metodaViraj, int nrRoti, int greutateCaroserie, Motor motor, Roata roata, char* producator) : Vehicul("Volan", 4, greutateCaroserie, motor, roata, producator) {};
};
class Sofer {
	string Nume;
	int experienta;
};
class Participant {
	Vehicul vehicul;
	Sofer sofer;
};
void main() {
	for (int i = 0; i++; i = 6) {
		string numeMotocicleta = "moto" + char(i);
		int greutateCaroserie = int(100 + std::rand() % 51);
		Motocicleta numeMotocicleta(greutateCaroserie, )
	}
}