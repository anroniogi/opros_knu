// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDKMM_TYPES_H
#define _GDKMM_TYPES_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <glibmm/value.h>
#include <gdk/gdk.h>
#include <gdkmmconfig.h>

/* Shadow ERROR macro (from wingdi.h).
 */
#if defined(ERROR) && !defined(GTKMM_MACRO_SHADOW_ERROR)
enum { GTKMM_MACRO_DEFINITION_ERROR = ERROR };
#undef ERROR
enum { ERROR = GTKMM_MACRO_DEFINITION_ERROR };
#define ERROR ERROR
#define GTKMM_MACRO_SHADOW_ERROR 1
#endif

/*********************************************************************
***** Version macros
*********************************************************************/

/* macro for controlling version numbers */
#ifndef _GDK_VERSION

#define GDK_VERSION_GT(major,minor) ((GTK_MAJOR_VERSION>major)||(GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION>minor))
#define GDK_VERSION_GE(major,minor) ((GTK_MAJOR_VERSION>major)||(GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION>=minor))
#define GDK_VERSION_EQ(major,minor) ((GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION==minor))
#define GDK_VERSION_NE(major,minor) ((GTK_MAJOR_VERSION!=major)||(GTK_MINOR_VERSION!=minor))
#define GDK_VERSION_LE(major,minor) ((GTK_MAJOR_VERSION<major)||(GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION<=minor))
#define GDK_VERSION_LT(major,minor) ((GTK_MAJOR_VERSION<major)||(GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION<minor))

//Note: Use GTK_CHECK_VERSION to check that a version is equal or more than (the micro version).

#endif /* _GDK_VERSION */

