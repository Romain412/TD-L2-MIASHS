#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	return 0;
}
struct file{
    int *tableau;
    int taille_tableau;
    int debut;
    int fin;
};typedef struct file file;



file * initialisation_file(int taille){
    file *f;
    f=(file*)malloc(sizeof(file));
    f->tableau=(int*)malloc(sizeof(int)*taille);
    f->taille_tableau=taille;
    f->debut=0;
    f->fin=0;
    return f;
}




int file_vide(file f){
    if (f.fin==f.debut){
        return 1;
    }
    return 0;
}



int file_pleine(file f){
    if (f.fin==f.debut-1){
        return 1;
    }
    return 0;
}




int enfiler(file * f, int element){
    if (file_pleine(*f)==1){
        return -1;
    }
    f->tableau[f->fin]=element;
    f->fin++;
    if (f->fin+1>f->taille_tableau){
        f->fin=0;
    }
}




int defiler(file * f){
    int val;
    if (file_vide(*f)==1) return -1;

    val=f->tableau[f->debut];
    f->debut=(f->debut+1)%f->taille_tableau;
    return val;
}


void affichage_file(file f){
    int i=f.debut;
    printf("|");
    while(i%f.taille_tableau!=f.fin){
        printf("%d|",f.tableau[i]);
        i++;
    }

}



void liberation_file(file * f){
    free(f->tableau);
    free(f);
}






