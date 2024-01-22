/*GROUP PROJECT QUESTION 3 MADE BY:
1) MOUHAMMAD BIN SAID TOURE A19EE0471 
2)ElMOATASEM BELLAH OSSAMA MOHAMED WAHBA A19EE4032
3)TAN KAI SHENG A19EE0190
4)ANDY TAN KUI HUAT A19EE0020*/


#include <stdio.h>

double readFile(double *a, double *b, double *c, double *d, double *e);//Function to read values from the input file
double grandTotalSales(double *a, double *b, double *c, double *d, double *e); //Function to calculate the Grand total sales over all store
void averagepermonths(double numb);//Function to get the average of sales per month
void highestSale(double *a, double *b, double *c, double *d, double *e);//Function to display the highest sale by store, month and value
void lowestSale(double *a, double *b, double *c, double *d, double *e);//Function to display the lowest sale by store, month and value
void totalsalespermonth(double *a, double *b, double *c, double *d, double *e);//Function to display the total sales of the company per month
void totalsalesbystore(double *a, double *b, double *c, double *d, double *e);//Function to display the total sales of the company by store

//We used "*" along the variables to pass specific arguments such as arrays


main ()
{
	FILE *outputfile;
	double JohorBahru[12], Segamat[12], BatuPahat[12]; 
	double KotaTinggi[12], Mersing[12];//storebranch[12] keeps the sales by each store in 12 months
	double grandtotal;
	outputfile = fopen("output.out", "w");//At the beginning, the letter "w" (write) is used to create the ouput file, if it exists, it is emptied
	//Variables declarations to be used into main()
	
	readFile(JohorBahru, Segamat, BatuPahat, KotaTinggi, Mersing);
	//To read files
	
	grandtotal= grandTotalSales(JohorBahru, Segamat, BatuPahat, KotaTinggi, Mersing);
	fprintf(outputfile,"Grand total of sales over all stores:\t RM %10.2lf", grandtotal);
	fclose(outputfile);
	//To get the total sales over all stores
	
	averagepermonths(grandtotal);
	fclose(outputfile);
	//To get Average sales per month

	//Designated for highest sales:
	highestSale(JohorBahru, Segamat, BatuPahat, KotaTinggi, Mersing);
	fclose(outputfile);
	//End of highest sales

	//Designated for lowest sales:
	lowestSale(JohorBahru, Segamat, BatuPahat, KotaTinggi, Mersing);
	fclose(outputfile);
	//End of Lowest Sales

	//Designated for Total sales per month
	totalsalespermonth(JohorBahru, Segamat, BatuPahat, KotaTinggi, Mersing);
	//End of Total sales by month
	
	//Total sales by store and Profitable stores
	totalsalesbystore(JohorBahru, Segamat, BatuPahat, KotaTinggi, Mersing);
	//End of Total sales by store

	
	return 0;
	

fclose(outputfile);//To close the outputfile
	
	
}


double readFile(double *a, double *b, double *c, double *d, double *e)
{
	FILE *inputfile;
	inputfile = fopen("sales2014.dat", "r");
	/*We open the input file "sales2014.dat" to read the data from it*/
	int cnt;/*initializing the counter*/
	char stores[5][15];
	double JohorBahru[12], Segamat[12], BatuPahat[12]; 
	double KotaTinggi[12], Mersing[12];

	
	for(cnt=0; cnt<12; cnt++)
	fscanf(inputfile, "%lf", &a[cnt]);
	fgets(stores[0], 15, inputfile);
	
	for(cnt=0; cnt<12; cnt++)
	fscanf(inputfile, "%lf", &b[cnt]);
	fgets(stores[1], 15, inputfile);
	
	for(cnt=0; cnt<12; cnt++)
	fscanf(inputfile, "%lf", &c[cnt]);
	fgets(stores[2], 15, inputfile);
	
	for(cnt=0; cnt<12; cnt++)
	fscanf(inputfile, "%lf", &d[cnt]);
	fgets(stores[3], 15, inputfile);
	
	for(cnt=0; cnt<12; cnt++)
	fscanf(inputfile, "%lf", &e[cnt]);
	fgets(stores[4], 15, inputfile);
	/*Scanning the values from the input file*/
	
	for(cnt=0; cnt<12; cnt++)
	{
		a[cnt]=1000*a[cnt];
		b[cnt]=1000*b[cnt];
		c[cnt]=1000*c[cnt];
		d[cnt]=1000*d[cnt];
		e[cnt]=1000*e[cnt];
	}
	//Multiplying the numbers by 1000.00
	
	fclose(inputfile);//To close the inputfile
	
	return *a, *b, *c, *d, *e;/*returning the pointer values to their respective arrays*/
}


