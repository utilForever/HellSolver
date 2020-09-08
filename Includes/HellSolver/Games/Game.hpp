//
// Created by flow on 2020-09-07.
//

#ifndef HELL_SOLVER_GAME_HPP
#define HELL_SOLVER_GAME_HPP

#include <HellSolver/Games/Map.hpp>
#include <HellSolver/Player/Player.hpp>

#include <string_view>

namespace hell_solver
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

    //! Gets map.
    //! \return the map.
    Map& GetMap();

    //! Checks an object can move.
    //! \param dir The direction to move.
    //! \return the flag indicates that the player can move.
    MoveState CanMove(std::size_t x, std::size_t y, Direction dir);

 private:
    //! Gets the moved coordinate of the player.
    //! \param x The original x position.
    //! \param y The original y position.
    //! \param dir The direction to move.
    //! \return the pair contains the coordinate of moved player.
    static std::pair<int, int> Move(std::size_t x, std::size_t y,
                                    Direction dir);
                                    
    MoveState CanMove(Direction dir);

 private:
    Map m_map;

    Player GamePlayer;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_GAME_HPP
