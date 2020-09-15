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
    [[nodiscard]] Player& GetPlayer();

    //! Moves the player to the direction.
    //! \param dir The direction to move.
    //! \return the status of the player.
    [[nodiscard]] PlayerStatus MovePlayer(Direction dir);

 private:
    Map m_map;

    std::unique_ptr<Player> GamePlayer;

    //! Checks an object can move.
    //! \param x The current x coordinate.
    //! \param y The current y coordinate.
    //! \param dir The direction to move.
    //! \return true if an object can move, false otherwise.
    [[nodiscard]] MoveState CanMove(size_t x, size_t y, Direction dir);

    //! Moves current coordinates to \p direction.
    //! \param x The current x coordinate.
    //! \param y The current y coordinate.
    //! \param dir The direction to move.
    //! \return The moved coordinate.
    static std::pair<std::size_t, std::size_t> Move(std::size_t x,
                                                    std::size_t y,
                                                    Direction dir);

    //! Pushes the rock.
    //! \param x The current x coordinate of the rock.
    //! \param y The current y coordinate of the rock.
    //! \param dir The direction to push.
    void PushRock(size_t x, size_t y, Direction dir);

    //! Pushes the undead.
    //! \param x The current x coordinate of the undead.
    //! \param y The current y coordinate of the undead.
    //! \param dir The direction to push.
    void PushUndead(size_t x, size_t y, Direction dir);
};
}  // namespace HellSolver

#endif  // HELL_SOLVER_GAME_HPP
