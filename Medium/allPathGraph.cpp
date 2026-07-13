/*
Problem: All Paths From Source to Target
Link: https://leetcode.com/problems/all-paths-from-source-to-target/
*/

/*
Description:
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n-1, 
find all possible paths from node 0 to node n-1 and return them in any order.
The graph is given as an adjacency list.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void give(vector<vector<int>>& graph, int i, vector<vector<int>>& answer,
              vector<int>& result) {

        if (i == graph.size() - 1) {
            answer.push_back(result);
            return;
        }

        for (int j = 0; j < graph[i].size(); j++) {

            result.push_back(graph[i][j]);

            give(graph, graph[i][j], answer, result);

            result.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size()==0){
            return {};
        }
        vector<vector<int>> answer;
        vector<int> result = {0};
        
        result.reserve(graph.size());

        give(graph, 0, answer, result);

        return answer;
    }
};

/*
Test:
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths from 0 to 3:
  0 → 1 → 3
  0 → 2 → 3

Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

Time Complexity: O(2^V * V) where V is number of vertices
Space Complexity: O(V) for recursion stack + output
*/
