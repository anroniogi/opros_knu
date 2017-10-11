// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDKMM_RGBA_H
#define _GDKMM_RGBA_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2010 The gtkmm Development Team
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
#include <gdk/gdk.h> //TODO: Remove this?


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GdkRGBA GdkRGBA; }
#endif

namespace Gdk
{

/** An RGBA Color.
 * The RGBA class is a convenient way to pass rgba colors around.
 * It's based on cairo's way to deal with (possibly translucent) colors and mirrors its behavior.
 * All values are in the range from 0.0 to 1.0 inclusive.
 * So the color (0.0, 0.0, 0.0, 0.0) represents transparent black and (1.0, 1.0, 1.0, 1.0) is opaque white.
 * Other values will be clamped to this range when drawing.
 */
class RGBA
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef RGBA CppObjectType;
  typedef GdkRGBA BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type() G_GNUC_CONST;


  explicit RGBA(GdkRGBA* gobject, bool make_a_copy = true);

  RGBA(const RGBA& other);
  RGBA& operator=(const RGBA& other);

  ~RGBA();

  void swap(RGBA& other);

  ///Provides access to the underlying C instance.
  GdkRGBA*       gobj()       { return gobject_; }

  ///Provides access to the underlying C instance.
  const GdkRGBA* gobj() const { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  GdkRGBA* gobj_copy() const;

protected:
  GdkRGBA* gobject_;

private:

  
public:

  
  /** Instantiate a new Gdk::RGBA.
   */
  RGBA();

  /** Instantiate a new Gdk::RGBA.
   * The text string can be in any of the forms accepted by XParseRGBA; these include names for a color from rgb.txt,
   * such as DarkSlateGray, or a hex specification such as 305050.
   * @param value the string specifying the color..
   */
  explicit RGBA(const Glib::ustring& value);
  

  /** Set a grey color, by using the same value for all color components.
   * @param value The value to be used for the red, green, and blue components.
   */
  void set_grey_u(gushort value, gushort alpha = 65535);
  void set_grey(double g, double alpha = 1.0);

  /** Set the color, by specifying red, green, and blue color component values.
   * @param red_ The red component of the color.
   * @param green_ The green component of the color.
   * @param blue_ The blue component of the color.
   */
  void set_rgba_u(gushort red_, gushort green_, gushort blue_, gushort alpha_ = 65535);

  /** Set the color, by specifying red, green, and blue color component values, as percentages.
   * @param red_ The red component of the color, as a percentage.
   * @param green_ The green component of the color, as a percentage.
   * @param blue_ The blue component of the color, as a percentage.
   */
  void set_rgba(double red_, double green_, double blue_, double alpha_ = 1.0);

  //TODO: Add alpha parameter?
  void set_hsv(double h, double s, double v);
  void set_hsl(double h, double s, double l);

  
  /** Parses a textual representation of a color, filling in
   * the <structfield>red</structfield>, <structfield>green</structfield>,
   * <structfield>blue</structfield> and <structfield>alpha</structfield>
   * fields of the @a rgba struct.
   * 
   * The string can be either one of:
   * - 
   * A standard name (Taken from the X11 rgb.txt file).
   * - 
   * A hex value in the form '#rgb' '#rrggbb' '#rrrgggbbb'
   * or '#rrrrggggbbbb'
   * - 
   * A RGB color in the form 'rgb(r,g,b)' (In this case the color will
   * have full opacity)
   * - 
   * A RGBA color in the form 'rgba(r,g,b,a)'
   * 
   * Where 'r', 'g', 'b' and 'a' are respectively the red, green, blue and
   * alpha color values. In the last two cases, r g and b are either integers
   * in the range 0 to 255 or precentage values in the range 0% to 100%, and
   * a is a floating point value in the range 0 to 1.
   * 
   * @newin{3,0}
   * @param spec The string specifying the color.
   * @return <tt>true</tt> if the parsing succeeded.
   */
  bool set(const Glib::ustring& value);

  /** Get the red component of the color.
   * @result The red component of the color.
   */
  gushort get_red_u() const;

  /** Get the green component of the color.
   * @result The green component of the color.
   */
  gushort get_green_u() const;

  /** Get the blue component of the color.
   * @result The blue component of the color.
   */
  gushort get_blue_u() const;

  /** Get the alpha component of the color.
   * @result The alpha component of the color.
   */
  gushort get_alpha_u() const;

  /** Set the red component of the color.
   * @param value The red component of the color.
   */
  void set_red_u(gushort value);

  /** Set the green component of the color.
   * @param value The green component of the color.
   */
  void set_green_u(gushort value);

  /** Set the blue component of the color.
   * @param value The blue component of the color.
   */
  void set_blue_u(gushort value);

  /** Set the alpha component of the color.
   * @param value The alpha component of the color.
   */
  void set_alpha_u(gushort value);


  /** Get the red component of the color, as a percentage.
   * @result The red component of the color, as a percentage.
   */
  double get_red() const;

  /** Get the green component of the color, as a percentage.
   * @result The green component of the color, as a percentage.
   */
  double get_green() const;

  /** Get the blue component of the color, as a percentage.
   * @result The blue component of the color, as a percentage.
   */
  double get_blue() const;

  /** Get the alpha component of the color, as a percentage.
   * @result The alpha component of the color, as a percentage.
   */
  double get_alpha() const;

  /** Set the red component of the color, as a percentage.
   * @param value The red component of the color.
   */
  void set_red(double value);

  /** Set the green component of the color, as a percentage.
   * @param value The green component of the color.
   */
  void set_green(double value);

  /** Set the blue component of the color, as a percentage.
   * @param value The blue component of the color.
   */
  void set_blue(double value);

  /** Set the alpha component of the color, as a percentage.
   * @param value The blue component of the color.
   */
  void set_alpha(double value);

  
  /** Set the alpha component of the color.
   * @param value The alpha component of the color.
   */
  Glib::ustring to_string() const;


};


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/* These traits are for arrays of GdkRGBA structs -- not pointer arrays.
 */
struct RGBATraits
{
  typedef Gdk::RGBA  CppType;
  typedef GdkRGBA    CType;
  typedef GdkRGBA    CTypeNonConst;

  static CType   to_c_type      (const CppType& obj) { return *obj.gobj(); }
  static CType   to_c_type      (const CType&   obj) { return obj; }
  static CppType to_cpp_type    (const CType&   obj) { return CppType(const_cast<CType*>(&obj), true); }
  static void    release_c_type (const CType&)       {}
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gdk


namespace Gdk
{

/** @relates Gdk::RGBA
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
bool operator==(const RGBA& lhs, const RGBA& rhs);

/** @relates Gdk::RGBA
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
bool operator!=(const RGBA& lhs, const RGBA& rhs);


} // namespace Gdk


namespace Gdk
{

/** @relates Gdk::RGBA
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(RGBA& lhs, RGBA& rhs)
  { lhs.swap(rhs); }

} // namespace Gdk

namespace Glib
{

/** A Glib::wrap() method for this object.
 * 
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gdk::RGBA
 */
Gdk::RGBA wrap(GdkRGBA* object, bool take_copy = false);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class Value<Gdk::RGBA> : public Glib::Value_Boxed<Gdk::RGBA>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GDKMM_RGBA_H */

