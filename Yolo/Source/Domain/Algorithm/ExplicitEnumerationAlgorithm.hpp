#pragma once

#include "Algorithm.hpp"

namespace Yolo
{
    class ExplicitEnumerationAlgorithm : public Algorithm
    {
    public:
        ExplicitEnumerationAlgorithm(const Graph& graph, int nbClasses, bool (*criterion)(std::vector<int>, int, int)) : Algorithm(graph, nbClasses, criterion){}

        virtual Solution solve() override;
        void enumerateFrom(Solution sol, int from);
        void compareBest(Solution sol);

    protected:
        Solution mBest = Solution(mGraph.getNbVertices(), mNbClasses);
    };
}