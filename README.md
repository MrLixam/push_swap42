# push_swap42
My repo while doing the pushswap project of 42School


# Usage
just use `make` to get the main executable
there also is a `make bonus` to get a checker

`push_swap` will generate a list instructions to sort list passed if it fits the criteria (is an integer, no repeated integers)

# supported syntax for passing a list of integers
```
./push_swap "ARG1 ARG2 ARG3 ..
./push_swap ARG1 ARG2 ARG3 ..
./push_swap "ARG1 ARG2 ARG3" ARG4 "ARG5" .. -> you can mix and match single args and strings containing multiple args as you wish
```
# checker usage

to use `checker` on `push_swap`, you must pipe the result of `push_swap` into `checker` as follows :

```./push_swap YOUR_LIST | ./checker YOUR_LIST```

`OK` means the list is sorted

`KO` means the list isn't sorted

`Error` Means your args have a problem
