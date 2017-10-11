// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDKMM_CURSOR_H
#define _GDKMM_CURSOR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <gdkmm/color.h>
#include <gdkmm/display.h>
#include <gdkmm/pixbuf.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdkCursor GdkCursor;
typedef struct _GdkCursorClass GdkCursorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{ class Cursor_Class; } // namespace Gdk
namespace Gdk
{

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 * @ingroup gdkmmEnums
 */
enum CursorType
{
  X_CURSOR = 0,
  ARROW = 2,
  BASED_ARROW_DOWN = 4,
  BASED_ARROW_UP = 6,
  BOAT = 8,
  BOGOSITY = 10,
  BOTTOM_LEFT_CORNER = 12,
  BOTTOM_RIGHT_CORNER = 14,
  BOTTOM_SIDE = 16,
  BOTTOM_TEE = 18,
  BOX_SPIRAL = 20,
  CENTER_PTR = 22,
  CIRCLE = 24,
  CLOCK = 26,
  COFFEE_MUG = 28,
  CROSS = 30,
  CROSS_REVERSE = 32,
  CROSSHAIR = 34,
  DIAMOND_CROSS = 36,
  DOT = 38,
  DOTBOX = 40,
  DOUBLE_ARROW = 42,
  DRAFT_LARGE = 44,
  DRAFT_SMALL = 46,
  DRAPED_BOX = 48,
  EXCHANGE = 50,
  FLEUR = 52,
  GOBBLER = 54,
  GUMBY = 56,
  HAND1 = 58,
  HAND2 = 60,
  HEART = 62,
  ICON = 64,
  IRON_CROSS = 66,
  LEFT_PTR = 68,
  LEFT_SIDE = 70,
  LEFT_TEE = 72,
  LEFTBUTTON = 74,
  LL_ANGLE = 76,
  LR_ANGLE = 78,
  MAN = 80,
  MIDDLEBUTTON = 82,
  MOUSE = 84,
  PENCIL = 86,
  PIRATE = 88,
  PLUS = 90,
  QUESTION_ARROW = 92,
  RIGHT_PTR = 94,
  RIGHT_SIDE = 96,
  RIGHT_TEE = 98,
  RIGHTBUTTON = 100,
  RTL_LOGO = 102,
  SAILBOAT = 104,
  SB_DOWN_ARROW = 106,
  SB_H_DOUBLE_ARROW = 108,
  SB_LEFT_ARROW = 110,
  SB_RIGHT_ARROW = 112,
  SB_UP_ARROW = 114,
  SB_V_DOUBLE_ARROW = 116,
  SHUTTLE = 118,
  SIZING = 120,
  SPIDER = 122,
  SPRAYCAN = 124,
  STAR = 126,
  TARGET = 128,
  TCROSS = 130,
  TOP_LEFT_ARROW = 132,
  TOP_LEFT_CORNER = 134,
  TOP_RIGHT_CORNER = 136,
  TOP_SIDE = 138,
  TOP_TEE = 140,
  TREK = 142,
  UL_ANGLE = 144,
  UMBRELLA = 146,
  UR_ANGLE = 148,
  WATCH = 150,
  XTERM = 152,
  LAST_CURSOR = 153,
  BLANK_CURSOR = -2,
  CURSOR_IS_PIXMAP = -1
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::CursorType> : public Glib::Value_Enum<Gdk::CursorType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{


/** This represents a cursor.
 */

class Cursor : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Cursor CppObjectType;
  typedef Cursor_Class CppClassType;
  typedef GdkCursor BaseObjectType;
  typedef GdkCursorClass BaseClassType;

private:  friend class Cursor_Class;
  static CppClassType cursor_class_;

private:
  // noncopyable
  Cursor(const Cursor&);
  Cursor& operator=(const Cursor&);

protected:
  explicit Cursor(const Glib::ConstructParams& construct_params);
  explicit Cursor(GdkCursor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Cursor();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkCursor*       gobj()       { return reinterpret_cast<GdkCursor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkCursor* gobj() const { return reinterpret_cast<GdkCursor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkCursor* gobj_copy();

private:

   //We use DO_NOT_DERIVE_GTYPE because glib does not allow us to derive from a non-fundamental (abstract) type, for some reason.
   //deprecated

protected:

  explicit Cursor(const Glib::RefPtr<Display>& display, const Glib::ustring& name);
  

public:
  //We use _WRAP_METHOD() instead of _WRAP_CREATE() and constructors,
  //because the gdk_cursor_new_*() functions actually return existing instances sometimes,
  //but constructors assume that they own the instance.
  //And we would have to have to use the gdk_cursor_new_*() functions in the constructors anyway,
  //because they do more than just call g_object_new().
  
  /** Creates a new cursor from the set of builtin cursors for the default display.
   * See new_for_display().
   * 
   * To make the cursor invisible, use Gdk::BLANK_CURSOR.
   * @param cursor_type Cursor to create.
   * @return A new Gdk::Cursor.
   */
  static Glib::RefPtr<Cursor> create(CursorType cursor_type);
  
  /** Creates a new cursor from the set of builtin cursors.
   * Some useful ones are:
   * - 
   * <inlinegraphic format="PNG" fileref="right_ptr.png"></inlinegraphic> Gdk::RIGHT_PTR (right-facing arrow)
   * - 
   * <inlinegraphic format="PNG" fileref="crosshair.png"></inlinegraphic> Gdk::CROSSHAIR (crosshair)
   * - 
   * <inlinegraphic format="PNG" fileref="xterm.png"></inlinegraphic> Gdk::XTERM (I-beam)
   * - 
   * <inlinegraphic format="PNG" fileref="watch.png"></inlinegraphic> Gdk::WATCH (busy)
   * - 
   * <inlinegraphic format="PNG" fileref="fleur.png"></inlinegraphic> Gdk::FLEUR (for moving objects)
   * - 
   * <inlinegraphic format="PNG" fileref="hand1.png"></inlinegraphic> Gdk::HAND1 (a right-pointing hand)
   * - 
   * <inlinegraphic format="PNG" fileref="hand2.png"></inlinegraphic> Gdk::HAND2 (a left-pointing hand)
   * - 
   * <inlinegraphic format="PNG" fileref="left_side.png"></inlinegraphic> Gdk::LEFT_SIDE (resize left side)
   * - 
   * <inlinegraphic format="PNG" fileref="right_side.png"></inlinegraphic> Gdk::RIGHT_SIDE (resize right side)
   * - 
   * <inlinegraphic format="PNG" fileref="top_left_corner.png"></inlinegraphic> Gdk::TOP_LEFT_CORNER (resize northwest corner)
   * - 
   * <inlinegraphic format="PNG" fileref="top_right_corner.png"></inlinegraphic> Gdk::TOP_RIGHT_CORNER (resize northeast corner)
   * - 
   * <inlinegraphic format="PNG" fileref="bottom_left_corner.png"></inlinegraphic> Gdk::BOTTOM_LEFT_CORNER (resize southwest corner)
   * - 
   * <inlinegraphic format="PNG" fileref="bottom_right_corner.png"></inlinegraphic> Gdk::BOTTOM_RIGHT_CORNER (resize southeast corner)
   * - 
   * <inlinegraphic format="PNG" fileref="top_side.png"></inlinegraphic> Gdk::TOP_SIDE (resize top side)
   * - 
   * <inlinegraphic format="PNG" fileref="bottom_side.png"></inlinegraphic> Gdk::BOTTOM_SIDE (resize bottom side)
   * - 
   * <inlinegraphic format="PNG" fileref="sb_h_double_arrow.png"></inlinegraphic> Gdk::SB_H_DOUBLE_ARROW (move vertical splitter)
   * - 
   * <inlinegraphic format="PNG" fileref="sb_v_double_arrow.png"></inlinegraphic> Gdk::SB_V_DOUBLE_ARROW (move horizontal splitter)
   * - 
   * Gdk::BLANK_CURSOR (Blank cursor). Since 2.16
   * 
   * @newin{2,2}
   * @param display The Gdk::Display for which the cursor will be created.
   * @param cursor_type Cursor to create.
   * @return A new Gdk::Cursor.
   */
  static Glib::RefPtr<Cursor> create(const Glib::RefPtr<Display>& display, CursorType cursor_type);
  
  /** Creates a new cursor from a pixbuf.
   * 
   * Not all GDK backends support RGBA cursors. If they are not
   * supported, a monochrome approximation will be displayed.
   * The functions Gdk::Display::supports_cursor_alpha() and
   * Gdk::Display::supports_cursor_color() can be used to determine
   * whether RGBA cursors are supported;
   * Gdk::Display::get_default_cursor_size() and
   * Gdk::Display::get_maximal_cursor_size() give information about
   * cursor sizes.
   * 
   * If @a x or @a y are <tt>-1</tt>, the pixbuf must have
   * options named "x_hot" and "y_hot", resp., containing
   * integer values between %0 and the width resp. height of
   * the pixbuf. (@newin{3,0})
   * 
   * On the X backend, support for RGBA cursors requires a
   * sufficently new version of the X Render extension.
   * 
   * @newin{2,4}
   * @param display The Gdk::Display for which the cursor will be created.
   * @param pixbuf The Gdk::Pixbuf containing the cursor image.
   * @param x The horizontal offset of the 'hotspot' of the cursor.
   * @param y The vertical offset of the 'hotspot' of the cursor.
   * @return A new Gdk::Cursor.
   */
  static Glib::RefPtr<Cursor> create(const Glib::RefPtr<Display>& display, const Glib::RefPtr<Pixbuf>& pixbuf, int x, int y);
  
  /** Creates a new cursor by looking up @a name in the current cursor
   * theme.
   * 
   * @newin{2,8}
   * @param display The Gdk::Display for which the cursor will be created.
   * @param name The name of the cursor.
   * @return A new Gdk::Cursor, or <tt>0</tt> if there is no cursor with
   * the given name.
   */
  static Glib::RefPtr<Cursor> create(const Glib::RefPtr<Display>& display, const Glib::ustring& name);

  
  /** Returns the display on which the Gdk::Cursor is defined.
   * 
   * @newin{2,2}
   * @return The Gdk::Display associated to @a cursor.
   */
  Glib::RefPtr<Display> get_display();
  
  /** Returns the display on which the Gdk::Cursor is defined.
   * 
   * @newin{2,2}
   * @return The Gdk::Display associated to @a cursor.
   */
  Glib::RefPtr<const Display> get_display() const;

  
  /** Returns a Gdk::Pixbuf with the image used to display the cursor.
   * 
   * Note that depending on the capabilities of the windowing system and 
   * on the cursor, GDK may not be able to obtain the image data. In this 
   * case, <tt>0</tt> is returned.
   * 
   * @newin{2,8}
   * @return A Gdk::Pixbuf representing @a cursor, or <tt>0</tt>.
   */
  Glib::RefPtr<Gdk::Pixbuf> get_image();
  
  /** Returns a Gdk::Pixbuf with the image used to display the cursor.
   * 
   * Note that depending on the capabilities of the windowing system and 
   * on the cursor, GDK may not be able to obtain the image data. In this 
   * case, <tt>0</tt> is returned.
   * 
   * @newin{2,8}
   * @return A Gdk::Pixbuf representing @a cursor, or <tt>0</tt>.
   */
  Glib::RefPtr<const Gdk::Pixbuf> get_image() const;

  
  /** Returns the cursor type for this cursor.
   * 
   * @newin{2,22}
   * @return A Gdk::CursorType.
   */
  CursorType get_cursor_type() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Cursor
   */
  Glib::RefPtr<Gdk::Cursor> wrap(GdkCursor* object, bool take_copy = false);
}


#endif /* _GDKMM_CURSOR_H */
