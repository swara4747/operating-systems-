#include<stdio.h>
int main(){
int pages;  //number of pages in reference string
int n;            //number of frames in the string 
   
//taking user input to read the number of frames and pages
printf("enter the number of frames in the fifo array:  ");
scanf("%d", &n);

printf("enter the number of pages:  ");
scanf("%d", &pages);

int ref_string[pages];
printf("enter the reference string :  ");
//since we have to take one by one input of the reference strings into the frame
//we use a for loop to take the user input till the total number of pages
for (int i=0;i<pages; i++){
scanf("%d", &ref_string[i]);
}
    
//initialising all the frames as empty first (which is -1)
int frames[n];
for (int i=0;i<n;i++){
frames[i]=-1;
}
//initialising pointer and page faults as zero as the first step
int pointer=0;             
int page_faults=0;
//it is a triggered signal by the hardarware
int currentpage;
    
//operating on each page in the reference string , we write 2 conditions of either page hit or no page hit
for (int i=0;i<pages;i++){
int currentpage=ref_string[i];
int pagehit=0;  //page fault 

for (int j=0;j<n;j++){
if (frames[j]==currentpage){
int pagehit=1;
    printf("page hit succesful\n");
break;
}
}

//this is the counter for page faults 
if (!pagehit){
page_faults++;
    frames[pointer]=currentpage;
    pointer=(pointer+1) % n ;    //circular pointer increment
}
    else{
        printf("page fault case");
        
    }
   
for (int j = 0; j < n; j++) {
                if (frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }
            printf("]\n");
        }
      printf("\nTotal page faults: %d\n", page_faults);

    return 0;
}
