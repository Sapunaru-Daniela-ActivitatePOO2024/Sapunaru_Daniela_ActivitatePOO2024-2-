#include<iostream>

using namespace std;


class tricou {
private:
	string marca;
	int nrMagazine;
	static int TVA;
	string material;
	float* pretT;
	const int anAparitie;


public:

	tricou() : anAparitie(2020) {
		this->marca = "Adidas";
		this->nrMagazine = 36;
		this->pretT = NULL;
		this->material = "in";
	}


	tricou(const tricou& t) :anAparitie(t.anAparitie) {
		this->marca = t.marca;
		this->nrMagazine = t.nrMagazine;
		this->material = t.material;
		if (t.pretT != NULL) {
			this->pretT = new float[t.nrMagazine];
			for (int i = 0; i < t.nrMagazine; i++) {
				this->pretT[i] = t.pretT[i];
			}
		}
		else this->pretT = NULL;
	}


	~tricou() {
		if (this->pretT) {
			delete[]this->pretT;
		}
	}

	string getMarca() {
		return this->marca;
	}
	string setMarca(string marca) {
		if (marca.length() > 2) {
			this->marca = marca;
		}
	}

	int getNrMagazine() {
		return this->nrMagazine;
	}
	int setNrMagazine(int nrMagazine) {
		if (nrMagazine > 1) {
			this->nrMagazine = nrMagazine;
		}
		return nrMagazine;
	}

	string getMaterial() {
		return this->material;
	}
	string setMaterial(string material) {
		if (material.length() > 1) {
			this->material = material;
		}
	}

	static int getTVA() {
		return TVA;
	}


	//seter compus:
	void setNrMagazine(int nrMagazine, float* pretT) {
		if (nrMagazine > 0) {
			this->nrMagazine = nrMagazine;
			if (this->pretT != NULL) {
				delete[] this->pretT;
			}
			this->pretT = new float[this->nrMagazine];
			for (int i = 0; i < this->nrMagazine; i++) {
				this->pretT[i] = pretT[i];
			}
		}
	}

	float* getPreturi() {
		return this->pretT;
	}

	float setPret(int index) {
		if (index >= 0 && index < this->nrMagazine) {
			return this->pretT[index];
		}
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			tricou::TVA = noulTVA;
		}
	}



	friend ostream& operator<<(ostream& out, tricou t) {
		out << "Tricoul este marca:" << t.marca << endl;
		out << "Material:" << t.material << endl;
		out << "Numarul magazinelor care vand tricoul:" << t.nrMagazine << ":";
		if (t.pretT != NULL) {
			for (int i = 0; i < t.nrMagazine; i++) {
				out << t.pretT[i] << ",";
			}
		}out << endl;

		out << "An aparitie:" << t.anAparitie << endl;
		out << "TVA:" << tricou::TVA << endl << endl;

		return out;
	}

	friend istream& operator>>(istream& in, tricou& t) {
		cout << "Introduceti marca:";
		in >> t.marca;
		cout << "Materialul:";
		in >> t.material;
		cout << "Nr magazine:";
		in >> t.nrMagazine;
		if (t.pretT != NULL) {
			delete[]t.pretT;
		}
		if (t.nrMagazine > 0) {
			t.pretT = new float[t.nrMagazine];
			for (int i = 0; i < t.nrMagazine; i++) {
				cout << "Salariul " << i + 1 << ":";
				in >> t.pretT[i];
			}
		}
		else {
			t.pretT = NULL;
		}

		return in;
	}

	tricou operator+(float pret)const {
		tricou temp = *this;
		if (temp.pretT != NULL) {
			delete[]temp.pretT;
		}
		temp.pretT = new float[temp.nrMagazine + 1];
		for (int i = 0; i < this->nrMagazine; i++) {
			temp.pretT[i] = this->pretT[i];
		}
		temp.pretT[temp.nrMagazine] = pret;
		temp.nrMagazine++;
		return temp;
	}

	tricou operator=(const tricou& t) {
		if (this != &t) {
			this->marca = t.marca;
			this->nrMagazine = t.nrMagazine;
			this->material = t.material;
			if (this->pretT != NULL) {
				delete[]this->pretT;
			}
			this->pretT = new float[t.nrMagazine];
			for (int i = 0; i < t.nrMagazine; i++) {
				this->pretT[i] = t.pretT[i];
			}
		}
		return *this;
	}
	friend class dulap;

};

