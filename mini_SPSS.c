
/**********************************************************
 *
 * Project Name: Mini SPSS in C
 * 
 * -박유진 Park Yujin
 *
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include <string.h>
#include <math.h>

#include <gsl/gsl_sf_erf.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_statistics.h>


/* Constants */
#define MAX_LINE 30

/* Global Variables */
char line[MAX_LINE];
char* lineP;


/* Functions */

void Opening_Interface();		// Opening Statements


int Interface_Input_Main();		// main menu


int Interface_Input_Transformation();	// Transformation

int Interface_Input_PDF();		// [PDF]
float PDF_Binomial_Distribution();	// -Binomial
float PDF_Poisson_Distribution();	// -Poisson
float PDF_Normal_Distribution();	// -Normal
float PDF_Std_Norm_Distribution();	// -Standard Normal

int Interface_Input_CDF();	// [CDF]
float CDF_Binomial_Distribution();	// -Binomial
float CDF_Poisson_Distribution();	// -Poisson
float CDF_Normal_Distribution();	// -Normal
float CDF_Std_Norm_Distribution();	// -Standard Normal

int Interface_Input_Inverse_PDF();	// [Inverse PDF]
float IPDF_Binomial_Distribution();	// -Binomial
float IPDF_Poisson_Distribution();	// -Poisson
float IPDF_Normal_Distribution();	// -Normal
float IPDF_Std_Norm_Distribution();	// -Standard Normal

int Interface_Input_Inverse_CDF();	// [Inverse CDF]
float ICDF_Binomial_Distribution();	// -Binomial
float ICDF_Poisson_Distribution();	// -Poisson
float ICDF_Normal_Distribution();	// -Normal
float ICDF_Std_Norm_Distribution();	// -Standard Normal


int Interface_Input_Analysis();		// Analysis

float H1_Confidence_Interval();

int Interface_Input_H1();	// Hypothesis Test for 1 Population
float H1_X_Based();			// X Based
float H1_Z_Based();			// Z Based
float H1_P_Val_Based();			// P-value Based

int Interface_Input_H2();	// Hypothesis Test for 2 Populations

int Interface_Independent();
float H2_IS_X_Based();			// X Based
float H2_IS_Z_Based();			// Z Based
float H2_IS_P_Val_Based();			// P-value Based

int Interface_Paired();
float H2_PS_X_Based();			// X Based
float H2_PS_Z_Based();			// Z Based
float H2_PS_P_Val_Based();			// P-value Based

float H2_Two_Sample_Variances();


int Interface_Input_ANOVA1();	// 1 Way ANOVA Test
int Interface_Input_ANOVA2();	// 2 Way ANOVA Test


int Interface_Input_Others();		// Other


/* Additional Function */

void Error_Handler(char* m, char* p) {

	if (!m) {

		printf("This message is shown for the error!\n");
		exit(0);
	}

	printf("%s at %s!\n", m, p);
}

void Choice_Message(char* m) {

	printf("SPSS> You chose the [ %s ] menu.\n", m);
}

void gsl_Error_Handler() {
	gsl_set_error_handler_off();
}





int main(int argc, char* argv[]) {
	
	int L1;
	int L2;
	int L3;
	int L4;
	bool flag = false;

	Opening_Interface();
	L1 = Interface_Input_Main();


	while (!flag) {
		
		if (L1 == 0) {
			/* Quit */
			Choice_Message("Quit");
			printf("SPSS> Exiting the program...\n");
			exit(0);
		}

		if (L1 == 1) {
			/* Transformation */

			Choice_Message("Transformation");
			
			while (!flag) {
				L2 = Interface_Input_Transformation();

				if (L2 == 0) {
					/* Back to the Main Menu */
					Choice_Message("Main Menu");
					break;
				}
				if (L2 == 1) {
					/* PDF */
					Choice_Message("PDF");

					while (!flag) {
						L3 = Interface_Input_PDF();

						if (L3 == 0) {
							/* Back to the Transformation */
							Choice_Message("Previous Menu");
							break;
						}
						switch (L3) {
						case 1:
							Choice_Message("Binomial Distribution");
							PDF_Binomial_Distribution();
							break;
						case 2:
							Choice_Message("Poisson Distribution");
							PDF_Poisson_Distribution();
							break;
						case 3:
							Choice_Message("Normal Distribution");
							PDF_Normal_Distribution();
							break;
						case 4:
							Choice_Message("Standard Normal Distribution");
							PDF_Std_Norm_Distribution();
							break;
						}

						flag = true;
						break;
					}
				}
				else if (L2 == 2) {
					/* CDF */
					Choice_Message("CDF");
					
					while (!flag) {
						L3 = Interface_Input_CDF();

						if (L3 == 0) {
							/* Back to the Transformation */
							Choice_Message("Previous Menu");
							break;
						}
						switch (L3) {
						case 1:
							Choice_Message("Binomial Distribution");
							CDF_Binomial_Distribution();
							break;
						case 2:
							Choice_Message("Poisson Distribution");
							CDF_Poisson_Distribution();
							break;
						case 3:
							Choice_Message("Normal Distribution");
							CDF_Normal_Distribution();
							break;
						case 4:
							Choice_Message("Standard Normal Distribution");
							CDF_Std_Norm_Distribution();
							break;
						}

						flag = true;
						break;
					}
				}
				else if (L2 == 3) {
					/* Inverse PDF */
					Choice_Message("Inverse PDF");
					
					while (!flag) {
						L3 = Interface_Input_Inverse_PDF();

						if (L3 == 0) {
							/* Back to the Transformation */
							Choice_Message("Previous Menu");
							break;
						}
						switch (L3) {
						case 1:
							Choice_Message("Binomial Distribution");
							IPDF_Binomial_Distribution();
							break;
						case 2:
							Choice_Message("Poisson Distribution");
							IPDF_Poisson_Distribution();
							break;
						case 3:
							Choice_Message("Normal Distribution");
							IPDF_Normal_Distribution();
							break;
						case 4:
							Choice_Message("Standard Normal Distribution");
							IPDF_Std_Norm_Distribution();
							break;
						}

						flag = true;
						break;
					}
				}
				else if (L2 == 4) {
					/* Inverse CDF */
					Choice_Message("Inverse CDF");
					
					while (!flag) {
						L3 = Interface_Input_Inverse_CDF();

						if (L3 == 0) {
							/* Back to the Transformation */
							Choice_Message("Previous Menu");
							break;
						}
						switch (L3) {
						case 1:
							Choice_Message("Binomial Distribution");
							ICDF_Binomial_Distribution();
							break;
						case 2:
							Choice_Message("Poisson Distribution");
							ICDF_Poisson_Distribution();
							break;
						case 3:
							Choice_Message("Normal Distribution");
							ICDF_Normal_Distribution();
							break;
						case 4:
							Choice_Message("Standard Normal Distribution");
							ICDF_Std_Norm_Distribution();
							break;
						}

						flag = true;
						break;
					}
				}

				flag = false;
				break;
			}
		}
		else if (L1 == 2) {
			/* Analysis */

			Choice_Message("Analysis");

			while (!flag) {
				L2 = Interface_Input_Analysis();

				if (L2 == 0) {
					/* Back to the Main Menu */
					Choice_Message("Main Menu");
					break;
				}

				if (L2 == 1) {

					Choice_Message("Hypothesis Test for 1 Population");

					while (!flag) {
						
						L3 = Interface_Input_H1();

						switch (L3) {
						case 1:
							Choice_Message("X Based");
							H1_X_Based();
							break;
						case 2:
							Choice_Message("Z Based");
							H1_Z_Based();
							break;
						case 3:
							Choice_Message("P-value Based");
							H1_P_Val_Based();
							break;
						}

						flag = true;
						break;
					}
				}
				else if (L2 == 2) {

					Choice_Message("Hypothesis Test for 2 Populations");
					
					while (!flag) {

						L3 = Interface_Input_H2();


						if (L3 == 1) {

							Choice_Message("Compare mean for independent samples");

							while (!flag) {

								L4 = Interface_Independent();

								switch (L4) {
								case 1:
									Choice_Message("X Based");
									H2_IS_X_Based();
									break;
								case 2:
									Choice_Message("Z Based");
									
									break;
								case 3:
									Choice_Message("P-value Based");
									
									break;
								}

								flag = true;
								break;
							}
						}
						else if (L3 == 2) {

							Choice_Message("Compare mean for paired samples");

						}
						else if (L3 == 3) {
							
							Choice_Message("Test for two sample variances");

						}

						flag = true;
						break;
					}
				}
				else if (L2 == 3) {

					Choice_Message("1 Way ANOVA Test");
					Interface_Input_ANOVA1();
				}
				else if (L2 == 4) {

					Choice_Message("2 Way ANOVA Test");
					Interface_Input_ANOVA2();
				}
				else if (L2 == 5) {

					Choice_Message("Confidential Interval Calculation");
					H1_Confidence_Interval();
				}

				flag = true;
				break;
			}
		}
		else if (L1 == 3) {
			/* Other */

			Choice_Message("Others");
		}

		flag = false;
		L1 = Interface_Input_Main();
	}

	return 0;
}


