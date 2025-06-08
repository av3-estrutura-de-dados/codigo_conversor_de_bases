#include <stdio.h>
#include <stdlib.h>

char * conversorO(int * be, int * bs, char * valor);
char * conversorH(int * be, int * bs, char * valor);

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



int charPraIntDeci(int * be,char vetor[]){
    int contador = 0;
    int expoente= 0;
    int numeroDec = 0;
    int limitador = 0;
    if((*be) == 1){
        for(int i = 0; i < 10; i++){
            if(vetor[i] != '\0'){
                contador +=1;
            }
        }
    }else if((*be) == 2){
        for(int i = 0; i < 7; i++){
            if(vetor[i] != '\0'){
                contador +=1;
            }
        }

    }else if((*be) == 3){
        for(int i = 0; i < 7; i++){
            if(vetor[i] != '\0'){
                contador +=1;
            }
        }

    }else if((*be) == 5){
        for(int i = 0; i < 7; i++){
            if(vetor[i] != '\0'){
                contador +=1;
            }
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
        valorSaiConvertidoD = intDeciPraChar(decimal);
        if((*bs) == 3){
            ImprimirSaida(valorSaiConvertidoD);
        }else if((*bs) == 2){
            (*be) = 3;
        	conversorO(be,bs,valorSaiConvertidoD);
        }else if((*bs) == 4){ ;//mandar o número em decimal para o conversor hexadecimal
            (*be) = 3;
            conversorH(be,bs,valorSaiConvertidoD);
        }
    }else if((*be) == 3){ //converte decimal para binário
        int numeroDe =charPraIntDeci(be ,valor);
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




char * conversorO(int * be, int * bs, char * valor){
    char * valorSaiConvertidoD = (char *) malloc(50 * sizeof(char));
    if((*be) == 2){ // converte octal para decimal
        int contador = 0;
        int expoente = 0;
        int decimal = 0;
        if ((*bs) == 2){
            ImprimirSaida(valor);
        }
        for(int i = 0; i < 7; i++){
            if(valor[i] != '\0'){
                contador +=1;


            }
        }

        int numeros[contador];
        for(int k =0; k< contador; k++){
            numeros[k] = valor[k] - '0';
        }

        for(int j = (contador-1); j >=0; j--){
            int multiplicando = exponenciacao(8,expoente);
            decimal = decimal + (numeros[j]*multiplicando);
            expoente +=1;

        }
        valorSaiConvertidoD = intDeciPraChar(decimal);
        if((*bs) == 3){
            ImprimirSaida(valorSaiConvertidoD);
        }else if((*bs) == 1){ //mandar o número em decimal para o conversor binário
        	(*be) = 3;
        	conversorB(be,bs,valorSaiConvertidoD); //mandar o número em decimal para o conversor hexadecimal
        }else if((*bs) == 4){
            (*be) = 3;
            conversorH(be,bs,valorSaiConvertidoD);
        }
    }else if((*be) == 3){ //converte decimal para binário
        int numeroDe =charPraIntDeci(be,valor);
        char * valorInterConvertidoO = (char *) malloc(50 * sizeof(char));
        char * valorSaiConvertidoO = (char *) malloc(50 * sizeof(char));
        int i = 0;
        while(numeroDe > 0){
            if(numeroDe == 1){
                valorInterConvertidoO[i] = numeroDe + '0';
                numeroDe = numeroDe/8;
                i++;
            }else{
                int resto = numeroDe % 8;
                valorInterConvertidoO[i] = resto + '0';
                numeroDe = numeroDe/8;
                i++;
            }

        }
        i = 0;
        for(int j = 49; j >=0; j--){

            if(valorInterConvertidoO[j] != '\0'){
                valorSaiConvertidoO[i] = valorInterConvertidoO[j];
                i++;
            }

        }
        ImprimirSaida(valorSaiConvertidoO);


    }

}



char * conversorH(int * be, int * bs, char * valor){
    char * valorSaiConvertidoD = (char *) malloc(50 * sizeof(char));
    if((*be) == 4){ // converte hexadecimal para decimal
        int contador = 0;
        int expoente = 0;
        int decimal = 0;
        if ((*bs) == 4){
            ImprimirSaida(valor);
        }
        for(int i = 0; i < 5; i++){
            if(valor[i] != '\0'){
                contador +=1;


            }
        }

        int numeros[contador];
        for(int k =0; k< contador; k++){
            if(valor[k] == 'a' || valor[k] == 'A'){
                numeros[k] = 10;
            }else if(valor[k] == 'b' || valor[k] == 'B'){
                numeros[k] = 11;
            }else if(valor[k] == 'c' || valor[k] == 'C'){
                numeros[k] = 12;
            }else if(valor[k] == 'd' || valor[k] == 'D'){
                numeros[k] = 13;
            }else if(valor[k] == 'e' || valor[k] == 'E'){
                numeros[k] = 14;
            }else if(valor[k] == 'f' || valor[k] == 'F'){
                numeros[k] = 15;
            }else{
                numeros[k] = valor[k] - '0';
            }
        }

        for(int j = (contador-1); j >=0; j--){
            int multiplicando = exponenciacao(16,expoente);
            decimal = decimal + (numeros[j]*multiplicando);
            expoente +=1;

        }
        valorSaiConvertidoD = intDeciPraChar(decimal);
        if((*bs) == 3){
            ImprimirSaida(valorSaiConvertidoD);
        }else if((*bs) == 1){ //mandar o número em decimal para o conversor binário
        	(*be) = 3;
        	conversorB(be,bs,valorSaiConvertidoD);
        }else if((*bs) == 2){
            (*be) = 3;
        	conversorO(be,bs,valorSaiConvertidoD);
        }
    }else if((*be) == 3){ //converte decimal para hexadecimal
        int numeroDe =charPraIntDeci(be, valor);
        char * valorInterConvertidoH = (char *) malloc(50 * sizeof(char));
        char * valorSaiConvertidoH = (char *) malloc(50 * sizeof(char));
        int i = 0;
        while(numeroDe > 0){
            if(numeroDe == 1){
                valorInterConvertidoH[i] = numeroDe + '0';
                numeroDe = numeroDe/16;
                i++;
            }else{
                int resto = numeroDe % 16;
                if(resto == 10){
                    valorInterConvertidoH[i] = 'A';
                }else if(resto == 11){
                    valorInterConvertidoH[i] = 'B';
                }else if(resto == 12){
                    valorInterConvertidoH[i] = 'C';
                }else if(resto == 13){
                    valorInterConvertidoH[i] = 'D';
                }else if(resto == 14){
                    valorInterConvertidoH[i] = 'E';
                }else if(resto == 15){
                    valorInterConvertidoH[i] = 'F';
                }else{
                    valorInterConvertidoH[i] = resto + '0';
                }
                numeroDe = numeroDe/16;
                i++;
            }

        }
        i = 0;
        for(int j = 49; j >=0; j--){

            if(valorInterConvertidoH[j] != '\0'){
                valorSaiConvertidoH[i] = valorInterConvertidoH[j];
                i++;
            }

        }
        ImprimirSaida(valorSaiConvertidoH);


    }

}


int main(){
    int controleBaseEntra = 0;
    int controleBaseSai = 0;
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

    while(controleBaseEntra == 0){
        if(be == 1 || be == 2 || be == 3 || be == 4){
            controleBaseEntra = 1;
        }else{
            printf("digite uma das opções válidas: \n");
            printf("1 - para binária\n"); //digite 1 para entrar números binários
            printf("2 - para octal\n"); //digite 2 para entrar números octais
            printf("3 - para decimal\n"); //digite 3 para entrar números decimais
            printf("4 - para hexadecimal\n"); ////digite 4 para entrar números hexadecimais'
            scanf("%d", &be);

        }     

    }

    printf("digite para qual base a seja deve ser convertida: \n"); // opções da base de saída
    printf("1 - para binária\n"); //digite 1 para sair números binários
    printf("2 - para octal\n"); //digite 2 para sair números octais
    printf("3 - para decimal\n"); //digite 3 para sair números decimais
    printf("4 - para hexadecimal\n"); //digite 4 para sair números hexadecimais

    scanf("%d",&bs); //escaneia a opção desejada

    while(controleBaseSai == 0){
        if(bs == 1 || bs == 2 || bs == 3 || bs == 4){
            controleBaseSai = 1;
        }else{
            printf("digite uma das opções válidas: \n");
            printf("1 - para binária\n"); //digite 1 para entrar números binários
            printf("2 - para octal\n"); //digite 2 para entrar números octais
            printf("3 - para decimal\n"); //digite 3 para entrar números decimais
            printf("4 - para hexadecimal\n"); ////digite 4 para entrar números hexadecimais'
            scanf("%d", &bs);

        }     

    }    

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
    	int controleOc = 0;
        char valorEntraO[7] = {};
        printf("Se colocar um espaço vazio no meio do número, ");
        printf("tudo depois dele será desconsiderado\n");
        printf("digite abaixo o valor octal que deseja converter com até 7 caractéres: \n");

        while(controleOc == 0){
            scanf("%s", &valorEntraO);
            for(int i =0; i <7; i++){
                if(valorEntraO[i] == '0' || valorEntraO[i] == '1' || valorEntraO[i] == '\0'|| valorEntraO[i] == '2' || valorEntraO[i] == '3'|| valorEntraO[i] == '4'|| valorEntraO[i] == '5'|| valorEntraO[i] == '6'|| valorEntraO[i] == '7'){
                    controleOc = 1;
                }else{
                    controleOc = 0;
                    break;
                }

            }

            if(controleOc == 0){
                printf("Digite um número octal com até 7 caractéres ");
            }
        }
    	conversorO(pbe,pbs,valorEntraO);

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
            conversorO(pbe,pbs,valorEntraD);
        }
        if(bs == 3){
            ImprimirSaida(valorEntraD);
        }
        if(bs == 4){
            conversorH(pbe,pbs,valorEntraD);
        }
        break;

    case 4:
        int controleHe = 0;
        char valorEntraH[5] = {};
        printf("Se colocar um espaço vazio no meio do número, ");
        printf("tudo depois dele será desconsiderado\n");
        printf("digite abaixo o valor hexadecimal que deseja converter com até 5 caractéres: \n");

        while(controleHe == 0){
            scanf("%s", &valorEntraH);
            for(int i =0; i <5; i++){
                if(valorEntraH[i] == '0' || valorEntraH[i] == '1' || valorEntraH[i] == '\0'|| valorEntraH[i] == '2' || valorEntraH[i] == '3'|| valorEntraH[i] == '4'||
                   valorEntraH[i] == '5'|| valorEntraH[i] == '6'|| valorEntraH[i] == '7' || valorEntraH[i] == '8' || valorEntraH[i] == '9'|| valorEntraH[i] == 'a'
                   || valorEntraH[i] == 'A'|| valorEntraH[i] == 'b'|| valorEntraH[i] == 'B'|| valorEntraH[i] == 'c'|| valorEntraH[i] == 'C'|| valorEntraH[i] == 'd'
                   || valorEntraH[i] == 'D'|| valorEntraH[i] == 'e'|| valorEntraH[i] == 'E'|| valorEntraH[i] == 'f'|| valorEntraH[i] == 'F'){
                    controleHe = 1;
                }else{
                    controleHe = 0;
                    break;
                }

            }

            if(controleHe == 0){
                printf("Digite um número hexadecimal com até 5 caractéres ");
            }
        }
    	conversorH(pbe,pbs,valorEntraH);
        break;
    default:
        
    }
    return 0;

}
