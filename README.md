<img src='https://sigarra.up.pt/feup/pt/imagens/LogotipoSI' width="30%"/>

<div align="center">
🌍 <a href="README.md">English</a> | 🇵🇹 <a href="README.pt.md">Português</a>
</div>

<h3 align="center">BSc in Informatics and Computing Engineering<br> L.EIC016 - Algorithm Design<br> 2024/2025 </h3>

---
<h3 align="center"> Collaborators &#129309 </h2>

<div align="center">

| Name          | Number      |
|---------------|-------------|
| Bárbara Gomes | up202305089 |
| Tomás Morais  | up202304692 |
| Tomás Silva   | up202307796 |

Grade : 15,6

</div>

# Delivery Truck Pallet Packing Optimization Tool Report

## Class Diagram

<div align="center">
<img width="1694" height="786" alt="Captura de ecrã de 2025-09-23 23-04-24" src="https://github.com/user-attachments/assets/77e01a75-7744-461c-88da-635eceafa60e" />
</div>

## User Interface

- When starting the program, it will be displayed to the
user a menu with the options “Exit”, which will
terminate the program and “Select Data Files”;

- If the second option is selected, all available “Data
Files” (those in the same directory as the source code)
will be displayed for the user to select;

- After selecting the ﬁles, it will be shown the algorithmic
approaches to solving the problem, for the user to
choose between them, being also present an option to
go back to the “Select Data Files” section;

- After performing the algorithm, the solution will be
displayed to the user (including the associated total
proﬁt) and an option for processing another dataset;

## Reading the DataSet

After the selection of the ﬁles to process:

- pair<vector<int>, vector<int>> extractPalletValues(const
string& palletsFileName) opens and reads every line reads
each line of the “Pallets” ﬁle extracting each pallet’ weight
and proﬁt and inserting those in vectors weights and
proﬁts respectively, which in the end are returned inside a
pair in order to be used by other functions;

- int extractTruckCapacity(const string& truckFileName)
extracts and returns the truck’s maximum weight capacity,
which is written in the corresponding “Truck” ﬁle.

## Programming Approaches

### Brute-Force (Exhaustive)

- The program iterates through all subsets of the given
items

- For each subset, calculates the total weight and proﬁt
  
- If a subset's total weight is within the allowed capacity
and its proﬁt is greater than the current best, it updates
the best subset

- Outputs the indices, weights, and proﬁts of the
selected items in the best subset and the maximum
total proﬁt achievable without exceeding the capacity

**Time Complexity:** O (n 2^n)

**Space Complexity:** O (n)

**Data Structures:** The brute force function receives 2
vectors (proﬁt and weight) and an
integer (maximum capacity).
The output function receives the same
2 vectors, plus a vector of indices
representing the items selected in the
best subset and an integer representing

### Dynamic Programming

#### Greedy Algorithm A

Sort pallets by increasing order of their
weight-to-proﬁt ratio and, then, pick the pallets while
they not surpass the truck´s maximum weight capacity

#### Greedy Algorithm B

Sort pallets by increasing order of their proﬁts
and, next, pick the pallets while they still ﬁt in the truck

#### Approximation Algorithm

The two greedy approaches are not optimal, so we
choose from the total proﬁt

**Time Complexity:** O (n log n)

**Space Complexity:** O (n)

**Data Structures:** Each Greedy Approach returns a
pair with a vector of the selected
items and the associated total
proﬁt; the Approximation
Algorithm returns the elements of
the pair related to the most
proﬁtable solution

### Integer Linear Programming

##### Item Struct

Stores data for each item including the index, proﬁt,
weight, and the proﬁt-to-weight ratio. Sorts items in
descending order.

#### Branch and Bound

Explores which items to include in the knapsack in
attempt to maximise the total proﬁt while pruning the
unpromising branches.

#### knapsackILP

Main function to solve the 0/1 knapsack problem using
the Branch and Bound Integer Linear Programming
approach.

**Time Complexity:** O (n log n + 2^n)

**Space Complexity:** O (n)

**Data Structures:** The Branch and Bound uses vectors,
one of integers and one of Items to
store the current solution and items
respectively. The knapsackILP uses
vectors of integers to store the proﬁts,
weights and the current solution and
one of Items for the items processed.
