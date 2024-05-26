#include <bits/stdc++.h>
using namespace std;

int n, Bessie[50001], Elsie[50000];

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    cin >> n; 
    for (int i = 0; i < n; i++) 
        cin >> Elsie[i];  
    Elsie[n] = n * 2; // Add a boundary value to prevent bessie cards from missing statistics
    sort(Elsie, Elsie + n);  // Sort Elsie's cards

    // Calculate the cards Bessie has
    for (int i = 0, j = 0; i <= n; i++) 
        for (int k = Elsie[i - 1] + 1; k < Elsie[i]; k++)
            Bessie[j++] = k;  // Fill Bessie's cards with the remaining cards not in Elsie's set

    int l = 0, r = 0;
    while (r < n) {
        // Find the first card in Bessie's set that is larger than Elsie's current card
        while (r < n - 1 && Elsie[l] > Bessie[r])
            r++;
        l++, r++;  // Move to the next round
    }
    cout << l - 1 << endl;
}