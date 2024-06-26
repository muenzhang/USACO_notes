# [USACO 2018 January Contest, Silver](http://www.usaco.org/index.php?page=jan18results)
## [Problem 2. Rental Service](http://www.usaco.org/index.php?page=viewproblem2&cpid=787)

Farmer John realizes that the income he receives from milk production is insufficient to fund the growth of his farm, so to earn some extra money, he launches a cow-rental service, which he calls "USACOW" (pronounced "Use-a-cow").

Farmer John has `N` cows `(1≤N≤100,000)`, each capable of producing some amount of milk every day. The `M` stores near FJ's farm `(1≤M≤100,000)` each offer to buy a certain amount of milk at a certain price. Moreover, Farmer John's `R` `(1≤R≤100,000)` neighboring farmers are each interested in renting a cow at a certain price.

Farmer John has to choose whether each cow should be milked or rented to a nearby farmer. Help him find the maximum amount of money he can make per day.

**INPUT FORMAT (file rental.in):**  

The first line in the input contains `N`, `M`, and `R`. The next `N` lines each contain an integer `ci` `(1≤ci≤1,000,000)`, indicating that Farmer John's ith cow can produce `ci` gallons of milk every day. The next `M` lines each contain two integers `qi` and `pi` `(1≤qi,pi≤1,000,000)`, indicating that the ith store is willing to buy up to qi gallons of milk for pi cents per gallon. Keep in mind that Farmer John can sell any amount of milk between zero and `qi` gallons to a given store. The next `R` lines each contain an integer `ri` `(1≤ri≤1,000,000)`, indicating that one of Farmer John's neighbors wants to rent a cow for `ri` cents per day.

**OUTPUT FORMAT (file rental.out):**  

The output should consist of one line containing the maximum profit Farmer John can make per day by milking or renting out each of his cows. Note that the output might be too large to fit into a standard 32-bit integer, so you may need to use a larger integer type like a "long long" in C/C++.  

**SAMPLE INPUT:**  
```
5 3 4  
6  
2  
4  
7  
1  
10 25  
2 10  
15 15  
250  
80  
100  
40  
```

**SAMPLE OUTPUT:**  
```
725  
```

Farmer John should milk cows #1 and #4, to produce 13 gallons of milk. He should completely fill the order for 10 gallons, earning 250 cents, and sell the remaining three gallons at 15 cents each, for a total of 295 cents of milk profits.

Then, he should rent out the other three cows for 250, 80, and 100 cents, to earn 430 more cents. (He should leave the request for a 40-cent rental unfilled.) This is a total of 725 cents of daily profit.

## Custom Comparators + Sort + Greedy Approach

### Read sample input

`Number of cows = N = 5`  
`Number of shops = M = 3`  
`Number of neighbors = R = 4`

Milk produced per cow in gallons:  
`milk = [6, 2, 4, 7, 1]`  
Quantity demand of milk gallons and cents per gallon from shops:  
`shops = [(10, 25), (2, 10), (15, 15)] `  
Neighbor rent a cow cents per day rate:  
`rent = [250, 80, 100, 40]`  

### Sort in `reverse` and by `rate`; we always want to milk the cow that produces the most milk 
`milk = [7, 6, 4, 2, 1]`  
`shops = [(10, 25), (15, 15), (2, 10)] `  
`rent = [250, 100, 80, 40]`  

### **Start iterating through cows in descending order and check if renting a cow is more profitable than selling milk**
#### **1. Calculate potential revenue if cow were to be milked using shops' rates and demand**
#### **2. Compare renting a cow vs selling milk gallons**
#### **3. Choose what returns the most revenue and repeat**

Observe `1st Cow` in **descending** ordered cow list that can produce `7 gallons of milk`:  
Gallons of milk max price = 7 * 25 = 175, Rent a cow price = 250  
`Last Cow` in sorted cow list that produces 1 gallon of milk, rented for `250` **instead**  
**(It is more optimal to sell cow that produces least amount of milk)**  
milk = [7, 6, 4, 2, **RENTED**]  
shops = [(10, 25), (15, 15), (2, 10)]  
rent = [**RENTED**, 100, 80, 40]  
`Current revenue = 250`

