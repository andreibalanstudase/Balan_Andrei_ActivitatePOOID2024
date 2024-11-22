#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Autobuz {
private:
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;
public:

    // Constructorul fara parametrii
    Autobuz() : idAutobuz(++nrAutobuze) {
        this->capacitate = 30;
        this->nrPersoaneImbarcate = 0;
        this->producator = new char[strlen("Default") + 1];
        strcpy(producator, "Default");
    }

    // Constructorul cu parametrii
    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(++nrAutobuze) {
        this->capacitate = capacitate;
        if (nrPersoaneImbarcate <= capacitate) 
        {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }
        else 
        {
            this->nrPersoaneImbarcate = capacitate;
            cout << "Numarul de persoane imbarcate depaseste capacitatea. Oameni ramasi de imbarcat:" << nrPersoaneImbarcate - capacitate << endl;
        }
        this->producator = new char[strlen(producator) + 1];
        strcpy(this->producator, producator);
    }

    // Constructorul de copiere
    Autobuz(const Autobuz& a) : idAutobuz(++nrAutobuze) {
        this->capacitate = a.capacitate;
        this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
        this->producator = new char[strlen(a.producator) + 1];
        strcpy(this->producator, a.producator);
    }

    // Supraincarcarea operatorului =
    Autobuz operator=(const Autobuz& a) {
        if (this->producator != NULL)
        {
            delete[]this->producator;

            this->capacitate = a.capacitate;
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
            this->producator = new char[strlen(a.producator) + 1];
            strcpy(producator, a.producator);
        }
        return *this;
    }

    // Supraincarcarea opeartorului de cast explicit int
    explicit operator int() {
        return this->capacitate - this->nrPersoaneImbarcate;
    }

    // Getter Id Autobuz
    int getIdAutobuz() {
        return this->idAutobuz;
    }

    // Getter capacitate
    int getCapacitate() {
        return this->capacitate;
    }

    // Setter capacitate
    void setCapacitate(int capacitate) {
        this->capacitate = capacitate;
    }

    // Getter numar persoane imbarcate
    int getNrPersoaneImbarcate() {
        return this->nrPersoaneImbarcate;
    }

    // Setter numar persoane imbarcate
    void setNrPersoaneImbarcate(int nrPersoaneImbarcate) {
        if (nrPersoaneImbarcate <= capacitate)
        {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }
        else
        {
            this->nrPersoaneImbarcate = capacitate;
            cout << "Numarul de persoane imbarcate depaseste capacitatea. Oameni ramasi de imbarcat:" << nrPersoaneImbarcate - capacitate << endl;
        }
    }

    // Getter locuri libere (diferenta intre capacitate si numarul de persoane imbarcate)
    int getLocuriLibere() {
        return (this->capacitate - this->nrPersoaneImbarcate);
    }

    char* getProducator() {
        return this->producator;
    }

    // Destructor in care se sterge pointerul pentru a evita memory leaks
    ~Autobuz() {
        cout << endl << "S-a apelat destructorul!";
        delete[] producator;
    }

    // Utilizarea cuvantului cheie friend pentru a supraincarca operatorul <<
    friend ostream& operator<<(ostream& oStream, Autobuz& autobuz);

};

// Supraincarcarea operatorului <<
ostream& operator<< (ostream& oStream, Autobuz& autobuz) {
    oStream <<"Autobuzul are :" << "id: " << autobuz.idAutobuz << "; " << "capacitate: " << autobuz.capacitate << "; " <<"nr. persoane imbarcate: " << autobuz.nrPersoaneImbarcate << "; " << "locuri libere: " << autobuz.getLocuriLibere() << "; " << "producator: " << autobuz.producator << endl;
    return oStream;
}

// Supraincarcarea operatorului > pentru compararea disponibilitatii in autobuze
bool operator>(Autobuz& a, Autobuz& b) {
    if (a.getLocuriLibere() > b.getLocuriLibere())
    {
        cout << "Primul autobuz are mai multe locuri libere" << endl;
        return true;
    }
    else
    {
        cout << "Al doilea autobuz are mai multe locuri libere" << endl;
        return false;
    }
}

// Initializarea numarului de autobuze cu 0
int Autobuz::nrAutobuze = 0;

int main() {
    Autobuz autobuz1;
    cout << autobuz1.getCapacitate() << endl;
    cout << autobuz1.getNrPersoaneImbarcate() << endl;
    autobuz1.setNrPersoaneImbarcate(50);
    cout << autobuz1.getNrPersoaneImbarcate() << endl;
    Autobuz autobuz2(40, 20, "Mercedes");
    cout << autobuz2 << endl;
    Autobuz autobuz3 = autobuz2;
    Autobuz autobuz4 = Autobuz(autobuz1);
    cout << autobuz4 << endl;
    autobuz3.getLocuriLibere();
    cout << autobuz3 << endl;
    autobuz3 > autobuz1;
    return 0;
}