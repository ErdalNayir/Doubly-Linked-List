#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int dataPtr;
    struct node* Forw;
    struct node* backw;
    int index;
} NODE;

typedef struct list
{
    int   count;
    NODE* head;
    NODE* rear;
} LIST;

//	Prototype Declarations
NODE* NodeOlustur(int data);
void addNode(LIST* pList,NODE* pNew);
void traverseBackward (LIST* pList);
void removeNode(LIST* pList,int index);
LIST* destroyList (LIST* pList);
void SearchNode(LIST* pList,int index);
LIST* createList();
void listCount(LIST* pList);



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

NODE* NodeOlustur(int data) { // Bu kod ile kod tekrarlarindan kaciniyoruz.

	NODE* pNew= (NODE*)malloc(sizeof(NODE));
	pNew->dataPtr = data;
	pNew->backw = NULL;
	pNew->Forw = NULL;
	pNew->index=0;
	return pNew;
}

void addNode (LIST* pList, NODE* pNew)
{
    //BU FONKSIYON YENI EKLENECEK NODE 'U LISTENIN EN SONUNA EKLER
    if(pList==NULL){
        printf("\n");
        printf("Liste silinmis ya da hic olusturulmamis\n\n");
        return;
    }


	if(pList->head==NULL || pList->count==0) { // Eger liste bos ise

        pNew->index=pList->count;
        pList->count=pList->count+1;

		pList->head = pNew;  //Listenin Head nodunu pNew'e isaret ettiriyoruz
        pList->rear=pNew;    //Listenin rear nodunu pNew'e isaret ettiriyoruz
        printf("Node Eklendi\n\n");
		return;
	}
	  else{
            pNew->index=pList->count;
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

    while(temp->index!=index){
        temp = temp->Forw;
    }

    if(index==0 || index==pList->count-1){

        if(index==0){ //bastan silme
            pList->head=pList->head->Forw;
            pList->head->backw=NULL;
            free(pList->head->backw);
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
        temp->Forw->backw=temp->backw;
        temp->backw->Forw=temp->Forw;
        free(temp);
        pList->count=pList->count-1;
        printf("Sectiginiz node silindi\n\n");

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

	if(temp == NULL || pList->count==0) // Bos listedir cikis yap
        return;

	//backw ile geriye doðru gidiyoruz
	printf("\n\n");
	printf("Reverse: \n");
	int i = pList->count-1;
	while(temp != NULL) {
		printf("%d . Node Data: %d \n",i,temp->dataPtr);
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
            deletenode    = pList->head;
            pList->head  = pList->head->Forw;
            pList->count--;
            free (deletenode);

        }
        free(pList);
        return NULL;
    } // if

    else{
        printf("\n");
        printf("Liste zaten silinmis ya da hic olusturulmamis\n\n");
        return NULL;
    }
}	// destroyList

void SearchNode(LIST* pList,int index){

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

   while(temp!= NULL){

        if(temp->index==index){
            printf("Aradiginiz Node Bulundu!\n");
            printf("Aradiginiz Node'un Datasi: %d\n\n",temp->dataPtr);
            break;
        }
        temp = temp->Forw;
   }

}
