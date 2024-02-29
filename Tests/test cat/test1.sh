#!/bin/bash
var1="1.txt 2.txt 3.txt 4.txt 5.txt test_1_cat.txt test_2_cat.txt test_3_cat.txt test_4_cat.txt test_5_cat.txt test_case_cat.txt"
adress="./a.out"

function test_no_flag {
  a=$(cat $var1)
  b=$($adress $var1)
  if [[ "$a" == "$b" ]]; then
    echo "  - Равно!"
  else
    echo " - Не равно!"
  fi
}
function test_flag_b {
  a=$(cat -b $var1)
  b=$($adress -b $var1)
  if [[ "$a" == "$b" ]]; then
    echo " -b $var1 - Равно!"
  else
    echo " -b $var1 - Не равно!"
  fi
}
function test_flag_e {
  a=$(cat -ev $var1)
  b=$($adress -e $var1)
  if [[ "$a" == "$b" ]]; then
    echo " -e $var1 - Равно!"
  else
    echo " -e $var1- Не равно!"
  fi
}
function test_flag_n {
  a=$(cat -n $var1)
  b=$($adress -n $var1)
  if [[ "$a" == "$b" ]]; then
    echo " -n $var1- Равно!"
  else
    echo " -n $var1- Не равно!"
  fi
}
function test_flag_s {
  a=$(cat -s $var1)
  b=$($adress -s $var1)
  if [[ "$a" == "$b" ]]; then
    echo " -s $var1 - Равно!"
  else
    echo " -s $var1 - Не равно!"
  fi
}
function test_flag_t {
  a=$(cat -t $var1)
  b=$($adress -t $var1)
  if [[ "$a" == "$b" ]]; then
    echo " -tv $var1- Равно!"
  else
    echo " -t $var1- Не равно!"
  fi
}
function test_flag_bn {
  a=$(cat -bn $var1)
  b=$($adress -bn $var1)
  if [[ "$a" == "$b" ]]; then
    echo " -bn $var1 - Равно!"
  else
    echo " -bn $var1 - Не равно!"
  fi
}
function test_flag_se {
  a=$(cat -s -e $var1)
  b=$($adress -s -e $var1)
  if [[ "$a" == "$b" ]]; then
    echo " -se $var1 - Равно!"
  else
    echo " -se $var1 - Не равно!"
  fi
}
test_no_flag
test_flag_b
test_flag_e
test_flag_n
test_flag_s
test_flag_t
test_flag_bn
test_flag_se
# chmod +x test1.sh
# ./test1.sh   
