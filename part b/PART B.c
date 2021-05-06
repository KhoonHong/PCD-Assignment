#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#pragma warning (disable: 4996) //to disable the warning when using scanf function//
#define MAX_SIZE 100 //define the max size of an array//

void todayTable(double localCase, double importedCase, double newCases, double totalCases, double totalDeaths, double totalRecovered, double underTreatment, double ratesTotalDeaths, double ratesTotalRecovered, double ratesUnderTreatment, double today); // define base function for today table// 
void currentTable(double previousNewCases, double previousTotalCases, double previousDeathRate, double previousRecoveryRate, double currentNewCases, double currentTotalCases, double currentDeathRate, double currentRecoveryRate, double differenceNewCases, double differenceTotalCases, double differenceDeathRate, double differenceRecoveryRate, double yesterday, double today); //define base function for current table//
void yesterdayTable(double newCases, double totalCases, double totalDeaths, double totalRecovered, double underTreatment, double ratesTotalDeaths, double ratesTotalRecovered, double ratesUnderTreatment, double yesterday);//define base function for yesterday table//

double main(void) 
{
	const double DAY9NEWCASES = 9, DAY9TOTALCASES = 100, DAY9TOTALDEATHS = 2, DAY9TOTALRECOVERED = 10, DAY9UNDERTREATMENT = 88, STARTINGDAY = 10;// define constant variables//
	double previousNewCases = 0, previousTotalCases = 0, previousTotalDeaths = 0, previousTotalRecovered = 0, previousUnderTreatment = 0;
	double currentNewCases, currentLocal, currentImport, currentTotalCases, currentTotalDeaths, currentTotalRecovered, currentUnderTreatment, previousDeathRates, previousRecoveryRates, currentRecoveryRates, currentDeathRates, dayToday = 10, dayYesterday = 9;
	double ratesCurrentTotalDeaths, ratesCurrentTotalRecovered, ratesCurrentUnderTreatment, ratesPreviousTotalDeaths, ratesPreviousTotalRecovered, ratesPreviousUnderTreatment, differenceNewCases, differenceTotalCases, differenceDeathRates, differenceRecoveryRates, totalDaysRecorded, highestNumOfCases, dayHighestNumOfCases, lowestNumOfCases, dayLowestNumOfCases;
	int userDigitPrompt, i, arrayCount = 0, cases[MAX_SIZE], duplicateCases[MAX_SIZE];
	char userYesNoPrompt; 

	ratesPreviousTotalDeaths = (DAY9TOTALDEATHS / DAY9TOTALCASES) * 100; //local declaration calculate the rates of previous day total deaths
	ratesPreviousTotalRecovered = (DAY9TOTALRECOVERED / DAY9TOTALCASES) * 100;  //local declaration calculate the rates of previous day total recovered
	ratesPreviousUnderTreatment = (DAY9UNDERTREATMENT / DAY9TOTALCASES) * 100;  //local declaration calculate the rate of previous day under treatment

	printf("\n###########################################################\n"); //welcome screen
	printf("#                     B A S I C                           #\n");
	printf("#                                                         #\n");
	printf("#            Covid-19 Cases Tracking System               #\n");
	printf("#                                                         #\n");
	printf("#                    Powered By C                         #\n");
	printf("###########################################################\n");
	
	int returnCase = 0;                                //login prompt
	char username[5] = "0000", password[4] = "1111";   //define database default username and password
	while (1) //define while loop equals to true until break statement
	{
		char inputID[MAX_SIZE], inputPassword[MAX_SIZE]; // define two empty strings with index of 100
		returnCase = 0;       //define flag as true false test case
		rewind(stdin);                    //clear all value in variables
		printf("\n\nPlease key in your credentials :   \n"); // prompt users to key in id and password
		
		printf("\n*numbers only, not more than 4 characters*\nUser ID : ");
		scanf("%s", &inputID);                           //user ID input
		
		printf("\n*numbers only, not more than 4 characters*\nPassword : ");
		scanf("%s", &inputPassword);                         //user password input
		
		for (int x = 0; x < 4; x++) //for loop 4 times 
		{
			if (inputID[x] != username[x]) //comparing inputID variable and username variable string character one by one 
											//return true for if condition if inputID character doesn't match test case character
			{
				printf("\n****Access Denied****\n*UserID not found!*\n"); // print access denied if above if condition meets 
				returnCase = 1; //assigning returnCase = 1 to mark user input as false
				break; // break out of for loop
			}
			continue; // continue to loop through for loop
		}
		if (returnCase) // test if condition returnCase is true 
		{
			continue; //return back to initial while loop
		}
		for (int y = 0; y < 4; y++) // for loop 4 times
		{
			if (inputPassword[y] != password[y]) //compairing inputPassword variable and password variable string character one by one
				                           // return true for if statement if inputPassword character doesn't match test case character
			{
				printf("\n****Access Denied****\n*Password Incorrect!*\n"); // print access denied if above if condition meets
				returnCase = 1; //assigning returnCase = 1 to mark user input as false
				break; // break out of for loop
			}
		}
		if (returnCase) //test if condition returnCase is true
		{
			continue; // return back to initial while loop
		}
		printf("\n****Access Granted****\n"); //print access granted since user input passed all test cases
		break; // break out of while loop
	}

	time_t start, end; // define after user login starting time and ending time
	start = time(NULL); // assign current time to start variable

	printf("\nWelcome back , %s!", username);

	printf("\n\n------------------------ COVID-19 CASES Tracking System --------------------------\n"); // design (title)
	
	while (1) //define while loop equals to true until break statement
	{
		yesterdayTable(DAY9NEWCASES, DAY9TOTALCASES, DAY9TOTALDEATHS, DAY9TOTALRECOVERED, DAY9UNDERTREATMENT, ratesPreviousTotalDeaths, ratesPreviousTotalRecovered, ratesPreviousUnderTreatment, dayYesterday);
		
		printf("\nDay %3.0lf", dayToday); //prints out today's day no.
		printf("\n========\n");  // printing out equal sign as dividing line
		printf("Key in Today's data:"); // prompting users to key in today's data
		
		printf("\n       No. of new local cases    : "); // prompt user to key in local case no.
		scanf("%lf", &currentLocal); // take current localCase cases from user input
		
		printf("       No. of new imported cases : "); // prompts users to input imported cases
		scanf("%lf", &currentImport); // take current imported cases value from user input 
		
		currentNewCases = currentLocal + currentImport; //local declaration calculate current day new cases 

		printf("\nTotal no. of new cases = %3.0lf     ", currentNewCases); //displaying the total no. of new cases

		if (currentNewCases > DAY9NEWCASES) { //if condition returns true if current day local cases is higher than previous day local case
			printf("( Increased by %2.0lf from yesterday.)", currentNewCases - DAY9NEWCASES); //prints out increase by how much compared to yesterday 
		}
		else if (currentNewCases < DAY9NEWCASES) { // if condition returns true if current day local cases is lower than previous day local case
			printf("( Decreased by %2.0lf from yesterday.)", DAY9NEWCASES - currentNewCases); // prints out decrease by how much compared to yesterday
		}
		else { // if both conditions above returns false then will run else statement
			printf("\n\nNo change from yesterday\n\n"); // prints out no changes compared to yesterday
		}
		printf("\nNo. of deaths          =  "); //prompting users to key in number of deaths
		scanf("%lf", &currentTotalDeaths); //take current day total deaths value from user input
		printf("No. recovered          =  "); // prompting users to key in number of recoveries
		scanf("%lf", &currentTotalRecovered); // take current day total recovered value from user input
		cases[arrayCount] = DAY9NEWCASES; duplicateCases[arrayCount] = DAY9NEWCASES; // local declaration assign DAY9NEWCASES to both arrays
		currentTotalCases = DAY9TOTALCASES + currentNewCases;// local declaration calculate current day total cases
		currentTotalDeaths += DAY9TOTALDEATHS;  // local declaration calculate current day total deaths
		currentTotalRecovered += DAY9TOTALRECOVERED; // local declaration calculate current day total recovered
		currentUnderTreatment = currentTotalCases - currentTotalDeaths - currentTotalRecovered; // local declaration calculate current day under treatment
		ratesCurrentTotalDeaths = (currentTotalDeaths / currentTotalCases) * 100; // local declaration calculate rates of current day total deaths 
		ratesCurrentTotalRecovered = (currentTotalRecovered / currentTotalCases) * 100; // local declaration calculate rates of current day total recovered
		ratesCurrentUnderTreatment = (currentUnderTreatment / currentTotalCases) * 100; // local declaration calculate rates of current day under treatment
		previousDeathRates = (DAY9TOTALDEATHS / DAY9TOTALCASES) * 100;  // local declaration calculate previous day death rates
		previousRecoveryRates = (DAY9TOTALRECOVERED / DAY9TOTALCASES) * 100; // local declaration calculate previous day recovery rates
		currentDeathRates = (currentTotalDeaths / currentTotalCases) * 100;  // local declaration calculate current day death rates
		currentRecoveryRates = (currentTotalRecovered / currentTotalCases) * 100; // local declaration calculate current day recovery rates
		differenceNewCases = currentNewCases - DAY9NEWCASES; // local declaration calculate difference of new cases
		differenceTotalCases = currentTotalCases - DAY9TOTALCASES; // local declaration calculate difference of total cases 
		differenceDeathRates = currentDeathRates - previousDeathRates; // local declaration calculate difference of death rates
		differenceRecoveryRates = currentRecoveryRates - previousRecoveryRates; // local declaration calculate difference of recovery rates

		printf("\n1 - Daily Summary Report,  2 - Daily Comparative Report"); //displaying options for users to choose from
		printf("\nWhat type of Report would you like to view (Choose 1 or 2)? "); // asking user to input '1' or '2' based on the choices stated above
		scanf("%d", &userDigitPrompt); //takes '1' or '2' as input depending on user's preference

		switch (userDigitPrompt) //switch case using userDigitPrompt as testcase variable
		{
		case 1: //if userDigitPrompt equals to '1'
			todayTable(currentLocal, currentImport, currentNewCases, currentTotalCases, currentTotalDeaths, currentTotalRecovered, currentUnderTreatment, ratesCurrentTotalDeaths, ratesCurrentTotalRecovered, ratesCurrentUnderTreatment, dayToday);
			break; // break out of switch statement in order not to run the remaining switch cases below
		case 2: // if userDigitPrompt equals to '2'
			currentTable(previousNewCases, previousTotalCases, previousDeathRates, previousRecoveryRates, currentNewCases, currentTotalCases, currentDeathRates, currentRecoveryRates, differenceNewCases, differenceTotalCases, differenceDeathRates, differenceRecoveryRates, dayYesterday, dayToday);
			break;  // break out of switch statement in order not to run the remaining switch cases below
		default: // if all above switch case statement doesn't match, run default case as true
			printf("Please try again later"); // displays out a string of text prompting user to try again later
		}

		printf("\n-------------------------End of Day %2.0lf reporting-------------------------\n\n", dayToday); // displaying the current day no.
		printf("Continue to next day (Y = yes)? "); // prompting the user to input either 'y' or 'n'
		scanf("%c", &userYesNoPrompt); // take 'y' or 'n' from user
		
		if (userYesNoPrompt == 'n') { // if user input equals to 'n' returns true
			break; //breaks out of while loop
		}
		
		dayToday++; dayYesterday++; arrayCount++; // increment for current day, previous day and array index count by +1
		
		//assigning all current day variable data to previous day variable before looping to next day 
		previousNewCases = currentNewCases; previousTotalCases = currentTotalCases; previousTotalDeaths = currentTotalDeaths; previousTotalRecovered = currentTotalRecovered; previousUnderTreatment = currentUnderTreatment; ratesPreviousTotalDeaths = ratesCurrentTotalDeaths; ratesPreviousTotalRecovered = ratesCurrentTotalRecovered; ratesPreviousUnderTreatment = ratesCurrentUnderTreatment;
		
		while (1)  //define while loop equals to true until break statement
		{
			printf("\nDay %3.0lf", dayToday); //prints out today's day no.
			printf("\n========\n");  // printing out equal sign as dividing line
			printf("Key in Today's data:");  // prompting users to key in today's data
			
			printf("\n       No. of new local cases    : ");  // prompt user to key in local case no.
			scanf("%lf", &currentLocal); // take current local cases from user
			
			printf("       No. of new imported cases : ");  //prompt user to key in imported case no.
			scanf("%lf", &currentImport); // take current imported cases from user
			
			currentNewCases = currentLocal + currentImport; //local declaration calculate current day new cases
			
			printf("\nTotal no. of new cases = %3.0lf     ", currentNewCases);  //displays out the total number of new cases
			
			if (currentNewCases > previousNewCases) {                    // if current day new cases is higher than previous day new cases, return true for if statement
				printf("( Increased by %2.0lf from yesterday.)", currentNewCases - previousNewCases); //displays out increased by how much compared to yesterday
			}
			else if (currentNewCases < previousNewCases) { // if current day new cases is lower than previous day new cases, return true for else if statement
				printf("( Decreased by %2.0lf from yesterday.)", previousNewCases - currentNewCases); // displays out decreased by how much compared to yesterday
			}
			else { // if if and else if statement are false, else statement will be initiated accordingly  
				printf("\n\nNo change from yesterday\n\n"); //displays out no changes compared to yesterday
			}
			
			printf("\nNo. of deaths          =  "); // prompt users to input no. of deaths
			scanf("%lf", &currentTotalDeaths);   //take current no. of death from user
			
			printf("No. recovered          =  "); // prompt users to input no. of recovered
			scanf("%lf", &currentTotalRecovered); // take current no. of recovered patients from user

			//formula 

			ratesPreviousTotalDeaths = (previousTotalDeaths / previousTotalCases) * 100;     // local declaration calculate the rates of previosu day total deaths
			ratesPreviousTotalRecovered = (previousTotalRecovered / previousTotalCases) * 100;   //local declaration calculate the rates of previous day total recovered
			ratesPreviousUnderTreatment = (previousUnderTreatment / previousTotalCases) * 100; //local declaration calculate the rates of previous day under treatment
			cases[arrayCount] = previousNewCases; duplicateCases[arrayCount] = previousNewCases;  // local assigmnent assigning previous day new cases to cases[arraycount] and duiplicatecases[arraycount] array
			currentTotalCases = previousTotalCases + currentNewCases;  //local declaration calculate current day total cases
			currentTotalDeaths += previousTotalDeaths; // local declaration calculate current day total deaths
			currentTotalRecovered += previousTotalRecovered;  // local declaration calculate current day total recovered
			currentUnderTreatment = currentTotalCases - currentTotalDeaths - currentTotalRecovered;  // local declaration calculate current day under treatment
			ratesCurrentTotalDeaths = (currentTotalDeaths / currentTotalCases) * 100;  //local declaration calculate the rates of current day total deaths
			ratesCurrentTotalRecovered = (currentTotalRecovered / currentTotalCases) * 100;  //local declaration calculate the rates of current day total recovered
			ratesCurrentUnderTreatment = (currentUnderTreatment / currentTotalCases) * 100;  //local declaration calculate the rates of current day under treatment
			previousDeathRates = (previousTotalDeaths / previousTotalCases) * 100;  //local declaration calculate the rates of previous day death rates
			previousRecoveryRates = (previousTotalRecovered / previousTotalCases) * 100;  //local declaration calculate previous day recovery rates
			currentDeathRates = (currentTotalDeaths / currentTotalCases) * 100;  //local declaration calculate current day death rates
			currentRecoveryRates = (currentTotalRecovered / currentTotalCases) * 100;  //local declaration calculate current day recovery rates
			differenceNewCases = currentNewCases - previousNewCases;  // local declaration calculate the difference of new cases 
			differenceTotalCases = currentTotalCases - previousTotalCases;  //local declaration calculate the difference of total cases
			differenceDeathRates = currentDeathRates - previousDeathRates;  // local declaration calculate the difference of death rates
			differenceRecoveryRates = currentRecoveryRates - previousRecoveryRates; // local declaration calculate the difference of recovery rates

			printf("\n1 - Daily Summary Report,  2 - Daily Comparative Report");  //displaying the choices for users to choose from
			printf("\nWhat type of Report would you like to view (Choose 1 or 2)? ");
			scanf("%d", &userDigitPrompt);                 // let users to pick either choice which is 1 or 2// 

			switch (userDigitPrompt)// switch case depends on previous 1 or 2 input value//
			{
			case 1:  //if userDigitPrompt equals to '1'
				todayTable(currentLocal, currentImport, currentNewCases, currentTotalCases, currentTotalDeaths, currentTotalRecovered, currentUnderTreatment, ratesCurrentTotalDeaths, ratesCurrentTotalRecovered, ratesCurrentUnderTreatment, dayToday);
				break; // break out of switch statement in order not to run the remaining switch cases below
			case 2:  // if userDigitPrompt equals to '2'
				currentTable(previousNewCases, previousTotalCases, previousDeathRates, previousRecoveryRates, currentNewCases, currentTotalCases, currentDeathRates, currentRecoveryRates, differenceNewCases, differenceTotalCases, differenceDeathRates, differenceRecoveryRates, dayYesterday, dayToday);
				break;  // break out of switch statement in order not to run the remaining switch cases below
			default:  // if all above switch case statement doesn't match, run default case as true
				printf("Please try again later"); // displays out a string of text prompting user to try again later
			}

			printf("\n-------------------------End of Day %2.0lf reporting-------------------------\n\n", dayToday); //printing out the current day no.
			
			printf("Continue to next day (Y = yes)? "); // prompting user to input either 'y' or 'n' 
			scanf("%c", &userYesNoPrompt); // takes input y or n from user//
			
			if (userYesNoPrompt == 'n') { // if else statement depends on above input value//
				break; // break out of while loop if above condition returns true
			}
			
			dayToday++; dayYesterday++; arrayCount++; // increment by +1 for those three variable namely dayToday, dayYesterday, and arrayCount
			
													  // assigning all current day variable data to previous day variable before looping to next day 
			previousNewCases = currentNewCases; previousTotalCases = currentTotalCases; previousTotalDeaths = currentTotalDeaths; previousTotalRecovered = currentTotalRecovered; previousUnderTreatment = currentUnderTreatment; ratesPreviousTotalDeaths = ratesCurrentTotalDeaths; ratesPreviousTotalRecovered = ratesCurrentTotalRecovered; ratesPreviousUnderTreatment = ratesCurrentUnderTreatment;
			continue; // continuing the while loop
		}
		if (userYesNoPrompt == 'n') { // check if userYesNoPrompt equals to 'n' , if statement returns true if condition meets 
			break; // breaks out of while loop
		}
	}

	totalDaysRecorded = (dayToday - STARTINGDAY) + 1; //local declaration calculate total days that the user input
	
	for (i = 1; i < (arrayCount + 1); ++i) {  //finding the largest array element//
		if (cases[0] < cases[i])  //check if cases[0] is smaller than cases[i]
			cases[0] = cases[i];  //if above if case return true, then assign cases[0] equals to cases[i]
	}
	
	highestNumOfCases = cases[0]; //local assignment assigning cases[0] to highest number of cases variable
	
	for (i = 0; i < (arrayCount + 1); ++i) { // finding which day is the highest no of day//
		if (highestNumOfCases == duplicateCases[i]) //return true if highest no. of cases equals to test case sample (dulplicateCases[i])
			dayHighestNumOfCases = i + 9;  // if above if case return true, calculate the day of highest number of cases
	}
	
	for (i = 1; i < (arrayCount + 1); ++i) {  //finding the smallest array element//
		if (cases[0] > cases[i])  //check if cases[0] is bigger than cases[i]
			cases[0] = cases[i];  //if above if case return true, then assign cases[0] equals to cases[i]
	}
	
	lowestNumOfCases = cases[0];  //local assignment assignment cases[0] to lowest number of cases variable 
	
	for (i = 0; i < (arrayCount + 1); ++i) {  // finding which day is the lowest no. of day//
		if (lowestNumOfCases == duplicateCases[i])  //return true if lowest no. of cases equals to test case sample (dulplicateCases[i])
			dayLowestNumOfCases = i + 9;  // if above if case return true, calculate the day of lowest number of cases
	}
	
	// summary or finalize the input given//
	
	printf("\n\n             TOTAL Days recorded       = %3.0lf days (Day %3.0lf to Day %3.0lf)", totalDaysRecorded, STARTINGDAY, dayToday);  //displays out the total days recorded by the program(based on how many days the user input)
	printf("\n             HIGHEST number of cases   =  %3.0lf, occuring on Day %3.0lf", highestNumOfCases, dayHighestNumOfCases); // displays out the highest number of cases to the user, and which day did that occur
	printf("\n             LOWEST number of cases    =  %3.0lf, occuring on Day %3.0lf", lowestNumOfCases, dayLowestNumOfCases);  // displays out the lowest number of cases to the user, and which day did that occur
	
	printf("\n\nBye and Thank You!!\n\n"); //prints thank you msg to the user
	
	end = time(NULL); //assign current time to end variable
	
	printf("\n\n\nUser ID --- %s 's Total clock-in time :  %.2f seconds\n\n", username, difftime(end, start)); //outputs total user's clock in time/login time
	
	system("pause"); //pausing the program, prompt user to press any key to continue
}

