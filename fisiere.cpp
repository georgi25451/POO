#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//FISIERE TEXT SI FISIERE BINARE:
enum TipMagazin {
	MagazinHaine = 10, MagazinAlimentar = 20, MagazinElectronic = 30
};


class Magazin {

	const int codCAEN;
	const int idMagazin;
	static float procentTVA;
	static int contor;
protected:

	string nume;
	char* adresa;
	TipMagazin tip;
	int nrAngajati;
	float suprafata;
	int nrProduse;
	string* denumireProduse;
	float* pretProduse;
	bool esteNonStop;
public:
	Magazin(/*nu avem parametrii*/) :codCAEN(1000), idMagazin(contor++) {

		this->nume = "Necunoscut";
		this->adresa = new char[strlen("Strada Anonima") + 1];//+1 este pentru terminatorul de sir --> '/0'
		strcpy(this->adresa, "Strada Anonima");
		this->nrAngajati = 0;
		this->tip = MagazinAlimentar;
		this->suprafata = 0;
		this->nrProduse = 0;
		this->denumireProduse = NULL;
		this->pretProduse = NULL;
		this->esteNonStop = false;
	}
	Magazin(int codCAEN, string nume, const char* adresa, TipMagazin tip, int nrAngajati, float suprafata, int nrProduse, string* denumireProduse,
		float* pretProduse, bool esteNonStop) :codCAEN(codCAEN), idMagazin(contor++) {
		this->nume = nume;
		this->adresa = new char[strlen(adresa) + 1];//+1 este pentru terminatorul de sir --> '/0'
		strcpy(this->adresa, adresa);
		this->tip = tip;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->nrProduse = nrProduse;
		this->denumireProduse = new string[this->nrProduse];//asa alocam spatiu pentru vector
		for (int i = 0; i < this->nrProduse; i++) {
			this->denumireProduse[i] = denumireProduse[i];
		}
		this->pretProduse = new float[this->nrProduse];//asa alocam spatiu pentru vector
		for (int i = 0; i < this->nrProduse; i++) {
			this->pretProduse[i] = pretProduse[i];
		}
		this->esteNonStop = esteNonStop;
	}
	Magazin(const Magazin& m) :codCAEN(m.codCAEN), idMagazin(m.idMagazin) {
		this->nume = m.nume;
		this->adresa = new char[strlen(m.adresa) + 1];//+1 este pentru terminatorul de sir --> '/0'
		strcpy(this->adresa, m.adresa);
		this->tip = m.tip;
		this->nrAngajati = m.nrAngajati;
		this->suprafata = m.suprafata;
		this->nrProduse = m.nrProduse;
		this->denumireProduse = new string[this->nrProduse];//asa alocam spatiu pentru vector
		for (int i = 0; i < this->nrProduse; i++) {
			this->denumireProduse[i] = m.denumireProduse[i];
		}
		this->pretProduse = new float[this->nrProduse];//asa alocam spatiu pentru vector
		for (int i = 0; i < this->nrProduse; i++) {
			this->pretProduse[i] = m.pretProduse[i];
		}
		this->esteNonStop = m.esteNonStop;
	}
	~Magazin() {
		delete[] this->adresa;
		delete[] this->denumireProduse;
		delete[] this->pretProduse;
		//De cate ori se apleaza destructorul intr-un program??
		//R: De cate ori apelam constructorii in program
		//cout << "S-a apelat destructorul!" << endl;
		//cout << "S-a apelat destructorul din clasa Magazin!" << endl;
	}Magazin& operator=(const Magazin& m) {
		//evitarea auto-asignarii --> sa nu putem face un obiect egal cu el insusi
		if (this != &m) {
			delete[] this->adresa;
			delete[] this->denumireProduse;
			delete[] this->pretProduse;
			this->nume = m.nume;
			this->adresa = new char[strlen(m.adresa) + 1];//+1 este pentru terminatorul de sir --> '/0'
			strcpy(this->adresa, m.adresa);
			this->tip = m.tip;
			this->nrAngajati = m.nrAngajati;
			this->suprafata = m.suprafata;
			this->nrProduse = m.nrProduse;
			this->denumireProduse = new string[this->nrProduse];//asa alocam spatiu pentru vector
			for (int i = 0; i < this->nrProduse; i++) {
				this->denumireProduse[i] = m.denumireProduse[i];
			}
			this->pretProduse = new float[this->nrProduse];//asa alocam spatiu pentru vector
			for (int i = 0; i < this->nrProduse; i++) {
				this->pretProduse[i] = m.pretProduse[i];
			}
			this->esteNonStop = m.esteNonStop;
		}
		return *this;
	}
	friend ostream& operator <<(ostream& out, const Magazin& m) {
		out << m.codCAEN << endl;
		out << m.idMagazin << endl;
		out << m.nume << endl;
		out << m.adresa << endl;
		//out << m.tip << endl;
		if (m.tip == MagazinHaine) {
			out << "Magazin Haine" << endl;
		}
		else if (m.tip == MagazinAlimentar) {
			out << "Magazin Alimentar" << endl;
		}
		else {
			out << "Magazin Electronic" << endl;
		}
		out << m.nrAngajati << endl;
		out << m.suprafata << endl;
		out << m.nrProduse << endl;
		for (int i = 0; i < m.nrProduse; i++) {
			out << m.denumireProduse[i] << " , ";
		}
		out << endl;
		for (int i = 0; i < m.nrProduse; i++) {
			out << m.pretProduse[i] << " lei, ";
		}
		out << endl;
		out << m.esteNonStop << endl;
		return out;
	}
	//FISIERELE TEXT: de afisare (<<) -->ofstream se copiaza opertaorul << fara texte aditionale 
	// si atribute statice/constante:
	friend ofstream& operator<<(ofstream& out, const Magazin& m) 
	{
		out << m.nume <<endl<< m.adresa <<endl<< m.tip<<endl << m.nrAngajati<<endl<< m.suprafata<<endl << m.nrProduse<<endl; 
		for (int i = 0; i < m.nrProduse; i++)
		{
			out << m.denumireProduse[i]<<endl;
		}
		for (int i = 0; i < m.nrProduse; i++)
		{
			out << m.pretProduse[i]<<endl; 
		}
		out << m.esteNonStop<<endl;
		return out;
	}
	//FISIERELE TEXT: de scriere (>>) -->ifstream, se copiaza operatorul >>
	friend ifstream& operator>>(ifstream& in, Magazin& m)
	{
		in >> ws;
		getline(in, m.nume);
		string buffer;
		in >> ws;
		getline(in, buffer);
		delete[]m.adresa;
		m.adresa = nullptr;
		m.adresa = new char[buffer.size() + 1]; 
		strcpy_s(m.adresa, buffer.size() + 1, buffer.data()); 
		int nr;
		in >> nr;
		if (nr == TipMagazin::MagazinAlimentar)
			m.tip = TipMagazin::MagazinAlimentar;
		else
			if (nr == TipMagazin::MagazinElectronic)
				m.tip = TipMagazin::MagazinElectronic;
			else
				m.tip = TipMagazin::MagazinHaine;
		in >> m.nrAngajati;
		in >> m.suprafata;
		in >> m.nrProduse;
		if (m.nrProduse > 0)
		{
			delete[]m.denumireProduse;
			m.denumireProduse = nullptr;
			delete[]m.pretProduse;
			m.pretProduse = nullptr;
			m.denumireProduse = new string[m.nrProduse];
			for (int i = 0; i < m.nrProduse; i++)
			{
				in >> ws;
				getline(in, m.denumireProduse[i]);
			}
			m.pretProduse = new float[m.nrProduse];
			for (int i = 0; i < m.nrProduse; i++)
			{
				in >> m.pretProduse[i];
			}
		}
		in >> m.esteNonStop;
		return in;


	}
	/*string nume;
	char* adresa;
	TipMagazin tip;
	int nrAngajati;
	float suprafata;
	int nrProduse;
	string* denumireProduse;
	float* pretProduse;
	bool esteNonStop;*/
	
