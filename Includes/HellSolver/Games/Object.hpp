// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_SOLVER_OBJECT_HPP
#define HELL_SOLVER_OBJECT_HPP

#include <HellSolver/Enums/GameEnums.hpp>

namespace hell_solver
{
//!
//! \brief Object class.
//!
//! This class represents objects in one tile.
//! One object represents one tile, tile can hold at most two object types.
//!
class Object
{
 public:
    //! Default constructor.
    Object() = default;

    //! Constructs an object.
    //! \param types A pair of object types.
    explicit Object(Tile tile);

    //! Adds an object type.
    void Add(ObjectType type);

    //! Removes an object type.
    //! \param types An object type to remove.
    void Remove(ObjectType type);

    //! Initializes an object type.
    //! Used only when loading the map data.
    //! \param types An object type to initialize.
    void Init(ObjectType type);

    //! Gets the type of object.
    //! \return Pair of object type.
    [[nodiscard]] Tile GetTypes() const;

    //! Returns true if the object has the \p type.
    //! \return true if the object has the \p type.
    [[nodiscard]] bool HasType(ObjectType type) const;

 private:
    Tile o_tile;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_OBJECT_HPP
