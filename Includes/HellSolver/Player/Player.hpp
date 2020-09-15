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

    //! Constructs a player with given \p pos and \p moveCount.
    //! \param pos The position to initialize.
    //! \param moveCount The move count to initialize.
    Player(Position pos, std::size_t moveCount);

    //! Resets a player.
    //! \param pos The position to reset.
    //! \param moveCount The move count to reset.
    void Reset(Position pos, std::size_t moveCount);

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
    Position m_pos{ 0, 0 };
    std::size_t m_moveCount = 0;
    bool m_hasKey = false;
};
}  // namespace HellSolver

#endif  // HELL_SOLVER_PLAYER_HPP
