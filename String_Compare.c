#include <stdio.h>
#include <stdlib.h>

int equal(char u[], char d[]) {
    
    int i = 0;
    int flag = 0;
    
    while(u[i] != '\0' && d[i] != '\0'){
    	
    	if(u[i] != d[i]){
    		flag = 1;
		}
    	i++;
	}
	
	if(flag == 0 && u[i] == '\0' && d[i] == '\0')
        return 1;
    else
        return 0;
    
}
int main(){
	
	char str_1[10] = "A2";
	char str_2[10] = "A2";
	
	if(equal(str_1, str_2) == 1){
		
		printf("the strings %s and %s are equal", str_1, str_2);
		return(0);
		
	}
	
	printf("the strings %s and %s are not equal", str_1, str_2);
	return(-1);	 
	
}
