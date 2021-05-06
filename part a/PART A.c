#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#pragma warning (disable: 4996) //to disable the warning when using scanf function//
#define MAX_SIZE 100 //define the max size of an array//
void todayTable(double localCase, double importedCase, double newCases, double totalCases, double totalDeaths, double totalRecovered, double underTreatment, double ratesTotalDeaths, double ratesTotalRecovered, double ratesUnderTreatment, double today); // define base function for today table// 
void currentTable(double previousNewCases, double previousTotalCases, double previousDeathRate, double previousRecoveryRate, double currentNewCases, double currentTotalCases, double currentDeathRate, double currentRecoveryRate, double differenceNewCases, double differenceTotalCases, double differenceDeathRate, double differenceRecoveryRate, double yesterday, double today); //define base function for current table//
void yesterdayTable(double newCases, double totalCases, double totalDeaths, double totalRecovered, double underTreatment, double ratesTotalDeaths, double ratesTotalRecovered, double ratesUnderTreatment, double yesterday);//define base function for yesterday table//

double main()
{
	const double DAY9NEWCASES = 9, DAY9TOTALCASES = 100, DAY9TOTALDEATHS = 2, DAY9TOTALRECOVERED = 10, DAY9UNDERTREATMENT = 88;// define constant variables//
	double previousNewCases = 0, previousTotalCases = 0, previousTotalDeaths = 0, previousTotalRecovered = 0, previousUnderTreatment = 0;
	double currentNewCases, currentLocal, currentImport, currentTotalCases, currentTotalDeaths, currentTotalRecovered, currentUnderTreatment, previousDeathRates, previousRecoveryRates, currentRecoveryRates, currentDeathRates, dayToday = 10, dayYesterday = 9;
	double ratesCurrentTotalDeaths, ratesCurrentTotalRecovered, ratesCurrentUnderTreatment, ratesPreviousTotalDeaths, ratesPreviousTotalRecovered, ratesPreviousUnderTreatment, differenceNewCases, differenceTotalCases, differenceDeathRates, differenceRecoveryRates, totalDaysRecorded, highestNumOfCases, dayHighestNumOfCases, lowestNumOfCases, dayLowestNumOfCases;
	int userDigitPrompt, i; char userYesNoPrompt; int arrayCount = 0; //choice//
	int cases[MAX_SIZE], duplicateCases[MAX_SIZE];
	const double STARTINGDAY = 10;
	

	ratesPreviousTotalDeaths = (DAY9TOTALDEATHS / DAY9TOTALCASES) * 100;
	ratesPreviousTotalRecovered = (DAY9TOTALRECOVERED / DAY9TOTALCASES) * 100;
	ratesPreviousUnderTreatment = (DAY9UNDERTREATMENT / DAY9TOTALCASES) * 100;

	printf("\n###########################################################\n");
	printf("#                     B A S I C                           #\n");
	printf("#                                                         #\n");
	printf("#            Covid-19 Cases Tracking System               #\n");
	printf("#                                                         #\n");
	printf("#                    Powered By C                         #\n");
	printf("###########################################################\n");

	printf("\n\n------------------------ COVID-19 CASES Tracking System --------------------------\n");
	while (1)
	{
		yesterdayTable(DAY9NEWCASES, DAY9TOTALCASES, DAY9TOTALDEATHS, DAY9TOTALRECOVERED, DAY9UNDERTREATMENT, ratesPreviousTotalDeaths, ratesPreviousTotalRecovered, ratesPreviousUnderTreatment, dayYesterday);
		printf("\nDay %3.0lf", dayToday);
		printf("\n========\n");
		printf("Key in Today's data:");
		printf("\n       No. of new local cases    : ");
		scanf("%lf", &currentLocal); // take current localCase cases from user//
		printf("       No. of new imported cases : ");
		scanf("%lf", &currentImport); // take current importedCase cases from user//
		currentNewCases = currentLocal + currentImport;
		printf("\nTotal no. of new cases = %3.0lf     ", currentNewCases);
		if (currentNewCases > previousNewCases) {
			printf("( Increased by %2.0lf from yesterday.)", currentNewCases - DAY9NEWCASES);
		}
		else if (currentNewCases < previousNewCases) {
			printf("( Decreased by %2.0lf from yesterday.)", DAY9NEWCASES - currentNewCases);
		}
		else {
			printf("\n\nNo change from yesterday\n\n");
		}
		printf("\nNo. of deaths          =  ");
		scanf("%lf", &currentTotalDeaths);
		printf("No. recovered          =  ");
		scanf("%lf", &currentTotalRecovered);
		cases[arrayCount] = DAY9NEWCASES; duplicateCases[arrayCount] = DAY9NEWCASES;
		currentTotalCases = DAY9TOTALCASES + currentNewCases;
		currentTotalDeaths += DAY9TOTALDEATHS;
		currentTotalRecovered += DAY9TOTALRECOVERED;
		currentUnderTreatment = currentTotalCases - currentTotalDeaths - currentTotalRecovered;
		ratesCurrentTotalDeaths = (currentTotalDeaths / currentTotalCases) * 100;
		ratesCurrentTotalRecovered = (currentTotalRecovered / currentTotalCases) * 100;
		ratesCurrentUnderTreatment = (currentUnderTreatment / currentTotalCases) * 100;
		previousDeathRates = (DAY9TOTALDEATHS / DAY9TOTALCASES) * 100;
		previousRecoveryRates = (DAY9TOTALRECOVERED / DAY9TOTALCASES) * 100;
		currentDeathRates = (currentTotalDeaths / currentTotalCases) * 100;
		currentRecoveryRates = (currentTotalRecovered / currentTotalCases) * 100;
		differenceNewCases = currentNewCases - DAY9NEWCASES;
		differenceTotalCases = currentTotalCases - DAY9TOTALCASES;
		differenceDeathRates = currentDeathRates - previousDeathRates;
		differenceRecoveryRates = currentRecoveryRates - previousRecoveryRates;

		printf("\n1 - Daily Summary Report,  2 - Daily Comparative Report");
		printf("\nWhat type of Report would you like to view (Choose 1 or 2)? ");
		scanf("%d", &userDigitPrompt);

		switch (userDigitPrompt)
		{
		case 1:
			todayTable(currentLocal, currentImport, currentNewCases, currentTotalCases, currentTotalDeaths, currentTotalRecovered, currentUnderTreatment, ratesCurrentTotalDeaths, ratesCurrentTotalRecovered, ratesCurrentUnderTreatment, dayToday);
			break;
		case 2:
			currentTable(previousNewCases, previousTotalCases, previousDeathRates, previousRecoveryRates, currentNewCases, currentTotalCases, currentDeathRates, currentRecoveryRates, differenceNewCases, differenceTotalCases, differenceDeathRates, differenceRecoveryRates, dayYesterday, dayToday);
			break;
		default:
			printf("Please try again later");
		}

		printf("\n-------------------------End of Day %2.0lf reporting-------------------------\n\n", dayToday);
		printf("Continue to next day (Y = yes)? ");
		scanf("%c", &userYesNoPrompt);
		if (userYesNoPrompt == 'n') {
			break;
		}
		dayToday += 1; dayYesterday += 1; arrayCount += 1;
		previousNewCases = currentNewCases; previousTotalCases = currentTotalCases; previousTotalDeaths = currentTotalDeaths; previousTotalRecovered = currentTotalRecovered; previousUnderTreatment = currentUnderTreatment; ratesPreviousTotalDeaths = ratesCurrentTotalDeaths; ratesPreviousTotalRecovered = ratesCurrentTotalRecovered; ratesPreviousUnderTreatment = ratesCurrentUnderTreatment;
		while (1)
		{
			printf("\nDay %3.0lf", dayToday); //prints the current day//
			printf("\n========\n");
			printf("Key in Today's data:");
			printf("\n       No. of new local cases    : ");
			scanf("%lf", &currentLocal); // take current local cases from user//
			printf("       No. of new imported cases : ");
			scanf("%lf", &currentImport); // take current imported cases from user//
			currentNewCases = currentLocal + currentImport;
			printf("\nTotal no. of new cases = %3.0lf     ", currentNewCases);
			if (currentNewCases > previousNewCases) {                    // compare today and yesterday data//
				printf("( Increased by %2.0lf from yesterday.)", currentNewCases - previousNewCases);
			}
			else if (currentNewCases < previousNewCases) {
				printf("( Decreased by %2.0lf from yesterday.)", previousNewCases - currentNewCases);
			}
			else {
				printf("\n\nNo change from yesterday\n\n");
			}
			printf("\nNo. of deaths          =  ");
			scanf("%lf", &currentTotalDeaths);   //take current no. of death from user//
			printf("No. recovered          =  ");
			scanf("%lf", &currentTotalRecovered); // take current no. of recovered patients from user//

			ratesPreviousTotalDeaths = (previousTotalDeaths / previousTotalCases) * 100;           // formula list//
			ratesPreviousTotalRecovered = (previousTotalRecovered / previousTotalCases) * 100;    
			ratesPreviousUnderTreatment = (previousUnderTreatment / previousTotalCases) * 100;
			cases[arrayCount] = previousNewCases; duplicateCases[arrayCount] = previousNewCases;
			currentTotalCases = previousTotalCases + currentNewCases;
			currentTotalDeaths += previousTotalDeaths;
			currentTotalRecovered += previousTotalRecovered;
			currentUnderTreatment = currentTotalCases - currentTotalDeaths - currentTotalRecovered;
			ratesCurrentTotalDeaths = (currentTotalDeaths / currentTotalCases) * 100;
			ratesCurrentTotalRecovered = (currentTotalRecovered / currentTotalCases) * 100;
			ratesCurrentUnderTreatment = (currentUnderTreatment / currentTotalCases) * 100;
			previousDeathRates = (previousTotalDeaths / previousTotalCases) * 100;
			previousRecoveryRates = (previousTotalRecovered / previousTotalCases) * 100;
			currentDeathRates = (currentTotalDeaths / currentTotalCases) * 100;
			currentRecoveryRates = (currentTotalRecovered / currentTotalCases) * 100;
			differenceNewCases = currentNewCases - previousNewCases;
			differenceTotalCases = currentTotalCases - previousTotalCases;
			differenceDeathRates = currentDeathRates - previousDeathRates;
			differenceRecoveryRates = currentRecoveryRates - previousRecoveryRates;

			printf("\n1 - Daily Summary Report,  2 - Daily Comparative Report");
			printf("\nWhat type of Report would you like to view (Choose 1 or 2)? ");
			scanf("%d", &userDigitPrompt);                 // let users to pick either choice which is 1 or 2// 
			 
			switch (userDigitPrompt)// switch case depends on previous 1 or 2 input value//
			{
			case 1:
				todayTable(currentLocal, currentImport, currentNewCases, currentTotalCases, currentTotalDeaths, currentTotalRecovered, currentUnderTreatment, ratesCurrentTotalDeaths, ratesCurrentTotalRecovered, ratesCurrentUnderTreatment, dayToday);
				break;
			case 2:
				currentTable(previousNewCases, previousTotalCases, previousDeathRates, previousRecoveryRates, currentNewCases, currentTotalCases, currentDeathRates, currentRecoveryRates, differenceNewCases, differenceTotalCases, differenceDeathRates, differenceRecoveryRates, dayYesterday, dayToday);
				break;
			default:
				printf("Please try again later");
			}

			printf("\n-------------------------End of Day %2.0lf reporting-------------------------\n\n", dayToday);
			printf("Continue to next day (Y = yes)? ");
			scanf("%c", &userYesNoPrompt); // takes input y or n from user//
			if (userYesNoPrompt == 'n') { // if else statement depends on above input value//
				break;
			}
			dayToday += 1; dayYesterday += 1; arrayCount += 1;
			previousNewCases = currentNewCases; previousTotalCases = currentTotalCases; previousTotalDeaths = currentTotalDeaths; previousTotalRecovered = currentTotalRecovered; previousUnderTreatment = currentUnderTreatment; ratesPreviousTotalDeaths = ratesCurrentTotalDeaths; ratesPreviousTotalRecovered = ratesCurrentTotalRecovered; ratesPreviousUnderTreatment = ratesCurrentUnderTreatment;
			continue;
		}
		if (userYesNoPrompt == 'n') {
			break;
		}
	}
	

	totalDaysRecorded = (dayToday - STARTINGDAY) + 1;
	for (i = 1; i < (arrayCount + 1); ++i) {  //finding the largest array element//
		if (cases[0] < cases[i])
			cases[0] = cases[i];
	}
	highestNumOfCases = cases[0];
	for (i = 0; i < (arrayCount + 1); ++i) { // finding which day is the highest no of day//
		if (highestNumOfCases == duplicateCases[i])
			dayHighestNumOfCases = i + 9;
	}
	for (i = 1; i < (arrayCount + 1); ++i) {  //finding the smallest array element//
		if (cases[0] > cases[i])
			cases[0] = cases[i];
	}
	lowestNumOfCases = cases[0];
	for (i = 0; i < (arrayCount + 1); ++i) {  // finding which day is the lowest no of day//
		if (lowestNumOfCases == duplicateCases[i])
			dayLowestNumOfCases = i + 9;
	}
	printf("\n\n             TOTAL Days recorded       = %3.0lf days (Day %3.0lf to Day %3.0lf)", totalDaysRecorded, STARTINGDAY, dayToday);  // summary or finalize the input given//
	printf("\n             HIGHEST number of cases   =  %3.0lf, occuring on Day %3.0lf", highestNumOfCases, dayHighestNumOfCases);
	printf("\n             LOWEST number of cases    =  %3.0lf, occuring on Day %3.0lf", lowestNumOfCases, dayLowestNumOfCases);
	printf("\n\nBye and Thank You!!\n\n");
	system("pause");
	return 0;
}

