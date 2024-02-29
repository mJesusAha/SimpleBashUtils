#!/bin/bash
#2.txt 3.txt 4.txt 5.txt test_1_cat.txt test_2_cat.txt test_3_cat.txt test_4_cat.txt test_5_cat.txt test_case_cat.txt
var1="1.txt 2.txt 3.txt"
adress="./a.out"
search="a"
search1="A"
search2="do"
search3="DO"
flag="e o i v c l n h s iv ic il ih is vc vl vn vh vs cn ch cs ln lh ls nh ov oc ol on oh os io"
for var in $flag
do 
        a=$(grep -$var $search $var1)
         b=$($adress -$var $search $var1)
        if [[ "$a" == "$b" ]]; then
        echo " $var $va- Равно!"
        else
        echo " $var $va- Не равно!"
  fi
done
for var in $flag
do 
        a=$(grep -$var $search1 $var1)
         b=$($adress -$var $search1 $var1)
        if [[ "$a" == "$b" ]]; then
        echo " $var $va- Равно!"
        else
        echo " $var $va- Не равно!"
  fi
done
for var in $flag
do 
        a=$(grep -$var $search2 $var1)
         b=$($adress -$var $search2 $var1)
        if [[ "$a" == "$b" ]]; then
        echo " $var $va- Равно!"
        else
        echo " $var $va- Не равно!"
  fi
done
for var in $flag
do 
        a=$(grep -$var $search3 $var1)
         b=$($adress -$var $search3 $var1)
        if [[ "$a" == "$b" ]]; then
        echo " $var $va- Равно!"
        else
        echo " $var $va- Не равно!"
  fi
done
for var in $flag
do 
        a=$(grep -$var $search3 $var1)
         b=$($adress -$var $search3 $var1)
        if [[ "$a" == "$b" ]]; then
        echo " $var $va- Равно!"
        else
        echo " $var $va- Не равно!"
  fi
done
 a=$(grep -e $search3 -e $search2 $var1)
         b=$($adress  -e $search3 -e $search2 $var1)
        if [[ "$a" == "$b" ]]; then
        echo " -e -e - Равно!"
        else
        echo " -e -e - Не равно!"
fi
        a=$(grep -f 3.txt -e $search2 $var1)
         b=$($adress -f 3.txt -e $search2 $var1)
        if [[ "$a" == "$b" ]]; then
        echo " -f -e - Равно!"
        else
        echo " -f -e - Не равно!"
fi
