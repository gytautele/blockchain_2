## Užduoties formuluotė
https://github.com/blockchain-group/Blockchain-technologijos/blob/master/pratybos/2uzduotis-Blockchain.md

Pirminė užduotis:
* sugeneruoti ~1000 tinklo vartotojų (vardas, public_key, valiutos balansas (100-1000000)
* sugeneruoti transkacijų pol'ą sudarytą iš 10000 atsitiktinių transakcijų tarp visų vartotojų, kurių metu jie vienas kitam atlikinėtų pinigų pervedimus
* iš šių transakcijų atsitiktinai pasirinkti 100-ą ir jas priskirti naujam sugeneruotam blokui
* realizuoti mining Proof-of-Work (PoW) procesą, kurio tikslas yra surasti naujam blokui hash'ą, tenkinantį Difficulty Targer reikalavimą, t.y., hash'o pradžioje esančių nulių skaičių
* suradus tokį naujo bloko hash'ą, bloką pridėti prie grandinės
* kartoti tol, kol yra laisvų transakcijų

## Versijavimas

### v.01

* Pirminis supratimas apie Blockchain. Ne visos funkcijos pridėtos, tai tik pirminė versija, kuroje realizuota blockchain struktūra ir jų mine'ninimas.
Programa pasileidžia naudojant ```g++ block.cpp blockchain.cpp main.cpp sha256.cpp -o programa```

### v.02

* Pakeista programos struktūra, iš esmės perdaryta programa, nors struktūra išlieka panaši. Pridėta user'io, mychain, transakcijų klasės. Ištaisyta, kad atitiktų reikalavimus.
* atlikta transakcijų pool'e esančių transakcijų verifikavimas
* patikrinti balansas
* patikrinti transakcijos hash'as
* patobulintas blokų kasimo (mininimo) procesas pagal pateiktą logiką

### v.03

* Nuo šios versijos yra būtina turėti prieigą prie pilno Bitcoin mazgo (angl. Bitcoin full node).
* Įsidiegta biblioteka *libbitcoin-system: Bitcoin Cross-Platform C++ Development Toolkit
* Adaptuota merkle tree funkcija programiniame kode
