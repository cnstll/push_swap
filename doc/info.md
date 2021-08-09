## Linear Time Sorting
* comparison model
* lower bounds
   * searching: O(log(n))
   * sorting: O(nlog(n))
* O(n) sorting algorithms (linear-time)
   * counting sort
   * radix sort

### Comparison model
* all input items are considered as black boxes or "Abstract Data Type"
* only operations allowed are comparisons (>, <=, >=, <, =) 
* the time cost of these models is the number of comparisons
* Examples: binary search tree / merge sort /  heap sort / quick sort

### lower bounds (Demo with binary trees)
* Searching algorithm always take at least O(log(n)) to complete - even if preprocessed
* Sorting algorithm always take at least O(nlog(n))  to complete

### Sorting in linear time (Integer sorting) - O(n)
Sorting in linear is possible when you have a few number of items to sort
* counting sort
* radix sort

### Time Complexity ?
Time complexity is a measure of the time or the number of step taken by an algorithm to solve a problem (sorting, searching, etc.). The steps can be ram memory used, number of comparisons int he case of sorting algorithm.
Time complexity is used when studying algorithm complexity theory as well as space complexity.
The worst-case time complexity is commonly used to represent the maximum amount of time an algorithm can take to complete for inputs of a given size. Usually, time complexity is determined for an infinite number of inputs. In other words, the asymptomatic behaviour of the algorithm is studied (n, nlogn, n^a ,2^n...).
The Big O Landau notation is used to represent the asymptomatic behaviour of the algorithm such as O(n) or O(nlogn). This notation helps classify algorithm and assess their efficiency. Thus, algorithm complexity can be of constant time, logarithmic time, linear time, polynomial time, exponential time..

### Sorting Algorithm classification
Sorting algorithm can be classified using different criteria:
* Time complexity (Worst, best, average cases).
* Space complexity or memory usage
* Stability, the relative order of appearance of records are maintained whenever they have equal keys. Stable algorithms are used whenever you have a primary key and a secondary key. When sorting integers or if each element is different, stability is not an issue (merge sort is stable while quicksort isn't)
*  Comparison based or not
* General method used to sort the elements: insertion, exchange, selection, merging, partitioning. etc.
### Sorting algorithms, different methods

* Quicksort: quicksort is a divide and conquer algorithm which partition the list using a pivot (first, last number or median) and put the lowest elements on the left of the pivot, the highest elements on the right of the pivot. In most cases, time complexity is O(n logn) though if the pivot is chosen as the first/last element, time complexity can be O(n^2) when the list is already ordered. Space complexity is O(log n) in avg., O(n) in worst case.
![alter][260px-Sorting_quicksort_anim.gif]
* Merge sort: merge sort is a stable, merging, comparison based, divide and conquer algorithm. The general idea is to divide the list in n sublists of 1 element and then reassemble sublists by comparing and ordering elements creating sorted lists, until there is only one list.
![alter][220px-Merge-sort-example-300px.gif]
* Bubble sort: an exchanging, comparison-sort algorithm that sorts lists by repeatedly comparing and swaping adjacent numbers.
![alter][Bubble-sort-example-300px.gif]
* Radix sort: radix-sort is a a non-comparative sorting algorithm. It distributes elements into bucket according to their radix. For each digit, the elements are repeatedly distributed in the corresponding radix bucket while the ordering of the prior step is preserved. Time complexity in worst-case is O(w.n) with n being the number of keys to sort and w being the key length.
