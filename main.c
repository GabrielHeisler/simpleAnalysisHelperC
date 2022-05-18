#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUANT_AV 5

bool continuar(){
    bool continua;
    char selector;
    printf("\n\nContinue? [y]es [n]o: ");
    scanf(" %c", &selector);
    switch(selector){
    case 'y':
        continua = true;
        break;
    case 'n':
        continua = false;
        break;
    default:
        continua = false;
        break;
    }
    if(continua == true){
        printf("\n\n\n\n\n");
    }
    return continua;
}



int main(){

    float CI[QUANT_AV], EN[QUANT_AV], HE,  mediaCI, mediaEN, minCI, maxCI, minEN, maxEN;
    minCI = minEN = 100000;
    maxCI = maxEN = 0;
    int minCIind, maxCIind, minENind, maxENind;

    do{
        minCI = minEN = 100000;
        maxCI = maxEN = 0;
        printf("Valor de HE (sem numeros decimais): ");
        scanf("%f", &HE);
        for(int i = 0; i<QUANT_AV; i++){
            printf("Valor de CI %d (sem numeros decimais): ", i+1);
            scanf("%f", &CI[i]);
        }
        printf("\n\n");
        for(int i = 0; i<QUANT_AV; i++){
            printf("Valor de EN %d (sem numeros decimais): ", i+1);
            scanf("%f", &EN[i]);
        }
        for(int i = 0; i<QUANT_AV; i++){
            if(CI[i]>maxCI){
                maxCI = CI[i];
                maxCIind = i;
            }
            if(CI[i]<minCI){
                minCI = CI[i];
                minCIind = i;
            }
            if(EN[i]>maxEN){
                maxEN = EN[i];
                maxENind = i;
            }
            if(EN[i]<minEN){
                minEN = EN[i];
                minENind = i;
            }
        }
        printf(" menor CI = %.2f|%.2f\n maior CI = %.2f|%.2f\n menor EN = %.2f|%.2f\n maior EN = %.2f|%.2f\n", CI[minCIind], minCI, CI[maxCIind], maxCI, EN[minENind], minEN, EN[maxENind], maxEN);

        float somaCI = 0, somaEN = 0;
        for(int i = 0; i<QUANT_AV; i++){
            if(i != maxCIind && i != minCIind){
                somaCI+=CI[i];
            }
            if(i != maxENind && i != minENind){
                somaEN+=EN[i];
            }
        }
        if(maxCIind == minCIind){
            somaCI-=CI[minCIind];
        }
        if(maxENind == minENind){
            somaEN-=EN[minENind];
        }

        printf("\nSoma CI = %.2f\nSoma EN = %.2f", somaCI, somaEN);

        float mediaCI = somaCI/((QUANT_AV-2) * 100);
        float mediaEN = somaEN/((QUANT_AV-2) * 100);
        float mediaHE = HE/100;
        float mediaFinal;

        //printf("\n\nsoma CI = %.3f\nsoma EN = %.3f\n media CI = %.3f\n media EN = %.3f \n HE = %.3f\n media HE = %.3f\n media final = %.3f\n\n", somaCI, somaEN, mediaCI, mediaEN, HE, mediaHE, mediaFinal);

        mediaFinal = ((mediaHE * 2) + (mediaCI * 3) + (mediaEN * 5))/10;
        printf("\n\nMedia final: %.3f", mediaFinal);
    }while(continuar()==true);


}
