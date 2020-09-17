// Copyright (c) 2020 HellSolver Team
// Chris Ohk, Juhan Cha, Woosung Joung, Yongwook Choi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HELL_SOLVER_OBJECT_HPP
#define HELL_SOLVER_OBJECT_HPP

#include <HellSolver/Enums/GameEnums.hpp>

namespace HellSolver
{
//!
//! \brief Object class.
//!
//! This class represents objects in a tile.
//! An object represents a tile, a tile can hold at most two object types.
//!
class Object
{
 public:
    //! Default constructor.
    Object() = default;

    //! Constructs an object.
    //! \param tile A pair of object types.
    explicit Object(Tile tile);

    //! Adds an object type.
    //! \param type An object type to add.
    void Add(ObjectType type);

    //! Removes an object type.
    //! \param type An object type to remove.
    void Remove(ObjectType type);

    //! Initializes an object type. Used only when loading the map data.
    //! \param type An object type to initialize.
    void Init(ObjectType type);

    //! Returns the flag that the object has \p type.
    //! \param type The type of the object to check.
    //! \return true if the object has \p type, false otherwise.
    [[nodiscard]] bool HasType(ObjectType type) const;

    //! Returns the flag that the object has \p type or \p args.
    //! \param type The type of the object to check.
    //! \param args The variadic arguments to check.
    //! \return true if the object has \p type or \p args, false otherwise.
    template <typename ObjectType, typename... ObjectTypes>
    [[nodiscard]] bool HasType(ObjectType type, ObjectTypes... args) const
    {
        return HasType(type) || HasType(args...);
    }

 private:
    Tile m_tile;
};
}  // namespace HellSolver

#endif  // HELL_SOLVER_OBJECT_HPP
