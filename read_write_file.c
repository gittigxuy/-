//程序名：linkfile.c
//执行时可用：linkfile filename1 filename2形式的命令行运行，将文件filename2的内容附加在文件filename1之后。
// file linked program.
#include <stdio.h>
#define SIZE 512
void main(int argc,char *argv[])
{
    char buffer[SIZE];
    FILE *fp1,*fp2;
    if(argc!=3)
    {
        printf("Usage: linkfile filename1 filename2\n");
        return;
    }
    // 按追加方式打开argv[1] 所指文件
    if((fp1=fopen(argv[1],"a"))==NULL)
    {
        printf("The file %s can not be opened.\n",argv[1]);
        return;
    }
    if((fp2=fopen(argv[2],"r"))==NULL)
    {
        printf("The file %s can not be opened.\n",argv[2]);
        return;
    }
    // 读入一行立即写出，直到文件结束
    while(fgets(buffer,SIZE,fp1)!=NULL)
        printf("%s\n",buffer);
    while(fgets(buffer,SIZE,fp2)!=NULL)
        fputs(buffer,fp1);
    fclose(fp1);
    fclose(fp2);
    if((fp1=fopen(argv[1],"r"))==NULL)
    {
        printf("The file %s can not be opened.\n",argv[1]);
        return;
    }
    while(fgets(buffer,SIZE,fp1)!=NULL)
        printf("%s\n",buffer);
    fclose(fp1);
}
