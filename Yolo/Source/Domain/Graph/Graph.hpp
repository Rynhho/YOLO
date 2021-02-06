#pragma once

#include "Domain/Graph/Edge.hpp"

#include "Domain/Solution/Solution.hpp"

#include <vector>

namespace Yolo
{
    struct CheckerOutput
    {
        const bool isValid;
        const double cost;
    };

    class Graph
    {
    public:
        Graph(const std::vector<std::vector<Edge>>& adjacencyList);

        inline int getNbVertices() const { return static_cast<int>(mAdjacencyList.size()); }

        inline int getVertexDegree(int vertex) const { return mVertexDegrees[vertex]; }

        inline int getMaxDegree() const { return mMaxDegree; }
        inline int getMinDegree() const { return mMinDegree; }

        inline int getNbEdges() const { return mNbEdges; }

        bool isPartialSolutionValid(const Solution& solution, bool (*criterion)(std::vector<int>, int, int), int lastIndex) const;
        bool isValid(const Solution& solution, bool (*criterion)(std::vector<int>, int, int)) const;
        double getSolutionCost(const Solution& solution) const;
        double getSolutionCostDifference(const Solution& solution, int vertex, int newClass) const;

        CheckerOutput checkSolution(const Solution& solution, bool (*criterion)(std::vector<int>, int, int)) const;

    private:
        std::vector<int> mVertexDegrees;
        int mMaxDegree;
        int mMinDegree;

        int mNbEdges;

        std::vector<std::vector<Edge>> mAdjacencyList;
    };
} // namespace Yolo
