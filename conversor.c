#include <stdio.h> //inclusão da biblioteca de entrada e saída
#include <stdlib.h> //inclusão da biblioteca de controle de alocação de memória

char * conversorO(int * be, int * bs, char * valor); /*declaração da chamada da função de conversão de base octal 
com 2 ponteiros do tipo inteiro, chamados be e bs para receber as bases e um ponteiro do tipo char chamado 
valor para receber o número que será convertido*/

char * conversorH(int * be, int * bs, char * valor); /*declaração da chamada da função de conversão de base hexadecimal 
com 2 ponteiros do tipo inteiro, chamados be e bs para receber as bases e um ponteiro do tipo char chamado 
valor para receber o número que será convertido*/

void ImprimirSaida(char * lista){ /*declaração da função para imprimir saída com um parâmetro 
    do tipo char para receber o número a ser impreso*/
    printf("O número convertido é: %s\n", &lista[0]); //impressão da saída com o string do número convertido 
}


int exponenciacao(int base, int expo){ /*declaração da função do tipo inteiro chamada exponenciação 
    para realizar tal operação tendo como parâmetrosdois valores interios com nome base e expo, 
    sendo o último o futuro expoente da operação*/
    
    int valor = base; //declaração de variável inteira para receber o valor de base

    if(expo == 0){ //condicional para caso o expoente da operação seja 0
        valor = 1; //o valor resultante da operação nesse caso será 1
    
    }else if(expo == 1){//condicional caso o expoente seja 1
        valor = base; //neste caso o valor resultante é ele mesmo, ou a base
    
    }else{ //caso não seja nenhuma das condições acima
        for(int i =1; i<expo; i++){ /*declaração de um laço para realização da multiplicação do 
            valor por ele mesmo de forma consecutiva, tendo como limite o valor do expoente*/
            
            valor = valor * base; // o valor é ele multiplicado pela base original
        }
    }
    return valor; //retorna o valor após exponenciação

}



int charPraIntDeci(int * be,char vetor[]){ /*declaração de função do tipo inteiro chamado charPraIntDeci, 
    com finalidade de transformar uma valor decimal escrito em char, em inteiro. Os parâmetros dessa função são:
    o um ponteiro be que é a base de entrada do tipo inteiro e um vetor do tipo char, chamado vetor*/
    
    int contador = 0; //declaração de variável contador do tipo inteiro inicializado com valor 0
    int expoente= 0; //declaração de variável expoente do tipo inteiro inicializada com valor 0
    int numeroDec = 0; //declaração de variável numeroDec do tipo inteiro inicializado com valor 0
    int limitador = 0; //declaração de variável limitador do tipo inteiro inicializado com valor 0
    
    if((*be) == 1){ //condicional para verificar se a base de entrada é igual a 1 (opção para binário)
        for(int i = 0; i < 10; i++){ //cria laço com limitador com mesmo tamanho do limitador do entrada do valor binario original
            if(vetor[i] != '\0'){ //condicional para verificar se o caracter está vazio segundo as regras do ASCII usado pela linguagem 
                contador +=1; //conta quantos caracters preenchidos tem
            }
        }
    }else if((*be) == 2){ //condicional para verificar se a base de entrada é igual a 2 (opção para octal)
        for(int i = 0; i < 7; i++){ //cria laço com limitador com mesmo tamanho do limitador do entrada do valor octal original
            if(vetor[i] != '\0'){ //condicional para verificar se o caracter está vazio segundo as regras do ASCII usado pela linguagem 
                contador +=1; //conta quantos caracters preenchidos tem
            }
        }

    }else if((*be) == 3){ //condicional para verificar se a base de entrada é igual a 3 (opção para decimal)
        for(int i = 0; i < 7; i++){ //cria laço com limitador com mesmo tamanho do limitador do entrada do valor octal original
            if(vetor[i] != '\0'){ //condicional para verificar se o caracter está vazio segundo as regras do ASCII usado pela linguagem 
                contador +=1; //conta quantos caracters preenchidos tem
            }
        }

    }else if((*be) == 4){ //condicional para verificar se a base de entrada é igual a 4 (opção para hexadecimal)
        for(int i = 0; i < 5; i++){ //cria laço com limitador com mesmo tamanho do limitador do entrada do valor hexadecimal original
            if(vetor[i] != '\0'){ //condicional para verificar se o caracter está vazio segundo as regras do ASCII usado pela linguagem 
                contador +=1; //conta quantos caracters preenchidos tem
            }
        }

    }
    int numeros[contador]; //cria lista do tipo inteiro com o tamanho correspondente a quantidade de itens não vazios na lista vetor
    
    for(int k =0; k< contador; k++){ //cração de laço para alocar itens na lista numeros, tendo como limitador o contador
        numeros[k] = vetor[k] - '0'; /*alocação de cada número no vetor, ao mesmo tempo que 
        transformam eles para inteiros pelas regras do ASCII*/
    }

    for(int j = (contador-1); j >=0; j--){ /*criação de um laço para leitura em ordem inversa dos itens
        indo do último item do vetor até a posição 0*/
        int multiplicando = exponenciacao(10,expoente); /*criação de uma variavel do tipo inteiro chamada multiplicando responsável 
        por receber a casa em que o número vai ficar, como unidade, dezena, centena, milhar, etc, com usando da função exponenciação*/ 
        numeroDec = numeroDec + (numeros[j]*multiplicando); //o número decimal recebe a soma dele mesmo com número de cada posição 
        //já com sua posição no sistema decimal
        expoente +=1; //aumenta o expoente em 1 para aumentar a casa decimal do próximo número
    }

    return numeroDec; //a função retorna o número decimal já convertido

}



