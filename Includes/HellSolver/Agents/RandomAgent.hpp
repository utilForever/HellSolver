// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_SOLVER_RANDOM_AGENT_HPP
#define HELL_SOLVER_RANDOM_AGENT_HPP

#include <HellSolver/Agents/IAgent.hpp>

namespace HellSolver
{
//!
//! \brief RandomAgent class.
//!
//! This class is an agent that plays an action at random.
//!
class RandomAgent final : public IAgent
{
 public:
    //! Default constructor.
    RandomAgent() = default;

    //! Deleted copy constructor.
    RandomAgent(const RandomAgent&) = delete;

    //! Deleted move constructor.
    RandomAgent(RandomAgent&&) noexcept = delete;

    //! Default virtual destructor.
    ~RandomAgent() override = default;

    //! Deleted copy assignment operator.
    RandomAgent& operator=(const RandomAgent&) = delete;

    //! Deleted move assignment operator.
    RandomAgent& operator=(RandomAgent&&) noexcept = delete;

    //! Gets an action of agent.
    //! \param state The current game state.
    //! \return An action of agent.
    Direction GetAction(const Game& state) override;
};
}  // namespace HellSolver

#endif  // HELL_SOLVER_RANDOM_AGENT_HPP
