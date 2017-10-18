#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentT{
	char *name;
	int literature;
	int math;
	int science;
}studentT;

int main(int argc, char *argv[]){
	int num;
	FILE *fp;
	fp = fopen(argv[1], "r"); //open file for reading 
	fscanf(fp, "%d\n", &num); //read number
	
	studentT *list = (studentT *)malloc(sizeof(studentT) * num); //allocate memory for number of structure
	for(int i = 0; i < num; i++){
		list[i].name = (char *)malloc(30 * sizeof(char)); //allocate name
	}

	for(int i = 0; i < num; i++){
		fscanf(fp, "%s %d %d %d\n", (list[i].name), &(list[i].literature), &(list[i].math), &(list[i].science)); //reading name and scores, store them at structure	
	}

	fclose(fp); //close file

	FILE *fw = fopen(argv[2], "w"); //open file for output	
	fprintf(fw, "  Name   Literature    Math    Science      Ave.   \n"); //print first line
	for(int i = 0; i < num; i++){
		fprintf(fp, "  %.5s%8d        %d        %d        %.2f   \n", (list[i].name), list[i].literature, list[i].math, list[i].science, (list[i].literature + list[i].math + list[i].science) / 3.0);
		//print students' names and scores
	}

	int lit_sum = 0, math_sum = 0, sci_sum = 0;
	float lit_avg, math_avg, sci_avg;
	for(int i = 0; i < num; i++){
		lit_sum += list[i].literature;
		math_sum += list[i].math;
		sci_sum += list[i].science;
	} //calculate score sum
	lit_avg = lit_sum / 3.0;
	math_avg = math_sum / 3.0;
	sci_avg = sci_sum / 3.0; //calculate average
	fprintf(fw, "  Ave.%10.2f%10.2f%10.2f\t%10.2f\n", lit_avg, math_avg, sci_avg, (lit_avg + math_avg + sci_avg) / 3);
	//print last line
	fclose(fw); //close output file

	return 0;
}