#!/bin/bash
echo "simple calculator"
sum=0
i="y"
echo "enter first number"
read n1
echo "enter second number"
read n2
while [ $i = "y" ]
do
echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
echo "Enter choice"
read ch
case $ch in
1)sum=$(echo " $n1 + $n2" | bc -l)
echo "Addition is =" $sum;;
2)sum=$(echo "$n1 - $n2" | bc -l)
echo "Sub is =" $sum;;
3)sum=$(echo "$n1 * $n2" | bc -l)
echo "Mul is =" $sum;;
4)sum=$(echo "$n1 / $n2" | bc -l)
echo "div is =" $sum;;
*)echo "invalid choice"
esac
echo "Do you want to continue"
read i
if [ ${i,,} != "y" ]
then
exit
fi