char * intDeciPraChar(int numero){ /*declaração da função intDeciPraChar para retornar um 
    vetor de caracteres com um parâmetro inteiro chamado número*/

    char * vetorInterm = (char *)malloc(50 * sizeof(char)); //criação de uma lista de caracteres com 50 itens chamada vetorInterm
    char * vetorDefini = (char *)malloc(50 * sizeof(char)); //criação de uma lista de caracteres com 50 itens chamada vetorDefini
    int i = 0; //criação de uma variáveldo tipo inteiro chamado i inicializada com valor 0
    
    while (numero > 0) { //laço enquanto o valor de número for maior que 0
        int digito = numero % 10; //declaração de variável digito que pega o último digito do número

        vetorInterm[i] = digito + '0'; /*o item atual do vetorInterm recebe o número transformado em caractere 
        seguindo as regras do ASCII, em ordem contrária*/

        numero /= 10; /*número é dividido por 10 para que o proximo item a ser lido seja a próxima casa 
        indo para a esquerda do número inteiro*/

        i++; //acrescena 1 no valor de i para que o proximo item seja armazenado na proxima casa do vetorInterm

    }
    i = 0; //reseta o valor em i
    for(int j = 49; j >=0; j--){ //criaçãode um laço que vai do fim ao começo da lista vetorDefini

        if(vetorInterm[j] != '\0'){ //condicional para verificar de o item dentro de vetorInterm não está vazio
            vetorDefini[i] = vetorInterm[j]; /*caso não esteja vazio, o vetorDefini recebe os valores em ordem 
            inversa aos presentes no vetorInterm*/
            i++; //acrescenta novamente o valor i para avançar nas casas do vetorDefini
        }

    }

    return vetorDefini; //retorna alista vetorDefini

}



char * conversorB(int * be, int * bs, char * valor){ /*declaração de função do tipo char de nome conversorB 
    para retornar um vetor com parâmetros de 2 ponteiros int chamados be (base de entrada) e bs (base de saída) e 
    recebe uma lista de caracteres chamado valor*/

    char * valorSaiConvertidoD = (char *) malloc(50 * sizeof(char)); /*criação de um vetor do tipo char de 50 
    itens de tamanho de nomevalorSaiConvertidoD*/ 

    if((*be) == 1){ // condicional para verificar se o item apontado por be é o que indica que a base de entrada é 1 que representa binário

        int contador = 0; //declaração de variável do tipo inteiro com nome contador inicializado em 0
        int expoente = 0; //declaração de variável do tipo inteiro com nome expoente inicializado em 0
        int decimal = 0; //declaração de variável do tipo inteiro com nome decimal inicializado em 0
        
        if ((*bs) == 1){ //condicional que verifica se a base de sáida também for 1
            ImprimirSaida(valor); //chama a função ImprimirSaida atrelando como parâmetro a variável valor
        }

        for(int i = 0; i < 10; i++){ //laço de repetição com limite do mesmo tamanho da entrada de binário
            if(valor[i] != '\0'){ //verifica se o item presente no valor está vazio
                contador +=1; //acrescenta mais um no valor do contador


            }
        }

        int numeros[contador]; //declaração do vetor de tipo inteiro com nome numeros de tamanho delimitado pelo contador
        for(int k =0; k< contador; k++){ //laço de repetição com limite de contador
            numeros[k] = valor[k] - '0'; //acrescenta os itens presentes em valor em numeros transformando em inteiros com a regra do ASCII
        }

        for(int j = (contador-1); j >=0; j--){ //laço de repetição que começa com o último item da lista e vai em direção ao primeiro
            int multiplicando = exponenciacao(2,expoente); /*criação de uma variavel do tipo inteiro chamada multiplicando responsável 
        por receber o valor que deve ser multplicado com um número binário para achar seu valor decimal, com uso da função exponenciação*/ 
            decimal = decimal + (numeros[j]*multiplicando); //decimal recebe o número bínário ao longo de sua conversão
            expoente +=1; //aumenta em 1 o expoente para realizar a transformação

        }
        valorSaiConvertidoD = intDeciPraChar(decimal); //converte o número decimal do tipo interio em uma lista do tipo char
        if((*bs) == 3){ //condicional que verifica se a base de saída é decimal (3)
            ImprimirSaida(valorSaiConvertidoD); //chama a função de impressão para imprimir valorSaiConvertidoD
        }else if((*bs) == 2){ //condicional para verificar se a base de saída é octal(2)
            (*be) = 3; //muda a base de entrada para decimal
        	conversorO(be,bs,valorSaiConvertidoD); //manda o número em decimal para o conversor octal
        }else if((*bs) == 4){ ;//condicional para verificar se a base de saída é hexadecimal(4)
            (*be) = 3; //muda a base de entrada para decimal
            conversorH(be,bs,valorSaiConvertidoD); //manda o número em decimal para o conversor hexadecimal
        }
    }else if((*be) == 3){ //condicional para verificar se a base de entrada é decimal
        int numeroDe =charPraIntDeci(be ,valor); //transforma o valor decimal em char para inteiro e armazena na variável numeroDe do tipo inteiro
        char * valorInterConvertidoB = (char *) malloc(50 * sizeof(char)); //cria uma lista em char com tamanho de 50 itens de nome valorInterConvertidoB
        char * valorSaiConvertidoB = (char *) malloc(50 * sizeof(char)); //cria uma lista em char com tamanho de 50 itens de nome valorSaiConvertidoB
        int i = 0; //cria variavel inteira i inicializada com valor 0
        while(numeroDe > 0){ //criação de laço que se repete enquanto a variavel numeroDe for maior que 0
            if(numeroDe == 1){ //condicional que verifica se numeroDE é igual a 1
                valorInterConvertidoB[i] = numeroDe + '0'; //valorInterConvertidoB recebe o numeroDe como char na posição i
                numeroDe = numeroDe/2; //numeroDe é divido por dois e seu novo valor é armazenado em si mesmo
                i++; //incrementa mais 1 na variavel i que é usada como contador
            }else{ //caso não seja o caso da condicional anterior
                int resto = numeroDe % 2; // a variavel do tipo inteira chamado resto é inicializada com o resto da divisão de numeroDe por 2
                valorInterConvertidoB[i] = resto + '0'; //o valorInterConvertidoB recebe o valor resto como char na posição i
                numeroDe = numeroDe/2; //numeroDe é divido por dois e seu novo valor é armazenado em si mesmo
                i++; //incrementa mais 1 na variavel i que é usada como contador
            }

        }
        i = 0; //a variavel i volta a ter valor 0
        for(int j = 49; j >=0; j--){ //criação do laço para leitura em ordem inversa de uma lista

            if(valorInterConvertidoB[j] != '\0'){ //condicional verifica se o valor atualmente lido em valorInterConvertidoB não é vazio
                valorSaiConvertidoB[i] = valorInterConvertidoB[j]; //valorSaiConvertidoB na posição i recebe em ordem inversa o item presente em valorInterConvertidoB
                i++; //incrementa mais 1 na variavel i que é usada como contador
            }

        }
        ImprimirSaida(valorSaiConvertidoB); //chamada da função ImprimirSaida tendo como parâmetro valorSaiConvertidoB


    }

}




