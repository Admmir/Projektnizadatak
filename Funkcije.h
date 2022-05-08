#ifndef FUNKCIJE_H_INCLUDED
#define FUNKCIJE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Studenti{
char index[10];
char ime[20];
char prezime[20];
int kviz[10]}Studenti;
//Definisana struktura

Studenti studenti[120];

Studenti grupa[40];

char trash[2];

int odabranosort;

char tempc[40][20];

int odabranagrupa;

int odabraniRB;

void init_load(Studenti studenti[120])
{
FILE * fptr;
fptr = fopen("studenti.txt", "r");

if(fptr == NULL) {printf("Error opening file");}//najlakse provjerava da li file postoji

char buffer[200];

fgets(buffer, 200, fptr);

while(!feof(fptr))
{
Studenti* p=studenti+i;
sscanf(buffer, "%s",&p->index);

fgets(buffer, 200, fptr);
sscanf(buffer, "%s",&p->ime);

fgets(buffer, 200, fptr);
sscanf(buffer, "%s",&p->prezime);

fgets(buffer, 200, fptr);
       //for petlja u ovom slucaju iz nekog razloga nije funkcionisala izgleda glupo trebam prepravit
sscanf(buffer, "%d%s%d%s%d%s%d%s%d%s%d%s%d%s%d%s%d%s%d",&p->kviz[0],&trash[0], &p->kviz[1],&trash[0],&p->kviz[2],&trash[0],
       &p->kviz[3],&trash[0],&p->kviz[4],&trash[0], &p->kviz[5],&trash[0],&p->kviz[6],&trash[0], &p->kviz[7],&trash[0],&p->kviz[8],
       &trash[0], &p->kviz[9]); 
fgets(buffer, 200, fptr);

fgets(buffer,200, fptr);

};






fclose(fptr);
}

void print_studenti()
{
for(int i=0; i<120; i++)
    {
printf("%s\n%s\n%s\n",studenti[i].index,studenti[i].ime, studenti[i].prezime);

for(int y=0;y<10;y++){
        printf("%d ",studenti[i].kviz[y]);
}
printf("\n\n");
};
}

void meni(){

int opcija=0;

while(opcija<1 || opcija>4)
    {//while petlja u slucaju da izabere nesto deseto

printf("Izaberite kako cete sortirati studente:\n 1: po indexu\n 2: po imenu\n 3: po prezimenu\n 4: po broju bodova iz kvizova\n");

printf("Unesite broj ispred opcije: ");

scanf("%d", &opcija);

if(opcija==1){
        printf("Izabrali ste opciju 1\n");
bsort_index(studenti, 120);
odabranosort=1;}
else if(opcija==2){
        printf("Izabrali ste opciju 2\n");
sort_selekcija_ime(studenti, 120);
odabranosort=2;
}
else if(opcija==3){
        printf("Izabrali ste opciju 3\n");
sort_selekcija_prezime(studenti, 120);
odabranosort=3;}
else if(opcija==4){
        printf("Izabrali ste opciju 4\n");
bsort_kviz(studenti, 120);
odabranosort=4;}
else{
        printf("unijeli ste pogresan broj\n");
}

}
print_studenti();
meni2();
}

void sort_selekcija_ime(Studenti studenti[120], int n){
//Od ove dvije bi se mogla napravit jedna funkcija, ako stignem
int i,j;

Studenti temp;

for(i=0;i<n-1;i++)
    {

   for(j=i+1;j<n;j++)
   {
   if(strcmpi (studenti[i].ime, studenti[j].ime)>0)
   {
   temp=studenti[i];
   studenti[i]=studenti[j];
   studenti[j]=temp;
   }
   }

}

}

void sort_selekcija_prezime(Studenti studenti[120], int n){

int i,j;

Studenti temp;

for(i=0;i<n-1;i++)
{

   for(j=i+1;j<n;j++)
   {
   if(strcmpi (studenti[i].prezime, studenti[j].prezime)>0)
   {
   temp=studenti[i];
   studenti[i]=studenti[j];
   studenti[j]=temp;
   }
   }

}

}

