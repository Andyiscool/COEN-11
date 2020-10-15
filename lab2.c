#include<stdio.h>
#include<string.h>
void insert();
void next();
void printing();
char symptoms[][30] = {"fever", "headache", "flu", "stomachache", "allergies", "breathing difficulties", "swollen eye", "runny nose", "diareia", "dizziness"};
char gender [][10] = {"Male", "Female"};
int count = 0;//counting
int Experiment;
int TurnedAway;
int MaxSize;
//int symptomarray[50];
//int genderarray[50];
double addsymptomwait[50];
double addgenderwait[50];//add gender and symptom wait
double WaitTimeTotalSymptom[10];
double WaitTimeTotalGender[2];
int PatientSeenSymptom[10];
int PatientSeenGender[2];
int symptomn;
int gendern;
int patientn;
int k;
int l;
double retest;
double waittime;
int *gqueue;
int *squeue;
//int main (void){
int main (int argc, char* argv[]){
    MaxSize = atoi(argv[1]);
    retest = atof(argv[2]);
//    if (argc != 3){
//	printf("3 inputs expected \n");
  //  } 
  // if (retest < 0 ||retest > 1){
    //      printf("retest should be between 0 and 1\n");
      // }

    gqueue = (int*)malloc(MaxSize * sizeof(int));
    squeue = (int*)malloc(MaxSize * sizeof(int));








//else {
//	("Value Normal \n");
   /* }
    if (retest > 0.3){
        ("Retest too big \n");
    } else {
        ("Retest value normal \n");
    }*/
    srand((int) time (NULL));
    for (Experiment = 0; Experiment < 10000; Experiment++){
        int number = rand() % 100 + 1;
        if (number > 50){
            insert();
        } else {
            next();
        }
    }
    printing();
    free(gqueue);
    free(squeue);
}
void insert(){
    if (count >= MaxSize){
       TurnedAway++;
       return;
    }
    symptomn = rand() % 10;
    gendern = rand() % 2;
    squeue[count] = symptomn;
    gqueue[count] = gendern;
    count++;
}
void next(){
    int i;
    int firstpatientgender;
    int firstpatientsymptom;
    firstpatientgender = gqueue[0];
    firstpatientsymptom = squeue[0];
    addgenderwait[firstpatientgender] = rand() % 30 + 1.0;
    addsymptomwait[firstpatientsymptom] = rand() % 30 + 1.0;
    WaitTimeTotalGender[firstpatientgender] += addgenderwait[firstpatientgender];
    WaitTimeTotalSymptom[firstpatientsymptom] += addsymptomwait[firstpatientsymptom];
    PatientSeenGender[firstpatientgender] += 1;
    PatientSeenSymptom[firstpatientsymptom] += 1;
    for (i = 0; i <= count; i++){
        gqueue[i] = gqueue[i+1];
        squeue[i] = squeue[i+1];
    }



   patientn = rand() % 100 + 1;
   if (patientn > (retest * 100)){
        PatientSeenGender[count] = PatientSeenGender[i];
        PatientSeenSymptom[count] = PatientSeenSymptom[i];
    }else{
	count--;    
        return; 
    }
}
void printing(){
    printf("Gender, Wait Time (Minutes)\n");
    printf("-------------------------------------\n");
    for (k = 0; k <= 1; k++){
         printf(gender[k]);
         printf(", ");
         printf("%f", PatientSeenGender[k] == 0? 0 : (WaitTimeTotalGender[k]/PatientSeenGender[k]));
         printf(" Minutes\n");
    }
    printf("------------------------------------\n");
    printf("    \n");
    printf("Symptom, Average Wait Time (Minutes)\n");
    printf("------------------------------------\n");
    for(l = 0; l <= 9; l++){
        printf(symptoms[l]);
        printf(", ");
        printf("%f", PatientSeenSymptom[l] == 0? 0 : (WaitTimeTotalSymptom[l]/PatientSeenSymptom[l]));
     	printf(" Minutes\n");
    }
    printf("------------------------------------\n");
    printf("    \n");
    printf("Turned Away Patients: %d\n", TurnedAway);
    printf("------------------------------------\n");
}