char * conversorO(int * be, int * bs, char * valor){ /*declaração de função do tipo char de nome conversorO 
    para retornar um vetor com parâmetros de 2 ponteiros int chamados be (base de entrada) e bs (base de saída) e 
    recebe uma lista de caracteres chamado valor*/
    char * valorSaiConvertidoD = (char *) malloc(50 * sizeof(char));/*criação de um vetor do tipo char de 50 
    itens de tamanho de nomevalorSaiConvertidoD*/ 
    if((*be) == 2){// condicional para verificar se o item apontado por be é o que indica que a base de entrada é 2 que representa octal
        int contador = 0; //declaração de variável do tipo inteiro com nome contador inicializado em 0
        int expoente = 0; //declaração de variável do tipo inteiro com nome expoente inicializado em 0
        int decimal = 0; //declaração de variável do tipo inteiro com nome decimal inicializado em 0
        if ((*bs) == 2){ //condicional que verifica se a base de sáida também for 2
            ImprimirSaida(valor); //chama a função ImprimirSaida atrelando como parâmetro a variável valor
        }
        for(int i = 0; i < 7; i++){ //laço de repetição com limite do mesmo tamanho da entrada de octal
            if(valor[i] != '\0'){ //verifica se o item presente no valor está vazio
                contador +=1; //acrescenta mais um no valor do contador


            }
        }

        int numeros[contador]; //declaração do vetor tipo inteiro com nome numeros de tamanho delimitado pelo contador
        for(int k =0; k< contador; k++){ //laço de repetição com limite de contador
            numeros[k] = valor[k] - '0'; //acrescenta os itens presentes em valor em numeros transformando em inteiros com a regra do ASCII
        }

        for(int j = (contador-1); j >=0; j--){ //laço de repetição que começa com o último item da lista e vai em direção ao primeiro
            int multiplicando = exponenciacao(8,expoente); /*criação de uma variavel do tipo inteiro chamada multiplicando responsável 
        por receber o valor que deve ser multplicado com um número octal para achar seu valor decimal, com uso da função exponenciação*/
            decimal = decimal + (numeros[j]*multiplicando); //decimal recebe o número bínário ao longo de sua conversão
            expoente +=1;//aumenta em 1 o expoente para realizar a transformação

        }
        valorSaiConvertidoD = intDeciPraChar(decimal); //converte o número decimal do tipo interio em uma lista do tipo char com a função intDeciPraChar 
        if((*bs) == 3){ //condicional que verifica se a base de saída é decimal (3)
            ImprimirSaida(valorSaiConvertidoD); //chama a função de impressão para imprimir valorSaiConvertidoD
        }else if((*bs) == 1){ //condicional para verificar se a base de saída é binário(1)
        	(*be) = 3; //muda a base de entrada para decimal
        	conversorB(be,bs,valorSaiConvertidoD); //manda o número em decimal para o conversor binário
        }else if((*bs) == 4){ //condicional para verificar se a base de saída é hexadecimal(4)
            (*be) = 3; //muda a base de entrada para decimal
            conversorH(be,bs,valorSaiConvertidoD); //manda o número em decimal para o conversor hexadecimal
        }
    }else if((*be) == 3){ //condicional para verificar se a base de entrada é decimal
        int numeroDe =charPraIntDeci(be,valor); //transforma o valor decimal em char para inteiro e armazena na variável numeroDe do tipo inteiro
        char * valorInterConvertidoO = (char *) malloc(50 * sizeof(char)); //cria uma lista em char com tamanho de 50 itens de nome valorInterConvertidoO
        char * valorSaiConvertidoO = (char *) malloc(50 * sizeof(char)); //cria uma lista em char com tamanho de 50 itens de nome valorSaiConvertidoO
        int i = 0; //cria variavel inteira i inicializada com valor 0
        while(numeroDe > 0){ //criação de laço que se repete enquanto a variavel numeroDe for maior que 0
            if(numeroDe == 1){ //condicional que verifica se numeroDE é igual a 1
                valorInterConvertidoO[i] = numeroDe + '0'; //valorInterConvertidoO recebe o numeroDe como char na posição i
                numeroDe = numeroDe/8; //numeroDe é divido por oito e seu novo valor é armazenado em si mesmo
                i++; //incrementa mais 1 na variavel i que é usada como contador
            }else{ //caso não seja o caso da condicional anterior
                int resto = numeroDe % 8; // a variavel do tipo inteira chamado resto é inicializada com o resto da divisão de numeroDe por 8
                valorInterConvertidoO[i] = resto + '0'; //o valorInterConvertidoO recebe o valor resto como char na posição i
                numeroDe = numeroDe/8; //numeroDe é divido por oito e seu novo valor é armazenado em si mesmo
                i++; //incrementa mais 1 na variavel i que é usada como contador
            }

        }
        i = 0; //a variavel i volta a ter valor 0
        for(int j = 49; j >=0; j--){ //criação do laço para leitura em ordem inversa de uma lista

            if(valorInterConvertidoO[j] != '\0'){ //condicional verifica se o valor atualmente lido em valorInterConvertidoO não é vazio
                valorSaiConvertidoO[i] = valorInterConvertidoO[j]; //valorSaiConvertidoO na posição i recebe em ordem inversa o item presente em valorInterConvertidoO
                i++; //incrementa mais 1 na variavel i que é usada como contador
            }

        }
        ImprimirSaida(valorSaiConvertidoO); //chamada da função ImprimirSaida tendo como parâmetro valorSaiConvertidoO


    }

}



