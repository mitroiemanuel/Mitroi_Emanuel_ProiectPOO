#include<iostream>
#pragma warning (disable:4996)

using namespace std;

//Initiale: MEC, am ales domeniul "MECANICA"

class cutieViteze {
private:
	const int id;
	int nrRapoarte;
	float uleiCutie;
	bool esteAutomata;
	static bool areMarsarier;
	char* producator;
	string tipAmbreiaj;
public:
	//constructori
	cutieViteze() :id(1), uleiCutie(2.4) {
		producator = new char[strlen("Renault") + 1];
		strcpy_s(producator, strlen("Renault") + 1, "Renault");
		nrRapoarte = 6;
		esteAutomata = true;
		areMarsarier = true;
		tipAmbreiaj = "hidraulic";
	}

	cutieViteze(int idNou, float uleiCutieNou) :id(idNou), uleiCutie(uleiCutieNou) {
		esteAutomata = true;
		producator = new char[strlen("Opel") + 1];
		strcpy_s(producator, strlen("Opel") + 1, "Opel");
		tipAmbreiaj = "mecanic";
		nrRapoarte = 7;
	}

	cutieViteze(float uleiCutieNou, bool esteAutomataNou, int nrRapoarteNou, string tipAmbreiajNou) :id(3), uleiCutie(uleiCutieNou), esteAutomata(esteAutomataNou), nrRapoarte(nrRapoarteNou), tipAmbreiaj(tipAmbreiajNou) {
		producator = new char[strlen("Toyota") + 1];
		strcpy_s(producator, strlen("Toyota") + 1, "Toyota");
	}

	//destructor
	~cutieViteze() {
		if (producator != NULL) {
			delete[]this->producator;
		}
	}

	//mesajul de afisare
	void afisare() {
		//cout << "ID: " << id << " Cutia are o capacitate de " << uleiCutie << " litri ulei, fiind o cutie de tip" << (this->esteAutomata ? " automata" : " manuala") << (this->areMarsarier ? ", avand marsarier,":", neavand marsarier,") << " cu un ambreiaj de tip " << tipAmbreiaj << " , avand un numar de " << nrRapoarte << " rapoarte, fiind produsa de " << producator << "." << endl;
		cout << "ID:" << id << " Cutia de viteze produsa de " << producator << " are o capacitate de " << uleiCutie << " litri ulei, fiind o cutie de tip " << (this->esteAutomata ? " automata" : " manuala") << (this->areMarsarier ? ", avand marsarier," : ", neavand marsarier,") << " cu un ambreiaj de tip " << tipAmbreiaj << " , avand un numar de " << nrRapoarte << " rapoarte." << endl;
	};

	//get si set

	bool getesteAutomata() {
		return esteAutomata;
	}

	void setesteAutomata(bool esteAutomata) {
		this->esteAutomata = esteAutomata;
	}

	int getnrRapoarte() {
		return nrRapoarte;
	}

	void setnrRapoarte(int nrRapoarte) {
		if (nrRapoarte > 0) {
			this->nrRapoarte = nrRapoarte;
		}
	}

	string gettipAmbreiaj() {
		return tipAmbreiaj;
	}

	void settipAmbreiaj(string tipAmbreiaj) {
		if (tipAmbreiaj.length() > 0) {
			this->tipAmbreiaj = tipAmbreiaj;
		}
	}

	float getuleiCutie() {
		return uleiCutie;
	}

	void setuleiCutie(float uleiCutie) {
		if (uleiCutie > 2) {
			this->uleiCutie = uleiCutie;
		}
	}

	static bool getareMarsarier() {
		return cutieViteze::areMarsarier;
	}

	static void setareMarsarier(bool da) {
		cutieViteze::areMarsarier = da;
	}

	char* getProducator() {
		return producator;
	}

	void setProducator(char* prod) {
		if (prod != NULL) {
			delete[]producator;
		}
		producator = new char[strlen(prod) + 1];
		strcpy_s(producator, strlen(prod) + 1, prod);
	}

	//constructorul de copiere.

