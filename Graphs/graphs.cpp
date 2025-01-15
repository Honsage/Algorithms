#include <iostream>
#include "graphs.h"

std::vector<int> Dijkstra(const std::vector<std::vector<int>> &costMatrix, const int v) {
    const int size = static_cast<int>(costMatrix.size());
    std::vector<int> shortestPath(size, INF);
    std::vector<bool> visited(size, false);

    int cur = v-1, min_cost, next;
    shortestPath[cur] = 0;
    visited[cur] = true;

    bool stop = false;
    for(int c = 0; c < size; ++c) {
        for(int j = 0; j < size; ++j) {
            if(costMatrix[cur][j] != INF && !visited[j]) {
                shortestPath[j] = std::min(shortestPath[j], shortestPath[cur] + costMatrix[cur][j]);
            }
        }
        min_cost = INF, next = cur;
        for(int j = 0; j < size; ++j) {
            if(!visited[j]) {
                if(shortestPath[j] < min_cost) {
                    min_cost = shortestPath[j];
                    next = j;
                }
            }
        }
        visited[next] = true;
        cur = next;
        stop = true;
        for(int j = 0; j < size; ++j) {
            stop = stop && visited[j];
        }
        if(stop) { break; }
    }

    return shortestPath;
}
