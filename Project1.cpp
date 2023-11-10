#include<iostream>
#pragma warning (disable:4996)

using namespace std;

//Initale:MEC, am ales domeniul "MECANICA"

class cutieViteze {
private:
	bool esteAutomata;
	int nrRapoarte;
	string tipAmbreiaj;
	char* producator;
	const int id;
	static bool areMarsarier;
	float uleiCutie;
public:
	cutieViteze() :id(1), uleiCutie(2.4) {
		producator = new char[strlen("Renault") + 1];
		strcpy_s(producator, strlen("Renault") + 1, "Renault");
		nrRapoarte = 6;
		esteAutomata = true;
		tipAmbreiaj = "Hidraulic";
	}

	cutieViteze(int idNou, float uleiCutieNou) :id(idNou), uleiCutie(uleiCutieNou) {
		esteAutomata = true;
		producator = new char[strlen("Opel") + 1];
		strcpy_s(producator, strlen("Opel") + 1, "Opel");
		areMarsarier = true;
		tipAmbreiaj = "Mecanic";
		nrRapoarte = 7;
	}

	cutieViteze(int idNou, float uleiCutieNou, bool esteAutomataNou, int nrRapoarteNou, string tipAmbreiajNou) :id(idNou), uleiCutie(uleiCutieNou), esteAutomata(esteAutomataNou), nrRapoarte(nrRapoarteNou), tipAmbreiaj(tipAmbreiajNou) {
		producator = new char[strlen("Toyota") + 1];
		strcpy_s(producator, strlen("Toyota") + 1, "Toyota");
	}

	~cutieViteze() {
		if (nrRapoarte = !NULL) {
			delete[]this->producator;
		}
	}

	void afisare() {
		cout << "ID: " << id << " Cutia are o capacitate de " << uleiCutie << " litri ulei, fiind o cutie de tip" << (this->esteAutomata ? " automata" : " manuala") << " cu un ambreiaj de tip " << tipAmbreiaj << " , avand un numar de " << nrRapoarte << " rapoarte, fiind produsa de " << producator << "." << endl;
	};
	//get si set;



	const int getid() {
		return this->id;
	}


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

	cutieViteze(const cutieViteze& c) :id(c.id) {
		this->producator = new char[strlen(c.producator) + 1];
		strcpy(this->producator, c.producator);
		this->esteAutomata = c.esteAutomata;
		this->nrRapoarte = c.nrRapoarte;
		this->tipAmbreiaj = c.tipAmbreiaj;
		this->areMarsarier = c.areMarsarier;
		this->uleiCutie = c.uleiCutie;
	}
	
	friend string masinaSauUtilaj(bool areMarsarier);
	friend string masinaSauCamion(int nrRapoarte);

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

	friend ostream& operator<<(ostream& cutie, const cutieViteze& s) {
		cutie << "Producator: " << s.producator << endl;;
		cutie << "Numar rapoarte: " << s.nrRapoarte << endl;
		cutie << "Tip ambreiaj: " << s.tipAmbreiaj << endl;
		cutie << "Ulei cutie: " << s.uleiCutie << endl;
		cutie << (s.areMarsarier ? "Are marsarier. " : "Nu are marsarier. ") << endl;
		cutie << (s.esteAutomata ? "Este automata. " : "Este manuala. ") << endl;
		return cutie;
	}
	
	cutieViteze operator+ (const cutieViteze& rapoarte) {
		cutieViteze aux = *this;
		aux.nrRapoarte += rapoarte.nrRapoarte;
		return aux;
	}
	
	cutieViteze operator+=(const cutieViteze& k) {
		this->nrRapoarte += k.nrRapoarte;
		return *this;
	}
	
	
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
	char* producator;
	int numarPistoane;
	const int id;
	float capacitate;
	static bool esteElectric;
	int putere;
	int putere2;
	int* putere3;
	string combustibil;
public:
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

	~Motor() {
		if (capacitate = !NULL) {
			delete[]this->producator;
		}
	}

	void afisareM() {
		cout << "ID: " << id << " Motorul produs de " << producator << " are o capacitate de " << capacitate << " litri, o putere de " << putere << " cai putere, avand drept combustibil " << combustibil << (this->esteElectric ? " Nu este electric" : " Este electric") << " si avand un numar de " << numarPistoane << " pistoane." << endl;
	}
	//get si set;
	

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