	cutieViteze(const cutieViteze& c) : id(c.id) {
		this->producator = new char[strlen(c.producator) + 1];
		strcpy_s(this->producator, strlen(c.producator) + 1, c.producator);
		this->esteAutomata = c.esteAutomata;
		this->nrRapoarte = c.nrRapoarte;
		this->tipAmbreiaj = c.tipAmbreiaj;
		this->areMarsarier = c.areMarsarier;
		this->uleiCutie = c.uleiCutie;
	}

	//operatorul =
	cutieViteze& operator=(const cutieViteze& aux) {
		delete[]producator;
		this->producator = new char[strlen(aux.producator) + 1];
		strcpy(this->producator, aux.producator);
		this->esteAutomata = aux.esteAutomata;
		this->nrRapoarte = aux.nrRapoarte;
		this->tipAmbreiaj = aux.tipAmbreiaj;
		this->areMarsarier = aux.areMarsarier;
		this->uleiCutie = aux.uleiCutie;

		return *this;
	}

	//operator>>
	friend istream& operator>>(istream& masina, cutieViteze& c) {
		char aux[100];
		cout << "Producatorul cutiei este: ";
		masina >> aux;
		if (c.producator != NULL) {
			delete[]c.producator;
		}
		c.producator = new char[strlen(aux) + 1];
		strcpy_s(c.producator, strlen(aux) + 1, aux);
		cout << "Ulei cutie (litri): ";
		masina >> c.uleiCutie;
		cout << "Numar rapoarte: ";
		masina >> c.nrRapoarte;
		cout << "Are marsarier 0-Nu, 1-Da: ";
		masina >> c.areMarsarier;
		cout << "Tip ambreiaj: ";
		masina >> c.tipAmbreiaj;
		cout << "Este automata 0-Nu, 1-Da: ";
		masina >> c.esteAutomata;


		return masina;
	}

	//operator<<
	friend ostream& operator<<(ostream& cutie, const cutieViteze& s) {
		cutie << "Producator: " << s.producator << endl;;
		cutie << "Numar rapoarte: " << s.nrRapoarte << endl;
		cutie << "Tip ambreiaj: " << s.tipAmbreiaj << endl;
		cutie << "Ulei cutie: " << s.uleiCutie << endl;
		cutie << (s.areMarsarier ? "Are marsarier. " : "Nu are marsarier. ") << endl;
		cutie << (s.esteAutomata ? "Este automata. " : "Este manuala. ") << endl;
		return cutie;
	}

	//operator+
	cutieViteze operator+ (const cutieViteze& rapoarte) {
		cutieViteze aux = *this;
		aux.nrRapoarte += rapoarte.nrRapoarte;
		return aux;
	}

	//functiile globale
	friend string masinaSauUtilaj(bool areMarsarier);
	friend string masinaSauCamion(int nrRapoarte);

};
bool cutieViteze::areMarsarier = true;

string masinaSauUtilaj(bool areMarsarier) {
	if (areMarsarier) {
		return "Are marsarier, este masina!";
	}
	else {
		return "Nu are marsarier, este utilaj!";
	}
}

string masinaSauCamion(int nrRapoarte) {
	if (nrRapoarte > 10) {
		return "Este camion, nu masina!";
	}
	else {
		return "Este masina, nu camion!";
	}
}

class Motor {
private:
	const int id;
	int numarPistoane;
	int putere;
	int putere2;
	char* producator;
	static bool esteElectric;
	float capacitate;
	string combustibil;
public:
	//constructorii
	Motor() :id(1), capacitate(1.6), putere(112) {
		producator = new char[strlen("Renault") + 1];
		strcpy_s(producator, strlen("Renault") + 1, "Renault");
		combustibil = "benzina";
		esteElectric = false;
		numarPistoane = 4;
	}

	Motor(int idNou, float capacitateNou, int putereNou, string combustibilNou) :id(idNou), capacitate(capacitateNou), putere(putereNou), combustibil(combustibilNou) {
		producator = new char[strlen("BMW") + 1];
		strcpy_s(producator, strlen("BMW") + 1, "BMW");
		esteElectric = true;
		numarPistoane = 6;
	}

	Motor(int idNou, float capacitateNou, int putereNou, string combustibilNou, int numarPistoaneNou) : id(idNou), capacitate(capacitateNou), putere(putereNou), combustibil(combustibilNou), numarPistoane(numarPistoaneNou) {
		producator = new char[strlen("Tesla") + 1];
		strcpy_s(producator, strlen("Tesla") + 1, "Tesla");
		esteElectric = true;
	}

