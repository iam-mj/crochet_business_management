#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Bobina {

private:

    string material;
    string culoare;
    char grosime; //char intre 1 si 7
    float crosetaRecomandata;
    float pret;
    int stoc;

public:

    //constructori
    Bobina(); //fara parametrii
    Bobina(string material, string culoare, char grosime, float crosetaRecomandata, float pret, int stoc);//toti parametrii
    Bobina(string culoare, char grosime, float crosetaRecomandata, float pret); //mai putini parametrii
    Bobina(string material, float crosetaRecomandata, float pret); //si mai putini parametrii
    Bobina(const Bobina& Obj); //copy constructor

    //operatori
    Bobina &operator =(const Bobina &Obj);
    friend istream& operator >>(istream &in, Bobina& b);//nu e const fiindca vr sa o schimbam
    friend ostream& operator <<(ostream &out, const Bobina& b);

    //nu avem operator de indexare ca nu avem ce indexa
    Bobina& operator ++();
    Bobina operator ++(int);
    Bobina operator +(int a);
    friend Bobina operator +(int a, Bobina Obj);
    Bobina operator -(int a);
    friend Bobina operator -(int a, Bobina Obj);
    //cast explicit
    operator float();
    operator string();
    //operatori relationali
    bool operator <(const Bobina& Obj);
    bool operator ==(const Bobina& Obj);

    //metode
    void esteCumparata(int cant);

    //sett gett
    string getMaterial() {return this -> material;}
    string getCuloare() {return this -> culoare;}
    char getGrosime() {return this -> grosime;}
    float getCrosetaRecomandata() {return this -> crosetaRecomandata;}
    float getPret() {return this -> pret;}
    int getStoc() {return this -> stoc;}

    void setMaterial(string material) {this -> material = material;}
    void setCuloare(string culoare) {this -> culoare = culoare;}
    void setGrosime(char grosime) {this -> grosime = grosime;}
    void setCrosetaRecomandata(float croseta) {this -> crosetaRecomandata = croseta;}
    void setPret(float pret) {this -> pret = pret;}
    void setStoc(int stoc) {this -> stoc = stoc;}

    //destructor
    ~Bobina();
};

//clasa BOBINA
//constructori
Bobina::Bobina(): material("bumbac"), culoare("negru"), grosime('0'), crosetaRecomandata(0.0), pret(0.0), stoc(0) {};
Bobina::Bobina(string material, string culoare, char grosime, float crosetaRecomandata, float pret, int stoc) {
    this -> material = material;
    this -> culoare = culoare;
    this -> grosime = grosime;
    this -> crosetaRecomandata = crosetaRecomandata;
    this -> pret = pret;
    this -> stoc = stoc;
}
Bobina::Bobina(string culoare, char grosime, float crosetaRecomandata, float pret) {
    this -> material = "bumbac";
    this -> culoare = culoare;
    this -> grosime = grosime;
    this -> crosetaRecomandata = crosetaRecomandata;
    this -> pret = pret;
    this -> stoc = 0;
}
Bobina::Bobina(string material, float crosetaRecomandata, float pret) {
    this -> material = material;
    this -> culoare = "negru";
    this -> grosime = '0';
    this -> crosetaRecomandata = crosetaRecomandata;
    this -> pret = pret;
    this -> stoc = 0;
}
Bobina::Bobina(const Bobina& Obj) {
    this -> material = Obj.material;
    this -> culoare = Obj.culoare;
    this -> grosime = Obj.grosime;
    this -> crosetaRecomandata = Obj.crosetaRecomandata;
    this -> pret = Obj.pret;
    this -> stoc = Obj.stoc;
}
//operatori
Bobina& Bobina::operator =(const Bobina &Obj) {
    if(this != &Obj) {
        this -> material = Obj.material;
        this -> culoare = Obj.culoare;
        this -> grosime = Obj.grosime;
        this -> crosetaRecomandata = Obj.crosetaRecomandata;
        this -> pret = Obj.pret;
        this -> stoc = Obj.stoc;
    }
    return *this;
}
istream& operator >>(istream &in, Bobina& b) {
    cout << "Material: ";
    in >> b.material;
    cout << "Culoare: ";
    in >> b.culoare;
    cout << "Grosime [1 - 7]: ";
    in >> b.grosime;
    cout << "Croseta Recomandata: ";
    in >> b.crosetaRecomandata;
    cout << "Pret: ";
    in >> b.pret;
    cout << "Cate avem in stoc? ";
    in >> b.stoc;

    return in;
}
ostream& operator <<(ostream &out, const Bobina& b) {
    out << "Material: " << b.material << '\n';
    out << "Culoare: " << b.culoare << '\n';
    out << "Grosime: " << b.grosime << '\n';
    out << "Croseta Recomandata: " << b.crosetaRecomandata << '\n';
    out << "Pret: " << b.pret << '\n';
    out << "Stoc: " << b.stoc << '\n';

    return out;
}
Bobina& Bobina::operator ++()
{
    this -> stoc++;
    return *this;
}
Bobina Bobina::operator ++(int)
{
    Bobina aux(*this);
    this -> stoc++;
    return aux;
}
Bobina Bobina::operator +(int a)
{
    Bobina aux(*this);
    aux.stoc += a;
    return aux;
}
//asta e friend fiindca e binar si atunci nu mai traieste in Bobina::
Bobina operator +(int a, Bobina Obj)
{
    Obj.stoc += a;
    return Obj;
}
Bobina Bobina::operator -(int a)
{
    Bobina aux(*this);
    aux.stoc -= a;
    return aux;
}
Bobina operator -(int a, Bobina Obj)
{
    Obj.stoc -= a;
    return Obj;
}
Bobina::operator float()
{
    return this -> pret;
}
Bobina::operator string()
{
    return this -> material;
}
bool Bobina::operator <(const Bobina& Obj)
{
    return this -> stoc < Obj.stoc;
}
bool Bobina::operator ==(const Bobina& Obj)
{
    if(this -> material != Obj.material)
        return false;
    if(this -> culoare != Obj.culoare)
        return false;
    if(this -> grosime != Obj.grosime)
        return false;
    if(this -> crosetaRecomandata != Obj.crosetaRecomandata)
        return false;
    if(this -> pret != Obj.pret)
        return false;
    //stocul nu trebuie sa fie egal

    return true;
}
//metode
void Bobina::esteCumparata(int cant)
{
    this -> stoc -= cant;
}
//destructor
Bobina::~Bobina() {};



class Proiect; // o declaram inainte fiindca se confuzeaza compiler-ul la operatorul intre clase
class Client {

private:

    string nume;
    string email;
    string parola;
    bool trimiteAnunturi;
    float bani;
    float timpLiber; //in zile
    int nrProiecte;
    int* proiecte;

public:

    //constructori
    Client(); //constructor fara parametrii
    // toti parametrii
    Client(string nume, string email, string parola, bool trimiteAnunturi, float bani, float timpLiber, int nrProiecte, int* proiecte);
    Client(string nume, string email, string parola, float bani, int nrProiecte, int* proiecte); //mai putini parametrii
    Client(string nume, string email, string parola, float bani, float timpLiber); //si mai putini parametrii
    Client(const Client& Obj); //copy constructor

    //operatori
    Client &operator =(const Client &Obj);
    friend istream& operator >>(istream& in, Client& C);//nu e const fiindca vr sa o schimbam
    friend ostream& operator <<(ostream &out, const Client& C);

    int operator [](int a);
    Client& operator ++();
    Client operator ++(int);
    Client operator +(int a);
    friend Client operator +(int a, Client Obj);
    Client operator -(int a);
    friend Client operator -(int a, Client Obj);
    //+ intre 2 clase
    Client operator +(const Client& C); // am nevoie de el pt comutativitatea operatorului intre clase
    friend Client operator +(const Client& C, const Proiect& P);
    friend Client operator +(const Proiect& P, const Client& C);
    //cast explicit
    operator float();
    operator string();
    operator int();
    operator bool();
    //operatori relationali
    bool operator >(const Client& Obj);
    bool operator ==(const Client& Obj);

    //metode
    void iaVacanta(float zile);
    void cumpara(int cant);

    //sett gett
    string getEmail() {return this -> email;}
    string getParola() {return this -> parola;}
    bool getTrimiteAnunturi() {return this -> trimiteAnunturi;}
    float getBani() {return this -> bani;}
    float getTimpLiber() {return this -> timpLiber;}

    void setNume(string nume) {this -> nume = nume;}
    void setEmail(string email) {this -> email = email;}
    void setParola(string parola) {this -> parola = parola;}
    void setTrimiteAnunturi(bool trimiteAnunturi) {this -> trimiteAnunturi = trimiteAnunturi;}
    void setBani(float bani) {this -> bani = bani;}
    void setTimpLiber(float timpLiber) {this -> timpLiber = timpLiber;}
    void setProiecte(int nrProiecte, int* proiecte);

    //destructor
    ~Client();
};

