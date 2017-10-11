// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GIOMM_DBUSSERVER_H
#define _GIOMM_DBUSSERVER_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2010 The giomm Development Team
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
#include <giomm/dbusconnection.h>
#include <giomm/dbusauthobserver.h>
#include <giomm/initable.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDBusServer GDBusServer;
typedef struct _GDBusServerClass GDBusServerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{

namespace DBus
{ class Server_Class; } // namespace DBus

} // namespace Gio
namespace Gio
{

namespace DBus
{

/** @addtogroup giommEnums giomm Enums and Flags */

/**
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>%ServerFlags operator|(ServerFlags, ServerFlags)</tt><br>
 * <tt>%ServerFlags operator&(ServerFlags, ServerFlags)</tt><br>
 * <tt>%ServerFlags operator^(ServerFlags, ServerFlags)</tt><br>
 * <tt>%ServerFlags operator~(ServerFlags)</tt><br>
 * <tt>%ServerFlags& operator|=(ServerFlags&, ServerFlags)</tt><br>
 * <tt>%ServerFlags& operator&=(ServerFlags&, ServerFlags)</tt><br>
 * <tt>%ServerFlags& operator^=(ServerFlags&, ServerFlags)</tt><br>
 */
enum ServerFlags
{
  SERVER_FLAGS_NONE = 0x0,
  SERVER_FLAGS_RUN_IN_THREAD = (1<<0),
  SERVER_FLAGS_AUTHENTICATION_ALLOW_ANONYMOUS = (1<<1)
};

/** @ingroup giommEnums */
inline ServerFlags operator|(ServerFlags lhs, ServerFlags rhs)
  { return static_cast<ServerFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline ServerFlags operator&(ServerFlags lhs, ServerFlags rhs)
  { return static_cast<ServerFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline ServerFlags operator^(ServerFlags lhs, ServerFlags rhs)
  { return static_cast<ServerFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline ServerFlags operator~(ServerFlags flags)
  { return static_cast<ServerFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline ServerFlags& operator|=(ServerFlags& lhs, ServerFlags rhs)
  { return (lhs = static_cast<ServerFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline ServerFlags& operator&=(ServerFlags& lhs, ServerFlags rhs)
  { return (lhs = static_cast<ServerFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline ServerFlags& operator^=(ServerFlags& lhs, ServerFlags rhs)
  { return (lhs = static_cast<ServerFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


//TODO: Add example from the C API in class docs.
/** This is a helper for listening to and accepting D-Bus connections.
 * Since Server derives from Initiable, its constructors can
 * throw an exception if construction fails.
 *
 * This can be used to create a new D-Bus server, allowing two
 * peers to use the D-Bus protocol for their own specialized communication.
 * A server instance provided in this way will not perform message routing or
 * implement the org.freedesktop.DBus interface.
 *
 * To just export an object on a well-known name on a message bus, such as the
 * session or system bus, you should instead use Gio::DBus::own_name().
 *
 * @newin{2,28}
 * @ingroup DBus
 */

class Server : public Glib::Object, public Initable
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Server CppObjectType;
  typedef Server_Class CppClassType;
  typedef GDBusServer BaseObjectType;
  typedef GDBusServerClass BaseClassType;

private:  friend class Server_Class;
  static CppClassType server_class_;

private:
  // noncopyable
  Server(const Server&);
  Server& operator=(const Server&);

protected:
  explicit Server(const Glib::ConstructParams& construct_params);
  explicit Server(GDBusServer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Server();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GDBusServer*       gobj()       { return reinterpret_cast<GDBusServer*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GDBusServer* gobj() const { return reinterpret_cast<GDBusServer*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GDBusServer* gobj_copy();

private:

  
protected:

  Server(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const Glib::RefPtr<Cancellable>& cancellable,
    ServerFlags flags);

  Server(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<Cancellable>& cancellable,
    ServerFlags flags);

  Server(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    ServerFlags flags);

  Server(const std::string& address,
    const std::string& guid,
    ServerFlags flags);

public:

  
  /** Creates a new D-Bus server that listens on the first address in
   *  @a address that works.
   * 
   * Once constructed, you can use g_dbus_server_get_client_address() to
   * get a D-Bus address string that clients can use to connect.
   * 
   * Connect to the DBusServer::signal_new_connection() signal to handle
   * incoming connections.
   * 
   * The returned DBusServer isn't active - you have to start it with
   * g_dbus_server_start().
   * 
   * See <xref linkend="gdbus-peer-to-peer"/> for how DBusServer can
   * be used.
   * 
   * This is a synchronous failable constructor. See
   * Glib::dbus_server_new() for the asynchronous version.
   * 
   * @newin{2,26}
   * @param address A D-Bus address.
   * @param flags Flags from the DBusServerFlags enumeration.
   * @param guid A D-Bus GUID.
   * @param observer A DBusAuthObserver or <tt>0</tt>.
   * @param cancellable A Cancellable or <tt>0</tt>.
   * @return A DBusServer or <tt>0</tt> if @a error is set. Free with
   * Glib::object_unref().
   */

  /// @throw Glib::Error.
  static Glib::RefPtr<Server> create_sync(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const Glib::RefPtr<Cancellable>& cancellable,
    ServerFlags flags = Gio::DBus::SERVER_FLAGS_NONE);

  
  /** Creates a new D-Bus server that listens on the first address in
   *  @a address that works.
   * 
   * Once constructed, you can use g_dbus_server_get_client_address() to
   * get a D-Bus address string that clients can use to connect.
   * 
   * Connect to the DBusServer::signal_new_connection() signal to handle
   * incoming connections.
   * 
   * The returned DBusServer isn't active - you have to start it with
   * g_dbus_server_start().
   * 
   * See <xref linkend="gdbus-peer-to-peer"/> for how DBusServer can
   * be used.
   * 
   * This is a synchronous failable constructor. See
   * Glib::dbus_server_new() for the asynchronous version.
   * 
   * @newin{2,26}
   * @param address A D-Bus address.
   * @param flags Flags from the DBusServerFlags enumeration.
   * @param guid A D-Bus GUID.
   * @param observer A DBusAuthObserver or <tt>0</tt>.
   * @param cancellable A Cancellable or <tt>0</tt>.
   * @return A DBusServer or <tt>0</tt> if @a error is set. Free with
   * Glib::object_unref().
   */

  /// @throw Glib::Error.
  static Glib::RefPtr<Server> create_sync(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<Cancellable>& cancellable,
    ServerFlags flags = Gio::DBus::SERVER_FLAGS_NONE);

  /// Non-cancellable version of create_sync().
  static Glib::RefPtr<Server> create_sync(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    ServerFlags flags = Gio::DBus::SERVER_FLAGS_NONE);

  /// Non-cancellable version of create_sync().
  static Glib::RefPtr<Server> create_sync(const std::string& address,
    const std::string& guid,
    ServerFlags flags = Gio::DBus::SERVER_FLAGS_NONE);

  
  /** Starts @a server.
   * 
   * @newin{2,26}
   */
  void start();
  
  /** Stops @a server.
   * 
   * @newin{2,26}
   */
  void stop();
  
  /** Gets whether @a server is active.
   * 
   * @newin{2,26}
   * @return <tt>true</tt> if server is active, <tt>false</tt> otherwise.
   */
  bool is_active() const;
  
  /** Gets the GUID for @a server.
   * 
   * @newin{2,26}
   * @return A D-Bus GUID. Do not free this string, it is owned by @a server.
   */
  std::string get_guid() const;
  
  /** Gets the flags for @a server.
   * 
   * @newin{2,26}
   * @return A set of flags from the DBusServerFlags enumeration.
   */
  ServerFlags get_flags() const;
  
  /** Gets a D-Bus address string that can be used by clients to connect
   * to @a server.
   * 
   * @newin{2,26}
   * @return A D-Bus address string. Do not free, the string is owned
   * by @a server.
   */
  std::string get_client_address() const;

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the server is currently active.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_active() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The address to listen on.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< std::string > property_address() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Object used to assist in the authentication process.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<AuthObserver> > property_authentication_observer() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The address clients can use.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< std::string > property_client_address() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Flags for the server.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< ServerFlags > property_flags() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The guid of the server.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< std::string > property_guid() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


/**
   * @par Slot Prototype:
   * <tt>bool on_my_%new_connection(const Glib::RefPtr<Connection>& connection)</tt>
   *
   * Emitted when a new authenticated connection has been made. Use
   * g_dbus_connection_get_peer_credentials() to figure out what
   * identity (if any), was authenticated.
   * 
   * If you want to accept the connection, take a reference to the
   *  @a connection object and return <tt>true</tt>. When you are done with the
   * connection call g_dbus_connection_close() and give up your
   * reference. Note that the other peer may disconnect at any time -
   * a typical thing to do when accepting a connection is to listen to
   * the DBusConnection::signal_closed() signal.
   * 
   * If DBusServer::property_flags() contains DBUS_SERVER_FLAGS_RUN_IN_THREAD
   * then the signal is emitted in a new thread dedicated to the
   * connection. Otherwise the signal is emitted in the thread-default main
   * loop of the thread that @a server was constructed in.
   * 
   * You are guaranteed that signal handlers for this signal runs
   * before incoming messages on @a connection are processed. This means
   * that it's suitable to call g_dbus_connection_register_object() or
   * similar from the signal handler.
   * 
   * @newin{2,26}
   * @param connection A DBusConnection for the new connection.
   * @return <tt>true</tt> to claim @a connection, <tt>false</tt> to let other handlers
   * run.
   */

  Glib::SignalProxy1< bool,const Glib::RefPtr<Connection>& > signal_new_connection();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace DBus

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::DBus::Server
   */
  Glib::RefPtr<Gio::DBus::Server> wrap(GDBusServer* object, bool take_copy = false);
}


#endif /* _GIOMM_DBUSSERVER_H */

