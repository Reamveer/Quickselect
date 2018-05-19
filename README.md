# Quickselect (Hoare's selection algorithm)
Example of Quickselect Algorithm in C++

Algorithm receives N pairs that contain objects and their values.  
Algorithm also accepts max sum value and the number of selected objects in a descending order list by their indexes.

At the output, the program lists the given objects in a sorted order

Example:  
In:  
6 - number of pairs
House 10  
Shop 4  
Bar 24  
Castle 12  
Park 5  
River 22  
40  - max sum value  
3 - number of objects you want to print  
2 4 3 - indexes of objects in ordered list  
Out:  
Castle Park NO

Strings are sorted according to their value (or the lexical order when the values are the same).  
If the number of all selected values is greater than the declared maximum value of the sum then the algorithm will write the word "NO" instead of the name of the object.
