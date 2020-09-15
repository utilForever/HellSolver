// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_SOLVER_PLAYER_HPP
#define HELL_SOLVER_PLAYER_HPP

#include <HellSolver/Enums/GameEnums.hpp>

#include <utility>

namespace HellSolver
{
//!
//! \brief Player class.
//!
//! This class represents a player of the game.
//!
class Player
{
 public:
    //! Default constructor.
    Player() = default;

    //! Default destructor.
    ~Player() = default;

    //! Constructs a player with given \p initX, \p initY and \p moveCount.
    //! \param initX The initial coordinate of X.
    //! \param initY The initial coordinate of Y.
    //! \param moveCount The initial move count.
    Player(std::size_t initX, std::size_t initY, std::size_t moveCount);

    //! Resets a player.
    //! \param initX The initial coordinate of X.
    //! \param initY The initial coordinate of Y.
    //! \param moveCount The initial move count.
    void Reset(std::size_t initX, std::size_t initY, std::size_t moveCount);

    //! Processes move by given \p dir and returns moved coordinate by pair.
    //! \param dir The direction to move.
    //! \return The moved coordinate represented by pair.
    [[nodiscard]] Position ProcessMove(Direction dir);

    //! Gets the status of the player.
    //! \param isEndPoint The flag for checking the player is on end point.
    //! \return The status of the player.
    [[nodiscard]] PlayerStatus GetPlayerStatus(bool isEndPoint) const;

    //! Gets the move count of the player.
    //! \return The move count of the player.
    [[nodiscard]] std::size_t GetMoveCount() const;

    //! Returns the flag which represents the player has key.
    //! \return The flag which represents the player has key.
    [[nodiscard]] bool HasKey() const;

    //! Sets the boolean flag when player gets a key.
    void SetKey();

    //! Gets the current position of the player.
    //! \return the current position of the player.
    [[nodiscard]] Position GetPosition() const;

    //! Decrease player's move count by one.
    void DecreaseMoveCount();

 private:
    std::size_t m_x = 0;
    std::size_t m_y = 0;
    std::size_t m_moveCount = 0;
    bool m_hasKey = false;
};
}  // namespace HellSolver

#endif  // HELL_SOLVER_PLAYER_HPP
