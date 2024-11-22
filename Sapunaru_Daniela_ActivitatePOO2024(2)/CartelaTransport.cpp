#include<iostream>
using namespace std;

class CartelaTransport {
private:
	const string serieCartela;
	string numePosesor;
	char* producatorCartela;
	int nrZileUtilizare;
	float sumaPortofel;
	int nrCalatorii;
	float* valoriCalatorii;
	static float valoareMinCalatorie;

public:

	CartelaTransport() :serieCartela("EFG") {
		this->numePosesor = "Radu";
		this->producatorCartela = NULL;
		this->nrZileUtilizare = 30;
		this->sumaPortofel = 50;
		this->nrCalatorii = 3;
		this->valoriCalatorii = new float[3] {3, 3, 4};

	}

	CartelaTransport(string numePosesor, float sumaPortofel, float* valoriCalatorii, int nrCalatorii) :serieCartela("ABC") {
		this->numePosesor = numePosesor;
		this->producatorCartela = new char[strlen("B4U") + 1];
		strcpy_s(this->producatorCartela, strlen("B4U") + 1, "B4U");
		this->nrZileUtilizare = 20;
		this->sumaPortofel = sumaPortofel;
		this->valoriCalatorii = valoriCalatorii;
		this->nrCalatorii = nrCalatorii;
	}

	~CartelaTransport() {
		if (this->valoriCalatorii) {
			delete[] this->valoriCalatorii;
		}
		if (this->producatorCartela) {
			delete[]this->producatorCartela;
		}
	}

	CartelaTransport(const CartelaTransport& c) : serieCartela(c.serieCartela) {
		this->numePosesor = c.numePosesor;
		if (this->producatorCartela != NULL) {
			this->producatorCartela = new char[strlen(c.producatorCartela) + 1];
			strcpy_s(this->producatorCartela, strlen(c.producatorCartela) + 1, c.producatorCartela);
		}
		else { this->producatorCartela = NULL; }

		this->nrZileUtilizare = c.nrZileUtilizare;
		this->sumaPortofel = c.sumaPortofel;
		this->nrCalatorii = c.nrCalatorii;
		if (this->valoriCalatorii != NULL) {

			this->valoriCalatorii = new float[this->nrCalatorii];
			for (int i = 0; i < this->nrCalatorii; i++) {
				this->valoriCalatorii[i] = c.valoriCalatorii[i];
			}
		}
		else { this->valoriCalatorii = NULL; }
	}

	string getNumePosesor() {
		return this->numePosesor;
	}

	void setNumePosesor(string nume) {
		if (nume.length() > 2) {
			this->numePosesor = nume;
		}
	}

	float* getValoriCalatorii() {
		return this->valoriCalatorii;
	}

	float getValoareCalatorie(int index) {
		if (index >= 0 && index < this->nrCalatorii) {
			return this->valoriCalatorii[index];
		}
		else return this->valoriCalatorii[index] = NULL;
	}

	void setValoriCalatorii(int nrCalatorii, float* valoriCalatorii) {
		if (nrCalatorii > 0) {
			this->nrCalatorii = nrCalatorii;
			if (this->valoriCalatorii != NULL) {
				delete[]this->valoriCalatorii;
			}
			this->valoriCalatorii = new float[this->nrCalatorii];
			for (int i = 0; i < this->nrCalatorii; i++) {
				this->valoriCalatorii[i] = valoriCalatorii[i];
			}
		}
	}

	CartelaTransport operator=(const CartelaTransport& c) {
		if (&c != this) {
			this->numePosesor = c.numePosesor;
			if (this->producatorCartela != NULL) {
				delete[] this->producatorCartela;
			}
			this->producatorCartela = new char[strlen(c.producatorCartela) + 1];
			strcpy_s(this->producatorCartela, strlen(c.producatorCartela) + 1, c.producatorCartela);


			this->nrZileUtilizare = c.nrZileUtilizare;
			this->sumaPortofel = c.sumaPortofel;
			this->nrCalatorii = c.nrCalatorii;
			if (this->valoriCalatorii != NULL) {
				delete[]this->valoriCalatorii;
			}
			this->valoriCalatorii = new float[this->nrCalatorii];
			for (int i = 0; i < this->nrCalatorii; i++) {
				this->valoriCalatorii[i] = c.valoriCalatorii[i];
			}
		}

		return *this;
	}