double grandTotalSales(double *a, double *b, double *c, double *d, double *e)
{
	int cnt;
	double num2=0;
	for(cnt=0; cnt<12; cnt++)
	{
		num2= num2+a[cnt]+b[cnt]+c[cnt]+d[cnt]+e[cnt];//it successively adds the sales per month to get the yearly total denoted by num2
	}
	
	return num2;
}


void averagepermonths(double numb)
/*The variable numb is grandtotal is this case in order to get the monthly average*/
{
	FILE *outputfile;
	outputfile = fopen("output.out", "a");
	/*The letter "a" for (appending) is used to place the writing pointer at the end
	of the file in order to preserve what was previously written*/
	double num;
	
	num=numb/12;
	
	fprintf(outputfile,"\nAverage sales per month:\t\t RM %10.2lf", num);
	
}


void highestSale(double *a, double *b, double *c, double *d, double *e)
/*The methods and pattern used in this function are the same observed in the lowestsale function*/
{
	FILE *outputfile;
	double highestofall, highestjb, highestseg, highestbat, highestkot, highestmer;
	/*We get the highest monthly value for every store*/
	int cnt, highestmonth, highestmonthjb, highestmonthseg, highestmonthbat, highestmonthkot, highestmonthmer;
	/* The highestmonth values will hold the value of counter, counter will be the the index of the month
	Therefore, highestmonth will hold the month's number*/
	double highest[5];
	char months[12][4]= 
	       { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , 
	        "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
	/*The array months[12][4] is used to print the month names. The maximum size of those strings is 4*/
	outputfile = fopen("output.out", "a");
	char stores[5][15]= 
	{"Johor Bahru", "Segamat", "Batu Pahat", "Kota Tinggi", "Mersing"};
	
	fprintf(outputfile,"\n\nThe highest sales:\n");
	fprintf(outputfile,"------------------");
	
	/*The followings will process the different indexes of the arrays to find the highest value
	That value will be given to highest(store name) using a "for" loop and the comparison process.*/
	
	/*In the comparison process with arrays, we assign the comparative variable to one of the values hold by
	the array. Then, using a for loop, we can find the element with the requested quality.
	In this instance, we are looking for the highest value*/
	highestjb=a[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(a[cnt]>highestjb)
		{
			highestjb=a[cnt];
			highestmonthjb=cnt;
		}
	}
	
	highestseg=b[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(b[cnt]>highestseg)
		{
			highestseg=b[cnt];
			highestmonthseg=cnt;
		}	
	}
	
	highestbat=c[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(c[cnt]>highestbat)
		{
			highestbat=c[cnt];
			highestmonthbat=cnt;
		}	
	}
	
	highestkot=d[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(d[cnt]>highestkot)
		{
			highestkot=cnt;
			;
		}	
	}
	
	highestmer=e[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(e[cnt]>highestmer)
		{
			highestmer=e[cnt];
			highestmonthmer=cnt;
		}	
	}
	
	highest[0]=highestjb;
	highest[1]=highestseg;
	highest[2]=highestbat;
	highest[3]=highestkot;
	highest[4]=highestmer;
	/*We appoint each index of highest[] to the highest of each branch*/
	highestofall=highest[0];
	for(cnt=1; cnt<5; cnt++)
	{
		if(highest[cnt]>highestofall)
		highestofall=highest[cnt];
	}
	/*We then proceed to compare the highest values with each other to be appointed
	as the "Highest of all"*/
	
	
	/*Depending on the value or variable belonging to the highestofall, the appropiate
	informations (Store name and month) are displayed using if else statements.
	At the end, we print the value of highestofall*/
	if(highestofall==highestjb)
	{
		fprintf(outputfile,"\nStore:  %s", stores[0]);
		fprintf(outputfile,"\nMonth:  %s", months[highestmonthjb]);
	}
	else if(highestofall==highestseg)
	{
		fprintf(outputfile,"\nStore:  %s", stores[1]);
		fprintf(outputfile,"\nMonth:  %s", months[highestmonthseg]);
	}
	else if(highestofall==highestbat)
	{
		fprintf(outputfile,"\nStore:  %s", stores[2]);
		fprintf(outputfile,"\nMonth:  %s", months[highestmonthbat]);
	}
	else if(highestofall==highestkot)
	{
		fprintf(outputfile,"\nStore:  %s", stores[3]);
		fprintf(outputfile,"\nMonth:  %s", months[highestmonthkot]);
	}
	else if(highestofall==highestmer)
	{
		fprintf(outputfile,"\nStore:  %s", stores[4]);
		fprintf(outputfile,"\nMonth:  %s", months[highestmonthmer]);
	}
	
	fprintf(outputfile,"\nSales:  RM%10.2lf", highestofall);
}


void lowestSale(double *a, double *b, double *c, double *d, double *e)
{
	FILE *outputfile;
	double lowestofall, lowestjb, lowestseg, lowestbat, lowestkot, lowestmer;
	/*We get the highest monthly value for every store*/
	int cnt, lowestmonth, lowestmonthjb, lowestmonthseg, lowestmonthbat, lowestmonthkot, lowestmonthmer;
	/* The lowestmonth values will hold the value of counter, counter will be the the index of the month
	Therefore, lowestmonth will hold the month's number*/
	double lowest[5];
	char months[12][4]= 
	       { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , 
	        "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
	outputfile = fopen("output.out", "a");
	char stores[5][15]= 
	{"Johor Bahru", "Segamat", "Batu Pahat", "Kota Tinggi", "Mersing"};
	
	fprintf(outputfile,"\n\nThe lowest sales:\n");
	fprintf(outputfile,"------------------");
	
	/*The followings will process the different indexes of the arrays to find the lowest value
	That value will be given to lowest(store name) using a "for" loop and the comparison process.*/
	
	/*In the comparison process with arrays, we assign the comparative variable to one of the values hold by
	the array. Then, using a for loop, we can find the element with the requested quality.
	In this instance, we are looking for the lowest value
	Please notice once again that the same pattern is used as in the highestsale function*/
	lowestjb=a[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(a[cnt]<lowestjb)
		{
			lowestjb=a[cnt];
			lowestmonthjb=cnt;
		}
	}
	
	lowestseg=b[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(b[cnt]<lowestseg)
		{
			lowestseg=b[cnt];
			lowestmonthseg=cnt;
		}
	}
	
	lowestbat=c[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(c[cnt]<lowestbat)
		{
			lowestbat=c[cnt];
			lowestmonthbat=cnt;
		}
	}
	
	lowestkot=d[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(d[cnt]<lowestkot)
		{
			lowestkot=d[cnt];
			lowestmonthkot=cnt;
		}
	}
	
	lowestmer=e[0];
	for(cnt=1; cnt<12; cnt++)
	{
		if(e[cnt]<lowestmer)
		{
			lowestmer=e[cnt];
			lowestmonthmer=cnt;
		}	
	}
	
	lowest[0]=lowestjb;
	lowest[1]=lowestseg;
	lowest[2]=lowestbat;
	lowest[3]=lowestkot;
	lowest[4]=lowestmer;
	/*We appoint each index of lowest[] to the lowest of each branch*/
	lowestofall=lowest[0];
	for(cnt=1; cnt<5; cnt++)
	{
		if(lowest[cnt]<lowestofall)
		lowestofall=lowest[cnt];
	}
	/*We then proceed to compare the lowest values with each other to be appointed
	as the "Lowest of all"*/
	
	
	/*Depending on the value or variable belonging to the lowestofall, the appropiate
	informations (Store name and month) are displayed using if else statements.
	At the end, we print the value of lowestofall*/
	if(lowestofall==lowestjb)
	{
		fprintf(outputfile,"\nStore:  %s", stores[0]);
		fprintf(outputfile,"\nMonth:  %s", months[lowestmonthjb]);
	}
	else if(lowestofall==lowestseg)
	{
		fprintf(outputfile,"\nStore:  %s", stores[1]);
		fprintf(outputfile,"\nMonth:  %s", months[lowestmonthseg]);
	}
	else if(lowestofall==lowestbat)
	{
		fprintf(outputfile,"\nStore:  %s", stores[2]);
		fprintf(outputfile,"\nMonth:  %s", months[lowestmonthbat]);
	}
	else if(lowestofall==lowestkot)
	{
		fprintf(outputfile,"\nStore:  %s", stores[3]);
		fprintf(outputfile,"\nMonth:  %s", months[lowestmonthkot]);
	}
	else if(lowestofall==lowestmer)
	{
		fprintf(outputfile,"\nStore:  %s", stores[4]);
		fprintf(outputfile,"\nMonth:  %s", months[lowestmonthmer]);
	}
	
	fprintf(outputfile,"\nSales:  RM%10.2lf", lowestofall);
}


void totalsalespermonth(double *a, double *b, double *c, double *d, double *e)
{
	FILE *outputfile;
	int cnt;
	double totaljan=0, totalfeb=0, totalmar=0, totalapr=0, totalmay=0, totaljun=0; 
	double totaljul=0, totalaug=0, totalsep=0, totaloct=0, totalnov=0, totaldec=0;
	/*We initialize the variables total(month name) to hold the total sales of all stores in each month*/
	double totalpermonth[12]= 
           {totaljan=0, totalfeb=0, totalmar=0, totalapr=0, totalmay=0, totaljun=0, 
	        totaljul=0, totalaug=0, totalsep=0, totaloct=0, totalnov=0, totaldec=0};
	/*The array totalpermonth[12] holds the different total sales per month in every index, therefore
	the size of the array is 12*/
	char months[12][4]= 
	       { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , 
	        "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
	
	outputfile = fopen("output.out", "a");
	
	for(cnt=0; cnt<12; cnt++)
	totalpermonth[cnt]=(a[cnt]+b[cnt]+c[cnt]+d[cnt]+e[cnt]);
	
	fprintf(outputfile,"\n\n\nTotal sales by month:\n");
	fprintf(outputfile,"Month\tSales\n");
	fprintf(outputfile,"-----\t-----");
	
	for(cnt=0; cnt<12; cnt++)
	fprintf(outputfile,"\n%s   RM %10.2lf", months[cnt], totalpermonth[cnt]);
	/*The range of cnt is from 0 to 11 (both included) because of its usage in arrays.
	Based on the month's number, the name and total sales in that month are printed*/
}


void totalsalesbystore(double *a, double *b, double *c, double *d, double *e)
{
	FILE *outputfile;
	outputfile = fopen("output.out", "a");
	int cnt;
	double totalbranch[5], totalJohorBahru=0, totalSegamat=0, totalBatuPahat=0, totalKotaTinggi=0, totalMersing=0;
	/*We initialize the variables total(store name) to hold the total yearly sales by each store
	In this regard, they will be used as accumulator variables.*/
	char stores[5][15]= 
	{"Johor Bahru", "Segamat", "Batu Pahat", "Kota Tinggi", "Mersing"};
	
	for(cnt=0; cnt<12; cnt++)
	{
		totalJohorBahru=(totalJohorBahru+a[cnt]);
		totalSegamat=(totalSegamat+b[cnt]);
		totalBatuPahat=(totalBatuPahat+c[cnt]); 
		totalKotaTinggi=(totalKotaTinggi+d[cnt]); 
		totalMersing=(totalMersing+e[cnt]);
	}/*We accumulate the total yearly sales by using the individual values stored in the arrays (Store name)[12]*/
	
	totalbranch[0]=totalJohorBahru;
	totalbranch[1]=totalSegamat;
	totalbranch[2]=totalBatuPahat;
	totalbranch[3]=totalKotaTinggi;
	totalbranch[4]=totalMersing;
	/*The total yearly sales per stores are appointed to the different indexes in the totalbranch[5] array*/
	
	fprintf(outputfile,"\n\nTotal sales by store:\n");
	fprintf(outputfile,"Store\t\tTotal Sales\n");
	fprintf(outputfile,"-----\t\t-----------\n");
	for(cnt=0; cnt<5; cnt++)
	fprintf(outputfile,"%-13s\tRM %10.2lf\n", stores[cnt], totalbranch[cnt]);
	/*we proceed to print the stores names' and their total yearly sales*/
	
	
	fprintf(outputfile,"\nProfitable stores:");
	fprintf(outputfile,"\n------------------");
	for(cnt=0; cnt<5; cnt++)
	{
		if(totalbranch[cnt]>=600000)
		fprintf(outputfile,"\n%s", stores[cnt]);
	}/*Knowing that a store branch is considered profitable if its total yearly sales
	are over 600000, the program will print it's name according to that standard*/
	
}