	//FISIERELE BINARE:
	//scrierea se realizeaza prin SERIALIZARE-->adica transformarea obiectului intr-o secventa de biti
	//SERIALIZAREA-->ofstream-->ios::out
	void serializare(string numeFisier)
	{
		ofstream fisBin(numeFisier, ios::out | ios::binary);
		
		//scriere STRING:
		int dimNume = this->nume.size(); 
		fisBin.write((char*)&dimNume, sizeof(dimNume)); 
		fisBin.write(this->nume.c_str(), dimNume + 1);

		//scriere CHAR*:
		int dimAdresa = strlen(this->adresa); 
		fisBin.write((char*)&dimAdresa, sizeof(dimAdresa));
		fisBin.write(this->adresa, dimAdresa + 1);

		//scriere pt ENUM/INT/FLOAT/DOUBLE/BOOL etc:
		fisBin.write((char*)&this->tip, sizeof(this->tip));
		fisBin.write((char*)&this->nrAngajati, sizeof(this->nrAngajati));
		fisBin.write((char*)&this->suprafata, sizeof(this->suprafata));
		fisBin.write((char*)&this->nrProduse, sizeof(this->nrProduse));
		
		//scriere pt STRING*:
		for (int i = 0; i < this->nrProduse; i++)
		{
			int dimProdus = this->denumireProduse[i].size();
			fisBin.write((char*)&dimProdus, sizeof(dimProdus));
			fisBin.write(this->denumireProduse[i].c_str(), dimProdus + 1);
		}
		//scriere pt INT*:
		for (int i = 0; i < this->nrProduse; i++)
		{
			fisBin.write((char*)&this->pretProduse[i], sizeof(this->pretProduse[i]));
		}
		fisBin.write((char*)&this->esteNonStop, sizeof(this->esteNonStop));
		fisBin.close(); 
    }