void Opening_Interface() {
	
	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                    >>  Mini SPSS in C  <<                    ||\n");
	printf("||                                                              ||\n");
	printf("||  ** This program is designed to analyze statistics in C. **  ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("******************************************************************\n");
}

int Interface_Input_Main() {

	int L1;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                      >>   MAIN MENU  <<                      ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                      1) Transformation                       ||\n");
	printf("||                      2) Analysis                             ||\n");
	printf("||                      3) Others                               ||\n");
	printf("||                      0) Quit                                 ||\n");
	printf("||                                                              ||\n");
	printf("||      * If you want to quit, please enter the number 0.       ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if(!(lineP=gets(line)))
		Error_Handler("Error: This command is not available", "menu");

	L1 = atoi(line);

	while (L1 < 0 || L1 > 3) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "menu");
		L1 = Interface_Input_Main();
	}

	return L1;
}

int Interface_Input_Transformation() {

	int L2;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                    >>  TRANSFORMATION  <<                    ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||            1) Probability Density Function(PDF)              ||\n");
	printf("||            2) Cumulative Probability Functions(CDF)          ||\n");
	printf("||            3) Inverse PDF                                    ||\n");
	printf("||            4) Inverse CDF                                    ||\n");
	printf("||            0) Back to the Main Menu                          ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "transformation");

	L2 = atoi(line);

	while (L2 < 0 || L2 > 4) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "transformation");
		L2 = Interface_Input_Transformation();
	}

	return L2;
}

int Interface_Input_PDF() {

	int L3;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                           >>  PDF  <<                        ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                1) Binomial Distribution                      ||\n");
	printf("||                2) Poisson Distribution                       ||\n");
	printf("||                3) Normal Distribution                        ||\n");
	printf("||                4) Standard Normal Distribution               ||\n");
	printf("||                0) Back to the Previous Menu                  ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF");

	L3 = atoi(line);

	while (L3 < 0 || L3 > 4) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "PDF");
		L3 = Interface_Input_PDF();
	}

	return L3;
}


float PDF_Binomial_Distribution() {

	int n, k;
	double p;
	double res;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||             >>  (PDF)  Binomial Distribution  <<             ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> Please enter the number of total trials: ");

	if (!(lineP=gets(line)))
		Error_Handler("Error: This command is not available", "PDF Binomial Distribution");

	n = atoi(line);

	printf("SPSS> Please enter the probability for success (0.0 to 1.0): ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF Binomial Distribution");

	p = atof(line);

	printf("SPSS> Please enter the number of successes: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF Binomial Distribution");

	k = atoi(line);

	res = gsl_ran_binomial_pdf(k, p, n);

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", res);
	printf("SPSS>\n");

	return res;
}

float PDF_Poisson_Distribution() {

	int k;
	double mu;
	double res;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||              >>  (PDF) Poisson Distribution  <<              ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> Please enter the average number of events: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF Poisson Distribution");

	mu = atof(line);

	printf("SPSS> Please enter the number of events: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF Poisson Distribution");

	k = atoi(line);

	res = gsl_ran_poisson_pdf(k, mu);

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", res);
	printf("SPSS>\n");

	return res;
}

float PDF_Normal_Distribution() {

	double x, mu, sigma;
	double res;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||              >>  (PDF)  Normal Distribution  <<              ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> Please enter the mean: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF Normal Distribution");

	mu = atof(line);

	printf("SPSS> Please enter the standard deviation: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF Normal Distribution");

	sigma = atof(line);

	printf("SPSS> Please enter the value of x: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF Normal Distribution");

	x = atof(line);

	res = gsl_ran_gaussian_pdf(x - mu, sigma);

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", res);
	printf("SPSS>\n");

	return res;
}

float PDF_Std_Norm_Distribution() {

	double z;
	double res;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||          >>  (PDF) Standard Normal Distribution  <<          ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> Please enter the value of z: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF Standard Normal Distribution");

	z = atof(line);

	res = gsl_ran_gaussian_pdf(z, 1.0);

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", res);
	printf("SPSS>\n");

	return res;
}

int Interface_Input_CDF() {

	int L3;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                           >>  CDF  <<                        ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                1) Binomial Distribution                      ||\n");
	printf("||                2) Poisson Distribution                       ||\n");
	printf("||                3) Normal Distribution                        ||\n");
	printf("||                4) Standard Normal Distribution               ||\n");
	printf("||                0) Back to the Previous Menu                  ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF");

	L3 = atoi(line);

	while (L3 < 0 || L3 > 4) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "CDF");
		L3 = Interface_Input_CDF();
	}

	return L3;
}

