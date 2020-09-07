//
// Created by flow on 2020-09-07.
//

#ifndef HELLSOLVER_MAP_HPP
#define HELLSOLVER_MAP_HPP

#include <HellSolver/Enums/GameEnums.hpp>

#include <string>
#include <vector>

namespace hell_solver
{
typedef std::pair<std::size_t, std::size_t> Position;

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

    //! Loads the data of the map.
    //! \param filename The name of file to be loaded.
    void Load(std::string_view filename);

    //! Assigns an object to the map.
    //! \param x The x position.
    //! \param y The y position.
    //! \return An object at row and column.
    [[nodiscard]] ObjectType At(std::size_t x, std::size_t y) const;

 private:
    std::size_t m_width = 0;
    std::size_t m_height = 0;
    std::size_t m_count = 1;
    bool m_key = false;

    std::size_t m_initCount = 1;
    std::vector<std::vector<ObjectType>> m_board;
    std::vector<std::vector<ObjectType>> m_initBoard;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_MAP_HPP