	//DESERIALIZARE: transform secventele de biti inapoi in obiect
	//deserializare-->ifstream-->ios::in, write-->read
	void deserializare(string numeFisier)
	{
		ifstream fisBin(numeFisier, ios::in | ios::binary);
		
	        if (fisBin.is_open()) 
			{
				delete[]this->adresa;
				delete[]this->denumireProduse;
				delete[]this->pretProduse;

				int dimNume = 0;
				fisBin.read((char*)&dimNume, sizeof(dimNume));
				char* aux = new char[dimNume + 1];
				fisBin.read(aux, dimNume + 1);
				this->nume = aux;
				delete[]aux; 

				int dimAdresa = 0;
				fisBin.read((char*)&dimAdresa, sizeof(dimAdresa));
				this->adresa = new char[dimAdresa + 1];
				fisBin.read(this->adresa, dimAdresa + 1);

				fisBin.read((char*)&this->tip, sizeof(this->tip)); 
				fisBin.read((char*)&this->nrAngajati, sizeof(this->nrAngajati));
				fisBin.read((char*)&this->suprafata, sizeof(this->suprafata));
				fisBin.read((char*)&this->nrProduse, sizeof(this->nrProduse)); 

				this->denumireProduse = new string[this->nrProduse];
				for (int i = 0; i < this->nrProduse; i++)
				{
					int dimDen = 0;
					fisBin.read((char*)&dimDen, sizeof(dimDen));
					char* atribut = new char[dimDen + 1];
					fisBin.read(atribut, dimDen + 1); 
					this->denumireProduse[i] = atribut;  
					delete[]atribut;
				}
				this->pretProduse = new float[this->nrProduse];
				for (int i = 0; i < this->nrProduse; i++)
				{
					fisBin.read((char*)&this->pretProduse[i], sizeof(this->pretProduse[i]));
				}

				fisBin.read((char*)&this->esteNonStop, sizeof(this->esteNonStop));
				fisBin.close();
			}
			else
			{
				cout << "\nFis nu s a putut gasi!\n";
			}
		
	}
};
float Magazin::procentTVA = 18.6;
int Magazin::contor = 1;
int main()
{
	Magazin m1;
	string denumiri[] = { "TV","Boxa","Radio","Casti","Telefon","Apple","Radiator" };
	float preturi[] = { 400.41,98.1,55.2,45.12,800.51, 900, 2500 };
	Magazin m2(121, "Leroy Merlin", "Strada Scolii", MagazinElectronic, 34, 5431, 7, denumiri, preturi, true);
	Magazin m3(m1);
	m3 = m2;
	cout << m1 << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	//FISIERE TEXT:
	//afisarea=EXPORTARE:
	ofstream exportare("exemplu.txt", ios::out); 
	exportare << m2 << endl;
	exportare.close();
	//scriere=IMPORTARE
	Magazin m4;
	cout << m4 << endl;

	ifstream importare("exemplu.txt", ios::in);
	if (importare.is_open())
	{
		importare >> m4;
		importare.close();
	}
	else
	{
		cout << "\nFisierul nu exista!\n";
	}
	cout << endl << endl;
	cout << m4;
	cout << "\n===============================================\n" << endl;
	//FISIERE BINARE
	m2.serializare("exSerializare.bin");
	cout << endl << endl;
	Magazin m5;
	m5.deserializare("exSerializare.bin");
	cout << m5 << endl;
	
	return 0;
}