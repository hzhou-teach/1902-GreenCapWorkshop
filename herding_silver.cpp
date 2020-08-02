// Brian Lu
//
// after ~25 mins *xxxxxx*xxxx 
// ok fair enough this only works in a specific case i didn't think this through
//

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <limits>

int main()
{
    int N;
    FILE *input = fopen("herding.in", "r");
    fscanf(input, "%d", &N);
    std::vector<int> cows;
    for (int i = 0; i < N; i++) {
        int c;
        fscanf(input, "%d", &c);
        cows.push_back(c);
    }
    fclose(input);

    std::sort(cows.begin(), cows.end());

    int min = 2147483647;
    int max = -1;
    for (int i = 1; i < N; i++) {
        int gap = cows[i] - cows[i-1];
        gap--;
        min = std::min(min, gap);
        max = std::max(max, gap);
    }

    FILE *output = fopen("herding.out", "w");
    fprintf(output, "%d\n%d\n", min, max);
    fclose(output);

    return 0;
}