char * conversorH(int * be, int * bs, char * valor){ /*declaração de função do tipo char de nome conversorH 
    para retornar um vetor com parâmetros de 2 ponteiros int chamados be (base de entrada) e bs (base de saída) e 
    recebe uma lista de caracteres chamado valor*/

    char * valorSaiConvertidoD = (char *) malloc(50 * sizeof(char)); /*criação de um vetor do tipo char de 50 
    itens de tamanho de nomevalorSaiConvertidoD*/
    if((*be) == 4){ // condicional para verificar se o item apontado por be é o que indica que a base de entrada é 4 que representa hexadecimal
        int contador = 0; //declaração de variável do tipo inteiro com nome contador inicializado em 0
        int expoente = 0; //declaração de variável do tipo inteiro com nome expoente inicializado em 0
        int decimal = 0; //declaração de variável do tipo inteiro com nome decimal inicializado em 0
        if ((*bs) == 4){ //condicional que verifica se a base de sáida também for 4
            ImprimirSaida(valor); //chama a função ImprimirSaida atrelando como parâmetro a variável valor
        }
        for(int i = 0; i < 5; i++){ //laço de repetição com limite do mesmo tamanho da entrada de hexadecimal
            if(valor[i] != '\0'){ //verifica se o item presente no valor está vazio
                contador +=1; //acrescenta mais um no valor do contador


            }
        }

        int numeros[contador]; //declaração do vetor de tipo inteiro com nome numeros de tamanho delimitado pelo contador
        for(int k =0; k< contador; k++){ //laço de repetição com limite de contador
            if(valor[k] == 'a' || valor[k] == 'A'){ //condicional que verifica se o item em valor é a minusculo ou a maiusculo
                numeros[k] = 10; //nesse caso como a representa 10 então no vetor de números esse valor é adicionado no lugar
            }else if(valor[k] == 'b' || valor[k] == 'B'){ //condicional que verifica se o item em valor é b minusculo ou b maiusculo
                numeros[k] = 11; //nesse caso como a representa 11 então no vetor de números esse valor é adicionado no lugar
            }else if(valor[k] == 'c' || valor[k] == 'C'){ //condicional que verifica se o item em valor é c minusculo ou c maiusculo
                numeros[k] = 12; //nesse caso como a representa 12 então no vetor de números esse valor é adicionado no lugar
            }else if(valor[k] == 'd' || valor[k] == 'D'){ //condicional que verifica se o item em valor é d minusculo ou d maiusculo
                numeros[k] = 13; //nesse caso como a representa 13 então no vetor de números esse valor é adicionado no lugar
            }else if(valor[k] == 'e' || valor[k] == 'E'){ //condicional que verifica se o item em valor é e minusculo ou e maiusculo
                numeros[k] = 14; //nesse caso como a representa 14 então no vetor de números esse valor é adicionado no lugar
            }else if(valor[k] == 'f' || valor[k] == 'F'){ //condicional que verifica se o item em valor é f minusculo ou f maiusculo
                numeros[k] = 15; //nesse caso como a representa 15 então no vetor de números esse valor é adicionado no lugar
            }else{ //caso não seja nenhum desses cenários
                numeros[k] = valor[k] - '0'; //acrescenta os itens presentes em valor em numeros transformando em inteiros com a regra do ASCII
            }
        }

        for(int j = (contador-1); j >=0; j--){ //laço de repetição que começa com o último item da lista e vai em direção ao primeiro
            int multiplicando = exponenciacao(16,expoente); /*criação de uma variavel do tipo inteiro chamada multiplicando responsável 
        por receber o valor que deve ser multplicado com um número hexadecimal para achar seu valor decimal, com uso da função exponenciação*/
            decimal = decimal + (numeros[j]*multiplicando); //decimal recebe o número hexadecimal ao longo de sua conversão
            expoente +=1; //aumenta em 1 o expoente para realizar a transformação

        }
        valorSaiConvertidoD = intDeciPraChar(decimal); //converte o número decimal do tipo interio em uma lista do tipo char com a função intDeciPraChar
        if((*bs) == 3){ //condicional que verifica se a base de saída é decimal (3)
            ImprimirSaida(valorSaiConvertidoD); //chama a função de impressão para imprimir valorSaiConvertidoD
        }else if((*bs) == 1){ //condicional para verificar se a base de saída é binario(1)
        	(*be) = 3; //muda a base de entrada para decimal
        	conversorB(be,bs,valorSaiConvertidoD); //manda o número em decimal para o conversor binário
        }else if((*bs) == 2){ //condicional para verificar se a base de saída é octal(2)
            (*be) = 3; //muda a base de entrada para decimal
        	conversorO(be,bs,valorSaiConvertidoD); //manda o número em decimal para o conversor octal
        }
    }else if((*be) == 3){  //condicional para verificar se a base de entrada é decimal
        int numeroDe =charPraIntDeci(be, valor); //transforma o valor decimal em char para inteiro e armazena na variável numeroDe do tipo inteiro
        char * valorInterConvertidoH = (char *) malloc(50 * sizeof(char)); //cria uma lista em char com tamanho de 50 itens de nome valorInterConvertidoH
        char * valorSaiConvertidoH = (char *) malloc(50 * sizeof(char)); //cria uma lista em char com tamanho de 50 itens de nome valorSaiConvertidoH
        int i = 0; //cria variavel inteira i inicializada com valor 0
        while(numeroDe > 0){ //criação de laço que se repete enquanto a variavel numeroDe for maior que 0
            if(numeroDe == 1){ //condicional que verifica se numeroDE é igual a 1
                valorInterConvertidoH[i] = numeroDe + '0'; //valorInterConvertidoH recebe o numeroDe como char na posição i
                numeroDe = numeroDe/16; //numeroDe é divido por 16 e seu novo valor é armazenado em si mesmo
                i++; //incrementa mais 1 na variavel i que é usada como contador
            }else{ //caso não seja o caso da condicional anterior
                int resto = numeroDe % 16; // a variavel do tipo inteira chamado resto é inicializada com o resto da divisão de numeroDe por 16
                if(resto == 10){ //condicional verifica se o resto for igual a 10
                    valorInterConvertidoH[i] = 'A'; //nessa condição o valorInterConvertidoH[i] armazena o char A 
                }else if(resto == 11){ //condicional verifica se o resto for igual a 11
                    valorInterConvertidoH[i] = 'B'; //nessa condição o valorInterConvertidoH[i] armazena o char B
                }else if(resto == 12){ //condicional verifica se o resto for igual a 12
                    valorInterConvertidoH[i] = 'C'; //nessa condição o valorInterConvertidoH[i] armazena o char C
                }else if(resto == 13){ //condicional verifica se o resto for igual a 13
                    valorInterConvertidoH[i] = 'D'; //nessa condição o valorInterConvertidoH[i] armazena o char D
                }else if(resto == 14){ //condicional verifica se o resto for igual a 14
                    valorInterConvertidoH[i] = 'E'; //nessa condição o valorInterConvertidoH[i] armazena o char E
                }else if(resto == 15){ //condicional verifica se o resto for igual a 15
                    valorInterConvertidoH[i] = 'F'; //nessa condição o valorInterConvertidoH[i] armazena o char F
                }else{ //caso não seja o caso da condicional anterior
                    valorInterConvertidoH[i] = resto + '0';  //o valorInterConvertidoB recebe o valor resto como char na posição i
                }
                numeroDe = numeroDe/16; //numeroDe é divido por 16 e seu novo valor é armazenado em si mesmo
                i++; //incrementa mais 1 na variavel i que é usada como contador
            }

        }
        i = 0; //a variavel i volta a ter valor 0
        for(int j = 49; j >=0; j--){ //criação do laço para leitura em ordem inversa de uma lista

            if(valorInterConvertidoH[j] != '\0'){ //condicional verifica se o valor atualmente lido em valorInterConvertidoH não é vazio
                valorSaiConvertidoH[i] = valorInterConvertidoH[j]; //valorSaiConvertidoH na posição i recebe em ordem inversa o item presente em valorInterConvertidoH
                i++; //incrementa mais 1 na variavel i que é usada como contador
            }

        }
        ImprimirSaida(valorSaiConvertidoH); //chamada da função ImprimirSaida tendo como parâmetro valorSaiConvertidoH


    }

}


