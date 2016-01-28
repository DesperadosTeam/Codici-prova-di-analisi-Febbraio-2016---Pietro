#include <stdio.h>

//Esercizio 1:

int d(int a, int b) {
	while(a>=b) a=a-b;
	return a;
}

int f(int a, int b) {
	int i = 1;
	while (d(i,a) + d(i,b) > 0)
		i++;
	return i;
}

void testes1(int a, int b){
	printf("f(%i,%i) = %i\n", a, b, f(a,b));
}

//Esercizio 2:

int q(int a) {
	return a*a;
}

int e(int a, int b) {
	if (b==0) return 1;
	return a*e(a, b-1);
}

int e10(int a) {
	return e(10, a);
}

int iq(int a) {
	int i;
	for (i=0;q(i)<=a;i++);
	return i-1;
}

int ie10(int a) {
	int i;
	for (i=0;e10(i)<=a;i++);
	return i-1;
}

void testes2iq(int a) {
	printf("iq(%i) = %i\n", a,iq(a));
}

void testes2ie10(int a) {
	printf("ie10(%i) = %i\n", a, ie10(a));
}

//Esercizio 3:
//NOTA: nel codice la funzione l'ho chiamata ff per non creare conflitto con f del primo esercizio.

int ff(int a, int b, int i, int j){
	if (j==a)
		return i;
	if (i+1==b)
		return ff(a, b, 0, j+1);
	else
		return ff(a, b, i+1, j+1);
}

int h(int a, int b) {
	return ff(a,b,0,0);
}

int m(int c) {
	if (c<100) return c;
	return m(c/100);
}

int n(int c) {
	return h(c, 100);
}

int p(int a) {
	return h(m(a), n(a));
}

void testp(int a) {
	printf("p(%i) = %i\n", a, p(a));
}

//NON LEGGERE QUESTA FUNZIONE SE NON VUOI SAPERE COSA FANNO LE FUNZIONI
void soluzioni(int a){
	if (a==1){
		printf("\n\nSoluzioni funzione per funzione:\n");
		printf("\n\nEsercizio 1:\n");
		printf("La funzione <p> non faceva nulla di importante per l'esercizio.\n");
		printf("La funzione <d> è collegata a <f> e restituiva l'MCM tra i due numeri.\n");
		printf("\n\nEsercizio 2:\n");
		printf("La funzione <q> fa il quadrato del numero a\n");
		printf("La funzione <e> eleva a alla b.\n");
		printf("La funzione <e10> ritorna 10 elevato alla a.\n");
		printf("La funzione <iq> ritorna la radice quadrata di a o quella arrotondata per difetto.\n");
		printf("La funzione <ie10> ritorna l'indice della potenza di 10 più vicino al numero a per difetto.\n");
		printf("\n\nEsercizio 3:\n");
		printf("La funzione <p> ritorna la funzione modulo/resto tra le prime due cifre di a e le sue ultime due.\n");
	}
	else
		return;
}

//ADESSO PUOI LEGGERE

int main(){
	printf("\nSoluzioni esericizi:\n\nEsercizio 1:\n");
	testes1(1,2);
	testes1(1000,2);
	testes1(14,2);
	testes1(15,2);
	testes1(1000,3);
	printf("\n\nEsercizio 2:\n");
	testes2iq(25);
	testes2iq(41);
	testes2iq(6);
	testes2iq(90000);
	testes2ie10(2);
	testes2ie10(1223);
	testes2ie10(3321);
	testes2ie10(3213213);
	printf("\n\nEsercizio 3:\n");
	testp(1001);
	testp(1210);
	testp(1310);
	printf("\nAttenzione: il numero inserito successivamente nell'esercizio\nè troppo lungo quindi ne ho messo uno più corto ma che restituisce lo stesso risultato.\n\n");
	testp(131210);
	int a = 0;
	printf("Vuoi leggere le soluzioni testuali? Inserisci 1 per SI, o un qualsiasi altro numero per NO.\n");
	scanf("%i", &a);
	soluzioni(a);
	printf("\nSoluzioni finite.\n");
}
