#include<stdio.h>

int main(){
	char line[1000];
	int rem = 0;
	while(fgets(line, sizeof(line), stdin) != NULL){
		if( rem%3 == 1 ){
			printf("%s", line);
		}
		rem = (rem+1)%3;
	}
	return 0;
}
