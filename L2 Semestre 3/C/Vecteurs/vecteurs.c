#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(int argc, char *argv[]) {
	return 0;
}


struct vecteur{
    int *donnees;
    int taille;
};typedef struct vecteur vecteur;



vecteur * creation_vecteur(int taille){
    vecteur *v=malloc(sizeof(*v));
    v->donnees=malloc(sizeof(int)*taille);
    v->taille=taille;
    return v;
}



int modifier_vecteur(vecteur v, int val, int position){
    if (position< v.taille && position>=0){
        v.donnees[position]=val;
        return 1;
    }
    return 0;

}




int valeur_vecteur(vecteur v, int position){
    if (position< v.taille && position>=0){
        return v.donnees[position];
    }
    return INT_MIN;
}



void initialiser_vecteur(vecteur v){
    for(int i=0;i<v.taille;i++){
        v.donnees[i]=i;
    }
}



void affichage_vecteur(vecteur v){
    for(int i=0;i<v.taille;i++){
        printf("%d ",v.donnees[i]);
    }
}

