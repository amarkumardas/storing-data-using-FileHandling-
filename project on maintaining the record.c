  #include<stdio.h>
 #include<errno.h>
int main()
{   struct habits
	{
		int number;
		char sentence[80]; //80 characters can be stored
		int done;
	}HABITsentence[100];//100 records can be stored
     FILE *fp,*fp2,*tempfile;
     int numberofrecords,i,ch,option,found,serielnumber,record,recordnumbertodelete,valueofi,countnumberofsamerecord,j;
     int toexit,k,arr[50],store,valueofdecrementednumberofrecords,linenumberofrecordtodelete,anothercountnumberofsamerecordvariable,decrement;
     do
     {
     	printf("\n********************** Enter your desired OPTION ******************************");
     	printf("\n[1].APPEND NEW DATA");
     	printf("\n[2].UPDATE DATA");
     	printf("\n[3].DISPLAY DATA");
     	printf("\n[4].DELETE RECORD\n");
     	printf("\nEnter the option: ");
     	scanf("%d",&option);
     	switch(option)
     	{
     	  case 1:fp=fopen("e:/hab.txt","r");       //int numberofrecords=2;//in switch case we cant use declaration statement we have to use only statement
     	       	if(fp==NULL){printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");}
		         numberofrecords=0;
		         tempfile=tmpfile();//to store record if file temporarily
		         while(1)       // while(feof(fp)==0){ch=fgetc(fp);if(ch=='\n'){numberofrecords++;	} } printf("%d",numberofrecords);both give same result
		         {
		            ch=fgetc(fp);
		            if(ch==EOF) 
		            {                 ///counting number of records
		            	break;
					}       //@@@@when the user entering data to file and suddendly close the console then data will not be saved to file to avoid this make sure program run till last.Because when program execute till last than there is fclose() function which indicate that when user entered data and program execute completely than fclose function close the file and saved automaticilly
						if(ch=='\n')//if there is no record than this statement will not execute
						{
					      numberofrecords++;    //1when there is no date in file than it does not execute so value remain 0 as declared
					    }	
				 }
				  fclose(fp);
				if(numberofrecords==0)
				 { 
				    printf("\n********************************************************************************");
				 	printf("\nThere is no RECORD in FILE.\n");
				 	printf("Please Enter Record.\n");
				 	numberofrecords++;   //2when there is no date in file than printf execute and  numberofrecords increment by 1
				 }
				 else
				 {
				 	numberofrecords++;
		         }
				
				 printf("\nHow many RECORDS you want to append: ");
     	         scanf("%d",&record);
     	         printf("\n********************************************************************************");
     	         if(record==0)
     	         { 
     	         	printf("\nYOU have selected 0 record to append so nothing is appended.\n");
     	         	printf("\n********************************************************************************");
     	         	break;//this break statement terminate the switch function because we are inside switch function after terminate we will enter in do while loop
     				}
				 fp=fopen("e:/HAB.txt","a");
				 if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");}
                 for(i=0;i<record;i++)
                 {  
                   if(i==0)//6so this statement execute only 1 time otherwise double Seriel arranged records number or CODE= is produce ,it is specially for when there is no record in file 
                   {
				     printf("\nSeriel Arranged records number or CODE= %d",numberofrecords-1);//3since numberofrecords increment by 1 and subtracting by 1 gives exact Seriel arranged records number or number of records present in file  
				   }	
			    	printf("\n\nEnter %d or any CODE as SERIEL NUMBER to append: ",numberofrecords);//4this line have to show next value so in 2 numberofrecords increment by 1 so it gives the next value 
                 	scanf("%d",&HABITsentence[i].number);     //APPEND NEW DATA
     	            fflush(stdin);
     	            printf("\nenter the SENTENCE to append: ");
                    gets(HABITsentence[i].sentence);
                  	fflush(stdin);
                 	printf("\nenter DONE to append: ");
                   	scanf("%d",&HABITsentence[i].done);
     		        fflush(stdin);
	             	fprintf(fp,"%d %s %d\n",HABITsentence[i].number,HABITsentence[i].sentence,HABITsentence[i].done);
	             	fprintf(tempfile,"%d %s %d\n",HABITsentence[i].number,HABITsentence[i].sentence,HABITsentence[i].done);
	             	 printf("\nDetails of data appended successfully\n");
	             	 printf("%d %s %d\n",HABITsentence[i].number,HABITsentence[i].sentence,HABITsentence[i].done);
	             	 printf("\n********************************************************************************");
					 printf("\nTotal Number of Records OR  Sequence ARRANGED records number or CODE= %d",numberofrecords++);	//5now record is appended so record is increase by 1 so in 4 numberofrecords is increased by 1 which is total number of records so in this statement first value is using than increased   	
                  }
                  printf("\n\n%d Record APPENDED successfully.",record);
                  printf("\nAppended record are:\n",record);
                  rewind(tempfile);
                  for(i=0;i<record;i++)
                  {
                  	 fscanf(tempfile,"%d %s %d\n",&HABITsentence[i].number,HABITsentence[i].sentence,&HABITsentence[i].done);
                  	  printf("%d %s %d\n",HABITsentence[i].number,HABITsentence[i].sentence,HABITsentence[i].done);
				  }
				   printf("\n********************************************************************************");
				   
                   fclose(fp);
				   break;
		case 2:  fp=fopen("e:/hab.txt","r");// int numberofrecords=2;in switch case we cant use declaration statement we have to use only statement
		         if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");}
		         numberofrecords=0;    // while(feof(fp)==0){ch=fgetc(fp);if(ch=='\n'){numberofrecords++;	} } printf("%d",numberofrecords);both give same result*/
		         while(1)
		         {
		            ch=fgetc(fp);
		            if(ch==EOF)
		            {
		            	break;
					}                    //counting number of records
					if(ch=='\n')  //this line will not execute when there is no record in file
					{
					  numberofrecords++;
					}	 
				  }	
				 if(numberofrecords==0)
				 {  printf("\n********************************************************************************");
				 	printf("\nThere is NO RECORD in File.");
				 	printf("\nEnter OPTION 1 to WRITE Record in File.\n");
				 	printf("\n********************************************************************************");
				 	break;//this break statement terminate the switch function
				 }
				 printf("\n********************************************************************************");///
				printf("\nNumber of Record PRESENT in FILE= %d",numberofrecords);
		        fp=fopen("e:/hab.txt","r"); if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
		        printf("\nRecords are:\n");
		        //char str[90];
                ch=fgetc(fp);      //this gives accurate result     DISPLAYING DATA
                while(!feof(fp))
                 {
                	printf("%c",ch);
     	            ch=fgetc(fp);
	             }
	             /*while(fgets(str,90,fp)!=NULL){	printf("\n%s",str); }    one line contain 89 characters,but not 100% accurate result*/
	             fclose(fp);
            	printf("\n********************************************************************************");/////
				  printf("\n********************************************************************************");
				  printf("\nNumber of records in File= %d\n",numberofrecords);
				 fclose(fp);
				 fp=fopen("e:/hab.txt","r");//it is open to counting number of records which is same in file and closed after finished
				 if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				 printf("\nEnter seriel number or CODE of Records to EDIT: ");
				 scanf("%d",&serielnumber);
				 k=0,countnumberofsamerecord=0;
				for(j=0;j<numberofrecords;j++)    
				  {
				  	 fscanf(fp,"%d %s %d\n",&HABITsentence[j].number,HABITsentence[j].sentence,&HABITsentence[j].done);
				  	  if(serielnumber==HABITsentence[j].number)
				  	  {
				  	   arr[k++]=j;//storinging number of same records to delete individually 
				  	   countnumberofsamerecord++;  //counting number of same records which is in file 	
					  }
				  }
				  fclose(fp); //it is closed here
				   if(countnumberofsamerecord>=2)
				   {
					    printf("\n********************************************************************************");
				    	printf("\n %d SAME record of seriel number or CODE: %d FOUND in File.\n",countnumberofsamerecord,serielnumber);
				    	for(i=0;i<countnumberofsamerecord;i++)
				    	{                                             //displaying the number same records
						  store=arr[i]; 
						  printf("\nNumber LINE %d--> %d %s %d ",i+1,HABITsentence[store].number,HABITsentence[store].sentence,HABITsentence[store].done);
						//printf("\nNumber LINE %d--> %d %s %d ",i+1,HABITsentence[arr[i]].number,HABITsentence[arr[i]].sentence,HABITsentence[arr[i]].done);    	
						}
						printf("\n\n********************************************************************************");
				    	printf("\nEnter 0 to STOP Mdifying.");
				    	printf("\nEnter -1 to continue modifying ALL %d SAME record.",countnumberofsamerecord);
				    	printf("\nEnter Number LINE to modify SAME records INDIVIDUALLY: ");
				    	scanf("%d",&toexit);
				    	printf("\n********************************************************************************");
				    	
				    	if(toexit>=1 && toexit<=countnumberofsamerecord)
						  { 
						     anothercountnumberofsamerecordvariable=countnumberofsamerecord;
						  	while(anothercountnumberofsamerecordvariable--)
						  	{
						  	   fp=fopen("e:/hab.txt","r"); 
						       fp2=fopen("e:/first.txt","w");
						  	   linenumberofrecordtodelete=toexit;//using line number is more usefull than using seriel number from the user because if user enter seriel number than seriel number will be same where as number would be different
						  	   found=0;
						  	  for(j=0;j<numberofrecords;j++)
						  	    { 
						  	       fscanf(fp,"%d %s %d\n",&HABITsentence[j].number,HABITsentence[j].sentence,&HABITsentence[j].done);
			                             if(arr[linenumberofrecordtodelete-1]==j)   //to modify 1 record at a time
			                                { 
			                                    valueofi=j;//to display modified record one at a time
			                                   	found=1;
			                                   	printf("\n********************************************************************************");
			                                 	printf("\nDetails of Number LINE--> %d TO MODIFY",toexit);
			                                  	{
			                                  	printf("\n%d %s %d\n",HABITsentence[j].number,HABITsentence[j].sentence,HABITsentence[j].done);	
								                }
							                    printf("\n********************************************************************************");
							                    printf("\nEnter the Modified SERIEL NUMBER: ");          //midifying
							                   	scanf("%d",&HABITsentence[j].number);
							                 	fflush(stdin);
							                 	printf("\nEnter the Modified SENTENCE: ");
							                 	scanf("%s",HABITsentence[j].sentence);
							                	fflush(stdin);
							                   	printf("\nEnter the Modified DONE: ");
							                  	scanf("%d",&HABITsentence[j].done);
							                	fflush(stdin);
							                   	fprintf(fp2,"%d %s %d\n",HABITsentence[j].number,HABITsentence[j].sentence,HABITsentence[j].done);
							                }
							                   else
							                      {
							                	    fprintf(fp2,"%d %s %d\n",HABITsentence[j].number,HABITsentence[j].sentence,HABITsentence[j].done);
					                              }
				                }
				                fclose(fp2);
				                fclose(fp);
				                if(found==0)
				                   {
				     	             printf("\nYou have entered WRONG Number Line.");
				     	             printf("\nNOTHING is Modified.\n");
				     	             printf("\n********************************************************************************");
				                     break;//this statement will terminate while loop function
				                    }
				                    
				               else
				                {   
				                     fp2=fopen("e:/first.txt","r");
				                     if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				                     fp=fopen("e:/hab.txt","w");
				                     if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
						               ch=getc(fp2);
						                  while(1) 
					               	     {                          //copying data to other file
						                       if(ch==EOF)
							                   {
								                   break;  
							                   }
							               fputc(ch,fp);
							               ch=getc(fp2);	
						                 }
										  printf("\n********************************************************************************");
					   	                  printf("\nDetails of Record Modified successfully\n");//we are able to access modified record because we modified using addresss so we able to access valueofi
										  printf("%d %s %d\n",HABITsentence[valueofi].number,HABITsentence[valueofi].sentence,HABITsentence[valueofi].done);         
					            }
					                printf("\nNOW %d SAME record After Modifying in File.\n",anothercountnumberofsamerecordvariable);
					            	for(i=0;i<countnumberofsamerecord;i++)
				                      	{                      //displaying the number same records
						                   store=arr[i]; 
						                     printf("\nNumber LINE %d--> %d %s %d ",i+1,HABITsentence[store].number,HABITsentence[store].sentence,HABITsentence[store].done);
						                  // printf("\nNumber LINE %d--> %d %s %d ",i+1,HABITsentence[arr[i]].number,HABITsentence[arr[i]].sentence,HABITsentence[arr[i]].done);    	
					                   	}
					                   	fclose(fp2);
				                        fclose(fp);
											if(anothercountnumberofsamerecordvariable==0)
								             	{ 
									              printf("\n\nALL SAME Records Midified Successfully\n");
										          break;//this statement will terminate while loop function
									            } 
					                printf("\n\n********************************************************************************"); 
					                printf("\nEnter 0 to STOP modifying.");
					                printf("\nEnter Number LINES to modify SAME records INDIVIDUALLY.");
					                scanf("%d",&toexit);
					                if(toexit==0)
					                {
					                	break;//this statement will terminate while loop function
									}
									else
									{
									   if(toexit>=1 && toexit<=countnumberofsamerecord)
									   {
									   	//continue modifying ALL SAME record 
									   }
									   else
									   {
									   	break;//this statement will terminate while loop function
									   }
									}
					    	}//while bracket inside second if statement
							    if((toexit!=0) && !(toexit>=1 && toexit<=countnumberofsamerecord))//when the user enter wrong number line after entering in while loop then it will terminating  switch function 
								{
									 printf("\n********************************************************************************"); 
									 printf("\nYou have entered WRONG Number line.");
						             printf("\nEXITED from Modifying Records.");
									 printf("\n\n********************************************************************************"); 
									break;//after terminating while loop function this statement will terminate switch function and will enter in do while loop
								 } 
							    else if(toexit==0) 
							      {
							     	break;//after terminating while loop function this statement will terminate switch function and will enter in do while loop
						    	  }
							    else if(found==0)
				                   {
								   break;//after terminating while loop function this statement will terminate switch function and will enter in do while loop
						         	}
						       else if(anothercountnumberofsamerecordvariable==0)
						        	{
							     	break;//after terminating while loop function this statement will terminate switch function and will enter in do while loop
						            }     	
						}//second if bracket         
						else
						{
						      if(toexit==-1)
				    	       { //continue modifying ALL SAME record control will move to rewind statement
						       } 
						      else
						       {
							     if(toexit==0)
								  { 
						           break;//this statement will terminate switch function because we are inside switch function and we will enter in do while loop
						          }
						          else
						          {
						          	printf("\nYou have entered WRONG Number line.");
						          	printf("\nEXITED from Modifying Records.");
						          	printf("\n\n********************************************************************************");
						          	break;//this statement will terminate switch function because we are inside switch function and we will enter in do while loop	
								  }
						       } 
						}
			      
				} //first if bracket
				 fp=fopen("e:/hab.txt","r"); 
				  if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				 fp2=fopen("e:/first.txt","w");
				  if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				found=0;//***we have to give found value inside do while loop not on top of program	or as gobal value bcause if we give than when we first run the code then if seriel number match the HABITsentence[i].number then found value will be updataed but when seriel number did not match the HABITsentence[i].number 
				 for(i=0;i<numberofrecords;i++)//then also value of found will be 1 but we want found value to be 0 because it did not match,this is because when program execute we enter in switch function  so value remain updated if we go out of do while loop than found value would be 0.so if we give found value before for loop
				 {                             //then whenever we want to modify once or twice found value will be 0 when serielnumber did not match HABITsentence[i].number  
				   fscanf(fp,"%d %s %d\n",&HABITsentence[i].number,HABITsentence[i].sentence,&HABITsentence[i].done);
			                  if(serielnumber==HABITsentence[i].number)
			                  {                                         
			                    valueofi=i;//to display modified record
			                  	found=1;
			                  	printf("\n********************************************************************************");
			                  	printf("\nDetails of Record seriel number or CODE: %d TO MODIFY",serielnumber);
			                    printf("\n%d %s %d\n",HABITsentence[i].number,HABITsentence[i].sentence,HABITsentence[i].done);	
							    printf("\n********************************************************************************");
							    printf("\nEnter the Modified SERIEL NUMBER: ");          //midifying
								scanf("%d",&HABITsentence[i].number);
								fflush(stdin);
								printf("\nEnter the Modified SENTENCE: ");
								scanf("%s",HABITsentence[i].sentence);
								fflush(stdin);
								printf("\nEnter the Modified DONE: ");
								scanf("%d",&HABITsentence[i].done);
								fflush(stdin);
								fprintf(fp2,"%d %s %d\n",HABITsentence[i].number,HABITsentence[i].sentence,HABITsentence[i].done);
							  }
							  else
							  {
							  	fprintf(fp2,"%d %s %d\n",HABITsentence[i].number,HABITsentence[i].sentence,HABITsentence[i].done);
					          }
			    }
			       fclose(fp2);
				   fclose(fp);
				   if(found==0)
				     {
				     	printf("\nRecord not found in FILE\n");
				     	printf("\n********************************************************************************");
				     	break;//this statement will terminate switch function
				     }
				  else
				{  
				        fp2=fopen("e:/first.txt","r");
				         if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				        fp=fopen("e:/hab.txt","w");
				         if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
						ch=getc(fp2);
						while(1) 
						{                          //copying data to other file
						    if(ch==EOF)
							{
								break;  
							}
							fputc(ch,fp);
							ch=getc(fp2);	
						} 
						/*ch=fgetc(fp2);
	                    while(ch!=EOF)	  
	                   {                      both works
	                      fputc(ch,fp);
	                      ch=fgetc(fp2);
	                   }*/
	                    printf("\n********************************************************************************");
					   	printf("\nDetails of Record Modified successfully\n");
	                    if(countnumberofsamerecord>=2)
					 {
				       for(j=0;j<countnumberofsamerecord;j++)
				       {
				    	  store=arr[j];
						  printf("%d %s %d\n",HABITsentence[store].number,HABITsentence[store].sentence,HABITsentence[store].done); 
					   }
					    printf("\n********************************************************************************");		
				     }   
					   else
				        {
				          printf("%d %s %d\n",HABITsentence[valueofi].number,HABITsentence[valueofi].sentence,HABITsentence[valueofi].done);
				          printf("\n********************************************************************************");
					    }
				}
				    fclose(fp2);
					fclose(fp); 
			     	break;
		 case 3:fp=fopen("e:/hab.txt","r");// int numberofrecords=2;//in switch case we cant use declaration statement we have to use only statement
		         if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
		         numberofrecords=0;
		         while(1)
		         {
		            ch=fgetc(fp);
		            if(ch==EOF)
		            {                 //counting number of records
		            	break;
					}
					if(ch=='\n')//if there is no record than this statement will not execete
					{
					  numberofrecords++;
					}	
				 }
				 fclose(fp);
				 if(numberofrecords==0)
				 { 
				    printf("\n********************************************************************************");
				 	printf("\nThere is NO RECORD in FILE.");
				 	printf("\nEnter Option 1 to WRITE Record in File.\n");
				 	printf("\n********************************************************************************");
				 }
				 else
				 {
				printf("\n********************************************************************************");
				printf("\nNumber of Record PRESENT in FILE= %d",numberofrecords);
		        fp=fopen("e:/hab.txt","r");
		        printf("\nRecords are:\n");
		        //char str[90];
                ch=fgetc(fp);      //this gives accurate result     DISPLAYING DATA
                while(!feof(fp))
                 {
                	printf("%c",ch);
     	            ch=fgetc(fp);
	             }
	             /*while(fgets(str,90,fp)!=NULL){	printf("\n%s",str); }    one line contain 89 characters,but not 100% accurate result*/
	             fclose(fp);
            	printf("\n********************************************************************************");
                 }
				 break;
		 case 4:fp=fopen("e:/hab.txt","r");// int numberofrecords=2;//in switch case we cant use declaration statement we have to use only statement
		         if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
		         numberofrecords=0;
		         while(1)
		         {
		            ch=fgetc(fp);
		            if(ch==EOF)
		            {                 //counting number of records
		            	break;
					}
					if(ch=='\n')//if there is no record than this statement will not execete
					{
					  numberofrecords++;
					}	
				 }
				 fclose(fp);
				 if(numberofrecords==0)
				 {
				 	printf("\n********************************************************************************");
				 	printf("\nThere is NO RECORD in File.");
				 	printf("\nEnter OPTION 1 to WRITE Record in File.\n");
				 	printf("\n********************************************************************************");
				 	break;
				 }
				 else
				 {
				 	fp=fopen("e:/hab.txt","r");// int numberofrecords=2;//in switch case we cant use declaration statement we have to use only statement
				 	 if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
		         numberofrecords=0;
		         while(1)
		         {
		            ch=fgetc(fp);
		            if(ch==EOF)
		            {                 //counting number of records
		            	break;
					}
					if(ch=='\n')//if there is no record than this statement will not execete
					{
					  numberofrecords++;
					}	
				 }
				 fclose(fp);
				 if(numberofrecords==0)
				 { 
				    printf("\n********************************************************************************");
				 	printf("\nThere is NO RECORD in FILE.");
				 	printf("\nEnter Option 1 to WRITE Record in File.\n");
				 	printf("\n********************************************************************************");
				 }
				 else
				 {
				printf("\n********************************************************************************");
				printf("\nNumber of Record PRESENT in FILE= %d",numberofrecords);
		        fp=fopen("e:/hab.txt","r"); if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
		        printf("\nRecords are:\n");
		        //char str[90];
                ch=fgetc(fp);      //this gives accurate result     DISPLAYING DATA
                while(!feof(fp))
                 {
                	printf("%c",ch);
     	            ch=fgetc(fp);
	             }
	             /*while(fgets(str,90,fp)!=NULL){	printf("\n%s",str); }    one line contain 89 characters,but not 100% accurate result*/
	             fclose(fp);
            	printf("\n********************************************************************************");
                 }
                 printf("\nEnter -1 to STOP Deletion.");
		          printf("\nEnter record number or record CODE to DELETE: ");
			    	scanf("%d",&recordnumbertodelete);
			    	 decrement=valueofdecrementednumberofrecords=numberofrecords;
			while(recordnumbertodelete!=-1)
			{ 
				 fp=fopen("e:/hab.txt","r");
				  if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				 k=0, countnumberofsamerecord=0;
				  
				for(j=0;j<valueofdecrementednumberofrecords;j++)//while running at first initial value of  valueofdecrementednumberofrecords is  total numberofrecords    
				  {
				  	 fscanf(fp,"%d %s %d\n",&HABITsentence[j].number,HABITsentence[j].sentence,&HABITsentence[j].done);
				  	  if(recordnumbertodelete==HABITsentence[j].number)
				  	  {                                                                          //counting number of records which is same in file
				  	   arr[k++]=j;//storinging number of same records to delete individually 
				  	   countnumberofsamerecord++;  	
					  }
				  }
				  fclose(fp);
				   if(countnumberofsamerecord>=2)
					{ 
					    printf("\n********************************************************************************");
				    	printf("\n %d SAME record of seriel number or CODE: %d : Found in File.\n",countnumberofsamerecord,recordnumbertodelete);
				    	for(i=0;i<countnumberofsamerecord;i++)
				    	{                                                       //displaying the number same records
				    	    store=arr[i];
						  printf("\nNumber LINE %d--> %d %s %d ",i+1,HABITsentence[store].number,HABITsentence[store].sentence,HABITsentence[store].done);
						//printf("\nNumber LINE %d--> %d %s %d ",i+1,HABITsentence[arr[i]].number,HABITsentence[arr[i]].sentence,HABITsentence[arr[i]].done);
						}
						printf("\n\n********************************************************************************");
				    	printf("\nEnter 0 to STOP Deletion.");
				    	printf("\nEnter -1 to continue DELETEING ALL %d SAME record. ",countnumberofsamerecord);
				    	printf("\nEnter Number LINE to Delete SAME Record INDIVIDUALLY: ");
				    	scanf("%d",&toexit); 
				    		if(toexit>=1 && toexit<=countnumberofsamerecord)
						  { 
						    anothercountnumberofsamerecordvariable=countnumberofsamerecord;
						  	while(anothercountnumberofsamerecordvariable--)
						  	{ 
						  	
						  	   fp=fopen("e:/hab.txt","r");
							   if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully 
						       fp2=fopen("e:/first.txt","w");
						       if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
						  	   linenumberofrecordtodelete=toexit;//using line number is more usefull than using seriel number from the user because if user enter seriel number than seriel number will be same where as number would be different
						  	  for(j=0;j<decrement;j++)//while running at first initial value of  valueofdecrementednumberofrecords is  total numberofrecords 
						  	    { 
						  	       fscanf(fp,"%d %s %d\n",&HABITsentence[j].number,HABITsentence[j].sentence,&HABITsentence[j].done);
			                             if(arr[linenumberofrecordtodelete-1]==j)   //to delete 1 record at a time
			                                { 
			                                    valueofi=j;//to display deleted record one at a time
			                                 //   --decrement; // never use decrement here because while running it decrese  number of records .we want to decrese when for loop execute completely 
							                }
							                   else
							                      {
							                	    fprintf(fp2,"%d %s %d\n",HABITsentence[j].number,HABITsentence[j].sentence,HABITsentence[j].done);
					                              }
				                }
				                fclose(fp2);
				                fclose(fp);  
				                     fp2=fopen("e:/first.txt","r");
				                      if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				                     fp=fopen("e:/hab.txt","w");
				                      if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
						               ch=getc(fp2);
						                  while(1) 
					               	     {                          //copying data to other file
						                       if(ch==EOF)
							                   {
								                   break;  
							                   }
							               fputc(ch,fp);
							               ch=getc(fp2);	
						                 }
										 fclose(fp2);
				                        fclose(fp);
										  printf("\n********************************************************************************");
					   	                  printf("\nDetails of Deleting Record successfully\n");//we are able to access delete record because i think even deleted record can be access once by using number line like i
										  printf("%d %s %d\n",HABITsentence[valueofi].number,HABITsentence[valueofi].sentence,HABITsentence[valueofi].done);         
					                      printf("\nNOW %d SAME record After Deleting from File.\n",anothercountnumberofsamerecordvariable);
					                        fp=fopen("e:/hab.txt","r");
					                         if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				                            k=0,countnumberofsamerecord=0;
				                             --decrement;//very important to use here
			                            	for(j=0;j<decrement;j++)//while running at first initial value of  valueofdecrementednumberofrecords is  total numberofrecords    
				                              {
				  	                                 fscanf(fp,"%d %s %d\n",&HABITsentence[j].number,HABITsentence[j].sentence,&HABITsentence[j].done);
				  	                                 if(recordnumbertodelete==HABITsentence[j].number)
				  	                                      {                                                                                //counting number of records which is same in file FROM START
				  	                                           arr[k++]=j;//storinging number of same records to delete individually 
				  	                                           countnumberofsamerecord++;  	
					                                      }
				                              }
				                          fclose(fp);
					            	for(i=0;i<countnumberofsamerecord;i++)
				                      	{                      //displaying the number same records
						                   store=arr[i];//If data is not present in HABITsentence[5].number than nothing will be printed
						                     printf("\nNumber LINE %d--> %d %s %d ",i+1,HABITsentence[store].number,HABITsentence[store].sentence,HABITsentence[store].done);
						                  // printf("\nNumber LINE %d--> %d %s %d ",i+1,HABITsentence[arr[i]].number,HABITsentence[arr[i]].sentence,HABITsentence[arr[i]].done);   //both works 	
					                   	}
					                   	
											if(anothercountnumberofsamerecordvariable==0)
								             	{ 
									              printf("\n\nALL SAME Records DELETED Successfully\n");
									              printf("\n\n********************************************************************************"); 
										          break;//this statement will terminate while loop function
									            } 
					                printf("\n\n********************************************************************************"); 
					                printf("\nEnter 0 to STOP Deleting.");
					                printf("\nEnter NUMBER LINES to Delete SAME records INDIVIDUALLY: ");
					                scanf("%d",&toexit);
					                if(toexit==0)
					                {
					                	break;//this statement will terminate while loop function
									}
									else
									{
									   if(toexit>=1 && toexit<=countnumberofsamerecord)
									   {
									   	//continue deleting ALL SAME record 
									   }
									   else
									   {
									   	break;//this statement will terminate while loop function
									   }
									}
					    	}//while bracket inside second if statement
							    	if(anothercountnumberofsamerecordvariable==0)
						        	{
							     	break;//after terminating while loop function this statement will terminate switch function and will enter in do while loop
						            } 
							    else if((toexit!=0) && !(toexit>=1 && toexit<=countnumberofsamerecord))//when the user enter wrong number line after entering in while loop then it will terminating  switch function 
								{
									 printf("\n********************************************************************************"); 
									 printf("\nYou have entered WRONG Number line.");
						             printf("\nEXITED from Deleting Records.");
									 printf("\n\n********************************************************************************"); 
									break;//after terminating while loop function this statement will terminate switch function and will enter in do while loop
								 } 
							    else if(toexit==0) 
							      {
							     	break;//after terminating while loop function this statement will terminate switch function and will enter in do while loop
						    	  }
						}//second if bracket         
						else
						{
						      if(toexit==-1)
				    	       { //continue deleting ALL SAME record control will move to rewind statement
						       } 
						      else
						       {
							     if(toexit==0)
								  { 
						           break;//this statement will terminate switch function because we are inside switch function and we will enter in do while loop
						          }
						          else
						          {
						          	printf("\nYou have entered WRONG Number line.");
						          	printf("\nEXITED from Deleting Records.");
						          	printf("\n\n********************************************************************************");
						          	break;//this statement will terminate switch function because we are inside switch function and we will enter in do while loop	
								  }
						       } 
						}
				    }
				    
				   printf("\n********************************************************************************");
				   printf("\nNumber of  Records  PRESENT  in  file:%d\n",valueofdecrementednumberofrecords);
				   fp=fopen("e:/hab.txt","r"); if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				   fp2=fopen("e:/first.txt","w"); if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				   found=0;//***we have to give found value inside do while loop not on top of program	or as gobal value bcause if we give than when we first run the code then if seriel number match the HABITsentence[i].number then found value will be updataed but when seriel number did not match the HABITsentence[i].number 
				          //then also value of found will be 1 but we want found value to be 0 because it did not match,this is because when program execute we enter in switch function so value remain updated if we go out of do while loop than found value would be 0.
				   for(i=0;i<numberofrecords;i++)	
				    {
				      fscanf(fp,"%d %s %d\n",&HABITsentence[i].number,HABITsentence[i].sentence,&HABITsentence[i].done);
			                  if(recordnumbertodelete==HABITsentence[i].number)
			                  {
			                  	found=1;
			                  	printf("\nDetails of Deleting Record:");//if record number or code is same than it will delete both
			                    printf("\n\n%d %s %d  Deleted successfully\n",HABITsentence[i].number,HABITsentence[i].sentence,HABITsentence[i].done);
			                    --valueofdecrementednumberofrecords;//when data is deleted value of valueofdecrementednumberofrecords variable is decremented by once or twice which is other variable of number of records in file
			                     printf("\nAfter Deleting Records PRESENT in file:%d\n",valueofdecrementednumberofrecords);
			                     printf("\n********************************************************************************");
			                     if(valueofdecrementednumberofrecords==0)
			                        {
			                           printf("\nNumber of records PRESENT in File= %d",valueofdecrementednumberofrecords);
                                       printf("\nThere is NO Record in file\n");	
			                           printf("\nEnter OPTION 1 to WRITE Record in File.\n");
			                           printf("\n********************************************************************************");
			                           break;  //this statement will terminate forloop because we r inside for loop
			                     	}   
						      } 
						      else
						      {
						        fprintf(fp2,"%d %s %d\n",HABITsentence[i].number,HABITsentence[i].sentence,HABITsentence[i].done);	
							  }		   
					}
				   fclose(fp);
				   fclose(fp2);
				   if(found==0)
				   {
				     printf("\nRecord number or record CODE : %d : NOT FOUND in File\n",recordnumbertodelete);
				     printf("\n********************************************************************************");
				   }
				   else
				   {
				   	fp=fopen("e:/hab.txt","w"); if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				    fp2=fopen("e:/first.txt","r"); if(fp==NULL){ printf("\nProblem in openeing File.");printf("\nError No.= %d",errno);perror(" ");} //checking file is opened or not successfully
				      ch=fgetc(fp2);
				      while(1)
				       {                      //copying one file to other
				      	if(ch==EOF)
				        	{
				      		break;
						    }
						 fputc(ch,fp);
						 ch=fgetc(fp2);
					    }
				    }
				    fclose(fp);
				    fclose(fp2);
					if(valueofdecrementednumberofrecords==0)//this statement will encounter  when totalnumber of records become 0 so that it will stop the program and do not execute further
					{
					break;//this statement will terminate while loop and enter in else function than switch function
			    	}
		              numberofrecords=valueofdecrementednumberofrecords;                 
		     	printf("\nEnter -1 to STOP Deletion.");
		     	printf("\nEnter record number or record CODE to DELETE:");
				scanf("%d",&recordnumbertodelete);
			}//while bracket inside else and switch statement
		}//else bracket inside switch statement
	     	break;
        }//switch bracket inside do wile loop	
	 }while(option<5);
     return 0;	
}
