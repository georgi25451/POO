#include<iostream>
#include<string>
using namespace std;

// Clasa Magazin
class Magazin {
    const int id;
    string nume;
    float dimensiune;
    int nrProduse;
    string* denumireProduse;
    float* pretProduse;
    int* cantitate;

public:
    Magazin() : id(1000)
    {
        this->nume = "Anonim";
        this->dimensiune = 0;
        this->nrProduse = 0;
        this->denumireProduse = nullptr;
        this->pretProduse = nullptr;
        this->cantitate = nullptr;
    }
    Magazin(int _id, string _nume, float _dimensiune, int _nrProduse, string* _denumireProduse, float* _pretProduse, int * _cantitate) : id(_id)
    {
        this->nume = _nume;
        this->dimensiune = _dimensiune;
        this->nrProduse = _nrProduse;
        if (_nrProduse > 0 && _denumireProduse != nullptr && _pretProduse != nullptr && _cantitate!=nullptr)
        {
            this->denumireProduse = new string[this->nrProduse];
            for (int i = 0; i < this->nrProduse; i++)
            {
                this->denumireProduse[i] = _denumireProduse[i];
            }
            this->pretProduse = new float[this->nrProduse];
            for (int i = 0; i < this->nrProduse; i++)
            {
                this->pretProduse[i] = _pretProduse[i];
            }
            this->cantitate = new int[this->nrProduse];
            for (int i = 0; i < this->nrProduse; i++)
            {
                this->cantitate[i] = _cantitate[i];
            }
        }
        else
        {
            this->denumireProduse = nullptr;
            this->pretProduse = nullptr;
            this->cantitate = nullptr;
        }
    }
    Magazin(const Magazin& m) : id(m.id)
    {
        this->nume = m.nume;
        this->dimensiune = m.dimensiune;
        this->nrProduse = m.nrProduse;
        if (m.nrProduse > 0 && m.denumireProduse != nullptr && m.pretProduse != nullptr && m.cantitate!=nullptr)
        {
            this->denumireProduse = new string[this->nrProduse];
            for (int i = 0; i < this->nrProduse; i++)
            {
                this->denumireProduse[i] = m.denumireProduse[i];
            }
            this->pretProduse = new float[this->nrProduse];
            for (int i = 0; i < this->nrProduse; i++)
            {
                this->pretProduse[i] = m.pretProduse[i];
            }
            this->cantitate = new int[this->nrProduse];
            for (int i = 0; i < this->nrProduse; i++)
            {
                this->cantitate[i] = m.cantitate[i]; 
            }
        }
        else
        {
            this->denumireProduse = nullptr;
            this->pretProduse = nullptr;
            this->cantitate = nullptr;
        }
    }
    Magazin& operator=(const Magazin& m)
    {
        if (this != &m)
        {
            if (this->denumireProduse != nullptr)
            {
                delete[] this->denumireProduse;
                this->denumireProduse = nullptr;
            }
            if (this->pretProduse != nullptr)
            {
                delete[] this->pretProduse;
                this->pretProduse = nullptr;
            }
            if (this->cantitate != nullptr)
            {
                delete[]this->cantitate;
                this->cantitate = nullptr;
            }
            this->nume = m.nume;
            this->dimensiune = m.dimensiune;
            this->nrProduse = m.nrProduse;
            if (m.nrProduse > 0 && m.denumireProduse != nullptr && m.pretProduse != nullptr && m.cantitate!=nullptr)
            {
                this->denumireProduse = new string[this->nrProduse];
                for (int i = 0; i < this->nrProduse; i++)
                {
                    this->denumireProduse[i] = m.denumireProduse[i];
                }
                this->pretProduse = new float[this->nrProduse];
                for (int i = 0; i < this->nrProduse; i++)
                {
                    this->pretProduse[i] = m.pretProduse[i];
                }
                this->cantitate = new int[this->nrProduse];
                for (int i = 0; i < this->nrProduse; i++)
                {
                    this->cantitate[i] = m.cantitate[i];
                }
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Magazin& m)
    {
        out << "\nNume: " << m.nume;
        out << "\nDimensiune: " << m.dimensiune;
        out << "\nNr produse: " << m.nrProduse;
        if (m.nrProduse > 0 && m.denumireProduse != nullptr && m.pretProduse != nullptr)
        {
            out << "\nDenumire produse: ";
            for (int i = 0; i < m.nrProduse; i++)
            {
                out << m.denumireProduse[i] << ", ";
            }
            out << "\nPret produse: ";
            for (int i = 0; i < m.nrProduse; i++)
            {
                out << m.pretProduse[i] << ", ";
            }
            out << "\nCantitatea produselor: ";
            for (int i = 0; i < m.nrProduse; i++)
            {
                out << m.cantitate[i] << ", ";
            }
        }
        return out;
    }

    string getNume()
    {
        return this->nume;
    }
    int getNrProduse()
    {
        return this->nrProduse;
    }
    float* getPretProduse()
    {
        return this->pretProduse;
    }
    ~Magazin()
    {
        if (this->denumireProduse != nullptr)
        {
            delete[] this->denumireProduse;
            this->denumireProduse = nullptr;
        }
        if (this->pretProduse != nullptr)
        {
            delete[] this->pretProduse;
            this->pretProduse = nullptr;
        }
        if (this->cantitate != nullptr)
        {
            delete[]this->cantitate;
            this->cantitate = nullptr;
        }
    }
};

// Clasa Oras
class Oras {
    string nume;
    int nrMagazine;
    Magazin* magazine;

public:
    Oras()
    {
        this->nume = "Necunoscut";
        this->nrMagazine = 0;
        this->magazine = nullptr;
    }
    Oras(string _nume, int _nrMagazine, Magazin* _magazine)
    {
        this->nume = _nume;
        this->nrMagazine = _nrMagazine;
        if (_nrMagazine > 0 && _magazine != nullptr)
        {
            this->magazine = new Magazin[this->nrMagazine];
            for (int i = 0; i < this->nrMagazine; i++)
            {
                this->magazine[i] = _magazine[i];
            }
        }
        else
        {
            this->magazine = nullptr;
        }
    }
    Oras(const Oras& o)
    {
        this->nume = o.nume;
        this->nrMagazine = o.nrMagazine;
        if (o.nrMagazine > 0)
        {
            this->magazine = new Magazin[this->nrMagazine];
            for (int i = 0; i < this->nrMagazine; i++)
            {
                this->magazine[i] = o.magazine[i];
            }
        }
        else
        {
            this->magazine = nullptr;
        }
    }
    Oras& operator=(const Oras& o)
    {
        if (this != &o)
        {
            if (this->magazine != nullptr)
            {
                delete[] this->magazine;
                this->magazine = nullptr;
            }

            this->nume = o.nume;
            this->nrMagazine = o.nrMagazine;
            if (o.nrMagazine > 0)
            {
                this->magazine = new Magazin[this->nrMagazine];
                for (int i = 0; i < this->nrMagazine; i++)
                {
                    this->magazine[i] = o.magazine[i];
                }
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Oras& o)
    {
        out << "\nNume oras: " << o.nume;
        out << "\nNr magazine: " << o.nrMagazine;
        if (o.nrMagazine > 0 && o.magazine != nullptr)
        {
            out << "\nMagazinele:";
            out << "\n-----------------------------------------------------\n";
            for (int i = 0; i < o.nrMagazine; i++)
            {
                out << o.magazine[i] << endl;
            }
            out << "\n-----------------------------------------------------\n";
        }
        return out;
    }
    ~Oras()
    {
        if (this->magazine != nullptr)
        {
            delete[] this->magazine;
            this->magazine = nullptr;
        }
    }
    //adaugarea unui magazin in oras -->operator +=
    Oras& operator+=(Magazin m)
    {
        
        Oras copie = *this;
        delete[]this->magazine;
        this->magazine = nullptr;
        this->nrMagazine++;
        this->magazine = new Magazin[this->nrMagazine]; 
        for (int i = 0; i < copie.nrMagazine; i++)
        {
            this->magazine[i] = copie.magazine[i]; 
        }
        this->magazine[this->nrMagazine - 1] = m;
        return *this;

    }
    //calcularea pretului mediu din toate magazine dintr-un oras
    float pretMediu()
    {
        int k = 0;
        for (int i = 0; i < this->nrMagazine; i++)
        {
            k = k + this->magazine[i].getNrProduse();
        }
        float sum = 0;
        for (int i = 0; i < this->nrMagazine; i++)
        {
            for (int j = 0; j < this->magazine[i].getNrProduse(); j++)
            {
                sum = sum + this->magazine[i].getPretProduse()[j];
            }
        }
        return float(sum / k); 
    }
    //sa se elimine magazinele fara produse prin opertaorul functie
    Oras operator()()
    {
        int nrElementeFaraCantitate = 0;
        for (int i = 0; i < this->nrMagazine; i++) {
            if (this->magazine[i].getNrProduse() == 0) {
                nrElementeFaraCantitate++;
            }
        }

        if (nrElementeFaraCantitate > 0) {
            Oras copie = *this;  
            delete[]this->magazine;
            this->nrMagazine = this->nrMagazine - nrElementeFaraCantitate;  
            this->magazine = new Magazin[this->nrMagazine]; 
            int pozitie = 0; 
            for (int i = 0; i < copie.nrMagazine; i++) {
                if (copie.magazine[i].getNrProduse() != 0) {
                    this->magazine[pozitie] = copie.magazine[i]; 
                    pozitie++; 
                }
            }
        }
        return *this;

    }

};

int main()
{
    Magazin m1;
    string v1[] = { "tricou", "pantaloni", "hanorac" };
    float v2[] = { 60.5, 150, 100 };
    int c[] = { 10, 15, 10 };
    Magazin m2(1001, "Bershka", 200.50, 3, v1, v2, c);
    cout << m1 << endl;
    cout << m2 << endl;
    Magazin m3(m1);
    Magazin m4(m1);
    m4 = m2;
    cout << m3 << endl;
    cout << m4 << endl;
    string vA[] = { "adidasi", "geaca" };
    float vB[] = { 350, 500 };
    Magazin m5(1005, "Zara", 150.5, 2, vA, vB, c); 
    Oras o1;
    Magazin v3[3]={ m1, m2, m5 };
    Oras o2("Pitesti", 3, v3);
    
    cout << o1 << endl;
    cout << o2 << endl;

    o2 += m3;
    cout << o2 << endl;
    cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
    cout << o2.pretMediu();
    Magazin vectMag[8] = { m1, m1, m1, m1, m2, m5, m1, m1 };  
    Oras o3("Bucuresti", 8, vectMag); 
    cout << o3 << endl;
    cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
    cout << o3() <<endl; 

    return 0;
}