float CDF_Binomial_Distribution() {

	int menu;
	int n, k;
	double p;
	double res;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||             >>  (CDF)  Binomial Distribution  <<             ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                  1) P(X <= k)                                ||\n");
	printf("||                  2) P(X > k) = 1 - P(X <= k)                 ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Binomial Distribution");

	menu = atoi(line);

		
	printf("SPSS> Please enter the number of total trials: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Binomial Distribution");

	n = atoi(line);

	printf("SPSS> Please enter the probability for success (0.0 to 1.0): ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Binomial Distribution");

	p = atof(line);

	printf("SPSS> Please enter the number of successes: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Binomial Distribution");

	k = atoi(line);

	if (menu == 1)
		res = gsl_cdf_binomial_P(k, p, n);
	else if (menu == 2)
		res = gsl_cdf_binomial_Q(k-1, p, n);

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", res);
	printf("SPSS>\n");

	return res;
}

float CDF_Poisson_Distribution() {

	int menu;
	int k;
	double mu;
	double res;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||              >>  (CDF) Poisson Distribution  <<              ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                  1) P(X <= k)                                ||\n");
	printf("||                  2) P(X > k) = 1 - P(X <= k)                 ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Poisson Distribution");

	menu = atoi(line);
	
	
	printf("SPSS> Please enter the average number of events: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Poisson Distribution");

	mu = atof(line);

	printf("SPSS> Please enter the number of events: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Poisson Distribution");

	k = atoi(line);

	if (menu == 1)
		res = gsl_cdf_poisson_P(k, mu);
	else if (menu == 2)
		res = 1 - gsl_cdf_poisson_P(k, mu);

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", res);
	printf("SPSS>\n");

	return res;
}

float CDF_Normal_Distribution() {

	int menu;
	double x, mu, sigma, a, b;
	double cdf_a, cdf_b, res;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||              >>  (CDF)  Normal Distribution  <<              ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                  1) P(X <= x)                                ||\n");
	printf("||                  2) P(X > x) = 1 - P(X <= x)                 ||\n");
	printf("||                  3) P(a <= X <= b)                           ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Normal Distribution");

	menu = atoi(line);
	
	
	printf("SPSS> Please enter the mean: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Normal Distribution");

	mu = atof(line);

	printf("SPSS> Please enter the standard deviation: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Normal Distribution");

	sigma = atof(line);

	if (menu == 1 || menu == 2) {
		
		printf("SPSS> Please enter the value of x: ");
		if (!(lineP = gets(line)))
			Error_Handler("Error: This command is not available", "CDF Normal Distribution");

		x = atof(line);
	}
	else if (menu == 3) {

		printf("SPSS> Please enter the first value: ");
		if (!(lineP = gets(line)))
			Error_Handler("Error: This command is not available", "CDF Normal Distribution");

		a = atof(line);

		printf("SPSS> Please enter the second value: ");
		if (!(lineP = gets(line)))
			Error_Handler("Error: This command is not available", "CDF Normal Distribution");

		b = atof(line);

		if (a > b) {
			Error_Handler("Error: First value can't be bigger than the second", "CDF Normal Distribution");
		}
	}

	if (menu == 1)
		res = 0.5 * (1 + erf((x - mu) / (sigma * sqrt(2))));
	else if (menu == 2)
		res = 1 - (0.5 * (1 + erf((x - mu) / (sigma * sqrt(2)))));
	else if (menu == 3) {

		cdf_a = 0.5 * (1 + erf((a - mu) / (sigma * sqrt(2))));
		cdf_b = 0.5 * (1 + erf((b - mu) / (sigma * sqrt(2))));

		res = cdf_b - cdf_a;
	}

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", res);
	printf("SPSS>\n");

	return res;
}

float CDF_Std_Norm_Distribution() {

	int menu;
	double x;
	double res;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||          >>  (CDF) Standard Normal Distribution  <<          ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                  1) P(X <= k)                                ||\n");
	printf("||                  2) P(X > k) = 1 - P(X <= k)                 ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Standard Normal Distribution");

	menu = atoi(line);
	

	printf("SPSS> Please enter the value of x: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "CDF Standard Normal Distribution");

	x = atof(line);

	if (menu == 1)
		res = gsl_cdf_gaussian_P(x, 1);
	else if (menu == 2)
		res = gsl_cdf_gaussian_Q(x, 1);

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", res);
	printf("SPSS>\n");

	return res;
}

int Interface_Input_Inverse_PDF() {

	int L3;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                     >>  Inverse  PDF  <<                     ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                1) Binomial Distribution                      ||\n");
	printf("||                2) Poisson Distribution                       ||\n");
	printf("||                3) Normal Distribution                        ||\n");
	printf("||                4) Standard Normal Distribution               ||\n");
	printf("||                0) Back to the Previous Menu                  ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "Inverse PDF");

	L3 = atoi(line);

	while (L3 < 0 || L3 > 4) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "Inverse PDF");
		L3 = Interface_Input_Inverse_PDF();
	}

	return L3;
}

float IPDF_Binomial_Distribution() {

	int n;
	double p, p_val;
	int k;

	gsl_Error_Handler();

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||             >>  (IPDF) Binomial Distribution  <<             ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> Please enter the number of total trials: ");

	if (scanf("%d", &n) != 1 || n <= 0)
		Error_Handler("Error: This command is not available", "IPDF Binomial Distribution");

	printf("SPSS> Please enter the probability for success (0.0 to 1.0): ");

	if (scanf("%lf", &p) != 1 || p < 0.0 || p > 1.0)
		Error_Handler("Error: This command is not available", "IPDF Binomial Distribution");

	printf("SPSS> Please enter the p-value: ");

	if (scanf("%lf", &p_val) != 1 || p_val < 0.0 || p_val > 1.0)
		Error_Handler("Error: This command is not available", "IPDF Binomial Distribution");

	int low = 0;
	int high = n;
	int mid;
	double cdf_val;

	while (high - low > 1) {

		mid = (low + high) / 2;

		cdf_val = gsl_cdf_binomial_P(mid, p, n);

		if (cdf_val < p_val)
			low = mid + 1;
		else
			high = mid;
	}
	k = low;

	printf("SPSS>\n");
	printf("SPSS> The Result: %d\n", k);
	printf("SPSS>\n");

	return k;
}

float IPDF_Poisson_Distribution() {

	double mu, p_val;
	int k;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||             >>  (IPDF)  Poisson Distribution  <<             ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> Please enter the average number of events: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "IPDF Poisson Distribution");

	mu = atof(line);

	printf("SPSS> Please enter the p-value: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "IPDF Poisson Distribution");

	p_val = atof(line);

	int low = 0;
	int high = 1000;
	int mid;
	double cdf_val;

	while (low <= high) {

		mid = (low + high) / 2;

		cdf_val = gsl_cdf_poisson_P(mid, mu);

		if (cdf_val < p_val)
			low = mid + 1;
		else if (cdf_val > p_val)
			high = mid - 1;
		else
			break;
	}
	k = low;

	printf("SPSS>\n");
	printf("SPSS> The Result: %d\n", k);
	printf("SPSS>\n");

	return k;
}

