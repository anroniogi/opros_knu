// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDKMM_DEVICE_H
#define _GDKMM_DEVICE_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2002-2004 The gtkmm Development Team
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

//#include <gdkmm/window.h>
#include <gdkmm/cursor.h>
#include <gdkmm/event.h>
#include <gdkmm/timecoord.h>
#include <gdk/gdk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdkDevice GdkDevice;
typedef struct _GdkDeviceClass GdkDeviceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{ class Device_Class; } // namespace Gdk
namespace Gdk
{

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 * @ingroup gdkmmEnums
 * @par Bitwise operators:
 * <tt>%EventMask operator|(EventMask, EventMask)</tt><br>
 * <tt>%EventMask operator&(EventMask, EventMask)</tt><br>
 * <tt>%EventMask operator^(EventMask, EventMask)</tt><br>
 * <tt>%EventMask operator~(EventMask)</tt><br>
 * <tt>%EventMask& operator|=(EventMask&, EventMask)</tt><br>
 * <tt>%EventMask& operator&=(EventMask&, EventMask)</tt><br>
 * <tt>%EventMask& operator^=(EventMask&, EventMask)</tt><br>
 */
enum EventMask
{
  EXPOSURE_MASK = 1 << 1,
  POINTER_MOTION_MASK = 1 << 2,
  POINTER_MOTION_HINT_MASK = 1 << 3,
  BUTTON_MOTION_MASK = 1 << 4,
  BUTTON1_MOTION_MASK = 1 << 5,
  BUTTON2_MOTION_MASK = 1 << 6,
  BUTTON3_MOTION_MASK = 1 << 7,
  BUTTON_PRESS_MASK = 1 << 8,
  BUTTON_RELEASE_MASK = 1 << 9,
  KEY_PRESS_MASK = 1 << 10,
  KEY_RELEASE_MASK = 1 << 11,
  ENTER_NOTIFY_MASK = 1 << 12,
  LEAVE_NOTIFY_MASK = 1 << 13,
  FOCUS_CHANGE_MASK = 1 << 14,
  STRUCTURE_MASK = 1 << 15,
  PROPERTY_CHANGE_MASK = 1 << 16,
  VISIBILITY_NOTIFY_MASK = 1 << 17,
  PROXIMITY_IN_MASK = 1 << 18,
  PROXIMITY_OUT_MASK = 1 << 19,
  SUBSTRUCTURE_MASK = 1 << 20,
  SCROLL_MASK = 1 << 21,
  TOUCH_MASK = 1 << 22,
  SMOOTH_SCROLL_MASK = 1 << 23,
  ALL_EVENTS_MASK = 0xFFFFFE
};

/** @ingroup gdkmmEnums */
inline EventMask operator|(EventMask lhs, EventMask rhs)
  { return static_cast<EventMask>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline EventMask operator&(EventMask lhs, EventMask rhs)
  { return static_cast<EventMask>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline EventMask operator^(EventMask lhs, EventMask rhs)
  { return static_cast<EventMask>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline EventMask operator~(EventMask flags)
  { return static_cast<EventMask>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline EventMask& operator|=(EventMask& lhs, EventMask rhs)
  { return (lhs = static_cast<EventMask>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline EventMask& operator&=(EventMask& lhs, EventMask rhs)
  { return (lhs = static_cast<EventMask>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline EventMask& operator^=(EventMask& lhs, EventMask rhs)
  { return (lhs = static_cast<EventMask>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::EventMask> : public Glib::Value_Flags<Gdk::EventMask>
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
enum InputMode
{
  MODE_DISABLED,
  MODE_SCREEN,
  MODE_WINDOW
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::InputMode> : public Glib::Value_Enum<Gdk::InputMode>
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
enum InputSource
{
  SOURCE_MOUSE,
  SOURCE_PEN,
  SOURCE_ERASER,
  SOURCE_CURSOR,
  SOURCE_KEYBOARD,
  SOURCE_TOUCHSCREEN,
  SOURCE_TOUCHPAD
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::InputSource> : public Glib::Value_Enum<Gdk::InputSource>
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
enum DeviceType
{
  DEVICE_TYPE_MASTER,
  DEVICE_TYPE_SLAVE,
  DEVICE_TYPE_FLOATING
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::DeviceType> : public Glib::Value_Enum<Gdk::DeviceType>
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
enum GrabOwnership
{
  OWNERSHIP_NONE,
  OWNERSHIP_WINDOW,
  OWNERSHIP_APPLICATION
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::GrabOwnership> : public Glib::Value_Enum<Gdk::GrabOwnership>
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
enum GrabStatus
{
  GRAB_SUCCESS,
  GRAB_ALREADY_GRABBED,
  GRAB_INVALID_TIME,
  GRAB_NOT_VIEWABLE,
  GRAB_FROZEN
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::GrabStatus> : public Glib::Value_Enum<Gdk::GrabStatus>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{


class Display;
class Window;

/** A Gdk::Device instance contains a detailed description of an extended input device.
 */

class Device : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Device CppObjectType;
  typedef Device_Class CppClassType;
  typedef GdkDevice BaseObjectType;
  typedef GdkDeviceClass BaseClassType;

private:  friend class Device_Class;
  static CppClassType device_class_;

private:
  // noncopyable
  Device(const Device&);
  Device& operator=(const Device&);

protected:
  explicit Device(const Glib::ConstructParams& construct_params);
  explicit Device(GdkDevice* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Device();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkDevice*       gobj()       { return reinterpret_cast<GdkDevice*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkDevice* gobj() const { return reinterpret_cast<GdkDevice*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkDevice* gobj_copy();

private:


protected:
  Device();

public:

  
  /** Determines the name of the device.
   * 
   * @newin{2,20}
   * @return A name.
   */
  Glib::ustring get_name() const;
  
  /** Determines whether the pointer follows device motion.
   * 
   * @newin{2,20}
   * @return <tt>true</tt> if the pointer follows device motion.
   */
  bool get_has_cursor() const;

  
  /** Determines the type of the device.
   * 
   * @newin{2,20}
   * @return A Gdk::InputSource.
   */
  InputSource get_source() const;
  
  /** Determines the mode of the device.
   * 
   * @newin{2,20}
   * @return A Gdk::InputSource.
   */
  InputMode get_mode() const;
  
  /** Sets a the mode of an input device. The mode controls if the
   * device is active and whether the device's range is mapped to the
   * entire screen or to a single window.
   * @param mode The input mode.
   * @return <tt>true</tt> if the mode was successfully changed.
   */
  bool set_mode(InputMode mode);
  
  /** Returns the number of keys the device currently has.
   * 
   * @newin{2,24}
   * @return The number of keys.
   */
  int get_n_keys() const;
  
  /** If @a index has a valid keyval, this function will return <tt>true</tt>
   * and fill in @a keyval and @a modifiers with the keyval settings.
   * 
   * @newin{2,20}
   * @param index The index of the macro button to get.
   * @param keyval Return value for the keyval.
   * @param modifiers Return value for modifiers.
   * @return <tt>true</tt> if keyval is set for @a index.
   */
  bool get_key(guint index_, guint& keyval, ModifierType& modifiers) const;
  
  /** Specifies the X key event to generate when a macro button of a device
   * is pressed.
   * @param index The index of the macro button to set.
   * @param keyval The keyval to generate.
   * @param modifiers The modifiers to set.
   */
  void set_key(guint index_, guint keyval, ModifierType modifiers);
  
  /** Returns the axis use for @a index.
   * 
   * @newin{2,20}
   * @param index The index of the axis.
   * @return A Gdk::AxisUse specifying how the axis is used.
   */
  AxisUse get_axis_use(guint index_) const;
  
  /** Specifies how an axis of a device is used.
   * @param index The index of the axis.
   * @param use Specifies how the axis is used.
   */
  void set_axis_use(guint index_, AxisUse use);
  
  /** Gets the current state of a pointer device relative to @a window. As a slave
   * device coordinates are those of its master pointer, This
   * function may not be called on devices of type Gdk::DEVICE_TYPE_SLAVE,
   * unless there is an ongoing grab on them, see grab().
   * @param window A Gdk::Window.
   * @param axes An array of doubles to store the values of the axes of @a device in,
   * or <tt>0</tt>.
   * @param mask Location to store the modifiers, or <tt>0</tt>.
   */
  void get_state(const Glib::RefPtr<Window>& window, double& axes, ModifierType& mask);

  // TODO: docs.
  std::vector<TimeCoord> get_history(const Glib::RefPtr<Window>& window, guint32 start, guint32 stop) const;
  

  /** If the device if of type Gdk::DEVICE_TYPE_MASTER, it will return
   * the list of slave devices attached to it, otherwise it will return
   * <tt>0</tt>
   * @return The list of
   * slave devices, or <tt>0</tt>. The list must be freed with
   * Glib::list_free(), the contents of the list are owned by GTK+
   * and should not be freed.
   */
  std::vector<Glib::RefPtr<Gdk::Device> > list_slave_devices();
  //TODO:_WRAP_METHOD(std::vector<Glib::RefPtr<const Gdk::Device> > list_slave_devices() const, gdk_device_list_slave_devices, constversion)

  
  /** Returns the number of axes the device currently has.
   * 
   * @newin{3,0}
   * @return The number of axes.
   */
  int get_n_axes() const;

  /** Returns the labels for the axes that the device currently has.
   * @newin{3,4}
   */
  std::vector<std::string> list_axes() const;
  

  //TODO: Use a string instead of a GdkAtom:
  
  /** Interprets an array of double as axis values for a given device,
   * and locates the value in the array for a given axis label, as returned
   * by list_axes()
   * 
   * @newin{3,0}
   * @param axes Pointer to an array of axes.
   * @param axis_label Gdk::Atom with the axis label.
   * @param value Location to store the found value.
   * @return <tt>true</tt> if the given axis use was found, otherwise <tt>false</tt>.
   */
  bool get_axis_value(double& axes, GdkAtom axis_label, double& value) const;

  
  /** Interprets an array of double as axis values for a given device,
   * and locates the value in the array for a given axis use.
   * @param axes Pointer to an array of axes.
   * @param use The use to look for.
   * @param value Location to store the found value.
   * @return <tt>true</tt> if the given axis use was found, otherwise <tt>false</tt>.
   */
  bool get_axis(double& axes, AxisUse use, double& value) const;

  
  /** Returns the Gdk::Display to which @a device pertains.
   * 
   * @newin{3,0}
   * @return A Gdk::Display. This memory is owned
   * by GTK+, and must not be freed or unreffed.
   */
  Glib::RefPtr<Display> get_display();
  
  /** Returns the Gdk::Display to which @a device pertains.
   * 
   * @newin{3,0}
   * @return A Gdk::Display. This memory is owned
   * by GTK+, and must not be freed or unreffed.
   */
  Glib::RefPtr<const Display> get_display() const;

  
  /** Returns the associated device to @a device, if @a device is of type
   * Gdk::DEVICE_TYPE_MASTER, it will return the paired pointer or
   * keyboard.
   * 
   * If @a device is of type Gdk::DEVICE_TYPE_SLAVE, it will return
   * the master device to which @a device is attached to.
   * 
   * If @a device is of type Gdk::DEVICE_TYPE_FLOATING, <tt>0</tt> will be
   * returned, as there is no associated device.
   * 
   * @newin{3,0}
   * @return The associated device, or <tt>0</tt>.
   */
  Glib::RefPtr<Device> get_associated_device();
  
  /** Returns the associated device to @a device, if @a device is of type
   * Gdk::DEVICE_TYPE_MASTER, it will return the paired pointer or
   * keyboard.
   * 
   * If @a device is of type Gdk::DEVICE_TYPE_SLAVE, it will return
   * the master device to which @a device is attached to.
   * 
   * If @a device is of type Gdk::DEVICE_TYPE_FLOATING, <tt>0</tt> will be
   * returned, as there is no associated device.
   * 
   * @newin{3,0}
   * @return The associated device, or <tt>0</tt>.
   */
  Glib::RefPtr<const Device> get_associated_device() const;

  
  /** Returns the device type for @a device.
   * 
   * @newin{3,0}
   * @return The Gdk::DeviceType for @a device.
   */
  DeviceType get_device_type() const;

  
  /** Grabs the device so that all events coming from this device are passed to
   * this application until the device is ungrabbed with ungrab(),
   * or the window becomes unviewable. This overrides any previous grab on the device
   * by this client.
   * 
   * Device grabs are used for operations which need complete control over the
   * given device events (either pointer or keyboard). For example in GTK+ this
   * is used for Drag and Drop operations, popup menus and such.
   * 
   * Note that if the event mask of an X window has selected both button press
   * and button release events, then a button press event will cause an automatic
   * pointer grab until the button is released. X does this automatically since
   * most applications expect to receive button press and release events in pairs.
   * It is equivalent to a pointer grab on the window with @a owner_events set to
   * <tt>true</tt>.
   * 
   * If you set up anything at the time you take the grab that needs to be
   * cleaned up when the grab ends, you should handle the Gdk::EventGrabBroken
   * events that are emitted when the grab ends unvoluntarily.
   * 
   * @newin{3,0}
   * @param window The Gdk::Window which will own the grab (the grab window).
   * @param grab_ownership Specifies the grab ownership.
   * @param owner_events If <tt>false</tt> then all device events are reported with respect to
   *  @a window and are only reported if selected by @a event_mask. If
   * <tt>true</tt> then pointer events for this application are reported
   * as normal, but pointer events outside this application are
   * reported with respect to @a window and only if selected by
   *  @a event_mask. In either mode, unreported events are discarded.
   * @param event_mask Specifies the event mask, which is used in accordance with
   *  @a owner_events.
   * @param cursor The cursor to display while the grab is active if the device is
   * a pointer. If this is <tt>0</tt> then the normal cursors are used for
   *  @a window and its descendants, and the cursor for @a window is used
   * elsewhere.
   * @param time The timestamp of the event which led to this pointer grab. This
   * usually comes from the Gdk::Event struct, though Gdk::CURRENT_TIME
   * can be used if the time isn't known.
   * @return Gdk::GRAB_SUCCESS if the grab was successful.
   */
  GrabStatus grab(const Glib::RefPtr<Window>& window, GrabOwnership grab_ownership, bool owner_events, EventMask event_mask, const Glib::RefPtr<Cursor>& cursor, guint32 time_);

  // TODO: docs.
  GrabStatus grab(const Glib::RefPtr<Window>& window, GrabOwnership grab_ownership, bool owner_events, EventMask event_mask, guint32 time_);

  
  /** Release any grab on @a device.
   * 
   * @newin{3,0}
   * @param time A timestap (e.g. Gdk::CURRENT_TIME).
   */
  void ungrab(guint32 time_);
  
  /** Warps @a device in @a display to the point @a x, @a y on
   * the screen @a screen, unless the device is confined
   * to a window by a grab, in which case it will be moved
   * as far as allowed by the grab. Warping the pointer
   * creates events as if the user had moved the mouse
   * instantaneously to the destination.
   * 
   * Note that the pointer should normally be under the
   * control of the user. This function was added to cover
   * some rare use cases like keyboard navigation support
   * for the color picker in the Gtk::ColorSelectionDialog.
   * 
   * @newin{3,0}
   * @param screen The screen to warp @a device to.
   * @param x The X coordinate of the destination.
   * @param y The Y coordinate of the destination.
   */
  void warp(const Glib::RefPtr<Screen>& p1, int x, int y);

  // TODO: docs.
  void get_position(int& x, int& y) const;

  // TODO: docs.
  void get_position(Glib::RefPtr<Screen>& screen, int& x, int& y) const;
  

  /** Obtains the window underneath @a device, returning the location of the device in @a win_x and @a win_y. Returns
   * <tt>0</tt> if the window tree under @a device is not known to GDK (for example, belongs to another application).
   * 
   * As a slave device coordinates are those of its master pointer, This
   * function may not be called on devices of type Gdk::DEVICE_TYPE_SLAVE,
   * unless there is an ongoing grab on them, see grab().
   * 
   * @newin{3,0}
   * @param win_x Return location for the X coordinate of the device location,
   * relative to the window origin, or <tt>0</tt>.
   * @param win_y Return location for the Y coordinate of the device location,
   * relative to the window origin, or <tt>0</tt>.
   * @return The Gdk::Window under the device position, or <tt>0</tt>.
   */
  Glib::RefPtr<Window> get_window_at_position(int& win_x, int& win_y);

  
  /** Obtains the window underneath @a device, returning the location of the device in @a win_x and @a win_y. Returns
   * <tt>0</tt> if the window tree under @a device is not known to GDK (for example, belongs to another application).
   * 
   * As a slave device coordinates are those of its master pointer, This
   * function may not be called on devices of type Gdk::DEVICE_TYPE_SLAVE,
   * unless there is an ongoing grab on them, see grab().
   * 
   * @newin{3,0}
   * @param win_x Return location for the X coordinate of the device location,
   * relative to the window origin, or <tt>0</tt>.
   * @param win_y Return location for the Y coordinate of the device location,
   * relative to the window origin, or <tt>0</tt>.
   * @return The Gdk::Window under the device position, or <tt>0</tt>.
   */
  Glib::RefPtr<const Window> get_window_at_position(int& win_x, int& win_y) const;

  //TODO: Documentation
  Glib::RefPtr<Window> get_window_at_position();

  //TODO: Documentation
  Glib::RefPtr<const Window> get_window_at_position() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Device
   */
  Glib::RefPtr<Gdk::Device> wrap(GdkDevice* object, bool take_copy = false);
}


#endif /* _GDKMM_DEVICE_H */

