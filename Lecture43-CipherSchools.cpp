#include "bits/stdc++.h"
using namespace std;


//MST (Prims's algorithm and Kruskal algorithm)
int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}

int minCostConnectPoints(vector<vector<int>>& ps) {
    int n = ps.size(), res = 0;
    vector<int> ds(n, -1);
    vector<array<int, 3>> arr;
    for (auto i = 0; i < n; ++i)
        for (auto j = i + 1; j < n; ++j) {
            arr.push_back({abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i, j});
        }
    make_heap(begin(arr), end(arr), greater<array<int, 3>>());
    while (!arr.empty()) {
        pop_heap(begin(arr), end(arr), greater<array<int, 3>>());
        auto [dist, i, j] = arr.back();
        arr.pop_back();
        i = find(ds, i), j = find(ds, j);
        if (i != j) {
            res += dist;
            ds[i] += ds[j];
            ds[j] = i;
            if (ds[i] == -n)
                break;
        }
    }
    return res;
}


int minCostConnectPoints(vector<vector<int>>& ps) {
    int n = ps.size(), res = 0, i = 0, connected = 0;
    vector<bool> visited(n);
    priority_queue<pair<int, int>> pq;
    while (++connected < n) {
        visited[i] = true;
        for (int j = 0; j < n; ++j)
            if (!visited[j])
                pq.push({-(abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1])), j});
        while (visited[pq.top().second])
            pq.pop();
        res -= pq.top().first;
        i = pq.top().second;
        pq.pop();
    }
    return res;
}


int main(){
    cout<<"Nice approach"<<endl;
    return 0;
}


/* TSP(Travelling Salesman problem) */
//#include <bits/stdc++.h>
//using namespace std;
//
//void findMinRoute(vector<vector<int> > tsp)
//{
//    int sum = 0;
//    int counter = 0;
//    int j = 0, i = 0;
//    int min = INT_MAX;
//    map<int, int> visitedRouteList;
//    visitedRouteList[0] = 1;
//    int route[tsp.size()];
//    while (i < tsp.size() && j < tsp[i].size())
//    {
//        if (counter >= tsp[i].size() - 1)
//        {
//            break;
//        }
//        if (j != i && (visitedRouteList[j] == 0))
//        {
//            if (tsp[i][j] < min)
//            {
//                min = tsp[i][j];
//                route[counter] = j + 1;
//            }
//        }
//        j++;
//        if (j == tsp[i].size())
//        {
//            sum += min;
//            min = INT_MAX;
//            visitedRouteList[route[counter] - 1] = 1;
//            j = 0;
//            i = route[counter] - 1;
//            counter++;
//        }
//    }
//    i = route[counter - 1] - 1;
//
//    for (j = 0; j < tsp.size(); j++)
//    {
//
//        if ((i != j) && tsp[i][j] < min)
//        {
//            min = tsp[i][j];
//            route[counter] = j + 1;
//        }
//    }
//    sum += min;
//    cout << (sum);
//}
//
//int main()
//{
//    vector<vector<int> > tsp = { { -1, 10, 15, 20 },
//                                 { 10, -1, 35, 25 },
//                                 { 15, 35, -1, 30 },
//                                 { 20, 25, 30, -1 }};
//
//    findMinRoute(tsp);
}