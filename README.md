## Užduoties formuluotė

* sugeneruoti ~1000 tinklo vartotojų (vardas, public_key, valiutos balansas (100-1000000)
* sugeneruoti transkacijų pol'ą sudarytą iš 10000 atsitiktinių transakcijų tarp visų vartotojų, kurių metu jie vienas kitam atlikinėtų pinigų pervedimus
* iš šių transakcijų atsitiktinai pasirinkti 100-ą ir jas priskirti naujam sugeneruotam blokui
* realizuoti mining Proof-of-Work (PoW) procesą, kurio tikslas yra surasti naujam blokui hash'ą, tenkinantį Difficulty Targer reikalavimą, t.y., hash'o pradžioje esančių nulių skaičių
* suradus tokį naujo bloko hash'ą, bloką pridėti prie grandinės
* kartoti tol, kol yra laisvų transakcijų

## Versijavimas

### v.01

* Hash'avimo procesui turite naudoti pirmąjam darbui sukurtas hash funkcijas.
