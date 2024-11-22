#include<iostream>
#include<string>
using namespace std;
//
//enum class Type {
//	locatie,
//    online
//};

class flowerShop {
	const int shopID;
	char* nume = NULL;
	//Type type = Type::locatie;
	bool areWebsite;
	int nrFloriVandute;
	string url;
	static float pret_mediu_floare;

public:

	flowerShop(const int id = 1, const char* nume = "necunoscut", int nrFlori = 0) :shopID(id) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->nrFloriVandute = nrFlori;
		this->areWebsite = false;
		this->url = "ww.abc";
	}

	flowerShop(const flowerShop& c) : shopID(c.shopID) {
		if (this->nume != NULL) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else this->nume = NULL;
		this->areWebsite = c.areWebsite;
		this->nrFloriVandute = c.nrFloriVandute;
		this->url = c.url;
	}

	~flowerShop() {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
	}

	char* getNume() {
		return this->nume;
	}

	void setNume(char* nume) {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	const int getID() {
		return this->shopID;
	}

	int getNrFloriVandute() {
		return this->nrFloriVandute;
	}

	void setNrFloriVandute(int nr) {
		if (nr > 0) {
			this->nrFloriVandute = nr;
		}
	}

	void setWebsite(string url) {
		if (url.length() > 3) {
			this->url = url;
			this->areWebsite = true;
		}
	}

	float totalVanzari() {
		return this->nrFloriVandute * flowerShop::pret_mediu_floare;
	}

	flowerShop& operator=(const flowerShop& c) {
		if (&c != this) {
			if (this->nume != NULL) {
				delete[] this->nume;
			}
			this->nume = new char[strlen(c.nume) + 1];
			strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);

			this->url = c.url;
			this->nrFloriVandute = c.nrFloriVandute;
			this->areWebsite = c.areWebsite;

		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, flowerShop c) {
		out << "Nume:" << c.nume << endl;
		out << "Id magazin:" << c.shopID << endl;
		out << "Are website?(1-da,0-nu)" << c.areWebsite << endl;
		out << "Nr de flori vandute:" << c.nrFloriVandute << endl;
		out << "url:" << c.url << endl;
		out << "Pret mediu de floare:" << flowerShop::pret_mediu_floare;

		return out;
	}

	friend istream& operator>>(istream& in, flowerShop c) {
		cout << "introduceti numele:";
		in >> c.nume;
		cout << "Are website?(1-da,0-nu)";
		in >> c.areWebsite;
		cout << "Nr de flori vandute:";
		in >> c.nrFloriVandute;
		cout << "URL:";
		in >> c.url;

		return in;
	}

	friend flowerShop operator+(int nr, const flowerShop& c) {
		flowerShop copie = c;
		if (nr > 0) {
			copie.nrFloriVandute += nr;
		}
		return copie;
	}

	flowerShop operator+(int nr) {
		this->nrFloriVandute += nr;
		return *this;
	}

	flowerShop operator+=(int nr) {
		if (nr > 0) {
			return this->nrFloriVandute += nr;
		}
		else cout << "Numarul introdus nu este bun.";
	}

	flowerShop operator++(int) {
		flowerShop copie = *this;
		this->nrFloriVandute++;
		return copie;
	}


	void afisare() {
		cout << "Id. magazin:" << this->shopID << endl;
		cout << "Numele magazinului:" << this->nume << endl;
		cout << "Are website?(1-DA, 0-NU)" << (this->areWebsite ? "DA" : "NU") << endl;
		cout << "Nr de flori vandute:" << this->nrFloriVandute << endl;
		cout << "URL:" << this->url << endl;
		cout << "Pretul mediu pe floare:" << flowerShop::pret_mediu_floare << endl;
	}

};


float flowerShop::pret_mediu_floare = 7.5;

int main() {
	//1-constructorul implicit
	flowerShop f1(1, "Maria", 15);
	f1.afisare();

	//2-getteri si setteri
	flowerShop test(f1);
	cout << test.getNume() << endl;
	cout << test.getID() << endl;
	cout << test.getNrFloriVandute() << endl;

	//3- 2 metode: pentru a seta atributul boolean true si a calcula vanzarile totale.
	f1.setWebsite("www.maria.ro");
	float vanzari = f1.totalVanzari();
	cout << vanzari << endl;

	//4- operatorul =
	flowerShop f2(2, "Daisy", 35);
	f1 = f2;

	//5- supraincarcarea operatorilor de citire si scriere
	cin >> f1;
	cout << f1;

	//6- operatorul +, creste nr florilor vandute cu nr dat 
	f2 = 23 + f1;
	cout << f1 << endl;
	cout << f2 << endl;

	//7- operatorul+=, creste nr florilor
	f1 += 45;
	cout << f1;

	//8- operatorul ++(post incrementare) 
	f1++;//forma postfixa!
	cout << f1;

	return 0;
}