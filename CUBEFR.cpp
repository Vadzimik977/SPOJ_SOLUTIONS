#include <cstdio>
#include <cstdlib>

const int N = 1100000;
int isCubeFree[N];
int cubeId[N];
int numCubes = 0;

int main() {
    // Precalculation to mark cube-free numbers
    for (int i = 2; i * i * i < N; ++i)
        for (int j = i * i * i; j < N; j += i * i * i)
            isCubeFree[j] = 1;

    // Assign unique IDs to cube-free numbers
    for (int i = 1; i < N; ++i)
        if (!isCubeFree[i])
            cubeId[i] = ++numCubes;

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        printf("Case %d: ", t);

        if (!isCubeFree[n])
            printf("%d\n", cubeId[n]);
        else
            printf("Not Cube Free\n");
    }

    return 0;
}