	//destructorul
	~Motor() {
		if (producator != NULL) {
			delete[]this->producator;
		}
	}

	//mesajul de afisare
	void afisareM() {
		cout << "ID:" << id << " Motorul produs de " << producator << " are o capacitate de " << capacitate << " litri, o putere de " << putere << " cai putere, avand drept combustibil " << combustibil << (this->esteElectric ? " este electric/hibrid" : " nu este electric") << " si avand un numar de " << numarPistoane << " pistoane." << endl;
	}

	//get si set
	int getputere2() {
		return putere2;
	}

	void setputere2(int putere2) {
		if (putere2 > 0) {
			this->putere2 = putere2;
		}
	}


	const int getid() {
		return this->id;
	}


	char* getproducator() {
		return producator;
	}

	void setproducator(char* prod) {
		if (prod != NULL) {
			delete[]producator;
		}
		producator = new char[strlen(prod) + 1];
		strcpy_s(producator, strlen(prod) + 1, prod);
	}


	int getnumarPistoane() {
		return numarPistoane;
	}

	void setnumarPistoane(int nrPistoane) {
		if (numarPistoane > 0) {
			this->numarPistoane = nrPistoane;
		}
	}


	float getcapacitate() {
		return capacitate;
	}

	void setcapacitate(float capacitate) {
		if (capacitate > 0) {
			this->capacitate = capacitate;
		}
	}


	static bool getesteElectric() {
		return Motor::esteElectric;
	}

	static void setesteElectric(bool da) {
		Motor::esteElectric = da;
	}


	int getputere() {
		return putere;
	}

	void setputere(int putere) {
		if (putere > 0) {
			this->putere = putere;
		}
	}


	string getcombustibil() {
		return combustibil;
	}

	void setcombustibil(string comb) {
		if (comb.length() > 0) {
			this->combustibil = comb;
		}
	}

	//constructor de copiere
	Motor(const Motor& m) :id(m.id) {
		this->producator = new char[strlen(m.producator) + 1];
		strcpy(this->producator, m.producator);
		this->numarPistoane = m.numarPistoane;
		this->capacitate = m.capacitate;
		this->esteElectric = m.esteElectric;
		this->putere = m.putere;
		this->combustibil = m.combustibil;
	}

	//operator=
	Motor& operator=(const Motor& aux) {
		delete[]producator;
		producator = new char[strlen(aux.producator) + 1];
		strcpy(producator, aux.producator);
		this->numarPistoane = aux.numarPistoane;
		this->capacitate = aux.capacitate;
		this->esteElectric = aux.esteElectric;
		this->putere = aux.putere;
		this->combustibil = aux.combustibil;

		return *this;
	}

	//functii globale friend
	friend float kilowati(int putere);
	friend float puterePerPiston(int putere2, int numarPistoane);

	//operator<<
	friend ostream& operator<<(ostream& motor, const Motor& m) {
		motor << "Producatorul este: " << m.producator << endl;
		motor << "Numarul de pistoane: " << m.numarPistoane << endl;
		motor << "Capacitatea este de: " << m.capacitate << " centimetri cubi." << endl;
		/*motor << "Este electric (0-Nu, 1-Da): " << m.esteElectric << endl;*/
		motor << (m.esteElectric ? "Este pe combustibil." : "Este electric.") << endl;
		motor << "Are o putere de: " << m.putere << " cai putere." << endl;
		motor << "Combustibil: " << m.combustibil << endl;
		return motor;
	}

	//operator>>
	friend istream& operator>>(istream& componente, Motor& c) {
		char aux[100];
		cout << "Producatorul motorului este: ";
		componente >> aux;
		if (c.producator != NULL) {
			delete[]c.producator;
		}
		c.producator = new char[strlen(aux) + 1];
		strcpy_s(c.producator, strlen(aux) + 1, aux);
		cout << "Numarul de pistoane: ";
		componente >> c.numarPistoane;
		cout << "Capacitatea clinidrica este: ";
		componente >> c.capacitate;
		cout << "Este electric(0-Nu,1-Da):";
		componente >> c.esteElectric;
		cout << "Are o putere de: ";
		componente >> c.putere;
		cout << "Tipul combustibilului: ";
		componente >> c.combustibil;
		return componente;
	}

