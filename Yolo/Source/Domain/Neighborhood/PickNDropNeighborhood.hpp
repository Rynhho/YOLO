#pragma once

#include "Domain/Neighborhood/Neighborhood.hpp"

namespace Yolo
{
    class PickNDropNeighborhood : public Neighborhood
    {
    public:
        PickNDropNeighborhood() {}

        virtual std::vector<Solution> generateAll(const Solution& solution) const override;
        virtual Solution generateBest(const Graph& g, const Criterion* criterion, const Solution& solution) const override;
    };
} // namespace Yolo
