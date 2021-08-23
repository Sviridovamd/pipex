#!/bin/bash

echo "===============TEST 0==============="

echo "./pipex  "ls -l" "wc -l" outfile"
./pipex  "ls -l" "wc -l" outfile
cat outfile
rm -f outfile

echo "./pipex  infile "ls -l" "wc -l" outfile 123"
./pipex  infile "ls -l" "wc -l" outfile 123
cat outfile
rm -f outfile

echo "===============TEST 1==============="

echo "< infile ls -l | wc -l > outfile"
< infile ls -l | wc -l > outfile
cat outfile
echo "./pipex infile "ls -l" "wc -l" outfile"
./pipex infile "ls -l" "wc -l" outfile
cat outfile
rm -f outfile

echo "===============TEST 2==============="

echo "< infile grep | cat -e > outfile"
< infile grep | cat -e > outfile
cat outfile
echo "./pipex infile "grep " "wc -w" outfile"
./pipex infile "grep " "wc -w" outfile
cat outfile
rm -f outfile

echo "===============TEST 3==============="

echo "< infile grep a1 | wc -w > outfile"
< infile grep a1 | wc -w > outfile
cat outfile
echo "./pipex infile "grep a1" "wc -w" outfile"
./pipex infile "grep a1" "wc -w" outfile
cat outfile
rm -f outfile

echo "===============TEST 4==============="

echo "< infile ls -la | wc -w > outfile"
< infile ls -la | wc -w > outfile
cat outfile
echo "./pipex infile "ls -la" "wc -w" outfile"
./pipex infile "ls -la" "wc -w" outfile
cat outfile
rm -f outfile

echo "===============TEST 5==============="

echo "< infile grep 12 | cat fjbf > outfile"
< infile grep 12 | cat fjbf > outfile
cat outfile
echo "./pipex infile "grep 12" "cat fjbf" outfile"
./pipex infile "grep 12" "cat fjbf" outfile
cat outfile
rm -f outfile

echo "===============TEST 6==============="

echo "< infile ls -d | cat fjbf > outfile"
< infile ls -d | cat fjbf > outfile
cat outfile
echo "./pipex infile "ls -d" "cat fjbf" outfile"
./pipex infile "ls -d" "cat fjbf" outfile
cat outfile
rm -f outfile

