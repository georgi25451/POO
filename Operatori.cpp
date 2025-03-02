//Operatori POO C++
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Plantatie {
	const int id;
	string adresa;
	float dimensiune;
	int vechime;
	int nrPomi;
	int* varsta;
	static int varstaMinimaRod;

public:
	Plantatie(int _id) :id(_id)
	{
		this->adresa = "X";
		this->dimensiune = 0;
		this->vechime = 0;
		this->nrPomi = 0;
		this->varsta = nullptr;
	}
	Plantatie(int _id, string _adresa, float _dimensiune, int _vechime, int _nrPomi, int* _varsta) :id(_id)
	{
		if (_adresa.length() >= 2)
		{
			this->adresa = _adresa;
		}
		if (_dimensiune > 0)
		{
			this->dimensiune = _dimensiune;
		}
		if (_vechime > 0)
		{
			this->vechime = _vechime;
		}
		if (_nrPomi > 0 && _varsta != nullptr)
		{
			this->nrPomi = _nrPomi;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++)
			{
				this->varsta[i] = _varsta[i];
			}
		}
	}
	Plantatie(const Plantatie& p) :id(p.id)
	{
		if (p.adresa.length() >= 2)
		{
			this->adresa = p.adresa;
		}
		if (p.dimensiune > 0)
		{
			this->dimensiune = p.dimensiune;
		}
		if (p.vechime > 0)
		{
			this->vechime = p.vechime;
		}
		if (p.nrPomi > 0 && p.varsta != nullptr)
		{
			this->nrPomi = p.nrPomi;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++)
			{
				this->varsta[i] = p.varsta[i];
			}
		}
	}
	Plantatie& operator=(const Plantatie& p)
	{
		if (this != &p)
		{
			if (this->varsta != nullptr)
			{
				delete[]this->varsta;
				this->varsta = nullptr;
			}
			if (p.adresa.length() >= 2)
			{
				this->adresa = p.adresa;
			}
			if (p.dimensiune > 0)
			{
				this->dimensiune = p.dimensiune;
			}
			if (p.vechime > 0)
			{
				this->vechime = p.vechime;
			}
			if (p.nrPomi > 0 && p.varsta != nullptr)
			{
				this->nrPomi = p.nrPomi;
				this->varsta = new int[this->nrPomi];
				for (int i = 0; i < this->nrPomi; i++)
				{
					this->varsta[i] = p.varsta[i];
				}
			}

		}return *this;
	}
	friend ostream& operator<<(ostream& out, const Plantatie& p)
	{
		out << "\nAdresa: " << p.adresa;
		out << "\nDimensiune: " << p.dimensiune << " metrii patrati";
		out << "\nVechime: " << p.vechime << " ani";
		out << "\nNr pomi: " << p.nrPomi << "\nVarsta pomilor: ";
		for (int i = 0; i < p.nrPomi; i++)
		{
			out << p.varsta[i] << ", ";
		}
		return out;
	}
	friend istream& operator>>(istream& in, Plantatie& p)
	{
		cout << "\nIntroduceti adresa: ";
		in >> ws;
		getline(in, p.adresa);
		cout << "\nIntroduceti dimensiunea: ";
		in >> p.dimensiune;
		cout << "\nIntroduceti vechimea: ";
		in >> p.vechime;
		cout << "\nIntroduceti nr pomilor : ";
		in >> p.nrPomi;
		if (p.nrPomi > 0)
		{
			cout << "\nIntroduceti varsta pomilor: ";
			delete[]p.varsta;
			p.varsta = nullptr;
			p.varsta = new int[p.nrPomi];
			for (int i = 0; i < p.nrPomi; i++)
			{
				in >> p.varsta[i];
			}
		}
		return in;

	}
	friend ofstream& operator<<(ofstream& out, const Plantatie& p)
	{
		out << p.adresa << endl;
		out << p.dimensiune << endl;
		out << p.vechime << endl;
		out << p.nrPomi << endl;
		for (int i = 0; i < p.nrPomi; i++)
		{
			out << p.varsta[i] << endl;
		}
		return out;
	}

	string getAdresa()
	{
		return this->adresa;
	}
	void setAdresa(string _adresa)
	{
		if (_adresa.length() >= 2)
		{
			this->adresa = _adresa;
		}
	}

	int getNrPomi()
	{
		return this->nrPomi;
	}

	int* getVarsta()
	{
		return this->varsta;
	}

	void setVarste(int _nrPomi, int* _varsta)
	{
		if (_nrPomi > 0 && _varsta != nullptr)
		{
			this->nrPomi = _nrPomi;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++)
			{
				this->varsta[i] = _varsta[i];
			}
		}
	}

	int getNrPomiVarstaMinima(int varsta)
	{
		int k = 0;
		for (int i = 0; i < this->nrPomi; i++)
		{
			if (this->varsta[i] >= varsta)
			{
				k++;
			}
		}
		return k;
	}
	friend Plantatie operator+(int x, Plantatie p)
	{
		Plantatie copie = p;
		delete[]copie.varsta;
		copie.varsta = nullptr;
		copie.nrPomi = copie.nrPomi + x;
		copie.varsta = new int[copie.nrPomi];
		for (int i = 0; i < p.nrPomi; i++)
		{
			copie.varsta[i] = p.varsta[i];
		}
		for (int i = p.nrPomi; i < copie.nrPomi; i++)
		{
			copie.varsta[i] = 4;
		}
		return copie;

	}
	explicit operator int()
	{
		int k = 0;
		for (int i = 0; i < this->nrPomi; i++)
		{
			if (this->varsta[i] >= Plantatie::varstaMinimaRod)
			{
				k++;
			}
		}
		return k;
	}
	bool operator==(const Plantatie p)
	{
		if (this->adresa != p.adresa)
			return false;
		else if (this->dimensiune != p.dimensiune)
			return false;
		else if (this->vechime != p.vechime)
			return false;
		else if (this->nrPomi != p.nrPomi)
			return false;
		else
		{
			for (int i = 0; i < this->nrPomi; i++)
			{
				if (this->varsta[i] != p.varsta[i])
					return false;

			}
		}
		return true;
	}
	//ALTI OPERTAORI:
	//operatorul + de forma obj+obj (vector + vector)
	Plantatie operator+(const Plantatie p)
	{
		Plantatie copie = *this;
		delete[]copie.varsta;
		copie.varsta = nullptr;
		copie.nrPomi += p.nrPomi;
		copie.varsta = new int[copie.nrPomi];
		for (int i = 0; i < this->nrPomi; i++)
		{
			copie.varsta[i] = this->varsta[i];
		}
		for (int i = 0; i < p.nrPomi; i++) {
			copie.varsta[this->nrPomi + i] = p.varsta[i];
		}

		return copie;

	}
	//operatorul + de forma obj+x
	Plantatie operator+(float x)
	{
		Plantatie copie = *this;
		copie.dimensiune += x;
		return copie;
	}
	//operatorul != de forma obj!=obj si x!=obj
	bool operator != (float x)
	{
		if (this->dimensiune != x)
			return true;
		else return false;
	}

	bool operator!=(const Plantatie p)
	{
		return!(*this == p);
	}
	//operatorul ++ post si pre
	//PRE!!!
	Plantatie& operator++()
	{

		this->dimensiune++;
		return *this;
	}
	//POST!!!
	Plantatie operator++(int)
	{
		Plantatie copie = *this;
		this->dimensiune++;
		return copie;
	}
	//operatorul index
	int& operator[](int poz) {
		if (poz >= 0 && poz < this->nrPomi)
		{
			return varsta[poz];
		}
		else
		{
			int eroare = -1;
			return eroare;
		}
	}
	//operatorul +=
	Plantatie& operator+=(int x)
	{
		Plantatie copie = *this;
		delete[]this->varsta;
		this->varsta = nullptr;
		this->nrPomi++;
		this->varsta = new int[this->nrPomi];
		for (int i = 0; i < copie.nrPomi; i++)
		{
			this->varsta[i] = copie.varsta[i];
		}
		this->varsta[this->nrPomi - 1] = x;
		return *this;
	}
	Plantatie& operator+=(float x)
	{
		this->dimensiune += x;
		return *this;
	}
	~Plantatie()
	{
		if (this->varsta != nullptr)
		{
			delete[]this->varsta;
			this->varsta = nullptr;
		}
	}


};
int Plantatie::varstaMinimaRod = 3;

