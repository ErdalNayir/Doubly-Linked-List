#include <stdio.h>
#include <stdlib.h>
#include "DoublyList.h"
#include <stdbool.h>

int compare( void* p1 ,void* p2 )//compare two integer
{
    if( *(int*)p1 < *(int*)p2 ) return 1;
    else if( *(int*)p1 > *(int*)p2 ) return 1;
    else return 0;
}

int main()
{
    LIST* liste=createList();
    while(true){
        int islem;

        printf("1-Node Ekle\n");
        printf("2-Liste Uzunlugu\n");
        printf("3-Geriye dogru yazdir\n");
        printf("4-Node Ara\n");
        printf("5-Liste Sil\n");
        printf("0-Cikis\n");
        printf("Lutfen Bir islem seciniz: ");
        scanf("%d",&islem);

        if (islem==0){
            printf("Hoscakalin!\n");
            break;
        }
        else if (islem==1){
            int deger;
            printf("\n\n");
            printf("Node'in degerini giriniz: ");
            scanf("%d",&deger);

            addNode(liste,deger);

        }
        else if(islem==2){
            printf("Liste uzunlugu: %d\n\n",liste->count);
        }
        else if(islem==3){
            traverseBackward(liste);
        }
        else if(islem==4){
            int inx;
            printf("\n\n");
            printf("Datasini elde etmek istediginiz node'un index numarasini giriniz: ");
            scanf("%d",&inx);
            SearchNode(liste,inx);
        }
        else if (islem==5){
           liste= destroyList(liste);

        }

    }

}
