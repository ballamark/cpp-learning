#include <iostream>
#include <fstream>

using namespace std;

struct hivas {
    int kezdete;
    int vege;
};

int mpbe(int ora, int perc, int masodperc) {
    return (ora * 60 * 60) + (perc * 60) + masodperc;
}

int main() {

    //2. feladat

    ifstream hivasFile;
    hivasFile.open("hivas.txt");
    hivas hivasok[1000];
    int db = 0;
    int ko, kp, kmp, vo, vp, vmp;
    //a >> jobbra shift operátor, szóval valószínűleg a vezérlés egyet jobbra lép
    while (hivasFile >> ko >> kp >> kmp >> vo >> vp >> vmp) {
        hivasok[db].kezdete = mpbe(ko, kp, kmp);
        hivasok[db].vege = mpbe(vo, vp, vmp);
        db++;
    }
    hivasFile.close();

    //3. feladat

    //24 óra van egy napban, így létrehozunk egy 24 elemű tömböt, és minden index az adott órát jelenti
    //mindegyik elemet nullával inicializálunk, majd ezeket fogjuk növelni mindig egy-egy darabszámmal
    int statisztika[24] = {0};
    for (int ora = 0; ora < db; ++ora) {
        //osztjuk kétszer 60-al, mert másodpercben van megadva, ugye a mpbe függvényben ezt számoltuk ki
        // (egyébként lehet osztani 3600-al, mert annyi a váltószám a másodperc és az óra között)
        int oraSzam = hivasok[ora].kezdete / 60 / 60;
        //megkaptuk az órát, pl: 8 óra, akkor a 8. index helyen növeljük egyel az értéket
        statisztika[oraSzam]++;
    }
    //megvan a statisztika, végig járjuk a 24 elemű tömböt
    for (int ora = 0; ora < 24; ++ora) {
        int darabAzOraban = statisztika[ora];
        //megnézzük, hogy volt-e az adott órában hívás, tehát nagyobb-e az adott óra indexén az érték, mint 0
        if (darabAzOraban > 0) {
            cout << ora << "ora: " << darabAzOraban << endl;
        }
    }

    return 0;
}