int tricou::TVA = 9;

class incaltaminte {
private:
	string* producator;
	float pretI;
	static int TVA;
	const int anCumparare;
	int nrMagazine;

public:
	incaltaminte() :anCumparare(2021) {
		this->producator = NULL;
		this->pretI = 100;
		this->nrMagazine = 1;
	}

	incaltaminte(float pret, int nr, int an) :anCumparare(an) {
		this->pretI = pret;
		this->nrMagazine = nr;
		this->producator = new string[this->nrMagazine];
		for (int i = 0; i < this->nrMagazine; i++) {
			this->producator[i] = "nike";
		}

	}

	incaltaminte(const incaltaminte& i) :anCumparare(i.anCumparare) {
		this->producator = new string[i.nrMagazine];
		for (int j = 0; j < i.nrMagazine; j++) {
			this->producator[j] = i.producator[j];
		}
		this->nrMagazine = i.nrMagazine;
		this->pretI = i.pretI;
	}

	incaltaminte operator=(const incaltaminte& c) {
		if (&c != this) {//verif de autoasignare
			this->pretI = c.pretI;
			this->nrMagazine = c.nrMagazine;
			if (this->producator != NULL) {
				delete[]this->producator;
			}
			this->producator = new string[c.nrMagazine];
			for (int j = 0; j < c.nrMagazine; j++) {
				this->producator[j] = c.producator[j];
			}

		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, incaltaminte c) {
		if (c.producator != NULL) {
			for (int i = 0; i < c.nrMagazine; i++) {
				out << c.producator[i] << ", ";
			}
		}
		out << "Pret:" << c.pretI << endl;
		out << "Nr magazine:" << c.nrMagazine << endl;
		out << "TVA:" << incaltaminte::TVA << endl;
		out << "An cumparare:" << c.anCumparare << endl;

		return out;

	}

	friend istream& operator>>(istream& in, incaltaminte& c)
	{
		cout << "Pret:";
		in >> c.pretI;
		cout << "Nr magazine:";
		in >> c.nrMagazine;
		if (c.producator != NULL) {
			delete[]c.producator;
		}
		if (c.nrMagazine > 0) {
			c.producator = new string[c.nrMagazine];
			cout << "Producatori:";
			for (int i = 0; i < c.nrMagazine; i++) {
				in >> c.producator[i];
			}
		}
		else {
			c.producator = NULL;
		}
		return in;
	}


	~incaltaminte() {
		if (this->producator) {
			delete[]this->producator;
		}
	}

	float getPret() {
		return this->pretI;
	}

	void setPret(float pret) {
		if (pret > 0) {
			this->pretI = pret;
		}
	}


	int getNrMagazine() {
		return this->nrMagazine;
	}
	int setNrMagazine(int noulNr) {
		if (noulNr > 0) {
			this->nrMagazine = noulNr;
		}
		return noulNr;
	}


	string* getProducatorii() {
		return this->producator;
	}

	string setProducator(int index) {
		if (index >= 0 && index < this->nrMagazine) {
			return this->producator[index];
		}
	}
	static int getTVA() {
		return TVA;
	}

	static float calculeazaValoareaTotala(incaltaminte* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].pretI;
		}
	}

	friend class dulap;

};

int incaltaminte::TVA = 19;

enum marimi { s, m, l, xl };

class sapca {
private:
	string brand;
	int nrFabrici;
	marimi marime;
	const int anFabricare;
	float* cost;
	bool areImprimeu;
	static int nrTaxe;

public:

	sapca() :anFabricare(2021) {
		this->brand = "Kappa";
		this->cost = NULL;
		this->marime = marimi{ m };
		this->nrFabrici = 5;
		this->areImprimeu = false;
	}

	sapca(string brand, int nr, marimi mar, float* cost, bool imp, int an) :anFabricare(an) {
		this->brand = brand;
		this->cost = cost;
		this->marime = mar;
		this->nrFabrici = nr;
		this->areImprimeu = imp;
	}



	sapca(const sapca& s) :anFabricare(s.anFabricare) {
		this->brand = s.brand;
		this->nrFabrici = s.nrFabrici;
		this->marime = s.marime;
		this->cost = new float[s.nrFabrici];
		for (int i = 0; i < s.nrFabrici; i++) {
			this->cost[i] = s.cost[i];
		}
		this->areImprimeu = s.areImprimeu;
	}

	~sapca() {
		if (this->cost) {
			delete[]this->cost;
		}
	}

