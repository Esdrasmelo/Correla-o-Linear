#include <stdio.h>
#include <math.h>

double sumNumbers(double *y_Numbers, double *x_Numbers, double *sum_Y_Numbers, double *sum_X_Numbers, int numberOfInputs);
double sumPowNumbers(double *y_Numbers, double *x_Numbers, double *sum_Y_PowNumbers, double *sum_X_PowNumbers, int numberOfInputs);
double sumXYNumbers(double *y_Numbers, double *x_Numbers, double *sum_XY_Numbers, int numberOfInputs);
double calculate_R_Value(int numberOfValues, double XY_Sum,  double X_Sum, double Y_Sum, double X_Pow_Sum, double Y_Pow_Sum);

int main(void)
{
	int numberOfInputs = 0, index = 0;
	
	printf("\nDigite a quantidade de numeros que serão digitados: ");
	scanf("%d", &numberOfInputs);
	
	double inputNumber = 0, y_Numbers[numberOfInputs], x_Numbers[numberOfInputs], 
	sumOf_Y_Numbers = 0, sumOf_X_Numbers = 0, sumOf_X_PowNumbers = 0, sumOf_Y_PowNumbers = 0, sumOf_XY_Numbers = 0;;
	
	printf("\n---- ENTRADA DE NUMEROS DO EIXO X ----");
	for (index; index < numberOfInputs; index++)
	{		
		printf("\n\nDigite o %d° numero do eixo X: ", index + 1);
		scanf("%lf", &inputNumber);	

		x_Numbers[index] = inputNumber;	
	}
		
	printf("\n---- ENTRADA DE NUMEROS DO EIXO Y ----");
	for (index = 0; index < numberOfInputs; index++)
	{
		printf("\n\nDigite o %d° numero do eixo Y: ", index + 1);
		scanf("%lf", &inputNumber);	
		
		y_Numbers[index] = inputNumber;
	}
		
	sumNumbers(y_Numbers, x_Numbers, &sumOf_Y_Numbers, &sumOf_X_Numbers, numberOfInputs);
	sumPowNumbers(y_Numbers, x_Numbers, &sumOf_Y_PowNumbers, &sumOf_X_PowNumbers, numberOfInputs);
	sumXYNumbers(y_Numbers, x_Numbers, &sumOf_XY_Numbers, numberOfInputs);
	
	double R_Value = calculate_R_Value(numberOfInputs, sumOf_XY_Numbers, sumOf_X_Numbers, sumOf_Y_Numbers, sumOf_X_PowNumbers, sumOf_Y_PowNumbers);
	
	printf("\n\n=== SOMATORIA DE X: %.2lf", sumOf_X_Numbers);
	printf("\n=== SOMATORIA DE Y: %.2lf", sumOf_Y_Numbers);
	printf("\n=== SOMATORIA DE X²: %.2lf", sumOf_X_PowNumbers);
	printf("\n=== SOMATORIA DE Y²: %.2lf", sumOf_Y_PowNumbers);
	printf("\n=== SOMATORIA DE X x Y: %.2lf", sumOf_XY_Numbers);
	printf("\n\n=== VALOR DE R: %lf", R_Value);
	
	if (R_Value >= 0.6&& R_Value <= 1) printf("\n=== CLASSIFICAÇÃO: Correlação relativamente forte.");
	else if (R_Value >= 0.3 && R_Value < 0.6)  printf("\n=== CLASSIFICAÇÃO: Correlação relativamente fraca.");
	else  printf("\n=== CLASSIFICAÇÃO: Correlação relativamente muito fraca.\n");

	return 0;
}

double sumNumbers(double *y_Numbers, double *x_Numbers, double *Y_Sum, double *X_Sum, int numberOfValues)
{
	for (int index = 0; index < numberOfValues; index++)
	{
		*Y_Sum += y_Numbers[index];
		*X_Sum += x_Numbers[index];
	}
}

double sumPowNumbers(double *y_Numbers, double *x_Numbers, double *Y_Pow_Sum, double *X_Pow_Sum, int numberOfValues)
{
	for (int index = 0; index < numberOfValues; index++)
	{
		*Y_Pow_Sum += pow(y_Numbers[index], 2);
		*X_Pow_Sum += pow(x_Numbers[index], 2);
	}
}

double sumXYNumbers(double *y_Numbers, double *x_Numbers, double *XY_Sum, int numberOfValues)
{
	for (int index = 0; index < numberOfValues; index++)
		*XY_Sum += x_Numbers[index] * y_Numbers[index];
}

double calculate_R_Value(int numberOfValues, double XY_Sum,  double X_Sum, double Y_Sum, double X_Pow_Sum, double Y_Pow_Sum)
{
	double numeratorValue = numberOfValues * XY_Sum - X_Sum * Y_Sum;
	double leftSideValueOfDenominator = numberOfValues * X_Pow_Sum - pow(X_Sum, 2);
	double rightSideValueOfDenominator = numberOfValues * Y_Pow_Sum - pow(Y_Sum, 2);
	double denominatorValue = pow((leftSideValueOfDenominator * rightSideValueOfDenominator), 0.5);
	
	double R_Value = numeratorValue / denominatorValue;
	
	return R_Value;
}