//clasa CLIENT
Client::Client():nume("Anonim"), email(""), parola(""), trimiteAnunturi(false), bani(0.0), timpLiber(0.0), nrProiecte(0) {
    this -> proiecte = NULL;
}
Client::Client(string nume, string email, string parola, bool trimiteAnunturi, float bani, float timpLiber, int nrProiecte, int* proiecte) {
    this -> nume = nume;
    this -> email = email;
    this -> parola = parola;
    this -> trimiteAnunturi = trimiteAnunturi;
    this -> bani = bani;
    this -> timpLiber = timpLiber;
    this -> nrProiecte = nrProiecte;
    this -> proiecte = new int[nrProiecte];
    for(int i = 0; i < nrProiecte; i++)
        this -> proiecte[i] = proiecte[i];
}
Client::Client(string nume, string email, string parola, float bani, int nrProiecte, int* proiecte) {
    this -> nume = nume;
    this -> email = email;
    this -> parola = parola;
    this -> trimiteAnunturi = false;
    this -> bani = bani;
    this -> timpLiber = 0.0;
    this -> nrProiecte = nrProiecte;
    this -> proiecte = new int[nrProiecte];
    for(int i = 0; i < nrProiecte; i++)
        this -> proiecte[i] = proiecte[i];
}
Client::Client(string nume, string email, string parola, float bani, float timpLiber) {
    this -> nume = nume;
    this -> email = email;
    this -> parola = parola;
    this -> trimiteAnunturi = false;
    this -> bani = bani;
    this -> timpLiber = timpLiber;
    this -> nrProiecte = 0;
    this -> proiecte = NULL;
}
Client::Client(const Client& Obj) {
    this -> nume = Obj.nume;
    this -> email = Obj.email;
    this -> parola = Obj.parola;
    this -> trimiteAnunturi = Obj.trimiteAnunturi;
    this -> bani = Obj.bani;
    this -> timpLiber = Obj.timpLiber;
    this -> nrProiecte = Obj.nrProiecte;
    this -> proiecte = new int[Obj.nrProiecte];
    for(int i = 0; i < Obj.nrProiecte; i++)
        this -> proiecte[i] = Obj.proiecte[i];
}
//operatori
Client& Client::operator =(const Client &Obj) {
    if(this != &Obj) {
        if(this -> proiecte != NULL)
        {
            delete[] proiecte;
            this -> proiecte = NULL;
        }

        this -> nume = Obj.nume;
        this -> email = Obj.email;
        this -> parola = Obj.parola;
        this -> trimiteAnunturi = Obj.trimiteAnunturi;
        this -> bani = Obj.bani;
        this -> timpLiber = Obj.timpLiber;
        this -> nrProiecte = Obj.nrProiecte;
        this -> proiecte = new int[Obj.nrProiecte];
        for(int i = 0; i < Obj.nrProiecte; i++)
            this -> proiecte[i] = Obj.proiecte[i];
    }
    return *this;
}
istream& operator >>(istream& in, Client& C) {
    cout << "Numele clientului: ";
    cin.ignore(); //il folosesti cand treci de la cin >> la getline/get
    getline(in, C.nume);
    cout << "Email: ";
    getline(in, C.email);
    bool parolaInvalida = true;
    while(parolaInvalida)
    {
        cout << "Parola: ";
        string aux;
        getline(in, aux);
        cout << "Confirmare parola: ";
        string aux2;
        getline(in, aux2);
        if(aux == aux2)
        {
            C.parola = aux;
            parolaInvalida = false;
        }
        else
            cout << "\x1B[31mParola si confirmarea parolei nu conicid!\x1B[97m\n";
    }
    cout << "Suma de bani de care dispune: ";
    in >> C.bani;
    cout << "Timpul liber (in zile): ";
    in >> C.timpLiber;
    cout << "Numarul proiectelor realizate: ";
    in >> C.nrProiecte;

    if(C.proiecte != NULL)
    {
        delete[] C.proiecte;
        C.proiecte = NULL;
    }
    if(C.nrProiecte)
        cout << "Id-urile proiectelor realizate: \n";
    C.proiecte = new int[C.nrProiecte];
    for(int i = 0; i < C.nrProiecte; i++)
    {
        cout << " - proiectul " << i + 1 << ": ";
        in >> C.proiecte[i];
    }
    cout << "Doriti sa primiti oferte si anunturi pe adresa de mail? [0/1]: ";
    in >> C.trimiteAnunturi;

    return in;
}
ostream& operator <<(ostream &out, const Client& C) {
    out << "Numele clientului: " << C.nume << '\n';
    out << "Emailul: " << C.email << '\n';
    //nu afisam parola
    if(C.trimiteAnunturi == false)
        out << "NU ";
    out << "Doreste sa primeasca anunturi \n";
    out << "Suma de bani de care dispune: " << C.bani << '\n';
    out << "Timpul liber: " << C.timpLiber << " zile\n";
    if(C.nrProiecte > 0)
    {
        out << C.nrProiecte << " proiecte realizate: \n";
        for(int i = 0; i < C.nrProiecte; i++)
            out << " - proiectul " << i + 1 << ": " << C.proiecte[i] << '\n';
    }
    else out << "Nu a realizat niciun proiect\n";

    return out;
}
int Client::operator [](int a)
{
    if(this -> proiecte == NULL)
     throw runtime_error("Nu avem proiecte realizate");
    if(a < 0 || a > this -> nrProiecte)
        throw runtime_error("Index invalid!!");
    else
        return this -> proiecte[a];
}
Client& Client::operator ++()
{
    this -> timpLiber++;
    return *this;
}
Client Client::operator ++(int)
{
    Client aux(*this);
    this -> timpLiber++;
    return aux;
}
Client Client::operator +(int a)
{
    Client aux(*this);
    aux.timpLiber += a;
    return aux;
}
Client operator +(int a, Client Obj)
{
    Obj.timpLiber += a;
    return Obj;
}

Client Client::operator -(int a)
{
    Client aux(*this);
    aux.timpLiber -= a;
    return aux;
}
Client operator -(int a, Client Obj)
{
    Obj.timpLiber -= a;
    return Obj;
}
//operatorul + intre 2 instante ale clasei
Client Client::operator +(const Client& C)
{
    return *this; //nu vr sa se intample nimic;
}
Client::operator string()
{
    return this -> nume;
}
Client::operator float()
{
    return this -> timpLiber;
}
Client::operator int()
{
    return this -> nrProiecte;
}
Client::operator bool()
{
    return this -> trimiteAnunturi;
}
bool Client::operator >(const Client& Obj)
{
    return this -> bani > Obj.bani;
}
bool Client::operator ==(const Client& Obj)
{
    if(this -> nume != Obj.nume)
        return false;
    if(this -> email != Obj.email)
        return false;
    if(this -> parola != Obj.parola)
        return false;
    if(this -> trimiteAnunturi != Obj.trimiteAnunturi)
        return false;
    if(this -> bani != Obj.bani)
        return false;
    if(this -> timpLiber != Obj.timpLiber)
        return false;
    if(this -> nrProiecte != Obj.nrProiecte)
        return false;
    for(int i = 0; i < this -> nrProiecte; i++)
        if(this -> proiecte[i] != Obj.proiecte[i])
            return false;
    return false;
}
//metode
void Client::iaVacanta(float zile)
{
    this -> timpLiber += zile;
    this -> bani -= 100 * zile; //fiindca am stabilit eu ca o zi de vacanta te costa 100 =)
}
void Client::cumpara(int cant)
{
    this -> bani -= cant;
}
//setteri
void Client::setProiecte(int nrProiecte, int* proiecte)
{
    if(this -> proiecte != NULL)
        delete[] this -> proiecte;
    this -> proiecte = new int[nrProiecte];
    for(int i = 0; i < nrProiecte; i++)
        this -> proiecte[i] = proiecte[i];
    this -> nrProiecte = nrProiecte;
}
//destructori
Client::~Client() {
    if(this -> proiecte != NULL)
    {
        delete[] proiecte;
        this -> proiecte = NULL;
    }
}



class Croseta {

private:

    float marime;
    bool manerErgonomic;
    char* material;
    float pret;
    int stoc;

public:

    //constructori
    Croseta();// fara parametrii
    Croseta(float marime, bool manerErgonomic, char* material, float pret, int stoc); //toti parametrii
    Croseta(float marime, char* material, float pret); // mai putini parametrii
    Croseta(float marime, float pret); // si mai putini parametrii
    Croseta(const Croseta& Obj);

    //operatori
    Croseta &operator =(const Croseta &Obj);
    friend istream& operator >>(istream &in, Croseta& c);//nu e const fiindca vr sa o schimbam
    friend ostream& operator <<(ostream &out, const Croseta& c);

    char operator [](int a);
    Croseta& operator ++();
    Croseta operator ++(int);
    Croseta operator +(int a);
    friend Croseta operator +(int a, Croseta Obj);
    Croseta operator -(int a);
    friend Croseta operator -(int a, Croseta Obj);
    //cast explicit
    operator float();
    operator bool();
    operator int();
    //operatori relationali
    bool operator <=(const Croseta& Obj);
    bool operator ==(const Croseta& Obj);


    //metode
    void esteCumparata(int cant);

    //sett gett
    float getMarime() {return this -> marime;}
    bool getManerErgonomic() {return this -> manerErgonomic;}
    const char* getMaterial() {return this -> material;}
    float getPret() {return this -> pret;}
    int getStoc() {return this -> stoc;}

    void setMarime(float marime) {this -> marime = marime;}
    void setManerErgonomic(bool manerErgonomic) {this -> manerErgonomic = manerErgonomic;}
    void setMaterial(char* material);
    void setPret(float pret) {this -> pret = pret;}
    void setStoc(int stoc) {this -> stoc = stoc;}

    //destructor
    ~Croseta();
};

//clasa CROSETA
Croseta::Croseta(): marime(0.0), manerErgonomic(false), pret(0.0), stoc(0) {
    this -> material = new char[strlen("Nimic") + 1];
    strcpy(this -> material, "Nimic");
}
Croseta::Croseta(float marime, bool manerErgonomic, char* material, float pret, int stoc) {
    this -> marime = marime;
    this -> material = new char[strlen(material) + 1];
    strcpy(this -> material, material);
    this -> manerErgonomic = manerErgonomic;
    this -> pret = pret;
    this -> stoc = stoc;
}
Croseta::Croseta(float marime, char* material, float pret) {
    this -> marime = marime;
    this -> material = new char[strlen(material) + 1];
    strcpy(this -> material, material);
    this -> manerErgonomic = false;
    this -> pret = pret;
    this -> stoc = stoc;
}
Croseta::Croseta(float marime, float pret) {
    this -> marime = marime;
    this -> material = new char[strlen("otel") + 1];
    strcpy(this -> material, "otel");
    this -> manerErgonomic = false;
    this -> pret = pret;
    this -> stoc = 0;
}
Croseta::Croseta(const Croseta& Obj) {
    this -> marime = Obj.marime;
    this -> material = new char[strlen(Obj.material) + 1];
    strcpy(this -> material, Obj.material);
    this -> manerErgonomic = Obj.manerErgonomic;
    this -> pret = Obj.pret;
    this -> stoc = Obj.stoc;
}
//operatori
Croseta& Croseta::operator =(const Croseta &Obj) {
    if(this != &Obj) {
        if(this -> material != NULL)
        {
            delete[] material;
            this -> material = NULL;
        }

        this -> marime = Obj.marime;
        this -> material = new char[strlen(Obj.material) + 1];
        strcpy(this -> material, Obj.material);
        this -> manerErgonomic = Obj.manerErgonomic;
        this -> pret = Obj.pret;
        this -> stoc = Obj.stoc;
    }
    return *this;
}
istream& operator >>(istream &in, Croseta &c) {
    cout << "Marimea: ";
    in >> c.marime;

    char aux[20];
    cout << "Material: ";
    in >> aux;
    if(c.material != NULL)
        delete[] c.material;
    c.material = new char[strlen(aux) + 1];
    strcpy(c.material, aux);

    cout << "Maner ergonomic? [0/1]: ";
    in >> c.manerErgonomic;
    cout << "Pret: ";
    in >> c.pret;
    cout << "Cate avem in stoc? ";
    in >> c.stoc;

    return in;
}
ostream& operator <<(ostream &out, const Croseta &c) {
    out << "Marimea: " << c.marime << '\n';
    out << "Material: " << c.material << '\n';
    if(!c.manerErgonomic)
        out << "NU ";
    out << "ARE maner ergonomic" << '\n';
    out << "Pret: " << c.pret << '\n';
    out << "Stoc: " << c.stoc << '\n';

    return out;
}
char Croseta::operator [](int a)
{
    if(this -> material == NULL)
        throw runtime_error("Nu am specificat un material");
    if(a < 0 || a >= strlen(this -> material))
        throw runtime_error("Index invalid!!");
    else return this -> material[a];
}
Croseta& Croseta::operator ++()
{
    this -> stoc++;
    return *this;
}
Croseta Croseta::operator ++(int)
{
    Croseta aux(*this);
    this -> stoc++;
    return aux;
}
Croseta Croseta::operator +(int a)
{
    Croseta aux(*this);
    aux.stoc += a;
    return aux;
}
Croseta operator +(int a, Croseta Obj)
{
    Obj.stoc += a;
    return Obj;
}
Croseta Croseta::operator -(int a)
{
    Croseta aux(*this);
    aux.stoc -= a;
    return aux;
}
Croseta operator -(int a, Croseta Obj)
{
    Obj.stoc -= a;
    return Obj;
}
Croseta::operator float()
{
    return this -> marime;
}
Croseta::operator bool()
{
    return this -> manerErgonomic;
}
Croseta::operator int()
{
    return this -> stoc;
}
bool Croseta::operator <=(const Croseta& Obj)
{
    return this -> marime <= Obj.marime;
}
bool Croseta::operator ==(const Croseta& Obj)
{
    if(this -> marime != Obj.marime)
        return false;
    if(this -> manerErgonomic != Obj.manerErgonomic)
        return false;
    if(strcmp(this -> material, Obj.material) != 0)
        return false;
    if(this -> pret != Obj.pret)
        return false;
    if(this -> stoc != Obj.stoc)
        return false;
    return true;
}
//metode
void Croseta::esteCumparata(int cant)
{
    this -> stoc -= cant;
}
//setteri
void Croseta::setMaterial(char* material) {
    if(this -> material != NULL) {
        delete[] this -> material;
        this -> material = NULL;
    }
    this -> material = new char[strlen(material) + 1];
    strcpy(this -> material, material);
}
//destructor
Croseta::~Croseta() {
    if(this -> material != NULL)
    {
        delete[] material;
        this -> material = NULL;
    }
}



