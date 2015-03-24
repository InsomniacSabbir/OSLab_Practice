#! /bin/sh
w=0
cc=0
for i in `cat $1`
do 
   j=$i;
   echo $j
   w=`expr $w + 1`
   c = `expr "$i" : "*"`
   cc = `expr $cc + $c`
done
echo " no. of char " $cc
echo " no. of word " $w
