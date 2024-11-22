#include<iostream>

using namespace std;

class Cofetarie {
private:
	string nume; 
	int nrAngajati;
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

public:
	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 3;
		this->esteVegana = true;
		this->salarii = NULL;
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 10;
		}
	}

	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		if (this->salarii != NULL) {
			for (int i = 0; i < c.nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
		}
		//else this->salarii = 0;
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}
	Cofetarie operator=(const Cofetarie& c) {
		if (&c != this) {
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
			this->esteVegana = c.esteVegana;
			this->adaos = c.adaos;
		}
		return *this;
	}

	~Cofetarie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	Cofetarie operator+(Cofetarie c)const {
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < c.nrAngajati; i++) {
			aux[i + this->nrAngajati] = c.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Cofetarie operator-(Cofetarie c)const {
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati - c.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < c.nrAngajati; i++) {
			aux[i + this->nrAngajati] = c.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Cofetarie& operator+=(Cofetarie c) {
		*this = *this + c;
		return *this;
	}

	Cofetarie& operator-=(Cofetarie c) {
		*this = *this - c;
		return *this;
	}

	Cofetarie operator+(float salariu)const {
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}


	Cofetarie operator-(float salariu)const {
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati--;
		return temp;
	}

	friend Cofetarie operator+(float salariu, Cofetarie c) {
		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < c.nrAngajati; i++) {
			temp.salarii[i] = c.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	/*friend Cofetarie operator-(float salariu, Cofetarie c) {
		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < c.nrAngajati; i++) {
			temp.salarii[i] = c.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati--;
		return temp;
	}*/

	Cofetarie operator-(int valoare) {
		Cofetarie aux = *this;
		aux.nrAngajati = this->nrAngajati - valoare;
		return aux;
	}
	friend Cofetarie operator-(int valoare, Cofetarie c) {
		Cofetarie aux = c;
		aux.nrAngajati = c.nrAngajati - valoare;
		return aux;
	}

	Cofetarie operator*(float val) {
		Cofetarie aux = *this;
		aux.adaos = this->adaos * val;
		return aux;
	}

	friend Cofetarie operator*(float val, Cofetarie c) {
		Cofetarie aux = c;
		aux.adaos = c.adaos * val;
		return aux;
	}

	/*friend Cofetarie operator*(float val, Cofetarie c) {
		float valoare = c.adaos;
	     return c*val;

	 }*/







	Cofetarie operator%(const Cofetarie& c)const {
		if (c.adaos != 0) {
			Cofetarie aux = *this;
			aux.adaos = fmod(this->adaos, c.adaos);
			return aux;
		}
		
	}

	//cofetarie c3=c1%c2; cout<< "dupa opratoril %: cofetarie 3(c1%c2) este:"; c3.afiseaza();


	Cofetarie operator*(Cofetarie c) {
		Cofetarie aux = c;
		aux.adaos = aux.adaos * this->adaos;
		return aux;
	}

	Cofetarie operator/(float val) {
		Cofetarie aux = *this;
		aux.adaos = this->adaos / val;
		return aux;
	}


	explicit operator int() {
		return this->nrAngajati;
	}

	explicit operator float() {
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s += this->salarii[i];
		}
		return s;
	}
	// operatori unari: op cu un singur operand : ++, --,!
	//ptr ++, -- exista forma prefixa si postfixa

	//forma prefixa, returnam obiectul modificat
	Cofetarie operator++() {
		this->nrAngajati++;
		return *this;
	}

	//forma postfixa, lasam obiectul modificat, dar returnam cu forma initiala!

	Cofetarie operator++(int) {
		Cofetarie copie = *this;
		this->nrAngajati++;
		return copie;
	}

	Cofetarie operator--() {//--adaos
		this->adaos--;
		return *this;
	}

	Cofetarie operator--(int) {//adaos--
		Cofetarie copie = *this;
		this->adaos--;
		return copie;
	}

	Cofetarie operator!() {
		Cofetarie copie = *this;
		copie.esteVegana = !copie.esteVegana;
		return copie;
	}

	//operator functie-() cu nr variabil de parametrii
	//salariul total
	int operator()(){
		int suma=0;
		for (int i = 0; i < this->nrAngajati; i++) {
			suma += this->salarii[i];
		}
		return suma;
	}

	//salariul total pentru primii n angajati
	int operator()(int n) {
		if (n > 0 && n < this->nrAngajati) {
			int suma = 0;
			for (int i = 0; i < n; i++) {
				suma += this->salarii[i];
			}
			return suma;
		}
		else {
			return 0;
		}
	}
	//salariul pentru intervalul de angajati (n,m)
	int operator()(int n, int m) {
		if (n > 0 && m > n && m < this->nrAngajati) {
			int suma = 0;
			for (int i = n; i < m; i++) {
				suma += this->salarii[i];
			}
			return suma;
		}
		else {
			return 0;
		}
	}

	//operator->   returneaza pointer spre obiectul asupra caruia au fost realizate modificarile sau operatiile


	Cofetarie* operator->() {
		this->adaos = 1000;
		return this;
	}


	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		cout << "Are produse vegane:" << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Adaos:" << this->adaos << endl;
		cout << "TVA:" << Cofetarie::TVA << endl;
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}
	}
	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}

	friend ostream& operator<<(ostream& output, Cofetarie c);

	friend istream& operator>>(istream& input, Cofetarie& c) {
		cout << "Nume:";
		input >> c.nume;
		cout << "Nr angajati:";
		input >> c.nrAngajati;
		if (c.salarii != NULL) {
			delete[]c.salarii;
		}
		if (c.nrAngajati > 0) {
			c.salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				cout << "Salariul " << i + 1 << ":";
				input >> c.salarii[i];
			}
		}
		else {
			c.salarii = NULL;
		}
		cout << "Are produse vegane? 1-DA; 0-NU:";
		input >> c.esteVegana;
		cout << "Adaos comercial:";
		input >> c.adaos;
		return input;
	}

	//op de comparatie ; const si & pentru a evita copierea initila a obiectelor
	

	bool operator!=(const Cofetarie& c)const {
		return this->adaos != c.adaos;
	}

	bool operator<=(const Cofetarie& c)const {
		return this->adaos <= c.adaos;

		/*if (this->adaos < c.adaos) {
			return true;
		}
		else if (this->adaos = c.adaos) {
			return true;
		}
		else { return false; }*/
	}


	bool operator<(Cofetarie c) {
		return this->nrAngajati < c.nrAngajati;
	}

	bool operator==(const Cofetarie& c) const{
		return this->adaos == c.adaos;
	}

	//operatori logici: || &&

	bool operator&&(const Cofetarie& c) const{
		return(this->adaos != 0) && (c.adaos != 0);//verifica daca sunt dif de zero, pp ca adaos e tip numeric
	}

	bool operator||(Cofetarie c) {
		return (this->adaos != 0) || (c.adaos != 0);
	}


	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
		else {
			throw "Indexul este in afara limitelor";
		}
	}

	void setAdaos(float ads) {
		if (ads > 0) {
			this->adaos = ads;
		}
	}

	float getAdaos() {
		return this->adaos;
	}
};