Continue observing and comparing `1st Cow` in sorted cow list that can produce `7 gallons of milk`:  
Gallons of milk max price = 7 * 25 = 175, Rent a cow price = 100  
`1st Cow` in sorted cow list that produces `7 gallons of milk`, sold milk for `175`  
milk = [**MILKED**, 6, 4, 2, RENTED]  
shops = [(**3**, 25), (15, 15), (2, 10)]  
rent = [RENTED, 100, 80, 40]  
`Current revenue = 425`

Observe `2nd Cow` in sorted cow list that can produce `6 gallons of milk`:  
Gallons of milk max price = (3 * 25) + (3 * 15) = 120, Rent a cow price = 100  
`2nd Cow` in sorted cow list that produces `6 gallons of milk`, sold milk for `120` **across 2 different stores**  
milk = [MILKED, **MILKED**, 4, 2, RENTED]  
shops = [(**SOLD OUT**, 25), (**12**, 15), (2, 10)]  
rent = [RENTED, 100, 80, 40]  
`Current revenue = 545`

Observe `3rd Cow` in sorted cow list that can produce `4 gallons of milk`:  
Gallons of milk max price = 4 * 15 = 60, Rent a cow price = 100  
`2nd to last Cow` in sorted cow list that produces 2 gallons of milk, rented for `100` **instead**  
milk = [MILKED, MILKED, 4, **RENTED**, RENTED]  
shops = [(SOLD OUT, 25), (12, 15), (2, 10)]  
rent = [RENTED, **RENTED**, 80, 40]  
`Current revenue = 645`

Observe `3rd Cow` in sorted cow list that can produce `4 gallons of milk`:  
Gallons of milk max price = 4 * 15 = 60, Rent a cow price = 80  
`3rd to last Cow` in sorted cow list that produces 2 gallons of milk, rented for `80`  
milk = [MILKED, MILKED, **RENTED**, RENTED, RENTED]  
shops = [(SOLD OUT, 25), (12, 15), (2, 10)]  
rent = [RENTED, RENTED, **RENTED**, 40]  
`Current revenue = 725`

All cows used  
`Maximum revenue = 725`

## [Solution](https://github.com/Reddimus/USACO_notes/tree/main/Arrays_and_Hashing/Custom_Comparators_and_Coordinate_Compression/Silver/P2_2018-Rental_Service)

#### Steps:
1. **Read in input data:**
	- First line: `n` = number of cows, `m` = number of shops, and `r` = number of neighbors
	- Next `n` lines: read in milk produced per cow into a array like data structure.
	- Next `m` lines: read in demand of milk gallons and rate of milk from shops into an array of objects, or an array of pairs.
	- Next `r` lines: read in neighbor rent a cow rate into an array.
2. **Sort milk, shops, and rent arrays**:
	- Sort milk in descending order; we always want to milk the cow that produces the most milk.
	- Sort shops in descending order by rate; we always want to sell milk to the shop that offers the most money per gallon.
	- Sort rent in descending order; we always want to rent the cow for the most money.
3. **Calculate maximum revenue**:
	- First calculate potential price if cow were to be milked. This signifies we need to use a multitude of temporary variables.
	- Iterate through each cow in which we decide to either milk the cow or rent it to a neighbor. We can decide this by comparing the potential price of milk to the rent price. For each cow we decide to milk we need to update our cow index and shop index by +1. If we decide to rent a cow we need to update our cow index by renting the cow that produces the least amount of milk and update our rent index by +1.
4. **Write maximum profit to output file**.

### Time Complexity: `O(N * M)`
### Space Complexity: `O(N + M + R)`
Where `N` is `number of cows`, `M` is `number of shops as milk customers`, and `R` is `number of neighbors as rent customers`.