//function 1//
//for current day daily summary report table 
void todayTable(double localCase, double importedCase, double newCases, double totalCases, double totalDeaths, double totalRecovered, double underTreatment, double ratesTotalDeaths, double ratesTotalRecovered, double ratesUnderTreatment, double today)
{
	printf("\nDay %3.0lf                       DAILY SUMMARY REPORT                              ", today);
	printf("\n+---------------+-------------++------------+-----------------+-----------------+\n");
	printf("|       Today's |  Total      ||  Total     |  Total          |  Under          |\n");
	printf("|       cases   |  cases      ||  deaths    |  recovered      |  treatment      |\n");
	printf("+---------------+-------------++------------+-----------------+-----------------+\n");
	printf("|local   %4.0lf   |             ||            |                 |                 |\n", localCase);
	printf("|imported%4.0lf   |             ||            |                 |                 |\n", importedCase);
	printf("|          %4.0lf |    %4.0lf     ||   %4.0lf     |     %4.0lf        |     %4.0lf        |\n", newCases, totalCases, totalDeaths, totalRecovered, underTreatment);
	printf("+-----------------------------++------------+-----------------+-----------------+\n");
	printf("                              ||  %4.1lf %%    |    %4.1lf %%       |    %4.1lf %%       |\n", ratesTotalDeaths, ratesTotalRecovered, ratesUnderTreatment);
	printf("                              ++------------+-----------------+-----------------+\n");
	rewind(stdin);
}
//function 2//
//for current day daily comparative report table
void currentTable(double previousNewCases, double previousTotalCases, double previousDeathRate, double previousRecoveryRate, double currentNewCases, double currentTotalCases, double currentDeathRate, double currentRecoveryRate, double differenceNewCases, double differenceTotalCases, double differenceDeathRate, double differenceRecoveryRate, double yesterday, double today)
{
	char positive = '+';
	char negative = '-';
	char nc = ' ', dr = ' ', rr = ' ';
	printf("\n                             DAILY COMPARATIVE REPORT                         \n");
	if (previousNewCases < currentNewCases) {
		nc = positive;
	}
	if (previousDeathRate < currentDeathRate) {
		dr = positive;
	}
	if (previousRecoveryRate < currentRecoveryRate) {
		rr = positive;
	}
	printf("                         +---------------+------------------++------------------+\n");
	printf("                         |  YESTERDAY    |     TODAY        ||   DIFFERENCE     |\n");
	printf("                         |    Day %2.0lf     |      Day %2.0lf      ||                  |\n", yesterday, today);
	printf("+------------------------+---------------+------------------++------------------+\n");
	printf("|New Cases               |     %4.0lf      |       %4.0lf       ||     [%c %3.0lf]      |\n", previousNewCases, currentNewCases, nc, differenceNewCases);
	printf("+------------------------+---------------+------------------++------------------+\n");
	printf("|Total Cases             |     %4.0lf      |       %4.0lf       ||     [%c %3.0lf]      |\n", previousTotalCases, currentTotalCases, positive, differenceTotalCases);
	printf("+------------------------+---------------+------------------++------------------+\n");
	printf("|Death Rate              |     %4.1lf %%    |      %4.1lf %%      ||     [%c %3.1lf %%]    |\n", previousDeathRate, currentDeathRate, dr, differenceDeathRate);
	printf("+------------------------+---------------+------------------++------------------+\n");
	printf("|Recovery Rates          |     %4.1lf %%    |       %4.1lf %%     ||   [%c %4.1lf %%]     |\n", previousRecoveryRate, currentRecoveryRate, rr, differenceRecoveryRate);
	printf("+------------------------+---------------+------------------++------------------+\n");
	rewind(stdin);
}
//function 3//
//for previous day summary report table 
void yesterdayTable(double newCases, double totalCases, double totalDeaths, double totalRecovered, double underTreatment, double ratesTotalDeaths, double ratesTotalRecovered, double ratesUnderTreatment, double yesterday)
{
	printf("\n      Yesterday's Totals - (Day %2.0lf):", yesterday);
	printf("\n+---------------+-------------++------------+-----------------+-----------------+\n");
	printf("|   Yesterday's |   Total     || Total      | Total           | Under           |\n");
	printf("|   cases       |   cases     || deaths     | recovered       | treatment       |\n");
	printf("+---------------+-------------++------------+-----------------+-----------------+\n");
	printf("|        %4.0lf   |    %4.0lf     ||   %4.0lf     |     %4.0lf        |     %4.0lf        |\n", newCases, totalCases, totalDeaths, totalRecovered, underTreatment);
	printf("+-------------------------------------------+-----------------+-----------------+\n");
	printf("                              ||  %4.1lf %%    |    %4.1lf %%       |    %4.1lf %%       |\n", ratesTotalDeaths, ratesTotalRecovered, ratesUnderTreatment);
	printf("                              ++------------------------------------------------+\n");
	rewind(stdin);
}