	//operator+=
	Motor operator+=(const Motor& b) {
		this->putere += b.putere;
		return *this;
	}
};
bool Motor::esteElectric = 0;

//functie globala
float kilowati(int putere) {
	float putereKW = putere * 0.7457;//1cp=0.7457kwh
	return putereKW;
}

float puterePerPiston(int putere2, int numarPistoane) {
	if (numarPistoane > 0) {
		float puterePiston = putere2 / numarPistoane;
		return puterePiston;
	}
}

class sistemFranare {
private:
	const int id;
	int temperaturaOptimaFranare;
	static int numarPlacute;
	float dimensiunePlacuta;
	bool tambur;
	char* marca;
	string materialPlacute;
public:
	//constructori
	sistemFranare() :id(1), tambur(false), materialPlacute("ceramica") {
		marca = new char[strlen("ATE") + 1];
		strcpy_s(marca, strlen("ATE") + 1, "ATE");
		numarPlacute = 8;
		dimensiunePlacuta = 10.2;
	}
	sistemFranare(int idNou, float dimensiunePlacutaNou) : id(idNou), dimensiunePlacuta(dimensiunePlacutaNou) {
		marca = new char[strlen("Textar") + 1];
		strcpy_s(marca, strlen("Textar") + 1, "Textar");
		numarPlacute = 4;
		tambur = true;
		materialPlacute = "metal";
	}
	sistemFranare(int idNou, float dimensiunePlacutaNou, string materialPlacuteNou, bool tamburNou) : id(idNou), dimensiunePlacuta(dimensiunePlacutaNou), materialPlacute(materialPlacuteNou), tambur(tamburNou) {
		marca = new char[strlen("BOSCH") + 1];
		strcpy_s(marca, strlen("BOSCH") + 1, "BOSCH");
		numarPlacute = 8;
	}

	//destructor
	~sistemFranare() {
		if (marca != NULL) {
			delete[]this->marca;
		}
	}

	void afisareF() {
		cout << "ID:" << id << " Sistemul de franare al masinii este compus din placutele marca " << marca << ", avand o dimensiune de " << dimensiunePlacuta << " centimetri, pe puntea spate fiind " << (this->tambur ? " tambur" : " disc de frana") << ", avand un numar de " << numarPlacute << " placute in total, materialul fiind " << materialPlacute << "." << endl;
	}

	//get si set

	const int getid() {
		return this->id;
	}

	int gettemperatura() {
		return temperaturaOptimaFranare;
	}

	void settempertatura(int temperatura) {
		if (temperatura > 0) {
			this->temperaturaOptimaFranare = temperatura;
		}
	}

	static int getnumarPlacute() {
		return sistemFranare::numarPlacute;
	}

	static void setnumarPlacute(int numar) {
		if (numar > 0) {
			sistemFranare::numarPlacute = numar;
		}
	}

	string getmaterialPlacute() {
		return materialPlacute;
	}

	void setmaterialPlacute(string material) {
		if (material.length() > 0) {
			this->materialPlacute = material;
		}
	}

	bool gettambur() {
		return tambur;
	}

	void settambur(bool da) {
		tambur = da;
	}

	float getdimensiunePlacuta() {
		return dimensiunePlacuta;
	}

	void setdimensiunePlacuta(float dimP) {
		if (dimP > 0) {
			this->dimensiunePlacuta = dimP;
		}
	}

	char* getMarca() {
		return marca;
	}

	void setMarca(char* marcaa) {
		if (marcaa != NULL) {
			delete[]marca;
		}
		marca = new char[strlen(marcaa) + 1];
		strcpy_s(marca, strlen(marcaa) + 1, marcaa);
	}

	//constructor de copiere;
	sistemFranare(const sistemFranare& f) :id(f.id) {
		this->tambur = f.tambur;
		this->dimensiunePlacuta = f.dimensiunePlacuta;
		this->numarPlacute = f.numarPlacute;
		this->materialPlacute = f.materialPlacute;
		this->marca = new char[strlen(f.marca) + 1];
		this->temperaturaOptimaFranare = f.temperaturaOptimaFranare;
		strcpy(this->marca, f.marca);
	}



