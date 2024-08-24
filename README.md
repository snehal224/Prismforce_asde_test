# ASDE Algorithm Test: Abhimanyu in Chakravyuha

## Problem Description

In this problem, Abhimanyu is trapped in the Chakravyuha, surrounded by 11 circles, each guarded by an enemy with varying power levels. Abhimanyu starts in the innermost circle and must battle or strategically avoid enemies to reach the Pandavas' army.

### Given:
- **Enemy Powers:** Each of the 11 circles is guarded by an enemy with power levels denoted as `k1, k2, ..., k11`.
- **Initial Power:** Abhimanyu begins with a certain power `p`.
- **Skips:** Abhimanyu has the ability to skip fighting an enemy `a` times.
- **Recharges:** Abhimanyu can recharge his power `b` times during his journey.
- **Battle Rules:**
  - If Abhimanyu’s power is less than the enemy's power when he enters a circle, he loses the battle.
  - Battling an enemy decreases Abhimanyu's power by the amount equivalent to the enemy's power.
  - Enemies at circles 3 and 7 can regenerate with half of their initial power and may attack Abhimanyu from behind when he is battling in the next circle.

### Objective:
The objective is to determine whether Abhimanyu can successfully cross all 11 circles and reach the Pandavas' army.

## Working of the Algorithm

The algorithm employs a recursive strategy to explore all possible scenarios for Abhimanyu to cross the Chakravyuha. The recursive function considers three primary decisions at each step:
1. **Recharging:** If Abhimanyu has recharges left and his power is not at its maximum, he can recharge.
2. **Skipping:** If Abhimanyu has skips left, he can skip the current enemy without battling.
3. **Battling:** If Abhimanyu has enough power, he can choose to battle the current enemy.

Special consideration is given to the enemies in circles 3 and 7, who can regenerate and attack from behind. The algorithm evaluates whether Abhimanyu can survive these attacks and continue forward.

### Key Steps:
1. **Base Case:** If Abhimanyu reaches the last circle (11th enemy), he successfully crosses the Chakravyuha.
2. **Recursive Decisions:** The algorithm recursively checks the possibility of recharging, skipping, or battling at each circle.
3. **Handling Behind Attacks:** The algorithm tracks and manages attacks from enemies 3 and 7 when they regenerate and attack from behind.

## Time Complexity

The time complexity of the algorithm is exponential, O(3^n), where `n` is the number of circles (or enemies). This is because, at each circle, Abhimanyu has up to three choices: recharge, skip, or battle. In the worst-case scenario, all paths need to be explored due to the recursive nature of the algorithm.

### Optimizations:
- **Memoization:** To improve efficiency, memoization can be employed to store the results of already evaluated states (combinations of current power, skips left, and recharges left).
- **Pruning:** Some branches of recursion can be pruned if it's clear that they will not lead to a successful outcome.

## Test Cases

### Test Case 1
- **Input:**
  - Enemy Powers: `{0, 10, 9, 3, 2, 5, 6, 7, 8, 4, 7}`
  - Abhimanyu's Initial Power: `5`
  - Skips: `5`
  - Recharges: `3`
- **Output:** `Abhimanyu cannot cross the Chakravyuha`

### Test Case 2
- **Input:**
  - Enemy Powers: `{0, 10, 2, 3, 9, 5, 6, 7, 8, 4, 1}`
  - Abhimanyu's Initial Power: `10`
  - Skips: `6`
  - Recharges: `2`
- **Output:** `Abhimanyu can cross the Chakravyuha`

## Conclusion

The algorithm is designed to explore all possible strategies Abhimanyu can use to cross the Chakravyuha. While the worst-case time complexity is exponential, optimizations like memoization and pruning can significantly improve performance. The provided test cases demonstrate the algorithm's effectiveness in determining whether Abhimanyu can cross the Chakravyuha under different scenarios.
