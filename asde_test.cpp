#include <bits/stdc++.h>

using namespace std;
int max_enemies = 11; // Total number of enemies in the Chakravyuha

int power; // Initial power of Abhimanyu

// Function to check if Abhimanyu can cross the Chakravyuha.
bool canCrossChakrvyuha(vector<int> &enemyPower, int enemy, int cur_power, int behind, int skips, int recharge)
{
    // Abhimanyu successfully crossed the Chakravyuha
    if (enemy == max_enemies)
        return true;

    bool flag = false;
    if (behind != 0)
    {
        if (cur_power >= behind)
        {
            cur_power -= behind;
            behind = 0;
        }
        else
            return false;
    }

    // Option 1. Abhimanyu can recharge himself if he has remaining recharge count and his power is less than maximum power
    if (recharge > 0 && cur_power < power)
        flag |= canCrossChakrvyuha(enemyPower, enemy, power, behind, skips, recharge - 1);

    // If Abhimanyu can fight with the enemy attacking from behind.

    // Option 2. Abhimanyu can skip this enemy if he has remaining skips count
    if (skips > 0)
        flag |= canCrossChakrvyuha(enemyPower, enemy + 1, cur_power, behind, skips - 1, recharge);

    // Option 3. Fight with the current enemy without recharge or skip.

    // If current power is greater than or equal to the power of the current enemy
    if (cur_power >= enemyPower[enemy])
    {
        if (enemy == 2 || enemy == 6)
            behind = enemyPower[enemy] / 2;

        flag |= canCrossChakrvyuha(enemyPower, enemy + 1, cur_power - enemyPower[enemy], behind, skips, recharge);
    }

    return flag;
}

int main()
{
    vector<int> enemyPower(max_enemies); // Powers of each enemy from 1-11.

    for (int i = 0; i < max_enemies; i++)
        cin >> enemyPower[i];

    int a, b; // a: Total number of skips Abhimanyu has, b: Number of times Abhimanyu can recharge himself
    cin >> power >> a >> b;

    int behind = 0; // Power of regenerated enemy to attack from behind.

    if (canCrossChakrvyuha(enemyPower, 0, power, behind, a, b))
        cout << "Abhimanyu can cross the Chakrvyuha" << endl;
    else
        cout << "Abhimanyu cannot cross the Chakrvyuha" << endl;

    return 0;
}

// Test case: 1
// max_enemies = 11
// enemyPower = {0, 10, 9, 3, 2, 5, 6, 7, 8, 4, 7}
// power = 5
// a = 5
// b = 3
// Answer: Abhimanyu cannot cross the Chakrvyuha

// Test case: 2
//  max_enemies = 11
//  enemyPower = {0, 10, 2, 3, 9, 5, 6, 7, 8, 4, 1}
//  power = 10
//  a = 6
//  b = 2
//  Answer: Abhimanyu can cross the Chakrvyuha