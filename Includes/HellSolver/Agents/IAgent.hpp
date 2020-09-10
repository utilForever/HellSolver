//
// Created by flow on 2020-09-10.
//

#ifndef HELL_SOLVER_IAGENT_HPP
#define HELL_SOLVER_IAGENT_HPP

#include <HellSolver/Games/Game.hpp>

namespace hell_solver
{
//!
//! \brief IAgent class.
//!
//! This class is an interface of agent classes.
//!
class IAgent
{
 public:
    //! Default virtual destructor.
    virtual ~IAgent() = default;

    //! Gets an action of agent.
    //! \param state The current game state.
    //! \return An action of agent.
    virtual Direction GetAction(const Game& state) = 0;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_IAGENT_HPP
