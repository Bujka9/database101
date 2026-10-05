#include <iostream>
#include <vector>

using namespace std;

// DFS function
void dfs(int vertex, const vector<vector<int>>& graph, vector<bool>& visited) {
    // Одоогийн оройг visited болгож тэмдэглэнэ
    visited[vertex] = true;

    // Оройг хэвлэнэ
    cout << vertex << " ";

    // Холбогдсон орой бүрээр явна
    for (int nextVertex : graph[vertex]) {

        // Хэрэв тухайн оройд өмнө нь очоогүй бол
        if (!visited[nextVertex]) {

            // DFS-ийг тухайн оройгоос үргэлжлүүлнэ
            dfs(nextVertex, graph, visited);
        }
    }
}


// g++ dfs_homework.cpp -o dfs_homework.exe
// .\dfs_homework.exe


int main() {
    // Графын оройн тоо
    int n = 5;

    // Adjacency list ашиглан граф үүсгэнэ
    vector<vector<int>> graph(n);

    // 0 -> 1, 2
    graph[0].push_back(1);
    graph[0].push_back(2);

    // 1 -> 3
    graph[1].push_back(3);

    // 2 -> 4
    graph[2].push_back(4);

    // DFS эхлэх орой
    int startVertex = 0;

    // Ямар оройд очсоныг хадгална
    vector<bool> visited(n, false);

    cout << "DFS result: ";

    // DFS ажиллуулна
    dfs(startVertex, graph, visited);

    cout << endl;

    return 0;
}
