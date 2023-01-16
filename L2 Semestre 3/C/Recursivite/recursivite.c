#include<stdio.h>
#include<stdlib.h>

int puissance(int x, int n){
    int i,res=x;
    if (n<0)return n;
    if (n==0)return 1;
    if (n==1)return x;
    else{

        for (i=1; i<n;i++){
            res=res*x;
        }
    }
    return res;
}

int fonction_puissance_recursive(int x, int n){
    if (n==0)return 1;
    return(x*fonction_puissance_recursive(x,n-1));
}


int fonction_puissance_recursive_rapide(int x, int n){
    if (n==0)return 1;
    int res,par=1;
    res=fonction_puissance_recursive_rapide(x,n/2);
    if(n%2==1)par=x;
    return(par*res*res);
}

int factorielle_iterative(int n){
    int i,res=1;
    for (i=1;i<=n;i++){
        res=res*i;
    }
    return res;
}



int factorielle_recursive(int n){
    if (n==1)return 1;
    return n*factorielle_recursive(n-1);
}

void tous_les_entiers_de_x_a_y_recursif(int debut, int fin){
    if (debut<=fin){
        printf("%d\n",debut);
        tous_les_entiers_de_x_a_y_recursif(debut+1,fin);
    }
}


int nombre_de_chiffres_recursif(int n){
    int res=1;
    if (n<10)return 1;
    return res+nombre_de_chiffres_recursif(n/10);
}


int pgcd(int a, int b){
    if (b==0)return a;
    return pgcd(b,a%b);
}


int fibonacci_recursif(int n){
    if (n<0)return n;
    if (n==0)return 0;
    if (n==1)return 1;
    return fibonacci_recursif(n-1)+fibonacci_recursif(n-2);
}

int autre_suite(int n){
    int Unm1, Unm2;
    if (n<0)return n;
    if (n==0)return 3;
    if (n==1)return 5;
    Unm1=autre_suite(n-1);
    Unm2=autre_suite(n-2);
    return Unm1*Unm1*Unm2;
}


int encore_suite(int n){
    if (n<0)return n;
    if (n>=3 && n%2==1){
        return 2*encore_suite(n-2);
    }
    return 1;
}


int dichotomie_recursive(int *tab, int debut, int fin, int valeur){

	if (debut>fin)return -1;
	int milieu=(debut+fin)/2;

	if (tab[milieu]==valeur)return milieu;

	if (tab[milieu]>valeur){
	return dichotomie_recursive(tab,debut,milieu-1,valeur);
	}
	return dichotomie_recursive(tab,milieu+1,fin,valeur);
}


int dichotomie(int * tab, int taille, int valeur){
	int milieu=taille/2, debut=0,fin=taille-1;
	while(debut<=fin){
		if(valeur==tab[milieu])return milieu;

		if(valeur<tab[milieu]){
			fin=milieu-1;
		}
		else{
			debut=milieu+1;
		}
		milieu=(debut+fin)/2;
	}
	if(tab[milieu!=valeur])return -1;

	return debut;
}


int partition(int * tab, int d, int f){
	int pivot=d, tmp;
	while(d<f){
		if(pivot==d){
			if(tab[f]>=tab[pivot]){
				f--;
			}
			else{
				tmp=tab[f];
				tab[f]=tab[pivot];
				tab[pivot]=tmp;
				d++;
				pivot=f;
			}
		}
		if(pivot==f){
			if(tab[d]<=tab[pivot]){
				d++;
			}
			else{
				tmp=tab[d];
				tab[d]=tab[pivot];
				tab[pivot]=tmp;
				f--;
				pivot=d;
			}
		}
	}
	return pivot;
}


void tri_rapide(int * tab, int d, int f){
    int pivot;
    if(d<=f){
        pivot=partition(tab,d,f);
        tri_rapide(tab,d,pivot-1);
        tri_rapide(tab,pivot+1,f);
    }
}

int main(int argc, char *argv[]) {
	return 0;
}