int Cofetarie::TVA = 9;

ostream& operator<<(ostream& output, Cofetarie c) {
	output << "Nume:" << c.nume << endl;
	output << "Nr angajati:" << c.nrAngajati << endl;
	if (c.salarii != NULL) {
		for (int i = 0; i < c.nrAngajati; i++) {
			cout << c.salarii[i] << ", ";
		}
		cout << endl;
	}
	output << "Are produse vegane:" << (c.esteVegana ? "DA" : "NU") << endl;
	output << "An deschidere:" << c.anDeschidere << endl;
	output << "Adaos:" << c.adaos << endl;
	output << "TVA:" << Cofetarie::TVA << endl;
	return output;
}



int main() {
	Cofetarie c;
	Cofetarie c2("Minimal", 3, false, 2020, 10);

	Cofetarie c3;

	cout << c2;
	cin >> c2;
	cout << endl << c2 << endl;


	/*int nrAngajati = (int)c2;
	float salariiTotale = (float)c2;

	cout << c << endl << endl;
	cout << "ob2:"<<c2 << endl;

	c2 = c++;

	cout << c2 << endl << endl;*/

	cout << "ob3:" << c2;

	c2 = ++c2;

	cout << c2;

	c = --c;
	c3 = c3--;

	c2 = !c2;
	cout << c2;

	//op functie()
	Cofetarie c5("MaraMura", 2, false, 2021, 16);
	cout << endl;
	cout << c5() << endl;
	cout << c5(2) << endl;
	cout << c5(2, 5) << endl;

	//op->
	Cofetarie c6;
	c6.setAdaos(1);
	cout << c6.getAdaos() << endl;
	cout << c6->getAdaos() << endl;

	//op*

	Cofetarie c7 = c6 * 10;

	Cofetarie c8 = 10 * c6;

	Cofetarie c9 = c8 * c7;

	if (c < c2) { //c1.operator<(c2);
		cout << "C1 este mai mic decat c2";
	}

	try {
		cout << endl << c2[1] << endl;
		cout << c2[-6];
	}
	catch (int exceptie) {

	}
	catch (float exceptie) {

	}
	catch (const char* exceptie) {
		cout << endl << exceptie << endl;
		//}
	}
	

	cout << c2[1] << endl;
	c2[1] = 2000;
	cout << c2[1] << endl;



}