	//functii globale friend
	friend int calculeazaNumarPlacute(sistemFranare& sistem);
	friend string temperaturaOptima(int temperaturaOptimaFranare);

	//operator<<
	friend ostream& operator<<(ostream& sistem, const sistemFranare& s) {
		cout << "Producatorul sistemului de franare este: " << s.marca << endl;
		cout << (s.tambur ? "Are placute pe puntea spate." : "Are tambur pe punte spate.") << endl;
		cout << "Dimensiune placuta: " << s.dimensiunePlacuta << " centimetri." << endl;
		cout << "Numar placute: " << s.numarPlacute << endl;
		cout << "Material placute: " << s.materialPlacute << endl;
		cout << "Temperatura optima de franare este: " << s.temperaturaOptimaFranare << " grade celsius." << endl;
		return sistem;
	}
	//operator=
	sistemFranare& operator=(const sistemFranare& aux) {
		delete[]marca;
		marca = new char[strlen(aux.marca) + 1];
		strcpy(this->marca, aux.marca);
		dimensiunePlacuta = aux.dimensiunePlacuta;
		temperaturaOptimaFranare = aux.temperaturaOptimaFranare;
		tambur = aux.tambur;
		materialPlacute = aux.materialPlacute;
		numarPlacute = aux.numarPlacute;

		return *this;
	}

	//opertor>>
	friend istream& operator>>(istream& franare, sistemFranare& f) {
		char aux[100];
		cout << "Producatorul sistemului de franare este: ";
		franare >> aux;
		if (f.marca != NULL) {
			delete[]f.marca;
		}
		f.marca = new char[strlen(aux) + 1];
		strcpy_s(f.marca, strlen(aux) + 1, aux);
		cout << "Are tambur pe puntea spate(0-Nu, 1-Da): ";
		franare >> f.tambur;
		cout << "Dimensiune placuta (cm): ";
		franare >> f.dimensiunePlacuta;
		cout << "Numar placute: ";
		franare >> f.numarPlacute;
		cout << "Material placute: ";
		franare >> f.materialPlacute;
		cout << "Temperatura optima de franare (grade celsius): ";
		franare >> f.temperaturaOptimaFranare;
		return franare;
	}

	//operator+
	sistemFranare operator+(const sistemFranare& l) {
		sistemFranare aux = *this;
		this->dimensiunePlacuta += l.dimensiunePlacuta;
		return aux;
	}

	//operator+=
	sistemFranare operator+=(const sistemFranare& n) {
		this->dimensiunePlacuta += n.dimensiunePlacuta;
		return *this;
	}

};
int sistemFranare::numarPlacute = 0;
//functii globale
int calculeazaNumarPlacute(sistemFranare& sistem) {
	int numarPlacute = sistem.getnumarPlacute();
	bool tambur = sistem.gettambur();
	int existaNrPlacute;
	if (tambur) {
		existaNrPlacute = numarPlacute / 2;
	}
	else {
		existaNrPlacute = numarPlacute;
	}

	return existaNrPlacute;
}