float IPDF_Normal_Distribution() {

	double p_val, mu, sigma, z;
	double x;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||              >>  (IPDF) Normal Distribution  <<              ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> Please enter the mean: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "IPDF Normal Distribution");

	mu = atof(line);

	printf("SPSS> Please enter the standard deviation: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "IPDF Normal Distribution");

	sigma = atof(line);

	printf("SPSS> Please enter the p-value: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "IPDF Normal Distribution");

	p_val = atof(line);

	z = gsl_cdf_gaussian_Pinv(p_val, 1.0);
	x = mu + z * sigma;

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", x);
	printf("SPSS>\n");

	return x;
}

float IPDF_Std_Norm_Distribution() {

	double p_val;
	double z;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||         >>  (IPDF)  Standard Normal Distribution  <<         ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> Please enter the p-value: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "PDF Standard Normal Distribution");

	p_val = atof(line);

	z = gsl_cdf_gaussian_Pinv(p_val, 1.0);

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", z);
	printf("SPSS>\n");

	return z;
}

int Interface_Input_Inverse_CDF() {

	int L3;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                     >>  Inverse  CDF  <<                     ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                1) Binomial Distribution                      ||\n");
	printf("||                2) Poisson Distribution                       ||\n");
	printf("||                3) Normal Distribution                        ||\n");
	printf("||                4) Standard Normal Distribution               ||\n");
	printf("||                0) Back to the Previous Menu                  ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "Inverse CDF");

	L3 = atoi(line);

	while (L3 < 0 || L3 > 4) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "Inverse CDF");
		L3 = Interface_Input_Inverse_CDF();
	}

	return L3;
}

float ICDF_Binomial_Distribution() {

	int menu;
	int n;
	double p, p_val;
	int k;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||             >>  (ICDF) Binomial Distribution  <<             ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                  1) P(X <= k)                                ||\n");
	printf("||                  2) P(X > k) = 1 - P(X <= k)                 ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Binomial Distribution");

	menu = atoi(line);


	printf("SPSS> Please enter the number of total trials: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Binomial Distribution");

	n = atoi(line);

	printf("SPSS> Please enter the probability for success (0.0 to 1.0): ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Binomial Distribution");

	p = atof(line);

	printf("SPSS> Please enter the p-value: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Binomial Distribution");

	p_val = atof(line);


	int low = 0;
	int high = n;
	int mid;
	double cdf_val;

	while (low <= high) {

		mid = (low + high) / 2;

		if (menu == 1) {

			cdf_val = gsl_cdf_binomial_P(mid, p, n);
			printf("%d %d %d %lf\n", low, high, mid, cdf_val);

			if (cdf_val < p_val)
				low = mid + 1;
			else if (cdf_val > p_val)
				high = mid - 1;
			else
				break;
		}
		else if (menu == 2) {

			cdf_val = gsl_cdf_binomial_Q(mid, p, n);
			printf("%d %d %d %lf\n", low, high, mid, cdf_val);

			if ((1 - cdf_val) < p_val)
				low = mid + 1;
			else if ((1 - cdf_val) > p_val)
				high = mid - 1;
			else
				break;
		}
	}

	k = (menu == 1) ? low : n - low;

	printf("SPSS>\n");
	printf("SPSS> The Result: %d\n", k);
	printf("SPSS>\n");

	return k;
}

float ICDF_Poisson_Distribution() {

	int menu;
	double mu, p_val;
	int k;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||             >>  (ICDF)  Poisson Distribution  <<             ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                  1) P(X <= k)                                ||\n");
	printf("||                  2) P(X > k) = 1 - P(X <= k)                 ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Poisson Distribution");

	menu = atoi(line);


	printf("SPSS> Please enter the average number of events: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Poisson Distribution");

	mu = atof(line);

	printf("SPSS> Please enter the p-value: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Poisson Distribution");

	p_val = atof(line);

	double cdf_val = 0.0;

	if (menu == 1) {

		for (k = 0; k <= 1000; k++) {
			cdf_val = gsl_cdf_poisson_P(k, mu);
			printf("%d %lf\n", k, cdf_val);

			if (cdf_val >= p_val)
				break;
		}
	}
	else if (menu == 2) {

		for (k = 0; k <= 1000; k++) {
			cdf_val = gsl_cdf_poisson_Q(k, mu);
			printf("%d %lf\n", k, cdf_val);

			if (cdf_val < p_val) {

				k--;
				break;
			}
		}
	}

	printf("SPSS>\n");
	printf("SPSS> The Result: %d\n", k);
	printf("SPSS>\n");

	return k;
}

float ICDF_Normal_Distribution() {

	int menu;
	double p_val, mu, sigma, z;
	double x;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||              >>  (ICDF) Normal Distribution  <<              ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                  1) P(X <= k)                                ||\n");
	printf("||                  2) P(X > k) = 1 - P(X <= k)                 ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Normal Distribution");

	menu = atoi(line);


	printf("SPSS> Please enter the mean: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Normal Distribution");

	mu = atof(line);

	printf("SPSS> Please enter the standard deviation: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Normal Distribution");

	sigma = atof(line);

	printf("SPSS> Please enter the p-value: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Normal Distribution");

	p_val = atof(line);

	double cdf_val;

	if (menu == 1)
		cdf_val = p_val;
	else if (menu == 2)
		cdf_val = 1 - p_val;

	z = gsl_cdf_gaussian_Pinv(cdf_val, 1.0);
	x = mu + z * sigma;

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", x);
	printf("SPSS>\n");

	return x;
}

float ICDF_Std_Norm_Distribution() {

	int menu;
	double p_val;
	double z;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||        >>  (ICDF)  Standard Normal Distribution  <<          ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                  1) P(X <= k)                                ||\n");
	printf("||                  2) P(X > k) = 1 - P(X <= k)                 ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Standard Normal Distribution");

	menu = atoi(line);


	printf("SPSS> Please enter the p-value: ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ICDF Standard Normal Distribution");

	p_val = atof(line);

	if (menu == 1)
		z = gsl_cdf_ugaussian_Pinv(p_val);
	else if (menu == 2)
		z = gsl_cdf_ugaussian_Qinv(p_val);

	printf("SPSS>\n");
	printf("SPSS> The Result: %lf\n", z);
	printf("SPSS>\n");

	return z;
}

int Interface_Input_Analysis() {

	int L2;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                       >>  ANALYSIS  <<                       ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||              1) Hypothesis Test for 1 Population             ||\n");
	printf("||              2) Hypothesis Test for 2 Population             ||\n");
	printf("||              3) 1 Way ANOVA Test                             ||\n");
	printf("||              4) 2 Way ANOVA Test                             ||\n");
	printf("||              5) Confidence Interval Calculation              ||\n");
	printf("||              0) Back to the Main Menu                        ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "analysis");

	L2 = atoi(line);

	while (L2 < 0 || L2 > 5) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "analysis");
		L2 = Interface_Input_Analysis();
	}

	return L2;
}

