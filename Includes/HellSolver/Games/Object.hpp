//
// Created by flow on 2020-09-08.
//

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

    void Init(ObjectType type);

    //! Gets the type of object.
    //! \return Pair of object type.
    [[nodiscard]] Tile GetTypes() const;

    [[nodiscard]] bool HasType(ObjectType type) const;

 private:
    Tile o_tile;
};
}  // namespace hell_solver

#endif  // HELL_SOLVER_OBJECT_HPP
