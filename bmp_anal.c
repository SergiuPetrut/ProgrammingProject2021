#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "functions_header.h"
void bmp_analyzer(int temp[], int header[], int start, double weights[3])
    {
        for(int j = 0; j < temp[22]; j++){
        
        
        
            for(int i = 0; i < temp[18]; i++){
        
                double filepxl[3] = {(float)header[start+2+(3*i)]/255, (float)header[start+1+(3*i)]/255,(float)header[start+(3*i)]/255};
                if (anal(filepxl, weights)> 0.4)
                {
                    temp[start+2+(3*i)]= header[start+2+(3*i)];
                    temp[start+1+(3*i)]=header[start+1+(3*i)];
                    temp[start+(3*i)]=header[start+(3*i)];
                    printf("temp: %d\n %d\n %d\n",temp[start+2+(3*i)], temp[start+1+(3*i)],temp[start+(3*i)]);
                }   
            
            
        }
        start+= header[18]*3;
        start++;
        temp[start]= 0;
        start++;
        temp[start] = 0;
           
        
        
    }
    }
int randomf(int header[])
{
    srand(time(NULL));

    

 //Random Colours for the input
    int start = header[10];
    for(int j = 0; j< header[22]; j++){
    

        for(int i = 0 ; i< 3*header[18] ; i++){
            header[start+i] = (int)((float)rand()/RAND_MAX*255); 

        }
        start += 3 * header[18];
        start++;
        header[start]= 0;
        start++;
        header[start] = 0;
        
        
    }
    
     
     
    return 0;
}

//Making the Arr into a BMP File
int write(char * filename, int message[], int n)
{
    FILE * fp;
    if((fp= fopen(filename, "w+"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
     
    for(int i=0; i<n; i++)
    {
        putc(message[i], fp);
    }

    
     
    fclose(fp);
    return 0;
}

// I used this function to check colours just from file, but after few problems i decided to work with pixels in the array 
int read(char * filename, int pos){
    FILE * fp;
    int buffer[1];
    if((fp= fopen(filename, "r+"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    fseek(fp, pos, SEEK_SET);
    fread(buffer, 1, 1, fp);
    fclose(fp);
    return buffer[0];
}

