#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

typedef struct node
{
    char ogrenciNo[12];
    char Ad[12];
    char SoyAd[12];
    char Bolum[12];
    char Sinif[12];

    struct node* Forw;
    struct node* backw;
} NODE;

typedef struct list
{
    int   count;
    NODE* head;
    NODE* rear;
} LIST;

//	Prototype Declarations
NODE* NodeOlustur(char* no, char* ad, char* soyad, char* Bolum, char* Sinif);
void addNode(LIST* pList,char* no, char* ad, char* soyad, char* Bolum, char* Sinif);
void traverseBackward (LIST* pList);
void removeNode(LIST* pList,int index);
LIST* destroyList (LIST* pList);
void SearchNode(LIST* pList,int index,char* no);
LIST* createList();
void listCount(LIST* pList);
int* searchNumber(LIST* pList, char* no);


LIST* createList()
{
//	Local Definitions
	LIST* list;

//	Statements
	list = (LIST*) malloc(sizeof (LIST));
	if (list)
	   {
	    list->head    = NULL;
	    list->count   = 0;
	    list->rear=NULL;
	   } // if
	return list;
}	// createList

NODE* NodeOlustur(char* no, char* ad, char* soyad, char* Bolum, char* Sinif) { // Bu kod ile kod tekrarlarindan kaciniyoruz.

	NODE* pNew= (NODE*)malloc(sizeof(NODE));

    strcpy(pNew->ogrenciNo,no);
    strcpy(pNew->Ad,ad);
    strcpy(pNew->SoyAd,soyad);
    strcpy(pNew->Bolum, Bolum);
    strcpy(pNew->Sinif, Sinif);

	pNew->backw = NULL;
	pNew->Forw = NULL;
	return pNew;
}

int* searchNumber(LIST* pList, char* no){
    NODE* temp= pList->head;
    int isFound=0;
    int index=0;
    static int results[2];


    while(temp!=NULL){
        int result;
        result=strcmp(temp->ogrenciNo,no);
        if(result==0){
            isFound=1;

            results[0]=index;
            results[1]=isFound;

            return results;
        }
        else{
            temp=temp->Forw;
            index++;
        }

    }

     results[0]=index;
     results[1]=isFound;
     return results;

}

void addNode (LIST* pList, char* no, char* ad, char* soyad, char* Bolum, char* Sinif)
{
    //BU FONKSIYON YENI EKLENECEK NODE 'U LISTENIN EN SONUNA EKLER
    if(pList==NULL){
        printf("\n");
        printf("Liste silinmis ya da hic olusturulmamis\n\n");
        return;
    }

    int *results;
    results=searchNumber(pList,no);

    if(results[1]==1){
        printf("\n");
        printf("Bu ogrenci numarasi listede zaten var\n\n");
        printf("%d\n\n",results[0]);
        return;
    }

    NODE* pNew = NodeOlustur(no,ad,soyad,Bolum,Sinif);

	if(pList->head==NULL || pList->count==0) { // Eger liste bos ise

        pList->count=pList->count+1;

		pList->head = pNew;  //Listenin Head nodunu pNew'e isaret ettiriyoruz
        pList->rear=pNew;    //Listenin rear nodunu pNew'e isaret ettiriyoruz
        printf("Node Eklendi\n\n");
		return;
	}
	  else{
            pList->count=pList->count+1;

            pNew->backw=pList->rear; // bu rear en sondaki nodu isaret ediyordu. Bu code ile yeni eklenen node'un back nodu bu nodu isaret eder
            pList->rear=pNew; //pNew yeni en son node oldugundan listenin rearını bu nodu isaret ettiriyoruz
            pNew->backw->Forw=pNew;  //Data nodu pNew'in back nodu'nu eskiden en sonuncu olan data node'duna isaret ettirmistim. Bu kod ile bu data node'dun Forw nodu yeni eklenen nodu isaret edicek
            printf("Node Eklendi\n\n");
        }

}

void removeNode(LIST* pList,int index)
{
    if(pList==NULL){
        printf("\n");
        printf("Liste silinmis ya da hic olusturulmamis\n\n");
        return;
    }

    NODE* temp = pList->head; // Bununla orjinal listeye zarar vermemis oluyoruz

    if(temp==NULL || pList->count==0){  //Liste Bos
        printf("Liste hicbir node bulunmamaktadir\n\n");
        return;
    }

    else if(index>pList->count-1 || index<0){
        printf("Girdiginiz index liste sinirlari disinda\n\n");
        return;
    }

    if (pList->count>1){

        if(index==0 || index==pList->count-1){

        if(index==0){ //bastan silme
            pList->head=pList->head->Forw;
            free(pList->head->backw); //degisiklik var
            pList->head->backw=NULL;
            pList->count=pList->count-1;
            printf("Bastaki node silindi\n\n");
        }
        else if(index==pList->count-1){ //Sondaki node'u silme
            pList->rear=pList->rear->backw;
            free(pList->rear->Forw);
            pList->rear->Forw=NULL;
            pList->count=pList->count-1;
            printf("Sondaki node silindi\n\n");
        }

    }
    else{ // Ortadaki bir nodu silme
         int i =0;

        while(i!=index){
            temp = temp->Forw;
            i++;
        }

        temp->Forw->backw=temp->backw;
        temp->backw->Forw=temp->Forw;
        free(temp);
        pList->count=pList->count-1;
        printf("Sectiginiz node silindi\n\n");

    }

    }
    else {
        free(pList->head);
        pList->head=NULL;
        pList->rear=NULL;
        pList->count=pList->count-1;
        printf("Listede var olan tek node silindi\n\n");
    }

}

