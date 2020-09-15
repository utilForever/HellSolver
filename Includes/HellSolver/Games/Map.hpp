// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_SOLVER_MAP_HPP
#define HELL_SOLVER_MAP_HPP

#include <HellSolver/Games/Object.hpp>

#include <string>
#include <vector>

namespace HellSolver
{
//!
//! \brief Map class.
//!
//! This class represents map. A map is a board of the game.
//!
class Map
{
 public:
    //! Default constructor.
    Map() = default;

    //! Loads the data of the map.
    //! \param filename The name of file to be loaded.
    void Load(std::string_view filename);

    //! Resets a map data.
    void Reset();

    //! Gets the width of the map.
    //! \return The width of the map.
    [[nodiscard]] std::size_t GetWidth() const;

    //! Gets the height of the map.
    //! \return The height of the map.
    [[nodiscard]] std::size_t GetHeight() const;

    //! Gets the start position of the map.
    //! \return The start position of the map.
    [[nodiscard]] Position GetStartPos() const;

    //! Gets the initial move count of the map.
    //! \return The initial move count of the map.
    [[nodiscard]] std::size_t GetInitMoveCount() const;

    //! Flips the value of lurker flag.
    void FlipLurkerFlag();

    //! Processes a list of undead objects in a map.
    void ProcessUndeadObjects();

    //! Returns the lurker can attack \p object at this move.
    //! \param object The object to be attacked by the lurker.
    //! \return true if the lurker can attack at this move, false otherwise.
    [[nodiscard]] bool CanLurkerAttackThisMove(Object& object) const;

    //! Returns the lurker can attack \p object at next move.
    //! \param object The object to be attacked by the lurker.
    //! \return true if the lurker can attack at next move, false otherwise.
    [[nodiscard]] bool CanLurkerAttackNextMove(Object& object) const;

    //! Assigns an object to the map.
    //! \param x The x position.
    //! \param y The y position.
    //! \return An object at row and column.
    [[nodiscard]] Object& At(std::size_t x, std::size_t y) const;

 private:
    std::size_t m_width = 0;
    std::size_t m_height = 0;

    std::vector<Object> m_initBoard;
    std::vector<Object> m_board;

    Position m_startPos;
    std::size_t m_initMoveCount = 1;

    bool m_lurkerFlag = true;
};
}  // namespace HellSolver

#endif  // HELL_SOLVER_MAP_HPP
