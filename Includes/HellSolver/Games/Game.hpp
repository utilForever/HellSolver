// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_SOLVER_GAME_HPP
#define HELL_SOLVER_GAME_HPP

#include <HellSolver/Games/Map.hpp>
#include <HellSolver/Player/Player.hpp>

#include <memory>
#include <string_view>

namespace HellSolver
{
//!
//! \brief Game class.
//!
//! This class represents game. A game is a structured form of Helltaker.
//!
class Game
{
 public:
    //! Constructs game with given \p filename.
    //! \param filename The file name to load a map.
    explicit Game(std::string_view filename);

    //! Resets a game.
    void Reset();

    //! Gets a map object.
    //! \return A reference to map object.
    [[nodiscard]] Map& GetMap();

    //! Gets a player.
    //! \return A reference to player object.
    [[nodiscard]] Player& GetPlayer() const;

    //! Moves the player to the direction.
    //! \param dir The direction to move.
    //! \return the status of the player.
    [[nodiscard]] PlayerStatus MovePlayer(Direction dir);

 private:
    //! Checks an object can move.
    //! \param pos The current position.
    //! \param dir The direction to move.
    //! \return true if an object can move, false otherwise.
    [[nodiscard]] MoveState CanMove(Position pos, Direction dir) const;

    //! Moves current position to \p direction.
    //! \param pos The current position.
    //! \param dir The direction to move.
    //! \return The moved coordinate.
    static Position Move(Position pos, Direction dir);

    //! Pushes the rock.
    //! \param pos The current position of the rock.
    //! \param dir The direction to push.
    void PushRock(Position pos, Direction dir) const;

    //! Pushes the undead.
    //! \param pos The current position of the undead.
    //! \param dir The direction to push.
    void PushUndead(Position pos, Direction dir) const;

    Map m_map;
    std::unique_ptr<Player> m_gamePlayer;
};
}  // namespace HellSolver

#endif  // HELL_SOLVER_GAME_HPP
