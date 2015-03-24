#!/bin/bash
echo "Give first number:"
read a
echo "Give second number:"
read b
echo "Give the operand:"
read op
case $op in
    +) c=`expr $a + $b`;;
    -) c=`expr $a - $b`;;
    \*) c=`expr $a \* $b`;;
    /) c=`expr $a / $b`;;
esac
echo $c

