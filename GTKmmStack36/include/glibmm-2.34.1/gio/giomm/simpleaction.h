// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GIOMM_SIMPLEACTION_H
#define _GIOMM_SIMPLEACTION_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2011 The giomm Development Team
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

#include <glibmm/object.h>
#include <giomm/action.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSimpleAction GSimpleAction;
typedef GObjectClass GSimpleActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{ class SimpleAction_Class; } // namespace Gio
namespace Gio
{

/** SimpleAction - A simple Action implementation.
 * A SimpleAction is the obvious simple implementation of the Action
 * interface. This is the easiest way to create an action for purposes of
 * adding it to a SimpleActionGroup.
 *
 * See also Gtk::Action.
 *
 * @newin{2,32}
 */

class SimpleAction : public Glib::Object, public Action
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SimpleAction CppObjectType;
  typedef SimpleAction_Class CppClassType;
  typedef GSimpleAction BaseObjectType;
  typedef GSimpleActionClass BaseClassType;

private:  friend class SimpleAction_Class;
  static CppClassType simpleaction_class_;

private:
  // noncopyable
  SimpleAction(const SimpleAction&);
  SimpleAction& operator=(const SimpleAction&);

protected:
  explicit SimpleAction(const Glib::ConstructParams& construct_params);
  explicit SimpleAction(GSimpleAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~SimpleAction();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GSimpleAction*       gobj()       { return reinterpret_cast<GSimpleAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GSimpleAction* gobj() const { return reinterpret_cast<GSimpleAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GSimpleAction* gobj_copy();

private:

  
protected:
  explicit SimpleAction(const Glib::ustring& name);

 
    explicit SimpleAction(const Glib::ustring& name, const Glib::VariantType& parameter_type);


    explicit SimpleAction(const Glib::ustring& name, const Glib::VariantType& parameter_type, const Glib::VariantBase& sate);


public:

  
  static Glib::RefPtr<SimpleAction> create(const Glib::ustring& name);


  /** Creates a new action.
   * 
   * The created action is stateless.  See g_simple_action_new_stateful().
   * 
   * @newin{2,28}
   * @param name The name of the action.
   * @param parameter_type The type of parameter to the activate function.
   * @return A new SimpleAction.
   */

  
  static Glib::RefPtr<SimpleAction> create(const Glib::ustring& name, const Glib::VariantType& parameter_type);


  /** Creates a new stateful action.
   * 
   *  @a state is the initial state of the action.  All future state values
   * must have the same VariantType as the initial state.
   * 
   * If the @a state GVariant is floating, it is consumed.
   * 
   * @newin{2,28}
   * @param name The name of the action.
   * @param parameter_type The type of the parameter to the activate function.
   * @param state The initial state of the action.
   * @return A new SimpleAction.
   */

  
  static Glib::RefPtr<SimpleAction> create(const Glib::ustring& name, const Glib::VariantType& parameter_type, const Glib::VariantBase& sate);


  /** Sets the action as enabled or not.
   * 
   * An action must be enabled in order to be activated or in order to
   * have its state changed from outside callers.
   * 
   * This should only be called by the implementor of the action.  Users
   * of the action should not attempt to modify its enabled flag.
   * 
   * @newin{2,28}
   * @param enabled Whether the action is enabled.
   */
  void set_enabled(bool enabled);
  
  /** Sets the state of the action.
   * 
   * This directly updates the 'state' property to the given value.
   * 
   * This should only be called by the implementor of the action.  Users
   * of the action should not attempt to directly modify the 'state'
   * property.  Instead, they should call g_action_change_state() to
   * request the change.
   * 
   * @newin{2,30}
   * @param value The new Variant for the state.
   */
  void set_state(const Glib::VariantBase& value);

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** If the action can be activated.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_enabled() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** If the action can be activated.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_enabled() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The name used to invoke the action.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_name() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The type of GVariant passed to activate().
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::VariantType > property_parameter_type() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The state the action is in.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::VariantBase > property_state() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The state the action is in.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::VariantBase > property_state() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The type of the state kept by the action.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::VariantType > property_state_type() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


/**
   * @par Slot Prototype:
   * <tt>void on_my_%activate(const Glib::VariantBase& parameter)</tt>
   *
   * Indicates that the action was just activated.
   * 
   *  @parameter will always be of the expected type.  In the event that
   * an incorrect type was given, no signal will be emitted.
   * 
   * @newin{2,28}
   * @param parameter The parameter to the activation.
   */

  Glib::SignalProxy1< void,const Glib::VariantBase& > signal_activate();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%change_state(const Glib::VariantBase& value)</tt>
   *
   * Indicates that the action just received a request to change its
   * state.
   * 
   *  @a value will always be of the correct state type.  In the event that
   * an incorrect type was given, no signal will be emitted.
   * 
   * If no handler is connected to this signal then the default
   * behaviour is to call g_simple_action_set_state() to set the state
   * to the requested value.  If you connect a signal handler then no
   * default action is taken.  If the state should change then you must
   * call g_simple_action_set_state() from the handler.
   * 
   * <example>
   * <title>Example 'change-state' handler</title>
   * 
   * static void
   * change_volume_state (GSimpleAction *action,
   * GVariant      *value,
   * gpointer       user_data)
   * {
   * <tt>int</tt> requested;
   * 
   * requested = g_variant_get_int32 (value);
   * 
   * // Volume only goes from 0 to 10
   * if (0 <= requested && requested <= 10)
   * g_simple_action_set_state (action, value);
   * }
   * 
   * </example>
   * 
   * The handler need not set the state to the requested value.  It
   * could set it to any value at all, or take some other action.
   * 
   * @newin{2,30}
   * @param value The requested value for the state.
   */

  Glib::SignalProxy1< void,const Glib::VariantBase& > signal_change_state();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::SimpleAction
   */
  Glib::RefPtr<Gio::SimpleAction> wrap(GSimpleAction* object, bool take_copy = false);
}


#endif /* _GIOMM_SIMPLEACTION_H */

