#include<iostream>
#include<string>
using namespace std;
//MOSTENIREA --> principiul --> "IS A"
//DOWN-CASTING reprezinta procesul de transformare a unui obiect de tipul clasei de baza
//intr-un obiect de tipul clasei derivate.
// DOWN-CASTING -->interventia programatorului
//UP-CASTING reprezinta procesul de transformare a unui obiect de tipul clasei derivate
//intr-un obiect de tipul clasei de baza
//UP-CASTING -->se realizeaza de compilator

//Functiile virtuale pure
//functii virtuale care pointeaza care null=0

//Clasa abstracta-->clasele care contin cel putin o functie virtuala pura
//Daca folosim clase abstracte, puntem sa lucram prin ele doar prin intermediul pointerilor

//Exemplu de clasa abstracta:
class CalculChirie {
    float taxa;
public:
    CalculChirie()
    {
        this->taxa = 0;
    }
    CalculChirie(float _taxa)
    {
        this->taxa = _taxa;
    }
    //functiile virtuale pure doar ele pot si egalate cu 0

    virtual float calculChiriePeMagazin() = 0; //fct virtuala pura 


}; 

//O interfata este o clasa care contine doare functii virtuale pure
/*aceasta este o interfata*/
class CalculChirieInterfata {

public:

    //functiile virtuale pure(doar ele pot fi egalate cu 0)

    virtual float calculChiriePerMagazin() = 0;//functie virtuala pura

    virtual string arataCeClasaE() = 0;
};

// Clasa Magazin
class Magazin:public CalculChirie{ 
private:
    const int id;
protected:
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
    Magazin(int _id, string _nume, float _dimensiune, int _nrProduse, string* _denumireProduse, float* _pretProduse, int* _cantitate) : id(_id)
    {
        this->nume = _nume;
        this->dimensiune = _dimensiune;
        this->nrProduse = _nrProduse;
        if (_nrProduse > 0 && _denumireProduse != nullptr && _pretProduse != nullptr && _cantitate != nullptr)
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
        if (m.nrProduse > 0 && m.denumireProduse != nullptr && m.pretProduse != nullptr && m.cantitate != nullptr)
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
            if (m.nrProduse > 0 && m.denumireProduse != nullptr && m.pretProduse != nullptr && m.cantitate != nullptr)
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
        cout << "\nApel destructor clasa de baza";
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
    //daca eu apelez si in clasa derivata aceasta metoda, o sa afiseze CEEA CE AFISEAZA DIN CLASA DERIVATA PT CA NU ESTWE VIRTUALA
    //cand folosim virtual, se creeaza o tabela de pointeri si se vor regasi adresa tuturor metodelor din clasa de baza si va fi si ea mostenita
    //cand supradefinim schimbam adresa pointerilor
    virtual string afiseazaNatura()
    {
        return "Aceasta functie e de tipul clasa de baza";
    }

    float calculChiriePeMagazin()
    {
        return 100;
    }
};
//modificatorul de acces
//in clasa derivata trec doar atributele pe care clasa de baza nu le are
//specializare clasa -->mostenire

class MagazinOnline : public Magazin {
protected:
    /*
    aici avem atributele mostenite si trebuie sa pastram aceasta ordine
    */
    string numeSite;
    float notaRecenzie;
public:
    //constructor cu un parametru
    MagazinOnline() :Magazin()
    {
        this->numeSite = "X";
        this->notaRecenzie = 0;
    }
    //constructor cu toti param
    MagazinOnline(int _id, string _nume, float _dimensiune, int _nrProduse, string* _denumireProduse, float* _pretProduse, int* _cantitate, string _numeSite, float _notaRecenzie) :Magazin(_id, _nume, _dimensiune, _nrProduse, _denumireProduse, _pretProduse, _cantitate)
    {
        this->numeSite = _numeSite;
        this->notaRecenzie = _notaRecenzie;
    }
    //constructot de copiere
    MagazinOnline(const MagazinOnline& m) :Magazin(m)
    {
        this->numeSite = m.numeSite;
        this->notaRecenzie = m.notaRecenzie;
    }
    //overloading -->supraincarea operatorilor supraincarcati in clasa de baza 
    //operator =
    MagazinOnline& operator=(const MagazinOnline& m)
    {
        if (this != &m)
        {
            //destructor magazinOnline
            //apelam op = din clasa d ebaza 
            Magazin::operator=(m);
            this->numeSite = m.numeSite;
            this->notaRecenzie = m.notaRecenzie;

        }return *this;
    }
    //operator de afisare <<
     //il mostenim pe cel din clasa de baza
    friend ostream& operator<<(ostream& out, const MagazinOnline& m)
    {
        out << (Magazin&)m;
        out << "\nSite: " << m.numeSite;
        out << "\nRecenzie: " << m.notaRecenzie << endl;
        return out;

    }

    //destructorul
    //se apleaza primul din clasa derivata si dupa din clasa de baza
    ~MagazinOnline()
    {
        cout << "\nApel destructor clasa derivata";
    }
    //overline -->supraincarcarea aceleiasi functii in clasa derivata
    string afiseazaNatura()
    {
        return "Aceasta functie e de tipul clasa derivata";
    }


    //down-casting -->const de copiere
    MagazinOnline(const Magazin& m) :Magazin(m)
    {
        this->numeSite = "www.site.ro";
        this->notaRecenzie =5.5;
    }

  
    float calculChiriePeMagazin()
    {
        return 5;
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
    cout << "\n--------------------MOSTENIRE IS A---------------------\n";
    MagazinOnline mo1;
    MagazinOnline mo2(1005, "Zara", 150.5, 2, vA, vB, c, "www.zara.ro", 9.5);
    cout << mo1 << endl;
    cout << mo2 << endl;
    cout << m1.afiseazaNatura() << endl;
    cout << mo1.afiseazaNatura() << endl;
    cout << m2 << endl;
    cout << mo2 << endl;

    //Up-casting si Down-casting se pun in evidenta doar atunci cand dorim sa cream un obiect nou
    
    //cum punem Up-Casting:
    cout << "\n***************************************************************\n";
   Magazin mUpCasting=mo2; //transforma mo2(obj creat prin clasa derivata) in ACELASI obj dar din clasa de baza
    cout << mUpCasting << endl;
    cout << "\n***************************************************************\n";

    //Down-Casting-->putem crea obj de tipul clasei de baza in obj de tipul clasei derivate
    MagazinOnline moDownCasting = m2;
    cout << moDownCasting << endl; 
    
    cout << m1.afiseazaNatura() << endl; 
    cout << mo1.afiseazaNatura() << endl; 
    cout << endl << endl;

    Magazin* pointerM = new Magazin(m1);  
    Magazin* pointerM2 = new MagazinOnline(mo2); 
     
    cout << *pointerM << endl; 
    cout << *pointerM2 << endl; 
    

    cout << endl;

    cout << pointerM->afiseazaNatura() << endl;
    cout << pointerM2->afiseazaNatura() << endl; 
  

    
    CalculChirie* cc1=new Magazin(m2); 
    CalculChirie* cc2 = new MagazinOnline(mo2);

    cout << cc1->calculChiriePeMagazin() << endl;
    cout << cc2->calculChiriePeMagazin() << endl;
    cout << "\n-----------------------------------------------------------\n";
    return 0;
}
