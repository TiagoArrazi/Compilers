/*

TIAGO COSTA ARRAZI
GIOVANE JOSE FERNANDES

*/


#include <stdlib.h>
#include <stdio.h>


char tape[255]; int p=0;
char tempS[20]; int t=0;
char tabVar[20][20]; int k=0;
unsigned long long tempN;

void copy(char d[], char s[]);
int equal(char u[], char d[]);
void printTabVar();

void s0(); // initial and final state
void s1();
void s2();

void sigma1(); // tempS[0] <- symbol
void sigma2(); // tempS += symbol
void sigma3(); // checks whether tempS is in tabVar and shows V()
void sigma4(); // tempN <- symbol - '0'
void sigma5(); // tempN <- tempN * 10 + (symbol - '0')
void sigma6(); // shows N()

int main(int argc, char *argv[]) {
    
    fgets(tape, 255, stdin);
    s0();
    return(0);
    
}

void s0() {
    
    if(tape[p] >= 'A' && tape[p] <= 'z') {
        sigma1();
    
    }
    
    else if(tape[p] >= '0' && tape[p] <= '9') {
    	sigma4();	
	}
    
    else if(tape[p] == '\0') {
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

void s2() {
	
	if(tape[p] >= '0' && tape[p] <= '9') {
		sigma5();
	}
	
	else {
		sigma6();
	}
	
}

void sigma1() {
    
    tempS[t] = tape[p];
    p++;
    t++;
    s1();
        
}


void sigma2() {
    
    tempS[t] = tape[p];
    p++;
    t++;        
    s1(); 
	  
}


void sigma3() {
    
    tempS[t] = '\0';
    
    int c;
    int flag = 0;
    int pos;

    for(c=0; tabVar[c][0]!='\0'; c++) {
	
        if(equal(tempS, tabVar[c]) == 1) {
	    flag = 1;
	    pos = c;

		}
    }

    if(flag == 1) {
        printf("V(%d) ", pos);
   
    }

    else {
    	copy(tabVar[k], tempS);
		printf("V(%d) ", k);
		k++;
    
    }

    t = 0;
    s0(); 
	  
}

void sigma4() {
	
	tempN = tape[p] - '0';
	p++;
	s2();
	
}


void sigma5() {
	
	tempN = tempN * 10 + (tape[p] - '0');
	p++;
	s2();
	
}


void sigma6() {
	
	printf("N(%d) ", tempN);
	s0();
	
}


void copy(char d[], char s[]) {
    
    int c;
    for(c=0; d[c]=s[c]; c++);
    
}


int equal(char u[], char d[]) {
    
    int i = 0;
    int flag = 0;
    
    while(u[i] != '\0' && d[i] != '\0') {
    	
    	if(u[i] != d[i]) {
            flag = 1;
	}

    	i++;
    }
	
	if(flag == 0 && u[i] == '\0' && d[i] == '\0')
        return 1;
	
    else
        return 0;
	
    
}


void printTabVar() {
    
    int i;
    for(i=0; tabVar[i][0]!='\0'; i++) {
        printf("%d...%s\n", i, tabVar[i]);
    }
    
}