	//constructor de copiere;
	/*char* producator;
	int numarPistoane;
	const int id;
	float capacitate;
	static bool esteElectric;
	int putere;
	string combustibil;*/
	Motor(const Motor& m) : id(m.id) {
		this->producator = new char[strlen(m.producator) + 1];
		strcpy(this->producator, m.producator);
		this->numarPistoane = m.numarPistoane;
		this->capacitate = m.capacitate;
		this->esteElectric = m.esteElectric;
		this->putere = m.putere;
		this->combustibil = m.combustibil;
	}
	friend float kilowati(int putere);
	friend float puterePerPiston(int putere2, int numarPistoane);

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

	friend istream& operator>>(istream& componente, Motor& c) {
		char aux[100];
		cout << "Producatorul motorului este: ";
		componente>> aux;
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
	
	Motor operator+(const Motor& a) {
		Motor aux = *this;
		aux.putere += a.putere;
		return aux;
	}
	
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
	bool tambur;
	float dimensiunePlacuta;
	char* marca;
	static int numarPlacute;
	string materialPlacute;
	int temperaturaOptimaFranare;
public:
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
	~sistemFranare() {
		if (dimensiunePlacuta = !NULL) {
			delete[]this->marca;
		}
	}

	void afisareF() {
		cout << "ID: " << id << " Sistemul de franare al masinii este compus din placutele marca " << marca << " , avand o dimensiune de " << dimensiunePlacuta << " cm, pe puntea spate fiind" << (this->tambur ? " , tambur," : " , tot placute,") << " cu un numar de " << numarPlacute << " placute in total, fiind fabricate din " << materialPlacute << "." << endl;
	}
	//get si set;
	/*const int id;
	bool tambur;
	float dimensiunePlacuta;
	char* marca;
	static int numarPlacute;
	string materialPlacute;*/

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


	const int getid() {
		return this->id;
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
	/*const int id;
	bool tambur;
	float dimensiunePlacuta;
	char* marca;
	static int numarPlacute;
	string materialPlacute;*/
	sistemFranare(const sistemFranare& f) :id(f.id) {
		this->tambur = f.tambur;
		this->dimensiunePlacuta = f.dimensiunePlacuta;
		this->numarPlacute = f.numarPlacute;
		this->materialPlacute = f.materialPlacute;
		this->marca = new char[strlen(f.marca) + 1];
		strcpy(this->marca, f.marca);
	}

	friend int calculeazaNumarPlacute(sistemFranare& sistem);
	friend string temperaturaOptima(int temperaturaOptimaFranare);

	friend ostream& operator<<(ostream& sistem, const sistemFranare& s) {
		cout << "Producatorul sistemului de franare este: " << s.marca << endl;
		cout << (s.tambur ? "Are placute pe puntea spate." : "Are tambur pe punte spate.") << endl;
		cout << "Dimensiune placuta: " << s.dimensiunePlacuta<<" centimetri."<<endl;
		cout << "Numar placute: " << s.numarPlacute<<endl;
		cout << "Material placute: " << s.materialPlacute << endl;
		cout << "Temperatura optima de franare este: " << s.temperaturaOptimaFranare << " grade celsius." << endl;
		return sistem;
	}

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

	sistemFranare operator+(const sistemFranare& l) {
		sistemFranare aux = *this;
		this->dimensiunePlacuta += l.dimensiunePlacuta;
		return aux;
	}

	sistemFranare operator+=(const sistemFranare& n) {
		this->dimensiunePlacuta += n.dimensiunePlacuta;
		return *this;
	}
};
int sistemFranare::numarPlacute = 0;
//functie globala
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
	//cutie
	char* prod;
	prod = new char[strlen("Mercedes") + 1];
	strcpy_s(prod, strlen("Mercedes") + 1, "Mercedes");

	cutieViteze cutieViteze1;
	cutieViteze1.afisare();

	cutieViteze cutieViteze2(2, 3.9);
	cutieViteze2.afisare();

	cutieViteze cutieViteze3(3, 3.3, false, 7, "Mecanic");
	cutieViteze3.afisare();

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
	cout << "Producator: " << cutieViteze1.getProducator() << endl;

	cout << " " << endl;
	cout << "Functii globale " << endl;
	cout << " " << endl;

	string mesaj = masinaSauUtilaj(cutieViteze1.getareMarsarier());
	cout << mesaj << endl;

	string masinasaucamion = masinaSauCamion(cutieViteze1.getnrRapoarte());
	cout << masinasaucamion << endl;




	cout << " " << endl;
	//motor
	Motor motor1;
	motor1.afisareM();

	Motor motor2(2, 2.5, 200, "Diesel+Energie");
	motor2.afisareM();

	Motor motor3(3, 0, 500, "Energie", 0);
	motor3.afisareM();

	cout << " " << endl;

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

	motor1.setputere2(240);
	cout << "Putere2: " << motor1.getputere2() << endl;

	cout << " " << endl;
	cout << "Functii globale " << endl;
	cout << " " << endl;

	int putere = motor1.getputere();
	float putereKW = kilowati(putere);
	cout << "Putere in kilowati ora: " << putereKW << " kW" << endl;

	int putere2 = motor1.getputere2();
	int numarPistoane = motor1.getnumarPistoane();
	float puterePiston = puterePerPiston(putere2, numarPistoane);
	cout << "Putere per piston: " << puterePiston << " cp" << endl;

	cout << " " << endl;


	//franare
	char* marcaNou;
	marcaNou = new char[strlen("BMW") + 1];
	strcpy_s(marcaNou, strlen("BMW") + 1, "BMW");

	sistemFranare sistem1;
	sistem1.afisareF();

	sistemFranare sistem2(2, 10.5);
	sistem2.afisareF();

	sistemFranare sistem3(3, 11.3, " ceramica", false);
	sistem3.afisareF();

	cout << " " << endl;

	sistem1.setdimensiunePlacuta(10.3);
	cout << "Dimensiune placuta: " << sistem1.getdimensiunePlacuta() << endl;

	sistem1.setMarca(marcaNou);
	cout << "Producator: " << sistem1.getMarca() << endl;

	sistem1.setmaterialPlacute("ceramica");
	cout << "Material placute: " << sistem1.getmaterialPlacute() << endl;

	sistem1.setnumarPlacute(8);
	cout << "Numar placute: " << sistem1.getnumarPlacute() << endl;

	sistem1.settambur(false);
	cout << "Nu are(0)/Are(1): " << sistem1.gettambur() << endl;

	sistem1.settempertatura(160);
	cout << "Temperatura optima de franare este de: " << sistem1.gettemperatura() << " grade celsius." << endl;

	cout << " " << endl;
	cout << "Functii globale " << endl;
	cout << " " << endl;

	int existaNumarPlacute = calculeazaNumarPlacute(sistem1);
	cout << "Numar placute pe toata masina: " << existaNumarPlacute << endl;//daca rezultatul este 8, inseamna ca masina nu are tamburi, adica are 2 placute pe roata * 4 roti, iar daca rezultatul este 4, masina are tamburi, iar numarul de placute pe roata este 2 * 2 numarul de roti

	string temperatura = temperaturaOptima(sistem1.gettemperatura());
	cout << temperatura << endl;
	/*operatori cutieViteze:*/
	cout << " " << endl;
	cout << "Operatorul<< CUTIE" << endl;
	cout << cutieViteze1;

	cout << " " << endl;
	cout << "Operatorul>> CUTIE" << endl;
	cin >> cutieViteze1;

	cout << " " << endl;
	cout << "Operatorul+ CUTIE" << endl;
	cutieViteze rez = cutieViteze1 + cutieViteze2;
	cout << "Suma rapoartelor celor doua cutii este: " << rez.getnrRapoarte() << endl;

	cout << " " << endl;
	cout << "Operatorul+= CUTIE" << endl;
	cutieViteze3 += cutieViteze2;
	cout << "Numarul rapoartelor dupa adunare: " << cutieViteze3.getnrRapoarte() << endl;

	//operatori Motor:
	cout << " " << endl;
	cout << "Operatorul<< MOTOR" << endl;
	cout << motor1;

	cout << " " << endl;
	cout << "Operatorul>> MOTOR" << endl;
	cin >> motor1;

	cout << " " << endl;
	cout << "Operatorul+ MOTOR" << endl;
	Motor rezultat = motor1 + motor2;
	cout << "Suma puterilor celor doua motoare: " << rezultat.getputere() << " cai putere." << endl;

	cout << " " << endl;
	cout << "Operatorul+= MOTOR" << endl;
	motor2 += motor3;
	cout << "Puterea motorului dupa adunare: " << motor2.getputere()<<" cai putere." << endl;

	//operatori sistemFranare:

	cout << " " << endl;
	cout << "Operatorul<< FRANARE" << endl;
	cout << sistem1;

	cout << " " << endl;
	cout << "Operatorul>> FRANARE" << endl;
	cin >> sistem1;

	cout << " " << endl;
	cout << "Operatorul+ FRANARE" << endl;
	sistemFranare rezultatt = sistem2 + sistem1;
	cout << "Rezultatul adunarii celor doua dimensiuni ale placutelor este: " << rezultatt.getdimensiunePlacuta() << " centimetri." << endl;

	cout << " " << endl;
	cout << "Operatorul+= FRANARE" << endl;
	sistem3 += sistem1;
	cout << "Dimensiunea dupa adunare: " << sistem3.getdimensiunePlacuta() << endl;
}