#!/bin/sh
export LD_LIBRARY_PATH=/home/klee/klee_build/klee/Release+Debug+Asserts/lib/:/home/klee/klee_build/klee/lib/:$LD_LIBRARY_PATH
gcc testTXB.c -w -o a.out -ansi -Wall -Wno-deprecated-declarations -Wno-long-long -I /usr/local/openssl/include/ -pedantic -lcrypto -L /home/klee/klee_build/klee/lib/ -I ../../include/ -lkleeRuntest

echo "\n"
echo "\n"
echo "\n"
sleep 2
echo "Replaying the test case..."
echo ""
echo ""
KTEST_FILE=klee-last/test000002.ktest ./a.out 
echo $?

cat klee-last/test000002.ptr.err

echo "\n"
echo "\n"
echo "\n"
sleep 2
echo "Replaying the test case..."
echo ""
echo ""
KTEST_FILE=klee-last/test000003.ktest ./a.out
echo $?

cat klee-last/test000003.ptr.err