float H1_Confidence_Interval() {

	int size, dof;
	float alpha, s_mu, sigma, s_sigma;
	float range, z_val, t_val, lower_val, upper_val;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||           >>  Confidence Interval  Calculation  <<           ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");

	printf("SPSS> Please enter the sample size: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Confidence Interval Calculation");
	size = atoi(line);

	printf("SPSS> Please enter the sample mean: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Confidence Interval Calculation");
	s_mu = atof(line);

	printf("SPSS> Please enter the sigma(-1 if unknown): ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Confidence Interval Calculation");
	sigma = atof(line);

	if (sigma == -1) {

		printf("SPSS> Please enter the sample sigma: ");
		if (!(lineP = gets(line)))
			Error_Handler("Error: This command is not available", "H1 Confidence Interval Calculation");
		s_sigma = atof(line);
	}

	printf("SPSS> Please enter the alpha: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Confidence Interval Calculation");
	alpha = atof(line);


	if (size <= 30) {

		if (sigma != -1) {

			z_val = gsl_cdf_ugaussian_Pinv(1 - alpha / 2);
			range = z_val * (sigma / sqrt(size));
		}
		else {
			dof = size - 1;
			t_val = gsl_cdf_tdist_Pinv(1 - alpha / 2, dof);
			range = t_val * (s_sigma / sqrt(size));
		}
	}
	else {

		z_val = gsl_cdf_ugaussian_Pinv(1 - alpha / 2);
		range = z_val * (sigma != -1 ? sigma : s_sigma) / sqrt(size);
	}

	lower_val = s_mu - range;
	upper_val = s_mu + range;


	printf("SPSS>\n");
	printf("SPSS> The Confidence Interval: [%lf %lf]\n", lower_val, upper_val);

	return 0;
}

int Interface_Input_H1() {

	int L3;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||           >>  Hypothesis Test for 1 Population  <<           ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                        1) X Based                            ||\n");
	printf("||                        2) Z Based                            ||\n");
	printf("||                        3) P-value Based                      ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "Hypothesis Test for 1 population");

	L3 = atoi(line);

	while (L3 < 0 || L3 > 4) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "Hypothesis Test for 1 population");
		L3 = Interface_Input_H1();
	}

	return L3;
}

float H1_X_Based() {

	int size, side, res;
	float mu0, s_mu, sigma, alpha, Z_val;
	float C_val, C_lower, C_upper;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||               >>  X Based  Hypothesis Test  <<               ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");

	printf("SPSS> Please enter the mean of H0: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 X Based");
	mu0 = atof(line);

	printf("SPSS> Please enter the sample mean of H1: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 X Based");
	s_mu = atof(line);

	printf("SPSS> Please enter the sigma: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 X Based");
	sigma = atof(line);

	printf("SPSS> Please enter the sample size: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 X Based");
	size = atoi(line);

	printf("SPSS> Please enter the alpha: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 X Based");
	alpha = atof(line);

	printf("SPSS> Please enter the test side  1) Right-sided Test (H1: μ0 < μ1)\n");
	printf("                                  2) Left-sided Test (H1: μ0 > μ1)\n");
	printf("                                  3) Two-sided Test (H1: μ0 ≠ μ1)\n");
	printf("SPSS> ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 X Based");
	side = atoi(line);


	if (side == 1) {

		Z_val = gsl_cdf_ugaussian_Pinv(1 - alpha);
		C_val = mu0 + Z_val * (sigma / sqrt(size));

		printf("SPSS>\n");
		printf("SPSS> The Critical Value: %lf\n", C_val);

		res = (C_val < s_mu) ? 1 : 0;
	}
	else if (side == 2) {

		Z_val = gsl_cdf_ugaussian_Pinv(1 - alpha);
		C_val = mu0 - Z_val * (sigma / sqrt(size));
		
		printf("SPSS>\n");
		printf("SPSS> The Critical Value: %lf\n", C_val);

		res = (s_mu < C_val) ? 1 : 0;
	}
	else if (side == 3) {

		Z_val = gsl_cdf_ugaussian_Pinv(1 - alpha / 2);
		C_lower = mu0 - Z_val * (sigma / sqrt(size));
		C_upper = mu0 + Z_val * (sigma / sqrt(size));

		printf("SPSS>\n");
		printf("SPSS> The Critical Value: %lf %lf\n", C_lower, C_upper);

		res = (s_mu < C_lower || s_mu > C_upper) ? 1 : 0;
	}


	if (res == 1) {

		printf("SPSS>\n");
		printf("SPSS> The Result: H1\n");
		printf("SPSS> The Result: Reject the null hypothesis.\n");
		printf("SPSS>\n");
	}
	else {
		printf("SPSS>\n");
		printf("SPSS> The Result: H0\n");
		printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
		printf("SPSS>\n");
	}

	return 0;
}

