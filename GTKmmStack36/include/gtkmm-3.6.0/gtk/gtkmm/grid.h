// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_GRID_H
#define _GTKMM_GRID_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <gtkmm/container.h>
#include <gtkmm/orientable.h>
#include <gtkmm/enums.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkGrid GtkGrid;
typedef struct _GtkGridClass GtkGridClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class Grid_Class; } // namespace Gtk
namespace Gtk
{

/** A container which arranges its child widgets in rows and columns.
 * It is a very similar to Table and Box,
 * but it consistently uses Widget's margin and expand
 * properties instead of custom child properties, and it fully supports
 * height-for-width geometry management.
 *
 * Children are added using attach(). They can span multiple
 * rows or columns. It is also possible to add a child next to an
 * existing child, using attach_next_to().
 *
 * Grid can be used like a Box by just using Gtk::Container::add(),
 * which will place children next to each other in the direction determined
 * by the orientation property.
 *
 * @ingroup Widgets
 * @ingroup Containers
 *
 * @newin{3,0}
 */

class Grid
  : public Container,
    public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Grid CppObjectType;
  typedef Grid_Class CppClassType;
  typedef GtkGrid BaseObjectType;
  typedef GtkGridClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~Grid();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Grid_Class;
  static CppClassType grid_class_;

  // noncopyable
  Grid(const Grid&);
  Grid& operator=(const Grid&);

protected:
  explicit Grid(const Glib::ConstructParams& construct_params);
  explicit Grid(GtkGrid* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkGrid*       gobj()       { return reinterpret_cast<GtkGrid*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkGrid* gobj() const { return reinterpret_cast<GtkGrid*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

  
public:
  Grid();

  //TODO: Add a Grid(Orientation orientation = ORIENTATION_HORIZONTAL) constructor to match the Paned and Box ones?

  
  /** Adds a widget to the grid.
   * 
   * The position of @a child is determined by @a left and @a top. The
   * number of 'cells' that @a child will occupy is determined by
   *  @a width and @a height.
   * @param child The widget to add.
   * @param left The column number to attach the left side of @a child to.
   * @param top The row number to attach the top side of @a child to.
   * @param width The number of columns that @a child will span.
   * @param height The number of rows that @a child will span.
   */
  void attach(Widget& child, int left, int top, int width, int height);
  
  /** Adds a widget to the grid.
   * 
   * The widget is placed next to @a sibling, on the side determined by
   *  @a side. When @a sibling is <tt>0</tt>, the widget is placed in row (for
   * left or right placement) or column 0 (for top or bottom placement),
   * at the end indicated by @a side.
   * 
   * Attaching widgets labeled [1], [2], [3] with @a sibling == <tt>0</tt> and
   *  @a side == Gtk::POS_LEFT yields a layout of [3][2][1].
   * @param child The widget to add.
   * @param sibling The child of @a grid that @a child will be placed
   * next to, or <tt>0</tt> to place @a child at the beginning or end.
   * @param side The side of @a sibling that @a child is positioned next to.
   * @param width The number of columns that @a child will span.
   * @param height The number of rows that @a child will span.
   */
  void attach_next_to(Widget& child, Widget& sibling, PositionType side, int width, int height);

  
  /** Gets the child of @a grid whose area covers the grid
   * cell whose upper left corner is at @a left, @a top.
   * 
   * @newin{3,2}
   * @param left The left edge of the cell.
   * @param top The top edge of the cell.
   * @return The child at the given position, or <tt>0</tt>.
   */
  Widget* get_child_at(int left, int top);
  
  /** Gets the child of @a grid whose area covers the grid
   * cell whose upper left corner is at @a left, @a top.
   * 
   * @newin{3,2}
   * @param left The left edge of the cell.
   * @param top The top edge of the cell.
   * @return The child at the given position, or <tt>0</tt>.
   */
  const Widget* get_child_at(int left, int top) const;
  
  /** Inserts a row at the specified position.
   * 
   * Children which are attached at or below this position
   * are moved one row down. Children which span across this
   * position are grown to span the new row.
   * 
   * @newin{3,2}
   * @param position The position to insert the row at.
   */
  void insert_row(int position);
  
  /** Inserts a column at the specified position.
   * 
   * Children which are attached at or to the right of this position
   * are moved one column to the right. Children which span across this
   * position are grown to span the new column.
   * 
   * @newin{3,2}
   * @param position The position to insert the column at.
   */
  void insert_column(int position);
  
  /** Inserts a row or column at the specified position.
   * 
   * The new row or column is placed next to @a sibling, on the side
   * determined by @a side. If @a side is Gtk::POS_TOP or Gtk::POS_BOTTOM,
   * a row is inserted. If @a side is Gtk::POS_LEFT of Gtk::POS_RIGHT,
   * a column is inserted.
   * 
   * @newin{3,2}
   * @param sibling The child of @a grid that the new row or column will be
   * placed next to.
   * @param side The side of @a sibling that @a child is positioned next to.
   */
  void insert_next_to(Widget& sibling, PositionType side);

  
  /** Sets whether all rows of @a grid will have the same height.
   * @param homogeneous <tt>true</tt> to make rows homogeneous.
   */
  void set_row_homogeneous(bool homogeneous =  true);
  
  /** Returns whether all rows of @a grid have the same height.
   * @return Whether all rows of @a grid have the same height.
   */
  bool get_row_homogeneous() const;
  
  /** Sets the amount of space between rows of @a grid.
   * @param spacing The amount of space to insert between rows.
   */
  void set_row_spacing(guint spacing);
  
  /** Returns the amount of space between the rows of @a grid.
   * @return The row spacing of @a grid.
   */
  guint get_row_spacing() const;
  
  /** Sets whether all columns of @a grid will have the same width.
   * @param homogeneous <tt>true</tt> to make columns homogeneous.
   */
  void set_column_homogeneous(bool homogeneous);
  
  /** Returns whether all columns of @a grid have the same width.
   * @return Whether all columns of @a grid have the same width.
   */
  bool get_column_homogeneous() const;
  
  /** Sets the amount of space between columns of @a grid.
   * @param spacing The amount of space to insert between columns.
   */
  void set_column_spacing(guint spacing);
  
  /** Returns the amount of space between the columns of @a grid.
   * @return The column spacing of @a grid.
   */
  guint get_column_spacing() const;

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The amount of space between two consecutive rows.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< guint > property_row_spacing() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The amount of space between two consecutive rows.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< guint > property_row_spacing() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The amount of space between two consecutive columns.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< guint > property_column_spacing() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The amount of space between two consecutive columns.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< guint > property_column_spacing() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** If TRUE, the rows are all the same height.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_row_homogeneous() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** If TRUE, the rows are all the same height.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_row_homogeneous() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** If TRUE, the columns are all the same width.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_column_homogeneous() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** If TRUE, the columns are all the same width.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_column_homogeneous() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Grid
   */
  Gtk::Grid* wrap(GtkGrid* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_GRID_H */
