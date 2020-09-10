// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_SOLVER_PLAYER_HPP
#define HELL_SOLVER_PLAYER_HPP

#include <HellSolver/Enums/GameEnums.hpp>
#include <utility>

namespace hell_solver
{
//!
//! \brief Player class.
//!
//! This class represents player of the game.
//!
class Player
{
 public:
    //! Default constructor.
    Player() = default;

    //! Default destructor.
    ~Player() = default;

    //! Constructs player with given \p position and \p moveCount.
    //! \param initX The X coordinate for initializing.
    //! \param initY The Y coordinate for initializing.
    //! \param moveCount The limitation of move count.
    Player(std::size_t initX, std::size_t initY, std::size_t moveCount);

    void Reset(std::size_t initX, std::size_t initY, std::size_t moveCount);

    //! Processes move by given \p direction and returns moved coordinate by
    //! pair.
    //! \param dir The direction to be moved.
    //! \return The moved coordinated represented by pair.
    [[nodiscard]] std::pair<std::size_t, std::size_t> ProcessMove(
        Direction dir);

    //! Gets the status of the player.
    //! \param isEndPoint The boolean flag for checking the player is on end
    //! point.
    //! \return The status of the player.
    [[nodiscard]] PlayerStatus GetPlayerStatus(bool isEndPoint) const;

    //! Gets the current available move count of the player.
    //! \return The move count of the player.
    [[nodiscard]] std::size_t GetMoveCount() const;

    //! Returns the boolean flag which represents the player has key.
    //! \return The boolean flag which represents the player has key.
    [[nodiscard]] bool HasKey() const;

    //! Sets the boolean flag when player gets a key.
    void SetKey();

    //! Gets the current position of the player.
    //! \return the current position of the player represented by pair.
    [[nodiscard]] std::pair<std::size_t, std::size_t> GetPosition() const;

    //! Decrease player's move count by one.
    void DecreaseMoveCount();

 private:
    std::size_t x = 0;
    std::size_t y = 0;
    std::size_t moveCount = 0;
    bool hasKey = false;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_PLAYER_HPP