	string getBrand() {
		return this->brand;
	}
	string setBrand(string noulB) {
		if (noulB.length() > 1)
			this->brand = noulB;
	}

	int getNrFabrici() {
		return this->nrFabrici;
	}
	int setNrFabrici(int noulNr) {
		if (noulNr > 0) {
			this->nrFabrici = noulNr;
		}
		return noulNr;
	}



	marimi getMarime() {
		return this->marime;
	}

	marimi setCuloare(marimi marime) {
		this->marime = marime;
	}

	float* getCosturi() {
		return this->cost;
	}
	float getCost(int index) {
		if (index >= 0 && index < this->nrFabrici) {
			return this->cost[index];
		}

	}

	void setNrFabrici(int nr, float* cost) {
		if (nr > 0) {
			this->nrFabrici = nr;
			if (this->cost != NULL) {
				delete[] this->cost;
			}
			this->cost = new float[this->nrFabrici];
			for (int i = 0; i < nr; i++) {
				this->cost[i] = cost[i];
			}
		}
	}


	static int getNrTaxe() {
		return nrTaxe;
	}

	friend ostream& operator<<(ostream& out, sapca s) {
		out << endl << "Sapca are brandul:" << s.brand << endl;
		out << "An fabricare:" << s.anFabricare << endl;
		out << "Marimea:" << s.marime << endl;
		out << "Numar de fabrici:" << s.nrFabrici << endl;
		if (s.cost != NULL) {
			for (int i = 0; i < s.nrFabrici; i++) {
				out << "Costul " << i + 1 << s.cost << "; ";
				out << endl;
			}
		}
		out << endl;
		out << "Are imprimeu:" << (s.areImprimeu ? "da" : "nu");
		out << "Numar de taxe:" << sapca::nrTaxe << endl;
		return out;
	}

	friend istream& operator>>(istream& in, sapca& s) {
		cout << "Introduceti brandul:";
		in >> s.brand;
		cout << "Numar de fabrici:";
		in >> s.nrFabrici;
		if (s.cost != 0) {
			delete[] s.cost;
		}
		if (s.nrFabrici > 0) {
			s.cost = new float[s.nrFabrici];
			for (int i = 0; i < s.nrFabrici; i++) {
				cout << "Costul " << i + 1 << ":";
				in >> s.cost[i];
				cout << endl;
			}
		}
		cout << "Are imprimeu?(1-da,0-nu):";
		in >> s.areImprimeu;

		return in;
	}

	sapca operator+(sapca s)const {
		sapca temp = *this;
		temp.nrFabrici = this->nrFabrici + s.nrFabrici;
		float* aux = new float[temp.nrFabrici];
		for (int i = 0; i < this->nrFabrici; i++) {
			aux[i] = this->cost[i];
		}
		for (int i = 0; i < s.nrFabrici; i++) {
			aux[i + this->nrFabrici] = s.cost[i];
		}
		if (temp.cost != NULL) {
			delete[] temp.cost;
		}
		temp.cost = aux;
		return temp;
	}

	sapca operator+(float cost)const {
		sapca temp = *this;
		if (temp.cost != NULL) {
			delete[] temp.cost;
		}
		temp.cost = new float[temp.nrFabrici + 1];
		for (int i = 0; i < this->nrFabrici; i++) {
			temp.cost[i] = this->cost[i];
		}
		temp.cost[temp.nrFabrici] = cost;
		temp.nrFabrici++;

		return temp;
	}


	sapca operator=(const sapca& s) {
		if (&s != this) {
			this->brand = s.brand;
			this->nrFabrici = s.nrFabrici;
			this->marime = s.marime;
			if (this->cost != NULL) {
				delete this->cost;
			}
			this->cost = new float[s.nrFabrici];
			for (int i = 0; i < s.nrFabrici; i++) {
				this->cost[i] = s.cost[i];
			}
			this->areImprimeu = s.areImprimeu;
		}
		return *this;
	}
	friend class dulap;
};

int sapca::nrTaxe = 7;



class dulap {
private:
	string culoare;
	float inaltime;
	int nrTricouri;
	tricou* t;
	incaltaminte i;
	sapca* s;

public:

	dulap() {
		this->culoare = "maro";
		this->inaltime = 210, 5;
		this->nrTricouri = 2;
		this->t = new tricou[this->nrTricouri];
		for (int i = 0; i < this->nrTricouri; i++) {
			this->t[i].nrMagazine = i;
		}
		this->i = incaltaminte();
		this->s = new sapca("nike", 4, m, new float[4] {3000, 2000, 1000, 1500}, true, 2020);
	}

	dulap(string culoare, float inaltime, int nrTricouri, tricou* t, incaltaminte i, sapca* sa) {
		this->culoare = culoare;
		this->inaltime = inaltime;
		this->nrTricouri = nrTricouri;
		this->i = i;
		this->s = new sapca(*sa);
		this->t = new tricou[this->nrTricouri];
		for (int j = 0; j < this->nrTricouri; j++) {
			this->t[j] = t[j];
		}

	}

	dulap(const dulap& d) {
		this->culoare = d.culoare;
		this->inaltime = d.inaltime;
		this->nrTricouri = d.nrTricouri;
		this->i = d.i;
		this->t = new tricou[this->nrTricouri];
		for (int j = 0; j < d.nrTricouri; j++) {
			this->t[j] = d.t[j];
		}
		this->s = new sapca(*(d.s));
	}

	~dulap() {
		if (this->t) {
			delete[] this->t;
		}

		if (this->s) {
			delete this->s;
		}
	}
	string getCuloare() {
		return this->culoare;
	}
	void setCuloare(string cul) {
		if (cul.length() > 0) {
			this->culoare = cul;
		}
	}

	float getInaltime() {
		return this->inaltime;
	}
	void getInaltime(float inaltime) {
		if (inaltime > 0) {
			this->inaltime = inaltime;
		}
	}

	incaltaminte getIncaltaminte() {
		return this->i;
	}
	void setIncaltaminte(int nr) {
		if (nr)
			this->i.nrMagazine = nr;

	}

	sapca getSapca() {
		return *this->s;
	}
	void setSapca() {
		if (this->s->areImprimeu)
			this->s->areImprimeu = true;
	}

	tricou getTricou() {
		for (int i = 0; i < this->nrTricouri; i++)
			return this->t[i];
	}
	void setTricou(string material, int nrTricouri) {
		if (nrTricouri > 0) {
			this->nrTricouri = nrTricouri;

			if (material.length() > 1) {
				for (int i = 0; i < this->nrTricouri; i++)
					this->t[i].material = material;
			}
		}
	}

	dulap operator=(const dulap& d) {
		if (&d != this) {
			this->culoare = d.culoare;
			this->inaltime = d.inaltime;
			this->nrTricouri = d.nrTricouri;
			this->i = d.i;
			if (this->t) delete[] this->t;
			this->t = new tricou[this->nrTricouri];
			for (int j = 0; j < d.nrTricouri; j++) {
				this->t[j] = d.t[j];
			}
			if (this->s) delete this->s;
			this->s = new sapca(*(d.s));
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, dulap d) {
		out << "Culoarea dulapului este: " << d.culoare << endl;
		out << "Inaltimea: " << d.inaltime << endl;
		out << "Incaltamintea din dulap este: " << endl << d.i << endl;
		out << "Sapca din dulap este:" << endl << *d.s << endl;
		out << "Avem " << d.nrTricouri << " tricouri in dulap:" << endl;
		for (int j = 0; j < d.nrTricouri; j++) {
			out << d.t[j] << endl;
		}
		out << endl;

		return out;
	}

	dulap operator--() {
		if (this->nrTricouri > 0) {
			this->nrTricouri--;
			tricou* aux = new tricou[this->nrTricouri];
			for (int j = 0; j < this->nrTricouri; j++) {
				aux[j] = this->t[j];
			}
			delete[] this->t;
			this->t = aux;
		}
		return *this;
	}


	dulap operator--(int) {
		dulap copie = *this;
		--(*this);
		return copie;
	}


	tricou operator[](int index) {
		if (index >= 0 && index < this->nrTricouri) {
			return this->t[index];
		}
	}

	int operator()() {
		int s = 0;
		for (int i = 0; i < this->nrTricouri; i++)
		{
			s += t[i].nrMagazine;
		}
		return s;
	}

};


int main() {
	dulap d;
	incaltaminte incaltaminte;
	sapca* sapca1 = new sapca();
	tricou* tricouri = new tricou[5];
	dulap d1("negru", 190, 5, tricouri, incaltaminte, sapca1);


	d1 = d--;
	cout << d1;
	--d1;
	cout << d1;

	cout << d[1];
	cout << d();
}