namespace Gdk
{

class Window;
class Font;
class Color;

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 * @ingroup gdkmmEnums
 */
enum ByteOrder
{
  LSB_FIRST,
  MSB_FIRST
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::ByteOrder> : public Glib::Value_Enum<Gdk::ByteOrder>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{

/**
 * @ingroup gdkmmEnums
 * @par Bitwise operators:
 * <tt>%ModifierType operator|(ModifierType, ModifierType)</tt><br>
 * <tt>%ModifierType operator&(ModifierType, ModifierType)</tt><br>
 * <tt>%ModifierType operator^(ModifierType, ModifierType)</tt><br>
 * <tt>%ModifierType operator~(ModifierType)</tt><br>
 * <tt>%ModifierType& operator|=(ModifierType&, ModifierType)</tt><br>
 * <tt>%ModifierType& operator&=(ModifierType&, ModifierType)</tt><br>
 * <tt>%ModifierType& operator^=(ModifierType&, ModifierType)</tt><br>
 */
enum ModifierType
{
  SHIFT_MASK = 1 << 0,
  LOCK_MASK = 1 << 1,
  CONTROL_MASK = 1 << 2,
  MOD1_MASK = 1 << 3,
  MOD2_MASK = 1 << 4,
  MOD3_MASK = 1 << 5,
  MOD4_MASK = 1 << 6,
  MOD5_MASK = 1 << 7,
  BUTTON1_MASK = 1 << 8,
  BUTTON2_MASK = 1 << 9,
  BUTTON3_MASK = 1 << 10,
  BUTTON4_MASK = 1 << 11,
  BUTTON5_MASK = 1 << 12,
  MODIFIER_RESERVED_13_MASK = 1 << 13,
  MODIFIER_RESERVED_14_MASK = 1 << 14,
  MODIFIER_RESERVED_15_MASK = 1 << 15,
  MODIFIER_RESERVED_16_MASK = 1 << 16,
  MODIFIER_RESERVED_17_MASK = 1 << 17,
  MODIFIER_RESERVED_18_MASK = 1 << 18,
  MODIFIER_RESERVED_19_MASK = 1 << 19,
  MODIFIER_RESERVED_20_MASK = 1 << 20,
  MODIFIER_RESERVED_21_MASK = 1 << 21,
  MODIFIER_RESERVED_22_MASK = 1 << 22,
  MODIFIER_RESERVED_23_MASK = 1 << 23,
  MODIFIER_RESERVED_24_MASK = 1 << 24,
  MODIFIER_RESERVED_25_MASK = 1 << 25,
  SUPER_MASK = 1 << 26,
  HYPER_MASK = 1 << 27,
  META_MASK = 1 << 28,
  MODIFIER_RESERVED_29_MASK = 1 << 29,
  RELEASE_MASK = 1 << 30,
  MODIFIER_MASK = 0x5c001fff
};

/** @ingroup gdkmmEnums */
inline ModifierType operator|(ModifierType lhs, ModifierType rhs)
  { return static_cast<ModifierType>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline ModifierType operator&(ModifierType lhs, ModifierType rhs)
  { return static_cast<ModifierType>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline ModifierType operator^(ModifierType lhs, ModifierType rhs)
  { return static_cast<ModifierType>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline ModifierType operator~(ModifierType flags)
  { return static_cast<ModifierType>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline ModifierType& operator|=(ModifierType& lhs, ModifierType rhs)
  { return (lhs = static_cast<ModifierType>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline ModifierType& operator&=(ModifierType& lhs, ModifierType rhs)
  { return (lhs = static_cast<ModifierType>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline ModifierType& operator^=(ModifierType& lhs, ModifierType rhs)
  { return (lhs = static_cast<ModifierType>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::ModifierType> : public Glib::Value_Flags<Gdk::ModifierType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{

/**
 * @ingroup gdkmmEnums
 */
enum ModifierIntent
{
  MODIFIER_INTENT_PRIMARY_ACCELERATOR,
  MODIFIER_INTENT_CONTEXT_MENU,
  MODIFIER_INTENT_EXTEND_SELECTION,
  MODIFIER_INTENT_MODIFY_SELECTION,
  MODIFIER_INTENT_NO_TEXT_INPUT,
  MODIFIER_INTENT_SHIFT_GROUP
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::ModifierIntent> : public Glib::Value_Enum<Gdk::ModifierIntent>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{

/**
 * @ingroup gdkmmEnums
 */
enum Status
{
  OK = 0,
  ERROR = -1,
  ERROR_PARAM = -2,
  ERROR_FILE = -3,
  ERROR_MEM = -4
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::Status> : public Glib::Value_Enum<Gdk::Status>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{


typedef GdkGeometry Geometry; //It's not used enough to justify having a wrapper.

/** This is a simple structure containing an x and y coordinate of a point.
 */
class Point
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Point CppObjectType;
  typedef GdkPoint BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  Point();
  Point(int x, int y);

  void set_x(int x) { gobject_.x = x; }
  void set_y(int y) { gobject_.y = y; }

  int get_x() const { return gobject_.x; }
  int get_y() const { return gobject_.y; }

  bool equal(const Gdk::Point& rhs) const;

  /// Provides access to the underlying C GObject.
  GdkPoint*       gobj()       { return &gobject_; }
  /// Provides access to the underlying C GObject.
  const GdkPoint* gobj() const { return &gobject_; }

protected:
  GdkPoint gobject_;


};

/** @relates Gdk::Point */
inline bool operator==(const Point& lhs, const Point& rhs)
  { return lhs.equal(rhs); }

/** @relates Gdk::Point */
inline bool operator!=(const Point& lhs, const Point& rhs)
  { return !lhs.equal(rhs); }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct PointTraits
{
  typedef Gdk::Point     CppType;
  typedef GdkPoint       CType;
  typedef GdkPoint       CTypeNonConst;

  static CType   to_c_type      (CType c_obj)            { return c_obj; }
  static void    release_c_type (CType)                  {}
  static CType   to_c_type      (const CppType& cpp_obj) { return *(cpp_obj.gobj ()); }
  static CppType to_cpp_type    (CType c_obj)            { return CppType (c_obj.x, c_obj.y); }
};

struct AtomStringTraits
{
  typedef std::string CppType;
  typedef GdkAtom     CType;
  typedef GdkAtom     CTypeNonConst;

  static GdkAtom to_c_type(GdkAtom atom) { return atom; }
  static void    release_c_type(GdkAtom) {}

  // These aren't worth to be inlined since doing so
  // would expose way too much of the implementation.
  static GdkAtom     to_c_type  (const std::string& atom_name);
  static std::string to_cpp_type(GdkAtom atom);
};

// I'm typedef'ing this because when we call to_c_type or to_c_type,
// we don't want it to look like we're calling a template trait, but
// a utility function. -Bryan
typedef AtomStringTraits AtomString;

struct AtomUstringTraits
{
  typedef Glib::ustring CppType;
  typedef GdkAtom     CType;
  typedef GdkAtom     CTypeNonConst;

  static GdkAtom to_c_type(GdkAtom atom) { return atom; }
  static void    release_c_type(GdkAtom) {}

  // These aren't worth to be inlined since doing so
  // would expose way too much of the implementation.
  static GdkAtom     to_c_type  (const Glib::ustring& atom_name);
  static Glib::ustring to_cpp_type(GdkAtom atom);
};

typedef AtomUstringTraits AtomUstring;
#endif //DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gdk


namespace Glib
{

/** @relates Gdk::Point */
Gdk::Point& wrap(GdkPoint* object);

/** @relates Gdk::Point */
const Gdk::Point& wrap(const GdkPoint* object);

} // namespace Glib


#endif /* _GDKMM_TYPES_H */
