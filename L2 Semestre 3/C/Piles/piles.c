#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	return 0;
}

struct pile{
    int *tab;
    int nb_elements;
    int taille_max;
};
typedef struct pile pile;


pile * creation_pile(int taille){
    pile *p=malloc(sizeof(p));
    p->tab=malloc(sizeof(int)*taille);
    p->nb_elements=0;
    p->taille_max=taille;
    return p;
}



int pile_est_vide(pile * p){
    if (p->nb_elements==0){
        return 1;
    }
    return 0;
}



int pile_est_pleine(pile * p){
    if (p->nb_elements==p->taille_max){
        return 1;
    }
    return 0;
}



int empiler(pile * p, int val){
    if (p->taille_max>p->nb_elements){
        p->tab[p->nb_elements]=val;
        p->nb_elements++;
        return val;
    }
    return INT_MIN;
}



int depiler(pile * p){
    if (p->nb_elements!=0){
        p->nb_elements--;
        return p->tab[p->nb_elements];
    }
    return INT_MIN;
}



void affichage_pile(pile * p){
    if (p->nb_elements==0){
        printf("|");
    }
    else{
        for(int i=0;i<p->nb_elements-1;i++){
            printf("%d|",p->tab[i]);
        }
    printf("%d",p->tab[p->nb_elements-1]);
    }
}




