#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{

	char ch='g';               //��ʼ��һ���ַ���gΪ���⸳ֵ�����ǿ�ֵ����
	char filename[80];         //�ļ�������Ϊ�ַ�
    FILE *fp; 
	strcpy(filename,argv[2]);  //������ĵ������������Ƹ�filename
	fp=fopen(filename,"r");    //��ֻ����ʽ���ļ���Ϊfilename���ļ���ָ��ָ���һ���ַ�
	int cnt=0;
	if(strcmp(argv[1],"-c")==0)   //����ڶ���������-c��ִ��ͳ���ַ������Ĳ���
	{
		while(!feof(fp))            //���ļ�δ����ʱ��ִ������
		{
			ch=fgetc(fp);           //��ȡfpָ����ַ�����ֵ������
			cnt++;
			
		}
		printf("�ַ�����%d\n",--cnt);   //����ͳ�������һ�����з������������cnt��Ҫ��һ
		 
	}
	else
	{
		if(strcmp(argv[1],"-w")==0)         //����ڶ���������-w
		{
			
			int is_word = 0;                                               //���ڼ�¼�ַ��Ƿ��ڵ�����
			while (!feof(fp))                                    //��������ļ���β (ch = fgetc(fp)) != EOF
			{
				ch=fgetc(fp);
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))     //�ж� �������ĸ
				{         
					if(is_word==0)
					{
						cnt++;                                           //���is_word��0��״̬�������ż�һ����ֹ�����ո�����
					    is_word = 1;              //��¼���ڵ���״̬
			
					}
				
				}
				else 
					is_word = 0;                    //��¼�����ڵ���״̬
			}
			printf("��������%d\n",cnt);
		}
	}
	return 0;
}