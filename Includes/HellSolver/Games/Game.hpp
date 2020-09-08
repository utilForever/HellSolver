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
    Map& GetMap();

    Player& GetPlayer();

    MoveState CanMove(Direction dir);

    //! Checks an object can move.
    //! \param dir The direction to move.
    //! \return the flag indicates that the player can move.
    MoveState CanMove(size_t x, size_t y, Direction dir);

    //! Moves the player to the direction.
    //! \param dir The direction to move.
    //! \return the status of the player.
    PlayerStatus MovePlayer(Direction dir);

 private:
    Map m_map;

    Player* GamePlayer;

    static std::pair<std::size_t, std::size_t> Move(std::size_t x,
                                                    std::size_t y,
                                                    Direction dir);
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_GAME_HPP
