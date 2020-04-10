# Push_Swap
Project Push Swap from Codam College (42 network)

## Compiling
- Clone the repository
- Compile the project with one of the following commands :
> make re  
> make

## Usage
Run the push_swap executable with a random list of numbers like shown below :
>./push_swap 34 99 -55 0 123
When finished, it prints a list of all operations that were executed to sort the list

Run the checker executable with a list of numbers, eg. 1 2 3 4 5 with the following command :
>./checker 1 2 3 4 5 
Then it expects user input of one of the valid stack operations (sa, sb, ss, pa, pb, ra, rb, etc.)
When no other operation is needed, Ctrl-D.
And it shows OK/KO if the stack was sorted/not respectively.

You can also run push_swap and checker together :
>./push_swap 22 -5 0 123 9 | ./checker 22 -5 0 123 9

Extra options
Some extra options can be used :
- n : prints the number of operations executed
- v : prints the stack after each operation
- u : prints the usage

