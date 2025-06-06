#include <stdio.h>
#include <stdlib.h>


void ImprimirSaida(char * lista){
    printf("O número convertido é: %s\n", &lista[0]);
}


int exponenciacao(int base, int expo){
    int valor = base;
    if(expo == 0){
        valor = 1;
    }else if(expo == 1){
        valor = base;
    }else{
        for(int i =1; i<expo; i++){
            valor = valor * base;
        }
    }
    return valor;

}



int charPraIntDeci(char vetor[]){
    int contador = 0;
    int expoente= 0;
    int numeroDec = 0;
    for(int i = 0; i < 10; i++){
        if(vetor[i] != '\0'){
            contador +=1;


        }
    }
    int numeros[contador];
    for(int k =0; k< contador; k++){
        numeros[k] = vetor[k] - '0';
    }
    for(int j = (contador-1); j >=0; j--){
        int multiplicando = exponenciacao(10,expoente);
        numeroDec = numeroDec + (numeros[j]*multiplicando);
        expoente +=1;
    }

    return numeroDec;

}



char * intDeciPraChar(int numero){

    char * vetorInterm = (char *)malloc(50 * sizeof(char));
    char * vetorDefini = (char *)malloc(50 * sizeof(char));
    int i = 0;
    while (numero > 0) {
        int digito = numero % 10;

        vetorInterm[i] = digito + '0';
        numero /= 10;
        i++;

    }
    i = 0;
    for(int j = 49; j >=0; j--){

        if(vetorInterm[j] != '\0'){
            vetorDefini[i] = vetorInterm[j];
            i++;
        }

    }

    return vetorDefini;

}



char * conversorB(int * be, int * bs, char * valor){
    char * valorSaiConvertidoD = (char *) malloc(50 * sizeof(char));
    if((*be) == 1){ // converte binário para decimal
        int contador = 0;
        int expoente = 0;
        int decimal = 0;
        if ((*bs) == 1){
            ImprimirSaida(valor);
        }
        for(int i = 0; i < 10; i++){
            if(valor[i] != '\0'){
                contador +=1;


            }
        }

        int numeros[contador];
        for(int k =0; k< contador; k++){
            numeros[k] = valor[k] - '0';
        }

        for(int j = (contador-1); j >=0; j--){
            int multiplicando = exponenciacao(2,expoente);
            decimal = decimal + (numeros[j]*multiplicando);
            expoente +=1;

        }
        if((*bs) == 3){
            valorSaiConvertidoD = intDeciPraChar(decimal);
            ImprimirSaida(valorSaiConvertidoD);
        }else if((*bs) == 2){
            //mandar o número em decimal para o conversor octal
        }else if((*bs) == 4){
            //mandar o número em decimal para o conversor hexadecimal
        }
    }else if((*be) == 3){ //converte decimal para binário
        int numeroDe =charPraIntDeci(valor);
        char * valorInterConvertidoB = (char *) malloc(50 * sizeof(char));
        char * valorSaiConvertidoB = (char *) malloc(50 * sizeof(char));
        int i = 0;
        while(numeroDe > 0){
            if(numeroDe == 1){
                valorInterConvertidoB[i] = numeroDe + '0';
                numeroDe = numeroDe/2;
                i++;
            }else{
                int resto = numeroDe % 2;
                valorInterConvertidoB[i] = resto + '0';
                numeroDe = numeroDe/2;
                i++;
            }

        }
        i = 0;
        for(int j = 49; j >=0; j--){

            if(valorInterConvertidoB[j] != '\0'){
                valorSaiConvertidoB[i] = valorInterConvertidoB[j];
                i++;
            }

        }
        ImprimirSaida(valorSaiConvertidoB);


    }

}




int main(){

    int be; //base de entrada
    int bs; //base de saída
    int * pbe;
    int * pbs;
    pbe = &be;
    pbs = &bs;
    char * valorSaidaFinal = (char * ) malloc(50 * sizeof(char)); // valor saída

    printf("digite qual base de entrada deseja usar: \n"); // opções da base de entrada
    printf("1 - para binária\n"); //digite 1 para entrar números binários
    printf("2 - para octal\n"); //digite 2 para entrar números octais
    printf("3 - para decimal\n"); //digite 3 para entrar números decimais
    printf("4 - para hexadecimal\n"); //digite 4 para entrar números hexadecimais

    scanf("%d",&be); //escaneia a opção desejada

    printf("digite para qual base a seja deve ser convertida: \n"); // opções da base de saída
    printf("1 - para binária\n"); //digite 1 para sair números binários
    printf("2 - para octal\n"); //digite 2 para sair números octais
    printf("3 - para decimal\n"); //digite 3 para sair números decimais
    printf("4 - para hexadecimal\n"); //digite 4 para sair números hexadecimais

    scanf("%d",&bs); //escaneia a opção desejada

    switch (be)
    {
    case 1:
        int controleBi = 0; //variavel booleana para controle do número binário
        char valorEntraB[10] = {}; // variavel par1a armazenar a entrada em binário
        printf("Se colocar um espaço vazio no meio do número, ");
        printf("tudo depois dele será desconsiderado\n");
        printf("digite abaixo o valor binário que deseja converter com até 10 caractéres: \n");

        while(controleBi == 0){
            scanf("%s", &valorEntraB);
            for(int i =0; i <10; i++){
                if(valorEntraB[i] == '1' || valorEntraB[i] == '0' || valorEntraB[i] == '\0'){
                    controleBi = 1;

                }else{
                    controleBi = 0;
                    break;
                }

            }

            if(controleBi == 0){
                printf("Digite um número binário com até 10 caractéres ");
            }
        }
        conversorB(pbe,pbs,valorEntraB);
        break;
    case 2:

        break;

    case 3:
        int controleDec = 0;
        char valorEntraD[7] = {};
        printf("Se colocar um espaço vazio no meio do número, ");
        printf("tudo depois dele será desconsiderado\n");
        printf("digite abaixo o valor decimal que deseja converter com até 7 caractéres: \n");

        while(controleDec == 0){
            scanf("%s", &valorEntraD);
            for(int i =0; i <7; i++){
                if(valorEntraD[i] == '0' || valorEntraD[i] == '1' || valorEntraD[i] == '\0'|| valorEntraD[i] == '2' || valorEntraD[i] == '3'|| valorEntraD[i] == '4'|| valorEntraD[i] == '5'|| valorEntraD[i] == '6'|| valorEntraD[i] == '7'|| valorEntraD[i] == '8'|| valorEntraD[i] == '9'){
                    controleDec = 1;
                }else{
                    controleDec = 0;
                    break;
                }

            }

            if(controleDec == 0){
                printf("Digite um número decimal com até 7 caractéres ");
            }
        }
        if(bs ==1){
            conversorB(pbe,pbs,valorEntraD);
        }
        if(bs == 2){

        }
        if(bs == 4){

        }
        break;

    case 4:

        break;
    default:
        printf("digite uma das opções válidas: \n");
        printf("1 - para binária\n"); //digite 1 para entrar números binários
        printf("2 - para octal\n"); //digite 2 para entrar números octais
        printf("3 - para decimal\n"); //digite 3 para entrar números decimais
        printf("4 - para hexadecimal\n"); ////digite 4 para entrar números hexadecimais'

    }
    return 0;

}