int main(){ //inicialização do método main de tipo inteiro
    int controleBaseEntra = 0; //declaração de variável do tipo inteiro chamada controleBaseEntra inicializado com 0
    int controleBaseSai = 0; //declaração de variável do tipo inteiro chamada controleBaseSai inicializado com 0
    char beIni[1] = {};
    char bsIni[1] = {};
    int be; //delcaração de variável do tipo inteiro chamada be que representa a base de entrada
    int bs; //delcaração de variável do tipo inteiro chamada be que representa a base de saída
    int * pbe; //declaração de ponteiro do tipo inteiro chamado pbe que é o ponteiro da base de entrada
    int * pbs; //declaração de ponteiro do tipo inteiro chamado pbs que é o ponteiro da base de saída
    pbe = &be; //inicialização do ponteiro pbe apontando para be
    pbs = &bs; //inicialização do ponteiro pbs apontando para bs

    printf("digite qual base de entrada deseja usar: \n"); //impressão das opções da base de entrada
    printf("1 - para binária\n"); //imprime digite 1 para entrar números binários
    printf("2 - para octal\n"); //imprime digite 2 para entrar números octais
    printf("3 - para decimal\n"); //imprime digite 3 para entrar números decimais
    printf("4 - para hexadecimal\n"); //imprime digite 4 para entrar números hexadecimais

    scanf("%s",&beIni[0]); //escaneia a opção desejada para base de entrada do tipo inteiro

    while(controleBaseEntra == 0){ //declaração de laço de repetição baseada no valor do número de controleBaseEntra
        if(beIni[0] == '1' || beIni[0] == '2' || beIni[0] == '3' || beIni[0] == '4'){ //condicional para verificar se a base de entrada é 1, 2, 3 ou 4
            be = beIni[0] - '0';
            controleBaseEntra = 1;//caso seja uma das opções desejadas a variavel controleBaseEntra muda para 1 e encerra o laço
        }else{ //caso a condicional não seja atendida é repetido a impressão das opções de entrada e espera a nova resposta do usuário
            printf("digite uma das opções válidas: \n"); //imprime a solicitação por uma nova entrada até que atenda as condições
            printf("1 - para binária\n"); //imprime digite 1 para entrar números binários
            printf("2 - para octal\n"); //imprime digite 2 para entrar números octais
            printf("3 - para decimal\n"); //imprime digite 3 para entrar números decimais
            printf("4 - para hexadecimal\n"); //imprime digite 4 para entrar números hexadecimais'
            scanf("%s", &beIni[0]); //escaneia a opção desejada para base de entrada do tipo char

        }     

    }

    printf("digite qual deve ser a base de saída: \n"); //imprime as opções da base de saída
    printf("1 - para binária\n"); //imprime digite 1 para sair números binários
    printf("2 - para octal\n"); //imprime digite 2 para sair números octais
    printf("3 - para decimal\n"); //imprime digite 3 para sair números decimais
    printf("4 - para hexadecimal\n"); //imprime digite 4 para sair números hexadecimais

    scanf("%s",&bsIni[0]); //escaneia a opção desejada para base de saida do tipo inteiro

    while(controleBaseSai == 0){ //declaração de laço de repetição baseada no valor do número de controleBaseSai
        if(bsIni[0] == '1' || bsIni[0] == '2' || bsIni[0] == '3' || bsIni[0] == '4'){ //condicional para verificar se a base de saida é 1, 2, 3 ou 4
            bs = bsIni[0] - '0';
            controleBaseSai = 1; //caso seja uma das opções desejadas a variavel controleBaseSai muda para 1 e encerra o laço
        }else{ //caso a condicional não seja atendida é repetido a impressão das opções de saida e espera a nova resposta do usuário
            printf("digite uma das opções válidas: \n"); //imprime a solicitação por uma nova entrada até que atenda as condições
            printf("1 - para binária\n"); //imprime digite 1 para entrar números binários
            printf("2 - para octal\n"); //imprime digite 2 para entrar números octais
            printf("3 - para decimal\n"); //imprime digite 3 para entrar números decimais
            printf("4 - para hexadecimal\n"); //imprime digite 4 para entrar números hexadecimais'
            scanf("%s", &bsIni[0]); //escaneia a opção desejada para base de saida do tipo inteiro

        }     

    }    

    switch (be){ //condicional switch case com base no valor da variavel be
    case 1: //caso o valor de be seja 1 
        int controleBi = 0; //variavel inteira controleBi para controle do número binário
        char valorEntraB[10] = {}; // vetor do tipo char para armazenar a entrada do número binario
        printf("Se colocar um espaço vazio no meio do número, "); // imprissão para ensinar as condições de entrada
        printf("tudo depois dele será desconsiderado\n"); // imprissão para ensinar as condições de entrada
        printf("digite abaixo o valor binário que deseja converter com até 10 caractéres: \n"); // imprissão para ensinar as condições de entrada

        while(controleBi == 0){ //declaração de laço de repetição baseada no valor do número de controleBi
            scanf("%s", &valorEntraB); //escaneia a escrita da string do usuário e atrela à variável valorEntraB
            for(int i =0; i <10; i++){ //laço com tamanho do vetor valorEntraB para realizar sua leitura
                if(valorEntraB[i] == '1' || valorEntraB[i] == '0' || valorEntraB[i] == '\0'){ /*condicional para verificar se os itens no vetor são 1,
                     0 ou valor vazio segundo o ASCII*/
                    controleBi = 1; // caso seja atendido as condições muda a variável controleBi para 1 e encerra o laço

                }else{
                    controleBi = 0; //caso qualquer dos itens presentes no vetor não seja atendido controleBi continua 0 
                    break; //quebra o laço do for
                }

            }

            if(controleBi == 0){ //se o controleBi ainda for 0 ele imprime solicitando que o usuário preencha novamente o vetor
                printf("Digite um número binário com até 10 caractéres ");
            }
        }
        conversorB(pbe,pbs,valorEntraB); /*depois de preenchido o vetor com um número binário, ele é enviado para a função de conversorB, 
        junto com os ponteiros pbe e pbs*/
        break; //interrompe o switch case

    case 2: //caso o valor de be seja 2
    	int controleOc = 0; //variavel inteira controleOc para controle do número octal
        char valorEntraO[7] = {}; // vetor do tipo char para armazenar a entrada do número octal
        printf("Se colocar um espaço vazio no meio do número, "); // imprissão para ensinar as condições de entrada
        printf("tudo depois dele será desconsiderado\n"); // imprissão para ensinar as condições de entrada
        printf("digite abaixo o valor octal que deseja converter com até 7 caractéres: \n"); // imprissão para ensinar as condições de entrada

        while(controleOc == 0){  //declaração de laço de repetição baseada no valor do número de controleOc
            scanf("%s", &valorEntraO); //escaneia a escrita da string do usuário e atrela à variável valorEntraO
            for(int i =0; i <7; i++){ //laço com tamanho do vetor valorEntraO para realizar sua leitura
                if(valorEntraO[i] == '0' || valorEntraO[i] == '1' || valorEntraO[i] == '\0'|| 
                    valorEntraO[i] == '2' || valorEntraO[i] == '3'|| valorEntraO[i] == '4'|| 
                    valorEntraO[i] == '5'|| valorEntraO[i] == '6'|| valorEntraO[i] == '7'){ /*condicional para verificar se os itens no vetor são 0,
                     1, 2, 3, 4, 5, 6, 7 ou valor vazio segundo o ASCII*/

                    controleOc = 1; // caso seja atendido as condições muda a variável controleOc para 1 e encerra o laço
                }else{
                    controleOc = 0; //caso qualquer dos itens presentes no vetor não seja atendido controleOc continua 0 
                    break; //quebra o laço do for
                }

            }

            if(controleOc == 0){ //se o controleOc ainda for 0 ele imprime solicitando que o usuário preencha novamente o vetor
                printf("Digite um número octal com até 7 caractéres "); 
            }
        }
    	conversorO(pbe,pbs,valorEntraO);/*depois de preenchido o vetor com um número octal, ele é enviado para a função de conversorO, 
        junto com os ponteiros pbe e pbs*/

        break; //interrompe o switch case

    case 3: //caso o valor de be seja 3
        int controleDec = 0; //variavel inteira controleDec para controle do número decimal
        char valorEntraD[7] = {}; // vetor do tipo char para armazenar a entrada do número decimal
        printf("Se colocar um espaço vazio no meio do número, "); // imprissão para ensinar as condições de entrada
        printf("tudo depois dele será desconsiderado\n"); // imprissão para ensinar as condições de entrada
        printf("digite abaixo o valor decimal que deseja converter com até 7 caractéres: \n"); // imprissão para ensinar as condições de entrada

        while(controleDec == 0){ //declaração de laço de repetição baseada no valor do número de controleDec
            scanf("%s", &valorEntraD); //escaneia a escrita da string do usuário e atrela à variável valorEntraD
            for(int i =0; i <7; i++){ //laço com tamanho do vetor valorEntraD para realizar sua leitura
                if(valorEntraD[i] == '0' || valorEntraD[i] == '1' || valorEntraD[i] == '\0'|| valorEntraD[i] == '2' ||
                     valorEntraD[i] == '3'|| valorEntraD[i] == '4'|| valorEntraD[i] == '5'|| valorEntraD[i] == '6'||
                      valorEntraD[i] == '7'|| valorEntraD[i] == '8'|| valorEntraD[i] == '9'){ /*condicional para verificar se os itens no vetor são 0,
                     1, 2, 3, 4, 5, 6, 7, 8, 9 ou valor vazio segundo o ASCII*/
                    controleDec = 1; //caso seja atendido as condições muda a variável controleDec para 1 e encerra o laço
                }else{
                    controleDec = 0; //caso qualquer dos itens presentes no vetor não seja atendido controleDec continua 0 
                    break; //quebra o laço do for
                }

            }

            if(controleDec == 0){ //se o controleDec ainda for 0 ele imprime solicitando que o usuário preencha novamente o vetor
                printf("Digite um número decimal com até 7 caractéres ");
            }
        }
        if(bs ==1){ //condicional para verificar se a base de saida é 1 (binário)
            conversorB(pbe,pbs,valorEntraD); /*depois de preenchido o vetor com um número decimal, ele é enviado para a função de conversorB, 
        junto com os ponteiros pbe e pbs*/
        }
        if(bs == 2){ //condicional para verificar se a base de saida é 2 (octal)
            conversorO(pbe,pbs,valorEntraD); /*depois de preenchido o vetor com um número decimal, ele é enviado para a função de conversorO, 
        junto com os ponteiros pbe e pbs*/
        }
        if(bs == 3){ //condicional para verificar se a base de saida é 3 (decimal)
            ImprimirSaida(valorEntraD); //chama a função ImprimirSaida para imprimir o número decimal
        }
        if(bs == 4){ //condicional para verificar se a base de saida é 4 (hexadecimal)
            conversorH(pbe,pbs,valorEntraD); /*depois de preenchido o vetor com um número hexadecimal, ele é enviado para a função de conversorH, 
        junto com os ponteiros pbe e pbs*/
        }
        break; //interrompe o switch case

    case 4: //caso o valor de be seja 4
        int controleHe = 0; //variavel inteira controleHe para controle do número hexadecimal
        char valorEntraH[5] = {}; // vetor do tipo char para armazenar a entrada do número hexadecimal
        printf("Se colocar um espaço vazio no meio do número, "); // imprissão para ensinar as condições de entrada
        printf("tudo depois dele será desconsiderado\n"); // imprissão para ensinar as condições de entrada
        printf("digite abaixo o valor hexadecimal que deseja converter com até 5 caractéres: \n"); // imprissão para ensinar as condições de entrada

        while(controleHe == 0){ //declaração de laço de repetição baseada no valor do número de controleHe
            scanf("%s", &valorEntraH); //escaneia a escrita da string do usuário e atrela à variável valorEntraH
            for(int i =0; i <5; i++){ //laço com tamanho do vetor valorEntraH para realizar sua leitura
                if(valorEntraH[i] == '0' || valorEntraH[i] == '1' || valorEntraH[i] == '\0'|| valorEntraH[i] == '2' || valorEntraH[i] == '3'|| valorEntraH[i] == '4'||
                   valorEntraH[i] == '5'|| valorEntraH[i] == '6'|| valorEntraH[i] == '7' || valorEntraH[i] == '8' || valorEntraH[i] == '9'|| valorEntraH[i] == 'a'
                   || valorEntraH[i] == 'A'|| valorEntraH[i] == 'b'|| valorEntraH[i] == 'B'|| valorEntraH[i] == 'c'|| valorEntraH[i] == 'C'|| valorEntraH[i] == 'd'
                   || valorEntraH[i] == 'D'|| valorEntraH[i] == 'e'|| valorEntraH[i] == 'E'|| 
                   valorEntraH[i] == 'f'|| valorEntraH[i] == 'F'){ /*condicional para verificar se os itens no vetor são 0,
                     1, 2, 3, 4, 5, 6, 7, 8, 9, a, A, b, B, c, C, d, D, e, E, f, F ou valor vazio segundo o ASCII*/
                    controleHe = 1; // caso seja atendido as condições muda a variável controleHe para 1 e encerra o laço
                }else{
                    controleHe = 0; //caso qualquer dos itens presentes no vetor não seja atendido controleOc continua 0 
                    break; //quebra o laço do for
                }

            }

            if(controleHe == 0){ //se o controleHe ainda for 0 ele imprime solicitando que o usuário preencha novamente o vetor
                printf("Digite um número hexadecimal com até 5 caractéres ");
            }
        }
    	conversorH(pbe,pbs,valorEntraH); /*depois de preenchido o vetor com um número hexadecimal, ele é enviado para a função de conversorH, 
        junto com os ponteiros pbe e pbs*/
        break; //interrompe o switch case
    default: // são tem caso default neste switch case, pois o dado a variável a ser analisada já é filtrada anteriormente
        
    }
    return 0; // retorna 0 caso a função main consiga executar sem erros

}
