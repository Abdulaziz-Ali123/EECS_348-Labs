#include<stdio.h>

// recursive function
void Find_Play_Combinations(int score, int score_points[], int combinations[], int ways_to_score, int index, int start){
	//base case stops code from recursing infinitely
	if (score < 0){ return;}
	//base case 2: calculates combinations and prints them
	if (score == 0){
		//tracker for each point 
		int count_8pt = 0, count_7pt = 0, count_6pt = 0, count_3pt = 0, count_2pt = 0;
		
		//search combinations up until the index
		for (int i = 0; i < index; i++){
			if (combinations[i] == 8) { count_8pt++; }
			else if (combinations[i] == 7) { count_7pt++; }
			else if (combinations[i] == 6) { count_6pt++; }
			else if (combinations[i] == 3) { count_3pt++; }
			else if (combinations[i] == 2) { count_2pt++; }
		}

		// print combinations
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", count_8pt, count_7pt, count_6pt, count_3pt, count_2pt);

		//break the current layer of recursion
		return;
	}
	
	//recurse for each way to score
	for (int i = start; i < ways_to_score; i++){
		//stores the current score_point being checked
		combinations[index] = score_points[i];
		
		//recurse and check all combinations starting from i
		/*
		 * for example once all possibilities for scoring with 8,7,6,3,2 are check
		 * since all the possible ways to score with 8 have already been checked we should check all possibilities with just 7,6,3,2 
		 * doing this removes duplicate possibilities
		*/
		//decrease score by current ways_to_score
		//increase index by 1 to move up in the combinations list
		Find_Play_Combinations(score - score_points[i], score_points, combinations, ways_to_score, index+1, i);
	}
}

int main(){

	int score;
	//stores combinations of plays
	int combinations[100]; 
	//stores the different ways to score
	int score_points[] = {8,7,6,3,2};

	while (1){
		//get get score input
		printf("Enter a the NFL score (Enter 0 or 1 to STOP): ");
		scanf("%d", &score);
		
		if (score <=1 ) {break;}

		//print possible combinations of scoring 
		printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
		//start recurssion
		Find_Play_Combinations(score, score_points, combinations, 5, 0, 0);
	}
	

}

