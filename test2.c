#include <stdio.h>
enum
{
    SUCCESS,
    FAIL
};
main()
{
    FILE *fptr;
    char filename[] = "file.txt.docx";
    int reval = SUCCESS;
    if ((fptr = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename);
        reval = FAIL;
    }
    else
    {
        printf("The value of fptr: 0x%p\n", fptr);
        printf("Ready to close the file.");
        fclose(fptr);
    }
    return reval;
}