// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

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
