#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade
	
	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades	
	
	char languages[100];		// spoken languages
	
} Student;
int mostLanguages(Student students[],int size);
int languageCount(Student s);


int main(int argc, char *argv[]) {
	FILE *db = NULL;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");
		
	if (db){							
		Student students[1000];			// all the data goes here
		int size = 0;					// how many students in database
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded succesfully\n", size);
        char *fileName = "query12.txt";
        FILE *fp = fopen(fileName, "w");
        if (fp == NULL)
        {
            printf("Error opening the file %s", fileName);
            return -1;
        }
        fprintf(fp, "QUERY12\n");
		
		
		// MODIFY CODE BELOW
		
		int counterDemo = 0; // for counting students
		int maxLanguages = mostLanguages(students, size);
		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			
			if(languageCount(s)==maxLanguages){ // *** first filter, conditions on the student
				fprintf(fp, "%s %s, Course - %d, Average: %.2f Load: %d\n", s.name, s.surname, s.course, s.average, s.load); // print student data
				int anotherDemo = 0; // for counting courses/grades
				for (int i = 0; i < s.load; ++i){ // process each course taken by the student
					if(1){ // *** second filter, conditions on the course/grade
						++anotherDemo; // counting courses
						fprintf(fp, "%s %d\n", s.courses[i], s.grades[i]);
					}
				}
				fprintf(fp, "Languages: %s\n\n", s.languages);
						
				if (anotherDemo == s.load) // *** third filter, various other conditions			
					++counterDemo; // counting students
			}
		}
		fprintf(fp, "Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);
        fclose(fp);
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	
	return 0;
}
int mostLanguages(Student students[],int size){
    int languageCount=1;
    int mostLanguages=0;
    int j=0;
    for(int i=0;i<size;i++){
        while(students[i].languages[j]!='\0'){
            if(students[i].languages[j]==' ' || students[i].languages[j]=='\n' || students[i].languages[j]=='\t'){
                languageCount++;
            }
            j++;
        }
        if(languageCount>mostLanguages){
            mostLanguages=languageCount;
        }
        languageCount=1;
        j=0;
    }
    return mostLanguages;
}
int languageCount(Student s){
    int i=0;
    int languageCount=1;
    while(s.languages[i]!='\0'){
        if(s.languages[i]==' ' || s.languages[i]=='\n' || s.languages[i]=='\t'){
            languageCount++;
        }
        i++;
    }
    return languageCount;
}
