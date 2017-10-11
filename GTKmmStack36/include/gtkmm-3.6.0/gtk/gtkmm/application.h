// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_APPLICATION_H
#define _GTKMM_APPLICATION_H

#include <gtkmmconfig.h>


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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <vector>

#include <gtkmm/actiongroup.h>
#include <giomm/application.h>
#include <giomm/menumodel.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkApplication GtkApplication;
typedef struct _GtkApplicationClass GtkApplicationClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class Application_Class; } // namespace Gtk
namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%ApplicationInhibitFlags operator|(ApplicationInhibitFlags, ApplicationInhibitFlags)</tt><br>
 * <tt>%ApplicationInhibitFlags operator&(ApplicationInhibitFlags, ApplicationInhibitFlags)</tt><br>
 * <tt>%ApplicationInhibitFlags operator^(ApplicationInhibitFlags, ApplicationInhibitFlags)</tt><br>
 * <tt>%ApplicationInhibitFlags operator~(ApplicationInhibitFlags)</tt><br>
 * <tt>%ApplicationInhibitFlags& operator|=(ApplicationInhibitFlags&, ApplicationInhibitFlags)</tt><br>
 * <tt>%ApplicationInhibitFlags& operator&=(ApplicationInhibitFlags&, ApplicationInhibitFlags)</tt><br>
 * <tt>%ApplicationInhibitFlags& operator^=(ApplicationInhibitFlags&, ApplicationInhibitFlags)</tt><br>
 */
enum ApplicationInhibitFlags
{
  APPLICATION_INHIBIT_LOGOUT = (1 << 0),
  APPLICATION_INHIBIT_SWITCH = (1 << 1),
  APPLICATION_INHIBIT_SUSPEND = (1 << 2),
  APPLICATION_INHIBIT_IDLE = (1 << 3)
};

