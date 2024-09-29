#include <math.h>
#include <stdio.h>
double dataset[10][2] = {{0, 2}, {1, 5}, {2, 6}, {3, 9}, {4, 11}, {5, 14}, {6, 19}, {7, 20}, {8, 21}, {9, 25}};
double output[10][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
double weight = 0;
double bias = 0;
int EPOCH = 100;
int arrSize = sizeof(dataset) / sizeof(dataset[0]);

// Calculate Error
double MSE()
{
  double res = 0;
  for (int i = 0; i < arrSize; i++)
  {
    double temp = 0;
    temp = output[i][1] - dataset[i][1];
    res += pow(temp, 2);
  }
  res = res / (float)arrSize;
  printf("LOSS: %f\n", res);
  return res;
}

// Adjust Weights
void gradientDescent()
{
  double change = 0.01;
  double weightRes = 0;
  double biasRes = 0;
  for (int i = 0; i < arrSize; i++)
  {
    double weightTemp = 0;
    double biasTemp = 0;
    weightRes += (output[i][1] - dataset[i][1]) * 2 * i;
    biasRes += (output[i][1] - dataset[i][1]) * 2;
  }
  weightRes = weightRes / (float)arrSize;
  biasRes = biasRes / (float)arrSize;
  weight = weight - (change * weightRes);
  bias = bias - (change * biasRes);
}

//Update Output with new weights and bias
void calcOutput()
{
  for (int i = 0; i < arrSize; i++)
  {
    output[i][1] = weight * i + bias;
  }
}

int main()
{

  //Loop based on epoch
  for (int i = 0; i < EPOCH; i++)
  {
    MSE();
    gradientDescent();
    calcOutput();
  }
  printf("FINAL WEIGHT: %f\n", weight);
  printf("FINAL BIAS: %f\n", bias);

  return 0;
}