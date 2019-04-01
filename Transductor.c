#include <stdlib.h>
#include <stdio.h>


char tape[255]; int p=0;
char tempS[20]; int t=0;
char tabVar[20][20]; int k=0;

void copy(char d[], char s[]);
int equal(char u[], char d[]);
void printTabVar();

void s0(); // initial and final state
void s1();

void sigma1(); // tempS[0] <- symbol
void sigma2(); // tempS += symbol
void sigma3(); // checks whether tempS is in tabVar

int main(int argc, char *argv[]) {
    
    fgets(tape, 20, stdin);
    s0();
    return(0);
    
}

void s0() {
    
    if(tape[p] >= 'A' && tape[p] <= 'z') {
        sigma1();
    
    }
    else if(tape[p] == '\0'){
    	printf("\n\n");
        printTabVar();
        exit(0);
    }
        
    else {
        p++;
        s0();
    }
}

void s1() {
    
    if((tape[p] >= 'A' && tape[p] <= 'z') || (tape[p] >= '0' && tape[p] <= '9')) {
        sigma2();
    }
    
    else {
        sigma3();
    }   
}

void sigma1(){
    
    tempS[t] = tape[p];
    p++;
    t++;
    s1();
        
}


void sigma2(){
    
    tempS[t] = tape[p];
    p++;
    t++;        
    s1(); 
	  
}


void sigma3(){
    
    tempS[t] = '\0';
    
    int c;
    int flag = 0;
    int pos;

    for(c=0; c<20; c++){
	
        if(equal(tempS, tabVar[c]) == 1){
	    flag = 1;
	    pos = c;

	}
    }

    if(flag == 1){
        printf("VAR(%d) ", pos);
   
    }

    else{
        copy(tabVar[k], tempS);
	printf("VAR(%d) ", k);
	k++;
    
    }

    t = 0;
    s0();   
}


void copy(char d[], char s[]) {
    
    int c;
    for(c=0; d[c]=s[c]; c++);
    
}


int equal(char u[], char d[]) {
    
    int i = 0;
    int flag = 0;
    
    while(u[i] != '\0' && d[i] != '\0'){
    	
    	if(u[i] != d[i]){
            flag = 1;
	}

    	i++;
    }
	
	if(flag == 0 && u[i] == '\0' && d[i] == '\0'){
	    //printf("\n%s & %s are equal\n", u, d);
            return 1;
	}
    	else{
    	    //printf("\n%s & %s are NOT equal\n", u, d);
            return 0;
	}
    
}


void printTabVar() {
    
    int i;
    for(i=0; tabVar[i][0]!='\0'; i++) {
        printf("%d...%s\n", i, tabVar[i]);
    }
    
}
