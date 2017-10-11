// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_ICONINFO_H
#define _GTKMM_ICONINFO_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2003 The gtkmm Development Team
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

#include <vector>

#include <gtkmm/stylecontext.h>
#include <gdkmm/rectangle.h>
#include <gdkmm/pixbuf.h>
#include <gdkmm/rgba.h>
#include <gdkmm/types.h>

//#include <gtk/gtkicontheme.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GtkIconInfo GtkIconInfo; }
#endif

namespace Gtk
{

class IconTheme;

class IconInfo
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef IconInfo CppObjectType;
  typedef GtkIconInfo BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type() G_GNUC_CONST;

  IconInfo();

  explicit IconInfo(GtkIconInfo* gobject, bool make_a_copy = true);

  IconInfo(const IconInfo& other);
  IconInfo& operator=(const IconInfo& other);

  ~IconInfo();

  void swap(IconInfo& other);

  ///Provides access to the underlying C instance.
  GtkIconInfo*       gobj()       { return gobject_; }

  ///Provides access to the underlying C instance.
  const GtkIconInfo* gobj() const { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  GtkIconInfo* gobj_copy() const;

protected:
  GtkIconInfo* gobject_;

private:

  
public:

  IconInfo(const Glib::RefPtr<IconTheme>& icon_theme, const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);
  

  /** This typedef is just to make it more obvious that
   * our operator const void* should be used like operator bool().
   */
  typedef const void* BoolExpr;

  /** Tests whether the IconInfo is valid.
   * For instance,
   * @code
   * if(iconinfo)
   *   do_something()
   * @endcode
   */
  operator BoolExpr() const;

  
  /** Gets the base size for the icon. The base size
   * is a size for the icon that was specified by
   * the icon theme creator. This may be different
   * than the actual size of image; an example of
   * this is small emblem icons that can be attached
   * to a larger icon. These icons will be given
   * the same base size as the larger icons to which
   * they are attached.
   * 
   * @newin{2,4}
   * @return The base size, or 0, if no base
   * size is known for the icon.
   */
  int get_base_size() const;
  
  /** Gets the filename for the icon. If the
   * Gtk::ICON_LOOKUP_USE_BUILTIN flag was passed
   * to Gtk::IconTheme::lookup_icon(), there may be
   * no filename if a builtin icon is returned; in this
   * case, you should use get_builtin_pixbuf().
   * 
   * @newin{2,4}
   * @return The filename for the icon, or <tt>0</tt>
   * if get_builtin_pixbuf() should
   * be used instead.
   */
  Glib::ustring get_filename() const;
  
  /** Gets the built-in image for this icon, if any. To allow
   * GTK+ to use built in icon images, you must pass the
   * Gtk::ICON_LOOKUP_USE_BUILTIN to
   * Gtk::IconTheme::lookup_icon().
   * 
   * @newin{2,4}
   * @return The built-in image pixbuf, or <tt>0</tt>.
   * The returned image must not be modified.
   */
  Glib::RefPtr<Gdk::Pixbuf> get_builtin_pixbuf();
  
  /** Gets the built-in image for this icon, if any. To allow
   * GTK+ to use built in icon images, you must pass the
   * Gtk::ICON_LOOKUP_USE_BUILTIN to
   * Gtk::IconTheme::lookup_icon().
   * 
   * @newin{2,4}
   * @return The built-in image pixbuf, or <tt>0</tt>.
   * The returned image must not be modified.
   */
  Glib::RefPtr<const Gdk::Pixbuf> get_builtin_pixbuf() const;
  
  /** Renders an icon previously looked up in an icon theme using
   * Gtk::IconTheme::lookup_icon(); the size will be based on the size
   * passed to Gtk::IconTheme::lookup_icon(). Note that the resulting
   * pixbuf may not be exactly this size; an icon theme may have icons
   * that differ slightly from their nominal sizes, and in addition GTK+
   * will avoid scaling icons that it considers sufficiently close to the
   * requested size or for which the source image would have to be scaled
   * up too far. (This maintains sharpness.). This behaviour can be changed
   * by passing the Gtk::ICON_LOOKUP_FORCE_SIZE flag when obtaining
   * the Gtk::IconInfo. If this flag has been specified, the pixbuf
   * returned by this function will be scaled to the exact size.
   * 
   * @newin{2,4}
   * @return The rendered icon; this may be a newly
   * created icon or a new reference to an internal icon, so you must
   * not modify the icon. Use Glib::object_unref() to release your reference
   * to the icon.
   */
  Glib::RefPtr<Gdk::Pixbuf> load_icon() const;

  //TODO: Documentation
  Glib::RefPtr<Gdk::Pixbuf> load_symbolic(const Gdk::RGBA& fg, const Gdk::RGBA& success_color, const Gdk::RGBA& warning_color, const Gdk::RGBA& error_color, bool& was_symbolic) const;
  

   //deprecated

  //TODO: Documentation:
  Glib::RefPtr<Gdk::Pixbuf> load_symbolic(const Glib::RefPtr<StyleContext>& style, bool& was_symbolic);
  

  /** Sets whether the coordinates returned by get_embedded_rect()
   * and get_attach_points() should be returned in their
   * original form as specified in the icon theme, instead of scaled
   * appropriately for the pixbuf returned by load_icon().
   * 
   * Raw coordinates are somewhat strange; they are specified to be with
   * respect to the unscaled pixmap for PNG and XPM icons, but for SVG
   * icons, they are in a 1000x1000 coordinate space that is scaled
   * to the final size of the icon.  You can determine if the icon is an SVG
   * icon by using get_filename(), and seeing if it is non-<tt>0</tt>
   * and ends in '.svg'.
   * 
   * This function is provided primarily to allow compatibility wrappers
   * for older API's, and is not expected to be useful for applications.
   * 
   * @newin{2,4}
   * @param raw_coordinates Whether the coordinates of embedded rectangles
   * and attached points should be returned in their original
   * (unscaled) form.
   */
  void set_raw_coordinates(bool raw_coordinates =  true);
  
  /** Gets the coordinates of a rectangle within the icon
   * that can be used for display of information such
   * as a preview of the contents of a text file.
   * See set_raw_coordinates() for further
   * information about the coordinate system.
   * 
   * @newin{2,4}
   * @param rectangle Gdk::Rectangle in which to store embedded
   * rectangle coordinates; coordinates are only stored
   * when this function returns <tt>true</tt>.
   * @return <tt>true</tt> if the icon has an embedded rectangle.
   */
  bool get_embedded_rect(Gdk::Rectangle& rectangle) const;

  //TODO: Documentation.
  std::vector<Gdk::Point> get_attach_points() const;

  
  /** Gets the display name for an icon. A display name is a
   * string to be used in place of the icon name in a user
   * visible context like a list of icons.
   * 
   * @newin{2,4}
   * @return The display name for the icon or <tt>0</tt>, if
   * the icon doesn't have a specified display name. This value
   * is owned @a icon_info and must not be modified or free.
   */
  Glib::ustring get_display_name() const;


};

} // namespace Gtk


namespace Gtk
{

/** @relates Gtk::IconInfo
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(IconInfo& lhs, IconInfo& rhs)
  { lhs.swap(rhs); }

} // namespace Gtk

namespace Glib
{

/** A Glib::wrap() method for this object.
 * 
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gtk::IconInfo
 */
Gtk::IconInfo wrap(GtkIconInfo* object, bool take_copy = false);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class Value<Gtk::IconInfo> : public Glib::Value_Boxed<Gtk::IconInfo>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_ICONINFO_H */