### Python Code:
```Python
class Shop:
	def __init__(self, demand: int, rate: int) -> None:
		self.demand = demand
		self.rate = rate

# Open input file
with open('rental.in', 'r') as f:
	# Read first line: n = num of cows, m = num of shops, r = num of neighbors
	n, m, r = map(int, f.readline().split())
	# For the next n lines track milk produced per cow
	milk = [int(f.readline()) for jugs in range(n)]
	# For the next m lines track demand of milk and rate of milk from shops
	shops = [Shop(*map(int, f.readline().split())) for shop_customer in range(m)]
	# For the next r lines track neighbor rent a cow rate
	rent = [int(f.readline()) for neighbor_customer in range(r)]

# We always want to look at the cow that can potentially produce the most milk first
milk.sort(reverse=True)
shops.sort(reverse=True, key=lambda s: s.rate)
rent.sort(reverse=True)

# Calculate maximum revenue
revenue = 0
cached_price = False
cow_idx, shop_idx, rent_idx = 0, 0, 0
while (cow_idx < n):
	if not cached_price:
		# Calculate potential revenue if cow were to be milked
		jugs = milk[cow_idx]
		jugs_price = 0
		last_sold = 0
		temp_idx = shop_idx
		while temp_idx < m:
			sold = min(jugs, shops[temp_idx].demand)
			jugs_price += sold * shops[temp_idx].rate
			jugs -= sold
			if jugs == 0:
				last_sold = sold
				break
			temp_idx += 1

	# Compare rent a cow price to potential milked price
	if rent_idx < r and rent[rent_idx] > jugs_price:
		revenue += rent[rent_idx]
		cached_price = True	# save unused price for next iteration
		rent_idx += 1
		n -= 1	# rent cow that produces the least milk
	else:
		revenue += jugs_price
		shop_idx = temp_idx
		if temp_idx < m:
			shops[shop_idx].demand -= last_sold
		cached_price = False
		cow_idx += 1

# Write maximum profit to rental output file 
print(revenue, file=open('rental.out', 'w'))
```

### C++ Code:
```C++
#include <bits/stdc++.h>
using namespace std;

int main() {
	// Open input file
	freopen("rental.in", "r", stdin);
	// Read first line: n = num of cows, m = num of shops, r = num of neighborCustomers
	int n, m, r;
	cin >> n >> m >> r;
	// For the next n lines track milk produced per cow
	vector<int> milk(n);
	for (int cow = 0; cow < n; cow++)
		cin >> milk[cow];
	// For the next m lines track demand and rate of each shop
	struct Shop {int demand, rate;};
	vector<Shop> shops(m);
	for (int shopCustomer = 0; shopCustomer < m; shopCustomer++)
		cin >> shops[shopCustomer].demand >> shops[shopCustomer].rate;
	// For the next r lines track neighbor Customer rent a cow rate
	vector<int> rent(r);
	for (int neighborCustomer = 0; neighborCustomer < r; neighborCustomer++)
		cin >> rent[neighborCustomer];

	// We always want to look at the cow that can potentially produce the most milk first
	sort(milk.begin(), milk.end(), greater<int>());
	sort(shops.begin(), shops.end(), [](Shop a, Shop b) {return a.rate > b.rate;});
	sort(rent.begin(), rent.end(), greater<int>());

	// Calculate maximum revenue
	unsigned long revenue = 0;
	bool cachedPrice = false;
	int jugs, jugsPrice, lastSold, tempIdx;
	int cowIdx = 0, shopIdx = 0, rentIdx = 0;
	while (cowIdx < n) {		
		if (!cachedPrice) {
			// Calculate potential revenue if cow were to be milked
			jugs = milk[cowIdx], jugsPrice = 0, lastSold = 0;
			tempIdx = shopIdx;
			while (tempIdx < m) {
				int sold = min(jugs, shops[tempIdx].demand);
				jugsPrice += sold * shops[tempIdx].rate;
				jugs -= sold;

				if (jugs == 0){
					lastSold = sold;
					break;
				}
				tempIdx++;
			}
		}

		// Compare rent a cow price to potential milked price
		if (rentIdx < r && rent[rentIdx] > jugsPrice) {
			revenue += rent[rentIdx];
			cachedPrice = true;
			rentIdx++;
			n--;	// rent cow that produces least milk
		}
		else {
			revenue += jugsPrice;
			shopIdx = tempIdx;
			if (tempIdx < m)
				shops[shopIdx].demand -= lastSold;
			cachedPrice = false;
			cowIdx++;
		}
	}

	// Write maximum profit to output file 
	freopen("rental.out", "w", stdout);
	cout << revenue << endl;
}
```

