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
		if (this->pretT != NULL) {
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

	float calculeazaPretTotal(int index) {
		if (index >= 0 && index < this->nrMagazine)
			return this->pretT[index] + (this->pretT[index] * tricou::TVA / 100.0f);
	}

	explicit operator float() {
		return this->calculeazaPretTotal(this->nrMagazine);
	}

	tricou operator+(const tricou& t)const {
		tricou temp = *this;
		temp.nrMagazine = this->nrMagazine + t.nrMagazine;
		return temp;
	}

	tricou operator+=(tricou t) {
		this->nrMagazine = this->nrMagazine + t.nrMagazine;
		return *this;
	}

	/*tricou operator+=(tricou t) {
		*this = *this + t;
		return *this;
	}*/

	tricou operator+=(int magazineExtra) {
		this->nrMagazine += magazineExtra;
		return *this;
	}

	tricou operator+(int magExtr)const {
		tricou temp = *this;
		temp.nrMagazine += magExtr;//adaos pret
		return temp;
	}

	friend tricou operator+(int magazineExtra, tricou t) {
		tricou temp = t;
		temp.nrMagazine += magazineExtra;
		return temp;
	}

	tricou operator-(int nr) {
		tricou temp = *this;
		temp.nrMagazine -= nr;
		return temp;
	}

	friend tricou operator-(int nr, tricou t) {
		tricou temp = t;
		temp.nrMagazine -= nr;
		return temp;
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

	explicit operator string() {
		return this->marca;
	}

	explicit operator int() {
		return this->nrMagazine;
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

	float& operator[](int index) {
		if (index >= 0 && index < this->nrMagazine) {
			return this->pretT[index];
		}

		throw;
		//throw InvalidIndexException();// ("Indexul este in afara limitelor");

	}


	void afisare() {
		cout << "Tricoul este marca:" << this->marca << endl;
		cout << "Material:" << this->material << endl;
		cout << "Numarul magazinelor care vand tricoul:" << this->nrMagazine << endl;
		cout << "An aparitie:" << this->anAparitie << endl;
		cout << "TVA:" << tricou::TVA << endl << endl;

	}

	bool operator<(tricou t)
	{
		return this->nrMagazine < t.nrMagazine;
	}


};

int tricou::TVA = 9;

class InvalidIndexException :public exception {

public:
	InvalidIndexException() {}

};


class incaltaminte {
private:
	char* producator;
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
		this->producator = new char[strlen("Nike") + 1];
		strcpy_s(this->producator, strlen("Nike") + 1, "Nike");
	}

	incaltaminte(const incaltaminte& i) :anCumparare(i.anCumparare) {
		this->producator = new char[strlen(i.producator) + 1];
		strcpy_s(this->producator, strlen(i.producator) + 1, i.producator);
		this->nrMagazine = i.nrMagazine;
		this->pretI = i.pretI;
	}

	incaltaminte operator=(const incaltaminte& c) {
		if (&c != this) {//verif de autoasignare
			this->pretI = c.pretI;
			this->nrMagazine = c.nrMagazine;
			if (this->producator != NULL) {
				delete[] this->producator;
			}
			this->producator = new char[strlen(c.producator) + 1];
			strcpy_s(this->producator, strlen(c.producator) + 1, c.producator);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, incaltaminte c) {
		out << "Producator:" << c.producator << endl;
		out << "Pret:" << c.pretI << endl;
		out << "Nr magazine:" << c.nrMagazine << endl;
		out << "TVA:" << incaltaminte::TVA << endl;
		out << "An cumparare:" << c.anCumparare << endl;

		return out;
	}

	friend istream& operator>>(istream& in, incaltaminte& c) {
		cout << "Introduceti producatorul:";
		if (c.producator != 0) {
			delete[] c.producator;
		}
		c.producator = new char[strlen(c.producator) + 1];
		in >> c.producator;
		cout << "Pret:";
		in >> c.pretI;
		cout << "Nr magazine:";
		in >> c.nrMagazine;

		return in;
	}

	explicit operator float() {
		return this->calculeazaValoareaTotala(this, this->nrMagazine);
	}

	explicit operator int() {
		return this->nrMagazine;
	}


	~incaltaminte() {
		if (this->pretI) {
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


	char* getProducatorii() {
		return this->producator;
	}

	char setProducator(int index) {
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


	void afisare()
	{
		cout << endl << "Producatorul pantofilor este:" << this->producator << endl;
		cout << "TVA:" << incaltaminte::TVA << endl;
		cout << "An cumparare:" << this->anCumparare << endl;
		cout << "Nr magazinelor:" << this->nrMagazine << endl << endl;

	}

	bool operator>(incaltaminte i) {
		return this->nrMagazine < i.nrMagazine;
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


	bool getAreImprimeu() {
		return this->areImprimeu;
	}

	void setAreImprimeu(bool imp) {
		this->areImprimeu = imp;
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

	friend sapca operator+(float cost, sapca s) {
		sapca temp = s;
		if (temp.cost != NULL) {
			delete[] temp.cost;
		}
		temp.cost = new float[temp.nrFabrici + 1];
		for (int i = 0; i < s.nrFabrici; i++) {
			temp.cost[i] = s.cost[i];
		}
		temp.cost[temp.nrFabrici] = cost;
		temp.nrFabrici++;
		return temp;
	}

	//operatori unari cu forma prefixa ++a si forma postfixa a++
	sapca operator++() {
		this->nrFabrici++;
		return *this;
	}//++s

	sapca operator++(int) {
		sapca copie = *this;
		this->nrFabrici++;
		return copie;
	}//s++


	sapca operator--() {
		this->nrFabrici--;
		return *this;
	}//--s

	sapca operator--(int) {
		sapca copie = *this;
		this->nrFabrici--;
		return *this;
	}//s--

	sapca operator-(sapca s) const {
		sapca temp = *this;
		temp.nrFabrici = this->nrFabrici - s.nrFabrici;
		float* aux = new float[temp.nrFabrici];
		for (int i = 0; i < this->nrFabrici; i++) {
			aux[i] = this->cost[i];
		}
		for (int i = 0; i < s.nrFabrici; i++) {
			aux[i + this->nrFabrici] = s.cost[i];
		}
		if (temp.cost != NULL) {
			delete[]temp.cost;
		}
		temp.cost = aux;

		return temp;
	}




	/*sapca operator+(int valoare) {
		sapca aux = *this;
		aux.nrFabrici = this->nrFabrici + valoare;
		return aux;
	}*/

	friend sapca operator+(float cost, sapca s) {
		float valoare = s.nrFabrici;
		return s + cost;
	}

	sapca& operator-=(sapca s) {
		*this = *this - s;
		return *this;
	}

	sapca& operator+=(sapca s) {
		*this = *this + s;
		return *this;
	}

	sapca operator*(float valoare) {

	}
	sapca operator*(sapca s) {

	}
	friend sapca operator*(float valoare, sapca s) {

	}



	sapca operator/(float valoare) {

	}

	sapca operator/(sapca s) {

	}

	friend sapca operator/(float valoare, sapca s) {

	}

	sapca operator%(sapca& s) {

	}
	/*sapca operator%(sapca& s) {
	????????????????
	}*/

	//op logici:
	bool operator&& (const sapca& s)const {

	}

	bool operator||(const sapca& s)const {

	}

	//op ptr comparatie-relationali

	bool operator==(sapca s) {

	}

	bool operator<(sapca s) {

	}

	bool operator>=(sapca s) {

	}
	bool operator!=(sapca s) {

	}

	//op de CAST:
	explicit operator bool() {
		return this->areImprimeu;
	}

	explicit operator int() {
		return this->nrFabrici;
	}

	explicit operator float() {
		float s = 0;
		for (int i = 0; i < this->nrFabrici; i++) {
			s += this->cost[i];
		}
		return s;
	}

	/*explicit operator float* () {
		return this->cost;
	}*/

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

	//returneaza costurile totale
	int operator()() {
		int s = 0;
		for (int i = 0; i < this->nrFabrici; i++) {
			s += this->cost[i];
		}
		return s;
	}

	//returneaza costul total al primelor n fabrici;
	int operator()(int n) {
		int s = 0;
		if (n > 0 && n <= this->nrFabrici) {
			for (int i = 0; i < n; i++) {
				s += this->cost[i];
			}
		}
		else { cout << "Nu se poate calcula costul total."; }
		return s;
	}

	//returneaza costul fabricilor din intervalul (m,n)

	int operator()(int m, int n) {
		int s = 0;
		if (m > 0 && n > m && n <= this->nrFabrici) {
			for (int i = m; i < n; i++) {
				s += this->cost[i];
			}
		}
		else { cout << "Costul total nu se poate calcula."; }
		return s;
	}

	//op de negare-asupra atributelor de tip bool
	sapca operator!() {
		sapca copie = *this;
		copie.areImprimeu = !copie.areImprimeu;
		return *this;
	}

	//op -> returneaza pointer aspre obiectul asupra caruia au fost relizate modificari/operatii
	sapca operator->() {
		this->nrFabrici = 10;
		return *this;
	}


	//op de index
	float& operator[](int index) {
		if (index >= 0 && index < this->nrFabrici) {
			return this->cost[index];
		}
		else {
			throw "Indexul este in afara limitelor";
		}
	}

	void afisare()
	{
		cout << endl << "Sapca are brandul:" << this->brand << endl;
		cout << "An fabricare:" << this->anFabricare << endl;
		cout << "Mairme:" << this->marime << endl;
		cout << "Numar de fabrici:" << this->nrFabrici << endl;
		cout << "Cost:" << this->cost << endl;
		cout << "Are imprimeu:" << (this->areImprimeu ? "da" : "nu");
		cout << "Numar de taxe:" << sapca::nrTaxe << endl << endl;

	}
};

int sapca::nrTaxe = 7;





int main() {
	//
	tricou t1;
	tricou t2 = t1;
	tricou t;
	t1.afisare();
	cout << endl;

	t2.afisare();
	//op << si >>
	cin >> t2;
	cout << t2;

	tricou t4 = t2;
	tricou t5 = t2 + 20;
	t4.afisare();

	t4 += t2;
	t4.afisare();

	int nrMagazine = (int)t2;//operator de cast
	cout << nrMagazine << endl;

	string marca = (string)t1;
	cout << marca;
	if (t < t2) {//t1.operator<(t2)
		cout << "t1 este mai mic decat t2";

	}

	try {
		cout << t2[1] << endl;
		//cout << t2[-1];
	}
	catch (InvalidIndexException& e) {
		cout << e.what();
	}
	catch (exception& e) {
		cout << "exceptie";
	}
	catch (...) {
		cout << "Eroare necunoscuta";
	}

	cout << t2[1] << endl;
	t2[1] = 2000;
	cout << t2[1];

	float pret = (float)t2;
	cout << "Pretul total este:" << pret;




	incaltaminte c1;
	incaltaminte c2(130, 2, 2020);
	c1 = c2;

	cout << c1;
	cin >> c2;

	float valoareTotala = (float)c1;
	int nr = (int)c2;

	if (c1 > c2) {
		cout << "c1 este mai mare decat c2";
	}
	else { cout << "c2 este mai mare decat c1"; }




	sapca s1;
	cin >> s1;
	cout << s1;

	int nrFabrici = (int)s1;
	float costuriTotale = (float)s1;
	bool imprimeu = (bool)s1;

	try {
		cout << s1[2] << endl;
	}
	catch (int exceptie) {

	}
	catch (float exceptie) {

	}
	catch (const char* exceptie) {
		cout << endl << exceptie << endl;
	}
	catch (...) {

	}

	cout << s1[1] << endl;
	s1[1] = 200;
	cout << s1[1];


	sapca s2("nike", 4, m, new float[4] {3000, 2000, 1000, 1500}, true, 2020);


	cout << s1();
	cout << s2(2);
	cout << s1(2, 4);

	cout << !s2;




	return 0;

}


