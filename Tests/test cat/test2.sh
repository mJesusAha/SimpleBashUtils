#!/bin/bash
#2.txt 3.txt 4.txt 5.txt test_1_cat.txt test_2_cat.txt test_3_cat.txt test_4_cat.txt test_5_cat.txt test_case_cat.txt
var1="2.txt 3.txt 4.txt 5.txt test_1_cat.txt test_2_cat.txt test_3_cat.txt test_4_cat.txt test_5_cat.txt test_case_cat.txt"
adress="./a.out"
for var in b e n s t v be ne se te ve tb tn ts tv bn bs bv ns nt nv sv 
do 
for va in b e n s t v be ne se te ve tb tn ts tv bn bs bv ns nt nv sv
do  
        a=$(cat -$var -$va $var1)
         b=$($adress -$var -$va $var1)
        if [[ "$a" == "$b" ]]; then
        echo " $var $va- Равно!"
        else
        echo " $var $va- Не равно!"
  fi
done
done
for va in b e n s t v
do  
        a=$(cat -$var -$va $var1)
         b=$($adress -$var -$va $var1)
        if [[ "$a" == "$b" ]]; then
        echo " $var $va- Равно!"
        else
        echo " $var $va- Не равно!"
  fi
done