float H1_Z_Based() {

	int size, side, res, dof;
	float mu0, s_mu, sigma, s_sigma, alpha;
	float Z_val, T_val, Z_stat, T_stat;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||               >>  Z Based  Hypothesis Test  <<               ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");

	printf("SPSS> Please enter the mean of H0: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Z Based");
	mu0 = atof(line);

	printf("SPSS> Please enter the sample mean of H1: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Z Based");
	s_mu = atof(line);

	printf("SPSS> Please enter the sigma(-1 if unknown): ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Z Based");
	sigma = atof(line);

	if (sigma == -1) {

		printf("SPSS> Please enter the sample sigma: ");
		if (!(lineP = gets(line)))
			Error_Handler("Error: This command is not available", "H1 Z Based");
		s_sigma = atof(line);
	}

	printf("SPSS> Please enter the sample size: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Z Based");
	size = atoi(line);

	printf("SPSS> Please enter the alpha: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Z Based");
	alpha = atof(line);

	printf("SPSS> Please enter the test side  1) Right-sided Test (H1: μ0 < μ1)\n");
	printf("                                  2) Left-sided Test (H1: μ0 > μ1)\n");
	printf("                                  3) Two-sided Test (H1: μ0 ≠ μ1)\n");
	printf("SPSS> ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 Z Based");
	side = atoi(line);


	if (sigma != -1) {

		Z_stat = (s_mu - mu0) / (sigma / sqrt(size));

		if (side == 1) {

			Z_val = gsl_cdf_ugaussian_Pinv(1 - alpha);

			printf("SPSS>\n");
			printf("SPSS> The Z Critical Value: %lf\n", Z_val);
			printf("SPSS> The Z Statistic: %lf\n", Z_stat);

			res = (Z_val < Z_stat) ? 1 : 0;
		}
		else if (side == 2) {

			Z_val = gsl_cdf_ugaussian_Pinv(1 - alpha);

			printf("SPSS>\n");
			printf("SPSS> The Z Critical Value: %lf\n", -Z_val);
			printf("SPSS> The Z Statistic: %lf\n", Z_stat);

			res = (Z_stat < -Z_val) ? 1 : 0;
		}
		else if (side == 3) {

			Z_val = gsl_cdf_ugaussian_Pinv(1 - alpha / 2);

			printf("SPSS>\n");
			printf("SPSS> The Z Critical Values: %lf, %lf\n", -Z_val, Z_val);
			printf("SPSS> The Z Statistic: %lf\n", Z_stat);

			res = (Z_stat < -Z_val || Z_val < Z_stat) ? 1 : 0;
		}
	}
	else if (sigma == -1 && size > 30) {

		Z_stat = (s_mu - mu0) / (s_sigma / sqrt(size));

		if (side == 1) {

			Z_val = gsl_cdf_ugaussian_Pinv(1 - alpha);

			printf("SPSS>\n");
			printf("SPSS> The Z Critical Value: %lf\n", Z_val);
			printf("SPSS> The Z Statistic: %lf\n", Z_stat);

			res = (Z_val < Z_stat) ? 1 : 0;
		}
		else if (side == 2) {

			Z_val = gsl_cdf_ugaussian_Pinv(1 - alpha);

			printf("SPSS>\n");
			printf("SPSS> The Z Critical Value: %lf\n", -Z_val);
			printf("SPSS> The Z Statistic: %lf\n", Z_stat);

			res = (Z_stat < -Z_val) ? 1 : 0;
		}
		else if (side == 3) {

			Z_val = gsl_cdf_ugaussian_Pinv(1 - alpha / 2);

			printf("SPSS>\n");
			printf("SPSS> The Z Critical Values: %lf, %lf\n", -Z_val, Z_val);
			printf("SPSS> The Z Statistic: %lf\n", Z_stat);

			res = (Z_stat < -Z_val || Z_val < Z_stat) ? 1 : 0;
		}
	}
	else if (sigma == -1 && size <= 30) {

		dof = size - 1;
		T_stat = (s_mu - mu0) / (s_sigma / sqrt(size));

		if (side == 1) {

			T_val = gsl_cdf_tdist_Qinv(1 - alpha, dof);

			printf("SPSS>\n");
			printf("SPSS> The T Critical Value: %lf\n", T_val);
			printf("SPSS> The T Statistic: %lf\n", T_stat);

			res = (T_val < T_stat) ? 1 : 0;
		}
		else if (side == 2) {

			T_val = gsl_cdf_tdist_Qinv(alpha, dof);

			printf("SPSS>\n");
			printf("SPSS> The T Critical Value: %lf\n", -T_val);
			printf("SPSS> The T Statistic: %lf\n", T_stat);

			res = (T_stat < -T_val) ? 1 : 0;
		}
		else if (side == 3) {

			T_val = gsl_cdf_tdist_Qinv(1 - alpha / 2, dof);

			printf("SPSS>\n");
			printf("SPSS> The T Critical Values: %lf, %lf\n", -T_val, T_val);
			printf("SPSS> The T Statistic: %lf\n", T_stat);

			res = (T_stat < -T_val || T_val < T_stat) ? 1 : 0;
		}
	}


	if (res == 1) {

		printf("SPSS>\n");
		printf("SPSS> The Result: H1\n");
		printf("SPSS> The Result: Reject the null hypothesis.\n");
		printf("SPSS>\n");
	}
	else {
		printf("SPSS>\n");
		printf("SPSS> The Result: H0\n");
		printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
		printf("SPSS>\n");
	}

	return 0;
}

float H1_P_Val_Based() {

	int size, side, dof;
	float mu0, s_mu, sigma, s_sigma, alpha;
	float Z_stat, T_stat;
	float p_val;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||            >>  P-value Based  Hypothesis Test  <<            ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");

	printf("SPSS> Please enter the mean of H0: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 P-value Based");
	mu0 = atof(line);

	printf("SPSS> Please enter the sample mean of H1: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 P-value Based");
	s_mu = atof(line);

	printf("SPSS> Please enter the sigma(-1 if unknown): ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 P-value Based");
	sigma = atof(line);

	if (sigma == -1) {

		printf("SPSS> Please enter the sample sigma: ");
		if (!(lineP = gets(line)))
			Error_Handler("Error: This command is not available", "H1 P-value Based");
		s_sigma = atof(line);
	}

	printf("SPSS> Please enter the sample size: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 P-value Based");
	size = atoi(line);

	printf("SPSS> Please enter the alpha: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 P-value Based");
	alpha = atof(line);

	printf("SPSS> Please enter the test side  1) Right-sided Test (H1: μ0 < μ1)\n");
	printf("                                  2) Left-sided Test (H1: μ0 > μ1)\n");
	printf("                                  3) Two-sided Test (H1: μ0 ≠ μ1)\n");
	printf("SPSS> ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H1 P-value Based");
	side = atoi(line);


	if (sigma != -1 || (sigma == -1 && size > 30)) {

		if (sigma != -1)
			Z_stat = (s_mu - mu0) / (sigma / sqrt(size));
		else if (sigma == -1 && size > 30)
			Z_stat = (s_mu - mu0) / (s_sigma / sqrt(size));

		if (side == 1)
			p_val = gsl_cdf_ugaussian_Q(Z_stat);
		else if (side == 2)
			p_val = 1 - gsl_cdf_ugaussian_Q(Z_stat);
		else if (side == 3)
			p_val = 2 * gsl_cdf_ugaussian_Q(fabs(Z_stat));

		printf("SPSS>\n");
		printf("SPSS> The Z Statistic: %lf\n", Z_stat);
	}
	else if (sigma == -1 && size <= 30) {

		dof = size - 1;
		T_stat = (s_mu - mu0) / (s_sigma / sqrt(size));

		if (side == 1) 
			p_val = gsl_cdf_tdist_Q(T_stat, dof);
		else if (side == 2)
			p_val = 1 - gsl_cdf_tdist_Q(T_stat, dof);
		else if (side == 3)
			p_val = 2 * gsl_cdf_tdist_Q(fabs(T_stat), dof);

		printf("SPSS>\n");
		printf("SPSS> The T Statistic: %lf\n", T_stat);
	}


	printf("SPSS> The P-value: %lf\n", p_val);


	if (p_val <= alpha) {

		printf("SPSS>\n");
		printf("SPSS> The Result: H1\n");
		printf("SPSS> The Result: Reject the null hypothesis.\n");
		printf("SPSS>\n");
	}
	else {
		printf("SPSS>\n");
		printf("SPSS> The Result: H0\n");
		printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
		printf("SPSS>\n");
	}

	return 0;
}

int Interface_Input_H2() {
	
	int L3;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||          >>  Hypothesis Test  for 2 Populations  <<          ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||              1) Compare Two Independent Samples              ||\n");
	printf("||              2) Compare Paired Samples                       ||\n");
	printf("||              3) Test for Two Sample Variances                ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "Hypothesis Test for 2 populations");

	L3 = atoi(line);

	while (L3 < 0 || L3 > 4) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "Hypothesis Test for 2 populations");
		L3 = Interface_Input_H2();
	}

	return L3;
}

