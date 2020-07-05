
//Jun 2016 - Zad. 3.
#include "stdio.h"
#include "string.h"

void main() {

	int niz[30], n, k;
	
	scanf("%d", &k);

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &niz[i]);
	}
	
	int pozicija = 0, duzina = 0, zbir = 0, minZbir = _CRT_INT_MAX, odredjenaDuzina;
	int i = 0;
	//promenljive pretstavljaju:
	//zbir: zbir elemenata trenutnog podniza
	//duzina: broj cifara trenutnog podniza
	//minZbir: odredjen minimalni zbir nekog prethodnog podniza u odnosu na obradjene podnizove
	//odredjenaDuzina: duzina podniza koji trenutno ima minimalni zbir
	//pozicija: pocetni indeks elementa u nizu, koji je 0-ti u podnizu sa min zbirom
	while (i < n) {
		zbir += niz[i];	//kako je svaki element zasebno nerastuci podniz
		duzina++;		//obradjujemo ga zasebno, pa onda posle naredne elemente
						//ako ispunjavaju uslove
		while (niz[i] >= niz[i + 1] && i < n - 1) {
			i++;		//prvo inkrementujem i, jer je zasebni element vec ubacen
			zbir += niz[i];	//pa samo dodajem sledeci ako je uslov ispunjen
			duzina++;
		}
		

		if (zbir < minZbir) {//proverava da li je podniz sa minimalnim zbirom
			minZbir = zbir;	//ukoliko postoji vise sa istim zbirom, pamti se prvi,
			zbir = 0;		//jer naredni ne ispunjavaju uslov * uslov je da trenutni zbir < od pretMin

			//

			odredjenaDuzina = duzina;
			pozicija = i - odredjenaDuzina + 1;	//poziciju odredjujemo ovako
			duzina = 0;
		}
		i++;
	}

	printf("Br nerastucih pocevsi od elementa %d je: %d\nPozicija podniza sa minZbirom je: %d, duzine: %d", k, brNerastucih(niz, n, k), pozicija, odredjenaDuzina);
}

int brNerastucih(int* niz, int brEl, int k) {

	int pocetni = k, brojNerastucih;

	while (niz[k] >= niz[k + 1] && k < brEl) k++;
	brojNerastucih = k - pocetni + 1; //+1 jer ne moze da ima nula nerastucih, tj. k je indeks

	return brojNerastucih;
}
