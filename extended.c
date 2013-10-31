#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char program_name[15];

int extended_gcd(int a,int b){

long long unsigned int y,lasty,quotient,temp1,temp2;

y = 1;
lasty = 0;

while(b != 0){

quotient = a / b;
temp1 = a%b;
a = b;
b = temp1;

temp2 = y;
y = lasty - (quotient*y);
lasty = temp2;

} //End of while

return(lasty);
} // End of function

void print_help() {
	fprintf(stderr, "%s%s%s\n", "Usage: ",program_name," phi e");
	exit(EXIT_FAILURE);
}

void check_argument(char *checker) {
	if (*checker != '\0')
	{
		fprintf(stderr, "%s\n", "ERROR bad arguments! Check your arguments again!");
		print_help();
	}
}


int main(int argc, char const *argv[]) {
 //Main function
strcpy(program_name, argv[0]);
if (argc > 3 || argc < 3)
{
	print_help();
}
//Local variables
long long unsigned int phi = 0;
long long unsigned int e = 0;
char *endpt;

//Convert the values from argv[1] and argv[2]
phi = strtoull(argv[1],&endpt, 10);
//Check argument if endpt points to '\0' (Only numbers)
check_argument(endpt);

//Same as above
e = strtoull(argv[2], &endpt, 10);
check_argument(endpt);

//Function call
long long int g = extended_gcd(phi,e);

if(g < 0) { //Check if number if negative. If so then make it positive.

	for (int i = 1; i > 0; i++){

	g = g + (i*phi);

		if(g > 0){

		break; // When positive, break.
		}
	}
}

printf("%s%lld\n","Invers: ", g);
	
return 0;
}
