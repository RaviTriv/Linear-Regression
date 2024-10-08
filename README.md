## What is Linear Regression?

Linear regression is a technique used to find the relationship between a dependent variable and one or more independent variables.

In machine learning we often refer to a dependent variable as a label and an independent variable as a feature.

In simple linear regression our algebraic formula looks something like $y = mx + b$

For example, given a table which lists the number of bedrooms in a house and their listing price

| # Bedrooms in a house | Listing price |
| --------------------- | ------------- |
| 0                     | 1             |
| 1                     | 2             |
| 2                     | 3             |
| 3                     | 4             |
| 4                     | 5             |
| 5                     | 6             |
| 6                     | 7             |
| 7                     | 8             |
| 8                     | 9             |
| 9                     | 10            |

Plotted our table looks like this.

![Bedrooms and Prices Plot](/images/plot.png)

We can use our simple linear equation formula to make a model for this example. Our model looks something like the following.

$m = y2 - y1 / x2 - x1$ <br /> 
$m= 8 - 3 / 7 - 2$ <br />
$m= 5 / 5$ <br />
$m= 1$ <br />

$y = mx + b$ <br />
$9 = (1)(8) + b$ <br />
$9 - 8 = b$ <br />
$1 = b$ <br />

So our model will look like $y = 1(x) + 1$ <br />

![Line of Best Fit](/images/lineOfBestFit.png)

As you can see in this picture this model passes through all our points making it easy to predict the listing price of a house given the number of bedrooms.

## Simple Linear Regression Equation Formula

In Machine Learning we model Simple Linear Regression with the following formula,
$y=b_{0} + b_{1}X$

$y$ is our dependent variable. <br />
$b_{0}$ is our intercept. <br />
$b_{1}$ is our slope. <br />
$X$ is our independent variable. <br />

## Loss Function

Often our dataset won't have such a simple relationship, this is where calculating loss becomes important.
| x | y |
| - | - |
| 0 | 2 |
| 1 | 5 |
| 2 | 6 |
| 3 | 9 |
| 4 | 11 |
| 5 | 14 |
| 6 | 19 |
| 7 | 20 |
| 8 | 21 |
| 9 | 25 |

![Different Slopes](/images/differentSlopes.png)

In this plot we can see that our points are more scattered. There is not a single consistent increase between the points.

![Rough Model](/images/RoughLine.png)
A best fit line looks something like the following.

In situations like these measuring `Loss` is critical. Loss can be defined as the difference between the expected and recieved value. The purposing of training models is to reduce our loss to a minimal amount.

The formula we are using Mean Squared Error(MSE) looks like this <br />
$\frac{1}{N}\ \sum\_{}\(output - expected)^2 $

We can start by calculating MSE when our weight and bias are 0.

$Loss = {(2 - 0)^2 + (5 - 0)^2 + (6 - 0)^2 + (9 - 0)^2 + (11 - 0)^2 + (14 - 0)^2 + (19- 0)^2 + (20 - 0)^2 + (21 - 0)^2 + (25 - 0)^2 \over 10}$<br /> 
<br /> 
$Loss= {(4 + 25 + 36 + 81 + 121 + 196 + 361 + 400 + 441 + 625)\over 10}$<br /> 
<br /> 
$Loss= {(4 + 25 + 36 + 81 + 121 + 196 + 361 + 400 + 441 + 625)\over 10}$<br /> 
$Loss= 229$<br /> 


## Gradient Descent

Gradient Descent is a technique used to optimize our weight and bias values to get a minimal loss.

To do this, we want the slope of our loss function at different points.

We will calculate the derivative of our loss function with respect to weight and bias. 
<br />
$Loss = {(output - expected)^2 \over N }$ <br />
<br />
${((output)^2 + (expected)^2 - 2 * expected * output) \over N }$ <br />
<br />
${((w * x + b)^2 + (expected)^2 - 2 * expected * (w * x + b)) \over N }$ <br />
<br />
$((w * x + b)^2)\over N$ + $((expected)^2)\over N$ + $(-2 * expected * (w * x + b))\over N$ <br />
<br />
${(w)^2 * (x)^2 + (b)^2 + 2 * w * x * b\over N} + 0 +  {-2 * expected * x\over N}$ <br />
<br />
${2 * x * ( x * w + b - expected )\over N}$ <br />
The derivative of loss with respect to weight is <br>
${1\over N} \sum\_{i=1}^N{2 * x * ( output - expected )}$ <br />
Our derivative of loss with respect to bias is <br>
${1\over N} \sum\_{i=1}^N{2 * ( output - expected )}$ <br />

Using $weight=0$ and $bias=0$ we get a slope value of $-161$ and bias value of $-26.4$.

We can slightly adjust these values to generate a new weight.

Often the slight adjustment is referred to as the learning rate. In this case the learning rate is $0.01$.

$New Weight = oldWeight + (change * weightSlope)$ <br />
$New Weight = 0 - (0.01 * -161)$ <br />
$New Weight = 1.61$ <br />
$New Bias = 0 - (0.01 * -26.4)$ <br />
$New Bias = 0.264$ <br />

## Training the Model
Once we calculate loss, apply gradient descent we then update our output values with the new weight and bias. We repeat this process a number of times. This number is known as EPOCH. In this case our EPOCH value is $10000$.

Once our model is trained and we have optimal weight and bias we can attempt to calculate the output.
