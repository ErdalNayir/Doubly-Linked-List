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

            char OkulNo[12];
            char Isim[12];
            char SoyIsim[12];
            char Bolum[12];
            char Sinif[12];

            printf("\n\n");
            printf("Ogrenci Ismi: ");
            scanf("%s",&Isim);
            printf("\n");
            printf("Ogrenci Soyisim: ");
            scanf("%s",&SoyIsim);
            printf("\n");
            printf("Ogrenci Okul Numarasi: ");
            scanf("%s",&OkulNo);
            printf("\n");
            printf("Ogrenci Bolum: ");
            scanf("%s",&Bolum);
            printf("\n");
            printf("Ogrenci Sinif: ");
            scanf("%s",&Sinif);
            printf("\n\n");

            addNode(liste,OkulNo,Isim,SoyIsim,Bolum,Sinif);

        }
        else if(islem==2){
            listCount(liste);
        }
        else if(islem==3){
            traverseBackward(liste);
        }
        else if(islem==4){
            int inx;
            int secim;
            char okulNo[12];
            printf("\n\n");
            printf("1-Okul Numarasina Gore\n");
            printf("2-Indeksine Gore\n");
            printf("Hangi Kritere gore ogrenci aramasi yapmak istiyorsunuz:?");
            scanf("%d",&secim);

            if(secim==2){
                printf("Datasini elde etmek istediginiz node'un inx numarasini giriniz: ");
                scanf("%d",&inx);
                strcpy(okulNo,"-1");
                SearchNode(liste,inx,okulNo);
            }
            else if(secim==1){
                printf("Datasini elde etmek istediginiz node'un okul numarasini giriniz: ");
                scanf("%s",&okulNo);
                inx=-1;
                SearchNode(liste,inx,okulNo);
            }

        }
        else if (islem==5){
           liste= destroyList(liste);

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
