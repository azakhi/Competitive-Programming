Let **T = {a, b, s, c, d}** be an example list for the problem and **s** is the starting shop.

Assume **c** is the best option to visit first. If **d** is higher than or equal to **c**, **d** would be the next best option to visit. For any **x** & **y** where **y** comes after **x** and **y >= x**, visiting **y** right after **x** would be the best option. Then **x** and **y** can be assumed as a single shop that requires 2 days to visit and the new cost value would be average of **x** and **y**.

If the members of each side are combined again and again until there is no **x** and **y** such that **y** comes after **x** and **y >= x** (note that when using a combined group in a comparison, average value must be used), the members of the final list would be sorted in a decreasing order.

Finally the best cost can be found by comparing top member of each side on each step and visiting the bigger one.
