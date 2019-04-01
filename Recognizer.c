#include <stdio.h>
#include <stdlib.h>

int contains(char c){
	if(c == 'a' || c == 'b' || c == '+' || c == '='){
		return 1;
		}
	return 0;
	}

int main(int argc, char *argv[]) {
	char fita[255];
	int p, i;
	printf("Digite a sequencia: ");
	gets(fita);
	
	for(p=0; fita[p]!='\0'; p++){
			if(contains(fita[p]) == 0){
				printf("REJEITADO\n");
				printf("%s\n", fita);
				for(i=0; i<p; i++){
				printf("-");
				}
				printf("^");
				getchar();
				return(-1);
				}
		}
	printf("ACEITO");
	getchar();
	return(0);
	}


