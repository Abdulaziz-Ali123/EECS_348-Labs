#include<stdio.h>


int Convert( int temp, char scale, char target) {
	
	float converted = 0;

	//Cel. to Fahr.
	if (scale == 'C' && target == 'F'){
		converted = temp * (9/5) + 32;
	} 
	
	//Cel. to Kel.
	if (scale == 'C' && target == 'K'){
		converted = temp + 273.15;
	} 

	//Fahr. to Cel.
	if (scale == 'F' && target == 'C'){
		converted = (temp - 32) * (5/9);
	} 

	//Fahr. to Kel.
	if (scale == 'F' && target == 'K'){
		converted = (temp * (9/5) + 32)+ 273.15;

	} 

	//Kel. to Cel.
	if (scale == 'K' && target == 'C'){
		converted = temp - 273.15;

	} 

	//Kel. to Fahr. 
	if (scale == 'K' && target == 'F'){
		converted = (temp * (9/5) + 32) - 273.15;
	}

	if (scale == target){
		converted = temp;
	}

	return converted;
}	


int main() {
	
	//initialize variables
	int temp;
	char scale;
	char target;

	// get temerature
	printf("Enter a temperature: ");
	scanf("%d", &temp);

	// get scale
	printf("What is the scale of the temperature Kelvin(K) Celcius(C) Fahrenheit(F): ");
	scanf(" %c", &scale);

	// get target scale
	printf("What would you like to convert to Kelvin(K) Celcius(C) Fahrenheit(F): ");
	scanf(" %c", &target);
	
	// Convert
	float converted = Convert(temp, scale, target);
		
	// Celius conversion for conveniance
	float standard = Convert(converted, scale, 'C');
	
	// weather advisory statments
	if (standard < 0){
		printf("Its below freezing. Please stay inside.");
	} else if (standard >= 0 && standard< 10){
		printf("Its cold outside. Please wear a jacket.");
	} else if (standard >= 10 && standard < 25){
		printf("Its good weather today, wear something comfy.");
	} else if (standard >= 25 && standard < 35){
		printf("Its Hot outside. Please were something light.");
	} else { 
		printf("Its extreme heat outside. Please stay inside.");
	}
}
