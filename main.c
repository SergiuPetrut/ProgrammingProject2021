#include "functions_header.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

//The structure of the BMP header

    srand(time(NULL));
    int header[374] = {//14 Bytes Of Info//
                0x42, 0x4d, //BitMap Signature
                0x06, 0x17, 0x00, 0x00, //Size of file
                0x00, 0x00, //Reserved
                0x00, 0x00, //Reserved
                0x36, 0x00, 0x00, 0x00, //Start

//Device-Independent Bitmap Header//
                0x28, 0x00, 0x00, 0x00, //Header Size
                0x0a, 0x00, 0x00, 0x00, //BM Width
                0x0a, 0x00, 0x00, 0x00, //BM Height
                0x01, 0x00, // Color Planes #=1
                0x18, 0x00, //Bits/Pixel
                0x00, 0x00, 0x00, 0x00, //Compression
                0x00, 0x14, 0x00, 0x00, //ImgSize
                0x00, 0x00, 0x00, 0x00,//HorizRes
                0x00, 0x00, 0x00, 0x00, //VertRes
                0x00, 0x00, 0x00, 0x00, //#Colours
                0x00, 0x00, 0x00, 0x00, //#ColoursWeActuallyNeed
//ArrPixel//
                0x24, 0x1c, 0xed,
                0x24, 0x1c, 0xed,
                0x00, 0x00, //RawGap
                0x24, 0x1c, 0xed,
                0x24, 0x1c, 0xed,
                0x00, 0x00};//End
//Some of the values are the same, I'll only mention the different ones from the previous variable
    int temp[374] = {0x42, 0x4d,0x06, 0x17, 0x00, 0x00,0x00, 0x00,0x00, 0x00,0x36, 0x00, 0x00, 0x00,0x28, 0x00, 0x00, 0x00,0x0a, 0x00, 0x00, 0x00,0x0a, 0x00, 0x00, 0x00,0x01, 0x00,0x18, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x14, 0x00, 0x00,0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00,//Blue , Green and Red
                0x00, 0x00, 0x00,
                0x00, 0x00, //RawGap
                0x00, 0x00, 0x00,
                0x00, 0x00, 0x00,
                0x00, 0x00};//End
    char * input = "in.bmp";
    char * output = "out.bmp";

    //SynapticWeights
    double weights[3];
    //Training Array Numero One (to get some rough values)
    double execinp[4][3]={ {1, 0, 0.5},
                        {0, 0.5, 0},
                        {0.01, 0.9, 0.1},
                        {0.99, 0.5, 0.9}};
    double execoutp[4] = {0, 1, 1, 0};
    //Training Array Numero Dos (makes it more accurate)
    double execinp1[4][3] ={{1, 0, 1},
                            {1, 1, 1},
                            {0, 0, 0},
                           {0, 1, 1}};
    double execoutp1[4] ={0, 0, 0, 0};

    weights[0] = 2*(float)rand()/RAND_MAX -1;
    weights[1] = 2*(float)rand()/RAND_MAX -1;
    weights[2] = 2*(float)rand()/RAND_MAX -1;



    trainer(execinp, execoutp, 10000, weights);
    trainer(execinp1, execoutp1, 1000, weights);

//BMP Analysis


    int n = sizeof(header)/sizeof(header[0]); //Creating the input
    randomf(header);
    write(input, header, n);

    int start = temp[10]; //The analysis starts
    bmp_analyzer(temp, header, start, weights);
    n = sizeof(temp)/sizeof(temp[0]);

    write(output, temp, n);

    return 0;


}