class Proiect {

private:

    static int nrId;
    const int idProiect;
    string nume;
    float timpNecesar;
    int nrBobine;
    int nrCrosete;
    float* croseteNecesare;

public:

    //constructori
    Proiect(); //fara parametrii
    Proiect(string nume, float timpNecesar, int nrBobine, float* croseteNecesare, int nrCrosete); //toti parametrii
    Proiect(string nume, int nrBobine, float* croseteNecesare, int nrCrosete); //mai putini parametrii
    Proiect(string nume, int nrBobine, float timpNecesar); //si mai putini parametrii
    Proiect(const Proiect& Obj); //copy constructor

    //operatori
    Proiect &operator =(const Proiect &Obj);
    friend istream& operator >>(istream &in, Proiect& p);//nu e const fiindca vr sa o schimbam
    friend ostream& operator <<(ostream &out, const Proiect& p);

    float operator [](int a);
    Proiect& operator ++();
    Proiect operator ++(int);
    Proiect operator +(int a);
    friend Proiect operator +(int a, Proiect Obj);
    Proiect operator -(int a);
    friend Proiect operator -(int a, Proiect Obj);
    //operator + intre 2 clase
    friend Client operator +(const Client& C, const Proiect& P);
    friend Client operator +(const Proiect& P, const Client& C);
    //cast explicit
    operator float()const;
    operator string();
    operator int();
    //operatori relationali
    bool operator >=(const Proiect& Obj);
    bool operator ==(const Proiect& Obj);

    //metode

    //sett gett
    static int getNrId() {return Proiect::nrId;}
    const int getIdProiect() {return this -> idProiect;}
    string getNume() {return this -> nume;}
    float getTimpNecesar() {return this -> timpNecesar;}
    int getNrBobine() {return this -> nrBobine;}
    int getNrCrosete() {return this -> nrCrosete;}
    const float* getCroseteNecesare() {return this -> croseteNecesare;}

    //nu avem setteri pt static si const
    void setNume(string nume) {this -> nume = nume;}
    void setTimpNecesar(float timpNecesar) {this -> timpNecesar = timpNecesar;}
    void setNrBobine(int nrBobine) {this -> nrBobine = nrBobine;}
    void setCroseteNecesare(int nrCrosete, float* croseteNecesare);

    //destructor
    ~Proiect();
};

//clasa PROIECT
//constructori
int Proiect::nrId = 1000;
Proiect::Proiect():idProiect(nrId++), nume("Necunoscut"), timpNecesar(0.0), nrBobine(0), nrCrosete(0) {
    this -> croseteNecesare = NULL;
}
Proiect::Proiect(string nume, float timpNecesar, int nrBobine, float* croseteNecesare, int nrCrosete):idProiect(nrId++) {
    this -> nume = nume;
    this -> timpNecesar = timpNecesar;
    this -> nrBobine = nrBobine;
    this -> nrCrosete = nrCrosete;
    this -> croseteNecesare = new float[nrCrosete];
    for(int i = 0; i < nrCrosete; i++)
        this -> croseteNecesare[i] = croseteNecesare[i];
}
Proiect::Proiect(string nume, int nrBobine, float* croseteNecesare, int nrCrosete):idProiect(nrId++) {
    this -> nume = nume;
    this -> timpNecesar = 0.5;
    this -> nrBobine = nrBobine;
    this -> nrCrosete = nrCrosete;
    this -> croseteNecesare = new float[nrCrosete];
    for(int i = 0; i < nrCrosete; i++)
        this -> croseteNecesare[i] = croseteNecesare[i];
}
Proiect::Proiect(string nume, int nrBobine, float timpNecesar):idProiect(nrId++) {
    this -> nume = nume;
    this -> timpNecesar = timpNecesar;
    this -> nrBobine = nrBobine;
    this -> nrCrosete = 0;
    this -> croseteNecesare = NULL;
}
Proiect::Proiect(const Proiect& Obj):idProiect(Obj.idProiect) {
    this -> nume = Obj.nume;
    this -> timpNecesar = Obj.timpNecesar;
    this -> nrBobine = Obj.nrBobine;
    this -> nrCrosete = Obj.nrCrosete;
    this -> croseteNecesare = new float[Obj.nrCrosete];
    for(int i = 0; i < Obj.nrCrosete; i++)
        this -> croseteNecesare[i] = Obj.croseteNecesare[i];
}
//operatori
Proiect& Proiect::operator =(const Proiect &Obj) {
    if(this != &Obj) {
        if(this -> croseteNecesare != NULL)
        {
            delete[] this -> croseteNecesare;
            this -> croseteNecesare = NULL;
        }
        this -> nume = Obj.nume;
        this -> timpNecesar = Obj.timpNecesar;
        this -> nrBobine = Obj.nrBobine;
        this -> nrCrosete = Obj.nrCrosete;
        this -> croseteNecesare = new float[Obj.nrCrosete];
        for(int i = 0; i < Obj.nrCrosete; i++)
            this -> croseteNecesare[i] = Obj.croseteNecesare[i];
    }
    return *this;
}
istream& operator >>(istream &in, Proiect &p) {
    cout << "Numele Proiectului: ";
    cin.ignore();
    getline(in, p.nume);
    cout << "Timpul necesar realizarii proiectului (in zile): ";
    in >> p.timpNecesar;
    cout << "Numarul de bobine necesare: ";
    in >> p.nrBobine;
    cout << "Numarul de crosete necesare: ";
    in >> p.nrCrosete;

    if(p.nrCrosete)
        cout << "Marimile crosetelor necesare: \n";
    if(p.croseteNecesare != NULL)
        delete[] p.croseteNecesare;
    p.croseteNecesare = new float[p.nrCrosete];
    for(int i = 0; i < p.nrCrosete; i++)
    {
        cout << " - croseta " << i + 1 << ": ";
        in >> p.croseteNecesare[i];
    }
    return in;
}
ostream& operator <<(ostream &out, const Proiect &p)
{
    out << "Id Proiect: " << p.idProiect << '\n';
    out << "Nume Proiect: " << p.nume << '\n';
    out << "Timp necesar realizarii proiectului: " << p.timpNecesar << " zile\n";
    out << "Numarul de bobine necesare: " << p.nrBobine << '\n';
    if(p.nrCrosete > 0)
    {
        out << p.nrCrosete << " crosete necesare: \n";
        for(int i = 0; i < p.nrCrosete; i++)
            out << " - croseta " << i + 1 << ": " << p.croseteNecesare[i] << '\n';
    }
    else out << "Nu necesita nicio croseta\n";

    return out;
}
float Proiect::operator [](int a)
{
    if(this -> croseteNecesare == NULL)
        throw runtime_error("Nu avem crosete necesare");
    if(a < 0 || a >= this -> nrCrosete)
        throw runtime_error("Index invalid!!");
    else return this -> croseteNecesare[a];
}
Proiect& Proiect::operator ++()
{
    this -> timpNecesar++;
    return *this;
}
Proiect Proiect::operator ++(int)
{
    Proiect aux(*this);
    this -> timpNecesar++;
    return aux;
}
Proiect Proiect::operator +(int a)
{
    Proiect aux(*this);
    aux.timpNecesar += a;
    return aux;
}
Proiect operator +(int a, Proiect Obj)
{
    Obj.timpNecesar += a;
    return Obj;
}
Proiect Proiect::operator -(int a)
{
    Proiect aux(*this);
    aux.timpNecesar -= a;
    return aux;
}
Proiect operator -(int a, Proiect Obj)
{
    Obj.timpNecesar -= a;
    return Obj;
}
//operatorul + intre 2 clase
Client operator +(const Client& C, const Proiect& P)
{
    //vrem sa adaugam id-ul lui P la lista de proiecte a clientului
    Client aux(C);
    if(aux.proiecte != NULL)
        delete[] aux.proiecte;
    aux.proiecte = new int[aux.nrProiecte + 1];
    for(int i = 0; i < aux.nrProiecte; i++)
        aux.proiecte[i] = C.proiecte[i];
    aux.proiecte[aux.nrProiecte++] = P.idProiect;
    //pe deasupra scadem timpul necesar din timpul liber al clientului
    aux.timpLiber -= P.timpNecesar;
    return aux;
}
Client operator +(const Proiect& P, const Client& C)
{
    return C + P; //e ok?? sau tre sa dau neaparat copy paste la asta de sus?
}
Proiect::operator float() const
{
    return this -> timpNecesar;
}
Proiect::operator string()
{
    return this -> nume;
}
Proiect::operator int()
{
    return this -> nrBobine;
}
bool Proiect::operator >=(const Proiect& Obj)
{
    return this -> timpNecesar >= Obj.timpNecesar;
}
bool Proiect::operator ==(const Proiect& Obj)
{
    if(this -> nume != Obj.nume)
        return false;
    if(this -> timpNecesar != Obj.timpNecesar)
        return false;
    if(this -> nrBobine != Obj.nrBobine)
        return false;
    if(this -> nrCrosete != Obj.nrCrosete)
        return false;
    for(int i = 0; i < this -> nrCrosete; i++)
        if(this -> croseteNecesare[i] != Obj.croseteNecesare[i])
            return false;
    return true;
}
//setteri
void Proiect::setCroseteNecesare(int nrCrosete, float* croseteNecesare) {
    //verificam, eliberam, alocam =)
    this -> nrCrosete = nrCrosete;
    if(this -> croseteNecesare != NULL)
    {
        delete[] this -> croseteNecesare;
        this -> croseteNecesare = NULL;
    }
    this -> croseteNecesare = new float[nrCrosete];
    for(int i = 0; i < nrCrosete; i++)
        this -> croseteNecesare[i] = croseteNecesare[i];
}
//destructor
Proiect::~Proiect() {
    if(this -> croseteNecesare != NULL)
    {
        delete[] this -> croseteNecesare;
        this -> croseteNecesare = NULL;
    }
}




