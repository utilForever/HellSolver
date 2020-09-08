//
// Created by flow on 2020-09-07.
//

#ifndef HELL_SOLVER_GAME_HPP
#define HELL_SOLVER_GAME_HPP

#include <HellSolver/Enums/GameEnums.hpp>
#include <HellSolver/Games/Map.hpp>

#include <string>
#include <utility>

namespace hell_solver
{
using Position = std::pair<int, int>;

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

    //! Resets map and blocks.
    void Reset();

    Map& GetMap();

    [[nodiscard]] const Map& GetMap() const;

    //! Gets the player status of the game.
    //! \return The player status of the game.
    [[nodiscard]] PlayerStatus GetPlayerStatus() const;

    //! Checks an object can move.
    //! \param x The x position.
    //! \param y The y position.
    //! \param dir The direction to move.
    //! \return the flag indicates that the player can move.
    // MoveState CanMove(std::size_t x, std::size_t y, Direction dir);

 private:
    //! Gets the moved coordinate of the player.
    //! \param x The original x position.
    //! \param y The original y position.
    //! \param dir The direction to move.
    //! \return the pair contains the coordinate of moved player.
    static std::pair<int, int> Move(std::size_t x, std::size_t y, Direction dir);

    Map m_map;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_GAME_HPP
