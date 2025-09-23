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

- [Class Diagram](#class-diagram)  
- [User Interface](#user-interface)  
- [Reading the Dataset](#reading-the-dataset)  
- [Programming Approaches](#programming-approaches)  
  - [Brute-Force (Exhaustive)](#brute-force-exhaustive)  
  - [Dynamic Programming](#dynamic-programming)  
  - [Approximation (Greedy Approach)](#approximation-greedy-approach)  
  - [Integer Linear Programming](#integer-linear-programming)  

<a id="class-diagram"></a>
## Class Diagram

<div align="center">
<img width="1694" height="786" alt="Captura de ecrã de 2025-09-23 23-04-24" src="https://github.com/user-attachments/assets/77e01a75-7744-461c-88da-635eceafa60e" />
</div>

<a id="user-interface"></a>
## User Interface

- ✅ When starting the program, a menu is displayed with the options `Exit` (terminate program) and `Select Data Files`;  
- ✅ If `Select Data Files` is chosen, all available datasets in the same directory as the source code are listed;  
- ✅ After dataset selection, algorithmic approaches are shown for the user to choose from, with an option to return to `Select Data Files`;  
- ✅ Once the algorithm runs, the solution is shown (including total profit) and an option to process another dataset is offered.  

<a id="reading-the-dataset"></a>
## Reading the Dataset

After the selection of the ﬁles to process:

- ✅ `pair<vector<int>, vector<int>> extractPalletValues(const string& palletsFileName)`  
  Opens and reads each line of the `Pallets` ﬁle, extracting each pallet’s `weight` and `profit`, storing them in vectors `weights` and `profits`. Returns a `pair` of these vectors for use in other functions.  

- ✅ `int extractTruckCapacity(const string& truckFileName)`  
  Extracts and returns the truck’s maximum weight capacity from the `Truck` ﬁle.  

<a id="programming-approaches"></a>
## Programming Approaches

<a id="brute-force-exhaustive"></a>
### Brute-Force (Exhaustive)

- ✅ Iterates through all subsets of the given items;  
- ✅ For each subset, calculates the total `weight` and `profit`;  
- ✅ If the total weight is within the allowed capacity and profit is greater than the current best, updates the best subset;  
- ✅ Outputs the indices, weights, profits of selected items, and the maximum achievable profit.  

**Time Complexity:** `O(n 2^n)`  
**Space Complexity:** `O(n)`  

**Data Structures:**  
- Input: 2 vectors (`profit`, `weight`) + integer (`maximum capacity`).  
- Output: same 2 vectors + vector of selected indices + integer (`maximum profit`).  

<a id="dynamic-programming"></a>
### Dynamic Programming

- ✅ Takes as input profits, weights, and knapsack capacity;  
- ✅ Builds a DP table to compute the maximum profit without exceeding capacity;  
- ✅ Backtracks through the table to find items in the optimal solution;  
- ✅ Outputs selected items (index, weight, profit) and total profit;  
- ✅ More efficient than brute-force for larger inputs.  

**Time Complexity:** `O(nW)`  
**Space Complexity:** `O(nW)`  

**Data Structures:**  
- Input: 2 vectors (`profit`, `weight`) + integer (`maximum capacity`).  
- Output: same 2 vectors + vector of selected indices + integer (`total profit`).  

<a id="approximation-greedy-approach"></a>
### Approximation (Greedy Approach)

**Greedy Algorithm A**  
- ✅ Sort by `weight-to-profit` ratio (ascending).  
- ✅ Select items while they fit in the truck.  

**Greedy Algorithm B**  
- ✅ Sort by `profit` (ascending).  
- ✅ Select items while they fit in the truck.  

**Approximation Algorithm**  
- ✅ Picks the better solution between Greedy A and Greedy B.  

**Time Complexity:** `O(n log n)`  
**Space Complexity:** `O(n)`  

**Data Structures:**  
- Each greedy returns a `pair` (selected items, total profit).  
- Approximation Algorithm returns the most profitable `pair`.  

<a id="integer-linear-programming"></a>
### Integer Linear Programming

#### Item Struct  
- ✅ Stores `index`, `profit`, `weight`, and `profit-to-weight ratio`.  
- ✅ Items are sorted in descending order.  

#### Branch and Bound  
- ✅ Explores item inclusion in the knapsack to maximise profit.  
- ✅ Prunes unpromising branches.  

#### knapsackILP` 
- ✅ Main function solving `0/1 knapsack` using Branch and Bound ILP approach.  

**Time Complexity:** `O(n log n + 2^n)`  
**Space Complexity:** `O(n)`  

**Data Structures:**  
- Branch and Bound: vectors of integers and `Items` (current solution + items).  
- knapsackILP: vectors of `profits`, `weights`, current solution, and processed `Items`.  
