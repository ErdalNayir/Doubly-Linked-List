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
} LIST;

//	Prototype Declarations

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
	   } // if
    printf("Liste Olusturuldu\n\n");
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

void addNode (LIST* pList, int dataInPtr)
{
    //BU FONKSIYON YENI EKLENECEK NODE 'U LISTENIN EN SONUNA EKLER
    if(pList==NULL){
        printf("\n");
        printf("Liste silinmis ya da hic olusturulmamis\n\n");
        return;
    }

	NODE* pNew = NodeOlustur(dataInPtr);
	NODE* temp = pList->head; // Bununla orjinal listeye zarar vermemis oluyoruz

	if(pList->head==NULL || pList->count==0) { // Eger liste bos ise
        pNew->index=pList->count;
        pList->count=pList->count+1;
		pList->head = pNew;
		printf("Node Eklendi\n\n");
		return;
	}
	while(temp->Forw != NULL) temp = temp->Forw; // Bu En son node kadar gidecek.

	//En son node gelindiði zaman
	pNew->index=pList->count;
	temp->Forw = pNew;
	pNew->backw = temp;
	pList->count=pList->count+1;

	printf("Node Eklendi\n\n");

}

/*
void removeNode  (LIST*  pList, void*  keyPtr,
                  void** dataOutPtr)
{
//	Local Definitions

}	// removeNode



static bool searchNode (LIST*  pList,
                          void*  pArgu,
                          void** dataOutPtr)
{
//	Local Definitions

}	// retrieveNode
*/

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

    NODE* temp = pList->head; // Bununla orjinal listeye zarar vermemis oluyoruz
	if(temp == NULL || pList->count==0) return; // Bos listedir cikis yap


	// Ters basmak icin son node'a kadar gidiyoruz
	while(temp->Forw != NULL) {
		temp= temp->Forw;
	}
	//backw ile geriye doðru gidiyoruz
	printf("\n\n");
	printf("Reverse: \n");
	while(temp != NULL) {
		printf("%d . Node Data: %d \n",temp->index,temp->dataPtr);
		temp = temp->backw;
	}
	printf("\n");

}

int listCount(LIST* pList)
{
//	Statements
    if(pList==NULL){
        printf("\n");
        printf("Liste silinmis ya da hic olusturulmamis\n\n");
        return;
    }
	return pList->count;

}	// listCount

LIST* destroyList (LIST* pList)
{
//	Local Definitions

//	Statements
	if (pList!=NULL)
	   {
	    free (pList);
        printf("\n\n");
        printf("Liste Yok edildi\n\n");
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