string temperaturaOptima(int temperaturaOptimaFranare) {
	if (temperaturaOptimaFranare > 150) {
		return "Placutele sunt fabricate din ceramica!";
	}
	else {
		return "Placutele sunt fabricate din metal";
	}
}
void main() {
	char* prod;
	prod = new char[strlen("Mercedes") + 1];
	strcpy_s(prod, strlen("Mercedes") + 1, "Mercedes");

	cout << "========================CLASA CUTIE DE VITEZE======================" << endl << endl;
	cutieViteze cutieViteze1;
	cutieViteze cutieViteze2(2, 3.2);
	cutieViteze	cutieViteze3(2.9, false, 7, "mecanic");
	cutieViteze1.afisare();
	cutieViteze2.afisare();
	cutieViteze3.afisare();
	cout << "" << endl;
	//apelare constructor copiere

	cout << "======Constructor de copiere=======" << endl;
	cutieViteze cutieViteze4 = cutieViteze2;
	cutieViteze4.afisare();

	//operator=
	cout << "" << endl;
	cout << "========Operator(=)========" << endl;
	cutieViteze cutieviteze5;
	cutieviteze5 = cutieViteze3;
	cutieviteze5.afisare();

	//operator<<
	cout << "" << endl;
	cout << "========Operator<<========" << endl;
	cout << cutieViteze2;
	cout << "" << endl;

	//operator+
	cout << " " << endl;
	cout << "========Operator+========" << endl;
	cutieViteze rez = cutieViteze1 + cutieViteze2;
	cout << "Suma rapoartelor celor doua cutii este: " << rez.getnrRapoarte() << endl << endl;

	//operator>>
	cout << "" << endl;
	cout << "========Operator>>========" << endl;
	cin >> cutieviteze5;

	//vector

	cout << "=======Vector de obiecte=======" << endl << endl;
	cutieViteze* cutie = new cutieViteze[3];
	cutie[0] = cutieViteze1;
	cutie[1] = cutieViteze2;
	cutie[2] = cutieViteze3;
	for (int i = 0; i < 3; i++) {
		cout << cutie[i] << endl << endl;
	}
	delete[]cutie;

	cout << "========SET SI GET========" << endl;
	cout << " " << endl;

	cutieViteze1.setesteAutomata(false);
	cout << "Manuala(0)/Automata(1): " << cutieViteze1.getesteAutomata() << endl;

	cutieViteze1.setnrRapoarte(8);
	cout << "Numar rapoarte: " << cutieViteze1.getnrRapoarte() << endl;

	cutieViteze1.setareMarsarier(true);
	cout << "Are marsarier: " << cutieViteze1.getareMarsarier() << endl;

	cutieViteze1.settipAmbreiaj("Mecanic");
	cout << "Tip ambreiaj: " << cutieViteze1.gettipAmbreiaj() << endl;

	cutieViteze1.setuleiCutie(3.8);
	cout << "Capacitate ulei cutie: " << cutieViteze1.getuleiCutie() << endl;

	cutieViteze1.setProducator(prod);
	cout << "Producator: " << cutieViteze1.getProducator() << endl << endl;

	cout << "========FUNCTII GLOBALE=======" << endl;

	string mesaj = masinaSauUtilaj(cutieViteze1.getareMarsarier());
	cout << mesaj << endl << endl;

	string masinasaucamion = masinaSauCamion(cutieViteze1.getnrRapoarte());
	cout << masinasaucamion << endl << endl;
	//=====================================================================================================================================================================================
	cout << "======================CLASA MOTOR==========================" << endl << endl;

	Motor motor1;
	Motor motor2(2, 2.5, 200, "Benzina+Energie");
	Motor motor3(3, 0, 500, "Energie", 0);
	motor1.afisareM();
	motor2.afisareM();
	motor3.afisareM();
	cout << "" << endl;

	//constructor de copiere
	cout << "======Constructor de copiere=======" << endl;
	Motor motor4 = motor3;
	motor4.afisareM();

	//operator=
	cout << "" << endl;
	cout << "========Operator(=)========" << endl;
	motor1 = motor3;
	motor1.afisareM();

	//operator<<
	cout << "" << endl;
	cout << "=======OPERATOR<<========" << endl;
	cout << motor1;

	//operator>>
	cout << " " << endl;
	cout << "=======OPERATOR>>======" << endl;
	cin >> motor1;

	//operator+=
	cout << "=======OPERATOR(+=) ======" << endl;
	motor2 += motor3;
	cout << "Puterea motorului dupa adunare: " << motor2.getputere() << " cai putere." << endl << endl;


	cout << "=======Vector de obiecte=======" << endl << endl;
	Motor* _motor = new Motor[3];
	_motor[0] = motor1;
	_motor[1] = motor2;
	_motor[2] = motor3;
	for (int i = 0; i < 3; i++) {
		cout << _motor[i] << endl << endl;
	}
	delete[]_motor;

	cout << " " << endl;
	//set si get motor
	cout << "========SET SI GET========" << endl;
	motor1.setcapacitate(2500);
	cout << "Capacitatea motorului este: " << motor1.getcapacitate() << endl;

	motor1.setcombustibil("benzina");
	cout << "Combustibil: " << motor1.getcombustibil() << endl;

	motor1.setesteElectric(false);
	cout << "Combustibil(0)/Electric(1): " << motor1.getesteElectric() << endl;

	motor1.setnumarPistoane(6);
	cout << "Numar pistoane: " << motor1.getnumarPistoane() << endl;

	motor1.setproducator(prod);
	cout << "Producator: " << motor1.getproducator() << endl;

	motor1.setputere(204);
	cout << "Putere: " << motor1.getputere() << endl;

	cout << "Functii globale " << endl << endl;

	//apelare functii globale
	cout << "========FUNCTII GLOBALE=======" << endl;
	int putere = motor1.getputere();
	float putereKW = kilowati(putere);
	cout << "Putere in kilowati ora: " << putereKW << " kW" << endl;

	int putere2 = motor1.getputere2();
	int numarPistoane = motor1.getnumarPistoane();
	float puterePiston = puterePerPiston(putere2, numarPistoane);
	cout << "Putere per piston: " << puterePiston << " cp" << endl << endl;

	//====================================================================================================================================================================
	cout << "===================CLASA SISTEM DE FRANARE====================" << endl << endl;
	char* marcaNou;
	marcaNou = new char[strlen("BMW") + 1];
	strcpy_s(marcaNou, strlen("BMW") + 1, "BMW");

	sistemFranare sistem1;
	sistemFranare sistem2(2, 10.5);
	sistemFranare sistem3(3, 11.3, " ceramica", false);
	sistem1.afisareF();
	sistem2.afisareF();
	sistem3.afisareF();
	//constructor de copiere
	cout << "======Constructor de copiere=======" << endl;
	sistemFranare sistem4;
	sistem4 = sistem3;
	sistem4.afisareF();

	//operator=
	cout << "" << endl;
	cout << "========Operator(=)========" << endl;
	sistem1 = sistem2;
	sistem1.afisareF();

	//operator<<
	cout << "" << endl;
	cout << "=======OPERATOR<<========" << endl;
	cout << sistem3;
	//operator>>
	cout << " " << endl;
	cout << "=======OPERATOR>>======" << endl;
	cin >> sistem2;

	//operator+=
	cout << "=======OPERATOR(+=) ======" << endl;
	sistem3 += sistem1;
	cout << "Dimensiunea dupa adunare: " << sistem3.getdimensiunePlacuta() << endl << endl;

	cout << "=======Vector de obiecte=======" << endl << endl;
	/*Motor* _motor = new Motor[3];
	_motor[0] = motor1;
	_motor[1] = motor2;
	_motor[2] = motor3;
	for (int i = 0; i < 3; i++) {
		cout << _motor[i] << endl << endl;
	}
	delete[]_motor;*/

	sistemFranare* _sistem = new sistemFranare[3];
	_sistem[0] = sistem1;
	_sistem[1] = sistem2;
	_sistem[2] = sistem3;
	for (int i = 0; i < 3; i++) {
		cout << _sistem[i] << endl << endl;
	}
	delete[]_sistem;

	cout << "========SET SI GET========" << endl; cout << " " << endl;

	sistem1.setdimensiunePlacuta(10.3);
	cout << "Dimensiune placuta: " << sistem1.getdimensiunePlacuta() << endl;

	sistem1.setMarca(marcaNou);
	cout << "Producator: " << sistem1.getMarca() << endl;

	sistem1.setmaterialPlacute("ceramica");
	cout << "Material placute: " << sistem1.getmaterialPlacute() << endl;

	sistem1.setnumarPlacute(8);
	cout << "Numar placute: " << sistem1.getnumarPlacute() << endl;

	sistem1.settambur(false);
	cout << "Tambur - Nu are(0)/Are(1): " << sistem1.gettambur() << endl;

	sistem1.settempertatura(160);
	cout << "Temperatura optima de franare este de: " << sistem1.gettemperatura() << " grade celsius." << endl << endl;

	cout << "===========FUNCTII GLOBALE==============" << endl << endl;

	int existaNumarPlacute = calculeazaNumarPlacute(sistem1);
	cout << "Numar placute pe toata masina: " << existaNumarPlacute << endl;//daca rezultatul este 8, inseamna ca masina nu are tamburi, adica are 2 placute pe roata * 4 roti, iar daca rezultatul este 4, masina are tamburi, iar numarul de placute pe roata este 2 * 2 numarul de roti

	string temperatura = temperaturaOptima(sistem1.gettemperatura());
	cout << temperatura << endl << endl;
}