/*
###########################################################
#                     B A S I C                           #
#                                                         #
#            Covid-19 Cases Tracking System               #
#                                                         #
#                    Powered By C                         #
###########################################################


Please key in your credentials :

*numbers only, not more than 4 characters*
User ID : 1231

*numbers only, not more than 4 characters*
Password : 1568

****Access Denied****
*UserID not found!*


Please key in your credentials :

*numbers only, not more than 4 characters*
User ID : 0000

*numbers only, not more than 4 characters*
Password : 1111

****Access Granted****

Welcome back, 0000!

------------------------ COVID-19 CASES Tracking System --------------------------

      Yesterday's Totals - (Day  9):
+---------------+-------------++------------+-----------------+-----------------+
|   Yesterday's |   Total     || Total      | Total           | Under           |
|   cases       |   cases     || deaths     | recovered       | treatment       |
+---------------+-------------++------------+-----------------+-----------------+
|           9   |     100     ||      2     |        10       |       88        |
+-------------------------------------------+-----------------+-----------------+
                              ||   2.0 %    |    10.0 %       |    88.0 %       |
                              ++------------------------------------------------+

Day  10
========
Key in Today's data:
       No. of new local cases    : 6
       No. of new imported cases : 4

Total no. of new cases =  10     ( Increased by  1 from yesterday.)
No. of deaths          =  5
No. recovered          =  15

1 - Daily Summary Report,  2 - Daily Comparative Report
What type of Report would you like to view (Choose 1 or 2)? 1

Day  10                       DAILY SUMMARY REPORT
+---------------+-------------++------------+-----------------+-----------------+
|       Today's |  Total      ||  Total     |  Total          |  Under          |
|       cases   |  cases      ||  deaths    |  recovered      |  treatment      |
+---------------+-------------++------------+-----------------+-----------------+
|local      6   |             ||            |                 |                 |
|imported   4   |             ||            |                 |                 |
|            10 |     110     ||      7     |        25       |       78        |
+-----------------------------++------------+-----------------+-----------------+
                              ||   6.4 %    |    22.7 %       |    70.9 %       |
                              ++------------+-----------------+-----------------+

-------------------------End of Day 10 reporting-------------------------

Continue to next day (Y = yes)? y

Day  11
========
Key in Today's data:
       No. of new local cases    : 3
       No. of new imported cases : 2

Total no. of new cases =   5     ( Decreased by  5 from yesterday.)
No. of deaths          =  1
No. recovered          =  1

1 - Daily Summary Report,  2 - Daily Comparative Report
What type of Report would you like to view (Choose 1 or 2)? 2

                             DAILY COMPARATIVE REPORT
                         +---------------+------------------++------------------+
                         |  YESTERDAY    |     TODAY        ||   DIFFERENCE     |
                         |    Day 10     |      Day 11      ||                  |
+------------------------+---------------+------------------++------------------+
|New Cases               |       10      |          5       ||    [[   -5]]     |
+------------------------+---------------+------------------++------------------+
|Total Cases             |      110      |        115       ||    [[+   5]]     |
+------------------------+---------------+------------------++------------------+
|Death Rate              |      6.4 %    |       7.0 %      ||    [[+ 0.6 %]]   |
+------------------------+---------------+------------------++------------------+
|Recovery Rates          |     22.7 %    |       22.6 %     ||   [[  -0.1 %]]   |
+------------------------+---------------+------------------++------------------+

-------------------------End of Day 11 reporting-------------------------

Continue to next day (Y = yes)? y

Day  12
========
Key in Today's data:
       No. of new local cases    : 10
       No. of new imported cases : 40

Total no. of new cases =  50     ( Increased by 45 from yesterday.)
No. of deaths          =  10
No. recovered          =  10

1 - Daily Summary Report,  2 - Daily Comparative Report
What type of Report would you like to view (Choose 1 or 2)? 1

Day  12                       DAILY SUMMARY REPORT
+---------------+-------------++------------+-----------------+-----------------+
|       Today's |  Total      ||  Total     |  Total          |  Under          |
|       cases   |  cases      ||  deaths    |  recovered      |  treatment      |
+---------------+-------------++------------+-----------------+-----------------+
|local     10   |             ||            |                 |                 |
|imported  40   |             ||            |                 |                 |
|            50 |     165     ||     18     |        36       |      111        |
+-----------------------------++------------+-----------------+-----------------+
                              ||  10.9 %    |    21.8 %       |    67.3 %       |
                              ++------------+-----------------+-----------------+

-------------------------End of Day 12 reporting-------------------------

Continue to next day (Y = yes)? y

Day  13
========
Key in Today's data:
       No. of new local cases    : 8
       No. of new imported cases : 12

Total no. of new cases =  20     ( Decreased by 30 from yesterday.)
No. of deaths          =  2
No. recovered          =  100

1 - Daily Summary Report,  2 - Daily Comparative Report
What type of Report would you like to view (Choose 1 or 2)? 2

                             DAILY COMPARATIVE REPORT
                         +---------------+------------------++------------------+
                         |  YESTERDAY    |     TODAY        ||   DIFFERENCE     |
                         |    Day 12     |      Day 13      ||                  |
+------------------------+---------------+------------------++------------------+
|New Cases               |       50      |         20       ||    [[  -30]]     |
+------------------------+---------------+------------------++------------------+
|Total Cases             |      165      |        185       ||    [[+  20]]     |
+------------------------+---------------+------------------++------------------+
|Death Rate              |     10.9 %    |      10.8 %      ||    [[  -0.1 %]]   |
+------------------------+---------------+------------------++------------------+
|Recovery Rates          |     21.8 %    |       73.5 %     ||   [[+ 51.7 %]]   |
+------------------------+---------------+------------------++------------------+

-------------------------End of Day 13 reporting-------------------------

Continue to next day (Y = yes)? n


             TOTAL Days recorded       =   4 days (Day  10 to Day  13)
             HIGHEST number of cases   =   50, occuring on Day  12
             LOWEST number of cases    =    5, occuring on Day  11

Bye and Thank You!!

Press any key to continue . . .



User ID --- 0000 's Total clock-in time :  120.00 seconds

Press any key to continue . . .
*/