// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_LINKBUTTON_H
#define _GTKMM_LINKBUTTON_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2006 The gtkmm Development Team
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

#include <gtkmm/button.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkLinkButton GtkLinkButton;
typedef struct _GtkLinkButtonClass GtkLinkButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class LinkButton_Class; } // namespace Gtk
namespace Gtk
{

//TODO: Remove the mention of set_*_hook() when the C documentation has been fixed: https://bugzilla.gnome.org/show_bug.cgi?id=339745
/** Create buttons bound to a URL.
 *
 * A Gtk::LinkButton is a Gtk::Button with a hyperlink, similar to the one
 * used by web browsers, which triggers an action when clicked. It is useful
 * to show quick links to resources.
 *
 * The URI bound to a Gtk::LinkButton can be set specifically using set_uri(),
 * and retrieved using get_uri().
 * By default, Gtk::LinkButton calls gtk_show_uri() when the button is clicked.
 * This behaviour can be overridden by connecting to the activate_link signal and
 * returning true from the signal handler.
 *
 * The LinkButton widget looks like this:
 * @image html linkbutton1.png
 *
 * @newin{2,10}
 * @ingroup Widgets
 */

class LinkButton : public Button
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef LinkButton CppObjectType;
  typedef LinkButton_Class CppClassType;
  typedef GtkLinkButton BaseObjectType;
  typedef GtkLinkButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~LinkButton();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class LinkButton_Class;
  static CppClassType linkbutton_class_;

  // noncopyable
  LinkButton(const LinkButton&);
  LinkButton& operator=(const LinkButton&);

protected:
  explicit LinkButton(const Glib::ConstructParams& construct_params);
  explicit LinkButton(GtkLinkButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkLinkButton*       gobj()       { return reinterpret_cast<GtkLinkButton*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkLinkButton* gobj() const { return reinterpret_cast<GtkLinkButton*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_activate_link().
  virtual bool on_activate_link();


private:

public:
  LinkButton();
  explicit LinkButton(const Glib::ustring& uri);
  
    explicit LinkButton(const Glib::ustring& uri, const Glib::ustring& label);


  /** Retrieves the URI set using set_uri().
   * 
   * @newin{2,10}
   * @return A valid URI.  The returned string is owned by the link button
   * and should not be modified or freed.
   */
  Glib::ustring get_uri() const;
  
  /** Sets @a uri as the URI where the Gtk::LinkButton points. As a side-effect
   * this unsets the 'visited' state of the button.
   * 
   * @newin{2,10}
   * @param uri A valid URI.
   */
  void set_uri(const Glib::ustring& uri);

  
  /** Retrieves the 'visited' state of the URI where the Gtk::LinkButton
   * points. The button becomes visited when it is clicked. If the URI
   * is changed on the button, the 'visited' state is unset again.
   * 
   * The state may also be changed using set_visited().
   * 
   * @newin{2,14}
   * @return <tt>true</tt> if the link has been visited, <tt>false</tt> otherwise.
   */
  bool get_visited() const;
  
  /** Sets the 'visited' state of the URI where the Gtk::LinkButton
   * points.  See get_visited() for more details.
   * 
   * @newin{2,14}
   * @param visited The new 'visited' state.
   */
  void set_visited(bool visited =  true);

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The URI bound to this button.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Glib::ustring > property_uri() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The URI bound to this button.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_uri() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether this link has been visited.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_visited() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether this link has been visited.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_visited() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


/**
   * @par Slot Prototype:
   * <tt>bool on_my_%activate_link()</tt>
   *
   * The signal_activate_link() signal is emitted each time the Gtk::LinkButton
   * has been clicked.
   * 
   * The default handler will call gtk_show_uri() with the URI stored inside
   * the Gtk::LinkButton::property_uri() property.
   * 
   * To override the default behavior, you can connect to the signal_activate_link()
   * signal and stop the propagation of the signal by returning <tt>true</tt> from
   * your handler.
   */

  Glib::SignalProxy0< bool > signal_activate_link();


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
   * @relates Gtk::LinkButton
   */
  Gtk::LinkButton* wrap(GtkLinkButton* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_LINKBUTTON_H */

