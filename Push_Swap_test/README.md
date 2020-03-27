# Description

A python script and a shell script to test if my push_swap sorts my Stack A correctly.

## What does it include

* A python script (random_generator.py) that  generates sequences of random integers using python's pseudorandom number generator function randint. 
* Saves each sequence of random numbers in a newline in the file "random_prng.txt"
* Then executes the shell script "test_script.sh" to test push_swap (& checker) with each sequence of these random integers


## Usage

There are two ways to use the tests for push_swap.

Method 1
Running the python script (which executes also the shell script at the same time) :
* Download the folder "Push_Swap_test" locally
* Copy the "push_swap" and "checker" executables in the same folder
* Open the terminal and move to your downloaded folder
* From this path run in the terminal the following command :
````
python3 random_generator.py
```

Method 2
Running the shell script separately from the python script :
1. Download the folder "Push_Swap_test" locally
2. Copy the "push_swap" and "checker" executables in your downloaded folder
3. Open the terminal and move to your downloaded folder
4. From this path run in the terminal the following command :
````
./test_script.sh random_prng.txt
```
* To produce new random numbers, comment line 33 from the python script
* In the terminal run the following command :
````
python3 random_generator.py
```
* Then repeat steps 1 - 4 
* You can also use your own file with your own unique sequences of random integers like this :
````
./test_script.sh your_own_file.txt
```