/** @ingroup gtkmmEnums */
inline ApplicationInhibitFlags operator|(ApplicationInhibitFlags lhs, ApplicationInhibitFlags rhs)
  { return static_cast<ApplicationInhibitFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline ApplicationInhibitFlags operator&(ApplicationInhibitFlags lhs, ApplicationInhibitFlags rhs)
  { return static_cast<ApplicationInhibitFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline ApplicationInhibitFlags operator^(ApplicationInhibitFlags lhs, ApplicationInhibitFlags rhs)
  { return static_cast<ApplicationInhibitFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline ApplicationInhibitFlags operator~(ApplicationInhibitFlags flags)
  { return static_cast<ApplicationInhibitFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline ApplicationInhibitFlags& operator|=(ApplicationInhibitFlags& lhs, ApplicationInhibitFlags rhs)
  { return (lhs = static_cast<ApplicationInhibitFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline ApplicationInhibitFlags& operator&=(ApplicationInhibitFlags& lhs, ApplicationInhibitFlags rhs)
  { return (lhs = static_cast<ApplicationInhibitFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline ApplicationInhibitFlags& operator^=(ApplicationInhibitFlags& lhs, ApplicationInhibitFlags rhs)
  { return (lhs = static_cast<ApplicationInhibitFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::ApplicationInhibitFlags> : public Glib::Value_Flags<Gtk::ApplicationInhibitFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


class Window;

//TODO: Add overview documentation discussing the techniques show in the examples in gtkmm-docmentation.

/** TODO
 *
 * @newin{3,4}
 */

class Application
  : public Gio::Application
{
protected:
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Application CppObjectType;
  typedef Application_Class CppClassType;
  typedef GtkApplication BaseObjectType;
  typedef GtkApplicationClass BaseClassType;

private:  friend class Application_Class;
  static CppClassType application_class_;

private:
  // noncopyable
  Application(const Application&);
  Application& operator=(const Application&);

protected:
  explicit Application(const Glib::ConstructParams& construct_params);
  explicit Application(GtkApplication* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Application();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkApplication*       gobj()       { return reinterpret_cast<GtkApplication*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkApplication* gobj() const { return reinterpret_cast<GtkApplication*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkApplication* gobj_copy();

private:


protected:

  /** Creates a new Application instance.
   *
   * This initializes gtkmm (and the GObject type system) for you.
   *
   * If non-empty, the application ID must be valid.  See
   * g_application_id_is_valid().
   *
   * If no application ID is given then some features (most notably application
   * uniqueness) will be disabled. A null application ID is only allowed with
   * gtkmm 3.6 or later.
   *
   * @param application_id A valid application ID.
   * @param flags The application flags.
   *
   * @newin{3,4}
   */
  explicit Application(const Glib::ustring& application_id = Glib::ustring(), Gio::ApplicationFlags flags = Gio::APPLICATION_FLAGS_NONE);
  
  
  //This constructor does not correspond to anything in the C API.
  //We added it so we can choose to always initialize gtkmm as early as possible.
  //See https://bugzilla.gnome.org/show_bug.cgi?id=639925
  /** Creates a new Application instance.
   *
   * This initializes gtkmm (and the GObject type system) for you, parsing the
   * standard GTK+ command line arguments.
   *
   * You could instead use the constuctor that takes no command line arguements
   * and later supply the command line arguments to run().
   *
   * Note that all GTK+ functionality that is available via command line arguments
   * can instead be achieved by setting suitable environment variables
   * such as G_DEBUG.
   *
   * If non-empty, the application ID must be valid.  See
   * g_application_id_is_valid().
   *
   * If no application ID is given then some features (most notably application
   * uniqueness) will be disabled. A null application ID is only allowed with
   * gtkmm 3.6 or later.
   *
   * @param argc The parameter received by your main() function.
   * @param argv The parameter received by your main() function.
   * @param application_id A valid application ID.
   * @param flags The application flags.
   *
   * @newin{3,4}
   */
  explicit Application(int& argc, char**& argv, const Glib::ustring& application_id = Glib::ustring(), Gio::ApplicationFlags flags = Gio::APPLICATION_FLAGS_NONE);

public:

  /** Creates a new Application instance.
   *
   * This initializes gtkmm (and the GObject type system) for you.
   *
   * If non-empty, the application ID must be valid.  See
   * g_application_id_is_valid().
   *
   * If no application ID is given then some features (most notably application
   * uniqueness) will be disabled. A null application ID is only allowed with
   * gtkmm 3.6 or later.
   *
   * @param application_id A valid application ID.
   * @param flags The application flags.
   *
   * @newin{3,4}
   */
  static Glib::RefPtr<Application> create(const Glib::ustring& application_id = Glib::ustring(), Gio::ApplicationFlags flags = Gio::APPLICATION_FLAGS_NONE);

  /** Creates a new Application instance.
   *
   * This initializes gtkmm (and the GObject type system) for you, parsing the
   * standard GTK+ command line arguments.
   *
   * You could instead use the constuctor that takes no command line arguements
   * and later supply the command line arguments to run().
   *
   * Note that all GTK+ functionality that is available via command line arguments
   * can instead be achieved by setting suitable environment variables
   * such as G_DEBUG.
   *
   * If non-empty, the application ID must be valid.  See
   * g_application_id_is_valid().
   *
   * If no application ID is given then some features (most notably application
   * uniqueness) will be disabled. A null application ID is only allowed with
   * gtkmm 3.6 or later.
   *
   * @param argc The parameter received by your main() function.
   * @param argv The parameter received by your main() function.
   * @param application_id A valid application ID.
   *
   * @param flags The application flags.
   * @newin{3,4}
   */
  static Glib::RefPtr<Application> create(int& argc, char**& argv, const Glib::ustring& application_id = Glib::ustring(), Gio::ApplicationFlags flags = Gio::APPLICATION_FLAGS_NONE);

 
  /** Gets a list of the Gtk::Windows associated with @a application.
   * 
   * The list is sorted by most recently focused window, such that the first
   * element is the currently focused window. (Useful for choosing a parent
   * for a transient window.)
   * 
   * The list that is returned should not be modified in any way. It will
   * only remain valid until the next focus change or window creation or
   * deletion.
   * 
   * @newin{3,0}
   * @return A List of Gtk::Window.
   */
  std::vector<Window*> get_windows();

 
  /** Gets a list of the Gtk::Windows associated with @a application.
   * 
   * The list is sorted by most recently focused window, such that the first
   * element is the currently focused window. (Useful for choosing a parent
   * for a transient window.)
   * 
   * The list that is returned should not be modified in any way. It will
   * only remain valid until the next focus change or window creation or
   * deletion.
   * 
   * @newin{3,0}
   * @return A List of Gtk::Window.
   */
  std::vector<const Window*> get_windows() const;

  /** Adds a window to the Gtk::Application.
   *
   * If all the windows managed by Gtk::Application are closed or removed from
   * the application then the Gtk::Application will call quit(), and quit
   * the application.
   *
   * This call is equivalent to calling Gtk::Window::set_application().
   *
   * Normally, the connection between the application and the window
   * will remain until the window is closed or destroyed, but you can explicitly
   * remove it with remove_window().
   *
   * @newin{3,4}
   * @param window A toplevel window to add to the application.
   */
  void add_window(Window& window);
  

  /** Remove a window from @a application.
   * 
   * If @a window belongs to @a application then this call is equivalent to
   * setting the Gtk::Window::property_application() property of @a window to
   * <tt>0</tt>.
   * 
   * The application may stop running as a result of a call to this
   * function.
   * 
   * @newin{3,0}
   * @param window A Gtk::Window.
   */
  void remove_window(Window& window);

  /** Starts the application.
   *
   * The default implementation of this virtual function will simply run
   * a main loop.
   *
   * It is an error to call this function if @a application is a proxy for
   * a remote application.
   *
   * @newin{3,4}
   */
  int run(int argc, char** argv);

  /** Starts the application.
   *
   * The default implementation of this virtual function will simply run
   * a main loop.
   *
   * It is an error to call this function if @a application is a proxy for
   * a remote application.
   *
   * @param window The window to show. This method will return when the window is hidden.
   *
   * @newin{3,4}
   */
  int run(Window& window, int argc, char** argv);

  //TODO: If argc and argv are necessary at all, document the need to call that constructor first.
  //See https://bugzilla.gnome.org/show_bug.cgi?id=639925#c4
  /** Starts the application.
   *
   * The default implementation of this virtual function will simply run
   * a main loop.
   *
   * It is an error to call this function if @a application is a proxy for
   * a remote application.
   *
   * @param window The window to show. This method will return when the window is hidden.
   *
   * @newin{3,4}
   */
  int run(Window& window);

  //TODO: If argc and argv are necessary at all, document the need to call that constructor first.
  //See https://bugzilla.gnome.org/show_bug.cgi?id=639925#c4
  /** Starts the application.
   *
   * The default implementation of this virtual function will simply run
   * a main loop.
   *
   * It is an error to call this function if @a application is a proxy for
   * a remote application.
   *
   * @newin{3,4}
   */
  int run();

  
  /** Returns the menu model that has been set with
   * set_app_menu().
   * 
   * @newin{3,4}
   * @return The application menu of @a application.
   */
  Glib::RefPtr<Gio::MenuModel> get_app_menu();
  
  /** Returns the menu model that has been set with
   * set_app_menu().
   * 
   * @newin{3,4}
   * @return The application menu of @a application.
   */
  Glib::RefPtr<const Gio::MenuModel> get_app_menu() const;

  
  /** Sets or unsets the application menu for @a application.
   * 
   * This can only be done in the primary instance of the application,
   * after it has been registered.  Application::property_startup() is a good place
   * to call this.
   * 
   * The application menu is a single menu containing items that typically
   * impact the application as a whole, rather than acting on a specific
   * window or document.  For example, you would expect to see
   * "Preferences" or "Quit" in an application menu, but not "Save" or
   * "Print".
   * 
   * If supported, the application menu will be rendered by the desktop
   * environment.
   * 
   * Use the base ActionMap interface to add actions, to respond to the user
   * selecting these menu items.
   * 
   * @newin{3,4}
   * @param app_menu A MenuModel, or <tt>0</tt>.
   */
  void set_app_menu(const Glib::RefPtr<Gio::MenuModel>& app_menu);

  
  /** Returns the menu model that has been set with
   * set_menubar().
   * 
   * @newin{3,4}
   * @return The menubar for windows of @a application.
   */
  Glib::RefPtr<Gio::MenuModel> get_menubar();
  
  /** Returns the menu model that has been set with
   * set_menubar().
   * 
   * @newin{3,4}
   * @return The menubar for windows of @a application.
   */
  Glib::RefPtr<const Gio::MenuModel> get_menubar() const;

  
  /** Sets or unsets the menubar for windows of @a application.
   * 
   * This is a menubar in the traditional sense.
   * 
   * This can only be done in the primary instance of the application,
   * after it has been registered.  Application::property_startup() is a good place
   * to call this.
   * 
   * Depending on the desktop environment, this may appear at the top of
   * each window, or at the top of the screen.  In some environments, if
   * both the application menu and the menubar are set, the application
   * menu will be presented as if it were the first item of the menubar.
   * Other environments treat the two as completely separate -- for
   * example, the application menu may be rendered by the desktop shell
   * while the menubar (if set) remains in each individual window.
   * 
   * Use the base ActionMap interface to add actions, to respond to the user
   * selecting these menu items.
   * 
   * @newin{3,4}
   * @param menubar A MenuModel, or <tt>0</tt>.
   */
  void set_menubar(const Glib::RefPtr<Gio::MenuModel>& menubar);

  //TODO: Add a version that takes a VariantBase and deprecate this method:
  
  /** Installs an accelerator that will cause the named action
   * to be activated when the key combination specificed by @a accelerator
   * is pressed.
   * 
   *  @a accelerator must be a string that can be parsed by
   * gtk_accelerator_parse(), e.g. "<Primary>q" or
   * "<Control><Alt>p".
   * 
   *  @a action_name must be the name of an action as it would be used
   * in the app menu, i.e. actions that have been added to the application
   * are referred to with an "app." prefix, and window-specific actions
   * with a "win." prefix.
   * 
   * GtkApplication also extracts accelerators out of 'accel' attributes
   * in the MenuModels passed to set_app_menu() and
   * set_menubar(), which is usually more convenient
   * than calling this function for each accelerator.
   * 
   * @newin{3,4}
   * @param accelerator Accelerator string.
   * @param action_name The name of the action to activate.
   * @param parameter Parameter to pass when activating the action,
   * or <tt>0</tt> if the action does not accept an activation parameter.
   */
  void add_accelerator(const Glib::ustring& accelerator, const Glib::ustring& action_name, GVariant * parameter);

  //TODO: Add a version that takes a VariantBase and deprecate this method:
  
  /** Removes an accelerator that has been previously added
   * with add_accelerator().
   * 
   * @newin{3,4}
   * @param action_name The name of the action to activate.
   * @param parameter Parameter to pass when activating the action,
   * or <tt>0</tt> if the action does not accept an activation parameter.
   */
  void remove_accelerator(const Glib::ustring& action_name, GVariant* parameter);

  
  /** Inform the session manager that certain types of actions should be
   * inhibited. This is not guaranteed to work on all platforms and for
   * all types of actions.
   * 
   * Applications should invoke this method when they begin an operation
   * that should not be interrupted, such as creating a CD or DVD. The
   * types of actions that may be blocked are specified by the @a flags
   * parameter. When the application completes the operation it should
   * call uninhibit() to remove the inhibitor. Note that
   * an application can have multiple inhibitors, and all of the must
   * be individually removed. Inhibitors are also cleared when the
   * application exits.
   * 
   * Applications should not expect that they will always be able to block
   * the action. In most cases, users will be given the option to force
   * the action to take place.
   * 
   * Reasons should be short and to the point.
   * 
   * If @a window is given, the session manager may point the user to
   * this window to find out more about why the action is inhibited.
   * 
   * @newin{3,4}
   * @param window A Gtk::Window, or <tt>0</tt>.
   * @param flags What types of actions should be inhibited.
   * @param reason A short, human-readable string that explains
   * why these operations are inhibited.
   * @return A non-zero cookie that is used to uniquely identify this
   * request. It should be used as an argument to uninhibit()
   * in order to remove the request. If the platform does not support
   * inhibiting or the request failed for some reason, 0 is returned.
   */
  guint inhibit(Window& window, ApplicationInhibitFlags flags, const Glib::ustring& reason);
  
  /** Removes an inhibitor that has been established with inhibit().
   * Inhibitors are also cleared when the application exits.
   * 
   * @newin{3,4}
   * @param cookie A cookie that was returned by inhibit().
   */
  void uninhibit(guint cookie);
  
  /** Determines if any of the actions specified in @a flags are
   * currently inhibited (possibly by another application).
   * 
   * @newin{3,4}
   * @param flags What types of actions should be queried.
   * @return <tt>true</tt> if any of the actions specified in @a flags are inhibited.
   */
  bool is_inhibited(ApplicationInhibitFlags flags) const;

  
  /** Returns the Gtk::ApplicationWindow with the given ID.
   * 
   * @newin{3,6}
   * @param id An identifier number.
   * @return The window with ID @a id, or
   * <tt>0</tt> if there is no window with this ID.
   */
  Window* get_window_by_id(guint id);
  
  /** Returns the Gtk::ApplicationWindow with the given ID.
   * 
   * @newin{3,6}
   * @param id An identifier number.
   * @return The window with ID @a id, or
   * <tt>0</tt> if there is no window with this ID.
   */
  const Window* get_window_by_id(guint id) const;

  
  /** Gets the "active" window for the application.
   * 
   * The active window is the one that was most recently focused (within
   * the application).  This window may not have the focus at the moment
   * if another application has it -- this is just the most
   * recently-focused window within this application.
   * 
   * @newin{3,6}
   * @return The active window.
   */
  Window* get_active_window();
  
  /** Gets the "active" window for the application.
   * 
   * The active window is the one that was most recently focused (within
   * the application).  This window may not have the focus at the moment
   * if another application has it -- this is just the most
   * recently-focused window within this application.
   * 
   * @newin{3,6}
   * @return The active window.
   */
  const Window* get_active_window() const;


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The GMenuModel for the application menu.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > property_app_menu() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The GMenuModel for the application menu.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> > property_app_menu() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The GMenuModel for the menubar.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > property_menubar() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The GMenuModel for the menubar.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> > property_menubar() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Register with the session manager.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_register_session() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Register with the session manager.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_register_session() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The window which most recently had focus.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Window* > property_active_window() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


/**
   * @par Slot Prototype:
   * <tt>void on_my_%window_added(Window* window)</tt>
   *
   * Emitted when a Gtk::Window is added to @a application through
   * Gtk::Application::add_window().
   * 
   * @newin{3,2}
   * @param window The newly-added Gtk::Window.
   */

  Glib::SignalProxy1< void,Window* > signal_window_added();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%window_removed(Window* window)</tt>
   *
   * Emitted when a Gtk::Window is removed from @a application,
   * either as a side-effect of being destroyed or explicitly
   * through Gtk::Application::remove_window().
   * 
   * @newin{3,2}
   * @param window The Gtk::Window that is being removed.
   */

  Glib::SignalProxy1< void,Window* > signal_window_removed();


private:
  /** This is just a way to call Glib::init() (which calls g_type_init()) before
   * calling application_class_.init(), so that 
   * gtk_application_get_type() will always succeed.
   * See https://bugzilla.gnome.org/show_bug.cgi?id=639925
   */
  const Glib::Class& custom_class_init();
  
  void on_activate_add_and_show_main_window(Window* window);
  void on_window_hide(Window* window);
  
  //We need these to call g_application_run(), 
  //even if we have already called gtk_init().
  int m_argc;
  char** m_argv;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_window_added().
  virtual void on_window_added(Window* window);
  /// This is a default handler for the signal signal_window_removed().
  virtual void on_window_removed(Window* window);


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
   * @relates Gtk::Application
   */
  Glib::RefPtr<Gtk::Application> wrap(GtkApplication* object, bool take_copy = false);
}


#endif /* _GTKMM_APPLICATION_H */

