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

	incaltaminte(int pret, int nr, int an) :anCumparare(an) {
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

};

int sapca::nrTaxe = 7;





int main() {
	int nr = 3;//nr de obiecte
	tricou tricou1;
	tricou tricou2;
	tricou tricou3;

	tricou* v1 = new tricou[nr];
	for (int i = 0; i < nr; i++) {
		cin >> v1[i];
	}
	cout << endl;
	for (int i = 0; i < nr; i++) {
		cout << v1[i] << endl;
	}


	incaltaminte* v2 = new incaltaminte[nr];
	for (int i = 0; i < nr; i++) {
		cin >> v2[i];
	}
	cout << endl;
	for (int i = 0; i < nr; i++) {
		cout << v2[i] << endl;
	}



	sapca* v3 = new sapca[nr];
	for (int i = 0; i < nr; i++) {
		cin >> v3[i];
	}
	cout << endl;
	for (int i = 0; i < nr; i++) {
		cout << v3[i] << endl;
	}

	tricou** matrice = new tricou * [nr];
	for (int i = 0; i < nr; i++) {
		matrice[i] = new tricou[nr];
	}

	//matrice[0] = &tricou3;
	//matrice[1] = &tricou1;
	//matrice[2] = &tricou2;

	for (int i = 0; i < nr; i++) {
		cout << *matrice[i] << " ";
	}

	for (int i = 0; i < nr; i++) {
		delete[]matrice[i];
	}
	delete[]matrice;
	return 0;

}


