#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];

    int maxSections = 0;

    for (int i = 0; i < N; i++) {
        int count = 1; // empezamos en la posición i

        // hacia la izquierda
        for (int j = i - 1; j >= 0; j--) {
            if (V[j] <= V[j + 1])
                count++;
            else
                break;
        }

        // hacia la derecha
        for (int j = i + 1; j < N; j++) {
            if (V[j] <= V[j - 1])
                count++;
            else
                break;
        }

        maxSections = max(maxSections, count);
    }

    cout << maxSections << endl;
    return 0;
}
