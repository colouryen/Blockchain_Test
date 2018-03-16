# Blockchain_test

These are the Klee tests on popular Blockchain codes.

Therefore, first, we have to setup Klee testing environment to test our targets.

A. Install Docker and Klee

    Details and files can be found here : https://klee.github.io/


B. Build up Bolckchain environment

    1. Get openssl
       $ cd /usr/local/src
       $ wget https://www.openssl.org/source/openssl-1.1.1-pre1.tar.gz

       $ tar -xzvf openssl-1.1.1-pre1.tar.gz
       $ cd openssl-1.1.1-pre1

    2. Install
       $ make
       $ make install

    3. Create a symbolic link to /usr/local/openssl
       $ sudo ln -s /openssl-1.1.1-pre1 /usr/local/openssl

    4. Shell
       $ echo 'export PATH=/usr/local/openssl/bin:$PATH' >> ~/.bash_profile
       $ echo 'export MANPATH=/usr/local/openssl/share/man:$MANPATH' >> ~/.bash_profile

    5. openssl version -a

    6. Modify test.sh to ...
       #!/bin/sh
       OPENSSL_INCLUDE=/usr/local/openssl/include/
       touch $1.c
       gcc $1.c -o $1.out -ansi -Wall -Wno-deprecated-declarations -Wno-long-long -I $OPENSSL_INCLUDE -pedantic -lcrypto
       ./$1.out

    7. Run simple Blockchain code
       ./test.sh file_name (without extension .c)
       ./all-tests.sh
       
       
After all these miscellaneous installations, we can start testing our targets.

Sample codes and tutorials can be found here : http://klee.github.io/tutorials/

     1. Use LLVM to compile:
        $ clang -I ../../include -emit-llvm -c -g FILE_NAME.c


     2. Run KLEE:
        we can just run default by input command line like this:
        $ klee FILE_NAME.bc
        
        Or, we can specify our limintations:
        --optimize         (use optimal)
        --libc=uclibc      (included library)
        -emit-all-errors   (do not terminate when errors occur)
        -max-time=180      (set max time out in sec)


     3. Output Data:
        After each run, we can check our data in folder (klee-last) and by using command "klee-stats" we can directly show them.
        $ klee-stats klee-last


     4. Show error message:
        Our results are saved in folder klee-last/
        
        By ktest-tool and specify "--write-ints", we can see which input value make bugs
        $ ktest-tool klee-last/test000222.ktest
          --write-ints
        
        Show an error returning layer by layer
        $ cat klee-last/test000001.ptr.err
        
     5. Replay the test case:
        $ export LD_LIBRARY_PATH=/home/klee/klee_build/klee/Release+Debug+Asserts/lib/:/home/klee/klee_build/klee/lib/:$LD_LIBRARY_PATH
        $ gcc testHashes.c -w -o a.out -ansi -Wall -Wno-deprecated-declarations -Wno-long-long -I /usr/local/openssl/include/ -pedantic -lcrypto -L /home/klee/klee_build/klee/lib/ -I ../../include/ -lkleeRuntest
        $ KTEST_FILE=klee-last/test000001.ktest ./a.out 
        $ echo $?
        $ 0