	friend ostream& operator<<(ostream& out, CartelaTransport c) {
		cout << "Serie cartela:" << c.serieCartela << endl;
		cout << "Nume posesor:" << c.numePosesor << endl;
		cout << "Producator cartela:" << c.producatorCartela << endl;
		cout << "NR. Zile Utilizare:" << c.nrZileUtilizare << endl;
		cout << "Suma portofel:" << c.sumaPortofel << endl;
		cout << "Nr calatorii:" << c.nrCalatorii << endl;
		for (int i = 0; i < c.nrCalatorii; i++) {
			cout << "Valoarea calatoriei " << i + 1 << ":" << c.valoriCalatorii[i] << endl;
		}
		cout << "Valoare minima pe calatori:" << CartelaTransport::valoareMinCalatorie << endl;

		return out;
	}

	friend istream& operator>>(istream& in, CartelaTransport& c) {
		cout << "Introduceti numele posesorului:";
		in >> c.numePosesor;
		cout << "Producator cartela:";
		in >> c.producatorCartela;
		cout << "Nr zile de utilizare:";
		in >> c.nrZileUtilizare;
		cout << "Suma portofel:";
		in >> c.sumaPortofel;
		cout << "Numar calatorii:";
		in >> c.nrCalatorii;
		for (int i = 0; i < c.nrCalatorii; i++) {
			cout << "Valoarea calatoriei cu nr " << i + 1 << ":";
			in >> c.valoriCalatorii[i];
			cout << endl;
		}
		return in;
	}

	CartelaTransport operator+=(float valCalatorie) {
		/*CartelaTransport temp = *this;
		temp.nrCalatorii = this->nrCalatorii+1;
		if (temp.valoriCalatorii != NULL) {
			delete[]temp.valoriCalatorii;
		}
		for (int i = 0; i < temp.nrCalatorii; i++) {
			temp.valoriCalatorii=this->valoriCalatorii[i];
		}
		temp.valoriCalatorii[temp.nrCalatorii]=*/
		float* temp = new float[this->nrCalatorii + 1];
		for (int i = 0; i < this->nrCalatorii; i++) {
			temp[i] = valoriCalatorii[i];
		}
		temp[this->nrCalatorii] += valCalatorie;
		nrCalatorii++;
		delete[] valoriCalatorii;
		valoriCalatorii = temp;
		float s = 0;
		for (int i = 0; i < this->nrCalatorii; i++) {
			s += valoriCalatorii[i];
		}
		if (this->sumaPortofel < s)cout << "Nu sunt suficienti bani, calatoria nu se va efectua";
		else {
			cout << "Calatoria se va efectua.";
			this->valoriCalatorii = temp;
		}
		return *this;
	}

	bool operator>(CartelaTransport c) {
		float s = 0;
		for (int i = 0; i < this->nrCalatorii; i++) {
			s += this->valoriCalatorii[i];
		}
		float s1 = 0;
		for (int j = 0; j < c.nrCalatorii; j++) {
			s1 += c.valoriCalatorii[j];
		}
		return s > s1;
	}

	float medieSumaPeZi() {
		float medie = 0;
		float s = 0;
		for (int i = 0; i < this->nrCalatorii; i++) {
			s += valoriCalatorii[i];
		}

		medie = s / this->nrZileUtilizare;
		return medie;
	}


};
float CartelaTransport::valoareMinCalatorie = 10;

int main() {
	CartelaTransport c1;
	CartelaTransport c2("Ana", 300, new float[3] {3, 4, 5}, 3);
	CartelaTransport c3("Andreea", 200, new float[2] {3, 4}, 2);

	cout << c2.getNumePosesor() << endl;
	c2.setNumePosesor("Iulia");
	cout << c2;

	cout << c3.getValoareCalatorie(2) << endl;
	c3.setValoriCalatorii(2, new float[2] {5, 3});
	cout << c3.getValoriCalatorii();

	CartelaTransport c4 = c1;

	cin >> c4;
	cout << c4;

	CartelaTransport c5;
	c5 += 5;

	if (c5 > c4) {
		cout << "Valoarea totala a cartelei 5 este mai mare.";
	}
	else cout << "Valoarea totala a calatoriei 4 este mai mare.";
	cout << endl;
	float medie = c5.medieSumaPeZi();
	cout << "Valoarea medie cheltuita pe zi pentru transport este: " << medie << endl;



	return 0;
}