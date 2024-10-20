#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#pragma warning( disable : 4996)

int main() {
        int i;
        char code[100];//to store string
        printf("please enter the code you want to decode which only using upper case alphbet:\n");
        scanf("%s",code);

                if(code[0]=='+')//determine wether the first character is + or not
                {
                	
                        for(i=1;i<strlen(code);i++)//loop i as the length of character
                        {
                        	
					  if (code[i] < 'A' || code[i] > 'Z')//set the circumstance that is not satisfy when it is not capital letters
					{
						printf("Error format");
						system("pause");
						return 0;//since it is int main we need to return the value 0 back
						
					}
                                code[i]=code[i]+2;//let those character next two step
                                if(code[i]>'Z')//after we caculate the character,it may be over Z we can minus 26 to satisfy the situation
                                	{
									code[i]=code[i]-26;
									}
                                
                        }
                         printf("the result is %s \n",code+1);//output the outcome,when we +1 we can just output those letters without + or -
                    
                }
                else if(code[0]=='-')//determine wether the first character is - or not
                {
                	 if (code[i] < 'A' || code[i] > 'Z')//set the circumstance that is not satisfy when it is not capital letters
					{
						printf("Error format");
						system("pause");
						return 0;
					}
                        for(i=1;i<strlen(code);i++)
                        {
                                code[i]=code[i]-2;//let those character back two step
                                if(code[i]<'A')//after we caculate the character,it may be smaller than A we can plus 26 to satisfy the situation
								 {
								code[i]=code[i]+26;
							}
							
                        }
                          printf("the result is %s \n",code+1);//output the outcome,when we +1 we can just output those letters without + or -
                       
                }
               system("pause");
               return 0;

              
            }
        
        

            





