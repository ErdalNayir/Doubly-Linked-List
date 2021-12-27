#include <stdio.h>
#include <stdlib.h>
#include "DoublyList.h"
#include <stdbool.h>


int main()
{
    LIST* liste=createList();
    printf("Liste Olusturuldu\n\n");
    while(true){
        int islem;

        printf("1-Node Ekle\n");
        printf("2-Liste Uzunlugu\n");
        printf("3-Geriye dogru yazdir\n");
        printf("4-Node Ara\n");
        printf("5-Liste Yok Et\n");
        printf("6-Node Sil\n");
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

            NODE* pNew=NodeOlustur(deger);

            addNode(liste,pNew);

        }
        else if(islem==2){
            listCount(liste);
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
           printf("Liste Yok Edildi\n\n");

        }
        else if (islem==6){
            int inx;
            printf("\n\n");
            printf("Silmek istediginiz node'un index numarasini giriniz: ");
            scanf("%d",&inx);
            removeNode(liste,inx);
        }

    }

}
