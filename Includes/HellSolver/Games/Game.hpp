// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_SOLVER_GAME_HPP
#define HELL_SOLVER_GAME_HPP

#include <HellSolver/Games/Map.hpp>
#include <HellSolver/Player/Player.hpp>

#include <string_view>

namespace hell_solver
{
using Position = std::pair<std::size_t, std::size_t>;

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

    //! Resets game.
    void Reset();

    //! Gets map.
    //! \return the map.
    [[nodiscard]] Map& GetMap();

    //! Gets map.
    //! \return the map.
    [[nodiscard]] const Map& GetMap() const;

    //! Gets player.
    //! \return the player.
    [[nodiscard]] Player& GetPlayer();

    //! Moves the player to the direction.
    //! \param dir The direction to move.
    //! \return the status of the player.
    [[nodiscard]] PlayerStatus MovePlayer(Direction dir);

 private:
    Map m_map;

    Player* GamePlayer;

    //! Checks an object can move.
    //! \param dir The direction to move.
    //! \return the flag indicates that the player can move.
    [[nodiscard]] MoveState CanMove(size_t x, size_t y, Direction dir);

    //! Move current coordinates to \p direction.
    //! \param x The current x coordinate.
    //! \param y The current y coordinate.
    //! \param dir The direction to move.
    //! \return The moved coordinate.
    static std::pair<std::size_t, std::size_t> Move(std::size_t x,
                                                    std::size_t y,
                                                    Direction dir);

    //! Push the rock.
    //! \param x The current x coordinate of rock.
    //! \param y The current y coordinate of rock.
    void PushRock(size_t x, size_t y, Direction dir);

    //! Push the undead.
    //! \param x The current x coordinate of undead.
    //! \param y The current y coordinate of undead.
    void PushUndead(size_t x, size_t y, Direction dir);
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_GAME_HPP
