#!/bin/bash
function test_flag_l {
  a=$(grep -l 1.txt 2.txt)
  b=$(./a.out -l 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo "-l 1.txt 2.txt"
    echo "test_flag_l -       Равно!"
  else
    echo "-l 1.txt 2.txt"
    echo "test_flag_l -       Не равно!"
  fi
}
function test_flag_c {
  a=$(grep -c do 1.txt 2.txt)
  b=$(./a.out -c do 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo "-c do 1.txt 2.txt"
    echo "test_flag_c -       Равно!"
  else
    echo "-c do 1.txt 2.txt"
    echo "test_flag_c -       Не равно!"
  fi
}
function test_flag_f {
  a=$(grep -f 1.txt 2.txt)
  b=$(./a.out -f 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo "-f 1.txt 2.txt"
    echo "test_flag_f -       Равно!"
  else
    echo "-f 1.txt 2.txt"
    echo "test_flag_f -       Не равно!"
  fi
}


function test_flag_e {
  a=$(grep -e 1.txt 1.txt 2.txt)
  b=$(./a.out -e 1.txt 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo "-e 1.txt 1.txt 2.txt"
    echo "test_flag_e -       Равно!"
  else
    echo "-e 1.txt 1.txt 2.txt"
    echo "test_flag_e -       Не равно!"
  fi
}
function test_flag_i {
  a=$(grep -i do 1.txt 2.txt)
  b=$(./a.out -i do 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo "-i do 1.txt 2.txt"
    echo "test_flag_i -       Равно!"
  else
    echo "-i do 1.txt 2.txt"
    echo "test_flag_i -       Не равно!"
  fi
}
function test_flag_n {
  a=$(grep -n do 1.txt 2.txt)
  b=$(./a.out -n do 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo "-n do 1.txt 2.txt"
    echo "test_flag_n -       Равно!"
  else
    echo "-n do 1.txt 2.txt"
    echo "test_flag_n -       Не равно!"
  fi
}
function test_flag_s {
  a=$(grep -s do 1.txt 2.txt)
  b=$(./a.out -s do 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo "-s do 1.txt 2.txt"
    echo "test_flag_s -       Равно!"
  else
    echo "-s do 1.txt 2.txt"
    echo "test_flag_s -       Не равно!"
  fi
}
function test_flag_h {
  a=$(grep -h do 1.txt 2.txt)
  b=$(./a.out -h do 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo "-h do 1.txt 2.txt"
    echo "test_flag_h -       Равно!"
  else
    echo "-h do 1.txt 2.txt"
    echo "test_flag_h -       Не равно!"
  fi
}
function test_flag_o {
  a=$(grep -o do 1.txt 2.txt)
  b=$(./a.out -o do 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo "-o do 1.txt 2.txt"
    echo "test_flag_o -       Равно!"
  else
    echo "-o do 1.txt 2.txt"
    echo "test_flag_o -       Не равно!"
  fi
}
function test_flag_vns {
  a=$(grep  -vns do 1.txt 2.txt)
  b=$(./a.out  -vns do 1.txt 2.txt)
  if [[ "$a" == "$b" ]]; then
    echo " -vns do 1.txt 2.txt - Равно!"
  else
    echo " -vns do 1.txt 2.txt - Не равно!"
  fi
}
function test_flag_ncif {
  a=$(grep  -ncif 1.txt 2.txt 1.txt)
  b=$(./a.out  -ncif 1.txt 2.txt 1.txt)
  if [[ "$a" == "$b" ]]; then
    echo " -ncif 1.txt 2.txt 1.txt - Равно!"
  else
    echo " -ncif 1.txt 2.txt 1.txt - Не равно!"
  fi
}
test_flag_f
test_flag_c
test_flag_s 
test_flag_l
test_flag_h
test_flag_e
test_flag_i
test_flag_n
test_flag_o
test_flag_ncif
test_flag_vns
# chmod +x test.sh
# ./test.sh   