bool emptyList (LIST* pList)
{
//	Statements

	return (pList->count == 0);
}	// emptyList


void traverseBackward (LIST* pList)
{
    if(pList==NULL){
        printf("\n");
        printf("Liste silinmis ya da hic olusturulmamis\n\n");
        return;
    }

    NODE* temp = pList->rear; // Bununla orjinal listeye zarar vermemis oluyoruz

	if(temp == NULL || pList->count==0){

        // Bos listedir cikis yap
        printf("Listede eleman bulunmamaktadir\n\n");
        return;
	}

	//backw ile geriye doðru gidiyoruz
	printf("\n\n");
	printf("Reverse: \n");
	int i = pList->count-1;
	while(temp != NULL) {
		printf("%d . Ogrenci Isim: %s \n",i,temp->Ad);
		printf("%d . Ogrenci Soyisim: %s \n",i,temp->SoyAd);
		printf("%d . Ogrenci Okul Numarasi: %s \n",i,temp->ogrenciNo);
		printf("%d . Ogrenci Bolumu: %s \n",i,temp->Bolum);
		printf("%d . Ogrenci Sinifi: %s \n",i,temp->Sinif);
		printf("\n\n");
		temp = temp->backw;
		i--;
	}
	printf("\n");

}

void listCount(LIST* pList)
{
//	Statements
    if(pList==NULL){
        printf("\n");
        printf("Liste silinmis ya da hic olusturulmamis\n\n");
        return;
    }
    printf("Liste Uzunlugu: %d\n\n",pList->count);
}	// listCount

LIST* destroyList (LIST* pList)
{

	if (pList)
    {
        NODE* deletenode;
        while(pList->count>0){
            deletenode = pList->head;
            pList->head = pList->head->Forw;
            pList->count--;

            //Node daki veriler silindi
            free(deletenode);
        }
        printf("Liste Yok Edildi\n\n");
        free(pList);
        return NULL;
    } // if

    else{
        printf("\n");
        printf("Liste zaten silinmis ya da hic olusturulmamis\n\n");
        return NULL;
    }
}	// destroyList

void SearchNode(LIST* pList,int index,char* no){

    if(pList==NULL){
        printf("\n");
        printf("Liste silinmis ya da hic olusturulmamis\n\n");
        return;
    }

    NODE* temp = pList->head; // Bununla orjinal listeye zarar vermemis oluyoruz

    if(temp==NULL || pList->count==0){  //Liste Bos
        printf("Liste hicbir node bulunmamaktadir\n\n");
        return;
    }

    if(strcmp(no,"-1")==0){

        if(index>pList->count-1 || index<0){
            printf("Girdiginiz index liste sinirlari disinda\n\n");
            return;
        }

        for(int i=0; i!=index; i++){
            temp=temp->Forw;
        }

            printf("Aradiginiz Ogrenci Isim: %s \n",temp->Ad);
            printf("Aradiginiz Ogrenci Soyisim: %s \n",temp->SoyAd);
            printf("Aradiginiz Ogrenci Okul Numarasi: %s \n",temp->ogrenciNo);
            printf("Aradiginiz Ogrenci Bolumu: %s \n",temp->Bolum);
            printf("Aradiginiz Ogrenci Sinifi: %s \n",temp->Sinif);
            printf("\n\n");

    }
    else{
         int *results;
        results=searchNumber(pList,no);

        if(results[1]!=1){
            printf("Girdiginiz numaraya kayitli ogrenci bulunamadi\n\n");
        }
        else{
            for(int i=0; i!=results[0]; i++){
                temp=temp->Forw;
            }

            printf("Aradiginiz Ogrenci Isim: %s \n",temp->Ad);
            printf("Aradiginiz Ogrenci Soyisim: %s \n",temp->SoyAd);
            printf("Aradiginiz Ogrenci Okul Numarasi: %s \n",temp->ogrenciNo);
            printf("Aradiginiz Ogrenci Bolumu: %s \n",temp->Bolum);
            printf("Aradiginiz Ogrenci Sinifi: %s \n",temp->Sinif);
            printf("\n\n");

        }

        }
    }



