# Linear-Regression

### What is Linear Regression?

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

$m = y2 - y1 / x2 - x1$
$m= 8 - 3 / 7 - 2$
$m= 5 / 5$
$m= 1$

$y = mx + b$
$9 = (1)(8) + b$
$9 - 8 = b$
$1 = b$

So our model will look like $y = 1(x) + 1$

![Line of Best Fit](/images/lineOfBestFit.png)

As you can see in this picture this model passes through all our points making it easy to predict the listing price of a house given the number of bedrooms.

## Simple Linear Regression Equation Formula

In Machine Learning we model Simple Linear Regression with the following formula,
$y=b_{0} + b_{1}X$

$y$ is our dependent variable.
$b_{0}$ is our intercept.
$b_{1}$ is our slope.
$X$ is our independent variable.

## Loss Function

Often our model will not pass exactly through all our points given a more complicated data set.
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

The formula we are using Mean Squared Error(MSE) looks something like
$\frac{1}{N}\ \sum\_{}\(output - expected)^2 $

We can start by calculating MSE when our `weight` and `bias` is 0.

$Loss = {(2 - 0)^2 + (5 - 0)^2 + (6 - 0)^2 + (9 - 0)^2 + (11 - 0)^2 + (14 - 0)^2 + (19- 0)^2 + (20 - 0)^2 + (21 - 0)^2 + (25 - 0)^2 \over 10}$<br /> 
<br /> 
$Loss= {(4 + 25 + 36 + 81 + 121 + 196 + 361 + 400 + 441 + 625)\over 10}$<br /> 
<br /> 
$Loss= {(4 + 25 + 36 + 81 + 121 + 196 + 361 + 400 + 441 + 625)\over 10}$<br /> 
$Loss= 229$<br /> 

Now we want to calculate the derivative of our loss function with respect to weight. 
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
Therefore the derivative of loss with respect to w is <br>
${2 * x * ( output - expected )\over N}$ <br />
Our derivative of loss with respect to b is <br>
${2 * ( output - expected )\over N}$ <br />




$y=b_{0} + b_{1}X$<br /> 
$y=2.1 + b_{1}X$<br /> 
$y=2.1 + 2.5X$

| x   | recieved y | expected y |
| --- | ---------- | ---------- |
| 0   | 2.1        | 2          |
| 1   | 4.6        | 5          |
| 2   | 7.1        | 6          |
| 3   | 9.6        | 9          |
| 4   | 12.1       | 11         |
| 5   | 14.6       | 14         |
| 6   | 17.1       | 19         |
| 7   | 19.6       | 20         |
| 8   | 22.4       | 21         |
| 9   | 24.6       | 25         |

$\frac{1}{N}\ \sum\_{}\(expected - output)^2 $

Plugging these numbers in we see our MSE is $0.36$

## Gradient Descent

Gradient Descent is a technique used to optimize our weight and bias values to get a minimal loss.
