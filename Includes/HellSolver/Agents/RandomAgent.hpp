//
// Created by flow on 2020-09-10.
//

#ifndef HELL_SOLVER_RANDOMAGENT_HPP
#define HELL_SOLVER_RANDOMAGENT_HPP

#include <HellSolver/Agents/IAgent.hpp>

namespace hell_solver
{
//!
//! \brief RandomAgent class.
//!
//! This class is an agent that plays an action at random.
//!
class RandomAgent final : public IAgent
{
 public:
    //! Default virtual destructor.
    virtual ~RandomAgent() = default;

    //! Gets an action of agent.
    //! \param state The current game state.
    //! \return An action of agent.
    Direction GetAction(const Game& state) override;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_RANDOMAGENT_HPP
