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

namespace hell_solver
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

    //! Constructs map with given \p width and \p height.
    //! \param width The size of the width.
    //! \param height The size of the height.
    Map(std::size_t width, std::size_t height, std::size_t count);

    //! Resets map data.
    void Reset();

    //! Gets the width of the map.
    //! \return The width of the map.
    [[nodiscard]] std::size_t GetWidth() const;

    //! Gets the height of the map.
    //! \return The height of the map.
    [[nodiscard]] std::size_t GetHeight() const;

    [[nodiscard]] std::pair<std::size_t, std::size_t> GetStartPoint() const;

    [[nodiscard]] std::size_t GetInitMoveCount() const;

    [[nodiscard]] bool GetLurker() const;

    void SetLurker();

    [[nodiscard]] bool IsLurkerAttack(Object& object) const;

    //! Loads the data of the map.
    //! \param filename The name of file to be loaded.
    void Load(std::string_view filename);

    //! Assigns an object to the map.
    //! \param x The x position.
    //! \param y The y position.
    //! \return An object at row and column.
    [[nodiscard]] Object& At(std::size_t x, std::size_t y) const;

 private:
    std::size_t m_width = 0;
    std::size_t m_height = 0;
    bool m_key = false;
    bool m_lurker = true;

    std::vector<Object> m_board;
    std::vector<Object> m_initBoard;
    std::size_t m_initCount = 1;
    std::pair<std::size_t, std::size_t> m_startPoint;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_MAP_HPP
