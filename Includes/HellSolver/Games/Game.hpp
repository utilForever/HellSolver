//
// Created by flow on 2020-09-07.
//

#ifndef HELLSOLVER_GAME_HPP
#define HELLSOLVER_GAME_HPP

#include <HellSolver/Enums/GameEnums.hpp>

#include <string>

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

    //! Resets map and blocks.
    void Reset();

    //! Gets the player status of the game.
    //! \return The player status of the game.
    PlayerStatus GetPlayerStatus() const;

    //! Moves the player that represents player.
    //! \param dir The direction to move the player.
    void MovePlayer(Direction dir);
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_GAME_HPP