void bsort_index(Studenti studenti[120], int s)
{
    int i, j;
    Studenti temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (strcmpi(studenti[j].index ,studenti[j + 1].index)>0)
            {
                strcpy(temp.index, studenti[j].index);
                strcpy (studenti[j].index, studenti[j + 1].index);
                strcpy(studenti[j + 1].index,temp.index);
            }
        }
    }
}

void bsort_kviz(Studenti studenti[120], int s){

int brojk;

int odabir[10];

odabir[0]=0;

while(brojk<1 || brojk>10){
printf("Izabreite koliko kvizova sabirate:\n");
scanf("%d", &brojk);
}
int brojac=brojk;

for(int i=0; i<brojk; i++)
    {
printf("Unesite po zbiru kojih kvizova sortirate, imate jos %d da unesete: ",brojac);

while(odabir[i]<1 || odabir[i]>10)
    {
scanf("%d", &odabir[i]);
if(odabir[i]<1 || odabir[i]>10)
{
    printf("Pogresan broj, unesite ponovo");
}
}
printf("\n");
brojac--;
odabir[i]=odabir[i]-1;
}




int suma[120];
for(int i=0; i<120; i++)
    {
        suma[i]=0;
    }


    for(int i=0;i<120; i++ )
    {
        for(int j=0; j<brojk; j++)
        {
                suma[i]=suma[i]+studenti[i].kviz[odabir[j]];
}
    }



int i;
int look;
int y=120;
    Studenti temp;
    int temp1;

    for (i = 0; i < y - 1; i++)
    {
        for (look = 0; look < (y - 1-i); look++)
        {
            if (suma[look] > suma[look + 1])
            {
                temp1= suma[look];

                temp = studenti[look];
                suma[look]=suma[look + 1];
                studenti[look] = studenti[look + 1];
                suma[look+1]=temp1;
                studenti[look + 1] = temp;

            }
        }
    }





}

void kopiranje(){

if(odabranosort==1)
    {
for(int i=0; i<40;i++)
{
    strcpy(tempc[i], grupa[i].index);
}
}
else if(odabranosort==2)
{
for(int i=0; i<40;i++)
{
    strcpy(tempc[i], grupa[i].ime);
}
}
else if(odabranosort==3)
{
for(int i=0; i<40;i++)
{
    strcpy(tempc[i], grupa[i].prezime);
}
}
else if(odabranosort==4)
{
for(int i=0; i<40;i++)
{
    strcpy(tempc[i], grupa[i].prezime);
}
}
}

void meni2(){

int opcija=0;

while(opcija<1 || opcija>3)
    {//while petlja u slucaju da izabere nesto deseto
printf("Izaberite kako cete rasporediti studente:\n 1: A grupa (prvih 40 sortiranih studenata)\n 2: B grupa (drugih 40 sortiranih studenata)\n");

printf(" 3: C grupa (trecih 40 sortiranih studenata)\n");

printf(" 4: Povratak nazad\n");

printf("Unesite broj ispred opcije: ");

scanf("%d", &opcija);

if(opcija==1)
{
odabranagrupa=1;
printf("Izabrali ste opciju 1\n");
for(int i=0; i<40; i++)
{
strcpy(grupa[i].index,studenti[i].index);
strcpy(grupa[i].ime,studenti[i].ime);
strcpy(grupa[i].prezime,studenti[i].prezime);


}
}

else if(opcija==2)
{
odabranagrupa=2;
printf("Izabrali ste opciju 2\n");

for(int i=40; i<80; i++)
    {
strcpy(grupa[i-40].index,studenti[i].index);
strcpy(grupa[i-40].ime,studenti[i].ime);
strcpy(grupa[i-40].prezime,studenti[i].prezime);


}}
else if(opcija==3)
{
odabranagrupa=3;
printf("Izabrali ste opciju 3\n");
for(int i=80; i<120; i++)
{
strcpy(grupa[i-80].index,studenti[i].index);
strcpy(grupa[i-80].ime,studenti[i].ime);
strcpy(grupa[i-80].prezime,studenti[i].prezime);


}}
else if(opcija==4)
{
printf("Izabrali ste opciju 4\n");
meni();
}
else
{
    printf("unijeli ste pogresan broj\n");
}
}
kopiranje();
prikaz_amfiteatra(tempc);
}



