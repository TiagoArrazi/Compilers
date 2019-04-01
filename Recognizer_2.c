#include <stdio.h>
#include <stdlib.h>

void error_pointer(int p){
    int i;
    for(i=0; i<p; i++){
    	printf("-");
    }
    printf("^");


}

int main(int argc, char *argv[]){
    char fita[255];
    int p;
    printf("Digite a sequencia: ");
    gets(fita);

    for(p=0; fita[p]!='\0'; p++){
	if(fita[p] == 'e'){
		if(fita[p+1] != 'l' || fita[p+2] != 's' || fita[p+3] != 'e'){
			printf("REJEITADO\n");
			printf("%s\n", fita);
			error_pointer(p);
			getchar();
			return(-1);
		}else{ 
			p+=3; 
		}
	}else if(fita[p] == 'i'){
		if(fita[p+1] != 'f'){
			printf("REJEITADO\n");
                        printf("%s\n", fita);
			error_pointer(p);
                        getchar();
                        return(-1);

		}else{
			p+=1;
		}
	}else if(fita[p] != 'a' && fita[p] != 'b'){
	      	printf("REJEITADO\n");
                printf("%s\n", fita);
		error_pointer(p);
                getchar();
                return(-1);

	}	

    }

    printf("ACEITO\n");
    getchar();
    return(0);
}
