#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 5000

char * lerDados(){
	
	char * frase = (char*)calloc(TAM, sizeof (char));
	
	printf("Digite sua frase:");
	fflush(stdin);
	gets(frase);	
	return frase;
	
}

char * eliminarCorrupcao(char * palavra, int * cont, int *v){
	
	int i,k = 0, c = 0;
	char * resultado = (char*)calloc(TAM ,sizeof (char));
	char * aux = (char*)calloc(TAM ,sizeof (char));
	
	
	for(i = 0; i <= strlen(palavra);i++){
		aux[k] = palavra[i];
		
		if((aux[k] == ' ') || (aux[k] == '\0')){
					
			if((strcmp(aux,"corrupcao ") == 0) || (strcmp(aux,"corrupcao") == 0)){
				aux = (char*)calloc(TAM ,sizeof (char));				
				k = 0;							
				v[*cont] = 1; // é corrupcao
				printf("%d\n",v[*cont]);
			}
			else{
				strcat(resultado,aux);
				aux = (char*)calloc(TAM ,sizeof (char));
				k = 0;				
				v[*cont] = 0;	// ! é corrupcao		
				printf("%d\n",v[*cont]);		    
			}
		    *cont = *cont + 1; 
		    printf("O que ta passando %d\n",*cont);
		}
		else{
			k++;
		}
	}
	return resultado;
}

char * dancaLetras(char * palavra){
	
	char aux;
	char * auxD = (char *)calloc(TAM, sizeof(char));
	int i,j = 0;
	
	int r = strlen(palavra);
	int raiz = (int)sqrt(r);
	
	strcpy(auxD,palavra);
	
	for(i = 0; i < raiz;i++)
	{
		aux = auxD[j+2];
		auxD[j+2] = auxD[j];
		auxD[j] = aux;
		j++;
	}		
	return auxD;
}

char * sonoAmpliado(char * palavra){
	
	char * aux = (char *) calloc(TAM, sizeof(char));
	char * sono = (char *) calloc(TAM, sizeof(char));
	char * auxS = (char *) calloc(TAM, sizeof(char));
	
	char letra = 'a';
	int i,j = 0,cont = 0;
	
	strcpy(auxS,palavra);
	
	for(i = 0; i < strlen(auxS);i++){
		aux[j++] = auxS[i]; // armazenar a palavra		
		
		if(auxS[i] == 'z'){
			if(letra == 'z'){
				
				strcat(sono, "zz"); // iniciar com ZZ
				strcat(sono, aux); // juntar o ZZ mais a palavra
				strcat(sono, "zz"); // juntar tudo e dobrar o ZZ encontrado
				
				strcpy(aux,sono); // atualizar a variavel AUX
				strcpy(sono,""); // zerar a variavel SONO
				j = strlen(aux); // atualizar o valor de J para continar no final da palavra
				
				letra = 'a';
				cont++; // verificar quantas vezes tivemos que dobrar o ZZ para repetir esse processo no final
			}else{
				letra = auxS[i];
			}
			
		}else{
			letra = auxS[i];
		}
	}
	
	aux[strlen(aux)-1] = '\0';			
	
	for(i=0; i<cont; i++){
		strcat(aux, "zz"); // acrescentar o ZZ no final da palavra
	}			
	
	strcat(aux," ");
	
	return aux;

}

char * bMaligna(char * palavra){
	
	int i,j = 0;
	
	char * aux = (char *)calloc(TAM, sizeof(char));
	char * auxB = (char *)calloc(TAM, sizeof(char));
	
	strcpy(auxB,palavra);
	
	for(i = 0; i < strlen(auxB);i++){
		if(auxB[i] != 'b'){
			aux[j] = auxB[i];
			j++;
		}
		else{
			aux[j] = auxB[i];
			j++;
			i = i+2;		
		}
	}
	aux[j]='\0';
	return aux;
}

char * criptografaDados (char * palavra){
	
	char * auxC = (char *)calloc(TAM, sizeof(char));
	char * auxA = (char *)calloc(TAM, sizeof(char));
	char * auxL = (char *)calloc(TAM, sizeof(char));

	int i,k = 0,cont = 0;
	int tamanho = strlen(palavra);
	
	strcpy(auxC,palavra);
	
	for(i = 0; i <= tamanho;i++)
	{
		auxA[k] = auxC[i];
		k++;
		
		if((auxC[i] == ' ') || (auxC[i] == '\0'))
		{
			if(auxA[k] == ' '){
				auxA[k-1] = '\0'; 
			}
			
			if(cont == 0){
				auxA = dancaLetras(auxA);
				strcat(auxL,auxA);
				cont++;
			}
			else if(cont == 1){
				auxA = sonoAmpliado(auxA);
				strcat(auxL,auxA);
				cont++; 
			}
			else{
				auxA = bMaligna(auxA);
				strcat(auxL,auxA);
				cont = 0;
			}
			auxA = (char *)calloc(TAM, sizeof(char));
			k = 0;
		}
	}
	return auxL;
}

char * voltarCorrupcao(char * palavra_criptografada, int cont, int *v){
	
	int i,k = 0; // posicao "inicial" da palavra criptografada
	int g = 0;
	int p = 0; // numero de palavras
	int j = 0; // posicao atual
	char * resultado = (char*)calloc(TAM ,sizeof (char));
	resultado[0] = '\0';

	for(g = 0; g < cont; g++){
		if(v[g] == 1) { // verifica se é corrupcao e escreve corrupçao
			strcat(resultado, " corrupcao \0");
			j += 11;
			printf("%s\n",resultado);
			printf("%d\n",j);
			printf("v[%d]\n",g);
		} else { // se nao for corrupcao
			for(i = k; i< strlen(palavra_criptografada); i++){ 
				if((palavra_criptografada[i] == ' ') || (palavra_criptografada[i] == '\0')){
					k = i+1;
					break;
				} else {
					resultado[j] = palavra_criptografada[i];
					j++;
					resultado[j] = '\0';
				}
			}
		}
		
	}
	return resultado;
}

int main(int argc, char *argv[]) {
	int cont = 0;
	int *v = (int *) calloc(TAM, sizeof(int));
	char *palavra = lerDados();
	char *palavra_pre_processada = eliminarCorrupcao(palavra,&cont,v);
	char *palavra_criptografada = criptografaDados(palavra_pre_processada);
	printf("\n\nPalavra Criptografada: %s\n",palavra_criptografada);
	char *palavra_original = voltarCorrupcao(palavra_criptografada, cont, v);
	printf("A string original é: %s\n", palavra_original);
	system("Pause");
	return 0;
}
