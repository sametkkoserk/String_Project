//Samet Köser 150119910


#include <stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int charAt(char *s, int index){//get the string and index and give the wanted index character.
	int result;
	if (index>=strlen(s) ||index<0){
		result=-1;
	}
	else{
		result=0;
	}
	
	return result;
	
}

char *concat(char *s1, char *s2){//get the first string and second string and give the combination of them 

	int from=strlen(s1);
	int i;
	for(i = 0; i < strlen(s2); i++){
		s1[from+i]=s2[i];
	}
	return s1;
}
unsigned int strSearch(char *s1, char *s2){//get the first string and second string and if ther

	int num;
	int i;
	int from=0;
	int to=0;
	int the=-1;
	int result;
	for(i = 0; i < strlen(s1); i++){//find the index of second string in first string
		if((int)s1[i]==(int)s2[num]){
			num+=1;
		}
		else{
			num=0;
		}
		if(num==strlen(s2)){
			the=i;
			
			break;
		}
		
	}
	num=0;
	if(the!=-1){
		for(i = 0; i < strlen(s1); i++){//get the spaces in string with ascii code and get the before and after spaces of second string's index and give the result
			if((int)s1[i]==32){
				if (num==0){
					from=-1;
					to=i;
					num=1;
				}
				else{
					from=to;
					to=i;
				}
	
			}
	
			if (i==strlen(s1)-1 && (int)s1[i]!=32){
				from=to;
				to=strlen(s1);
			}
			if(the<to&&the>from){
				result=to-from-1;
				break;
			}
		}
	}
	else{//if there is no second string in first string result 0
		result=0;
	}
	
	
	return result;
	
}

unsigned int findScore(char *s1){//find the score of the string depend on the given letter score
	char score1[]="AEIOULNRST";
	char score2[]="DG";
	char score3[]="BCMP";
	char score4[]="FHVWMY";
	char score5[]="K";
	char score8[]="JX";
	char score10[]="QZ";
	
	int score=0;
	
	int i;
	int j;
	for(i = 0; i < strlen(s1); i++){//for all letters in the string control the score and add to score 
		for(j = 0; j < strlen(score1); j++){
			if((int)s1[i]==(int)score1[j]||(int)s1[i]==(int)tolower(score1[j])){
				score+=1;
			}
		}
		for(j = 0; j < strlen(score2); j++){
			if((int)s1[i]==(int)score2[j]||(int)s1[i]==(int)tolower(score2[j])){
				score+=2;
			}
		}
		for(j = 0; j < strlen(score3); j++){
			if((int)s1[i]==(int)score3[j]||(int)s1[i]==(int)tolower(score3[j])){
				score+=3;
			}
		}
		for(j = 0; j < strlen(score4); j++){
			if((int)s1[i]==(int)score4[j]||(int)s1[i]==(int)tolower(score4[j])){
				score+=4;
			}
		}
		for(j = 0; j < strlen(score5); j++){
			if((int)s1[i]==(int)score5[j]||(int)s1[i]==(int)tolower(score5[j])){
				score+=5;
			}
		}
		for(j = 0; j < strlen(score8); j++){
			if((int)s1[i]==(int)score8[j]||(int)s1[i]==(int)tolower(score8[j])){
				score+=8;
			}
		}
		for(j = 0; j < strlen(score10); j++){
			if((int)s1[i]==(int)score10[j]||(int)s1[i]==(int)tolower(score10[j])){
				score+=10;
			}
		}
		
	}
	
	return score;
	
}
int main(int argc,char* argv[]){//get the txt and direct to the wanted function, give the stat or quit
	char input_name[1000]="input.txt";
	char output_name[1000];
	
	char name[100];
	char line[1000];
	int num=0;
	char part1[1000];
	char part2[1000];
	char part3[1000];
	char part32[1000];
	int to;
	int at;
	int words=0;
	//printf("Name of the input file: ");
	//scanf("%s",input_name);
	
	printf("Name of the output file: ");
	scanf("%s",output_name);

	FILE *output;
	output= fopen(output_name, "a");
	FILE *Ptr; 
	if ((Ptr = fopen(input_name, "r")) == NULL) { //control if the txt file is opened or not      
		puts("File could not be opened");   
	}    
	else{
		
		char letter;
		while (!feof(Ptr)) {
			fscanf(Ptr, "%[^\n]\n", line);//get the line as line char
			
			int i;
 
			char *string = line;
            char *e;
            int index;

            e = strchr(string, ':');// find the index of colon
            index = (int)(e - string);
            if (index<0){// control is there any colon or not 
				index=100;
			}
			

            for (i = 0; i < strlen(line); i++){
            	if((int)line[i]<91&&(int)line[i]>64&& strlen(line)>4){// if it is a letter add one to num 
					num+=1;
				}
				else if((int)line[i]<123&&(int)line[i]>96&& strlen(line)>4){
					num+=1;
				}
				if(i<index){//if it is before colon or stat and exit add it to part1 
					part1[i]=line[i];
					
				}
				else if(i==index+1){//if it is direct number then add it to part2
					part2[0]=line[i];
				}
				else if(i>index+2){// if it is second string or number add to part3
					part3[i-index-3]=line[i];
				}
				
			}     
			
			if(strlen(line)==4&&(int)line[0]=='s'){//control if it is stat
				

				fprintf(output,"The number of words: %d\n",words);
				fprintf(output,"The number of alphabetic letters: %d\n" ,num);
				
			}
			else if(strlen(line)==4){//control if it is quit or exit
				fprintf(output,"Program ends. Bye");
				break;
			}
			
			sscanf(part2, "%d", &to);
			
			         
		 	if(to==1||to==2||to==3||to==4){//count the words of part1
		 		for(i = 0; i < strlen(part1); i++){
					if((int)part1[i]==32){
						words+=1;
					}
				}
				words+=1;
				if(to==2||to==3){
					for(i = 0; i < strlen(part3); i++){//count the words of part2 if it is a string
						if((int)part3[i]==32){
							words+=1;
						}
					}
					words+=1;
				}
			}

		  	
			
			if(to==1){//if wanted function is char at direct it and if there is no such second string in first string give -1
		  		
		  		for(i = 0; i < strlen(part3); i++){
		  			if ((int)part3[i]>47&&(int)part3[i]<58){
		  				part32[i]=part3[i];
		  				
					  }
		  			
				}
		  		sscanf(part32, "%d", &at);
		  		if(charAt(part1,at)==0){
		  			fprintf(output,"%c\n",part1[at]);
				}
				else{
					fprintf(output,"%d\n",-1);
				}
		  		
			}
			
			else if(to==2){//if wanted function is concat direct it
				
				fprintf(output,"%s\n",concat(part1,part3));
			}
			else if(to==3){//if wanted function is strsearch direct it
				fprintf(output,"%d\n",strSearch(part1,part3));
				
			}
			else if(to==4){//if wanted function is findscore direct it
				fprintf(output,"%d\n",findScore(part1));
			}
			memset(part1, 0, sizeof part1);
		  	memset(part2, 0, sizeof part2);
		  	memset(part3, 0, sizeof part3);
		  	memset(part32, 0, sizeof part32);
		  	to=0;
		} 
		
		 
	}
	
	
	fclose(Ptr);
	
}