int Interface_Independent() {

	int L4;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||           >>  Compare Two  Independent Samples  <<           ||\n");
	printf("||                                                              ||\n");
	printf("||     Please select the menu number you'd like to execute.     ||\n");
	printf("||                                                              ||\n");
	printf("||                                                              ||\n");
	printf("||                        1) X Based                            ||\n");
	printf("||                        2) Z Based                            ||\n");
	printf("||                        3) P-value Based                      ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("SPSS> ");

	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "Compare Two Independent Samples");

	L4 = atoi(line);

	while (L4 < 0 || L4 > 3) {

		printf("SPSS> ");
		Error_Handler("Error: This number is not available", "Compare Two Independent Samples");
		L4 = Interface_Independent();
	}

	return L4;
}

float H2_IS_X_Based() {

	int size1, size2, side;
	float mu1, mu2, sigma1, sigma2, D, alpha, C_lower, C_upper;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||               >>  X Based  Hypothesis Test  <<               ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");

	printf("SPSS> Please enter the mean of population 1: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H2 X Based");
	mu1 = atof(line);

	printf("SPSS> Please enter the sigma of population 1: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H2 X Based");
	sigma1 = atof(line);

	printf("SPSS> Please enter the sample size of population 1: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H2 X Based");
	size1 = atoi(line);

	printf("SPSS> Please enter the mean of population 2: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H2 X Based");
	mu2 = atof(line);

	printf("SPSS> Please enter the sigma of population 2: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H2 X Based");
	sigma2 = atof(line);

	printf("SPSS> Please enter the sample size of population 2: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H2 X Based");
	size2 = atoi(line);

	printf("SPSS> Please enter the alpha: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H2 X Based");
	alpha = atof(line);

	printf("SPSS> Please enter the test side  1) Right-sided Test (H1: μ0 < μ1)\n");
	printf("                                  2) Left-sided Test (H1: μ0 > μ1)\n");
	printf("                                  3) Two-sided Test (H1: μ0 ≠ μ1)\n");
	printf("SPSS> ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "H2 X Based");
	side = atoi(line);


	D = mu1 - mu2;

	float pooled_se = sqrt((sigma1 * sigma1 / size1) + (sigma2 * sigma2 / size2));
	
	if (side == 1) {  
		
		C_lower = mu2 + gsl_cdf_ugaussian_Pinv(1 - alpha) * pooled_se;
		
		printf("SPSS>\n");
		printf("SPSS> Critical Value: %.4f\n", C_lower);
		
		if (D > C_lower) {
			
			printf("SPSS>\n");
			printf("SPSS> The Result: H1\n");
			printf("SPSS> The Result: Reject the null hypothesis.\n");
			printf("SPSS>\n");
		}
		else {

			printf("SPSS>\n");
			printf("SPSS> The Result: H0\n");
			printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
			printf("SPSS>\n");
		}
	}
	else if (side == 2) {

		C_upper = mu2 + gsl_cdf_ugaussian_Pinv(alpha) * pooled_se;
		
		printf("SPSS>\n");
		printf("SPSS> Critical Value: %.4f\n", C_upper);
		
		if (D < C_upper) {

			printf("SPSS>\n");
			printf("SPSS> The Result: H1\n");
			printf("SPSS> The Result: Reject the null hypothesis.\n");
			printf("SPSS>\n");
		}
		else {
			
			printf("SPSS>\n");
			printf("SPSS> The Result: H0\n");
			printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
			printf("SPSS>\n");
		}
	}
	else if (side == 3) {

		C_lower = mu2 + gsl_cdf_ugaussian_Pinv(alpha / 2) * pooled_se;
		C_upper = mu2 + gsl_cdf_ugaussian_Pinv(1 - alpha / 2) * pooled_se;

		printf("SPSS>\n");
		printf("SPSS> Critical Values: %lf, %lf\n", C_lower, C_upper);

		if (D < C_lower || D > C_upper) {
			
			printf("SPSS>\n");
			printf("SPSS> The Result: H1\n");
			printf("SPSS> The Result: Reject the null hypothesis.\n");
			printf("SPSS>\n");
		}
		else {
			
			printf("SPSS>\n");
			printf("SPSS> The Result: H0\n");
			printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
			printf("SPSS>\n");
		}
	}

	return 0;
}

int Interface_Input_ANOVA1() {

	int level, repetition, total_size = 0;
	double alpha, total_mean = 0;
	double* means, * variances;
	double** data;
	double ss_A = 0, ss_E = 0, ss_T = 0;
	int dof_A, dof_E;
	//int dof_T;
	double ms_A, ms_E;
	double F_stat, p_val;

	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                   >>  1 Way ANOVA Test  <<                   ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	
	printf("SPSS> Please enter the level: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ANOVA1");
	level = atoi(line);

	printf("SPSS> Please enter the repetiton: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ANOVA1");
	repetition = atoi(line);

	data = (double**)malloc(level * sizeof(double*));
	means = (double *)malloc(level * sizeof(double));
	variances = (double *)malloc(level * sizeof(double));


	for (int i = 0; i < level; i++) {

		data[i] = (double*)malloc(repetition * sizeof(double));

		printf("SPSS> Please enter the results of level %d: ", i + 1);
		for (int j = 0; j < repetition; j++)
			scanf("%lf", &data[i][j]);

		means[i] = gsl_stats_mean(data[i], 1, repetition);
		variances[i] = gsl_stats_variance(data[i], 1, repetition);

		printf("SPSS>\n");

		total_mean += means[i] * repetition;
	}

	printf("SPSS> Please enter the alpha: ");
	if (scanf("%lf", &alpha) != 1)
		Error_Handler("Error: This command is not available", "ANOVA1");

	total_size = level * repetition;
	total_mean = total_mean / total_size;


	for (int i = 0; i < level; i++) {

		for (int j = 0; j < repetition; j++) {
			ss_T += pow(data[i][j] - total_mean, 2);
		}
	}
	for (int i = 0; i < level; i++) {
		ss_A += repetition * pow(means[i] - total_mean, 2);
	}
	for (int i = 0; i < level; i++) {
		ss_E += (repetition - 1) * variances[i];
	}


	dof_A = level - 1;
	dof_E = level * (repetition - 1);
	//dof_T = total_size - 1;

	ms_A = ss_A / dof_A;
	ms_E = ss_E / dof_E;

	F_stat = ms_A / ms_E;
	p_val = 1 - gsl_cdf_fdist_P(F_stat, dof_A, dof_E);


	printf("SPSS>\n");
	printf("SPSS> The F-statistic: %lf\n", F_stat);
	printf("SPSS> The p-value: %lf\n", p_val);

	if (p_val < alpha) {

		printf("SPSS>\n");
		printf("SPSS> The Result: H1\n");
		printf("SPSS> The Result: Reject the null hypothesis.\n");
		printf("SPSS>\n");
	}
	else {
		printf("SPSS>\n");
		printf("SPSS> The Result: H0\n");
		printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
		printf("SPSS>\n");
	}

	for (int i = 0; i < level; i++)
		free(data[i]);
	free(data);
	free(means);
	free(variances);


	return 0;
}

int Interface_Input_ANOVA2() {

	int level1, level2, repetition, total_size;
	double alpha;
	double*** data, * row_means, * col_means;
	double total_mean = 0, ss_A = 0, ss_B = 0, ss_AB = 0, ss_E = 0, ss_T = 0;
	double dof_A, dof_B, dof_AB, dof_E;
	//double dof_T;
	double ms_A, ms_B, ms_AB, ms_E;
	double F_A, F_B, F_AB, p_A, p_B, p_AB;
	
	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                   >>  2 Way ANOVA Test  <<                   ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");

	printf("SPSS> Please enter the level for factor 1: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ANOVA2");
	level1 = atoi(line);

	printf("SPSS> Please enter the level for factor 2: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ANOVA2");
	level2 = atoi(line);

	printf("SPSS> Please enter the the repetiton: ");
	if (!(lineP = gets(line)))
		Error_Handler("Error: This command is not available", "ANOVA2");
	repetition = atoi(line);
	

	data = (double***)malloc(level1 * sizeof(double**));
	row_means = (double*)calloc(level1, sizeof(double));
	col_means = (double*)calloc(level2, sizeof(double));

	if (!data || !row_means || !col_means)  // 메모리 할당 실패 여부 확인
		Error_Handler("Error: Failed to allocate memory", "ANOVA2");

	for (int i = 0; i < level1; i++) {

		data[i] = (double**)malloc(level2 * sizeof(double*));

		for (int j = 0; j < level2; j++) {

			data[i][j] = (double*)malloc(repetition * sizeof(double));

			printf("SPSS> Please enter the results for (Factor A)Level %d, (Factor B)Level %d: ", i + 1, j + 1);
			for (int k = 0; k < repetition; k++) {
				scanf("%lf", &data[i][j][k]);
			
				total_mean += data[i][j][k];
				row_means[i] += data[i][j][k];
				col_means[j] += data[i][j][k];
			}
		}

		printf("SPSS>\n");
	}

	printf("SPSS> Please enter the alpha: ");
	if (scanf("%lf", &alpha) != 1)
		Error_Handler("Error: This command is not available", "ANOVA2");

	total_size = level1 * level2 * repetition;
	total_mean /= total_size;
	
	for (int i = 0; i < level1; i++)
		row_means[i] /= (level2 * repetition);
	for (int j = 0; j < level2; j++)
		col_means[j] /= (level1 * repetition);


	for (int i = 0; i < level1; i++)
		ss_A += level2 * repetition * pow(row_means[i] - total_mean, 2);
	
	for (int j = 0; j < level2; j++)
		ss_B += level1 * repetition * pow(col_means[j] - total_mean, 2);

	for (int i = 0; i < level1; i++) {
		for (int j = 0; j < level2; j++) {

			double cell_mean = 0;

			for (int k = 0; k < repetition; k++) {
				
				cell_mean += data[i][j][k];
				
				ss_E += pow(data[i][j][k] - row_means[i] - col_means[j] + total_mean, 2);
				ss_T += pow(data[i][j][k] - total_mean, 2);
			}

			cell_mean /= repetition;
			ss_AB += repetition * pow(cell_mean - row_means[i] - col_means[j] + total_mean, 2);
		}
	}

	ss_E = ss_T - (ss_A + ss_B + ss_AB);
	if (ss_E < 0) ss_E = 0;

	dof_A = level1 - 1;
	dof_B = level2 - 1;
	dof_AB = dof_A * dof_B;
	dof_E = (level1 - 1) * (level2 - 1) * repetition;
	//dof_T = level1 * level2 * repetition - 1;

	ms_A = ss_A / dof_A;
	ms_B = ss_B / dof_B;
	ms_AB = ss_AB / dof_AB;
	ms_E = (dof_E > 0) ? (ss_E / dof_E) : 0;

	F_A = ms_A / ms_E;
	F_B = ms_B / ms_E;
	F_AB = ms_AB / ms_E;

	p_A = 1 - gsl_cdf_fdist_P(F_A, dof_A, dof_E);
	p_B = 1 - gsl_cdf_fdist_P(F_B, dof_B, dof_E);
	p_AB = 1 - gsl_cdf_fdist_P(F_AB, dof_AB, dof_E);


	if (repetition == 1) {

		printf("SPSS>\n");
		printf("SPSS> The F-statistic of Factor A : %lf\n", F_A);
		printf("SPSS> The F-statistic of Factor B : %lf\n", F_B);
		printf("SPSS> The p-value of Factor A: %lf\n", p_A);
		printf("SPSS> The p-value of Factor B: %lf\n", p_B);
	}
	else {

		printf("SPSS>\n");
		printf("SPSS> The F-statistic of Factor A : %lf\n", F_A);
		printf("SPSS> The F-statistic of Factor B : %lf\n", F_B);
		printf("SPSS> The F-statistic of Factor AB : %lf\n", F_AB);
		printf("SPSS> The p-value of Factor A: %lf\n", p_A);
		printf("SPSS> The p-value of Factor B: %lf\n", p_B);
		printf("SPSS> The p-value of Factor AB: %lf\n", p_AB);
	}


	if (p_A < alpha) {

		printf("SPSS>\n");
		printf("SPSS> [The result of Factor A]\n");
		printf("SPSS> The Result: H1\n");
		printf("SPSS> The Result: Reject the null hypothesis.\n");
		printf("SPSS>\n");
	}
	else {
		printf("SPSS>\n");
		printf("SPSS> [The result of Factor A]\n");
		printf("SPSS> The Result: H0\n");
		printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
		printf("SPSS>\n");
	}

	if (p_B < alpha) {

		printf("SPSS>\n");
		printf("SPSS> [The result of Factor B]\n");
		printf("SPSS> The Result: H1\n");
		printf("SPSS> The Result: Reject the null hypothesis.\n");
		printf("SPSS>\n");
	}
	else {
		printf("SPSS>\n");
		printf("SPSS> [The result of Factor B]\n");
		printf("SPSS> The Result: H0\n");
		printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
		printf("SPSS>\n");
	}

	if (repetition > 1) {

		if (p_AB < alpha) {

			printf("SPSS>\n");
			printf("SPSS> [The result of Factor AB]\n");
			printf("SPSS> The Result: H1\n");
			printf("SPSS> The Result: Reject the null hypothesis.\n");
			printf("SPSS>\n");
		}
		else {
			printf("SPSS>\n");
			printf("SPSS> [The result of Factor AB]\n");
			printf("SPSS> The Result: H0\n");
			printf("SPSS> The Result: Fail to reject the null hypothesis.\n");
			printf("SPSS>\n");
		}
	}


	for (int i = 0; i < level1; i++) {
		for (int j = 0; j < level2; j++)
			free(data[i][j]);
		
		free(data[i]);
	}
	free(data);
	free(row_means);
	free(col_means);

	return 0;
}