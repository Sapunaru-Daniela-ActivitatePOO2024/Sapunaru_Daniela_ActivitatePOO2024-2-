#include<iostream>;
using namespace std;


class Hotel {
private:
	const int id;
	string* nume;
	bool esteOnline;
	string url;
	int nrCamere;
	static int pretMediuCamera;

public:
	Hotel(int i, string* nume, int nr, string url) :id(i) {
		this->nume = nume;
		this->nrCamere = nr;
		this->esteOnline = false;
		this->url = url;
	}

	~Hotel() {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
	}

	Hotel(const Hotel& h) :id(h.id) {
		if (this->nume->length() != 0) {
			this->nume = h.nume;
		}
		else this->nume = NULL;

		this->esteOnline = h.esteOnline;
		this->url = h.url;
		this->nrCamere = h.nrCamere;
	}

	string* getNume() {
		return this->nume;
	}

	string getNum(int index) {
		if (index <= 0 && index < this->id) {
			return this->nume[index];
		}
	}

	/*void setNrCamere(int nrCam, string* nume) {
		if (id > 0) {
			this->nrCamere = nrCam;
			if (this->nume != NULL) {
				delete[] this->nume;
			}
			this->nume = new string[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(this->nume) + 1, nume);
		}
	}*/

	int getID() {
		return this->id;
	}

	int getNrCamere() {
		return this->nrCamere;
	}

	void setNrCamere(int nr) {
		if (nr > 0) {
			this->nrCamere = nr;
		}
	}

	bool esteOnline() {
		return this->esteOnline = true;
	}

	int valTotalCamere() {
		int s;
		s = this->nrCamere * Hotel::pretMediuCamera;
		return s;
	}

	Hotel operator=(const Hotel& h) {
		if (&h != this) {
			if (this->nume != NULL) {
				this->nume = h.nume;
			}
			this->esteOnline = h.esteOnline;
			this->url = h.url;
			this->nrCamere = h.nrCamere;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, Hotel h) {
		out << "Id hotel:" << h.id << endl;
		out << "Nume:" << h.nume << endl;
		out << "Este online:" << h.esteOnline << endl;
		out << "URL:" << h.url << endl;
		out << "Numar de camere disponibile:" << h.nrCamere << endl;
		out << "Pretul mediu pe camera este:" << Hotel::pretMediuCamera << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Hotel& h) {
		cout << "Introduceti numele:";
		for (int i = 0; i < h.nrCamere; i++)
			in >> h.nume[i];
		cout << "Este online:?(1-da,0-nu)";
		in >> h.esteOnline;
		cout << "Url:";
		in >> h.url;
		cout << "Nr de camere disponibile:";
		in >> h.nrCamere;
		return in;
	}

	friend Hotel operator*(int nr, Hotel h) {
		Hotel aux = h;
		if (nr > 0) {
			aux.nrCamere = nr * h.nrCamere;
		}
		return aux;
	}

	Hotel operator-=(int nr) {
		*this -= nr;
		return *this;
	}

	Hotel operator++(int) {
		Hotel copie = *this;
		this->nrCamere++;
		return copie;

	}

	void afisare() {
		cout << "Id hotel:" << this->id << endl;
		cout << "Nume:" << this->nume << endl;
		cout << "Este online:" << this->esteOnline << endl;
		cout << "URL:" << this->url << endl;
		cout << "Numar de camere disponibile:" << this->nrCamere << endl;
		cout << "Pretul mediu pe camera este:" << Hotel::pretMediuCamera << endl;
	}

};

int Hotel::pretMediuCamera = 150.5;

int main() {
	Hotel h1(1, new string[1]{ "Inter" }, 45, "www.inter.ro");

	Hotel h2 = h1;

	h1.esteOnline();
	int s = h2.valTotalCamere();
	cout << "Valoarea totala a camerelor:" << s << endl;
	Hotel h3(3, new string[1]{ "Daisy" }, 35, "www.daisy.ro");
	h1 = h3;

	cin >> h1;
	cout << h1;

	h2 = 2 * h1;
	cout << h1;
	cout << h2;

	Hotel h3(4, new string[1]{ "Ana" }, 40, "ww.ana.ro");
	h3++;
	cout << h3;


	return 0;
}