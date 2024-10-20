#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	char code[80];//to store string
	int num[80];//to store number you input
	int i,a = 1;//
	printf("PLease enter the code you want to decode and the number you want to move:");
	scanf("%s%d%d%d%d",code,&num[1],&num[2],&num[3],&num[4]);//
	if(code[0]=='+')//determine wether the first character is + or not
	{
		for(i=1;i<strlen(code);i++)//loop i as the length of character
		{
			if(code[i]<'A'||code[i]>'Z') //set the circumstance that is not satisfy when it is not capital letters
			{
			 printf("Error format.");
			 system("pause");
			 return 0;
			} 
		
		num[a]=num[a]%26;//since the number may over 26,we use dividion to caculate the remainder
		code[i]+=num[a];//using the letters plus those number
		if(code[i]>'Z')
		
			code[i]-=26;
			a=a+1;//since i is increase then a should be increase
		}
		printf("%s\n",code+1);
	}
		else if(code[0]=='-')//determine wether the first character is - or not
	{
		for(i=1;i<strlen(code);i++)
		{
			if(code[i]<'A'||code[i]>'Z') 
			{
			 printf("Error format.");
			 system("pause");
			 return 0;
			} 
		
		num[a]=num[a]%26;//since the number may over 26,we use dividion to caculate the remainder
		code[i]-=num[a];//using the letters minus those number
		if(code[i]<'A')
			code[i]+=26;
			a=a+1;//since i is increase then a should be increase
		}
		printf("%s\n",code+1);
	}
	else
	{
		printf("The first symbol have to be + or -");
	}
	system("pause");
}
