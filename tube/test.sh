#!/bin/bash

### tests de pipe2

echo "===============test de pipe2============= " >> resultats.txt

echo "./pipe2 \"ls -1\" to  \"wc -l\" ">> resultats.txt
./pipe2 "ls -1" to "wc -l" >> resultats.txt
echo " ls -1 | wc -l" >> resultats.txt
ls -1 | wc -l >> resultats.txt

echo "./pipe2 ls to wc" >> resultats.txt
./pipe2 ls to wc >> resultats.txt
echo " ls  | wc " >> resultats.txt
ls | wc  >> resultats.txt

echo "./pipe2 ls to grep pipe2.c" >> resultats.txt
./pipe2 ls to "grep pipe2.c" >> resultats.txt
echo " ls  | grep pipe2.c" >> resultats.txt
ls  | grep pipe2.c >> resultats.txt

### tests de pipe3


echo "================test de pipe3============= " >> resultats.txt

echo "./pipe3 \"ls -l\" \"grep p\" \"wc -l\""  >> resultats.txt
./pipe3 "ls -l" to "grep p" to "wc -l"  >> resultats.txt
echo " ls -1 | grep p | wc -l" >> resultats.txt
ls -1 | grep p | wc -l >> resultats.txt

echo "./pipe3 \"ls -l\" \"grep a\" \"wc -l\""  >> resultats.txt
./pipe3 "ls -l" to "grep a" to "wc -l"  >> resultats.txt
echo " ls -1 | grep a | wc -l" >> resultats.txt
ls -1 | grep a | wc -l >> resultats.txt




### tests de pipen

echo "=================test de pipen============= " >> resultats.txt

echo "./pipen \"ls -1\" to  \"wc -l\" ">> resultats.txt
./pipen "ls -1" to "wc -l" >> resultats.txt
echo " ls -1 | wc -l" >> resultats.txt
ls -1 | wc -l >> resultats.txt

echo "./pipen ls to wc" >> resultats.txt
./pipen ls to wc >> resultats.txt
echo " ls  | wc " >> resultats.txt
ls | wc  >> resultats.txt

echo "./pipen ls to grep pipen.c" >> resultats.txt
./pipen ls to "grep pipen.c" >> resultats.txt
echo " ls  | grep pipe2.c" >> resultats.txt
ls  | grep pipen.c >> resultats.txt

echo "./pipen \"ls -l\" \"grep p\" \"wc -l\""  >> resultats.txt
./pipen "ls -1" to "grep p" to "wc -l"  >> resultats.txt
echo " ls -1 | grep p | wc -l" >> resultats.txt
ls -1 | grep p | wc -l >> resultats.txt

echo "./pipen \"ls -l\" \"grep a\" \"wc -l\""  >> resultats.txt
./pipen "ls -1" to "grep a" to "wc -l"  >> resultats.txt
echo " ls -1 | grep a | wc -l" >> resultats.txt
ls -1 | grep a | wc -l >> resultats.txt