//function 1//
void todayTable(double localCase, double importedCase, double newCases, double totalCases, double totalDeaths, double totalRecovered, double underTreatment, double ratesTotalDeaths, double ratesTotalRecovered, double ratesUnderTreatment, double today)
{
	printf("\nDay %3.0lf                       DAILY SUMMARY REPORT                              ", today);
	printf("\n+---------------+-------------++------------+-----------------+-----------------+\n");
	printf("|       Today's |  Total      ||  Total     |  Total          |  Under          |\n");
	printf("|       cases   |  cases      ||  deaths    |  recovered      |  treatment      |\n");
	printf("+---------------+-------------++------------+-----------------+-----------------+\n");
	printf("|local   %4.0lf   |             ||            |                 |                 |\n", localCase);
	printf("|imported%4.0lf   |             ||            |                 |                 |\n", importedCase);
	printf("|          %4.0lf |    %4.0lf     ||   %4.0lf     |      %4.0lf       |     %4.0lf        |\n", newCases, totalCases, totalDeaths, totalRecovered, underTreatment);
	printf("+-----------------------------++------------+-----------------+-----------------+\n");
	printf("                              ||  %4.1lf %%    |    %4.1lf %%       |    %4.1lf %%       |\n", ratesTotalDeaths, ratesTotalRecovered, ratesUnderTreatment);
	printf("                              ++------------+-----------------+-----------------+\n");
	rewind(stdin);
}
//function 2//
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
	printf("+------------------------+---------------+------------------++------------------|\n");
	printf("|New Cases               |     %4.0lf      |       %4.0lf       ||    [[%c %3.0lf]]     |\n", previousNewCases, currentNewCases, nc, differenceNewCases);
	printf("+------------------------+---------------+------------------++------------------|\n");
	printf("|Total Cases             |     %4.0lf      |       %4.0lf       ||    [[+%3.0lf]]      |\n", previousTotalCases, currentTotalCases, differenceTotalCases);
	printf("+------------------------+---------------+------------------++------------------|\n");
	printf("|Death Rate              |     %4.1lf %%    |      %4.1lf %%      ||    [[%c %3.1lf %%]]   |\n", previousDeathRate, currentDeathRate, dr, differenceDeathRate);
	printf("+------------------------+---------------+------------------++------------------|\n");
	printf("|Recovery Rates          |     %4.1lf %%    |       %4.1lf %%     ||   [[%c %4.1lf %%]]   |\n", previousRecoveryRate, currentRecoveryRate, rr, differenceRecoveryRate);
	printf("+------------------------+---------------+------------------++------------------+\n");
	rewind(stdin);
}
//function 3//
void yesterdayTable(double newCases, double totalCases, double totalDeaths, double totalRecovered, double underTreatment, double ratesTotalDeaths, double ratesTotalRecovered, double ratesUnderTreatment, double yesterday)
{
	printf("\n      Yesterday's Totals - (Day %2.0lf):", yesterday);
	printf("\n+---------------+-------------++------------+-----------------+-----------------+\n");
	printf("|   Yesterday's |   Total     || Total      | Total           | Under           |\n");
	printf("|   cases       |   cases     || deaths     | recovered       | treatment       |\n");
	printf("+---------------+-------------++------------+-----------------+-----------------+\n");
	printf("|        %4.0lf   |    %4.0lf     ||   %4.0lf     |      %4.0lf       |     %4.0lf        |\n", newCases, totalCases, totalDeaths, totalRecovered, underTreatment);
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
+------------------------+---------------+------------------++------------------|
|New Cases               |       10      |          5       ||    [[   -5]]     |
+------------------------+---------------+------------------++------------------|
|Total Cases             |      110      |        115       ||    [[+  5]]      |
+------------------------+---------------+------------------++------------------|
|Death Rate              |      6.4 %    |       7.0 %      ||    [[+ 0.6 %]]   |
+------------------------+---------------+------------------++------------------|
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
What type of Report would you like to view (Choose 1 or 2)? 2

							 DAILY COMPARATIVE REPORT
						 +---------------+------------------++------------------+
						 |  YESTERDAY    |     TODAY        ||   DIFFERENCE     |
						 |    Day 11     |      Day 12      ||                  |
+------------------------+---------------+------------------++------------------|
|New Cases               |        5      |         50       ||    [[+  45]]     |
+------------------------+---------------+------------------++------------------|
|Total Cases             |      115      |        165       ||    [[+ 50]]      |
+------------------------+---------------+------------------++------------------|
|Death Rate              |      7.0 %    |      10.9 %      ||    [[+ 4.0 %]]   |
+------------------------+---------------+------------------++------------------|
|Recovery Rates          |     22.6 %    |       21.8 %     ||   [[  -0.8 %]]   |
+------------------------+---------------+------------------++------------------+

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
What type of Report would you like to view (Choose 1 or 2)? 1

Day  13                       DAILY SUMMARY REPORT
+---------------+-------------++------------+-----------------+-----------------+
|       Today's |  Total      ||  Total     |  Total          |  Under          |
|       cases   |  cases      ||  deaths    |  recovered      |  treatment      |
+---------------+-------------++------------+-----------------+-----------------+
|local      8   |             ||            |                 |                 |
|imported  12   |             ||            |                 |                 |
|            20 |     185     ||     20     |       136       |       29        |
+-----------------------------++------------+-----------------+-----------------+
							  ||  10.8 %    |    73.5 %       |    15.7 %       |
							  ++------------+-----------------+-----------------+

-------------------------End of Day 13 reporting-------------------------

Continue to next day (Y = yes)? n


			 TOTAL Days recorded       =   4 days (Day  10 to Day  13)
			 HIGHEST number of cases   =   50, occuring on Day  12
			 LOWEST number of cases    =    5, occuring on Day  11

Bye and Thank You!!

Press any key to continue . . .*/
