#include<stdio.h>
#include<stdlib.h>


struct liste{
    int valeur;
   struct liste *next;
};typedef struct liste liste;



liste * creation_maillon(int n){
    liste *l=malloc(sizeof(*l));
    l->valeur=n;
    l->next=NULL;
    return l;
}

int est_vide(liste * l){
    if(l==NULL)return 1;
    return 0;
}

void affichage_liste1(liste * l){
    while (l!=NULL){
        printf("%d->",l->valeur);
        l=l->next;
    }
    printf("NULL");
}


void affichage_liste_rec(liste * l){
    if (l!=NULL){
        printf("%d->",l->valeur);
        affichage_liste_rec(l->next);
    }
    else{
        printf("NULL");
    }
}


void affichage_liste_rec_a_l_envers(liste * l){
    if (l!=NULL){
        affichage_liste_rec_a_l_envers(l->next);
        printf("<-%d",l->valeur);
    }
    else{
        printf("NULL");
    }
}



liste * ajoute_tete(liste * l, liste * e){
    e->next=l;
    return e;
}


liste * suppression_tete(liste * l){
    if(l==NULL)return NULL;
    liste *tmp=l->next;
    free(l);
    return tmp;
}



liste * ajoute_queue(liste * l, liste * e){
    liste *tmp=l;
    if(l==NULL)return e;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=e;
    return l;
}



liste * ajoute_queue_rec(liste * l, liste * e){
    if(l==NULL)return e;
    l->next=ajoute_queue_rec(l->next, e);
    return l;
}


liste * suppression_queue(liste * l){
    liste *tmp=l;
    if(l==NULL)return NULL;
    if(l->next==NULL){
        free(l);
        return NULL;
    }
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    free(tmp->next);
    tmp->next=NULL;
    return l;
}



liste * suppression_queue_rec(liste * l){
    if(l==NULL)return NULL;
    if(l->next==NULL){
        free(l);
        return NULL;
    }
    l->next=suppression_queue_rec(l->next);
    return l;
}


liste * recherche(liste * l, int e){
    while(l!=NULL && l->valeur!=e){
        l=l->next;
    }
    return l;
}

liste * recherche_rec(liste * l, int e){
    if(l!=NULL && l->valeur==e)return l;

    if(l!=NULL && l->valeur!=e){
    l->next=recherche_rec(l->next,e);
    return l;
    }
}


liste * efface_premiere_occ_rec(liste * l, int e){
    liste *tmp=l;
    if(tmp->valeur==e){//si l'element est en debut de liste
        l=tmp->next;
        free(tmp);
        return l;
    }
    if((tmp->next)->valeur==e && (tmp->next)->next==NULL){//si il est a la fin
        l=tmp->next;
        free(tmp->next);
        return l;
    }

    if ((tmp->next)->valeur==e){ //si il est n'importe ou dans la liste
        tmp->next=(tmp->next)->next;
        free(tmp->next);
    }
    else{
        tmp->next=efface_premiere_occ_rec(tmp->next,e);//si on n'a pas encore trouve
        return l;
    }
}


void liberation(liste * l){
    liste *tmp=l;
    while(tmp!=NULL){
        free(tmp);
        tmp=tmp->next;
    }
}



void liberation_rec(liste * l){
    if (l!=NULL){
        liberation_rec(l->next);
        free(l);
    }
}


int main(int argc, char *argv[]) {
	return 0;
}