void prikaz_amfiteatra(char dummy2[40][20])
{
int a=176;
int b=177;
int c=178;
int rednibroj=0;
int f=-1;

for(int k=0;k<6;k++)
{
int p;
for(p=0; p<6; p++)
{

for(int z=0;z<10;z++)
{
    printf(" ");
}




for(int i=1;i<9;i++)
    {
int u=20;

if(i==1)
    {

        for(int j=0; j< u;j++)
            {

        if((j>1&&j<19) && p==2)
        {


if(j==2){
    printf("%d.",rednibroj);
rednibroj++;
f++;}
else if (dummy2[f][j-4]!=NULL && rednibroj<=10)
    {
    u=19;
    printf("%c",
    dummy2[f][j-4]);
    }
else if (dummy2[f][j-4]!=NULL && rednibroj>10)
    {
       u=18;
       printf("%c",
       dummy2[f][j-4]);
    }

else
    {
        printf("%c",c);
}

}
else
    {
        printf("%c",c);
}

}



}




else if(i==2){
        for(int x=0; x<20; x++)
{
    printf("%c",b);}
}



else if(i==3){
        for(int j=0; j<20;j++)
{
    printf("%c",a);}
}


else if(i==4){
        for(int j=0; j<u;j++)
        {
if((j>0&&j<19) && p==2){


if(j==2)
{
    printf("%d.",rednibroj);
rednibroj++;
f++;
}

else if (dummy2[f][j-4]!=NULL && rednibroj<=10)
    {
        u=19;
printf("%c",
       dummy2[f][j-4]);
    }

else if (dummy2[f][j-4]!=NULL && rednibroj>10)
    {u=18;
printf("%c",
       dummy2[f][j-4]);
    }

else
    {
        printf("%c",c);
}
}
else{printf("%c",c);}}}


else if(i==5){
        for(int x=0; x<20; x++)
{
    printf("%c",b);}
}


else if(i==6){for(int j=0; j<20;j++)
{printf("%c",a);}}


else if(i==7){
        for(int j=0; j< u;j++)
            {

        if((j>1&&j<19) && p==2){


if(j==2){printf("%d.",rednibroj);rednibroj++;f++;}
else if (dummy2[f][j-4]!=NULL && rednibroj<=10){u=19;printf("%c",dummy2[f][j-4]);
    }
else if (dummy2[f][j-4]!=NULL && rednibroj>10){u=18;printf("%c",dummy2[f][j-4]);
    }

else{printf("%c",c);}
}
else{printf("%c",c);}

}}
else{printf("\n");}
}


}


for(p=0; p<6; p++){
int u=20;
for(int z=0;z<10;z++){printf(" ");}




for(int i=1;i<9;i++){

if(i==1){for(int j=0; j<20;j++)
{
printf("%c",a);}}


else if(i==2){

for(int j=0; j< u;j++)
            {

if((j>1&&j<19) && p==2){


if(j==2){printf("%d.",rednibroj);rednibroj++;f++;}
else if (dummy2[f][j-4]!=NULL && rednibroj<=10){u=19;printf("%c",dummy2[f][j-4]);
    }
else if (dummy2[f][j-4]!=NULL && rednibroj>10){u=18;printf("%c",dummy2[f][j-4]);
    }

else{printf("%c",c);}
}
else{printf("%c",c);}

}}




else if(i==3){for(int j=0; j<20;j++)
{printf("%c",b);}}


else if(i==4){for(int j=0; j<20;j++){

printf("%c",a);}}


else if(i==5){for(int j=0; j< u;j++)
            {

if((j>1&&j<19) && p==2){


if(j==2){printf("%d.",rednibroj);rednibroj++;f++;}
else if (dummy2[f][j-4]!=NULL && rednibroj<=10){u=19;printf("%c",dummy2[f][j-4]);
    }
else if (dummy2[f][j-4]!=NULL && rednibroj>10){u=18;printf("%c",dummy2[f][j-4]);
    }

else{printf("%c",c);}
}
else{printf("%c",c);}

}}


else if(i==6){for(int j=0; j<20;j++)
{printf("%c",b);}}


else if(i==7){for(int j=0; j<20;j++){

printf("%c",a);}}
else{printf("\n");}
}


}


for(p=0; p<6; p++){
int u=20;
for(int z=0;z<10;z++){printf(" ");}




for(int i=1;i<9;i++){

if(i==1){for(int j=0; j<20;j++)
{

printf("%c",b);}}


else if(i==2){for(int x=0; x<20; x++)
{printf("%c",a);}}



else if(i==3){for(int j=0; j< u;j++)
            {

if((j>1&&j<19) && p==2){


if(j==2){if(rednibroj<40){printf("%d.",rednibroj);rednibroj++;f++;}}
else if (dummy2[f][j-4]!=NULL && rednibroj<=10){u=19;printf("%c",dummy2[f][j-4]);
    }
else if (dummy2[f][j-4]!=NULL && (rednibroj>10 && rednibroj<40)){u=18;printf("%c",dummy2[f][j-4]);
    }

else{printf("%c",c);}
if(rednibroj>=39 && j==18){printf("%c",c);}
}
else{printf("%c",c);}

}}


else if(i==4){for(int j=0; j<20;j++){
printf("%c",b);}}


else if(i==5){for(int x=0; x<20; x++)
{printf("%c",a);}}


else if(i==6){for(int j=0; j< u;j++)
            {

if((j>1&&j<19) && p==2){


if(j==2){if(rednibroj<40){printf("%d.",rednibroj);rednibroj++;f++;}}
else if (dummy2[f][j-4]!=NULL && rednibroj<=10){u=19;printf("%c",dummy2[f][j-4]);
    }
else if (dummy2[f][j-4]!=NULL && (rednibroj>10 && rednibroj<40)){u=18;printf("%c",dummy2[f][j-4]);
    }

else{printf("%c",c);}
if(rednibroj>=39 && j==18){printf("%c",c);}
}
else{printf("%c",c);}

}}


else if(i==7){for(int j=0; j<20;j++){

printf("%c",b);}}
else{printf("\n");}
}


}}
odabir();
}

