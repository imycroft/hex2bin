#include <stdio.h>
bool verifyBin(FILE* file);
int main(int argc, char* argv[])
{
    FILE *ptr;
    FILE *ptrw;
    if(argc != 3) {
        printf("Usage: %s [hexFile] [binFile]\n", argv[0]);
        return -1;
    }
     ptr = fopen(argv[1],"rb");
    if(!ptr){
        printf("File %s not found", argv[1]);
        return -2;
    }
    if(!verifyBin(ptr)){
        printf("%s is not a binary file", argv[1]);
        return -3;
    }
    rewind(ptr);
    ptrw = fopen(argv[2],"wb");
    if(!ptrw){
        printf("Could not create file %s ", argv[2]);
        return -3;
    }
    unsigned char c;
    while(true)
    {
        fscanf(ptr,"%02x", &c );
        if(feof(ptr))
            break;
        fwrite(&c, sizeof(unsigned char),1, ptrw);
    }
    fclose (ptr);
    fclose (ptrw);
}
bool verifyBin(FILE* file){
    unsigned char c;
    fscanf(file,"%02x", &c);
    if(c != 'M')
        return false;
    fscanf(file,"%02x", &c);
    if(c != 'Z')
        return false;
    return true;
}

