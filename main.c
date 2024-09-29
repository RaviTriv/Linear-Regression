#include <math.h>
#include <stdio.h>
double dataset[10][2] = {{0, 2}, {1, 5}, {2, 6}, {3, 9}, {4, 11}, {5, 14}, {6, 19}, {7, 20}, {8, 21}, {9, 25}};
double output[10][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
double weight = 0;
double bias = 0;
// Function to calculate Mean Squared Error
double MSE()
{
  double res = 0;
  for (int i = 0; i < 10; i++)
  {
    double temp = 0;
    temp = output[i][1] - dataset[i][1];
    res += pow(temp, 2);
  }
  res = res / (float)10;
  printf("LOSS: %f\n", res);
  return res;
}

void gradientDescent()
{
  double change = 0.01;
  double weightRes = 0;
  double biasRes = 0;
  for (int i = 0; i < 10; i++)
  {
    double weightTemp = 0;
    double biasTemp = 0;
    weightRes += (output[i][1] - dataset[i][1]) * 2 * i;
    biasRes += (output[i][1] - dataset[i][1]) * 2;
  }
  weightRes = weightRes / (float)10;
  biasRes = biasRes / (float)10;
  weight = weight - (change * weightRes);
  bias = bias - (change * biasRes);
}

void calcOutput()
{
  for (int i = 0; i < 10; i++)
  {
    output[i][1] = weight * i + bias;
  }
}

int main()
{
  for (int i = 0; i < 10; i++)
  {
    MSE();
    gradientDescent();
    calcOutput();
  }
  printf("WEIGHT: %f\n", weight);
  printf("BIAS: %f\n", bias);

  return 0;
}