int main()
{
    //schimbam culoarea consolei, primul simbol e pentru fundal, al doilea pt font
    system("color 3f");
    Client listaClienti[101];
    Bobina listaBobine[101];
    Croseta listaCrosete[101];
    Proiect listaProiecte[101];
    int contorClienti = 0, contorBobine = 0, contorCrosete = 0, contorProiecte = 0;
    bool stop = true; //controleaza cand iesim din program
    while(stop)
    {
    //stergem ce s-a afisat pana la momentul respectiv in consola
    system("cls");
    int identitate; //tine minte daca suntem client sau administrator
    cout << " Hello! Bine ati venit la Granny Mary \n Sunteti: \n 1 - Client \n 2 - Administrator \n";
    cin >> identitate;
    switch(identitate)
    {
    case 1:
    {
        bool profil = true; //controleaza cand iesim din profilul ales
        while(profil)
        {
            int comanda;
            system("cls");
            cout << " Hello, Mister Costumer! \n Va rugam realizati una dintre urmatoarele actiuni: \n 1 - Inregistrati-va";
            cout << "\n 2 - Daca aveti deja un cont, autentificati-va \n 3 - Mergeti inapoi \n 4 - Iesiti \n";
            int cont;
            cin >> cont;
            //inregistrare client nou
            if(cont == 1)
            {
                system("cls");
                cout << " Deveniti parte din comunitatea noastra!\n\n";
                //facem un client auxiliar pe care il punem in lista de clienti doar in momentul in care confirma ca datele sunt corecte
                Client ClientCurent;
                cin >> ClientCurent;
                bool confirmare;
                cout << "\n Urmatoarele date sunt corecte?\n\n";
                //nu o sa-i afisez parola dar oricum trebuie sa fi trecut de confirmarea ei
                cout << ClientCurent;
                cout << "\n Da\/Nu? [1/0]: ";
                cin >> confirmare;
                //daca confirma il bagam in lista si ii oferim sansa sa iasa din program
                //indiferent de confirmare, se intoarce inapoi la meniu anterior
                if(confirmare)
                {
                    listaClienti[++contorClienti] = ClientCurent;
                    bool iesire;
                    cout << "\n Cont creat cu succes! Doriti sa iesiti? [0/1]: ";
                    cin >> iesire;
                    if(iesire)
                    {
                        system("cls");
                        cout << "O zi frumoasa! Va mai asteptam!";
                        stop = false;
                        profil = false;
                    }
                }
            }
            else {
                    //autentificare
                    if(cont == 2)
                    {
                        bool neAutentificam = true;
                        while(neAutentificam)
                        {
                            system("cls");
                            cout << "Autentificati-va!\n\n";
                            //se introduce un email si o parola care sunt dupa cautate in lista de clienti inregistrati
                            string email, parola;
                            cout << "Email: ";
                            cin.ignore();
                            getline(cin, email);
                            cout << "Parola: "; //nu stiu sa o ascund...
                            getline(cin, parola);
                            int indiceCurent = 0;//daca gasim clientul in lista ii pastram indicele pt a putea sa manipulam usor obiectul respectiv
                            for(int i = 1; i <= contorClienti; i++)
                                if(listaClienti[i].getEmail() == email && listaClienti[i].getParola() == parola)
                                    indiceCurent = i;
                            //daca indicele curent e 0, avand in vedere ca lista de clienti e indexata de la 1, inseamna ca nu am gasit clientul in lista
                            if(indiceCurent == 0)
                            {
                                //ii oferim sansa sa mai incerce, sa revina la meniul anterior sau sa iasa cu totul din program
                                cout << "\nAutentificare esuata! Email sau parola incorecta.";
                                cout << "\nDoriti sa: \n1- Incercati din nou \n2 - Reveniti la meniul anterior \n3 - Iesiti\n";
                                int iesire;
                                cin >> iesire;
                                if(iesire == 3)
                                {
                                    system("cls");
                                    cout << "O zi frumoasa! Va mai asteptam!";
                                    stop = true;
                                    profil = true;
                                    neAutentificam = false;
                                }
                                else {
                                    if(iesire == 2)
                                        neAutentificam = false;
                                    else {
                                        if(iesire != 1)
                                            throw runtime_error("Comanda invalida!!");
                                    }
                                }
                            }
                            //autentificare reusita
                            else {
                                    bool autentificati = true; //controleaza cat suntem autentificati, astfel incat sa putem iesi doar din cont daca vrem
                                    while(autentificati)
                                    {
                                        system("cls");
                                        cout << "Bine ati revenit!\n";
                                        cout << "Ce doriti sa faceti?\n 1 - Vizualizati-ne stocul \n 2 - Alegeti-va urmatorul proiect";
                                        cout << "\n 3 - Contul meu \n 4 - Iesiti din cont \n 5 - Iesiti din aplicatie \n";
                                        cin >> comanda;
                                        system("cls");
                                        switch(comanda)
                                        {
                                        //daca vrem sa vizualizam un stoc / sa cumparam ceva
                                        case 1:
                                            {
                                                int bc; //bobine_crosete =) - daca vrem sa vedem/cumparam bobine sau crosete
                                                cout << " Doriti sa vizualizati oferta noastra de: \n 1 - Bobine \n 2 - Crosete\n";
                                                cin >> bc;
                                                system("cls");
                                                //daca vrem sa vedem/cumparam bobine
                                                if(bc == 1)
                                                {
                                                    //daca nu avem bobine in stoc
                                                    if(contorBobine == 0)
                                                    {
                                                        cout << "Din pacate, momentan nu avem bobine in stoc. \nVa rugam reveniti mai tarziu!";
                                                        //iese din if si ofera ocazia utilizatorului sa iasa din program
                                                    }
                                                    //daca avem bobine in stoc
                                                    else {
                                                        //afisam stocul cu tot cu indicele bobinelor in lista lor
                                                        cout << "Stocul nostru de bobine: \n\n";
                                                        for(int i = 1; i <= contorBobine; i++)
                                                            cout << "Tipul " << i << " de bobine:\n" << listaBobine[i] << endl << endl;

                                                        //intrebam utilizatorul daca vrea sa cumpere ceva
                                                        bool cumparam;
                                                        cout << "\nDoriti sa achizitionati bobine? [0/1]: ";
                                                        cin >> cumparam;
                                                        //daca vrea sa cumpere
                                                        if(cumparam)
                                                        {
                                                            //face selectia bobinei dupa indicele ei in lista
                                                            int indiceBobina, cantitate;
                                                            cout << "\nCe tip de bobina doriti sa cumparati? ";
                                                            cin >> indiceBobina;
                                                            //verificam ca indicele sa fie valid
                                                            if(indiceBobina < 1 || indiceBobina > contorBobine)
                                                                throw runtime_error("Indice invalid!");
                                                            cout << "\nCate bobine de acest tip doriti sa achizitionati? ";
                                                            cin >> cantitate;
                                                            //verificam daca avem destui bani sa cumparam cate bobine vrem
                                                            if(cantitate * listaBobine[indiceBobina].getPret() > listaClienti[indiceCurent].getBani())
                                                                cout << "\nNu aveti buget suficient pentru a realiza tranzactia dorita";
                                                            else {
                                                                    //verificam daca avem destule bobine in stoc
                                                                    if(cantitate > listaBobine[indiceBobina].getStoc())
                                                                        cout << "\nNu sunt destule bobine de acest tip in stoc";
                                                                    else {
                                                                        //realizam tranzactia <=> clientului ii scad banii, bobinei ii scade stocul
                                                                        listaClienti[indiceCurent].cumpara(listaBobine[indiceBobina].getPret() * cantitate);
                                                                        listaBobine[indiceBobina].esteCumparata(cantitate);
                                                                        cout << "\nTranzactie realizata cu succes!";
                                                                        //daca am cumparat toate bobinele de vreun fel stergem obiectul din lista
                                                                        if(listaBobine[indiceBobina].getStoc() == 0)
                                                                        {
                                                                            for(int i = indiceBobina + 1; i <= contorBobine; i++)
                                                                                listaBobine[i - 1] = listaBobine[i];
                                                                            contorBobine--;
                                                                        }
                                                                    }
                                                            }
                                                        }
                                                    }

                                                }
                                                else {
                                                    //daca vrem sa vedem/cumparam crosete
                                                    if(bc == 2)
                                                    {
                                                        //daca nu avem crosete in stoc
                                                        if(contorCrosete == 0)
                                                        {
                                                            cout << "Din pacate, momentan nu avem crosete in stoc. \nVa rugam reveniti mai tarziu!";
                                                        }
                                                        //daca avem crosete in stoc
                                                        else {
                                                            //afisam stocul de crosete cu tot cu indicele din lista lor
                                                            cout << "Stocul nostru de crosete: \n\n";
                                                            for(int i = 1; i <= contorCrosete; i++)
                                                                cout << "Tipul " << i << " de crosete:\n" << listaCrosete[i] << endl;
                                                            //verificam daca utilizatorul vrea sa cumpere ceva
                                                            bool cumparam;
                                                            cout << "\nDoriti sa achizitionati crosete? [0/1]: ";
                                                            cin >> cumparam;
                                                            //daca vrem sa cumparam
                                                            if(cumparam)
                                                            {
                                                                //selectam croseta prin indicele din lista crosetelor, pe care l-am afisat odata cu stocul
                                                                int indiceCroseta, cantitate;
                                                                cout << "\nCe tip de croseta doriti sa cumparati? ";
                                                                cin >> indiceCroseta;
                                                                //verificam validitatea stocului
                                                                if(indiceCroseta < 1 || indiceCroseta > contorCrosete)
                                                                    throw runtime_error("Indice invalid!");
                                                                cout << "\nCate crosete de acest tip doriti sa achizitionati? ";
                                                                cin >> cantitate;
                                                                //verificam daca avem destui bani
                                                                if(cantitate * listaCrosete[indiceCroseta].getPret() > listaClienti[indiceCurent].getBani())
                                                                    cout << "\nNu aveti buget suficient pentru a realiza tranzactia dorita";
                                                                else {
                                                                        //verificam daca avem destule crosete in stoc
                                                                        if(cantitate > listaCrosete[indiceCroseta].getStoc())
                                                                            cout << "\nNu sunt destule crosete de acest tip in stoc";
                                                                        else {
                                                                            //realizam tranzactia <=> clientului ii scad banii, crosetei ii scade stocul
                                                                            listaClienti[indiceCurent].cumpara(listaCrosete[indiceCroseta].getPret() * cantitate);
                                                                            listaCrosete[indiceCroseta].esteCumparata(cantitate);
                                                                            cout << "\nTranzactie realizata cu succes!";
                                                                            //daca am cumparat toate crosetele de vreun fel stergem croseta din lista
                                                                            if(listaCrosete[indiceCroseta].getStoc() == 0)
                                                                            {
                                                                                for(int i = indiceCroseta + 1; i <= contorCrosete; i++)
                                                                                    listaCrosete[i - 1] = listaCrosete[i];
                                                                                contorCrosete--;
                                                                            }
                                                                        }
                                                                }
                                                            }
                                                        }

                                                    }
                                                    else throw runtime_error("Comanda invalida!!");
                                                }
                                                //la final, indiferent de ce am ales sa facem, oferim posibilitatea iesirii din program
                                                //sau de intoarcere la meniul principal
                                                int iesire;
                                                cout << " \n1 - Iesiti \n2 - Intorceti-va la meniul principal\n";
                                                cin >> iesire;
                                                if(iesire == 1)
                                                {
                                                    system("cls");
                                                    cout << "O zi frumoasa! Va mai asteptam!\n";
                                                    stop = false;
                                                    profil = false;
                                                    neAutentificam = false;
                                                    autentificati = false;
                                                }
                                                break;
                                            }
                                        //daca vrem sa vizualizam/sa ne alegem un proiect
                                        case 2:
                                            {
                                                //daca nu avem niciun proiect
                                                if(contorProiecte == 0)
                                                {
                                                    cout << "Din pacate, momentan nu avem proiecte postate. \nVa rugam reveniti mai tarziu!";
                                                    //dupa iese din if si ii dam ocazia sa iasa din program sau sa se intoarca la meniul principal
                                                }
                                                //daca avem proiecte
                                                else {
                                                    //afisam lista de proiecte cu indicele lor in lista de proiecte
                                                    cout << "Vizualizati pattern-urile noastre si alegeti-va viitorul proiect!\n\n";
                                                    for(int i = 1; i <= contorProiecte; i++)
                                                        cout << "Proiectul " << i << ": \n" << listaProiecte[i] << endl;
                                                    //selectam un nou proiect cu ajutorul indicelui din lista proiectelor
                                                    int indiceProiect;
                                                    cout << "\nAlegeti-va viitorul proiect: ";
                                                    cin >> indiceProiect;
                                                    //verificam validitatea indicelui
                                                    if(indiceProiect < 1 || indiceProiect > contorProiecte) //vectorul listaProiecte e indexat de la 1
                                                        throw runtime_error("Indice invalid!");
                                                    //daca vrem sa alegem un proiect valid
                                                    else {
                                                        system("cls");
                                                        //afisam proiectul
                                                        cout << "Ati ales proiectul " << indiceProiect << endl;
                                                        cout << listaProiecte[indiceProiect] << endl;
                                                        //verificam daca nu avem timp
                                                        if(listaClienti[indiceCurent].getTimpLiber() < listaProiecte[indiceProiect].getTimpNecesar())
                                                        {
                                                            //ii sugeram sa-si ia o vacanta
                                                            cout << "\nDin pacate, nu aveti timp liber suficient pentru a termina proiectul =(";
                                                            cout << "\nVa sugeram calduros sa va luati o vacanta!";
                                                            cout << "\n1 - Imi iau concediu \n2 - Renunt la proiect =( \n";
                                                            int concendiu;
                                                            cin >> concendiu;
                                                            //daca isi ia vacanta
                                                            if(concendiu)
                                                            {
                                                                //ii spunem ca vacanta costa si de cate zile are nevoie macar pentru a realiza proiectul dorit
                                                                float diferenta = listaProiecte[indiceProiect].getTimpNecesar();
                                                                diferenta -= listaClienti[indiceCurent].getTimpLiber();
                                                                cout << "\nAveti nevoie de macar ";
                                                                cout << diferenta; //numarul de zile necesar pt a realiza proiectul
                                                                cout << " zile de vacanta \n";
                                                                cout << "Luati in considerare faptul ca fiecare zi de concediu costa 100 de lei :P\n";
                                                                cout << "Cate zile de concediu doriti sa va luati? ";
                                                                int zile;
                                                                cin >> zile; //cate zile de vacanta vrea clientul sa isi ia
                                                                //daca nu are bani de atatea zile de vacanta
                                                                if(zile * 100 > listaClienti[indiceCurent].getBani())
                                                                        cout << "\nNu aveti destui bani sa va luati " << zile << " zile de concediu...";
                                                                else {
                                                                    //daca are bani, dar si-a luat prea putine zile de concediu
                                                                    if(zile < diferenta)
                                                                    {
                                                                        cout << "\nNu v-ati luat destule zile de vacanta...";
                                                                        listaClienti[indiceCurent].iaVacanta(zile); //i le adaugam totusi (ii scadem si banii)
                                                                    }
                                                                    //daca are bani si si-a luat destule
                                                                    else
                                                                    {
                                                                        //ii adaugam zilele luate si ii scadem banii
                                                                        listaClienti[indiceCurent].iaVacanta(zile);
                                                                        //ii adaugam proiectul la lista si ii scadem zilele necesare
                                                                        listaClienti[indiceCurent] = listaClienti[indiceCurent] + listaProiecte[indiceProiect];
                                                                        cout << "\nAti realizat proiectul cu succes! Felicitari!!";
                                                                    }

                                                                }
                                                            }
                                                        }
                                                        //daca avem timp il adaugam la lista noastra de proiecte
                                                        else {
                                                            listaClienti[indiceCurent] = listaClienti[indiceCurent] + listaProiecte[indiceProiect];
                                                            cout << "\nAti realizat proiectul cu succes! Felicitari!!";
                                                        }
                                                    }
                                                }
                                                //ii oferim posibilitatea sa iasa din program/sa se intoarca la meniul principal
                                                int iesire;
                                                cout << " \n1 - Iesiti \n2 - Intorceti-va la meniul principal\n";
                                                cin >> iesire;
                                                if(iesire == 1)
                                                {
                                                    system("cls");
                                                    cout << "O zi frumoasa! Va mai asteptam!\n";
                                                    stop = false;
                                                    profil = false;
                                                    neAutentificam = false;
                                                    autentificati = false;
                                                }
                                                break;
                                            }
                                        //modificam sau stergem contul curent
                                        case 3:
                                            {
                                                //ii afisam datele contului
                                                system("cls");
                                                cout << "Contul Dumneavoastra: \n\n";
                                                cout << listaClienti[indiceCurent];
                                                //poate sa-si stearga sau sa-si modifice contul
                                                cout << "\n 1 - Modificati-va contul \n 2 - Stergeti-va contul \n 3 - Inapoi \n 4 - Iesiti \n";
                                                int modificare;
                                                cin >> modificare;
                                                //modificam contul
                                                switch(modificare)
                                                {
                                                case 1:
                                                    {
                                                        bool vremSaModificam = true; //ne mentine in meniul de schimbare a contului pana zicem ca vrem sa iesim
                                                        while(vremSaModificam)
                                                        {
                                                            system("cls");
                                                            //afisam din nou datele contului
                                                            cout << "Contul Dumneavoastra: \n\n";
                                                            cout << listaClienti[indiceCurent];
                                                            //ii dam posibilitatea sa-si modifice orice detaliu din cont
                                                            cout << "\n Ce doriti sa modificati? \n 1 - Numele \n 2 - Emailul \n 3 - Parola";
                                                            cout << "\n 4 - Decizia de a primi anunturi \n 5 - Banii \n 6 - Timpul liber ";
                                                            cout << "\n 7 - Proiectele \n";
                                                            int schimbare;
                                                            cin >> schimbare;
                                                            switch(schimbare)
                                                            {
                                                            //schimbam numele
                                                            case 1:
                                                                {
                                                                    string numeNou;
                                                                    cout << "\n Dati noul nume: ";
                                                                    cin.ignore();
                                                                    getline(cin, numeNou);
                                                                    listaClienti[indiceCurent].setNume(numeNou);
                                                                    break;
                                                                }
                                                            //schimbam email-ul
                                                            case 2:
                                                                {
                                                                    string emailNou;
                                                                    cout << "\n Dati noul email: ";
                                                                    cin.ignore();
                                                                    getline(cin, emailNou);
                                                                    listaClienti[indiceCurent].setEmail(emailNou);
                                                                    break;
                                                                }
                                                            //schimbam parola
                                                            case 3:
                                                                {
                                                                    string aux, aux2; //citim doua auxiliare pt parola si confirmarea ei
                                                                    bool parolaInvalida = true;
                                                                    cin.ignore();
                                                                    //tot citim pana cele doua auxiliare sunt egale
                                                                    while(parolaInvalida)
                                                                    {
                                                                        cout << "\n Dati noua parola: ";
                                                                        getline(cin, aux);
                                                                        cout << "\n Confirmati parola: ";
                                                                        getline(cin, aux2);
                                                                        //iesim din while cand sunt egale, moment in care setam si parola
                                                                        if(aux == aux2)
                                                                        {
                                                                            listaClienti[indiceCurent].setParola(aux);
                                                                            parolaInvalida = false;
                                                                        }
                                                                        // \x1B inseamna ca fundalul ramane la fel, [31m - font rosu, [97m - font alb
                                                                        else cout << "\n \x1B[31mParola si confirmarea parolei nu conicid!\x1B[97m";
                                                                    }
                                                                    break;
                                                                }
                                                            //schimbam daca vrem sau nu anunturi
                                                            case 4:
                                                                {
                                                                    if(listaClienti[indiceCurent].getTrimiteAnunturi())
                                                                        listaClienti[indiceCurent].setTrimiteAnunturi(false);
                                                                    else listaClienti[indiceCurent].setTrimiteAnunturi(true);
                                                                    break;
                                                                }
                                                            //schimbam bugetul
                                                            case 5:
                                                                {
                                                                    float baniNoi;
                                                                    cout << "\n Cat sunteti dispus sa investiti in produsele noastre? ";
                                                                    cin >> baniNoi;
                                                                    listaClienti[indiceCurent].setBani(baniNoi);
                                                                    break;
                                                                }
                                                            //schimbam timpul liber pe care il avem
                                                            case 6:
                                                                {
                                                                    float timpNou;
                                                                    cout << "\n Cat timp liber aveti la dispozitie? ";
                                                                    cin >> timpNou;
                                                                    listaClienti[indiceCurent].setTimpLiber(timpNou);
                                                                    break;
                                                                }
                                                            //schimbam proiectele pe care le-am realizat
                                                            case 7:
                                                                {
                                                                    int nrProiecteNou;
                                                                    int proiecteNoi[20];
                                                                    cout << "Dati numarul nou de proiecte: ";
                                                                    cin >> nrProiecteNou;
                                                                    cout << "Dati id-urile noilor proiecte cu spatiu intre ele: ";
                                                                    for(int i = 0; i < nrProiecteNou; i++)
                                                                        cin >> proiecteNoi[i];
                                                                    listaClienti[indiceCurent].setProiecte(nrProiecteNou, proiecteNoi);
                                                                    break;
                                                                }
                                                            default:
                                                                throw runtime_error("Comanda invalida!!");
                                                            }
                                                            system("cls");
                                                            //afisam contul modificat si vedem daca vrea sa mai modifice ceva sau nu
                                                            cout << " Modificare realizata cu succes! \n Contul dumneavoastra: \n\n";
                                                            cout << listaClienti[indiceCurent] << endl;
                                                            cout << " Doriti sa:\n 1 - Continuati modificarile\n 2 - Intorceti-va la meniu\n 3 - Iesiti\n";
                                                            int iesire;
                                                            cin >> iesire;
                                                            if(iesire == 3)
                                                            {
                                                                system("cls");
                                                                cout << "O zi frumoasa! Va mai asteptam!\n";
                                                                vremSaModificam = false;
                                                                neAutentificam = false;
                                                                autentificati = false;
                                                                profil = false;
                                                                stop = false;
                                                            }
                                                            else {
                                                                if(iesire == 2)
                                                                    vremSaModificam = false;
                                                                else {
                                                                    if(iesire != 1)
                                                                        throw runtime_error("Comanda invalida!!");
                                                                }
                                                            }
                                                        }
                                                        break;
                                                    }
                                                //stergem contul
                                                case 2:
                                                    {
                                                        //ne asiguram ca vr sa-si stearga permanent contul
                                                        bool stergere;
                                                        cout << "\n Sunteti sigur ca vreti sa va stergeti permanent contul? [0/1]: ";
                                                        cin >> stergere;
                                                        //stergem contul curent din lista
                                                        if(stergere)
                                                        {
                                                            for(int i = indiceCurent + 1; i <= contorClienti; i++)
                                                                listaClienti[i - 1] = listaClienti[i];
                                                            contorClienti--;
                                                            cout << "\n Contul a fost sters cu succes!";
                                                        }
                                                        int iesire;
                                                        cout << "\n Doriti sa: \n 1 - Ramaneti in aplicatie \n 2 - Iesiti \n";
                                                        cin >> iesire;
                                                        //daca vrem sa iesim
                                                        if(iesire == 2)
                                                        {
                                                            system("cls");
                                                            cout << "O zi frumoasa! Va mai asteptam!\n";
                                                            stop = false;
                                                            profil = false;
                                                            neAutentificam = false;
                                                            autentificati = false;
                                                        }
                                                        else {
                                                            //daca vrem sa ramanem in aplicatie
                                                            if(iesire == 1)
                                                            {
                                                                //o sa trebuiasca sa ne autentificam din nou
                                                                autentificati = false;
                                                                neAutentificam = false;
                                                            }
                                                            else throw runtime_error("Comanda invalida!");
                                                        }
                                                        break;
                                                    }
                                                //daca vrem sa mergem inapoi
                                                case 3:
                                                    {
                                                        break;
                                                    }
                                                //daca vrem sa iesim de tot
                                                case 4:
                                                    {
                                                        system("cls");
                                                        cout << "O zi frumoasa! Va mai asteptam!\n";
                                                        stop = false;
                                                        profil = false;
                                                        neAutentificam = false;
                                                        autentificati = false;
                                                        break;
                                                    }
                                                default:
                                                    throw runtime_error("Comanda Invalida!!");
                                                }
                                                break;
                                            }
                                        //daca vrem sa iesim din cont
                                        case 4:
                                            {
                                                neAutentificam = false;
                                                autentificati = false;
                                                break;
                                            }
                                        //daca vrem sa iesim din aplicatie
                                        case 5:
                                            {
                                                system("cls");
                                                cout << "O zi frumoasa! Va mai asteptam!\n";
                                                stop = false;
                                                profil = false;
                                                neAutentificam = false;
                                                autentificati = false;
                                                break;
                                            }
                                        default:
                                            {
                                                throw runtime_error("Comanda necunoscuta! =(");
                                                break;
                                            }
                                        }
                                    }

                            }
                        }

                    }

                    else {
                        //vrem sa ne intoarcem
                        if(cont == 3)
                        {
                            profil = false;
                        }
                        //vrem sa iesim
                        else {
                                if(cont == 4)
                                {
                                    system("cls");
                                    cout << "O zi frumoasa! Va mai asteptam!";
                                    stop = false;
                                    profil = false;
                                }
                                else throw runtime_error("Comanda necunoscuta!!");
                        }
                    }
            }

        }
    break;
    }
    //daca suntem administrator
    case 2:
         {
        int profil = true; //controleaza cand iesim din profilul ales
        while(profil)
        {
            int comanda;
            system("cls");
            cout << " Hello, Boss! \n Cu ce va ajut astazi? \n 1 - Vreau sa reactualizez stocul de bobine \n";
            cout << " 2 - Vreau sa reactualizez stocul de crosete \n 3 - Vreau sa reactualizez lista de proiecte";
            cout << "\n 4 - Vreau sa vizualizez lista de clienti \n 5 - Inapoi \n 6 - Iesiti \n";
            cin >> comanda;
            system("cls");
            switch(comanda)
            {
            //daca vrem sa reactualizam stocul de bobine
            case 1:
                {
                    // putem sa adaugam, stergem sau modificam bobine
                    cout << " Reactualizarea stocului de bobine! \n";
                    cout << " Doriti sa: \n 1 - Adaugati noi produse \n 2 - Stergeti produse \n 3 - Modificati produse \n";
                    int adauga;
                    cin >> adauga;
                    //daca alegem sa adaugam o bobina
                    if(adauga == 1)
                    {
                        bool vremSaAdaugam = true; //ne tine in meniul de adaugare pana vrem sa iesim
                        while(vremSaAdaugam)
                        {
                            system("cls");
                            //introducem o bobina auxiliara pe care o adauga la lista doar in momentul in care confirmam faptul ca datele sunt corecte
                            cout << " Adaugati noi bobine\n\n";
                            Bobina BobinaCurenta;
                            cin >> BobinaCurenta;
                            bool confirmare;
                            cout << "\n Urmatoarele date sunt corecte?\n\n";
                            cout << BobinaCurenta;
                            cout << "\n Da\/Nu? [1/0]: ";
                            cin >> confirmare;
                            //daca avem confirmarea
                            if(confirmare)
                            {
                                //adaugam bobina la lista
                                listaBobine[++contorBobine] = BobinaCurenta;
                                int iesire;
                                cout << "\n Stoc actualizat! Doriti sa: \n 1 - Mai adaugati produse \n 2 - Va intoarceti la meniul principal";
                                cout << "\n 3 - Iesiti\n";
                                cin >> iesire;
                                //daca vrem sa ramanem in meniul de adaugat nu schimbam nimic
                                //daca vrem sa iesim
                                if(iesire == 3)
                                {
                                    system("cls");
                                    cout << "Bye, Boss! <3\n";
                                    profil = false;
                                    stop = false;
                                    vremSaAdaugam = false;
                                }
                                else {
                                    //daca vr ne intoarcem inapoi iesim din while
                                    if(iesire == 2)
                                        vremSaAdaugam = false;
                                    else {
                                        if(iesire != 1)
                                            throw runtime_error("Comanda Invalida!");
                                    }
                                }
                            }
                        }

                    }
                    else {
                            //daca alegem sa stergem o bobina
                            if(adauga == 2)
                            {
                                bool vremSaStergem = true; //ne tine in meniul de stergere pana decidem sa iesim
                                while(vremSaStergem)
                                {
                                    system("cls");
                                    cout << "Stergeti bobine \n\n";
                                    //verificam daca avem bobine in stoc
                                    if(contorBobine == 0)
                                    {
                                        cout << "Nu avem inca bobine in stoc! =(\n";
                                        //iesim din if si afisam optiunile de iesire
                                    }
                                    else {
                                        //afisam stocul curent cu indicii bobinelor din lista de bobine
                                        cout << "Stocul curent: \n";
                                        for(int i = 1; i <= contorBobine; i++)
                                            cout << "Tipul de bobine " << i << ": \n" << listaBobine[i] << endl;
                                        //selectam bobina cu ajutorul indicelui din lista de bobine
                                        cout << "Doriti sa stergeti bobine de tipul: ";
                                        int indice, cantitate;
                                        cin >> indice;
                                        //verificam validitatea indicelui
                                        if(indice < 1 || indice > contorBobine)
                                            throw runtime_error("Index invalid!");
                                        cout << "Cate bobine de acest fel doriti sa stergeti? ";
                                        cin >> cantitate;
                                        //daca vrem sa stergem mai putine decat sunt in stoc
                                        if(cantitate < listaBobine[indice].getStoc())
                                        {
                                            //modificam stocul
                                            listaBobine[indice] = listaBobine[indice] - cantitate;
                                        }
                                        //daca vrei sa stergi cate bobine sunt in stoc sau mai multe pur si simplu iti sterge obiectul
                                        else {
                                            for(int i = indice + 1; i <= contorBobine; i++)
                                                listaBobine[i - 1] = listaBobine[i];
                                            contorBobine--;
                                        }
                                        //afisam stocul actualizat
                                        system("cls");
                                        cout << "Stocul actual: \n\n";
                                        for(int i = 1; i <= contorBobine; i++)
                                            cout << listaBobine[i] << endl;
                                    }
                                    //afisam optiunile de iesire
                                    cout << "\n Doriti sa: \n 1 - Mai stergeti produse \n 2 - Va intoarceti la meniul principal";
                                    cout << "\n 3 - Iesiti \n";
                                    int iesire;
                                    cin >> iesire;
                                    //daca vrem sa mai stergem nu facem nimic
                                    //daca vrem sa iesim de tot
                                    if(iesire == 3)
                                    {
                                        system("cls");
                                        cout << "Bye, Boss! <3\n";
                                        profil = false;
                                        stop = false;
                                        vremSaStergem = false;
                                    }
                                    else {
                                        //daca vr ne intoarcem inapoi iesim din while
                                        if(iesire == 2)
                                            vremSaStergem = false;
                                        else {
                                            if(iesire != 1)
                                                throw runtime_error("Comanda invalida!");
                                        }
                                    }
                                }
                            }
                            else
                            {
                                //daca vrem sa modificam o bobina
                                if(adauga == 3)
                                {
                                    bool vremSaModificam = true; //ne tine in meniul de modificare pana vrem sa iesim
                                    while(vremSaModificam)
                                    {
                                        system("cls");
                                        cout << "Modificati un tip de bobina! \n";
                                        //verificam daca avem bobine in stoc
                                        if(contorBobine == 0)
                                        {
                                            cout << "Nu avem inca bobine in stoc";
                                        }
                                        //daca avem bobine in stoc
                                        else {
                                            //afisam stocul curent cu tot cu indicele bobinelor din lista de bobine
                                            cout << "Stocul curent de bobine: \n";
                                            for(int i = 1; i <= contorBobine; i++)
                                                cout << "Bobinele de tipul " << i << ": \n" << listaBobine[i] << endl;
                                            //selectam bobina ce urmeaza sa fie modificata prin intermediul indicelui din lista de bobine
                                            cout << "Doriti sa modificati bobinele de tipul numarul: ";
                                            int indice;
                                            cin >> indice;
                                            //verificam validitatea indicelui
                                            if(indice < 1 || indice > contorCrosete)
                                                throw runtime_error("Indice invalid!");
                                            system("cls");
                                            //afisam bobina ce urmeaza sa fie modificata
                                            cout << "Modificam bobinele: \n\n";
                                            cout << listaBobine[indice];
                                            //alegem sa vrem sa modificam la ea
                                            int modificare;
                                            cout << "\nModificati: \n 1 - Materialul \n 2 - Culoarea \n 3 - Grosimea \n 4 - Croseta Recomandata";
                                            cout << "\n 5 - Pretul \n";
                                            cin >> modificare;
                                            switch(modificare)
                                            {
                                            //modificam materialul
                                            case 1:
                                                {
                                                    string materialNou;
                                                    cout << "\n Dati noul material: ";
                                                    cin.get();
                                                    getline(cin, materialNou);
                                                    listaBobine[indice].setMaterial(materialNou);
                                                    break;
                                                }
                                            //modificam culoarea
                                            case 2:
                                                {
                                                    string culoareNoua;
                                                    cout << "\n Dati noua culoare: ";
                                                    cin >> culoareNoua;
                                                    listaBobine[indice].setCuloare(culoareNoua);
                                                    break;
                                                }
                                            //modificam grosimea
                                            case 3:
                                                {
                                                    char grosimeNoua;
                                                    cout << "\n Dati noua grosime [0-7]: ";
                                                    cin >> grosimeNoua;
                                                    listaBobine[indice].setGrosime(grosimeNoua);
                                                    break;
                                                }
                                            //modificam marimea crosetei recomandate
                                            case 4:
                                                {
                                                    float crosetaNoua;
                                                    cout << "\n Dati marimea noii crosete: ";
                                                    cin >> crosetaNoua;
                                                    listaBobine[indice].setCrosetaRecomandata(crosetaNoua);
                                                    break;
                                                }
                                            //modficam pretul
                                            case 5:
                                                {
                                                    float pretNou;
                                                    cout << "\n Dati noul pret: ";
                                                    cin >> pretNou;
                                                    listaBobine[indice].setPret(pretNou);
                                                    break;
                                                }
                                            default:
                                                throw runtime_error("Comanda invalida!");
                                            }
                                            //afisam bobina modificata
                                            system("cls");
                                            cout << " Modificare realizata cu succes! Bobina actualizata: \n";
                                            cout << listaBobine[indice];
                                        }
                                        //afisam optiunile de iesire
                                        cout << "\n Mai departe doriti sa: \n 1 - Continuati sa modificati produse";
                                        cout << "\n 2 - Reveniti la meniul principal \n 3 - Iesiti \n";
                                        int iesire;
                                        cin >> iesire;
                                        //daca vrem sa iesim din program
                                        if(iesire == 3)
                                        {
                                            system("cls");
                                            cout << "Bye, Boss! <3\n";
                                            profil = false;
                                            stop = false;
                                            vremSaModificam = false;
                                        }
                                        else {
                                            //daca vrem sa ne intoarcem la meniul principal
                                            if(iesire == 2)
                                                vremSaModificam = false;
                                            else {
                                                if(iesire != 1)
                                                    throw runtime_error("Comanda invalida!");
                                            }
                                        }
                                    }
                                }
                                else throw runtime_error("Comanda invalida!");
                            }

                    }
                    break;
                }
            //reactualizam stocul de crosete
            case 2:
                {
                    cout << " Reactualizarea stocului de crosete! \n";
                    cout << " Doriti sa: \n 1 - Adaugati noi produse \n 2 - Stergeti produse \n 3 - Modificati produse \n";
                    int adauga;
                    cin >> adauga;
                    //daca alegem sa adaugam o croseta
                    if(adauga == 1)
                    {
                        bool vremSaAdaugam = true; //ne tine in meniul de adaugat pana vrem sa iesim
                        while(vremSaAdaugam)
                        {
                            system("cls");
                            //citim o croseta auxiliara care va fi adaugata in lista de crosete doar dupa confirmarea corectitudinii datelor
                            cout << " Adaugati o noua croseta\n\n";
                            Croseta CrosetaCurenta;
                            cin >> CrosetaCurenta;
                            bool confirmare;
                            cout << "\n Urmatoarele date sunt corecte?\n\n";
                            cout << CrosetaCurenta;
                            cout << "\n Da\/Nu? [1/0]: ";
                            cin >> confirmare;
                            //daca avem confirmarea
                            if(confirmare)
                            {
                                //adaugam croseta in lista
                                listaCrosete[++contorCrosete] = CrosetaCurenta;
                                int iesire;
                                //afisam optiunile de iesire
                                cout << "\n Stoc actualizat! Doriti sa: \n 1 - Mai adaugati produse \n 2 - Va intoarceti la meniul principal";
                                cout << "\n 3 - Iesiti\n";
                                cin >> iesire;
                                //daca vrem sa ramanem in meniul de adaugat nu facem nimic
                                //daca vrem sa iesim
                                if(iesire == 3)
                                {
                                    system("cls");
                                    cout << "Bye, Boss! <3\n";
                                    profil = false;
                                    stop = false;
                                    vremSaAdaugam = false;
                                }
                                else {
                                    //daca vr ne intoarcem inapoi iesim din while
                                    if(iesire == 2)
                                        vremSaAdaugam = false;
                                    else {
                                        if(iesire != 1)
                                            throw runtime_error("Comanda invalida!");
                                    }
                                }
                            }
                        }

                    }
                    //daca alegem sa stergem o croseta
                    else {
                            if(adauga == 2)
                            {
                                bool vremSaStergem = true; //ne tine in meniul de stergere pana vrem sa iesim
                                while(vremSaStergem)
                                {
                                    system("cls");
                                    cout << "Stergeti crosete \n\n";
                                    //verificam daca avem crosete in stoc
                                    if(contorCrosete == 0)
                                    {
                                        cout << "Nu avem inca crosete in stoc!";
                                    }
                                    //daca avem crosete in stoc
                                    else {
                                        //afisam stocul curent cu tot cu indicii din lista de crosete
                                        cout << "Stocul curent: \n";
                                        for(int i = 1; i <= contorCrosete; i++)
                                            cout << "Tipul de crosete " << i << ": \n" << listaCrosete[i] << endl;
                                        //selectia crosetei se realizeaza pe baza indicelui din lista de crosete
                                        cout << "Doriti sa stergeti crosete de tipul: ";
                                        int indice, cantitate;
                                        cin >> indice;
                                        //verificam validitatea indicelui
                                        if(indice < 1 || indice > contorCrosete)
                                            throw runtime_error("Indice invalid!");
                                        cout << "Cate crosete de acest fel doriti sa stergeti? ";
                                        cin >> cantitate;
                                        //daca stergem mai putine crosete decat cate avem in stoc
                                        if(cantitate < listaCrosete[indice].getStoc())
                                        {
                                            //modificam stocul
                                            listaCrosete[indice] = listaCrosete[indice] - cantitate;
                                        }
                                        //daca stregem cate avem in stoc sau mai multe pur si simplu stergem obiectul
                                        else {
                                            for(int i = indice + 1; i <= contorCrosete; i++)
                                                listaCrosete[i - 1] = listaCrosete[i];
                                            contorCrosete--;
                                        }
                                        //afisam stocul actualizat
                                        system("cls");
                                        cout << "Stocul actual: \n\n";
                                        for(int i = 1; i <= contorCrosete; i++)
                                            cout << listaCrosete[i] << endl;
                                    }
                                    //afisam optiunile de iesire
                                    cout << "\n Doriti sa: \n 1 - Mai stergeti produse \n 2 - Va intoarceti la meniul principal";
                                    cout << "\n 3 - Iesiti \n";
                                    int iesire;
                                    cin >> iesire;
                                    //daca vrem sa ramanem in meniul de stergere nu facem nimic
                                    //daca vrem sa iesim
                                    if(iesire == 3)
                                    {
                                        system("cls");
                                        cout << "Bye, Boss! <3\n";
                                        profil = false;
                                        stop = false;
                                        vremSaStergem = false;
                                    }
                                    else {
                                        //daca vr ne intoarcem inapoi iesim din while
                                        if(iesire == 2)
                                            vremSaStergem = false;
                                        else {
                                            if(iesire != 1)
                                                throw runtime_error("Comanda invalida!");
                                        }
                                    }
                                }
                            }
                            else {
                                //modificam crosete
                                if(adauga == 3)
                                {
                                    bool vremSaModificam = true; //ne mentine in meniul de modificare pana vrem sa iesim
                                    while(vremSaModificam)
                                    {
                                        system("cls");
                                        cout << "Modificati un tip de croseta! \n";
                                        //verificam daca avem crosete in stoc
                                        if(contorCrosete == 0)
                                            cout << "Nu avem inca crosete in stoc!";
                                        //daca avem crosete in stoc
                                        else {
                                            //afisam stocul curent cu indicii din lista de crosete
                                            cout << "Stocul curent de crosete: \n";
                                            for(int i = 1; i <= contorCrosete; i++)
                                                cout << "Crosetele de tipul " << i << ": \n" << listaCrosete[i] << endl;
                                            //selectam croseta ce va fi modificata prin intermediul indicelui sau din lista de crosete
                                            cout << "Doriti sa modificati crosetele de tipul numarul: ";
                                            int indice;
                                            cin >> indice;
                                            //verificam validitatea indicelui
                                            if(indice < 1 || indice > contorCrosete)
                                                throw runtime_error("Index invalid!");
                                            system("cls");
                                            //afisam crosetele pe care vrem sa le modificam
                                            cout << "Modificam crosetele: \n\n";
                                            cout << listaCrosete[indice];
                                            int modificare;
                                            //alegem ce vrem sa modificam
                                            cout << "\nModificati: \n 1 - Marimea \n 2 - Materialul \n 3 - Manerul ergonomic \n 4 - Pret \n";
                                            cin >> modificare;
                                            switch(modificare)
                                            {
                                            //modificam marimea
                                            case 1:
                                                {
                                                    float marimeNoua;
                                                    cout << "\n Dati noua marime: ";
                                                    cin >> marimeNoua;
                                                    listaCrosete[indice].setMarime(marimeNoua);
                                                    break;
                                                }
                                            //modificam materialul
                                            case 2:
                                                {
                                                    char materialNou[20];
                                                    cout << "\n Dati noul material: ";
                                                    cin >> materialNou;
                                                    listaCrosete[indice].setMaterial(materialNou);
                                                    break;
                                                }
                                            //modificam manerul ergonomic
                                            case 3:
                                                {
                                                    if(listaCrosete[indice].getManerErgonomic())
                                                        listaCrosete[indice].setManerErgonomic(false);
                                                    else listaCrosete[indice].setManerErgonomic(true);
                                                    break;
                                                }
                                            //modificam pretul
                                            case 4:
                                                {
                                                    float pretNou;
                                                    cout << "\n Dati noul pret: ";
                                                    cin >> pretNou;
                                                    listaCrosete[indice].setPret(pretNou);
                                                    break;
                                                }
                                            default:
                                                throw runtime_error("Comanda invalida!");
                                            }
                                            //afisam croseta modificata
                                            system("cls");
                                            cout << " Modificare realizata cu succes! Croseta actualizata: \n";
                                            cout << listaCrosete[indice];
                                        }
                                        //afisam optiunile de iesire
                                        cout << "\n Mai departe doriti sa: \n 1 - Continuati sa modificati produse";
                                        cout << "\n 2 - Reveniti la meniul principal \n 3 - Iesiti \n";
                                        int iesire;
                                        cin >> iesire;
                                        //daca vrem sa mai modificam nu facem nimic
                                        //daca vrem sa iesim din program
                                        if(iesire == 3)
                                        {
                                            system("cls");
                                            cout << "Bye, Boss! <3\n";
                                            profil = false;
                                            stop = false;
                                            vremSaModificam = false;
                                        }
                                        else {
                                            //daca vrem sa ne intoarcem la meniul principal
                                            if(iesire == 2)
                                                vremSaModificam = false;
                                            else {
                                                if(iesire != 1)
                                                    throw runtime_error("Comanda invalida!");
                                            }
                                        }
                                    }
                                }
                                else throw runtime_error("Comanda invalida!");
                            }
                    }
                    break;
                }
            //daca vrem sa reactualizam proiectele
            case 3:
                {
                    cout << " Reactualizarea proiectelor! \n";
                    cout << "Doriti sa: \n 1 - Adaugati un nou proiect \n 2 - Stergeti un proiect (neindicat)";
                    cout << "\n 3 - Modificati un proiect existent\n";
                    int adaugam;
                    cin >> adaugam;
                    //daca vrem sa adaugam un proiect
                    if(adaugam == 1)
                    {
                        bool vremSaAdaugam = true; //ne mentine in meniul de adaugat pana vrem sa iesim
                        while(vremSaAdaugam)
                        {
                            system("cls");
                            //citim un proiect auxiliar ce va fi adaugat la lista de proiecte doar dupa confirmarea corectitudinii datelor
                            cout << " Adaugati un nou proiect\n\n";
                            Proiect ProiectCurent;
                            cin >> ProiectCurent;
                            bool confirmare;
                            cout << "\n Urmatoarele date sunt corecte?\n\n";
                            cout << ProiectCurent;
                            cout << "\n Da\/Nu? [1/0]: ";
                            cin >> confirmare;
                            //daca primim confirmarea
                            if(confirmare)
                            {
                                //adaugam proiectul in lista
                                listaProiecte[++contorProiecte] = ProiectCurent;
                                cout << "\nLista actualizata!";

                            }
                            //afisam optiunile de iesire
                            int iesire;
                            cout << "Doriti sa: \n 1 - Mai adaugati proiecte \n 2 - Va intoarceti la meniul principal";
                            cout << "\n 3 - Iesiti \n";
                            cin >> iesire;
                            //daca vrem sa ramanem in meniul de adaugat nu facem nimic
                            //daca vrem sa iesim din program
                            if(iesire == 3)
                            {
                                system("cls");
                                cout << "Bye, Boss! <3\n";
                                profil = false;
                                stop = false;
                                vremSaAdaugam = false;
                            }
                            else {
                                //daca vrem sa ne intoarcem la meniul principal
                                if(iesire == 2)
                                    vremSaAdaugam = false;
                                else {
                                    if(iesire != 1)
                                        throw runtime_error("Comanda invalida!");
                                   }
                            }
                        }
                    }
                    else {
                        //daca vrem sa stergem un proiect
                        if(adaugam == 2)
                        {
                            bool vremSaStergem = true; //ne mentine in meniul de stergere pana vrem sa iesim
                            while(vremSaStergem)
                            {
                                system("cls");
                                cout << " Stregeti un proiect \n\n";
                                //verificam daca avem proiecte postate
                                if(contorProiecte == 0)
                                    cout << "Nu avem inca proiecte postate!";
                                //daca avem proiecte in stoc
                                else {
                                    //afisam lista curenta cu tot cu indicii proiectelor in lista de proiecte
                                    cout << " Lista curenta de pattern-uri disponibile: \n";
                                    for(int i = 1; i <= contorProiecte; i++)
                                        cout << "Proiectul " << i << ": \n" << listaProiecte[i] << endl;
                                    //selectam proiectul prin intermediul indicelui sau din lista de proiecte
                                    cout << "Doriti sa stergeti proiectul numarul: ";
                                    int indice;
                                    cin >> indice;
                                    //verificam validitatea indicelui
                                    if(indice < 1 || indice > contorProiecte)
                                        throw runtime_error("Comanda invalida");
                                    //stregem proiectul cu indicele "indice" din lista de proiecte
                                    for(int i = indice + 1; i <= contorProiecte; i++)
                                        listaProiecte[i - 1] = listaProiecte[i];
                                    contorProiecte--;
                                    //afisam stocul actualizat
                                    system("cls");
                                    cout << "Lista actualizata de proiecte din revista: \n\n";
                                    for(int i = 1; i <= contorProiecte; i++)
                                        cout << listaProiecte[i] << endl;
                                }
                                //afisam optiunile de iesire
                                cout << "Mai departe doriti sa: \n 1 - Continuati sa stergeti proiecte \n 2 - Reveniti la meniul principal";
                                cout << "\n 3 - Iesiti \n";
                                int iesire;
                                cin >> iesire;
                                //daca vrem sa ramanem in meniul de stergere nu facem nimic
                                //daca vrem sa iesim din program
                                if(iesire == 3)
                                {
                                    system("cls");
                                    cout << "Bye, Boss! <3\n";
                                    profil = false;
                                    stop = false;
                                    vremSaStergem = false;
                                }
                                else {
                                    //daca vrem sa ne intoarcem la meniul principal
                                    if(iesire == 2)
                                        vremSaStergem = false;
                                    else {
                                        if(iesire != 1)
                                            throw runtime_error("Comanda invalida!");
                                    }
                                }
                            }
                        }
                        else {
                            //daca vrem sa modificam un proiect
                            if(adaugam == 3)
                            {
                                bool vremSaModificam = true;//ne mentine in meniul de modificat
                                while(vremSaModificam)
                                {
                                    system("cls");
                                    cout << "Modificati un proiect! \n";
                                    //verificam daca avem proiecte postate
                                    if(contorProiecte == 0)
                                        cout << "Nu avem proiecte posatate!";
                                    //daca avem proiecte postate
                                    else {
                                        //afisam lista proiectelor curente cu tot cu indicii proiectelor in ea
                                        cout << "Lista curenta de pattern-uri disponibile: \n";
                                        for(int i = 1; i <= contorProiecte; i++)
                                            cout << "Proiectul " << i << ": \n" << listaProiecte[i] << endl;
                                        //selectam proiectul prin intermediul indicelui din lista
                                        cout << "Doriti sa modificati proiectul numarul: ";
                                        int indice;
                                        cin >> indice;
                                        //verificam validitatea indicelui
                                        if(indice < 1 || indice > contorProiecte)
                                            throw runtime_error("Comanda invalida!");
                                        system("cls");
                                        //afisam proiectul selectat
                                        cout << "Modificam proiectul: \n";
                                        cout << listaProiecte[indice];
                                        int modificare;
                                        //selectam ce vrem sa modificam
                                        cout << "\nModificati: \n 1 - Numele proiectului \n 2 - Timpul necesar realizarii sale \n 3 - Numarul de bobine";
                                        cout << "\n 4 - Crosetele Necesare\n";
                                        cin >> modificare;
                                        switch(modificare)
                                        {
                                        //modificam numele
                                        case 1:
                                            {
                                                string numeNou;
                                                cout << "\n Dati noul nume: ";
                                                cin.get();
                                                getline(cin, numeNou);
                                                listaProiecte[indice].setNume(numeNou);
                                                break;
                                            }
                                        //modificam timpul necesar realizarii lui
                                        case 2:
                                            {
                                                float timpNou;
                                                cout << "\n Dati noul timp necesar realizarii proiectului (in ore): ";
                                                cin >> timpNou;
                                                listaProiecte[indice].setTimpNecesar(timpNou);
                                                break;
                                            }
                                        //modificam numarul de bobine necesare realizarii lui
                                        case 3:
                                            {
                                                int nrBobineNou;
                                                cout << "\n Dati noul numar de bobine necesare realizarii proiectului: ";
                                                cin >> nrBobineNou;
                                                listaProiecte[indice].setNrBobine(nrBobineNou);
                                                break;
                                            }
                                        //modificam crosetele necesare realizarii lui
                                        case 4:
                                            {
                                                int nrCroseteNou;
                                                float croseteNoi[10];
                                                cout << "\n Dati numarul crosetelor noi: ";
                                                cin >> nrCroseteNou;
                                                cout << "\n Dati marimile noilor crosete: ";
                                                for(int i = 0; i < nrCroseteNou; i++)
                                                    cin >> croseteNoi[i];
                                                listaProiecte[indice].setCroseteNecesare(nrCroseteNou, croseteNoi);
                                                break;
                                            }
                                        default:
                                            throw runtime_error("Comanda invalida!");
                                        }
                                        //afisam proiectul modificat
                                        system("cls");
                                        cout << " Modificare realizata cu succes! Proiectul actualizat: \n";
                                        cout << listaProiecte[indice];
                                    }
                                    //afisam optiunile de iesire
                                    cout << "\n Mai departe doriti sa: \n 1 - Continuati sa modificati proiecte";
                                    cout << "\n 2 - Reveniti la meniul principal \n 3 - Iesiti \n";
                                    int iesire;
                                    cin >> iesire;
                                    //daca vrem sa ramanem in meniul de modificat nu facem nimic
                                    //daca vrem sa iesim din program
                                    if(iesire == 3)
                                    {
                                        system("cls");
                                        cout << "Bye, Boss! <3\n";
                                        profil = false;
                                        stop = false;
                                        vremSaModificam = false;
                                    }
                                    else {
                                        //daca vrem sa ne intoarcem la meniul principal
                                        if(iesire == 2)
                                            vremSaModificam = false;
                                        else {
                                            if(iesire != 1)
                                                throw runtime_error("Comanda invalida!");
                                        }
                                    }
                                }

                            }
                            else throw runtime_error("Comanda invalida!");
                        }
                    }
                    break;
                }
            //daca vrem sa afisam lista de clienti inregistrati
            case 4:
                {
                    //verificam daca avem clienti inregistrati
                    if(contorClienti > 0)
                    {
                        //afisam lista clientilor
                        cout << " Lista clientilor inregistrati: \n\n";
                        for(int i = 1; i <= contorClienti; i++)
                            cout << listaClienti[i] << endl;
                        //afisam cati clienti inregistrati avem
                        if(contorClienti == 1)
                            cout << "\n Avem un singur client inregistrat! Se putea si mai bine... \n";
                        else cout << "\n Avem un total de " << contorClienti << " clienti inregistrati! \n Bravo noua!! =) \n";
                    }
                    //daca nu avem clienti
                    else cout << "Nu avem clienti inregistrati =(( \n";
                    //afisam optiunile de iesire
                    bool iesire;
                    cout << "Doriti sa iesiti? [0/1]: ";
                    cin >> iesire;
                    //daca vrm sa iesim
                    if(iesire)
                    {
                        system("cls");
                        cout << "Bye, Boss! <3\n";
                        profil = false;
                        stop = false;
                    }
                    break;
                }
            //daca vrem sa iesim din meniul de administrator
            case 5:
                {
                    profil = false;
                    break;
                }
            //daca vrem sa iesim din program
            case 6:
                {
                    system("cls");
                    cout << "Bye, Boss! <3\n";
                    profil = false;
                    stop = false;
                    break;
                }
            default:
                {
                    throw runtime_error("Comanda necunoscuta! =(");
                    break;
                }
            }
        }
    break;
    }
    default: {
        throw runtime_error("Identitate necunoscuta! =( ");
        break;
    }
    }
    }
    return 0;
}