void odabir(){
int bodovi1=0;
int index;
printf("izaberite studenta tako sto cete unijeti redni broj(ili unesite -1 za povratak nazad): ");
int redni;
scanf("%d",&redni);
while(redni>40 || redni<=-2)
{//while petlja u slucaju da izabere nesto deseto


scanf("%d", &redni);
}
if(redni==-1){meni2();}
else{
if(odabranagrupa==1){

printf("%s\n%s\n%s\n",studenti[redni].index,studenti[redni].ime,studenti[redni].prezime);

for(int i=0; i<10; i++){
        printf("%d ",studenti[redni].kviz[i]);
}
printf("\nUpisite redni broj kviza kojeg zelite izmjeniti: ");
scanf("%d",&index);
while(index>10 || index<0){
        printf("Pogresan broj, ponovite: ");
        scanf("%d",&index);
printf("\n");}

index--;

printf("Unesite zeljeni broj bodova za odabrani kviz: ");
scanf("%d",&bodovi1);

while(bodovi1>20 || bodovi1<0)
    {
printf("Pogresan broj, unesite ponovo: ");
scanf("%d",&bodovi1);
}
studenti[redni].kviz[index]=bodovi1;

odabraniRB=redni;

printf("%s\n%s\n%s\n",studenti[redni].index,studenti[redni].ime,studenti[redni].prezime);
for(int i=0; i<10; i++){
        printf("%d ",studenti[redni].kviz[i]);
}
}
else if(odabranagrupa==2){

printf("%s\n%s\n%s\n",studenti[redni+40].index,studenti[redni+40].ime,studenti[redni+40].prezime);

for(int i=0; i<10; i++){
        printf("%d ",studenti[redni+40].kviz[i]);
}
printf("\nUpisite redni broj kviza kojeg zelite izmjeniti: ");
scanf("%d",&index);
while(index>10 || index<0){
        printf("Pogresan broj, ponovite: ");
        scanf("%d",&index);
printf("\n");
}

index--;
printf("Unesite zeljeni broj bodova za odabrani kviz: ");
scanf("%d",&bodovi1);
while(bodovi1>20 || bodovi1<0)
    {
printf("Pogresan broj, unesite ponovo: ");
scanf("%d",&bodovi1);
}
studenti[redni+40].kviz[index]=bodovi1;
odabraniRB=redni+40;
printf("%s\n%s\n%s\n",studenti[redni+40].index,studenti[redni+40].ime,studenti[redni+40].prezime);
for(int i=0; i<10; i++){
        printf("%d ",studenti[redni+40].kviz[i]);
}
}
else if (odabranagrupa==3)
    {
printf("%s\n%s\n%s\n",studenti[redni+80].index,studenti[redni+80].ime,studenti[redni+80].prezime);

for(int i=0; i<10; i++)
    {
        printf("%d ",studenti[redni+80].kviz[i]);
}
printf("\nUpisite redni broj kviza kojeg zelite izmjeniti: ");

scanf("%d",&index);

while(index>10 || index<0)
    {
        printf("Pogresan broj, ponovite: ");
        scanf("%d",&index);
printf("\n");
}

index--;
printf("Unesite zeljeni broj bodova za odabrani kviz: ");
scanf("%d",&bodovi1);
while(bodovi1>20 || bodovi1<0)
    {
printf("Pogresan broj, unesite ponovo: ");
scanf("%d",&bodovi1);
}
studenti[redni+80].kviz[index]=bodovi1;
odabraniRB=redni+80;
printf("%s\n%s\n%s\n",studenti[redni+80].index,studenti[redni+80].ime,studenti[redni+80].prezime);
for(int i=0; i<10; i++)
    {
        printf("%d ",studenti[redni+80].kviz[i]);
}
}
float suma;
for(int z=0; z<10; z++)
{
    suma=suma+studenti[odabraniRB].kviz[z];

}
suma=suma/10;
printf("\nProsjek ocjena iz kviza je: %.2f\nIzmjene su snimljene\n",suma );
upis(studenti);
}
}

void upis(Studenti studenti[120])
{
char datoteka[30]={"studenti.txt"};

FILE * fptr;

fptr = fopen(datoteka, "w");

if(fptr == NULL)
    {
        printf("Error opening file");
}
//najlakse provjerava da li file postoji



rewind(fptr);



for(int j=0; j<120;j++)

{
fprintf(fptr,"%s\n%s\n%s\n",studenti[j].index,studenti[j].ime,studenti[j].prezime);



for(int i=0;i<10;i++){

fprintf(fptr, " %d |",studenti[j].kviz[i]);
}
fprintf(fptr,"\n");
for(int o=0;o<55;o++)
{
    fprintf(fptr,"-");
}
fprintf(fptr,"\n");
}











int odb;


fclose(fptr);
printf("Unesite broj ispred opcije :\n1. Meni\n2. Izlaz\n");
scanf("%d",&odb);
while(odb>2 || odb<0)
    {
printf("Pogresan broj, unesite ponovo: \n");
scanf("%d",&odb);
}
if (odb==1){meni();}
else {exit(0);};
}









#endif // FUNKCIJE_H_INCLUDED