int main()
{
	Plantatie p1(1000);

	int v[] = { 3, 2, 1 };
	Plantatie p2(1001, "Dealul cu flori", 200, 2, 3, v);

	Plantatie p3(p1);
	p3 = p2;

	cout << p1 << endl << endl;
	cout << p2 << endl << endl;
	cout << p3 << endl << endl;
	/*cin >> p1;
	cout << p1;*/
	cout << "\n============================================\n";
	p3.setAdresa("Malul cu flori");
	cout << p3.getAdresa() << endl;
	int v2[] = { 1, 1, 2, 2 };
	p3.setVarste(4, v2);
	cout << p3.getNrPomi() << endl;
	for (int i = 0; i < p3.getNrPomi(); i++)
	{
		cout << p3.getVarsta()[i] << ", ";
	}
	cout << "\n============================================\n";
	cout << p3.getNrPomiVarstaMinima(2);
	cout << "\n============================================\n";
	Plantatie p4 = 3 + p2;
	cout << p4 << endl;
	cout << int(p4) << endl;
	if (p2 == p3)
		cout << "\nObiectele SUNT egale\n";
	else
		cout << "\nObiectele nu sunt egale\n";
	Plantatie p5(1002);
	Plantatie p6(p5);
	p6.setVarste(4, v2);
	int v3[] = { 1, 1, 3, 2 };
	p5.setVarste(4, v3);
	if (p5 == p6)
		cout << "\nObiectele SUNT egale\n";
	else
		cout << "\nObiectele nu sunt egale\n";
	cout << "\n============================================\n";
	Plantatie p7 = p2 + p3;
	cout << p2 << endl;
	cout << p3 << endl;
	cout << p7 << endl;
	cout << "\n============================================\n";
	Plantatie p8 = p2 + 10;
	cout << p8 << endl;
	cout << "\n============================================\n";
	if (p2 != 300)
		cout << "\nDimensiunea este diferita!\n";
	else
		cout << "\nDimensiunea este egala!\n";
	if (p2 != p3)
		cout << "\nObiectele nu sunt egale\n";
	else
		cout << "\nObiectele SUNT egale\n";
	cout << "\n============================================\n";
	++p3; //PREincrementare
	cout << p3 << endl;
	cout << "\n============================================\n";
	Plantatie p9 = p2++;//POSTincrementare
	cout << p9 << endl;
	cout << "------------------------------------------" << endl;
	cout << p2 << endl;
	cout << "\n============================================\n";
	cout << p2[3] << endl;
	cout << p2[0] << endl;
	cout << p2[1] << endl;
	cout << p2[9] << endl;
	cout << "\n============================================\n";
	p2 += 9;
	p3 += 150.5f;
	cout << p2 << endl;
	cout << p3 << endl;
	cout << "\n============================================\n";
	ofstream fisiertext("expFis.txt", ios::out);
	fisiertext << p2;
	fisiertext.close();

	return 0;
}