### Java Code:
```Java
import java.io.*;
import java.util.*;

public class RentalService {
	static class Shop {
		int demand, rate;
		Shop(int demand, int rate) {
			this.demand = demand;
			this.rate = rate;
		}
	}

	public static void main(String[] args) throws IOException {
		// Open Rental input file
		BufferedReader in = new BufferedReader(new FileReader("rental.in"));
		// Read first line: n = num of cows, m = num of shops, r = num of neighbors
		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		// For the next n lines track milk produced per cow
		Integer[] milk = new Integer[n];
		for (int cow = 0; cow < n; cow++)
			milk[cow] = Integer.parseInt(in.readLine());
		// For the next m lines track demand & rate of each shop that wants to buy milk
		Shop[] shops = new Shop[m];
		for (int shopCustomer = 0; shopCustomer < m; shopCustomer++) {
			st = new StringTokenizer(in.readLine());
			int demand = Integer.parseInt(st.nextToken());
			int rate = Integer.parseInt(st.nextToken());
			shops[shopCustomer] = new Shop(demand, rate);
		}
		// For the next r lines track neighbor's that want to rent cows
		Integer[] rent = new Integer[r];
		for (int neighborCustomer = 0; neighborCustomer < r; neighborCustomer++)
			rent[neighborCustomer] = Integer.parseInt(in.readLine());
		in.close();

		// Sort in reverse; we always want to milk the cow that produces the most milk
		Arrays.sort(milk, Collections.reverseOrder());
		Arrays.sort(shops, Collections.reverseOrder(Comparator.comparingInt(a -> a.rate)));
		Arrays.sort(rent, Collections.reverseOrder());

		// Calculate maximum revenue
		long revenue = 0;
		boolean cachedPrice = false;
		int jugs = 0, jugsPrice = 0, lastSold = 0, tempIdx = 0;
		int cowIdx = 0, shopIdx = 0, rentIdx = 0;
		while (cowIdx < n) {
			if (!cachedPrice) {
				// Calculate potential revenue if cow were to be milked
				jugs = milk[cowIdx];
				jugsPrice = 0;
				lastSold = 0;
				tempIdx = shopIdx;
				while (tempIdx < m) {
					int sold = Math.min(jugs, shops[tempIdx].demand);
					jugsPrice += sold * shops[tempIdx].rate;
					jugs -= sold;
					if (jugs == 0) {
						lastSold = sold;
						break;
					}
					tempIdx++;
				}
			}

			// Compare rent a cow price to potential milked price
			if (rentIdx < r && rent[rentIdx] > jugsPrice) {
				revenue += rent[rentIdx];
				cachedPrice = true;
				rentIdx++;
				n--;	// rent cow that produces least milk
			}
			else {
				revenue += jugsPrice;
				shopIdx = tempIdx;
				if (shopIdx < m)
					shops[shopIdx].demand -= lastSold;
				cachedPrice = false;
				cowIdx++;
			}
		}
		
		// Write maximum revenue/profit to output file 
		PrintWriter out = new PrintWriter("rental.out");
		out.println(revenue);
		out.close();
	}
}
```